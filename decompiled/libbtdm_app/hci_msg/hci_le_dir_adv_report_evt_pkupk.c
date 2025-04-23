/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> hci_msg.o -> hci_le_dir_adv_report_evt_pkupk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int hci_le_dir_adv_report_evt_pkupk(undefined1 *param_1,int param_2,ushort *param_3,int param_4)

{
  int iVar1;
  int iVar2;
  ushort uVar3;
  undefined1 *puVar4;
  int iVar5;
  int iVar6;
  int iStack_4c;
  undefined1 *puStack_48;
  undefined1 auStack_44 [18];
  undefined1 auStack_32 [10];
  
  if (param_2 == 0) {
    uVar3 = 0;
    iVar1 = 0;
  }
  else {
    if (param_1 == (undefined1 *)0x0) {
      puVar4 = auStack_32;
      param_1 = auStack_44;
    }
    else {
      puVar4 = param_1 + *param_3;
    }
    param_4 = param_2 + param_4;
    iStack_4c = param_2;
    puStack_48 = param_1;
    iVar1 = (**(code **)(_r_ip_funcs_p + 0xa4))
                      (&iStack_4c,&puStack_48,param_4,puVar4,1,*(code **)(_r_ip_funcs_p + 0xa4));
    if (iVar1 == 0) {
      iStack_4c = param_2 + 1;
      iVar2 = (**(code **)(_r_ip_funcs_p + 0xa4))
                        (&iStack_4c,&puStack_48,param_4,puVar4,1,*(code **)(_r_ip_funcs_p + 0xa4));
      iVar1 = iVar2;
      if (iVar2 == 0) {
        iVar5 = param_2 + 0x11;
        for (iVar6 = 0; iVar1 = iVar2, iVar6 < (int)(uint)*(byte *)(param_2 + 1); iVar6 = iVar6 + 1)
        {
          iStack_4c = iVar5 + -0xf;
          iVar1 = (**(code **)(_r_ip_funcs_p + 0xa4))
                            (&iStack_4c,&puStack_48,param_4,puVar4,1,
                             *(code **)(_r_ip_funcs_p + 0xa4));
          if (iVar1 != 0) break;
          iStack_4c = iVar5 + -0xe;
          iVar1 = (**(code **)(_r_ip_funcs_p + 0xa4))
                            (&iStack_4c,&puStack_48,param_4,puVar4,1,
                             *(code **)(_r_ip_funcs_p + 0xa4));
          if (iVar1 != 0) break;
          iStack_4c = iVar5 + -0xd;
          iVar1 = (**(code **)(_r_ip_funcs_p + 0xa4))
                            (&iStack_4c,&puStack_48,param_4,puVar4,6,
                             *(code **)(_r_ip_funcs_p + 0xa4));
          if (iVar1 != 0) break;
          iStack_4c = iVar5 + -7;
          iVar1 = (**(code **)(_r_ip_funcs_p + 0xa4))
                            (&iStack_4c,&puStack_48,param_4,puVar4,1,
                             *(code **)(_r_ip_funcs_p + 0xa4));
          if (iVar1 != 0) break;
          iStack_4c = iVar5 + -6;
          iVar1 = (**(code **)(_r_ip_funcs_p + 0xa4))
                            (&iStack_4c,&puStack_48,param_4,puVar4,6,
                             *(code **)(_r_ip_funcs_p + 0xa4));
          if (iVar1 != 0) break;
          iStack_4c = iVar5;
          iVar1 = (**(code **)(_r_ip_funcs_p + 0xa4))
                            (&iStack_4c,&puStack_48,param_4,puVar4,1,
                             *(code **)(_r_ip_funcs_p + 0xa4));
          iVar5 = iVar5 + 0x10;
          if (iVar1 != 0) break;
        }
      }
    }
    uVar3 = (short)puStack_48 - (short)param_1;
  }
  *param_3 = uVar3;
  return iVar1;
}

