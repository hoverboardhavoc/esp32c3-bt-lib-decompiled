/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> hci_msg.o -> hci_le_ext_create_con_cmd_upk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int hci_le_ext_create_con_cmd_upk(undefined1 *param_1,int param_2,ushort *param_3,int param_4)

{
  bool bVar1;
  undefined1 *puVar2;
  int iVar3;
  ushort uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iStack_74;
  undefined1 *puStack_70;
  undefined1 auStack_6c [58];
  undefined1 auStack_32 [14];
  
  if (param_2 == 0) {
    uVar4 = 0x3a;
    iVar3 = 0;
  }
  else {
    bVar1 = param_1 == (undefined1 *)0x0;
    if (bVar1) {
      puVar2 = auStack_32;
      param_1 = auStack_6c;
    }
    else {
      puVar2 = param_1 + *param_3;
    }
    param_4 = param_2 + param_4;
    iStack_74 = param_2;
    puStack_70 = param_1;
    iVar3 = (**(code **)(_r_ip_funcs_p + 0xa4))
                      (&iStack_74,&puStack_70,param_4,puVar2,1,*(code **)(_r_ip_funcs_p + 0xa4));
    if (iVar3 == 0) {
      puStack_70 = param_1 + 1;
      iVar3 = (**(code **)(_r_ip_funcs_p + 0xa4))
                        (&iStack_74,&puStack_70,param_4,puVar2,1,*(code **)(_r_ip_funcs_p + 0xa4));
      if (iVar3 == 0) {
        puStack_70 = param_1 + 2;
        iVar3 = (**(code **)(_r_ip_funcs_p + 0xa4))
                          (&iStack_74,&puStack_70,param_4,puVar2,1,*(code **)(_r_ip_funcs_p + 0xa4))
        ;
        if (iVar3 == 0) {
          puStack_70 = param_1 + 3;
          iVar3 = (**(code **)(_r_ip_funcs_p + 0xa4))
                            (&iStack_74,&puStack_70,param_4,puVar2,6,
                             *(code **)(_r_ip_funcs_p + 0xa4));
          if (iVar3 == 0) {
            puStack_70 = param_1 + 9;
            iVar3 = (**(code **)(_r_ip_funcs_p + 0xa4))
                              (&iStack_74,&puStack_70,param_4,puVar2,1,
                               *(code **)(_r_ip_funcs_p + 0xa4));
            if (iVar3 == 0) {
              uVar6 = 0;
              for (uVar5 = (uint)(byte)param_1[9]; uVar5 != 0; uVar5 = uVar5 >> 1) {
                uVar6 = (uVar5 & 1) + uVar6 & 0xff;
              }
              if (3 < uVar6) {
                (**(code **)(_r_plf_funcs_p + 8))
                          (0,"hci_msg.c",0x7b7,*(code **)(_r_plf_funcs_p + 8));
              }
              uVar5 = (uint)puVar2 & -(uint)!bVar1;
              puVar2 = param_1 + 0x18;
              for (iVar7 = 0; iVar7 < (int)uVar6; iVar7 = iVar7 + 1) {
                puStack_70 = puVar2 + -0xe;
                iVar3 = (**(code **)(_r_ip_funcs_p + 0xa4))
                                  (&iStack_74,&puStack_70,param_4,uVar5,2,
                                   *(code **)(_r_ip_funcs_p + 0xa4));
                if (iVar3 != 0) goto _L39;
                puStack_70 = puVar2 + -0xc;
                iVar3 = (**(code **)(_r_ip_funcs_p + 0xa4))
                                  (&iStack_74,&puStack_70,param_4,uVar5,2,
                                   *(code **)(_r_ip_funcs_p + 0xa4));
                if (iVar3 != 0) goto _L39;
                puStack_70 = puVar2 + -10;
                iVar3 = (**(code **)(_r_ip_funcs_p + 0xa4))
                                  (&iStack_74,&puStack_70,param_4,uVar5,2,
                                   *(code **)(_r_ip_funcs_p + 0xa4));
                if (iVar3 != 0) goto _L39;
                puStack_70 = puVar2 + -8;
                iVar3 = (**(code **)(_r_ip_funcs_p + 0xa4))
                                  (&iStack_74,&puStack_70,param_4,uVar5,2,
                                   *(code **)(_r_ip_funcs_p + 0xa4));
                if (iVar3 != 0) goto _L39;
                puStack_70 = puVar2 + -6;
                iVar3 = (**(code **)(_r_ip_funcs_p + 0xa4))
                                  (&iStack_74,&puStack_70,param_4,uVar5,2,
                                   *(code **)(_r_ip_funcs_p + 0xa4));
                if (iVar3 != 0) goto _L39;
                puStack_70 = puVar2 + -4;
                iVar3 = (**(code **)(_r_ip_funcs_p + 0xa4))
                                  (&iStack_74,&puStack_70,param_4,uVar5,2,
                                   *(code **)(_r_ip_funcs_p + 0xa4));
                if (iVar3 != 0) goto _L39;
                puStack_70 = puVar2 + -2;
                iVar3 = (**(code **)(_r_ip_funcs_p + 0xa4))
                                  (&iStack_74,&puStack_70,param_4,uVar5,2,
                                   *(code **)(_r_ip_funcs_p + 0xa4));
                if (iVar3 != 0) goto _L39;
                puStack_70 = puVar2;
                iVar3 = (**(code **)(_r_ip_funcs_p + 0xa4))
                                  (&iStack_74,&puStack_70,param_4,uVar5,2,
                                   *(code **)(_r_ip_funcs_p + 0xa4));
                puVar2 = puVar2 + 0x10;
                if (iVar3 != 0) goto _L39;
              }
              iVar3 = 0;
            }
          }
        }
      }
    }
_L39:
    uVar4 = (short)puStack_70 - (short)param_1;
  }
  *param_3 = uVar4;
  return iVar3;
}

