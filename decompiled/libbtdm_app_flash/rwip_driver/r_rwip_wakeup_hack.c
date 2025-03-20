/*
 * Last changed at upstream commit daab5dbba958a13041bd496e4a6ed506c9284a06
 * https://github.com/espressif/esp32c3-bt-lib/commit/daab5dbba958a13041bd496e4a6ed506c9284a06
 * Upstream date: 2025-03-20 20:43:40 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(86a4da5c)
 * Source: libbtdm_app_flash -> rwip_driver.o -> r_rwip_wakeup_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_rwip_wakeup_hack(void)

{
  int iVar1;
  
  iVar1 = r_sdk_config_get_opts_ext();
  if ((*(uint *)(iVar1 + 0x28) & 0x200) != 0) {
    iVar1 = r_sdk_config_get_opts_ext();
    if (*(byte *)(iVar1 + 0x2c) < 3) {
      r_ble_log_internal_x1(0x400c0003,_DAT_60042008);
    }
  }
  r_rwip_wakeup();
  _DAT_6003100c = 0x600009;
  return;
}

