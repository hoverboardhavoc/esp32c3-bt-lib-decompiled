/*
 * Last changed at upstream commit bfdfe8f851c99ced8316b133b0b15521917ea049
 * https://github.com/espressif/esp32c3-bt-lib/commit/bfdfe8f851c99ced8316b133b0b15521917ea049
 * Upstream date: 2024-07-18 14:51:28 +0800
 * Upstream subject: feat(bt): Support mesh duplicate with extend scan (aa16a46)
 * Source: libbtdm_app -> llm_scan.o -> r_llm_env_adv_dup_filt_init_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_llm_env_adv_dup_filt_init_eco(void)

{
  undefined4 uVar1;
  
  if (*(char *)(_p_llm_env + 0xd7) == '\x02') {
    uVar1 = r_llm_env_adv_dup_filt_init();
    return uVar1;
  }
  if (*(int *)(_p_llm_env + 0xcc) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"llm_scan.c",0x5dd,*(code **)(_r_plf_funcs_p + 8));
    return 1;
  }
  return 1;
}

