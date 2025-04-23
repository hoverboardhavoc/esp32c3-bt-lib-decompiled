/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> hci_msg.o -> hci_le_adv_report_evt_pkupk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int hci_le_adv_report_evt_pkupk(undefined1 *param_1,undefined1 *param_2,ushort *param_3,int param_4)

{
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  ushort uVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  int iVar7;
  undefined1 *puStack_64;
  undefined1 *puStack_60;
  undefined1 auStack_5c [43];
  undefined1 auStack_31 [9];
  
  if (param_2 == (undefined1 *)0x0) {
    uVar4 = 0;
    iVar2 = 0;
  }
  else {
    if (param_1 == (undefined1 *)0x0) {
      puVar5 = auStack_31;
      param_1 = auStack_5c;
    }
    else {
      puVar5 = param_1 + *param_3;
    }
    puVar1 = param_2 + param_4;
    puStack_64 = param_2;
    puStack_60 = param_1;
    iVar2 = (**(code **)(_r_ip_funcs_p + 0xa4))
                      (&puStack_64,&puStack_60,puVar1,puVar5,1,*(code **)(_r_ip_funcs_p + 0xa4));
    if (iVar2 == 0) {
      puStack_64 = param_2 + 1;
      iVar3 = (**(code **)(_r_ip_funcs_p + 0xa4))
                        (&puStack_64,&puStack_60,puVar1,puVar5,1,*(code **)(_r_ip_funcs_p + 0xa4));
      iVar2 = iVar3;
      if (iVar3 == 0) {
        puVar6 = param_2 + 10;
        for (iVar7 = 0; iVar2 = iVar3, iVar7 < (int)(uint)(byte)param_2[1]; iVar7 = iVar7 + 1) {
          puStack_64 = puVar6 + -8;
          iVar2 = (**(code **)(_r_ip_funcs_p + 0xa4))
                            (&puStack_64,&puStack_60,puVar1,puVar5,1,
                             *(code **)(_r_ip_funcs_p + 0xa4));
          if (iVar2 != 0) break;
          puStack_64 = puVar6 + -7;
          iVar2 = (**(code **)(_r_ip_funcs_p + 0xa4))
                            (&puStack_64,&puStack_60,puVar1,puVar5,1,
                             *(code **)(_r_ip_funcs_p + 0xa4));
          if (iVar2 != 0) break;
          puStack_64 = puVar6 + -6;
          iVar2 = (**(code **)(_r_ip_funcs_p + 0xa4))
                            (&puStack_64,&puStack_60,puVar1,puVar5,6,
                             *(code **)(_r_ip_funcs_p + 0xa4));
          if ((iVar2 != 0) ||
             (puStack_64 = puVar6,
             iVar2 = (**(code **)(_r_ip_funcs_p + 0xa4))
                               (&puStack_64,&puStack_60,puVar1,puVar5,1,
                                *(code **)(_r_ip_funcs_p + 0xa4)), iVar2 != 0)) break;
          puStack_64 = puVar6 + 1;
          iVar2 = (**(code **)(_r_ip_funcs_p + 0xa4))
                            (&puStack_64,&puStack_60,puVar1,puVar5,*puVar6,
                             *(code **)(_r_ip_funcs_p + 0xa4));
          if (iVar2 != 0) break;
          puStack_64 = puVar6 + 0x20;
          iVar2 = (**(code **)(_r_ip_funcs_p + 0xa4))
                            (&puStack_64,&puStack_60,puVar1,puVar5,1,
                             *(code **)(_r_ip_funcs_p + 0xa4));
          puVar6 = puVar6 + 0x29;
          if (iVar2 != 0) break;
        }
      }
    }
    uVar4 = (short)puStack_60 - (short)param_1;
  }
  *param_3 = uVar4;
  return iVar2;
}

