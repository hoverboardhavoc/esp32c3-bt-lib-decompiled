/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> llc_phy_upd.o -> f_llc_op_phy_upd_ind_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 f_llc_op_phy_upd_ind_handler(int param_1,uint param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  param_2 = param_2 >> 8;
  iVar3 = *(int *)(&llc_env + param_2 * 4);
  iVar2 = r_sdk_config_get_opts();
  if (((param_2 < *(byte *)(iVar2 + 0xd)) && (iVar2 = *(int *)(&llc_env + param_2 * 4), iVar2 != 0))
     && ((*(byte *)(iVar2 + 0x44) & 3) != 3)) {
    iVar2 = r_llc_proc_id_get(param_2,0);
    if ((iVar2 == 0) &&
       (((*(ushort *)(iVar3 + 0x42) & 0x10) == 0 ||
        (iVar2 = r_llc_proc_state_get(param_1), iVar2 != 0)))) {
      iVar2 = r_llc_proc_state_get(param_1);
      if ((iVar2 != 0) && (iVar2 = r_llc_proc_state_get(param_1), iVar2 != 1)) {
        uVar1 = r_llc_proc_state_get(param_1);
        r_assert_param(param_2,uVar1,"llc_phy_upd.c",0x5ee);
      }
      r_llc_proc_reg(param_2,0,param_1);
      uVar1 = r_llc_proc_state_get(param_1);
      r_llc_loc_phy_upd_proc_continue_hack(param_2,uVar1,0);
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
                (param_2,*(undefined1 *)(iVar3 + 0x46),*(undefined1 *)(iVar3 + 0x1c),
                 *(undefined1 *)(iVar3 + 0x1d));
    }
  }
  return uVar1;
}

