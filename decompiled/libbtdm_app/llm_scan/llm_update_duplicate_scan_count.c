/*
 * Last changed at upstream commit 3b0038690a644498d6d80f1de8df0efff8cd8cf5
 * https://github.com/espressif/esp32c3-bt-lib/commit/3b0038690a644498d6d80f1de8df0efff8cd8cf5
 * Upstream date: 2022-08-11 21:28:16 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(f2e5d813)
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
    _DAT_00012058 = _DAT_00012058 + 1;
    if (_r_llm_adv_rep_flow_control_update <= _DAT_00012058) {
      _DAT_00012058 = 0;
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

