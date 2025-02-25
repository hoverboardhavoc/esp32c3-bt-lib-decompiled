/*
 * Last changed at upstream commit 2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * https://github.com/espressif/esp32c3-bt-lib/commit/2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * Upstream date: 2025-02-25 15:16:47 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(723439d)
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

