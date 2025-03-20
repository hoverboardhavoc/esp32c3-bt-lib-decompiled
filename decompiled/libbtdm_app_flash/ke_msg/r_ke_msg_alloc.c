/*
 * Last changed at upstream commit aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * https://github.com/espressif/esp32c3-bt-lib/commit/aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * Upstream date: 2025-03-20 20:31:24 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(d74042a8)
 * Source: libbtdm_app_flash -> ke_msg.o -> r_ke_msg_alloc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 * r_ke_msg_alloc(undefined2 param_1,undefined2 param_2,undefined2 param_3,size_t param_4)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)r_ke_malloc(param_4 + 0xc,2);
  if (puVar1 == (undefined4 *)0x0) {
    r_assert_err("ke_msg.c",0x37);
  }
  *(undefined2 *)(puVar1 + 1) = param_1;
  *(undefined2 *)((int)puVar1 + 6) = param_2;
  *(undefined2 *)(puVar1 + 2) = param_3;
  *(short *)((int)puVar1 + 10) = (short)param_4;
  *puVar1 = 0xffffffff;
  memset(puVar1 + 3,0,param_4);
  return puVar1 + 3;
}

