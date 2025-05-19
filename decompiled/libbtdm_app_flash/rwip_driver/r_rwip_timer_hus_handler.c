/*
 * Last changed at upstream commit 72599d583c232ea78d6461b5b502426c6e5a1ec9
 * https://github.com/espressif/esp32c3-bt-lib/commit/72599d583c232ea78d6461b5b502426c6e5a1ec9
 * Upstream date: 2025-05-19 16:27:45 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(6cfabcd8)
 * Source: libbtdm_app_flash -> rwip_driver.o -> r_rwip_timer_hus_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_rwip_timer_hus_handler(void)

{
  _rwip_env = 0xffffffff;
  _DAT_6003100c = _DAT_6003100c & 0xfffff7ff;
  if (sdk_cfg_priv_opts != '\0') {
    _DAT_6003138c = 0x800;
  }
  r_sch_arb_event_start_isr_hack();
  return;
}

