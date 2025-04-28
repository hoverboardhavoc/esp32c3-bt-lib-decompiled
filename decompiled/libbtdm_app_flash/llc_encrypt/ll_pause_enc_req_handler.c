/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llc_encrypt.o -> ll_pause_enc_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 ll_pause_enc_req_handler(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar2 + 0x20) == '\0') {
    return 0x24;
  }
  if (((*(ushort *)(*(int *)(&llc_env + param_1 * 4) + 0x42) & 1) == 0) &&
     (iVar2 = r_llc_proc_id_get(1,param_2), iVar2 == 0)) {
    puVar1 = (undefined4 *)r_ke_msg_alloc(0x109,1,1,0x3c);
    *(undefined1 *)(puVar1 + 1) = 3;
    r_llc_proc_state_set(param_1,10);
    *puVar1 = r_llc_rem_encrypt_proc_err_cb;
    *(undefined1 *)((int)puVar1 + 0x3a) = 1;
    r_llc_proc_reg(param_1,1,puVar1);
    r_llc_rem_encrypt_proc_continue_eco(param_1,10,0);
    uVar3 = 0;
  }
  else {
    uVar3 = 0x24;
  }
  return uVar3;
}

