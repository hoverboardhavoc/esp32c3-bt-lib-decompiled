/*
 * Last changed at upstream commit 9780fd66d97866977d972fb63319830f47f12785
 * https://github.com/espressif/esp32c3-bt-lib/commit/9780fd66d97866977d972fb63319830f47f12785
 * Upstream date: 2024-04-23 11:19:15 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(a771b7c)
 * Source: libbtdm_app -> lld_scan.o -> r_lld_scan_frm_skip_isr_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_scan_frm_skip_isr_eco(int param_1)

{
  bool bVar1;
  int iVar2;
  
  bVar1 = false;
  if (_lld_scan_env != 0) {
    iVar2 = *(int *)(_lld_scan_env + param_1 * 4);
    if (iVar2 != 0) {
      bVar1 = *(char *)(iVar2 + 0x3d) == '\x01';
    }
  }
  r_lld_scan_frm_skip_isr(param_1);
  if ((((bVar1) && (_lld_scan_env != 0)) && (*(int *)(param_1 * 4 + _lld_scan_env) != 0)) &&
     (*(char *)(_lld_scan_env + 0x17) != '\0')) {
                    /* WARNING: Could not recover jumptable at 0x000108dc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_ip_funcs_p + 0x930))();
    return;
  }
  return;
}

