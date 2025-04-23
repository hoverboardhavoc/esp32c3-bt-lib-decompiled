/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> ke_msg.o -> ke_msg_find_by_id
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ke_msg_find_by_id(uint param_1,int *param_2)

{
  for (param_2 = (int *)*param_2; (param_2 != (int *)0x0 && (*(ushort *)(param_2 + 1) != param_1));
      param_2 = (int *)*param_2) {
  }
  return;
}

