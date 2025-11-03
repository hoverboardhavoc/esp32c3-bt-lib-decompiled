/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
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
    if (param_2 == 2) goto _L83;
    uVar2 = 0x1ab;
    pcVar3 = *(code **)(_r_plf_funcs_p + 0xc);
    uVar1 = 3;
  }
  else {
    if ((param_3 != 0) || (param_2 == 2)) goto _L83;
    uVar2 = 0x1ac;
    pcVar3 = *(code **)(_r_plf_funcs_p + 0xc);
    uVar1 = 0;
  }
  (*pcVar3)(param_2,uVar1,"llc.c",uVar2,pcVar3);
_L83:
  if (((iVar4 != 0) && ((*(byte *)(iVar4 + 0x44) & 3) != 3)) &&
     (((int)(uint)*(byte *)(iVar4 + 0x44) >> 2 & 3U) != 3)) {
    if (param_2 != 1) {
      if (param_2 != 2) {
        if (param_2 == 0) {
          if ((param_3 & 0xfffffffc) != 0) {
            (**(code **)(_r_plf_funcs_p + 0xc))
                      (3,param_3,"llc.c",0x1bb,*(code **)(_r_plf_funcs_p + 0xc));
          }
          *(byte *)(iVar4 + 0x44) = *(byte *)(iVar4 + 0x44) & 0xfc | (byte)param_3;
          return;
        }
                    /* WARNING: Could not recover jumptable at 0x00010778. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(_r_plf_funcs_p + 0xc))
                  (param_1,param_2,"llc.c",0x1cc,*(code **)(_r_plf_funcs_p + 0xc));
        return;
      }
      if ((param_3 & 0xfffffffc) != 0) {
        (**(code **)(_r_plf_funcs_p + 0xc))
                  (3,param_3,"llc.c",0x1c0,*(code **)(_r_plf_funcs_p + 0xc));
      }
      *(byte *)(iVar4 + 0x44) = *(byte *)(iVar4 + 0x44) & 0xfc | (byte)param_3;
    }
    if ((param_3 << 2 & 0xfffffff3) != 0) {
      (**(code **)(_r_plf_funcs_p + 0xc))
                (0xc,param_3,"llc.c",0x1c4,*(code **)(_r_plf_funcs_p + 0xc));
    }
    *(byte *)(iVar4 + 0x44) = *(byte *)(iVar4 + 0x44) & 0xf3 | (byte)(param_3 << 2);
                    /* WARNING: Could not recover jumptable at 0x00010750. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_ip_funcs_p + 0x5b8))(param_1,*(code **)(_r_ip_funcs_p + 0x5b8));
    return;
  }
  return;
}

