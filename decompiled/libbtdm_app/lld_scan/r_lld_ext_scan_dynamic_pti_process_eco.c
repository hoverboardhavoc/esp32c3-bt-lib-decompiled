/*
 * Last changed at upstream commit 5c6ab5248a124cffc731a9e4764473fdeef38054
 * https://github.com/espressif/esp32c3-bt-lib/commit/5c6ab5248a124cffc731a9e4764473fdeef38054
 * Upstream date: 2023-03-09 14:58:19 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(85a1090)
 * Source: libbtdm_app -> lld_scan.o -> r_lld_ext_scan_dynamic_pti_process_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_ext_scan_dynamic_pti_process_eco(int param_1,int param_2)

{
  int iVar1;
  
  if ((param_1 == 0) || (_lld_scan_env == 0)) {
    return;
  }
  iVar1 = (**(code **)(_r_modules_funcs_p + 400))(*(code **)(_r_modules_funcs_p + 400));
  if (iVar1 != 0) {
    if (((*(char *)(param_1 + 0x39) != '\x01') || (*(char *)(param_1 + 0x3d) != '\x02')) ||
       (1 < param_2 - 2U)) {
      r_lld_ext_scan_dynamic_pti_process(param_1);
      return;
    }
  }
  return;
}

