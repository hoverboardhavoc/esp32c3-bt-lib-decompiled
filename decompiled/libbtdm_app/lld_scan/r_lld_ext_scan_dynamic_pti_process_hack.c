/*
 * Last changed at upstream commit 78180e1b9c68c7068675e892df821bddefe5f88c
 * https://github.com/espressif/esp32c3-bt-lib/commit/78180e1b9c68c7068675e892df821bddefe5f88c
 * Upstream date: 2021-06-07 11:17:03 +0800
 * Upstream subject: Update ESP32-C3 and ESP32-S3 libbtdm_app.a(a6bf46f8)
 * Source: libbtdm_app -> lld_scan.o -> r_lld_ext_scan_dynamic_pti_process_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_ext_scan_dynamic_pti_process_hack(int param_1,int param_2)

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

