/*
 * Last changed at upstream commit 022b7da7fcf0043f891c2e8ccd8c241243018e2f
 * https://github.com/espressif/esp32c3-bt-lib/commit/022b7da7fcf0043f891c2e8ccd8c241243018e2f
 * Upstream date: 2021-04-20 16:00:04 +0800
 * Upstream subject: ESP32-C3, ESP32-S3: update libbtdm_app.a(d1d0c6f1)
 * Source: libbtdm_app -> llm_scan.o -> r_llm_adv_rep_flow_control_update_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_llm_adv_rep_flow_control_update_hack(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((*(char *)(_p_llm_env + 0xd7) == '\x01') ||
     ((*(char *)(_p_llm_env + 0xd7) == '\x02' && ((*(byte *)(param_1 + 0x15) & 0x10) != 0)))) {
    if (0x1f < *(byte *)(param_1 + 0x20)) {
      return 1;
    }
  }
  iVar1 = llm_le_adv_report_ind_duplicate_check();
  if (iVar1 != 0) {
    uVar2 = r_llm_adv_rep_flow_control_update(param_1,param_2);
    return uVar2;
  }
  return 1;
}

