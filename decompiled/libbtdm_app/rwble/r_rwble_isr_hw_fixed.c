/*
 * Last changed at upstream commit 5c6ab5248a124cffc731a9e4764473fdeef38054
 * https://github.com/espressif/esp32c3-bt-lib/commit/5c6ab5248a124cffc731a9e4764473fdeef38054
 * Upstream date: 2023-03-09 14:58:19 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(85a1090)
 * Source: libbtdm_app -> rwble.o -> r_rwble_isr_hw_fixed
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_rwble_isr_hw_fixed(int param_1)

{
  int *piVar1;
  
  piVar1 = (int *)(**(code **)(_r_ip_funcs_p + 0x918))(*(code **)(_r_ip_funcs_p + 0x918));
  if (param_1 == 0x20000) {
    piVar1[0x11] = piVar1[0x11] + 1;
  }
  else {
    if (param_1 != 0x400001) {
      return 0xffffffff;
    }
    *piVar1 = *piVar1 + 1;
    piVar1[0x16] = piVar1[0x16] + 1;
  }
  return 0;
}

