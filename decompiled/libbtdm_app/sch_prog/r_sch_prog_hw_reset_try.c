/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> sch_prog.o -> r_sch_prog_hw_reset_try
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_sch_prog_hw_reset_try(void)

{
  int iVar1;
  uint uVar2;
  undefined1 *puVar3;
  
  puVar3 = (undefined1 *)(**(code **)(_r_ip_funcs_p + 0x920))(*(code **)(_r_ip_funcs_p + 0x920));
  uVar2 = _DAT_60031060;
  *puVar3 = 0;
  iVar1 = _g_bt_plf_log_level;
  if ((uVar2 & 0x20001) != 0) {
    _DAT_60031000 = _DAT_60031000 | 0x80000000;
    do {
    } while ((int)_DAT_60031000 < 0);
    *puVar3 = 1;
    if (1 < iVar1) {
      ets_printf("nb_prog:%x\n",sch_prog_env);
      return;
    }
  }
  return;
}

