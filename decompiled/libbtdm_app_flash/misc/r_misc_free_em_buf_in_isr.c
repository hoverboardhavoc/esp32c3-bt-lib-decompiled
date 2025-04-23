/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> misc.o -> r_misc_free_em_buf_in_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_misc_free_em_buf_in_isr(undefined1 param_1,undefined2 param_2)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)r_ke_msg_alloc(0x901,4,0xff);
  if (puVar1 != (undefined1 *)0x0) {
    *puVar1 = param_1;
    *(undefined2 *)(puVar1 + 2) = param_2;
    r_ke_msg_send();
    return;
  }
  r_assert_err("misc.c",0xa3);
  return;
}

