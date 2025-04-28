/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> h4tl.o -> r_h4tl_write
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_h4tl_write(int param_1,int param_2,int param_3,undefined4 param_4)

{
  char *pcVar1;
  undefined *puVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  (**(code **)(_r_modules_funcs_p + 0x2b4))(2,*(code **)(_r_modules_funcs_p + 0x2b4));
  *(char *)(param_2 + -1) = (char)param_1;
  if ((param_1 - 1U & 0xff) < 5) {
    param_1 = param_2 + -1;
    _DAT_00011034 = param_1;
    _DAT_0001103c = (undefined2)param_3;
    _DAT_00011038 = param_4;
    if (DAT_00011040 != -1) {
      return;
    }
    DAT_00011040 = '\0';
    pcVar1 = *(char **)(_r_modules_funcs_p + 0x94);
    puVar2 = &h4tl_env;
    UNRECOVERED_JUMPTABLE = *(code **)(_h4tl_env + 4);
    param_3 = param_3 + 1;
  }
  else {
    (**(code **)(_r_plf_funcs_p + 0xc))(param_1,1,"h4tl.c",0x4f5,*(code **)(_r_plf_funcs_p + 0xc));
    puVar2 = (undefined *)0x50d;
    pcVar1 = "h4tl.c";
    UNRECOVERED_JUMPTABLE = *(code **)(_r_plf_funcs_p + 0xc);
    param_3 = 1;
  }
                    /* WARNING: Could not recover jumptable at 0x0001084a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(param_1,param_3,pcVar1,puVar2,UNRECOVERED_JUMPTABLE);
  return;
}

