/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
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
      r_assert_err("llm_scan.c",0x5ff);
    }
  }
  *(int *)(iVar3 + 4) = param_1;
  r_co_list_push_front(piVar1,iVar3);
  return 0;
}

