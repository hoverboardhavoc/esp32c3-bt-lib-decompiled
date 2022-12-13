/*
 * Last changed at upstream commit 84ebcda82aa5886d2a0b939dec1dbc62aa1c11c7
 * https://github.com/espressif/esp32c3-bt-lib/commit/84ebcda82aa5886d2a0b939dec1dbc62aa1c11c7
 * Upstream date: 2022-12-13 21:37:30 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3 (edd93b0)
 * Source: libbtdm_app -> llm_scan.o -> llm_update_duplicate_scan_count
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void llm_update_duplicate_scan_count(void)

{
  uint uVar1;
  
  if ((*(char *)(_p_llm_env + 0xd7) != '\x02') && ((*(byte *)(_p_llm_env + 0xd4) & 1) != 0)) {
    _co_rate_to_phy = _co_rate_to_phy + 1;
    if (_r_llm_adv_rep_flow_control_update <= _co_rate_to_phy) {
      _co_rate_to_phy = 0;
      DAT_00012060 = 1;
    }
    if (adv_evt_prop2type != '\0') {
      uVar1 = 1;
      if (5 < _r_llm_adv_rep_flow_control_update) {
        uVar1 = _r_llm_adv_rep_flow_control_update / 6;
      }
      if (_DAT_0001205c + 1 < uVar1) {
        _DAT_0001205c = _DAT_0001205c + 1;
        return;
      }
      _DAT_0001205c = 0;
      DAT_00012061 = 1;
    }
  }
  return;
}

