/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llc_le_ping.o -> r_llc_le_ping_proc_err_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llc_le_ping_proc_err_cb(uint param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  if (param_1 == 1) {
    if (param_2[1] == '\x12') {
      uVar1 = 0;
      UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x608);
      goto _L15;
    }
  }
  else {
    if (param_1 < 2) {
      uVar1 = *param_2;
      UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x608);
_L15:
                    /* WARNING: Could not recover jumptable at 0x000100ce. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*UNRECOVERED_JUMPTABLE)(1,uVar1,UNRECOVERED_JUMPTABLE);
      return;
    }
    if (1 < (param_1 - 2 & 0xff)) {
                    /* WARNING: Could not recover jumptable at 0x000100ba. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(_r_plf_funcs_p + 0xc))("llc_le_ping.c",0x12e,*(code **)(_r_plf_funcs_p + 0xc));
      return;
    }
  }
  return;
}

