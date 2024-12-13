/*
 * Last changed at upstream commit c57c0b11c3c0065a16b66685715100a189ef9b27
 * https://github.com/espressif/esp32c3-bt-lib/commit/c57c0b11c3c0065a16b66685715100a189ef9b27
 * Upstream date: 2024-12-13 13:39:25 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(555b0a2)
 * Source: libbtdm_app_flash -> llm_scan.o -> r_llm_init_ble_adv_report_flow_contol
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llm_init_ble_adv_report_flow_contol(int param_1,int param_2,undefined4 param_3)

{
  if ((param_1 == 0) || (param_2 == 0)) {
    DAT_0001408a = 0;
    _llm_le_adv_flow_env = 0;
    _co_rate_to_phy = 0;
  }
  else {
    DAT_0001408a = 1;
    _llm_le_adv_flow_env = (undefined2)param_2;
    _co_rate_to_phy = param_3;
  }
  _memcmp = 0;
  return;
}

