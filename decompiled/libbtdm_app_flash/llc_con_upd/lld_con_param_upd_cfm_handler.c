/*
 * Last changed at upstream commit 9b50531537e755792ac827d00d233eab499a0b37
 * https://github.com/espressif/esp32c3-bt-lib/commit/9b50531537e755792ac827d00d233eab499a0b37
 * Upstream date: 2025-12-17 10:51:37 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(5106725)
 * Source: libbtdm_app_flash -> llc_con_upd.o -> lld_con_param_upd_cfm_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 lld_con_param_upd_cfm_handler(uint param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  
  param_1 = param_1 >> 8;
  iVar4 = *(int *)(&llc_env + param_1 * 4);
  iVar1 = r_sdk_config_get_opts();
  if (((param_1 < *(byte *)(iVar1 + 0xd)) && (iVar1 = *(int *)(&llc_env + param_1 * 4), iVar1 != 0))
     && ((*(byte *)(iVar1 + 0x44) & 3) != 3)) {
    iVar1 = r_llc_proc_id_get(param_1,0);
    if ((iVar1 != 5) && (iVar1 = r_llc_proc_id_get(param_1,1), iVar1 != 5)) {
      uVar2 = r_llc_proc_id_get(param_1,0);
      uVar3 = r_llc_proc_id_get(param_1,1);
      r_assert_param(uVar2,uVar3,"llc_con_upd.c",0x6af);
    }
    iVar1 = r_llc_proc_id_get(param_1,0);
    if (iVar1 == 5) {
      r_llc_loc_con_upd_proc_continue_hack(param_1,4,0);
    }
    else {
      iVar1 = r_llc_proc_id_get(param_1,1);
      if (iVar1 == 5) {
        r_llc_rem_con_upd_proc_continue_hack(param_1,10,0);
      }
    }
    if (iVar4 != 0) {
      iVar1 = r_sdk_config_get_opts_ext();
      if (*(char *)(iVar1 + 0x20) != '\0') {
        r_llc_le_ping_set(param_1,*(undefined2 *)(iVar4 + 0x3e));
      }
    }
  }
  return 0;
}

