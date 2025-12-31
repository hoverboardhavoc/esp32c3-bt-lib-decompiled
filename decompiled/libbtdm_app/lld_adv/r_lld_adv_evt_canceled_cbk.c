/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
 * Source: libbtdm_app -> lld_adv.o -> r_lld_adv_evt_canceled_cbk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_adv_evt_canceled_cbk(int param_1)

{
  ushort uVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  code *UNRECOVERED_JUMPTABLE;
  
  if (param_1 == 0) {
    UNRECOVERED_JUMPTABLE = *(code **)(_r_plf_funcs_p + 8);
    uVar6 = 0x9eb;
  }
  else {
    if (*(char *)(param_1 + 0x89) != '\0') {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x9b9,*(code **)(_r_plf_funcs_p + 8));
    }
    cVar2 = rwip_priority;
    uVar1 = *(ushort *)(param_1 + 0x74);
    if ((uVar1 & 8) == 0) {
      if ((uint)(*(int *)(param_1 + 100) << 1) <=
          (*(int *)(param_1 + 4) - *(int *)(param_1 + 0x5c) & 0xfffffffU)) {
        *(int *)(param_1 + 0x5c) = *(int *)(param_1 + 4);
        *(char *)(param_1 + 0x16) = *(char *)(param_1 + 0x16) + cVar2;
        uVar4 = (**(code **)(_r_osi_funcs_p + 0x88))(*(code **)(_r_osi_funcs_p + 0x88));
        uVar4 = uVar4 % 0x11;
        uVar5 = uVar4 << 1;
        if (*(char *)(param_1 + 0x95) != '\0') {
          if (uVar4 == 0) {
            uVar5 = 1;
          }
          else if (uVar4 == 0x10) {
            uVar5 = 0x1f;
          }
        }
        uVar4 = uVar1 & 8;
        if (g_adv_delay_dis == '\0') {
          uVar4 = uVar5;
        }
        *(uint *)(param_1 + 4) = uVar4 + *(int *)(param_1 + 4) & 0xfffffff;
      }
    }
    else {
      *(char *)(param_1 + 0x16) = *(char *)(param_1 + 0x16) + rwip_priority;
    }
    iVar3 = (**(code **)(_r_ip_funcs_p + 0x6b0))(param_1,*(code **)(_r_ip_funcs_p + 0x6b0));
    if ((iVar3 == 0) || (*(char *)(param_1 + 0x95) != '\0')) {
      return;
    }
    if (*(int *)(param_1 + 0x58) != -1) {
                    /* WARNING: Could not recover jumptable at 0x00014436. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(_r_ip_funcs_p + 0x1a0))
                (*(undefined1 *)(param_1 + 0x87),1,0x3c,*(code **)(_r_ip_funcs_p + 0x1a0));
      return;
    }
    UNRECOVERED_JUMPTABLE = *(code **)(_r_plf_funcs_p + 8);
    uVar6 = 0x9e4;
  }
                    /* WARNING: Could not recover jumptable at 0x000144c6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(0,"lld_adv.c",uVar6,UNRECOVERED_JUMPTABLE);
  return;
}

