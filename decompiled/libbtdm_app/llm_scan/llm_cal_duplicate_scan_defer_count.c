/*
 * Last changed at upstream commit bba9af9259e0999ef246426d31a793fe0a3ff4db
 * https://github.com/espressif/esp32c3-bt-lib/commit/bba9af9259e0999ef246426d31a793fe0a3ff4db
 * Upstream date: 2022-12-14 15:32:37 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(80abacdd)
 * Source: libbtdm_app -> llm_scan.o -> llm_cal_duplicate_scan_defer_count
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void llm_cal_duplicate_scan_defer_count(int param_1)

{
  int iVar1;
  
  if (*(char *)(_p_llm_env + 0xd7) == '\x02') {
    return;
  }
  iVar1 = sdk_config_get_opts_ext();
  if (*(short *)(iVar1 + 0x16) != 0) {
    iVar1 = sdk_config_get_opts_ext();
    _r_llm_adv_rep_flow_control_update = (int)((uint)*(ushort *)(iVar1 + 0x16) * 0x640) / param_1;
    if (_r_llm_adv_rep_flow_control_update == 0) {
      _r_llm_adv_rep_flow_control_update = 1;
    }
    _sdk_config_get_opts_ext = 0;
  }
  return;
}

