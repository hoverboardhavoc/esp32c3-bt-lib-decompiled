/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld.o -> r_lld_sw_cca_isr_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_sw_cca_isr_eco(char param_1,undefined1 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  iVar1 = _p_lld_env;
  if (*(char *)(iVar2 + 0x19) != '\x02') {
    if (param_3 == 0) {
      *(char *)(_p_lld_env + 0x104) = param_1;
      *(undefined1 *)(iVar1 + 0x105) = param_2;
    }
                    /* WARNING: Could not recover jumptable at 0x00013184. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_modules_funcs_p + 0x108))(0xd,*(code **)(_r_modules_funcs_p + 0x108));
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x000131ca. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_ip_funcs_p + 0x9c8))((int)param_1,*(code **)(_r_ip_funcs_p + 0x9c8));
  return;
}

