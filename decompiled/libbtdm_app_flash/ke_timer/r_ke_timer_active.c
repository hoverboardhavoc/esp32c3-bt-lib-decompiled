/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> ke_timer.o -> r_ke_timer_active
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool r_ke_timer_active(uint param_1,uint param_2)

{
  int *piVar1;
  
  for (piVar1 = (int *)_r_ke_msg_send_basic;
      (piVar1 != (int *)0x0 &&
      ((*(ushort *)(piVar1 + 1) != param_1 || (*(ushort *)((int)piVar1 + 6) != param_2))));
      piVar1 = (int *)*piVar1) {
  }
  return piVar1 != (int *)0x0;
}

