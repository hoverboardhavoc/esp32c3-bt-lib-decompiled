/*
 * Last changed at upstream commit aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * https://github.com/espressif/esp32c3-bt-lib/commit/aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * Upstream date: 2025-03-20 20:31:24 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(d74042a8)
 * Source: libbtdm_app_flash -> llc_encrypt.o -> hci_le_ltk_req_reply_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 hci_le_ltk_req_reply_cmd_handler(uint param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar2 + 0x20) == '\0') {
    r_llc_cmd_cmp_send(param_1,param_3,0xc);
    return 0;
  }
  iVar2 = r_sdk_config_get_opts();
  if ((((param_1 < *(byte *)(iVar2 + 0xd)) && (*(int *)(&llc_env + param_1 * 4) != 0)) &&
      ((*(byte *)(*(int *)(&llc_env + param_1 * 4) + 0x44) & 3) != 3)) &&
     (iVar2 = r_llc_proc_id_get(param_1,1), iVar2 == 3)) {
    iVar2 = r_llc_proc_get(param_1,1);
    iVar1 = r_llc_proc_state_get();
    if (iVar1 == 0xe) {
      memcpy((void *)(iVar2 + 0x10),(void *)(param_2 + 2),0x10);
      r_llc_rem_encrypt_proc_continue_eco(param_1,0xe,0);
      uVar3 = 0;
      goto _L215;
    }
  }
  uVar3 = 0xc;
_L215:
  r_llc_cmd_cmp_send(param_1,param_3,uVar3);
  return 0;
}

