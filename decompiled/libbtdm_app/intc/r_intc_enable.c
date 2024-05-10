/*
 * Last changed at upstream commit 1a086eab61e78fa243d67c33206ece4022129ee1
 * https://github.com/espressif/esp32c3-bt-lib/commit/1a086eab61e78fa243d67c33206ece4022129ee1
 * Upstream date: 2024-05-10 19:28:08 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(eca46a0)
 * Source: libbtdm_app -> intc.o -> r_intc_enable
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_intc_enable(void)

{
  (**(code **)(_r_osi_funcs_p + 0xcc))(_LANCHOR0,*(code **)(_r_osi_funcs_p + 0xcc));
                    /* WARNING: Could not recover jumptable at 0x00010342. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_osi_funcs_p + 0xcc))(_LANCHOR1);
  return;
}

