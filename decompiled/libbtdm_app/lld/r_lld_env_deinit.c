/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld.o -> r_lld_env_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_env_deinit(void)

{
  int iVar1;
  code *pcVar2;
  
  if (_p_lld_env == 0) {
    _p_lld_env = 0;
    return;
  }
  iVar1 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  if (*(char *)(iVar1 + 0x19) == '\x02') {
    pcVar2 = *(code **)(_r_ip_funcs_p + 0x954);
  }
  else {
    iVar1 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
    if ((*(char *)(iVar1 + 0x19) != '\x01') && (sdk_cfg_priv_opts == '\0')) goto _L62;
    pcVar2 = *(code **)(_r_ip_funcs_p + 0x4a0);
  }
  (*pcVar2)(pcVar2);
_L62:
  (**(code **)(_r_osi_funcs_p + 0x7c))(_p_lld_env,*(code **)(_r_osi_funcs_p + 0x7c));
  _p_lld_env = 0;
  return;
}

