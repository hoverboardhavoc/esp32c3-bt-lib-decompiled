/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
 * Source: libbtdm_app_flash -> llc_encrypt.o -> hci_le_ltk_req_reply_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 hci_le_ltk_req_reply_cmd_handler(uint param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar3 + 0x20) == '\0') {
    r_llc_cmd_cmp_send(param_1,param_3,0xc);
    return 0;
  }
  iVar3 = r_sdk_config_get_opts();
  if (((param_1 < *(byte *)(iVar3 + 0xd)) && (*(int *)(&llc_env + param_1 * 4) != 0)) &&
     ((*(byte *)(*(int *)(&llc_env + param_1 * 4) + 0x44) & 3) != 3)) {
    iVar3 = r_llc_proc_id_get(param_1,1);
    if (iVar3 == 3) {
      iVar3 = r_llc_proc_get(param_1);
      iVar2 = r_llc_proc_state_get();
      if (iVar2 == 0xe) {
        memcpy((void *)(iVar3 + 0x10),(void *)(param_2 + 2),0x10);
        r_llc_rem_encrypt_proc_continue_eco(param_1,0xe,0);
        uVar1 = 0;
        goto _L229;
      }
      iVar3 = r_llc_proc_state_get(iVar3);
      uVar4 = param_1 << 8 | iVar3 << 0x10 | 0xc;
      uVar1 = 0x80030094;
    }
    else {
      iVar3 = r_llc_proc_id_get(param_1,1);
      uVar4 = param_1 << 8 | iVar3 << 0x10 | 0xc;
      uVar1 = 0x80030095;
    }
  }
  else {
    uVar4 = param_1 << 8 | 0xc;
    uVar1 = 0x80030093;
  }
  r_ble_log_internal_x1(uVar1,uVar4);
  uVar1 = 0xc;
_L229:
  r_llc_cmd_cmp_send(param_1,param_3,uVar1);
  return 0;
}

