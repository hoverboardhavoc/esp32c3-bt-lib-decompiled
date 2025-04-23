/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> arch_main.o -> r_assert_err
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_assert_err(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 extraout_a1;
  undefined4 extraout_a1_00;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar3 = 0;
  uVar2 = 0;
  uVar1 = (**(code **)(_r_modules_funcs_p + 0x278))
                    (param_1,param_2,0,0,1,*(code **)(_r_modules_funcs_p + 0x278));
  ebreak();
  uVar4 = extraout_a1;
  uVar2 = (**(code **)(_r_modules_funcs_p + 0x278))
                    (uVar2,uVar3,uVar1,extraout_a1,1,*(code **)(_r_modules_funcs_p + 0x278));
  ebreak();
                    /* WARNING: Could not recover jumptable at 0x00011f7c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_modules_funcs_p + 0x278))
            (uVar1,uVar4,uVar2,extraout_a1_00,0,*(code **)(_r_modules_funcs_p + 0x278));
  return;
}

