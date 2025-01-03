/*
 * Last changed at upstream commit ed99228396aaa18935b575d600bc19da38dc4746
 * https://github.com/espressif/esp32c3-bt-lib/commit/ed99228396aaa18935b575d600bc19da38dc4746
 * Upstream date: 2025-01-03 16:50:09 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(fd62b31)
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
                    /* WARNING: Could not recover jumptable at 0x00011a54. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_modules_funcs_p + 0x278))(uVar1,uVar4,uVar2,extraout_a1_00,0);
  return;
}

