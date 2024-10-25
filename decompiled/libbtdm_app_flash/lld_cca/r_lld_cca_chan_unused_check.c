/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld_cca.o -> r_lld_cca_chan_unused_check
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_cca_chan_unused_check(byte *param_1)

{
  byte *pbVar1;
  
  if (param_1[8] == *(byte *)(p_lld_cca + 0x1a)) {
    pbVar1 = (byte *)(*(int *)(p_lld_cca + 0x1c) + (uint)(*(byte *)(p_lld_cca + 8) >> 3));
    *pbVar1 = ~(byte)(1 << (*(byte *)(p_lld_cca + 8) & 7)) & *pbVar1;
    param_1[8] = 0;
    *param_1 = *param_1 | 4;
  }
  return;
}

