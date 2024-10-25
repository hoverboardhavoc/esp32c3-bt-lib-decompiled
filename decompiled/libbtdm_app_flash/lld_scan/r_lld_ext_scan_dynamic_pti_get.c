/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld_scan.o -> r_lld_ext_scan_dynamic_pti_get
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
  uint uVar3;
  int iVar4;
  undefined1 uVar5;
  undefined1 *puVar6;
  uint uVar7;
  
  if (param_1 == 0) {
    iVar2 = r_rwip_time_get();
    iVar1 = _lld_scan_env;
    if (*(char *)(_lld_scan_env + 0x17) == '\0') {
      if (((iVar2 - *(int *)(_lld_scan_env + 0x1c) & 0xfffffffU) < 0x8000001) ||
         ((*(int *)(_lld_scan_env + 0x1c) - iVar2 & 0xfffffffU) == 0)) {
        *(int *)(_lld_scan_env + 0x18) = iVar2;
        *(undefined1 *)(iVar1 + 0x17) = 1;
      }
    }
  }
  else if (((-1 < param_1) && (param_1 < 4)) && (*(char *)(_lld_scan_env + 0x17) != '\0')) {
    iVar2 = r_rwip_time_get();
    iVar1 = _lld_scan_env;
    iVar4 = *(int *)(_bt_rf_coex_cfg_p + 0x3c);
    uVar7 = ((iVar2 - *(int *)(_lld_scan_env + 0x18) & 0xfffffffU) * (uint)*(byte *)(iVar4 + 7)) /
            100;
    uVar3 = (uint)*(ushort *)(iVar4 + 8) * 2;
    if (uVar7 < uVar3) {
      uVar3 = iVar2 + uVar3;
    }
    else {
      uVar3 = (uint)*(ushort *)(iVar4 + 10) * 2;
      if (uVar3 < uVar7) {
        uVar3 = iVar2 + uVar3;
      }
      else {
        uVar3 = iVar2 + uVar7;
      }
    }
    *(uint *)(_lld_scan_env + 0x1c) = uVar3 & 0xfffffff;
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

