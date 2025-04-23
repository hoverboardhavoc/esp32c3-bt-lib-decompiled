/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_adv.o -> r_lld_adv_duration_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_adv_duration_update(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar2 = *(int *)(&lld_adv_env + param_1 * 4);
  if (iVar2 == 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0xdef,*(code **)(_r_plf_funcs_p + 8));
  }
  else {
    if ((*(ushort *)(iVar2 + 0x74) & 8) == 0) {
      if (param_2 != 0) {
        *(uint *)(iVar2 + 0x58) = param_2 * 0x20 + *(int *)(iVar2 + 4) & 0xfffffff;
        goto _L1151;
      }
      uVar1 = 0xffffffff;
    }
    else {
      uVar1 = *(int *)(iVar2 + 4) + 0x1000U & 0xfffffff;
    }
    *(uint *)(iVar2 + 0x58) = uVar1;
  }
_L1151:
                    /* WARNING: Could not recover jumptable at 0x000162f6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return;
}

