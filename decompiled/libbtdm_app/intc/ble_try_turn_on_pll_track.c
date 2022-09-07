/*
 * Last changed at upstream commit 2a91d90e33b3b1104daf1bff898fe5bc3f814811
 * https://github.com/espressif/esp32c3-bt-lib/commit/2a91d90e33b3b1104daf1bff898fe5bc3f814811
 * Upstream date: 2022-09-07 12:18:28 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(2ee0168e)
 * Source: libbtdm_app -> intc.o -> ble_try_turn_on_pll_track
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 ble_try_turn_on_pll_track(void)

{
  undefined4 extraout_a1;
  uint uVar1;
  
  if (_LANCHOR0 == '\0') {
    _LANCHOR1 = rwip_gross_time_get_raw();
    uVar1 = _LANCHOR1 - _LANCHOR2 & 0xfffffff;
    DAT_000103e0 = extraout_a1;
    if ((uVar1 < 0x8000001) && (0xc80 < uVar1)) {
      _LANCHOR2 = _LANCHOR1;
      (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
      _DAT_60011084 = _DAT_60011084 | 0x18000;
      _LANCHOR0 = 1;
      (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
      return 1;
    }
  }
  return 0;
}

