/*
 * Last changed at upstream commit 08e289633f823191a6c526377bfd68f31fb392e0
 * https://github.com/espressif/esp32c3-bt-lib/commit/08e289633f823191a6c526377bfd68f31fb392e0
 * Upstream date: 2023-06-06 21:15:22 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(a186b41)
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
    if (*(char *)(iVar1 + 0x17) != '\x01') goto _L244;
    pcVar2 = *(code **)(_r_plf_funcs_p + 200);
  }
  (*pcVar2)(pcVar2);
_L244:
                    /* WARNING: Could not recover jumptable at 0x00010cb4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_plf_funcs_p + 0xa0))();
  return;
}

