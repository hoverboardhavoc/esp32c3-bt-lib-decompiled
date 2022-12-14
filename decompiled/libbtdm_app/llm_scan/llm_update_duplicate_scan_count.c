/*
 * Last changed at upstream commit bba9af9259e0999ef246426d31a793fe0a3ff4db
 * https://github.com/espressif/esp32c3-bt-lib/commit/bba9af9259e0999ef246426d31a793fe0a3ff4db
 * Upstream date: 2022-12-14 15:32:37 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(80abacdd)
 * Source: libbtdm_app -> llm_scan.o -> llm_update_duplicate_scan_count
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void llm_update_duplicate_scan_count(void)

{
  int iVar1;
  uint uVar2;
  
  if (((*(char *)(_p_llm_env + 0xd7) != '\x02') &&
      (iVar1 = sdk_config_get_opts_ext(), *(short *)(iVar1 + 0x16) != 0)) &&
     ((*(byte *)(_p_llm_env + 0xd4) & 1) != 0)) {
    _sdk_config_get_opts_ext = _sdk_config_get_opts_ext + 1;
    if (_r_llm_adv_rep_flow_control_update <= _sdk_config_get_opts_ext) {
      _sdk_config_get_opts_ext = 0;
      DAT_00012060 = 1;
    }
    if (llm_util_flush_list != (code)0x0) {
      uVar2 = 1;
      _co_rate_to_phy = _co_rate_to_phy + 1;
      if (5 < _r_llm_adv_rep_flow_control_update) {
        uVar2 = _r_llm_adv_rep_flow_control_update / 6;
      }
      if (uVar2 <= _co_rate_to_phy) {
        _co_rate_to_phy = 0;
        DAT_00012061 = 1;
      }
    }
  }
  return;
}

