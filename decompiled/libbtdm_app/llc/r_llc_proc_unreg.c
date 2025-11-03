/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app -> llc.o -> r_llc_proc_unreg
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llc_proc_unreg(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  
  uVar4 = param_1 << 8 | 1;
  uVar1 = (**(code **)(_r_modules_funcs_p + 0x150))(uVar4,*(code **)(_r_modules_funcs_p + 0x150));
  iVar2 = *(int *)(&llc_env + param_1 * 4);
  if (1 < param_2) {
    (**(code **)(_r_plf_funcs_p + 0xc))
              (param_1,param_2,"llc.c",0x1eb,*(code **)(_r_plf_funcs_p + 0xc));
  }
  piVar3 = (int *)(iVar2 + param_2 * 4);
  if (*piVar3 == 0) {
    (**(code **)(_r_plf_funcs_p + 0xc))
              (param_1,param_2,"llc.c",0x1ec,*(code **)(_r_plf_funcs_p + 0xc));
  }
  (**(code **)(_r_ip_funcs_p + 0x68c))(param_1,param_2,0,*(code **)(_r_ip_funcs_p + 0x68c));
  (**(code **)(_r_modules_funcs_p + 0xd8))(*piVar3 + -0xc,*(code **)(_r_modules_funcs_p + 0xd8));
  *piVar3 = 0;
  if (uVar1 != 0xff) {
                    /* WARNING: Could not recover jumptable at 0x00010944. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_modules_funcs_p + 0x154))
              (uVar4,uVar1 & ~(1 << (param_2 & 0x1f)) & 0xff,*(code **)(_r_modules_funcs_p + 0x154))
    ;
    return;
  }
  return;
}

