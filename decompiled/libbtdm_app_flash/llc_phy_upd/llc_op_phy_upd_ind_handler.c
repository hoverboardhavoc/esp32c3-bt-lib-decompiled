/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  int iVar2;
  int iVar3;
  
  iVar2 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar2 + 0x18) != '\0') {
    param_3 = param_3 >> 8;
    iVar3 = *(int *)(&llc_env + param_3 * 4);
    iVar2 = r_sdk_config_get_opts(param_1,param_4);
    if (((param_3 < *(byte *)(iVar2 + 0xd)) &&
        (iVar2 = *(int *)(&llc_env + param_3 * 4), iVar2 != 0)) &&
       ((*(byte *)(iVar2 + 0x44) & 3) != 3)) {
      iVar2 = r_llc_proc_id_get(param_3,0);
      if ((iVar2 == 0) &&
         (((*(ushort *)(iVar3 + 0x42) & 0x10) == 0 ||
          (iVar2 = r_llc_proc_state_get(param_2), iVar2 != 0)))) {
        iVar2 = r_llc_proc_state_get(param_2);
        if ((iVar2 != 0) && (iVar2 = r_llc_proc_state_get(param_2), iVar2 != 1)) {
          uVar1 = r_llc_proc_state_get(param_2);
          r_assert_param(param_3,uVar1,"llc_phy_upd.c",0x5d1);
        }
        r_llc_proc_reg(param_3,0,param_2);
        uVar1 = r_llc_proc_state_get(param_2);
        r_llc_loc_phy_upd_proc_continue(param_3,uVar1,0);
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
                  (param_3,*(undefined1 *)(iVar3 + 0x46),*(undefined1 *)(iVar3 + 0x1c),
                   *(undefined1 *)(iVar3 + 0x1d));
      }
    }
    return uVar1;
  }
  if (*(char *)(param_2 + 0xe) != '\0') {
    r_llc_hci_le_phy_upd_cmp_evt_send(param_3 >> 8,0xc,0,0);
  }
  return 0;
}

