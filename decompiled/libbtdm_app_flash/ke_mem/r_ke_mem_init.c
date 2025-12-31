/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
 * Source: libbtdm_app_flash -> ke_mem.o -> r_ke_mem_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_ke_mem_init(int param_1,int param_2,uint param_3)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)(param_2 + 3U & 0xfffffffc);
  *(undefined2 **)(&r_osi_funcs_p + (param_1 + 4) * 4) = puVar1;
  puVar1[1] = ((short)param_2 + (short)param_3 & 0xfffcU) - (short)puVar1;
  *puVar1 = 0xa55a;
  *(undefined4 *)(puVar1 + 2) = 0;
  *(undefined4 *)(puVar1 + 4) = 0;
  *(short *)(&r_osi_funcs_p + (param_1 + 0x10) * 2) = (short)param_3;
  r_ble_log_internal_x2(0x402a0208,param_3 | param_1 << 0x10);
  return;
}

