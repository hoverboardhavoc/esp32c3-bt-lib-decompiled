/*
 * Last changed at upstream commit aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * https://github.com/espressif/esp32c3-bt-lib/commit/aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * Upstream date: 2025-03-20 20:31:24 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(d74042a8)
 * Source: libbtdm_app_flash -> llc_encrypt.o -> f_hci_le_ltk_req_neg_reply_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 f_hci_le_ltk_req_neg_reply_cmd_handler(uint param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = r_sdk_config_get_opts();
  if (param_1 < *(byte *)(iVar1 + 0xd)) {
    iVar1 = *(int *)(&llc_env + param_1 * 4);
    if (((iVar1 != 0) && ((*(byte *)(iVar1 + 0x44) & 3) != 3)) &&
       (iVar1 = r_llc_proc_id_get(param_1,1), iVar1 == 3)) {
      iVar1 = r_llc_proc_get(param_1,1);
      iVar2 = r_llc_proc_state_get();
      if (iVar2 == 0xe) {
        if (*(char *)(iVar1 + 0x3a) == '\0') {
          r_llc_rem_encrypt_proc_continue_eco(param_1,0xe,6);
        }
        else {
          r_llc_proc_unreg(param_1,1);
          iVar1 = *(int *)(&llc_env + param_1 * 4);
          *(ushort *)(iVar1 + 0x42) = *(ushort *)(iVar1 + 0x42) & 0xfdff;
          r_llc_init_term_proc(param_1,6);
        }
        uVar3 = 0;
        goto _L229;
      }
    }
  }
  uVar3 = 0xc;
_L229:
  r_llc_cmd_cmp_send(param_1,param_2,uVar3);
  return 0;
}

