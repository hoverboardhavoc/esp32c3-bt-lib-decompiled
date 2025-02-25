/*
 * Last changed at upstream commit 2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * https://github.com/espressif/esp32c3-bt-lib/commit/2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * Upstream date: 2025-02-25 15:16:47 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(723439d)
 * Source: libbtdm_app_flash -> ke_msg.o -> r_ke_msg_alloc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 * r_ke_msg_alloc(undefined2 param_1,undefined2 param_2,undefined2 param_3,size_t param_4)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)r_ke_malloc(param_4 + 0xc,2);
  if (puVar1 == (undefined4 *)0x0) {
    r_assert_err("ke_msg.c",0x37);
  }
  *(undefined2 *)(puVar1 + 2) = param_3;
  *puVar1 = 0xffffffff;
  *(undefined2 *)(puVar1 + 1) = param_1;
  *(undefined2 *)((int)puVar1 + 6) = param_2;
  *(short *)((int)puVar1 + 10) = (short)param_4;
  memset(puVar1 + 3,0,param_4);
  iVar2 = r_sdk_config_get_opts_ext();
  if ((*(uint *)(iVar2 + 0x28) & 2) != 0) {
    iVar2 = r_sdk_config_get_opts_ext();
    if (*(byte *)(iVar2 + 0x2c) < 3) {
      r_ble_log_internal_x1(0x40450009,puVar1);
    }
  }
  return puVar1 + 3;
}

