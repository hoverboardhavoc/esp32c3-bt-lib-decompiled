/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llm_hci.o -> r_llm_aes_res_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_llm_aes_res_cb(undefined1 param_1,void *param_2)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)r_ke_msg_alloc(7,0,0,0x11);
  *puVar1 = param_1;
  memcpy(puVar1 + 1,param_2,0x10);
  r_ke_msg_send(puVar1);
  return;
}

