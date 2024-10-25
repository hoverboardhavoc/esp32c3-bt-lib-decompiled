/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> rwip_driver.o -> r_rwip_lpcycles_2_hus
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int r_rwip_lpcycles_2_hus(uint param_1,uint *param_2)

{
  int iVar1;
  uint uVar2;
  
  if (*(code **)(_r_osi_funcs_p + 0x8c) != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x000105ec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (**(code **)(_r_osi_funcs_p + 0x8c))();
    return iVar1;
  }
  if (1999999 < param_1) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"rwip_driver.c",0x1f7,*(code **)(_r_plf_funcs_p + 8));
  }
  uVar2 = 0;
  if (param_2 != (uint *)0x0) {
    uVar2 = *param_2;
  }
  uVar2 = param_1 * 9 + uVar2;
  if (param_2 != (uint *)0x0) {
    *param_2 = uVar2 & 0xff;
  }
  return (uVar2 >> 8) + param_1 * 0x3d;
}

