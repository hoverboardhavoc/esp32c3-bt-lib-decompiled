/*
 * Last changed at upstream commit bba9af9259e0999ef246426d31a793fe0a3ff4db
 * https://github.com/espressif/esp32c3-bt-lib/commit/bba9af9259e0999ef246426d31a793fe0a3ff4db
 * Upstream date: 2022-12-14 15:32:37 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(80abacdd)
 * Source: libbtdm_app -> llm_scan.o -> llm_util_check_mesh_adv_report_list
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 llm_util_check_mesh_adv_report_list(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  
  if ((0xb < param_2) && (param_1 != 0)) {
    uVar1 = (uint)*(byte *)(param_1 + 2) << 0x18 | (uint)*(byte *)(param_1 + 4) << 0x10 |
            (uint)*(byte *)(param_1 + 6) | (uint)*(byte *)(param_1 + 5) << 8;
    uVar2 = (uint)*(byte *)(param_1 + 7) << 0x18 | (uint)*(byte *)(param_1 + 8) << 0x10 |
            (uint)*(byte *)(param_1 + 10) | (uint)*(byte *)(param_1 + 9) << 8;
    piVar6 = (int *)_memset;
    while( true ) {
      if (piVar6 == (int *)0x0) {
        uVar3 = (**(code **)(_r_modules_funcs_p + 0x50))
                          (&le_scan_duplicate_option,*(code **)(_r_modules_funcs_p + 0x50));
        iVar4 = _llm_adv_is_in_duplicate_scan_duplicate_exceptional_list;
        if (uVar3 < _r_osi_funcs_p) {
          iVar4 = (**(code **)(_r_modules_funcs_p + 0x120))
                            (0xc,3,*(code **)(_r_modules_funcs_p + 0x120));
          if (iVar4 == 0) {
            return 0;
          }
        }
        else {
          if (_llm_adv_is_in_duplicate_scan_duplicate_exceptional_list == 0) {
            return 0;
          }
          iVar5 = (**(code **)(_r_modules_funcs_p + 0x1c))
                            (&le_scan_duplicate_option,
                             _llm_adv_is_in_duplicate_scan_duplicate_exceptional_list,
                             *(code **)(_r_modules_funcs_p + 0x1c));
          if (iVar5 == 0) {
            (**(code **)(_r_plf_funcs_p + 8))("llm_scan.c",0x4ec,*(code **)(_r_plf_funcs_p + 8));
          }
        }
        iVar5 = _r_modules_funcs_p;
        *(uint *)(iVar4 + 4) = uVar1;
        *(uint *)(iVar4 + 8) = uVar2;
        (**(code **)(iVar5 + 0x4c))(&le_scan_duplicate_option,iVar4,*(code **)(iVar5 + 0x4c));
        return 0;
      }
      if ((uVar1 == piVar6[1]) && (uVar2 == piVar6[2])) break;
      piVar6 = (int *)*piVar6;
    }
    return 1;
  }
  return 0;
}

