/*
 * Last changed at upstream commit 2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * https://github.com/espressif/esp32c3-bt-lib/commit/2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * Upstream date: 2025-02-25 15:16:47 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(723439d)
 * Source: libbtdm_app -> lld_test.o -> r_lld_test_evt_canceled_cbk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_test_evt_canceled_cbk(int param_1)

{
  code *UNRECOVERED_JUMPTABLE;
  int iVar1;
  undefined4 uVar2;
  
  if (_lld_test_env != param_1) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_test.c",0x1ba,*(code **)(_r_plf_funcs_p + 8));
  }
  if (param_1 == 0) {
    uVar2 = 0x1ce;
    UNRECOVERED_JUMPTABLE = *(code **)(_r_plf_funcs_p + 8);
  }
  else {
    if (*(char *)(param_1 + 0x2a) != '\0') {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_test.c",0x1c1,*(code **)(_r_plf_funcs_p + 8));
    }
    *(char *)(param_1 + 0x16) = *(char *)(param_1 + 0x16) + rwip_priority;
    iVar1 = (**(code **)(_r_ip_funcs_p + 0x6b0))(param_1,*(code **)(_r_ip_funcs_p + 0x6b0));
    if (iVar1 == 0) {
      return;
    }
    uVar2 = 0x1c9;
    UNRECOVERED_JUMPTABLE = *(code **)(_r_plf_funcs_p + 8);
  }
                    /* WARNING: Could not recover jumptable at 0x00010426. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(0,"lld_test.c",uVar2);
  return;
}

