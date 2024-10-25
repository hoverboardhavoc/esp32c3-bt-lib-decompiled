/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llm_scan.o -> r_llm_init_ble_adv_report_flow_contol
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llm_init_ble_adv_report_flow_contol(int param_1,int param_2,undefined4 param_3)

{
  if ((param_1 == 0) || (param_2 == 0)) {
    DAT_0001403e = 0;
    _llm_le_adv_flow_env = 0;
    _g_bt_plf_log_level = 0;
  }
  else {
    DAT_0001403e = 1;
    _llm_le_adv_flow_env = (undefined2)param_2;
    _g_bt_plf_log_level = param_3;
  }
  _memcmp = 0;
  return;
}

