/*
 * Last changed at upstream commit 4f71ee7fab59e3114d0ac0144b38df973c90261e
 * https://github.com/espressif/esp32c3-bt-lib/commit/4f71ee7fab59e3114d0ac0144b38df973c90261e
 * Upstream date: 2023-04-14 16:45:28 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(02de671f)
 * Source: libbtdm_app -> lld_scan.o -> r_lld_scan_try_sched_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_scan_try_sched_hack(void)

{
  undefined2 uVar1;
  
  uVar1 = _r_lld_scan_try_sched;
  _r_lld_scan_try_sched = 0x9c4;
  r_lld_scan_try_sched();
  _r_lld_scan_try_sched = uVar1;
  return;
}

