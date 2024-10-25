/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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
                    /* WARNING: Could not recover jumptable at 0x00012e9e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_ip_funcs_p + 0x930))();
    return;
  }
  return;
}

