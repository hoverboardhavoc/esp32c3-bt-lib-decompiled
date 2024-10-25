/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llm_scan.o -> llm_util_check_adv_report_list_by_hash
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 llm_util_check_adv_report_list_by_hash(int param_1)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  
  piVar1 = (int *)r_llm_le_scan_duplicate_opt_get();
  for (piVar5 = (int *)*piVar1; piVar5 != (int *)0x0; piVar5 = (int *)*piVar5) {
    if (piVar5[1] == param_1) {
      return 1;
    }
  }
  uVar2 = r_co_list_size(piVar1);
  if (uVar2 < *(ushort *)((int)piVar1 + 10)) {
    iVar3 = r_ke_malloc(8,3);
    if (iVar3 == 0) {
      return 0;
    }
  }
  else {
    iVar3 = piVar1[1];
    if (iVar3 == 0) {
      return 0;
    }
    iVar4 = r_co_list_extract(piVar1,iVar3);
    if (iVar4 == 0) {
      r_assert_err("llm_scan.c",0x5a5);
    }
  }
  *(int *)(iVar3 + 4) = param_1;
  r_co_list_push_front(piVar1,iVar3);
  return 0;
}

