/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> llm.o -> esp_ble_enable_ch_assess
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void esp_ble_enable_ch_assess(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = _p_llm_env;
  *(bool *)(_p_llm_env + 0xd9) = param_1 != 0;
  if (param_2 != 0) {
    *(undefined1 *)(iVar1 + 0x22) = 0;
    r_ke_timer_set(4,0,(uint)_sdk_cfg_priv_opts * 100);
    return;
  }
  r_ke_timer_clear(4);
  *(undefined1 *)(_p_llm_env + 0x22) = 1;
  return;
}

