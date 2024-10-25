/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llc_con_upd.o -> lld_con_param_upd_cfm_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 lld_con_param_upd_cfm_handler(uint param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  
  uVar1 = param_1 >> 8 & 0xff;
  iVar5 = *(int *)(&llc_env + (param_1 >> 8) * 4);
  iVar2 = r_sdk_config_get_opts();
  if (((uVar1 < *(byte *)(iVar2 + 0xd)) &&
      (iVar2 = *(int *)(&llc_env + (param_1 >> 8) * 4), iVar2 != 0)) &&
     ((*(byte *)(iVar2 + 0x44) & 3) != 3)) {
    iVar2 = r_llc_proc_id_get(uVar1,0);
    if ((iVar2 != 5) && (iVar2 = r_llc_proc_id_get(uVar1,1), iVar2 != 5)) {
      uVar3 = r_llc_proc_id_get(uVar1,0);
      uVar4 = r_llc_proc_id_get(uVar1,1);
      r_assert_param(uVar3,uVar4,"llc_con_upd.c",0x697);
    }
    iVar2 = r_llc_proc_id_get(uVar1,0);
    if (iVar2 == 5) {
      r_llc_loc_con_upd_proc_continue(uVar1,4,0);
    }
    else {
      iVar2 = r_llc_proc_id_get(uVar1,1);
      if (iVar2 == 5) {
        r_llc_rem_con_upd_proc_continue(uVar1,10,0);
      }
    }
    if (iVar5 != 0) {
      iVar2 = r_sdk_config_get_opts_ext();
      if (*(char *)(iVar2 + 0x20) != '\0') {
        r_llc_le_ping_set(uVar1,*(undefined2 *)(iVar5 + 0x3e));
      }
    }
  }
  return 0;
}

