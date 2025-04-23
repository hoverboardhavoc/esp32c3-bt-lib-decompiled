/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> ecc_p256.o -> r_SubtractFromSelfBigHexSign256
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_SubtractFromSelfBigHexSign256(void *param_1,int param_2)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  undefined1 auStack_3c [36];
  undefined4 uStack_18;
  
  if (*(int *)((int)param_1 + 0x28) == 0) {
    if (*(int *)(param_2 + 0x28) == 0) {
      uVar3 = *(uint *)((int)param_1 + 0x24);
      if (uVar3 <= *(uint *)(param_2 + 0x24)) {
        if (uVar3 < *(uint *)(param_2 + 0x24)) {
_L71:
          (**(code **)(_r_modules_funcs_p + 0x3ac))
                    (param_2,param_1,auStack_3c,*(code **)(_r_modules_funcs_p + 0x3ac));
          memcpy(param_1,auStack_3c,0x22);
          *(undefined4 *)((int)param_1 + 0x24) = uStack_18;
          *(undefined4 *)((int)param_1 + 0x28) = 1;
          return;
        }
        for (uVar3 = 0x11 - uVar3; uVar3 < 0x11; uVar3 = uVar3 + 1) {
          uVar1 = *(ushort *)(param_2 + uVar3 * 2);
          uVar2 = *(ushort *)(uVar3 * 2 + (int)param_1);
          if (uVar2 < uVar1) goto _L71;
          if (uVar1 < uVar2) break;
        }
      }
_L77:
                    /* WARNING: Could not recover jumptable at 0x000103aa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(_r_modules_funcs_p + 0x3b8))
                (param_1,param_2,*(code **)(_r_modules_funcs_p + 0x3b8));
      return;
    }
  }
  else if (*(int *)(param_2 + 0x28) != 0) {
    uVar3 = *(uint *)(param_2 + 0x24);
    if (uVar3 <= *(uint *)((int)param_1 + 0x24)) {
      if (uVar3 < *(uint *)((int)param_1 + 0x24)) goto _L77;
      for (uVar3 = 0x11 - uVar3; uVar3 < 0x11; uVar3 = uVar3 + 1) {
        uVar1 = *(ushort *)((int)param_1 + uVar3 * 2);
        uVar2 = *(ushort *)(uVar3 * 2 + param_2);
        if (uVar2 < uVar1) goto _L77;
        if (uVar1 < uVar2) break;
      }
    }
    (**(code **)(_r_modules_funcs_p + 0x3ac))
              (param_2,param_1,auStack_3c,*(code **)(_r_modules_funcs_p + 0x3ac));
    memcpy(param_1,auStack_3c,0x22);
    *(undefined4 *)((int)param_1 + 0x28) = 0;
    *(undefined4 *)((int)param_1 + 0x24) = uStack_18;
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00010402. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_modules_funcs_p + 0x34c))(*(code **)(_r_modules_funcs_p + 0x34c));
  return;
}

