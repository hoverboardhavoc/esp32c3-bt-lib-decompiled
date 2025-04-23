/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llc_encrypt.o -> f_hci_le_ltk_req_reply_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 f_hci_le_ltk_req_reply_cmd_handler(uint param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = r_sdk_config_get_opts();
  if (param_1 < *(byte *)(iVar1 + 0xd)) {
    if (((*(int *)(&llc_env + param_1 * 4) != 0) &&
        ((*(byte *)(*(int *)(&llc_env + param_1 * 4) + 0x44) & 3) != 3)) &&
       (iVar1 = r_llc_proc_id_get(param_1,1), iVar1 == 3)) {
      iVar1 = r_llc_proc_get(param_1,1);
      iVar2 = r_llc_proc_state_get();
      if (iVar2 == 0xe) {
        memcpy((void *)(iVar1 + 0x10),(void *)(param_2 + 2),0x10);
        r_llc_rem_encrypt_proc_continue_eco(param_1,0xe,0);
        uVar3 = 0;
        goto _L227;
      }
    }
  }
  uVar3 = 0xc;
_L227:
  r_llc_cmd_cmp_send(param_1,param_3,uVar3);
  return 0;
}

