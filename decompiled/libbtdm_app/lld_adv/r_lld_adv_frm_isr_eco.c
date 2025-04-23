/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_adv.o -> r_lld_adv_frm_isr_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_adv_frm_isr_eco(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  byte bVar5;
  undefined4 unaff_s5;
  
  iVar1 = *(int *)(&lld_adv_env + param_1 * 4);
  if (iVar1 != 0) {
    if (*(uint *)(iVar1 + 100) < 0x20) {
      bVar5 = g_adv_delay_dis ^ 1;
      if (param_3 == 0) {
_L905:
        pcVar2 = (char *)(**(code **)(_r_ip_funcs_p + 0x914))(*(code **)(_r_ip_funcs_p + 0x914));
        if (*pcVar2 != '\0') {
          *(int *)(pcVar2 + 0xc) = *(int *)(pcVar2 + 0xc) + 1;
        }
      }
      if (bVar5 != 0) {
        g_adv_delay_dis = 1;
        unaff_s5 = *(undefined4 *)(iVar1 + 100);
        uVar3 = (**(code **)(_r_osi_funcs_p + 0x88))(*(code **)(_r_osi_funcs_p + 0x88));
        uVar4 = uVar3 % 9 << 1;
        if (*(char *)(iVar1 + 0x95) != '\0') {
          if (uVar4 < 0x10) {
            if (uVar3 % 9 == 0) {
              uVar4 = 1;
            }
          }
          else {
            uVar4 = 0xf;
          }
        }
        *(uint *)(iVar1 + 100) = *(int *)(iVar1 + 100) * 2 + uVar4 >> 1;
        goto _L892;
      }
    }
    else {
      bVar5 = 0;
      if (param_3 == 0) goto _L905;
    }
  }
  bVar5 = 0;
_L892:
  if ((adv_adv_data_need_to_set[param_1] != '\0') &&
     (((*(ushort *)(iVar1 + 0x74) & 0x10) == 0 || ((*(ushort *)(iVar1 + 0x74) & 0x14) == 0x10)))) {
    (**(code **)(_r_ip_funcs_p + 0x17c))
              (param_1,*(undefined1 *)(iVar1 + 0x28),*(undefined2 *)(iVar1 + 0x24),1,
               *(code **)(_r_ip_funcs_p + 0x17c));
    *(undefined2 *)(iVar1 + 0x24) = 0;
    adv_adv_data_need_to_set[param_1] = 0;
  }
  if ((adv_scan_rsp_data_need_to_set[param_1] != '\0') &&
     (((*(ushort *)(iVar1 + 0x74) & 0x12) == 2 || ((*(ushort *)(iVar1 + 0x74) & 0x14) == 0x10)))) {
    (**(code **)(_r_ip_funcs_p + 0x1d8))
              (param_1,*(undefined1 *)(iVar1 + 0x2a),*(undefined2 *)(iVar1 + 0x26),1,
               *(code **)(_r_ip_funcs_p + 0x1d8));
    *(undefined2 *)(iVar1 + 0x26) = 0;
    adv_scan_rsp_data_need_to_set[param_1] = 0;
  }
  r_lld_adv_frm_isr(param_1,param_2,param_3);
  if ((iVar1 != 0) && (bVar5 != 0)) {
    g_adv_delay_dis = 0;
    *(undefined4 *)(iVar1 + 100) = unaff_s5;
  }
  return;
}

