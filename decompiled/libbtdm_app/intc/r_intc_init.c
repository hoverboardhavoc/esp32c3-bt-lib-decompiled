/*
 * Last changed at upstream commit 1a086eab61e78fa243d67c33206ece4022129ee1
 * https://github.com/espressif/esp32c3-bt-lib/commit/1a086eab61e78fa243d67c33206ece4022129ee1
 * Upstream date: 2024-05-10 19:28:08 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(eca46a0)
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
    (**(code **)(_r_plf_funcs_p + 8))(0,"intc.c",0xd9,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar2 = (**(code **)(_r_osi_funcs_p + 8))
                    (uVar1,8,*(undefined4 *)(_r_plf_funcs_p + 0x90),0,&_LANCHOR0,
                     *(code **)(_r_osi_funcs_p + 8));
  if (iVar2 != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"intc.c",0xdd,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar2 = (**(code **)(_r_osi_funcs_p + 8))
                    (uVar1,5,*(undefined4 *)(_r_plf_funcs_p + 0x84),0,&_LANCHOR1,
                     *(code **)(_r_osi_funcs_p + 8));
  if (iVar2 != 0) {
                    /* WARNING: Could not recover jumptable at 0x000102d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_plf_funcs_p + 8))(0,"intc.c",0xe1);
    return;
  }
  return;
}

