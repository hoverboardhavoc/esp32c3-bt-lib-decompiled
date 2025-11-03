/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> llm_scan.o -> r_llm_adv_rep_flow_control_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char r_llm_adv_rep_flow_control_update(void)

{
  char cVar1;
  
  cVar1 = DAT_00014096;
  if (DAT_00014096 != '\0') {
    if (*(char *)(_p_llm_env + 0xd7) == '\x01') {
      if (_llm_le_adv_flow_env == 0) {
        _memcmp = _memcmp + 1;
        return DAT_00014096;
      }
      _llm_le_adv_flow_env = _llm_le_adv_flow_env + -1;
    }
    cVar1 = '\0';
  }
  return cVar1;
}

