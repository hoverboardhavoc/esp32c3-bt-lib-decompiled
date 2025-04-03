/*
 * Last changed at upstream commit f23a340e82d6a4be40f83214385a98c5bd30ccdd
 * https://github.com/espressif/esp32c3-bt-lib/commit/f23a340e82d6a4be40f83214385a98c5bd30ccdd
 * Upstream date: 2025-04-03 18:07:15 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(a684dd5)
 * Source: libbtdm_app_flash -> ke_msg.o -> ke_msg_find_by_id
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int ke_msg_find_by_id(uint param_1,int *param_2)

{
  for (param_2 = (int *)*param_2; (param_2 != (int *)0x0 && (*(ushort *)(param_2 + 1) != param_1));
      param_2 = (int *)*param_2) {
  }
  return (int)param_2;
}

