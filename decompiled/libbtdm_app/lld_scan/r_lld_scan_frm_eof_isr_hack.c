/*
 * Last changed at upstream commit 976ca00e43905df9e910b400a9e17c311b085ce2
 * https://github.com/espressif/esp32c3-bt-lib/commit/976ca00e43905df9e910b400a9e17c311b085ce2
 * Upstream date: 2022-11-03 19:06:39 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(ef8a115a) - Added config to disable scan backoff - Fixed llm_scan.c assert at line 1485 during controller deinit if duplicate scan is not stopped - Call pll track in controller task
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
                    /* WARNING: Could not recover jumptable at 0x0001046e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_ip_funcs_p + 0x3d8))(iVar2,3);
    return;
  }
  return;
}

