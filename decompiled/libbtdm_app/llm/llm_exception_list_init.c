/*
 * Last changed at upstream commit 352d001fc7f5d34243047454b3f9e684577ce3e0
 * https://github.com/espressif/esp32c3-bt-lib/commit/352d001fc7f5d34243047454b3f9e684577ce3e0
 * Upstream date: 2021-04-20 15:58:00 +0800
 * Upstream subject: ESP32C3, ESP32S3: update libbtdm_app.a(47235b66)
 * Source: libbtdm_app -> llm.o -> llm_exception_list_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void llm_exception_list_init(void)

{
  (**(code **)(_r_modules_funcs_p + 0x2c))(&DAT_000107f8,*(code **)(_r_modules_funcs_p + 0x2c));
                    /* WARNING: Could not recover jumptable at 0x0001036c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_modules_funcs_p + 0x2c))(&DAT_00010800);
  return;
}

