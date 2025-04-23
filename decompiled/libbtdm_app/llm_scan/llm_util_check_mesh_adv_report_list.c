/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  int iVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  
  if (param_2 < 0xc) {
    return 0;
  }
  if (param_1 != 0) {
    iVar3 = (**(code **)(_r_ip_funcs_p + 0x924))(*(code **)(_r_ip_funcs_p + 0x924));
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
    uVar4 = (**(code **)(_r_modules_funcs_p + 0x50))(iVar7,*(code **)(_r_modules_funcs_p + 0x50));
    if (uVar4 < *(ushort *)(iVar3 + 0xc)) {
      iVar3 = (**(code **)(_r_modules_funcs_p + 0x120))
                        (0xc,3,*(code **)(_r_modules_funcs_p + 0x120));
      if (iVar3 == 0) {
        return 0;
      }
    }
    else {
      iVar3 = *(int *)(iVar3 + 0x14);
      if (iVar3 == 0) {
        return 0;
      }
      iVar5 = (**(code **)(_r_modules_funcs_p + 0x1c))
                        (iVar7,iVar3,*(code **)(_r_modules_funcs_p + 0x1c));
      if (iVar5 == 0) {
        (**(code **)(_r_plf_funcs_p + 8))("llm_scan.c",0x564,*(code **)(_r_plf_funcs_p + 8));
      }
    }
    iVar5 = _r_modules_funcs_p;
    *(uint *)(iVar3 + 4) = uVar2;
    *(uint *)(iVar3 + 8) = uVar1;
    (**(code **)(iVar5 + 0x4c))(iVar7,iVar3,*(code **)(iVar5 + 0x4c));
  }
  return 0;
}

