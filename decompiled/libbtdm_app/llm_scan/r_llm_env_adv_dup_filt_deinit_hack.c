/*
 * Last changed at upstream commit bba9af9259e0999ef246426d31a793fe0a3ff4db
 * https://github.com/espressif/esp32c3-bt-lib/commit/bba9af9259e0999ef246426d31a793fe0a3ff4db
 * Upstream date: 2022-12-14 15:32:37 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(80abacdd)
 * Source: libbtdm_app -> llm_scan.o -> r_llm_env_adv_dup_filt_deinit_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llm_env_adv_dup_filt_deinit_hack(void)

{
  if (*(char *)(_p_llm_env + 0xd7) == '\x02') {
    r_llm_env_adv_dup_filt_deinit();
    return;
  }
  if (*(int *)(_p_llm_env + 0xcc) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"llm_scan.c",0x5e0,*(code **)(_r_plf_funcs_p + 8));
  }
  llm_duplicate_list_clear();
  return;
}

