/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> llc_encrypt.o -> hci_le_ltk_req_neg_reply_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 hci_le_ltk_req_neg_reply_cmd_handler(uint param_1,undefined4 param_2,undefined4 param_3)

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
  iVar3 = r_sdk_config_get_opts(param_2);
  if (param_1 < *(byte *)(iVar3 + 0xd)) {
    iVar3 = *(int *)(&llc_env + param_1 * 4);
    if ((iVar3 == 0) || ((*(byte *)(iVar3 + 0x44) & 3) == 3)) goto _L244;
    iVar3 = r_llc_proc_id_get(param_1,1);
    if (iVar3 == 3) {
      iVar3 = r_llc_proc_get(param_1);
      iVar2 = r_llc_proc_state_get();
      if (iVar2 == 0xe) {
        if (*(char *)(iVar3 + 0x3a) == '\0') {
          r_llc_rem_encrypt_proc_continue_eco(param_1,0xe,6);
        }
        else {
          r_llc_proc_unreg(param_1,1);
          iVar3 = *(int *)(&llc_env + param_1 * 4);
          *(ushort *)(iVar3 + 0x42) = *(ushort *)(iVar3 + 0x42) & 0xfdff;
          r_llc_init_term_proc(param_1,6);
        }
        uVar1 = 0;
        goto _L246;
      }
      iVar3 = r_llc_proc_state_get(iVar3);
      uVar4 = param_1 << 8 | iVar3 << 0x10 | 0xc;
      uVar1 = 0x80030033;
    }
    else {
      iVar3 = r_llc_proc_id_get(param_1,1);
      uVar4 = param_1 << 8 | iVar3 << 0x10 | 0xc;
      uVar1 = 0x80030034;
    }
  }
  else {
_L244:
    uVar4 = param_1 << 8 | 0xc;
    uVar1 = 0x80030032;
  }
  r_ble_log_internal_x1(uVar1,uVar4);
  uVar1 = 0xc;
_L246:
  r_llc_cmd_cmp_send(param_1,param_3,uVar1);
  return 0;
}

