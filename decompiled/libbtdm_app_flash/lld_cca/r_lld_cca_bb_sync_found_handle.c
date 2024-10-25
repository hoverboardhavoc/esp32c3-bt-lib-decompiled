/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld_cca.o -> r_lld_cca_bb_sync_found_handle
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_cca_bb_sync_found_handle(void)

{
  byte *pbVar1;
  undefined4 uVar2;
  
  pbVar1 = (byte *)(*(int *)(p_lld_cca + 0x28) + (uint)*(byte *)(p_lld_cca + 8) * 0xc);
  if ((*pbVar1 & 0x10) != 0) {
    uVar2 = r_lld_read_clock();
    *(undefined4 *)(pbVar1 + 4) = uVar2;
    r_lld_cca_force_tx(0);
    *pbVar1 = *pbVar1 & 0xe7;
  }
  return;
}

