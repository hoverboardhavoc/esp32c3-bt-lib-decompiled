/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llc_dl_upd.o -> llc_op_dl_upd_ind_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 llc_op_dl_upd_ind_handler(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = r_sdk_config_get_opts();
  uVar1 = param_2 >> 8 & 0xff;
  if (((uVar1 < *(byte *)(iVar2 + 0xd)) && (*(int *)(&llc_env + uVar1 * 4) != 0)) &&
     ((*(byte *)(*(int *)(&llc_env + uVar1 * 4) + 0x44) & 3) != 3)) {
    iVar2 = r_llc_proc_id_get(uVar1,0);
    uVar3 = 2;
    if (iVar2 == 0) {
      r_llc_proc_reg(uVar1,0,param_1);
      r_llc_loc_dl_upd_proc_continue(uVar1,0);
      uVar3 = 1;
    }
  }
  else {
    uVar3 = 0;
    if (*(char *)(param_1 + 0x10) != '\0') {
      r_llc_hci_dl_upd_info_send
                (uVar1,*(undefined1 *)(*(int *)(&llc_env + (param_2 >> 8) * 4) + 0x46),0,0,0,0);
    }
  }
  return uVar3;
}

