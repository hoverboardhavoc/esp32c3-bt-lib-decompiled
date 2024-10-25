/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llc_phy_upd.o -> llc_op_phy_upd_ind_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
llc_op_phy_upd_ind_handler(undefined4 param_1,int param_2,uint param_3,undefined4 param_4)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar3 + 0x18) != '\0') {
    param_3 = param_3 >> 8;
    iVar4 = *(int *)(&llc_env + param_3 * 4);
    iVar3 = r_sdk_config_get_opts(param_1,param_4);
    uVar2 = param_3 & 0xff;
    if (((uVar2 < *(byte *)(iVar3 + 0xd)) && (iVar3 = *(int *)(&llc_env + param_3 * 4), iVar3 != 0))
       && ((*(byte *)(iVar3 + 0x44) & 3) != 3)) {
      iVar3 = r_llc_proc_id_get(uVar2,0);
      if ((iVar3 == 0) &&
         (((*(ushort *)(iVar4 + 0x42) & 0x10) == 0 ||
          (iVar3 = r_llc_proc_state_get(param_2), iVar3 != 0)))) {
        iVar3 = r_llc_proc_state_get(param_2);
        if ((iVar3 != 0) && (iVar3 = r_llc_proc_state_get(param_2), iVar3 != 1)) {
          uVar1 = r_llc_proc_state_get(param_2);
          r_assert_param(param_3,uVar1,"llc_phy_upd.c",0x5d2);
        }
        r_llc_proc_reg(uVar2,0,param_2);
        uVar1 = r_llc_proc_state_get(param_2);
        r_llc_loc_phy_upd_proc_continue(uVar2,uVar1,0);
        uVar1 = 1;
      }
      else {
        uVar1 = 2;
      }
    }
    else {
      uVar1 = 0;
      if (*(char *)(param_2 + 0xe) != '\0') {
        r_llc_hci_le_phy_upd_cmp_evt_send
                  (uVar2,*(undefined1 *)(iVar4 + 0x46),*(undefined1 *)(iVar4 + 0x1c),
                   *(undefined1 *)(iVar4 + 0x1d));
      }
    }
    return uVar1;
  }
  if (*(char *)(param_2 + 0xe) != '\0') {
    r_llc_hci_le_phy_upd_cmp_evt_send(param_3 >> 8,0xc,0,0);
  }
  return 0;
}

