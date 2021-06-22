/*
 * Last changed at upstream commit 4b93865b52ab92f0b7777ed415b6598b96ac1d6d
 * https://github.com/espressif/esp32c3-bt-lib/commit/4b93865b52ab92f0b7777ed415b6598b96ac1d6d
 * Upstream date: 2021-06-22 22:28:01 +0800
 * Upstream subject: Update ESP32-C3/ESP32-S3 bt-lib (e6e17bb4)
 * Source: libbtdm_app -> intc.o -> r_intc_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_intc_init(void)

{
  undefined1 uVar1;
  int iVar2;
  
  iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  uVar1 = *(undefined1 *)(iVar2 + 0xb);
  if (*(int *)(_r_osi_funcs_p + 8) == 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"intc.c",0x75,*(code **)(_r_plf_funcs_p + 8));
  }
  if (*(int *)(_r_osi_funcs_p + 0x10) == 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"intc.c",0x76,*(code **)(_r_plf_funcs_p + 8));
  }
  (**(code **)(_r_osi_funcs_p + 8))(uVar1,8,5,1,*(code **)(_r_osi_funcs_p + 8));
  (**(code **)(_r_osi_funcs_p + 0x10))
            (5,*(undefined4 *)(_r_plf_funcs_p + 0x90),0,*(code **)(_r_osi_funcs_p + 0x10));
  iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  if (*(char *)(iVar2 + 0x11) != '\0') {
    (**(code **)(_r_osi_funcs_p + 8))(uVar1,5,8,1,*(code **)(_r_osi_funcs_p + 8));
                    /* WARNING: Could not recover jumptable at 0x000100ba. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_osi_funcs_p + 0x10))(8,*(undefined4 *)(_r_plf_funcs_p + 0x84),0);
    return;
  }
  return;
}

