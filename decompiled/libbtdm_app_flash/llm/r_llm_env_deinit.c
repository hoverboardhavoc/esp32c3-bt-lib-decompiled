/*
 * Last changed at upstream commit 3ff529142f6e2707d57b10eb87ac8d86e9098b88
 * https://github.com/espressif/esp32c3-bt-lib/commit/3ff529142f6e2707d57b10eb87ac8d86e9098b88
 * Upstream date: 2025-06-05 11:04:06 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(4713a69)
 * Source: libbtdm_app_flash -> llm.o -> r_llm_env_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llm_env_deinit(void)

{
  int iVar1;
  
  if (_p_llm_env != 0) {
    iVar1 = r_sdk_config_get_opts_ext();
    if (*(char *)(iVar1 + 0x23) != '\0') {
      r_llm_env_adv_dup_filt_deinit_eco();
    }
    if (*(int *)(_p_llm_env + 8) != 0) {
      (**(code **)(_r_osi_funcs_p + 0x7c))(*(code **)(_r_osi_funcs_p + 0x7c));
      *(undefined4 *)(_p_llm_env + 8) = 0;
    }
    (**(code **)(_r_osi_funcs_p + 0x7c))(_p_llm_env,*(code **)(_r_osi_funcs_p + 0x7c));
    _p_llm_env = 0;
  }
  iVar1 = r_sdk_config_get_opts_ext();
  if ((*(char *)(iVar1 + 0x23) != '\0') && (p_le_scan_duplicate_option != 0)) {
    (**(code **)(_r_osi_funcs_p + 0x7c))(*(code **)(_r_osi_funcs_p + 0x7c));
    p_le_scan_duplicate_option = 0;
  }
  llm_hci_env_deinit();
  return;
}

