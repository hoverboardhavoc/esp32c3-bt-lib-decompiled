/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llc_disconnect.o -> r_llc_init_term_proc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_llc_init_term_proc(int param_1,undefined1 param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)r_ke_msg_alloc(0x108,param_1 << 8 | 1,0xc);
  *(undefined1 *)(puVar1 + 1) = 1;
  r_llc_proc_state_set(param_1,0);
  *(undefined1 *)(puVar1 + 2) = param_2;
  *(undefined1 *)((int)puVar1 + 9) = param_2;
  *puVar1 = r_llc_disconnect_proc_err_cb;
  r_ke_msg_send(puVar1);
  return;
}

