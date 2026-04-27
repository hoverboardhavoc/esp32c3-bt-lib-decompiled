/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> llc_encrypt.o -> ll_pause_enc_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 ll_pause_enc_req_handler(uint param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar3 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar3 + 0x20) == '\0') {
    return 0x24;
  }
  if ((*(ushort *)(*(int *)(&llc_env + param_1 * 4) + 0x42) & 1) == 0) {
    iVar3 = r_llc_proc_id_get(1,param_2);
    if (iVar3 == 0) {
      puVar2 = (undefined4 *)r_ke_msg_alloc(0x109,1,1,0x3c);
      *(undefined1 *)(puVar2 + 1) = 3;
      r_llc_proc_state_set(param_1,10);
      *puVar2 = r_llc_rem_encrypt_proc_err_cb;
      *(undefined1 *)((int)puVar2 + 0x3a) = 1;
      r_llc_proc_reg(param_1,1,puVar2);
      r_llc_rem_encrypt_proc_continue_eco(param_1,10,0);
      return 0;
    }
    iVar3 = r_llc_proc_id_get(param_1,1);
    param_1 = iVar3 << 8 | param_1;
    uVar1 = 0x604f00a0;
  }
  else {
    uVar1 = 0x604f009f;
  }
  r_ble_log_internal_x1(uVar1,param_1);
  return 0x24;
}

