/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
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
    r_ble_log_internal_x1(0x400400a5,param_1 << 0x10 | (uint)*(ushort *)(*piVar1 + 0x4c));
    r_ke_free(*piVar1);
    *piVar1 = 0;
    return;
  }
  r_ble_log_internal_x1(0x800400a6,param_1);
  return;
}

