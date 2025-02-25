/*
 * Last changed at upstream commit 2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * https://github.com/espressif/esp32c3-bt-lib/commit/2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * Upstream date: 2025-02-25 15:16:47 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(723439d)
 * Source: libbtdm_app_flash -> ble_log.o -> r_ble_log_init_simple
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_ble_log_init_simple(int param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    return 0xffffffff;
  }
  ble_log_env = (void *)(**(code **)(_r_osi_funcs_p + 0x74))(0x10,*(code **)(_r_osi_funcs_p + 0x74))
  ;
  if (ble_log_env == (void *)0x0) {
    uVar2 = 0xffffffff;
  }
  else {
    memset(ble_log_env,0,0x14);
    pvVar1 = ble_log_env;
    *(int *)((int)ble_log_env + 4) = param_1;
    *(undefined **)((int)pvVar1 + 8) = &r_ble_log_simple_output;
    uVar2 = 0;
  }
  return uVar2;
}

