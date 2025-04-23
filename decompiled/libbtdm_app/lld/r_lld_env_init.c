/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld.o -> r_lld_env_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_lld_env_init(void)

{
  int iVar1;
  undefined4 uVar2;
  
  _p_lld_env = (**(code **)(_r_osi_funcs_p + 0x78))(0x11c,*(code **)(_r_osi_funcs_p + 0x78));
  if (_p_lld_env == 0) {
    uVar2 = 0;
  }
  else {
    iVar1 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
    if (*(char *)(iVar1 + 0x19) == '\x02') {
                    /* WARNING: Could not recover jumptable at 0x000105d6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (**(code **)(_r_ip_funcs_p + 0x950))(*(code **)(_r_ip_funcs_p + 0x950));
      return uVar2;
    }
    iVar1 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
    if ((*(char *)(iVar1 + 0x19) == '\x01') || (sdk_cfg_priv_opts != '\0')) {
      (**(code **)(_r_ip_funcs_p + 0x49c))(*(code **)(_r_ip_funcs_p + 0x49c));
    }
    uVar2 = 1;
  }
  return uVar2;
}

