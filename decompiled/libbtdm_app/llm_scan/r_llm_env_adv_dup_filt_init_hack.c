/*
 * Last changed at upstream commit f3c359a685a17bcc301e43778e7f581605e32d0a
 * https://github.com/espressif/esp32c3-bt-lib/commit/f3c359a685a17bcc301e43778e7f581605e32d0a
 * Upstream date: 2022-07-04 22:08:59 +0800
 * Upstream subject: fix ke_mem.c assert(0821b2a)
 * Source: libbtdm_app -> llm_scan.o -> r_llm_env_adv_dup_filt_init_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_llm_env_adv_dup_filt_init_hack(void)

{
  undefined4 uVar1;
  
  if (*(char *)(_p_llm_env + 0xd7) == '\x02') {
    uVar1 = r_llm_env_adv_dup_filt_init();
    return uVar1;
  }
  if (*(int *)(_p_llm_env + 0xcc) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"llm_scan.c",0x5af,*(code **)(_r_plf_funcs_p + 8));
    return 1;
  }
  return 1;
}

