/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
 * Source: libbtdm_app_flash -> arch_main.o -> btdm_controller_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void btdm_controller_deinit(void)

{
  int iVar1;
  
  iVar1 = r_sdk_config_get_opts();
  if (*(char *)(iVar1 + 0xc) != '\0') {
    btdm_controller_disable();
  }
  r_btdm_task_post_hack(8,0,0,1);
  (**(code **)(_r_osi_funcs_p + 0x34))(_g_rw_init_sem,10000,*(code **)(_r_osi_funcs_p + 0x34));
  btdm_controller_deinit_internal();
  r_ble_log_internal_x0(0x40c80225);
  return;
}

