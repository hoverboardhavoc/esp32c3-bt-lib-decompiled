/*
 * Last changed at upstream commit 5c6ab5248a124cffc731a9e4764473fdeef38054
 * https://github.com/espressif/esp32c3-bt-lib/commit/5c6ab5248a124cffc731a9e4764473fdeef38054
 * Upstream date: 2023-03-09 14:58:19 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(85a1090)
 * Source: libbtdm_app -> lld_init.o -> r_lld_init_start_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 r_lld_init_start_hack(undefined4 param_1)

{
  int iVar1;
  undefined1 uStack_11;
  
  uStack_11 = 0xc;
  iVar1 = (**(code **)(_r_ip_funcs_p + 0x838))
                    (1,&uStack_11,param_1,*(code **)(_r_ip_funcs_p + 0x838));
  if (iVar1 == 0) {
    uStack_11 = r_lld_init_start(param_1);
    (**(code **)(_r_ip_funcs_p + 0x838))(0,&uStack_11,param_1,*(code **)(_r_ip_funcs_p + 0x838));
  }
  return uStack_11;
}

