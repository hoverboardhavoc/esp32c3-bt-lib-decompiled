/*
 * Last changed at upstream commit 4c16da1a1a76b439e2cf981d2f915d94df364e58
 * https://github.com/espressif/esp32c3-bt-lib/commit/4c16da1a1a76b439e2cf981d2f915d94df364e58
 * Upstream date: 2024-12-16 11:11:02 +0800
 * Upstream subject: fix(bt): Fixed that the resolvable private address does not change when light sleep is enabled(6bca137)
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
                    /* WARNING: Could not recover jumptable at 0x00011a10. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_modules_funcs_p + 0x278))(uVar1,uVar4,uVar2,extraout_a1_00,0);
  return;
}

