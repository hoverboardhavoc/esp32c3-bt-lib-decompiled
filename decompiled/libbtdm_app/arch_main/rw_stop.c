/*
 * Last changed at upstream commit 0caae2bd70a999ac8a1c07330f7168e185db81ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/0caae2bd70a999ac8a1c07330f7168e185db81ba
 * Upstream date: 2024-01-31 19:37:46 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(91980c2)
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
    if (*(char *)(iVar1 + 0x17) != '\x01') goto _L258;
    pcVar2 = *(code **)(_r_plf_funcs_p + 200);
  }
  (*pcVar2)(pcVar2);
_L258:
                    /* WARNING: Could not recover jumptable at 0x00010d6a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_plf_funcs_p + 0xa0))();
  return;
}

