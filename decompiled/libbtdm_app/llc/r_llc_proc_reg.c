/*
 * Last changed at upstream commit e668c2d101ee46ee1950819607694fb852aecae0
 * https://github.com/espressif/esp32c3-bt-lib/commit/e668c2d101ee46ee1950819607694fb852aecae0
 * Upstream date: 2025-03-14 11:07:43 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(6e312587)
 * Source: libbtdm_app -> llc.o -> r_llc_proc_reg
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llc_proc_reg(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  
  uVar2 = param_1 << 8 | 1;
  uVar1 = (**(code **)(_r_modules_funcs_p + 0x150))(uVar2,*(code **)(_r_modules_funcs_p + 0x150));
  iVar3 = *(int *)(&llc_env + param_1 * 4);
  if (1 < param_2) {
    (**(code **)(_r_plf_funcs_p + 0xc))
              (param_1,param_2,"llc.c",0x1cc,*(code **)(_r_plf_funcs_p + 0xc));
  }
  piVar4 = (int *)(iVar3 + param_2 * 4);
  if (*piVar4 != 0) {
    (**(code **)(_r_plf_funcs_p + 0xc))
              (param_1,param_2,"llc.c",0x1cd,*(code **)(_r_plf_funcs_p + 0xc));
  }
  *piVar4 = param_3;
  if (uVar1 == 0xff) {
    (**(code **)(_r_plf_funcs_p + 0xc))(param_1,0xff,"llc.c",0x1d2,*(code **)(_r_plf_funcs_p + 0xc))
    ;
  }
                    /* WARNING: Could not recover jumptable at 0x0001084a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_modules_funcs_p + 0x154))(uVar2,(1 << (param_2 & 0x1f) | uVar1) & 0xff);
  return;
}

