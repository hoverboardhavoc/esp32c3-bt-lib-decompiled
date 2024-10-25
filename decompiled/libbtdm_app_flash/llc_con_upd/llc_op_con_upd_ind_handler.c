/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llc_con_upd.o -> llc_op_con_upd_ind_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 llc_op_con_upd_ind_handler(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  char cVar4;
  int iVar5;
  
  param_2 = param_2 >> 8;
  iVar5 = *(int *)(&llc_env + param_2 * 4);
  iVar2 = r_sdk_config_get_opts();
  uVar1 = param_2 & 0xff;
  if (((uVar1 < *(byte *)(iVar2 + 0xd)) && (iVar2 = *(int *)(&llc_env + param_2 * 4), iVar2 != 0))
     && ((*(byte *)(iVar2 + 0x44) & 3) != 3)) {
    iVar2 = r_llc_proc_id_get(uVar1,0);
    if ((iVar2 == 0) &&
       (((*(ushort *)(iVar5 + 0x42) & 0x10) == 0 ||
        (iVar2 = r_llc_proc_state_get(param_1), iVar2 != 0)))) {
      iVar2 = r_llc_proc_state_get(param_1);
      if ((iVar2 != 0) && (iVar2 = r_llc_proc_state_get(param_1), iVar2 != 1)) {
        uVar3 = r_llc_proc_state_get(param_1);
        r_assert_param(param_2,uVar3,"llc_con_upd.c",0x679);
      }
      r_llc_proc_reg(uVar1,0,param_1);
      uVar3 = r_llc_proc_state_get(param_1);
      r_llc_loc_con_upd_proc_continue(uVar1,uVar3,0);
      uVar3 = 1;
    }
    else {
      uVar3 = 2;
    }
  }
  else {
    if (*(char *)(param_1 + 0x2d) == '\0') {
      *(byte *)(iVar5 + 0x45) = *(byte *)(iVar5 + 0x45) & 0x7f;
    }
    else {
      cVar4 = *(char *)(iVar5 + 0x46);
      if (cVar4 == '\0') {
        cVar4 = *(char *)(iVar5 + 0x47);
      }
      r_llc_hci_con_upd_info_send_eco(uVar1,cVar4,param_1);
    }
    uVar3 = 0;
  }
  return uVar3;
}

