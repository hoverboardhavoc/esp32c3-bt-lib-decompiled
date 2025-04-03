/*
 * Last changed at upstream commit f23a340e82d6a4be40f83214385a98c5bd30ccdd
 * https://github.com/espressif/esp32c3-bt-lib/commit/f23a340e82d6a4be40f83214385a98c5bd30ccdd
 * Upstream date: 2025-04-03 18:07:15 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(a684dd5)
 * Source: libbtdm_app -> lld_scan.o -> r_lld_scan_frm_eof_isr_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_scan_frm_eof_isr_eco(int param_1)

{
  r_lld_scan_frm_eof_isr();
  if (((_lld_scan_env != 0) && (*(int *)(param_1 * 4 + _lld_scan_env) != 0)) &&
     (*(char *)(_lld_scan_env + 0x17) != '\0')) {
                    /* WARNING: Could not recover jumptable at 0x00012ef6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_ip_funcs_p + 0x930))();
    return;
  }
  return;
}

