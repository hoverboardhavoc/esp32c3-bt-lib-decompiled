/*
 * Last changed at upstream commit ec7ef197cb8018c468cd59dca893dbe018f47a2a
 * https://github.com/espressif/esp32c3-bt-lib/commit/ec7ef197cb8018c468cd59dca893dbe018f47a2a
 * Upstream date: 2023-10-26 19:39:25 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(f817304)
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
    if (*(char *)(iVar1 + 0x17) != '\x01') goto _L246;
    pcVar2 = *(code **)(_r_plf_funcs_p + 200);
  }
  (*pcVar2)(pcVar2);
_L246:
                    /* WARNING: Could not recover jumptable at 0x00010ce8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_plf_funcs_p + 0xa0))();
  return;
}

