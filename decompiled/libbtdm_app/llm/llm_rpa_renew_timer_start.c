/*
 * Last changed at upstream commit bfdfe8f851c99ced8316b133b0b15521917ea049
 * https://github.com/espressif/esp32c3-bt-lib/commit/bfdfe8f851c99ced8316b133b0b15521917ea049
 * Upstream date: 2024-07-18 14:51:28 +0800
 * Upstream subject: feat(bt): Support mesh duplicate with extend scan (aa16a46)
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
                    /* WARNING: Could not recover jumptable at 0x00010cee. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_modules_funcs_p + 0xc4))(6,0,(uint)*(ushort *)(_p_llm_env + 0xc4) * 100);
    return;
  }
  return;
}

