/*
 * Last changed at upstream commit aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * https://github.com/espressif/esp32c3-bt-lib/commit/aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * Upstream date: 2025-03-20 20:31:24 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(d74042a8)
 * Source: libbtdm_app_flash -> ke_mem.o -> r_ke_mem_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_ke_mem_init(int param_1,int param_2,short param_3)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)(param_2 + 3U & 0xfffffffc);
  *(undefined2 **)(r_assert_err + (param_1 + 4) * 4) = puVar1;
  puVar1[1] = ((short)param_2 + param_3 & 0xfffcU) - (short)puVar1;
  *puVar1 = 0xa55a;
  *(undefined4 *)(puVar1 + 2) = 0;
  *(undefined4 *)(puVar1 + 4) = 0;
  *(short *)(r_assert_err + (param_1 + 0x10) * 2) = param_3;
  return;
}

