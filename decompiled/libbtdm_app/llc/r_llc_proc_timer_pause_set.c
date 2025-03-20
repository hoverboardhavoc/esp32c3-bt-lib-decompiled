/*
 * Last changed at upstream commit aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * https://github.com/espressif/esp32c3-bt-lib/commit/aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * Upstream date: 2025-03-20 20:31:24 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(d74042a8)
 * Source: libbtdm_app -> llc.o -> r_llc_proc_timer_pause_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llc_proc_timer_pause_set(int param_1,uint param_2,int param_3)

{
  char cVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = *(int *)(&llc_env + param_1 * 4);
  if (1 < param_2) {
    (**(code **)(_r_plf_funcs_p + 0xc))("llc.c",0x279,*(code **)(_r_plf_funcs_p + 0xc));
  }
  if ((iVar3 != 0) && (iVar3 = *(int *)(*(int *)(&llc_env + param_1 * 4) + param_2 * 4), iVar3 != 0)
     ) {
    cVar1 = *(char *)(iVar3 + 6);
    if (cVar1 == '\x01') {
      if (param_3 != 0) {
        *(undefined1 *)(iVar3 + 6) = 2;
        uVar2 = 0;
        UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x668);
_L193:
                    /* WARNING: Could not recover jumptable at 0x00010c5c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*UNRECOVERED_JUMPTABLE)(param_1,param_2,uVar2);
        return;
      }
    }
    else if (cVar1 == '\0') {
      if (param_3 != 0) {
        *(undefined1 *)(iVar3 + 6) = 3;
      }
    }
    else if (cVar1 == '\x02') {
      if (param_3 == 0) {
        *(undefined1 *)(iVar3 + 6) = 1;
        uVar2 = 1;
        UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x668);
        goto _L193;
      }
    }
    else {
      if (cVar1 != '\x03') {
                    /* WARNING: Could not recover jumptable at 0x00010c16. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(_r_plf_funcs_p + 0xc))(*(undefined1 *)(iVar3 + 4),"llc.c",0x2ad);
        return;
      }
      if (param_3 == 0) {
        *(undefined1 *)(iVar3 + 6) = 0;
      }
    }
  }
  return;
}

