/*
 * Last changed at upstream commit b0ccea3c26a049649d2fdbaca78318af90a6dd5b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b0ccea3c26a049649d2fdbaca78318af90a6dd5b
 * Upstream date: 2025-05-16 11:55:10 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(4713205)
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
                    /* WARNING: Could not recover jumptable at 0x00013222. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_modules_funcs_p + 0x108))(0xd,*(code **)(_r_modules_funcs_p + 0x108));
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00013268. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_ip_funcs_p + 0x9c8))((int)param_1,*(code **)(_r_ip_funcs_p + 0x9c8));
  return;
}

