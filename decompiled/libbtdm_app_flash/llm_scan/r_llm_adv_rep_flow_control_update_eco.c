/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llm_scan.o -> r_llm_adv_rep_flow_control_update_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char r_llm_adv_rep_flow_control_update_eco(int param_1)

{
  int iVar1;
  
  if (((*(char *)(_p_llm_env + 0xd7) == '\x01') ||
      ((*(char *)(_p_llm_env + 0xd7) == '\x02' && ((*(byte *)(param_1 + 0x15) & 0x10) != 0)))) &&
     (0x1f < *(byte *)(param_1 + 0x20))) {
    return '\x01';
  }
  iVar1 = r_llm_le_adv_report_ind_duplicate_check(param_1);
  if (iVar1 == 0) {
    return '\x01';
  }
  if ((DAT_0001408e != '\0') && (*(char *)(_p_llm_env + 0xd7) == '\x01')) {
    if (_llm_le_adv_flow_env == 0) {
      _memcmp = _memcmp + 1;
      return DAT_0001408e;
    }
    _llm_le_adv_flow_env = _llm_le_adv_flow_env + -1;
  }
  return '\0';
}

