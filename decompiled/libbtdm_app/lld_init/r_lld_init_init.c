/*
 * Last changed at upstream commit a3f7d7ffa2b261b1415042d8b7cd457cc2b4b1de
 * https://github.com/espressif/esp32c3-bt-lib/commit/a3f7d7ffa2b261b1415042d8b7cd457cc2b4b1de
 * Upstream date: 2021-12-28 18:10:18 +0800
 * Upstream subject: Update ESP32-C3 and ESP32-S3 bt lib (33175c8)
 * Source: libbtdm_app -> lld_init.o -> r_lld_init_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_init_init(int param_1)

{
  if (param_1 == 1) {
    lld_init_env = (int *)0x0;
    return;
  }
  if (param_1 == 2) {
    if (lld_init_env != (int *)0x0) {
      if (lld_init_env[2] != 0) {
        (**(code **)(_r_modules_funcs_p + 0xd8))
                  (lld_init_env[2] + -0xc,*(code **)(_r_modules_funcs_p + 0xd8));
      }
      if (*lld_init_env != 0) {
        (**(code **)(_r_modules_funcs_p + 0x110))(*(code **)(_r_modules_funcs_p + 0x110));
      }
      if (lld_init_env[1] != 0) {
        (**(code **)(_r_modules_funcs_p + 0x110))(*(code **)(_r_modules_funcs_p + 0x110));
      }
      (**(code **)(_r_modules_funcs_p + 0x110))(lld_init_env,*(code **)(_r_modules_funcs_p + 0x110))
      ;
      lld_init_env = (int *)0x0;
    }
    return;
  }
  return;
}

