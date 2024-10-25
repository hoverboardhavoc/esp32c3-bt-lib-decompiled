/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> misc.o -> r_misc_free_em_buf_in_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_misc_free_em_buf_in_isr(undefined1 param_1,undefined2 param_2)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)r_ke_msg_alloc(0x901,4,0xff,4);
  if (puVar1 != (undefined1 *)0x0) {
    *puVar1 = param_1;
    *(undefined2 *)(puVar1 + 2) = param_2;
    r_ke_msg_send();
    return;
  }
  r_assert_err("misc.c",0xa3);
  return;
}

