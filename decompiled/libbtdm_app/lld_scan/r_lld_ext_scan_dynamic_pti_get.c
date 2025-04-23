/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_scan.o -> r_lld_ext_scan_dynamic_pti_get
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_ext_scan_dynamic_pti_get(int param_1,undefined1 *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined1 uVar5;
  undefined1 *puVar6;
  uint uVar7;
  
  if (param_1 == 0) {
    iVar2 = (**(code **)(_r_modules_funcs_p + 0x2c4))(*(code **)(_r_modules_funcs_p + 0x2c4));
    iVar1 = _lld_scan_env;
    if ((*(char *)(_lld_scan_env + 0x17) == '\0') &&
       (((iVar2 - *(int *)(_lld_scan_env + 0x1c) & 0xfffffffU) < 0x8000001 ||
        ((*(int *)(_lld_scan_env + 0x1c) - iVar2 & 0xfffffffU) == 0)))) {
      *(int *)(_lld_scan_env + 0x18) = iVar2;
      *(undefined1 *)(iVar1 + 0x17) = 1;
    }
  }
  else if ((param_1 - 1U < 3) && (*(char *)(_lld_scan_env + 0x17) != '\0')) {
    iVar2 = (**(code **)(_r_modules_funcs_p + 0x2c4))(*(code **)(_r_modules_funcs_p + 0x2c4));
    iVar1 = _lld_scan_env;
    iVar3 = *(int *)(_bt_rf_coex_cfg_p + 0x3c);
    uVar7 = ((iVar2 - *(int *)(_lld_scan_env + 0x18) & 0xfffffffU) * (uint)*(byte *)(iVar3 + 7)) /
            100;
    uVar4 = (uint)*(ushort *)(iVar3 + 8) << 1;
    if ((uVar7 < uVar4) || (uVar4 = (uint)*(ushort *)(iVar3 + 10) << 1, uVar4 < uVar7)) {
      uVar7 = uVar4;
    }
    *(uint *)(_lld_scan_env + 0x1c) = uVar7 + iVar2 & 0xfffffff;
    *(undefined1 *)(iVar1 + 0x17) = 0;
  }
  puVar6 = *(undefined1 **)(_bt_rf_coex_cfg_p + 0x3c);
  if (*(char *)(_lld_scan_env + 0x17) == '\0') {
    uVar5 = puVar6[2];
  }
  else {
    param_2[3] = puVar6[3];
    param_2[4] = puVar6[4];
    param_2[5] = puVar6[5];
    param_2[6] = puVar6[6];
    *param_2 = *puVar6;
    uVar5 = puVar6[1];
  }
  param_2[1] = uVar5;
  return;
}

