/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
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
                    /* WARNING: Could not recover jumptable at 0x00010de0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_modules_funcs_p + 0xc4))
              (6,0,(uint)*(ushort *)(_p_llm_env + 0xc4) * 100,*(code **)(_r_modules_funcs_p + 0xc4))
    ;
    return;
  }
  return;
}

