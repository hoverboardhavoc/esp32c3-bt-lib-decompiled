/*
 * Last changed at upstream commit e668c2d101ee46ee1950819607694fb852aecae0
 * https://github.com/espressif/esp32c3-bt-lib/commit/e668c2d101ee46ee1950819607694fb852aecae0
 * Upstream date: 2025-03-14 11:07:43 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(6e312587)
 * Source: libbtdm_app -> lld.o -> r_lld_hw_cca_isr_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_hw_cca_isr_eco(char param_1,int param_2,undefined1 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  iVar1 = _p_lld_env;
  if (*(char *)(iVar2 + 0x19) != '\x02') {
    iVar2 = *(int *)(_p_lld_env + 0x114);
    *(char *)(_p_lld_env + 0x104) = param_1;
    *(char *)(iVar1 + 0x105) = (char)param_2;
    *(undefined1 *)(iVar2 + param_2) = param_3;
                    /* WARNING: Could not recover jumptable at 0x0001326c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_modules_funcs_p + 0x108))(0xe);
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x000132b2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_ip_funcs_p + 0x9c4))((int)param_1);
  return;
}

