/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llm.o -> r_llm_env_deinit
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
    iVar1 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
    if (*(char *)(iVar1 + 0x23) != '\0') {
      (**(code **)(_r_ip_funcs_p + 0x53c))(*(code **)(_r_ip_funcs_p + 0x53c));
    }
    if (*(int *)(_p_llm_env + 8) != 0) {
      (**(code **)(_r_osi_funcs_p + 0x7c))(*(code **)(_r_osi_funcs_p + 0x7c));
    }
    (**(code **)(_r_osi_funcs_p + 0x7c))(_p_llm_env,*(code **)(_r_osi_funcs_p + 0x7c));
    _p_llm_env = 0;
  }
  llm_hci_env_deinit();
  return;
}

