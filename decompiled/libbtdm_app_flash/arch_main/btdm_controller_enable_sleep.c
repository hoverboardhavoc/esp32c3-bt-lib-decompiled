/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> arch_main.o -> btdm_controller_enable_sleep
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void btdm_controller_enable_sleep(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = r_sdk_config_get_opts();
  if (*(char *)(iVar1 + 0xe) == '\x01') {
    r_sdk_config_set_bt_sleep_enable(param_1);
    return;
  }
  return;
}

