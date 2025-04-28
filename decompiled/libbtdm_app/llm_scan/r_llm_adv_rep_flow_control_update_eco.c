/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llm_scan.o -> r_llm_adv_rep_flow_control_update_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char r_llm_adv_rep_flow_control_update_eco(int param_1)

{
  char cVar1;
  int iVar2;
  
  if ((((*(char *)(_p_llm_env + 0xd7) != '\x01') &&
       ((*(char *)(_p_llm_env + 0xd7) != '\x02' || ((*(byte *)(param_1 + 0x15) & 0x10) == 0)))) ||
      (*(byte *)(param_1 + 0x20) < 0x20)) &&
     (iVar2 = (**(code **)(_r_ip_funcs_p + 0x8d4))(param_1,*(code **)(_r_ip_funcs_p + 0x8d4)),
     iVar2 != 0)) {
    cVar1 = DAT_00014042;
    if (DAT_00014042 != '\0') {
      if (*(char *)(_p_llm_env + 0xd7) == '\x01') {
        if (_llm_le_adv_flow_env == 0) {
          _memcmp = _memcmp + 1;
          return DAT_00014042;
        }
        _llm_le_adv_flow_env = _llm_le_adv_flow_env + -1;
      }
      cVar1 = '\0';
    }
    return cVar1;
  }
  return '\x01';
}

