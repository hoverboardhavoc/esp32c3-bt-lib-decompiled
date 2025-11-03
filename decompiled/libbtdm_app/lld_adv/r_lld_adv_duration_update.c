/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
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
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0xe2f,*(code **)(_r_plf_funcs_p + 8));
  }
  else {
    if ((*(ushort *)(iVar2 + 0x74) & 8) == 0) {
      if (param_2 != 0) {
        *(uint *)(iVar2 + 0x58) = param_2 * 0x20 + *(int *)(iVar2 + 4) & 0xfffffff;
        goto _L1229;
      }
      uVar1 = 0xffffffff;
    }
    else {
      uVar1 = *(int *)(iVar2 + 4) + 0x1000U & 0xfffffff;
    }
    *(uint *)(iVar2 + 0x58) = uVar1;
  }
_L1229:
                    /* WARNING: Could not recover jumptable at 0x0001646c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return;
}

