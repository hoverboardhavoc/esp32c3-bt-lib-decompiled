/*
 * Last changed at upstream commit d2414a5dd958b32ca53382b441d24d97a0345a55
 * https://github.com/espressif/esp32c3-bt-lib/commit/d2414a5dd958b32ca53382b441d24d97a0345a55
 * Upstream date: 2025-03-20 20:11:19 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(03d0f8a6)
 * Source: libbtdm_app -> llc.o -> r_llc_llcp_state_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llc_llcp_state_set(int param_1,int param_2,uint param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  code *pcVar3;
  int iVar4;
  
  iVar4 = *(int *)(&llc_env + param_1 * 4);
  if (param_3 == 3) {
    if (param_2 == 2) goto _L84;
    uVar2 = 0x1a4;
    pcVar3 = *(code **)(_r_plf_funcs_p + 0xc);
    uVar1 = 3;
  }
  else {
    if ((param_3 != 0) || (param_2 == 2)) goto _L84;
    uVar2 = 0x1a5;
    pcVar3 = *(code **)(_r_plf_funcs_p + 0xc);
    uVar1 = 0;
  }
  (*pcVar3)(param_2,uVar1,"llc.c",uVar2,pcVar3);
_L84:
  if (((iVar4 == 0) || ((*(byte *)(iVar4 + 0x44) & 3) == 3)) ||
     (((int)(uint)*(byte *)(iVar4 + 0x44) >> 2 & 3U) == 3)) {
    return;
  }
  if (param_2 != 1) {
    if (param_2 == 0) {
      if ((param_3 & 0xfffffffc) != 0) {
        (**(code **)(_r_plf_funcs_p + 0xc))
                  (3,param_3,"llc.c",0x1b3,*(code **)(_r_plf_funcs_p + 0xc));
      }
      *(byte *)(iVar4 + 0x44) = (byte)param_3 | *(byte *)(iVar4 + 0x44) & 0xfc;
      return;
    }
    if (param_2 != 2) {
                    /* WARNING: Could not recover jumptable at 0x0001068c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(_r_plf_funcs_p + 0xc))(param_1,param_2,"llc.c",0x1c4);
      return;
    }
    if ((param_3 & 0xfffffffc) != 0) {
      (**(code **)(_r_plf_funcs_p + 0xc))(3,param_3,"llc.c",0x1b8,*(code **)(_r_plf_funcs_p + 0xc));
    }
    *(byte *)(iVar4 + 0x44) = *(byte *)(iVar4 + 0x44) & 0xfc | (byte)param_3;
  }
  if ((param_3 << 2 & 0xfffffff3) != 0) {
    (**(code **)(_r_plf_funcs_p + 0xc))(0xc,param_3,"llc.c",0x1bc,*(code **)(_r_plf_funcs_p + 0xc));
  }
  *(byte *)(iVar4 + 0x44) = *(byte *)(iVar4 + 0x44) & 0xf3 | (byte)(param_3 << 2);
                    /* WARNING: Could not recover jumptable at 0x00010766. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_ip_funcs_p + 0x5b8))(param_1);
  return;
}

