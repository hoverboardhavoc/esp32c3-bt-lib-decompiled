/*
 * Last changed at upstream commit e668c2d101ee46ee1950819607694fb852aecae0
 * https://github.com/espressif/esp32c3-bt-lib/commit/e668c2d101ee46ee1950819607694fb852aecae0
 * Upstream date: 2025-03-14 11:07:43 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(6e312587)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_adv_duration_update
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
    r_assert_err(0,"lld_adv.c",0xdc7);
  }
  else {
    if ((*(ushort *)(iVar2 + 0x74) & 8) == 0) {
      if (param_2 != 0) {
        *(uint *)(iVar2 + 0x58) = param_2 * 0x20 + *(int *)(iVar2 + 4) & 0xfffffff;
        goto _L1158;
      }
      uVar1 = 0xffffffff;
    }
    else {
      uVar1 = *(int *)(iVar2 + 4) + 0x1000U & 0xfffffff;
    }
    *(uint *)(iVar2 + 0x58) = uVar1;
  }
_L1158:
                    /* WARNING: Could not recover jumptable at 0x000156ac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_osi_funcs_p + 0x18))();
  return;
}

