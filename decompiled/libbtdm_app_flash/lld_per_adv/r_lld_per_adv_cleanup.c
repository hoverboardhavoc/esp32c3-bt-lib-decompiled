/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
 * Source: libbtdm_app_flash -> lld_per_adv.o -> r_lld_per_adv_cleanup
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_per_adv_cleanup(int param_1)

{
  int *piVar1;
  
  piVar1 = (int *)(&lld_per_adv_env + param_1 * 4);
  if (*piVar1 != 0) {
    r_ble_log_internal_x1(0x40040105,param_1 << 0x10 | (uint)*(ushort *)(*piVar1 + 0x4c));
    r_ke_free(*piVar1);
    *piVar1 = 0;
    return;
  }
  r_ble_log_internal_x1(0x80040106,param_1);
  return;
}

