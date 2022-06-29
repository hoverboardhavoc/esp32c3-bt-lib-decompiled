/*
 * Last changed at upstream commit 614154ba4a7b5e55e943f92c194de497e6ce4219
 * https://github.com/espressif/esp32c3-bt-lib/commit/614154ba4a7b5e55e943f92c194de497e6ce4219
 * Upstream date: 2022-06-29 19:01:17 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(16cffbc)
 * Source: libbtdm_app -> arch_main.o -> rw_stop
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void rw_stop(void)

{
  int iVar1;
  code *pcVar2;
  
  iVar1 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  if (*(char *)(iVar1 + 0x17) == '\0') {
    pcVar2 = *(code **)(_r_h4tl_eif_p + 0x10);
  }
  else {
    iVar1 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
    if (*(char *)(iVar1 + 0x17) != '\x01') goto _L191;
    pcVar2 = *(code **)(_r_plf_funcs_p + 200);
  }
  (*pcVar2)(pcVar2);
_L191:
                    /* WARNING: Could not recover jumptable at 0x000109b6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_plf_funcs_p + 0xa0))();
  return;
}

