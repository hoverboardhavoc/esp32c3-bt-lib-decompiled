/*
 * Last changed at upstream commit f23a340e82d6a4be40f83214385a98c5bd30ccdd
 * https://github.com/espressif/esp32c3-bt-lib/commit/f23a340e82d6a4be40f83214385a98c5bd30ccdd
 * Upstream date: 2025-04-03 18:07:15 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(a684dd5)
 * Source: libbtdm_app -> llm.o -> llm_rpa_renew_timer_start
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void llm_rpa_renew_timer_start(void)

{
  int iVar1;
  
  iVar1 = (**(code **)(_r_modules_funcs_p + 0xb0))(6,0,*(code **)(_r_modules_funcs_p + 0xb0));
  if (iVar1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x00010d18. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_modules_funcs_p + 0xc4))(6,0,(uint)*(ushort *)(_p_llm_env + 0xc4) * 100);
    return;
  }
  return;
}

