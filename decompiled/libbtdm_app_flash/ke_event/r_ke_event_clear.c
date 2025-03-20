/*
 * Last changed at upstream commit daab5dbba958a13041bd496e4a6ed506c9284a06
 * https://github.com/espressif/esp32c3-bt-lib/commit/daab5dbba958a13041bd496e4a6ed506c9284a06
 * Upstream date: 2025-03-20 20:43:40 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(86a4da5c)
 * Source: libbtdm_app_flash -> ke_event.o -> r_ke_event_clear
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_ke_event_clear(uint param_1)

{
  int iVar1;
  
  if (0xe < param_1) {
    r_assert_param(0,"ke_event.c",0x85);
  }
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  if (param_1 < 0xf) {
    _ke_event_env = ~(1 << (param_1 & 0x1f)) & _ke_event_env;
  }
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  iVar1 = r_sdk_config_get_opts_ext();
  if ((*(uint *)(iVar1 + 0x28) & 2) != 0) {
    iVar1 = r_sdk_config_get_opts_ext();
    if (*(byte *)(iVar1 + 0x2c) < 3) {
      r_ble_log_internal_x1(0x40050001,param_1);
      return;
    }
  }
  return;
}

