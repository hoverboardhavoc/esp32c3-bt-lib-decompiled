/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld.o -> lld_aux_ptr_thr_set
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

