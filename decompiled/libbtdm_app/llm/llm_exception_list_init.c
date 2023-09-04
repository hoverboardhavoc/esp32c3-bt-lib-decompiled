/*
 * Last changed at upstream commit 9e82ccc6cd24923b2e46e5b05064ccbbf1b2ac09
 * https://github.com/espressif/esp32c3-bt-lib/commit/9e82ccc6cd24923b2e46e5b05064ccbbf1b2ac09
 * Upstream date: 2023-09-04 20:35:54 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(3a1003fc)
 * Source: libbtdm_app -> llm.o -> llm_exception_list_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void llm_exception_list_init(void)

{
  int iVar1;
  
  iVar1 = (**(code **)(_r_ip_funcs_p + 0x924))(*(code **)(_r_ip_funcs_p + 0x924));
  (**(code **)(_r_modules_funcs_p + 0x2c))(iVar1 + 0x2c,*(code **)(_r_modules_funcs_p + 0x2c));
                    /* WARNING: Could not recover jumptable at 0x00010430. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_modules_funcs_p + 0x2c))(iVar1 + 0x34);
  return;
}

