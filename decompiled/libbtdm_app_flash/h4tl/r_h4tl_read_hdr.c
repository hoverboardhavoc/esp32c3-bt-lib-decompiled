/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> h4tl.o -> r_h4tl_read_hdr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_h4tl_read_hdr(undefined4 *param_1)

{
  *(undefined1 *)(param_1 + 5) = 1;
  (**(code **)*param_1)((int)param_1 + 10,r_h4tl_rx_done,param_1,*(code **)*param_1);
  r_rwip_prevent_sleep_set(4);
  return;
}

