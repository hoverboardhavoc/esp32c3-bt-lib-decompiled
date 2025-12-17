/*
 * Last changed at upstream commit 9b50531537e755792ac827d00d233eab499a0b37
 * https://github.com/espressif/esp32c3-bt-lib/commit/9b50531537e755792ac827d00d233eab499a0b37
 * Upstream date: 2025-12-17 10:51:37 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(5106725)
 * Source: libbtdm_app_flash -> llc_con_upd.o -> hci_le_rem_con_param_req_neg_reply_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
hci_le_rem_con_param_req_neg_reply_cmd_handler(uint param_1,int param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = r_sdk_config_get_opts();
  if (((param_1 < *(byte *)(iVar2 + 0xd)) && (*(int *)(&llc_env + param_1 * 4) != 0)) &&
     ((*(byte *)(*(int *)(&llc_env + param_1 * 4) + 0x44) & 3) != 3)) {
    uVar1 = 0x12;
    if (*(char *)(param_2 + 2) != ';') goto _L295;
    iVar2 = r_llc_proc_get(param_1,1);
    if (iVar2 != 0) {
      r_llc_rem_con_upd_proc_continue_hack(param_1,8,*(undefined1 *)(param_2 + 2));
      uVar1 = 0;
      goto _L295;
    }
  }
  uVar1 = 0xc;
_L295:
  r_llc_cmd_cmp_send(param_1,param_3,uVar1);
  if (uVar1 != 0) {
    uVar3 = r_llc_proc_get(param_1,1);
    r_ble_log_internal_x2
              (0x802f0025,uVar3,(uint)*(byte *)(param_2 + 2) << 0x10 | param_1 << 8 | uVar1);
  }
  return 0;
}

