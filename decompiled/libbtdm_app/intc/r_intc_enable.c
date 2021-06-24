/*
 * Last changed at upstream commit b223604efd557d0a5314afb3b751229df424d244
 * https://github.com/espressif/esp32c3-bt-lib/commit/b223604efd557d0a5314afb3b751229df424d244
 * Upstream date: 2021-06-24 21:26:02 +0800
 * Upstream subject: Update ESP32-C3 and ESP32-S3 bt lib (9c99115)
 * Source: libbtdm_app -> intc.o -> r_intc_enable
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_intc_enable(void)

{
  (**(code **)(_r_osi_funcs_p + 0xbc))(5,*(code **)(_r_osi_funcs_p + 0xbc));
                    /* WARNING: Could not recover jumptable at 0x000100d4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_osi_funcs_p + 0xbc))(8);
  return;
}

