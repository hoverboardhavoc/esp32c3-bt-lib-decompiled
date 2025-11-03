/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> ke_mem.o -> r_ke_mem_is_in_heap
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool r_ke_mem_is_in_heap(int param_1,uint param_2)

{
  if (*(uint *)(&r_osi_funcs_p + (param_1 + 4) * 4) <= param_2) {
    return param_2 <=
           (uint)*(ushort *)(&r_osi_funcs_p + (param_1 + 0x10) * 2) +
           *(uint *)(&r_osi_funcs_p + (param_1 + 4) * 4);
  }
  return false;
}

