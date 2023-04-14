/*
 * Last changed at upstream commit 4f71ee7fab59e3114d0ac0144b38df973c90261e
 * https://github.com/espressif/esp32c3-bt-lib/commit/4f71ee7fab59e3114d0ac0144b38df973c90261e
 * Upstream date: 2023-04-14 16:45:28 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(02de671f)
 * Source: libbtdm_app -> rwble.o -> r_rwble_isr_hw_fixed_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_rwble_isr_hw_fixed_hack(void)

{
  int iVar1;
  
  iVar1 = r_rwble_isr_hw_fixed();
  if (iVar1 != 0) {
    _g_bt_plf_log_level = 3;
  }
  return;
}

