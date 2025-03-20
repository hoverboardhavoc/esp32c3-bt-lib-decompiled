/*
 * Last changed at upstream commit daab5dbba958a13041bd496e4a6ed506c9284a06
 * https://github.com/espressif/esp32c3-bt-lib/commit/daab5dbba958a13041bd496e4a6ed506c9284a06
 * Upstream date: 2025-03-20 20:43:40 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(86a4da5c)
 * Source: libbtdm_app -> lld_adv.o -> r_lld_adv_evt_canceled_cbk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_adv_evt_canceled_cbk(int param_1)

{
  char cVar1;
  code *UNRECOVERED_JUMPTABLE;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  
  if (param_1 == 0) {
    UNRECOVERED_JUMPTABLE = *(code **)(_r_plf_funcs_p + 8);
    uVar4 = 0x9bb;
  }
  else {
    if (*(char *)(param_1 + 0x89) != '\0') {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x989,*(code **)(_r_plf_funcs_p + 8));
    }
    cVar1 = rwip_priority;
    if ((*(ushort *)(param_1 + 0x74) & 8) == 0) {
      if ((uint)(*(int *)(param_1 + 100) << 1) <=
          (*(int *)(param_1 + 4) - *(int *)(param_1 + 0x5c) & 0xfffffffU)) {
        *(int *)(param_1 + 0x5c) = *(int *)(param_1 + 4);
        *(char *)(param_1 + 0x16) = *(char *)(param_1 + 0x16) + cVar1;
        uVar3 = (**(code **)(_r_osi_funcs_p + 0x88))(*(code **)(_r_osi_funcs_p + 0x88));
        uVar3 = uVar3 % 0x11;
        iVar2 = uVar3 << 1;
        if (*(char *)(param_1 + 0x95) != '\0') {
          if (uVar3 == 0) {
            iVar2 = 1;
          }
          else if (uVar3 == 0x10) {
            iVar2 = 0x1f;
          }
        }
        if (g_adv_delay_dis != '\0') {
          iVar2 = 0;
        }
        *(uint *)(param_1 + 4) = iVar2 + *(int *)(param_1 + 4) & 0xfffffff;
      }
    }
    else {
      *(char *)(param_1 + 0x16) = *(char *)(param_1 + 0x16) + rwip_priority;
    }
    iVar2 = (**(code **)(_r_ip_funcs_p + 0x6b0))(param_1,*(code **)(_r_ip_funcs_p + 0x6b0));
    if ((iVar2 == 0) || (*(char *)(param_1 + 0x95) != '\0')) {
      return;
    }
    if (*(int *)(param_1 + 0x58) != -1) {
                    /* WARNING: Could not recover jumptable at 0x000142d2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(_r_ip_funcs_p + 0x1a0))(*(undefined1 *)(param_1 + 0x87),1,0x3c);
      return;
    }
    UNRECOVERED_JUMPTABLE = *(code **)(_r_plf_funcs_p + 8);
    uVar4 = 0x9b4;
  }
                    /* WARNING: Could not recover jumptable at 0x0001436c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(0,"lld_adv.c",uVar4);
  return;
}

