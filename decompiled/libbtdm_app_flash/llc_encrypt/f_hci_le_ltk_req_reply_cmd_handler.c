/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> llc_encrypt.o -> f_hci_le_ltk_req_reply_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 f_hci_le_ltk_req_reply_cmd_handler(uint param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  
  iVar1 = r_sdk_config_get_opts();
  if (param_1 < *(byte *)(iVar1 + 0xd)) {
    if ((*(int *)(&llc_env + param_1 * 4) == 0) ||
       ((*(byte *)(*(int *)(&llc_env + param_1 * 4) + 0x44) & 3) == 3)) goto _L235;
    iVar1 = r_llc_proc_id_get(param_1,1);
    if (iVar1 == 3) {
      iVar1 = r_llc_proc_get(param_1);
      iVar3 = r_llc_proc_state_get();
      if (iVar3 == 0xe) {
        memcpy((void *)(iVar1 + 0x10),(void *)(param_2 + 2),0x10);
        r_llc_rem_encrypt_proc_continue_eco(param_1,0xe,0);
        uVar2 = 0;
        goto _L237;
      }
      iVar1 = r_llc_proc_state_get(iVar1);
      uVar4 = param_1 << 8 | iVar1 << 0x10 | 0xc;
      uVar2 = 0x800300a5;
    }
    else {
      iVar1 = r_llc_proc_id_get(param_1,1);
      uVar4 = param_1 << 8 | iVar1 << 0x10 | 0xc;
      uVar2 = 0x800300a6;
    }
  }
  else {
_L235:
    uVar4 = param_1 << 8 | 0xc;
    uVar2 = 0x800300a4;
  }
  r_ble_log_internal_x1(uVar2,uVar4);
  uVar2 = 0xc;
_L237:
  r_llc_cmd_cmp_send(param_1,param_3,uVar2);
  return 0;
}

