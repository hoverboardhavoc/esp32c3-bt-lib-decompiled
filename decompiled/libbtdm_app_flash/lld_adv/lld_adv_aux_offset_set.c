/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> lld_adv.o -> lld_adv_aux_offset_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 lld_adv_aux_offset_set(uint param_1)

{
  undefined4 uVar1;
  
  if ((param_1 == 0xffffffff) || ((uVar1 = 0x12, param_1 < 0xff1 && (0x12a < param_1 - 1)))) {
    uVar1 = 0;
    _g_ble_ext_config = param_1;
  }
  return uVar1;
}

