/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app -> lld_adv.o -> r_lld_adv_rand_addr_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_adv_rand_addr_update(int param_1,undefined4 param_2,undefined2 param_3)

{
  int iVar1;
  undefined2 uStack_28;
  undefined2 uStack_26;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  if (*(int *)(&lld_adv_env + param_1 * 4) == 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0xe9f,*(code **)(_r_plf_funcs_p + 8));
  }
  else if ((*(byte *)(*(int *)(&lld_adv_env + param_1 * 4) + 0x8b) & 1) != 0) {
    uStack_28 = (undefined2)param_2;
    iVar1 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    param_1 = param_1 * 0x5a;
    *(undefined2 *)(param_1 + 6 + iVar1) = uStack_28;
    uStack_26 = (undefined2)((uint)param_2 >> 0x10);
    iVar1 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(undefined2 *)(param_1 + 8 + iVar1) = uStack_26;
    iVar1 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(undefined2 *)(param_1 + 10 + iVar1) = param_3;
  }
                    /* WARNING: Could not recover jumptable at 0x00016884. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return;
}

