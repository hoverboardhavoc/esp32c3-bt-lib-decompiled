/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llc_phy_upd.o -> f_ll_phy_update_ind_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 f_ll_phy_update_ind_handler(undefined4 param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  code *pcVar4;
  
  uVar1 = 0x20;
  if (((*(byte *)(param_2 + 1) & 0xf8) == 0) && ((*(byte *)(param_2 + 2) & 0xf8) == 0)) {
    if ((*(byte *)(param_2 + 1) != 0 || *(byte *)(param_2 + 2) != 0) &&
       ((param_3 - (uint)*(ushort *)(param_2 + 4) & 0xffff) < 0x7fff)) {
      uVar1 = 0x28;
      iVar2 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
      if ((*(byte *)(iVar2 + 0x1d) & 4) != 0) goto _L211;
      if (2 < _g_bt_plf_log_level) {
        ets_printf("phy_upd: %u %u %u\n",param_1,param_3,*(undefined2 *)(param_2 + 4));
      }
    }
    uVar1 = 0;
  }
_L211:
  iVar2 = (**(code **)(_r_ip_funcs_p + 0x678))(param_1,0,*(code **)(_r_ip_funcs_p + 0x678));
  if (iVar2 == 9) {
    iVar2 = (**(code **)(_r_ip_funcs_p + 0x674))(param_1,0,*(code **)(_r_ip_funcs_p + 0x674));
    uVar3 = 3;
    *(undefined1 *)(iVar2 + 0xc) = *(undefined1 *)(param_2 + 1);
    *(undefined1 *)(iVar2 + 0xd) = *(undefined1 *)(param_2 + 2);
    *(undefined2 *)(iVar2 + 8) = *(undefined2 *)(param_2 + 4);
    pcVar4 = *(code **)(_r_ip_funcs_p + 0x648);
  }
  else {
    iVar2 = (**(code **)(_r_ip_funcs_p + 0x678))(param_1,1,*(code **)(_r_ip_funcs_p + 0x678));
    if (iVar2 != 9) {
      return 0x24;
    }
    iVar2 = (**(code **)(_r_ip_funcs_p + 0x674))(param_1,1,*(code **)(_r_ip_funcs_p + 0x674));
    uVar3 = 6;
    *(undefined1 *)(iVar2 + 0xc) = *(undefined1 *)(param_2 + 1);
    *(undefined1 *)(iVar2 + 0xd) = *(undefined1 *)(param_2 + 2);
    *(undefined2 *)(iVar2 + 8) = *(undefined2 *)(param_2 + 4);
    pcVar4 = *(code **)(_r_ip_funcs_p + 0x650);
  }
  (*pcVar4)(param_1,uVar3,uVar1,pcVar4);
  return uVar1;
}

