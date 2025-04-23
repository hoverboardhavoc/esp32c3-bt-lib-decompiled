/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llc.o -> r_llc_proc_timer_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llc_proc_timer_set(int param_1,uint param_2,int param_3)

{
  byte bVar1;
  undefined1 uVar2;
  code *UNRECOVERED_JUMPTABLE;
  int iVar3;
  
  iVar3 = *(int *)(&llc_env + param_1 * 4);
  if (1 < param_2) {
    (**(code **)(_r_plf_funcs_p + 0xc))("llc.c",0x234,*(code **)(_r_plf_funcs_p + 0xc));
  }
  if ((iVar3 != 0) && (iVar3 = *(int *)(*(int *)(&llc_env + param_1 * 4) + param_2 * 4), iVar3 != 0)
     ) {
    bVar1 = *(byte *)(iVar3 + 6);
    uVar2 = 2;
    if (bVar1 == 2) {
      uVar2 = 3;
      if (param_3 != 0) {
        return;
      }
    }
    else {
      if (bVar1 < 3) {
        if (bVar1 == 0) {
          if (param_3 == 0) {
            return;
          }
          *(undefined1 *)(iVar3 + 6) = 1;
        }
        else {
          UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x668);
          if (param_3 == 0) {
            *(undefined1 *)(iVar3 + 6) = 0;
                    /* WARNING: Could not recover jumptable at 0x00010b52. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            (*UNRECOVERED_JUMPTABLE)(param_1,param_2,0,UNRECOVERED_JUMPTABLE);
            return;
          }
        }
                    /* WARNING: Could not recover jumptable at 0x00010af6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(_r_ip_funcs_p + 0x668))(param_1,param_2,1,*(code **)(_r_ip_funcs_p + 0x668));
        return;
      }
      if (bVar1 != 3) {
                    /* WARNING: Could not recover jumptable at 0x00010b28. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(_r_plf_funcs_p + 0xc))
                  (*(undefined1 *)(iVar3 + 4),"llc.c",0x26c,*(code **)(_r_plf_funcs_p + 0xc));
        return;
      }
      if (param_3 == 0) {
        return;
      }
    }
    *(undefined1 *)(iVar3 + 6) = uVar2;
  }
  return;
}

