/*
 * Last changed at upstream commit daab5dbba958a13041bd496e4a6ed506c9284a06
 * https://github.com/espressif/esp32c3-bt-lib/commit/daab5dbba958a13041bd496e4a6ed506c9284a06
 * Upstream date: 2025-03-20 20:43:40 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(86a4da5c)
 * Source: libbtdm_app_flash -> ke_mem.o -> r_ke_mem_is_in_heap
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool r_ke_mem_is_in_heap(int param_1,uint param_2)

{
  if (*(uint *)(r_ble_log_internal_x2 + (param_1 + 4) * 4) <= param_2) {
    return param_2 <=
           *(uint *)(r_ble_log_internal_x2 + (param_1 + 4) * 4) +
           (uint)*(ushort *)(r_ble_log_internal_x2 + (param_1 + 0x10) * 2);
  }
  return false;
}

