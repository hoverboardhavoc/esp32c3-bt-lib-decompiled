/*
 * Last changed at upstream commit 040cd0eafd8c6ee52bc7f7d5d633c9dc1b99bba2
 * https://github.com/espressif/esp32c3-bt-lib/commit/040cd0eafd8c6ee52bc7f7d5d633c9dc1b99bba2
 * Upstream date: 2023-08-03 10:45:08 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(ff6efe7)
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
    if ((*(char *)(iVar1 + 0x19) != '\x01') && (sdk_cfg_priv_opts == '\0')) goto _L57;
    pcVar2 = *(code **)(_r_ip_funcs_p + 0x4a0);
  }
  (*pcVar2)(pcVar2);
_L57:
  (**(code **)(_r_osi_funcs_p + 0x7c))(_p_lld_env,*(code **)(_r_osi_funcs_p + 0x7c));
  _p_lld_env = 0;
  return;
}

