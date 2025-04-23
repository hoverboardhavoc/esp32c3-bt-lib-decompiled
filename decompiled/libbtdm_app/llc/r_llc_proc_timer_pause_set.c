/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llc.o -> r_llc_proc_timer_pause_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llc_proc_timer_pause_set(int param_1,uint param_2,int param_3)

{
  byte bVar1;
  undefined4 uVar2;
  code *UNRECOVERED_JUMPTABLE;
  int iVar3;
  
  iVar3 = *(int *)(&llc_env + param_1 * 4);
  if (1 < param_2) {
    (**(code **)(_r_plf_funcs_p + 0xc))("llc.c",0x282,*(code **)(_r_plf_funcs_p + 0xc));
  }
  if ((iVar3 != 0) && (iVar3 = *(int *)(*(int *)(&llc_env + param_1 * 4) + param_2 * 4), iVar3 != 0)
     ) {
    bVar1 = *(byte *)(iVar3 + 6);
    if (bVar1 == 2) {
      if (param_3 == 0) {
        uVar2 = 1;
        *(undefined1 *)(iVar3 + 6) = 1;
        UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x668);
_L190:
                    /* WARNING: Could not recover jumptable at 0x00010c54. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*UNRECOVERED_JUMPTABLE)(param_1,param_2,uVar2,UNRECOVERED_JUMPTABLE);
        return;
      }
    }
    else if (bVar1 < 3) {
      if (bVar1 == 0) {
        if (param_3 != 0) {
          *(undefined1 *)(iVar3 + 6) = 3;
        }
      }
      else if (param_3 != 0) {
        *(undefined1 *)(iVar3 + 6) = 2;
        uVar2 = 0;
        UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x668);
        goto _L190;
      }
    }
    else {
      if (bVar1 != 3) {
                    /* WARNING: Could not recover jumptable at 0x00010c2a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(_r_plf_funcs_p + 0xc))
                  (*(undefined1 *)(iVar3 + 4),"llc.c",0x2b6,*(code **)(_r_plf_funcs_p + 0xc));
        return;
      }
      if (param_3 == 0) {
        *(undefined1 *)(iVar3 + 6) = 0;
      }
    }
  }
  return;
}

