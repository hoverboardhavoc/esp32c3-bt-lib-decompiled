/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> llm_scan.o -> r_llm_env_adv_dup_filt_deinit_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llm_env_adv_dup_filt_deinit_eco(void)

{
  int *piVar1;
  
  if (*(char *)(_p_llm_env + 0xd7) != '\x02') {
    if (*(int *)(_p_llm_env + 0xcc) != 0) {
      r_assert_err(0,"llm_scan.c",0x6b6);
    }
    r_llm_duplicate_list_clear();
    return;
  }
  piVar1 = (int *)(_p_llm_env + 0xcc);
  *(undefined1 *)(_p_llm_env + 0xd0) = 0;
  if (*piVar1 != 0) {
    (**(code **)(_r_osi_funcs_p + 0x7c))(*(code **)(_r_osi_funcs_p + 0x7c));
    *(undefined4 *)(_p_llm_env + 0xcc) = 0;
  }
  return;
}

