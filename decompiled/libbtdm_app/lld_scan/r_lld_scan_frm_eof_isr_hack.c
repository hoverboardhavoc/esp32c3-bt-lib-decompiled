/*
 * Last changed at upstream commit 4b93865b52ab92f0b7777ed415b6598b96ac1d6d
 * https://github.com/espressif/esp32c3-bt-lib/commit/4b93865b52ab92f0b7777ed415b6598b96ac1d6d
 * Upstream date: 2021-06-22 22:28:01 +0800
 * Upstream subject: Update ESP32-C3/ESP32-S3 bt-lib (e6e17bb4)
 * Source: libbtdm_app -> lld_scan.o -> r_lld_scan_frm_eof_isr_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_scan_frm_eof_isr_hack(int param_1)

{
  bool bVar1;
  int iVar2;
  
  if (_lld_scan_env == 0) {
    iVar2 = 0;
    bVar1 = false;
  }
  else {
    iVar2 = *(int *)(_lld_scan_env + param_1 * 4);
    bVar1 = false;
    if (iVar2 != 0) {
      if (*(char *)(iVar2 + 0x3c) != '\x02') {
        bVar1 = *(char *)(iVar2 + 0x3d) == '\x02';
      }
    }
  }
  r_lld_scan_frm_eof_isr();
  if ((bVar1) && (*(char *)(iVar2 + 0x3d) == '\0')) {
                    /* WARNING: Could not recover jumptable at 0x00010378. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_ip_funcs_p + 0x3d8))(iVar2,3);
    return;
  }
  return;
}

