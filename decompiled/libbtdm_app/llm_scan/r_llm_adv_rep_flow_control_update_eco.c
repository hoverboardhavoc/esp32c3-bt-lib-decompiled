/*
 * Last changed at upstream commit 5c6ab5248a124cffc731a9e4764473fdeef38054
 * https://github.com/espressif/esp32c3-bt-lib/commit/5c6ab5248a124cffc731a9e4764473fdeef38054
 * Upstream date: 2023-03-09 14:58:19 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(85a1090)
 * Source: libbtdm_app -> llm_scan.o -> r_llm_adv_rep_flow_control_update_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_llm_adv_rep_flow_control_update_eco(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (((*(char *)(_p_llm_env + 0xd7) == '\x01') ||
      ((*(char *)(_p_llm_env + 0xd7) == '\x02' && ((*(byte *)(param_1 + 0x15) & 0x10) != 0)))) &&
     (0x1f < *(byte *)(param_1 + 0x20))) {
    return 1;
  }
  iVar1 = (**(code **)(_r_ip_funcs_p + 0x8d4))(*(code **)(_r_ip_funcs_p + 0x8d4));
  if (iVar1 != 0) {
    uVar2 = r_llm_adv_rep_flow_control_update(param_1,param_2);
    return uVar2;
  }
  return 1;
}

