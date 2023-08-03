/*
 * Last changed at upstream commit 040cd0eafd8c6ee52bc7f7d5d633c9dc1b99bba2
 * https://github.com/espressif/esp32c3-bt-lib/commit/040cd0eafd8c6ee52bc7f7d5d633c9dc1b99bba2
 * Upstream date: 2023-08-03 10:45:08 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(ff6efe7)
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
    (**(code **)(_r_plf_funcs_p + 8))(0,"intc.c",0xd6,*(code **)(_r_plf_funcs_p + 8));
  }
  if (*(int *)(_r_osi_funcs_p + 0x10) == 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"intc.c",0xd7,*(code **)(_r_plf_funcs_p + 8));
  }
  (**(code **)(_r_osi_funcs_p + 8))(uVar1,8,5,1,*(code **)(_r_osi_funcs_p + 8));
  (**(code **)(_r_osi_funcs_p + 0x10))
            (5,*(undefined4 *)(_r_plf_funcs_p + 0x90),0,*(code **)(_r_osi_funcs_p + 0x10));
  (**(code **)(_r_osi_funcs_p + 8))(uVar1,5,8,1,*(code **)(_r_osi_funcs_p + 8));
                    /* WARNING: Could not recover jumptable at 0x000102ca. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_osi_funcs_p + 0x10))(8,*(undefined4 *)(_r_plf_funcs_p + 0x84),0);
  return;
}

