/*
 * Last changed at upstream commit 5c6ab5248a124cffc731a9e4764473fdeef38054
 * https://github.com/espressif/esp32c3-bt-lib/commit/5c6ab5248a124cffc731a9e4764473fdeef38054
 * Upstream date: 2023-03-09 14:58:19 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(85a1090)
 * Source: libbtdm_app -> sch_prog.o -> r_sch_prog_hw_reset_try
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_sch_prog_hw_reset_try(void)

{
  uint uVar1;
  undefined1 *puVar2;
  
  puVar2 = (undefined1 *)(**(code **)(_r_ip_funcs_p + 0x920))(*(code **)(_r_ip_funcs_p + 0x920));
  uVar1 = _DAT_60031060;
  *puVar2 = 0;
  if ((uVar1 & 0x20001) != 0) {
    _DAT_60031000 = _DAT_60031000 | 0x80000000;
    do {
    } while ((int)_DAT_60031000 < 0);
    *puVar2 = 1;
    if (1 < _g_bt_plf_log_level) {
      ets_printf("nb_prog:%x\n",sch_prog_env);
      return;
    }
  }
  return;
}

