/*
 * Last changed at upstream commit e9ad3d704f1034310de8f747d503ea5443df6b67
 * https://github.com/espressif/esp32c3-bt-lib/commit/e9ad3d704f1034310de8f747d503ea5443df6b67
 * Upstream date: 2023-09-15 17:47:18 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(29996e0)
 * Source: libbtdm_app -> lld.o -> r_lld_env_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int r_lld_env_init(void)

{
  int iVar1;
  
  _p_lld_env = (**(code **)(_r_osi_funcs_p + 0x78))(0x11c,*(code **)(_r_osi_funcs_p + 0x78));
  if (_p_lld_env == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
    if (*(char *)(iVar1 + 0x19) == '\x02') {
                    /* WARNING: Could not recover jumptable at 0x00010550. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar1 = (**(code **)(_r_ip_funcs_p + 0x950))();
      return iVar1;
    }
    iVar1 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
    if ((*(char *)(iVar1 + 0x19) == '\x01') || (iVar1 = 1, sdk_cfg_priv_opts != '\0')) {
      (**(code **)(_r_ip_funcs_p + 0x49c))(iVar1,*(code **)(_r_ip_funcs_p + 0x49c));
      iVar1 = 1;
    }
  }
  return iVar1;
}

