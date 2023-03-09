/*
 * Last changed at upstream commit 5c6ab5248a124cffc731a9e4764473fdeef38054
 * https://github.com/espressif/esp32c3-bt-lib/commit/5c6ab5248a124cffc731a9e4764473fdeef38054
 * Upstream date: 2023-03-09 14:58:19 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(85a1090)
 * Source: libbtdm_app -> llm_scan.o -> llm_cal_duplicate_scan_defer_count
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void llm_cal_duplicate_scan_defer_count(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (*(char *)(_p_llm_env + 0xd7) != '\x02') {
    iVar1 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
    if (*(short *)(iVar1 + 0x16) != 0) {
      iVar1 = (**(code **)(_r_ip_funcs_p + 0x924))(*(code **)(_r_ip_funcs_p + 0x924));
      iVar2 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
      param_1 = (int)((uint)*(ushort *)(iVar2 + 0x16) * 0x640) / param_1;
      if (param_1 == 0) {
        *(undefined4 *)(iVar1 + 0x18) = 1;
      }
      else {
        *(int *)(iVar1 + 0x18) = param_1;
      }
      *(undefined4 *)(iVar1 + 0x1c) = 0;
    }
    return;
  }
  return;
}

