/*
 * Last changed at upstream commit 352d001fc7f5d34243047454b3f9e684577ce3e0
 * https://github.com/espressif/esp32c3-bt-lib/commit/352d001fc7f5d34243047454b3f9e684577ce3e0
 * Upstream date: 2021-04-20 15:58:00 +0800
 * Upstream subject: ESP32C3, ESP32S3: update libbtdm_app.a(47235b66)
 * Source: libbtdm_app -> llm_scan.o -> llm_util_check_mesh_adv_report_list
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 llm_util_check_mesh_adv_report_list(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  
  if ((0xb < param_2) && (param_1 != 0)) {
    uVar2 = (uint)*(byte *)(param_1 + 2) << 0x18 | (uint)*(byte *)(param_1 + 4) << 0x10 |
            (uint)*(byte *)(param_1 + 6) | (uint)*(byte *)(param_1 + 5) << 8;
    uVar3 = (uint)*(byte *)(param_1 + 7) << 0x18 | (uint)*(byte *)(param_1 + 8) << 0x10 |
            (uint)*(byte *)(param_1 + 10) | (uint)*(byte *)(param_1 + 9) << 8;
    piVar6 = (int *)_memset;
    while( true ) {
      if (piVar6 == (int *)0x0) {
        uVar4 = (**(code **)(_r_modules_funcs_p + 0x50))
                          (&le_scan_duplicate_option,*(code **)(_r_modules_funcs_p + 0x50));
        if (_r_osi_funcs_p <= uVar4) {
          llm_util_flush_list(&le_scan_duplicate_option);
        }
        iVar5 = (**(code **)(_r_modules_funcs_p + 0x120))
                          (0xc,0,*(code **)(_r_modules_funcs_p + 0x120));
        iVar1 = _r_modules_funcs_p;
        if (iVar5 != 0) {
          *(uint *)(iVar5 + 4) = uVar2;
          *(uint *)(iVar5 + 8) = uVar3;
          (**(code **)(iVar1 + 0x4c))(&le_scan_duplicate_option,iVar5,*(code **)(iVar1 + 0x4c));
        }
        return 0;
      }
      if ((uVar2 == piVar6[1]) && (uVar3 == piVar6[2])) break;
      piVar6 = (int *)*piVar6;
    }
    return 1;
  }
  return 0;
}

