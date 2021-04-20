/*
 * Last changed at upstream commit 352d001fc7f5d34243047454b3f9e684577ce3e0
 * https://github.com/espressif/esp32c3-bt-lib/commit/352d001fc7f5d34243047454b3f9e684577ce3e0
 * Upstream date: 2021-04-20 15:58:00 +0800
 * Upstream subject: ESP32C3, ESP32S3: update libbtdm_app.a(47235b66)
 * Source: libbtdm_app -> arch_main.o -> btdm_controller_enable
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 btdm_controller_enable(uint param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  uVar2 = 0xffffffff;
  if (*(byte *)(iVar1 + 0xc) == param_1) {
    (**(code **)(_r_plf_funcs_p + 0x28))(9,0,0,1,*(code **)(_r_plf_funcs_p + 0x28));
    (**(code **)(_r_osi_funcs_p + 0x34))
              (_g_rw_init_sem,0xffffffff,*(code **)(_r_osi_funcs_p + 0x34));
    uVar2 = 0;
  }
  return uVar2;
}

