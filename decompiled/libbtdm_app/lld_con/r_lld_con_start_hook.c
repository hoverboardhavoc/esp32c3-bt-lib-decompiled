/*
 * Last changed at upstream commit a17e093350f31d09b8bcbfaad40b5b35535ea97b
 * https://github.com/espressif/esp32c3-bt-lib/commit/a17e093350f31d09b8bcbfaad40b5b35535ea97b
 * Upstream date: 2023-04-28 14:11:07 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(19c7783)
 * Source: libbtdm_app -> lld_con.o -> r_lld_con_start_hook
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_lld_con_start_hook(int param_1,int param_2)

{
  int iVar1;
  
  if (param_1 != 0) {
    iVar1 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
    if (*(char *)(iVar1 + 0x18) == '\0') {
      *(undefined1 *)(param_2 + 0x26) = 0;
    }
    return 0;
  }
  return 0;
}

