/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llc_con_upd.o -> hci_le_rem_con_param_req_neg_reply_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
hci_le_rem_con_param_req_neg_reply_cmd_handler(uint param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = r_sdk_config_get_opts();
  if (((param_1 < *(byte *)(iVar1 + 0xd)) && (*(int *)(&llc_env + param_1 * 4) != 0)) &&
     ((*(byte *)(*(int *)(&llc_env + param_1 * 4) + 0x44) & 3) != 3)) {
    uVar2 = 0x12;
    if (*(char *)(param_2 + 2) != ';') goto _L289;
    iVar1 = r_llc_proc_get(param_1,1,0x12);
    if (iVar1 != 0) {
      r_llc_rem_con_upd_proc_continue(param_1,8,*(undefined1 *)(param_2 + 2));
      uVar2 = 0;
      goto _L289;
    }
  }
  uVar2 = 0xc;
_L289:
  r_llc_cmd_cmp_send(param_1,param_3,uVar2);
  return 0;
}

