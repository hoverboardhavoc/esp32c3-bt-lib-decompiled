/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llc_phy_upd.o -> f_lld_phy_upd_cfm_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 f_lld_phy_upd_cfm_handler(uint param_1)

{
  int iVar1;
  undefined4 uVar2;
  code *pcVar3;
  
  param_1 = param_1 >> 8;
  iVar1 = (**(code **)(_r_ip_funcs_p + 0x678))(param_1,0,*(code **)(_r_ip_funcs_p + 0x678));
  if (iVar1 == 9) {
    pcVar3 = *(code **)(_r_ip_funcs_p + 0x648);
    uVar2 = 4;
  }
  else {
    iVar1 = (**(code **)(_r_ip_funcs_p + 0x678))(param_1,1,*(code **)(_r_ip_funcs_p + 0x678));
    if (iVar1 != 9) {
      return 0;
    }
    uVar2 = 7;
    pcVar3 = *(code **)(_r_ip_funcs_p + 0x650);
  }
  (*pcVar3)(param_1,uVar2,0,pcVar3);
  return 0;
}

