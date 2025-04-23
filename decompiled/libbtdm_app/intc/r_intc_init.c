/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
    (**(code **)(_r_plf_funcs_p + 8))(0,"intc.c",0xda,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar2 = (**(code **)(_r_osi_funcs_p + 8))
                    (uVar1,8,*(undefined4 *)(_r_plf_funcs_p + 0x90),0,&rwble_intr_handle,
                     *(code **)(_r_osi_funcs_p + 8));
  if (iVar2 != 0) {
    (**(code **)(_r_plf_funcs_p + 0xc))(8,iVar2,"intc.c",0xde,*(code **)(_r_plf_funcs_p + 0xc));
  }
  iVar2 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  if (((*(char *)(iVar2 + 0x11) != '\0') ||
      (iVar2 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0)),
      *(char *)(iVar2 + 0x19) != '\0')) &&
     (iVar2 = (**(code **)(_r_osi_funcs_p + 8))
                        (uVar1,5,0x10000,0,&bt_bb_intr_handle,*(code **)(_r_osi_funcs_p + 8)),
     iVar2 != 0)) {
                    /* WARNING: Could not recover jumptable at 0x00010324. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_plf_funcs_p + 0xc))(5,iVar2,"intc.c",0xe4,*(code **)(_r_plf_funcs_p + 0xc));
    return;
  }
  return;
}

