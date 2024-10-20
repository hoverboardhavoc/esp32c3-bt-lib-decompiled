/*
 * Last changed at upstream commit eeb2782618e0ab8cf0cf609c98c6a0c86d691a6c
 * https://github.com/espressif/esp32c3-bt-lib/commit/eeb2782618e0ab8cf0cf609c98c6a0c86d691a6c
 * Upstream date: 2024-10-20 16:32:16 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(52ee788)
 * Source: libbtdm_app -> lld.o -> lld_aux_ptr_thr_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 lld_aux_ptr_thr_set(uint param_1,uint param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0x12;
  if ((param_1 < 0xff1) && (param_2 < 0xff1)) {
    if (param_1 != 0) {
      _DAT_60031120 = (param_1 >> 4) << 0x18 | _DAT_60031120 & 0xffffff;
    }
    uVar1 = 0;
    if (param_2 != 0) {
      _DAT_60031120 = (param_2 >> 4) << 0x10 | _DAT_60031120 & 0xff00ffff;
      return uVar1;
    }
  }
  return uVar1;
}

