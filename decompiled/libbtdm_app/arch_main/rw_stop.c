/*
 * Last changed at upstream commit 022b7da7fcf0043f891c2e8ccd8c241243018e2f
 * https://github.com/espressif/esp32c3-bt-lib/commit/022b7da7fcf0043f891c2e8ccd8c241243018e2f
 * Upstream date: 2021-04-20 16:00:04 +0800
 * Upstream subject: ESP32-C3, ESP32-S3: update libbtdm_app.a(d1d0c6f1)
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
                    /* WARNING: Could not recover jumptable at 0x000109e8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_plf_funcs_p + 0xa0))();
  return;
}

