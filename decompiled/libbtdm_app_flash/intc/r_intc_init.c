/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> intc.o -> r_intc_init
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
  
  iVar2 = r_sdk_config_get_opts();
  uVar1 = *(undefined1 *)(iVar2 + 0xb);
  if (*(int *)(_r_osi_funcs_p + 8) == 0) {
    r_assert_err(0,"intc.c",0xda);
  }
  iVar2 = (**(code **)(_r_osi_funcs_p + 8))
                    (uVar1,8,0x10000,0,&rwble_intr_handle,*(code **)(_r_osi_funcs_p + 8));
  if (iVar2 != 0) {
    r_assert_param(8,iVar2,"intc.c",0xde);
  }
  iVar2 = r_sdk_config_get_opts_ext();
  if (((*(char *)(iVar2 + 0x11) != '\0') ||
      (iVar2 = r_sdk_config_get_opts_ext(), *(char *)(iVar2 + 0x19) != '\0')) &&
     (iVar2 = (**(code **)(_r_osi_funcs_p + 8))
                        (uVar1,5,bt_bb_isr_wrapper,0,&bt_bb_intr_handle,
                         *(code **)(_r_osi_funcs_p + 8)), iVar2 != 0)) {
    r_assert_param(5,iVar2,"intc.c",0xe4);
    return;
  }
  return;
}

