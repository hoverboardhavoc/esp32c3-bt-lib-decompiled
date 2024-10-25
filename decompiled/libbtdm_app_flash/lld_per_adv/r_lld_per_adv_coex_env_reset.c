/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld_per_adv.o -> r_lld_per_adv_coex_env_reset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_per_adv_coex_env_reset(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 != 0) {
    uVar1 = r_rwip_time_get();
    *(undefined4 *)(param_1 + 0x5c) = uVar1;
    return;
  }
  return;
}

