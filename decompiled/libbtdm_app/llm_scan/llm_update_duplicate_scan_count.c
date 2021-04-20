/*
 * Last changed at upstream commit 352d001fc7f5d34243047454b3f9e684577ce3e0
 * https://github.com/espressif/esp32c3-bt-lib/commit/352d001fc7f5d34243047454b3f9e684577ce3e0
 * Upstream date: 2021-04-20 15:58:00 +0800
 * Upstream subject: ESP32C3, ESP32S3: update libbtdm_app.a(47235b66)
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
    _DAT_00012048 = _DAT_00012048 + 1;
    if (_r_llm_adv_rep_flow_control_update <= _DAT_00012048) {
      _DAT_00012048 = 0;
      DAT_00012050 = 1;
    }
    if (adv_evt_prop2type != '\0') {
      uVar1 = 1;
      if (5 < _r_llm_adv_rep_flow_control_update) {
        uVar1 = _r_llm_adv_rep_flow_control_update / 6;
      }
      if (_DAT_0001204c + 1 < uVar1) {
        _DAT_0001204c = _DAT_0001204c + 1;
        return;
      }
      _DAT_0001204c = 0;
      DAT_00012051 = 1;
    }
  }
  return;
}

