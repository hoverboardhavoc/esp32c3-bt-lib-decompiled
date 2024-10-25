/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llc_phy_upd.o -> f_llc_op_phy_upd_ind_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 f_llc_op_phy_upd_ind_handler(int param_1,uint param_2)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  param_2 = param_2 >> 8;
  iVar4 = *(int *)(&llc_env + param_2 * 4);
  iVar3 = r_sdk_config_get_opts();
  uVar2 = param_2 & 0xff;
  if (((uVar2 < *(byte *)(iVar3 + 0xd)) && (iVar3 = *(int *)(&llc_env + param_2 * 4), iVar3 != 0))
     && ((*(byte *)(iVar3 + 0x44) & 3) != 3)) {
    iVar3 = r_llc_proc_id_get(uVar2,0);
    if ((iVar3 == 0) &&
       (((*(ushort *)(iVar4 + 0x42) & 0x10) == 0 ||
        (iVar3 = r_llc_proc_state_get(param_1), iVar3 != 0)))) {
      iVar3 = r_llc_proc_state_get(param_1);
      if ((iVar3 != 0) && (iVar3 = r_llc_proc_state_get(param_1), iVar3 != 1)) {
        uVar1 = r_llc_proc_state_get(param_1);
        r_assert_param(param_2,uVar1,"llc_phy_upd.c",0x5d2);
      }
      r_llc_proc_reg(uVar2,0,param_1);
      uVar1 = r_llc_proc_state_get(param_1);
      r_llc_loc_phy_upd_proc_continue(uVar2,uVar1,0);
      uVar1 = 1;
    }
    else {
      uVar1 = 2;
    }
  }
  else {
    uVar1 = 0;
    if (*(char *)(param_1 + 0xe) != '\0') {
      r_llc_hci_le_phy_upd_cmp_evt_send
                (uVar2,*(undefined1 *)(iVar4 + 0x46),*(undefined1 *)(iVar4 + 0x1c),
                 *(undefined1 *)(iVar4 + 0x1d));
    }
  }
  return uVar1;
}

