/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  code *UNRECOVERED_JUMPTABLE;
  
  if (param_1 == 0) {
    UNRECOVERED_JUMPTABLE = *(code **)(_r_plf_funcs_p + 8);
    uVar5 = 0x9ac;
  }
  else {
    if (*(char *)(param_1 + 0x89) != '\0') {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x97a,*(code **)(_r_plf_funcs_p + 8));
    }
    cVar1 = rwip_priority;
    if ((*(ushort *)(param_1 + 0x74) & 8) == 0) {
      if ((uint)(*(int *)(param_1 + 100) << 1) <=
          (*(int *)(param_1 + 4) - *(int *)(param_1 + 0x5c) & 0xfffffffU)) {
        *(int *)(param_1 + 0x5c) = *(int *)(param_1 + 4);
        *(char *)(param_1 + 0x16) = *(char *)(param_1 + 0x16) + cVar1;
        uVar3 = (**(code **)(_r_osi_funcs_p + 0x88))(*(code **)(_r_osi_funcs_p + 0x88));
        uVar4 = uVar3 % 0x11 << 1;
        if (*(char *)(param_1 + 0x95) != '\0') {
          if (uVar4 < 0x20) {
            if (uVar3 % 0x11 == 0) {
              uVar4 = 1;
            }
          }
          else {
            uVar4 = 0x1f;
          }
        }
        *(uint *)(param_1 + 4) =
             (uVar4 & -(uint)(g_adv_delay_dis == '\0')) + *(int *)(param_1 + 4) & 0xfffffff;
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
                    /* WARNING: Could not recover jumptable at 0x000142ec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(_r_ip_funcs_p + 0x1a0))
                (*(undefined1 *)(param_1 + 0x87),1,0x3c,*(code **)(_r_ip_funcs_p + 0x1a0));
      return;
    }
    UNRECOVERED_JUMPTABLE = *(code **)(_r_plf_funcs_p + 8);
    uVar5 = 0x9a5;
  }
                    /* WARNING: Could not recover jumptable at 0x0001438e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(0,"lld_adv.c",uVar5,UNRECOVERED_JUMPTABLE);
  return;
}

