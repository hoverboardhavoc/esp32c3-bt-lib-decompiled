/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
    uVar2 = 0x1a7;
    pcVar3 = *(code **)(_r_plf_funcs_p + 0xc);
    uVar1 = 3;
  }
  else {
    if ((param_3 != 0) || (param_2 == 2)) goto _L84;
    uVar2 = 0x1a8;
    pcVar3 = *(code **)(_r_plf_funcs_p + 0xc);
    uVar1 = 0;
  }
  (*pcVar3)(param_2,uVar1,"llc.c",uVar2,pcVar3);
_L84:
  if (((iVar4 != 0) && ((*(byte *)(iVar4 + 0x44) & 3) != 3)) &&
     ((*(byte *)(iVar4 + 0x44) & 0xc) != 0xc)) {
    if (param_2 != 1) {
      if (param_2 != 2) {
        if (param_2 == 0) {
          if (3 < param_3) {
            (**(code **)(_r_plf_funcs_p + 0xc))
                      (param_3,"llc.c",0x1b6,*(code **)(_r_plf_funcs_p + 0xc));
          }
          *(byte *)(iVar4 + 0x44) = *(byte *)(iVar4 + 0x44) & 0xfc | (byte)param_3;
          return;
        }
                    /* WARNING: Could not recover jumptable at 0x0001075a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(_r_plf_funcs_p + 0xc))
                  (param_1,param_2,"llc.c",0x1c7,*(code **)(_r_plf_funcs_p + 0xc));
        return;
      }
      if (3 < param_3) {
        (**(code **)(_r_plf_funcs_p + 0xc))(param_3,"llc.c",0x1bb,*(code **)(_r_plf_funcs_p + 0xc));
      }
      *(byte *)(iVar4 + 0x44) = *(byte *)(iVar4 + 0x44) & 0xfc | (byte)param_3;
    }
    if ((param_3 & 0xfc) != 0) {
      (**(code **)(_r_plf_funcs_p + 0xc))
                (0xc,param_3,"llc.c",0x1bf,*(code **)(_r_plf_funcs_p + 0xc));
    }
    *(byte *)(iVar4 + 0x44) = *(byte *)(iVar4 + 0x44) & 0xf3 | (byte)(param_3 << 2);
                    /* WARNING: Could not recover jumptable at 0x00010732. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_ip_funcs_p + 0x5b8))(param_1,*(code **)(_r_ip_funcs_p + 0x5b8));
    return;
  }
  return;
}

