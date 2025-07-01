/*
 * Last changed at upstream commit 0c68809d62e432427de97b5294f6619307f62f40
 * https://github.com/espressif/esp32c3-bt-lib/commit/0c68809d62e432427de97b5294f6619307f62f40
 * Upstream date: 2025-07-01 15:07:54 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2edb0b0)
 * Source: libbtdm_app_flash -> rwip_driver.o -> r_rwip_crypt_isr_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_rwip_crypt_isr_handler(void)

{
  int iVar1;
  
  r_rwip_prevent_sleep_clear_hack(0x20);
  _DAT_6003100c = _DAT_6003100c & 0xffffff7f;
  if (sdk_cfg_priv_opts != '\0') {
    _DAT_6003138c = 0x80;
  }
  iVar1 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar1 + 0x20) != '\0') {
    r_ke_event_set(2);
    return;
  }
  return;
}

