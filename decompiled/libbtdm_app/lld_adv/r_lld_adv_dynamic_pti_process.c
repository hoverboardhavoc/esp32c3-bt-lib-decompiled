/*
 * Last changed at upstream commit daab5dbba958a13041bd496e4a6ed506c9284a06
 * https://github.com/espressif/esp32c3-bt-lib/commit/daab5dbba958a13041bd496e4a6ed506c9284a06
 * Upstream date: 2025-03-20 20:43:40 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(86a4da5c)
 * Source: libbtdm_app -> lld_adv.o -> r_lld_adv_dynamic_pti_process
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_adv_dynamic_pti_process(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  if (param_1 == 0) {
    return;
  }
  if ((*(ushort *)(param_1 + 0x74) & 0x10) == 0) {
    iVar1 = (**(code **)(_r_modules_funcs_p + 0x18c))(*(code **)(_r_modules_funcs_p + 0x18c));
    if (iVar1 != 0) {
      iVar1 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
      if (*(char *)(iVar1 + 0x18) == '\0') {
                    /* WARNING: Could not recover jumptable at 0x00011954. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x46a);
        return;
      }
                    /* WARNING: Could not recover jumptable at 0x00011974. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(_r_ip_funcs_p + 0x764))(param_1,param_2,param_3);
      return;
    }
  }
  else {
    iVar1 = (**(code **)(_r_modules_funcs_p + 0x194))(*(code **)(_r_modules_funcs_p + 0x194));
    if (iVar1 != 0) {
                    /* WARNING: Could not recover jumptable at 0x00011914. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(_r_ip_funcs_p + 0x758))(param_1);
      return;
    }
  }
  return;
}

