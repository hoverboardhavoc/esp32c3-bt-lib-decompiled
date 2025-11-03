/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> llm_scan.o -> llm_util_check_mesh_adv_report_list
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 llm_util_check_mesh_adv_report_list(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  
  if (param_2 < 0xc) {
    return 0;
  }
  if (param_1 != 0) {
    iVar3 = r_llm_le_scan_duplicate_opt_get();
    uVar2 = (uint)*(byte *)(param_1 + 2) << 0x18 | (uint)*(byte *)(param_1 + 4) << 0x10 |
            (uint)*(byte *)(param_1 + 6) | (uint)*(byte *)(param_1 + 5) << 8;
    uVar1 = (uint)*(byte *)(param_1 + 7) << 0x18 | (uint)*(byte *)(param_1 + 8) << 0x10 |
            (uint)*(byte *)(param_1 + 10) | (uint)*(byte *)(param_1 + 9) << 8;
    for (piVar6 = *(int **)(iVar3 + 0x10); piVar6 != (int *)0x0; piVar6 = (int *)*piVar6) {
      if ((uVar2 == piVar6[1]) && (uVar1 == piVar6[2])) {
        return 1;
      }
    }
    iVar7 = iVar3 + 0x10;
    uVar4 = r_co_list_size(iVar7);
    if (uVar4 < *(ushort *)(iVar3 + 0xc)) {
      iVar3 = r_ke_malloc(0xc,3);
      if (iVar3 == 0) {
        return 0;
      }
    }
    else {
      iVar3 = *(int *)(iVar3 + 0x14);
      if (iVar3 == 0) {
        return 0;
      }
      iVar5 = r_co_list_extract(iVar7,iVar3);
      if (iVar5 == 0) {
        r_assert_err("llm_scan.c",0x5b0);
      }
    }
    *(uint *)(iVar3 + 4) = uVar2;
    *(uint *)(iVar3 + 8) = uVar1;
    r_co_list_push_front(iVar7,iVar3);
  }
  return 0;
}

