/*
 * Last changed at upstream commit f23a340e82d6a4be40f83214385a98c5bd30ccdd
 * https://github.com/espressif/esp32c3-bt-lib/commit/f23a340e82d6a4be40f83214385a98c5bd30ccdd
 * Upstream date: 2025-04-03 18:07:15 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(a684dd5)
 * Source: libbtdm_app -> lld_adv.o -> r_lld_adv_sync_info_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_adv_sync_info_update(int param_1,undefined1 param_2,undefined4 param_3)

{
  int iVar1;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar1 = *(int *)(&lld_adv_env + param_1 * 4);
  if (iVar1 == 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0xe45,*(code **)(_r_plf_funcs_p + 8));
  }
  else {
    *(undefined1 *)(iVar1 + 0x88) = param_2;
    *(undefined4 *)(iVar1 + 0x68) = param_3;
    *(undefined1 *)(iVar1 + 0x94) = 1;
  }
                    /* WARNING: Could not recover jumptable at 0x000165a6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_osi_funcs_p + 0x18))();
  return;
}

