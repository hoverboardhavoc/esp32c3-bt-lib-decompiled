/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llm_scan.o -> r_llm_adv_rep_flow_control_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char r_llm_adv_rep_flow_control_update(void)

{
  char cVar1;
  
  cVar1 = DAT_0001403e;
  if (DAT_0001403e != '\0') {
    if (*(char *)(_p_llm_env + 0xd7) == '\x01') {
      if (_llm_le_adv_flow_env == 0) {
        _memcmp = _memcmp + 1;
        return DAT_0001403e;
      }
      _llm_le_adv_flow_env = _llm_le_adv_flow_env + -1;
    }
    cVar1 = '\0';
  }
  return cVar1;
}

