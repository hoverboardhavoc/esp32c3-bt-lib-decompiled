/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
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
  int iVar2;
  ushort uVar3;
  uint uVar4;
  undefined1 *puVar5;
  uint uVar6;
  int iVar7;
  undefined1 *puVar8;
  int iStack_74;
  undefined1 *puStack_70;
  undefined1 auStack_6c [58];
  undefined1 auStack_32 [14];
  
  if (param_2 == 0) {
    uVar3 = 0x3a;
    iVar2 = 0;
  }
  else {
    bVar1 = param_1 == (undefined1 *)0x0;
    if (bVar1) {
      puVar8 = auStack_32;
      param_1 = auStack_6c;
    }
    else {
      puVar8 = param_1 + *param_3;
    }
    param_4 = param_2 + param_4;
    iStack_74 = param_2;
    puStack_70 = param_1;
    iVar2 = (**(code **)(_r_ip_funcs_p + 0xa4))
                      (&iStack_74,&puStack_70,param_4,puVar8,1,*(code **)(_r_ip_funcs_p + 0xa4));
    if (iVar2 == 0) {
      puStack_70 = param_1 + 1;
      iVar2 = (**(code **)(_r_ip_funcs_p + 0xa4))
                        (&iStack_74,&puStack_70,param_4,puVar8,1,*(code **)(_r_ip_funcs_p + 0xa4));
      if (iVar2 == 0) {
        puStack_70 = param_1 + 2;
        iVar2 = (**(code **)(_r_ip_funcs_p + 0xa4))
                          (&iStack_74,&puStack_70,param_4,puVar8,1,*(code **)(_r_ip_funcs_p + 0xa4))
        ;
        if (iVar2 == 0) {
          puStack_70 = param_1 + 3;
          iVar2 = (**(code **)(_r_ip_funcs_p + 0xa4))
                            (&iStack_74,&puStack_70,param_4,puVar8,6,
                             *(code **)(_r_ip_funcs_p + 0xa4));
          if (iVar2 == 0) {
            puStack_70 = param_1 + 9;
            iVar2 = (**(code **)(_r_ip_funcs_p + 0xa4))
                              (&iStack_74,&puStack_70,param_4,puVar8,1,
                               *(code **)(_r_ip_funcs_p + 0xa4));
            if (iVar2 == 0) {
              uVar6 = 0;
              for (uVar4 = (uint)(byte)param_1[9]; uVar4 != 0; uVar4 = uVar4 >> 1) {
                if ((uVar4 & 1) != 0) {
                  uVar6 = uVar6 + 1 & 0xff;
                }
              }
              if (3 < uVar6) {
                (**(code **)(_r_plf_funcs_p + 8))
                          (0,"hci_msg.c",0x7b7,*(code **)(_r_plf_funcs_p + 8));
              }
              if (bVar1) {
                puVar8 = (undefined1 *)0x0;
              }
              puVar5 = param_1 + 0x18;
              for (iVar7 = 0; iVar7 < (int)uVar6; iVar7 = iVar7 + 1) {
                puStack_70 = puVar5 + -0xe;
                iVar2 = (**(code **)(_r_ip_funcs_p + 0xa4))
                                  (&iStack_74,&puStack_70,param_4,puVar8,2,
                                   *(code **)(_r_ip_funcs_p + 0xa4));
                if (iVar2 != 0) goto _L41;
                puStack_70 = puVar5 + -0xc;
                iVar2 = (**(code **)(_r_ip_funcs_p + 0xa4))
                                  (&iStack_74,&puStack_70,param_4,puVar8,2,
                                   *(code **)(_r_ip_funcs_p + 0xa4));
                if (iVar2 != 0) goto _L41;
                puStack_70 = puVar5 + -10;
                iVar2 = (**(code **)(_r_ip_funcs_p + 0xa4))
                                  (&iStack_74,&puStack_70,param_4,puVar8,2,
                                   *(code **)(_r_ip_funcs_p + 0xa4));
                if (iVar2 != 0) goto _L41;
                puStack_70 = puVar5 + -8;
                iVar2 = (**(code **)(_r_ip_funcs_p + 0xa4))
                                  (&iStack_74,&puStack_70,param_4,puVar8,2,
                                   *(code **)(_r_ip_funcs_p + 0xa4));
                if (iVar2 != 0) goto _L41;
                puStack_70 = puVar5 + -6;
                iVar2 = (**(code **)(_r_ip_funcs_p + 0xa4))
                                  (&iStack_74,&puStack_70,param_4,puVar8,2,
                                   *(code **)(_r_ip_funcs_p + 0xa4));
                if (iVar2 != 0) goto _L41;
                puStack_70 = puVar5 + -4;
                iVar2 = (**(code **)(_r_ip_funcs_p + 0xa4))
                                  (&iStack_74,&puStack_70,param_4,puVar8,2,
                                   *(code **)(_r_ip_funcs_p + 0xa4));
                if (iVar2 != 0) goto _L41;
                puStack_70 = puVar5 + -2;
                iVar2 = (**(code **)(_r_ip_funcs_p + 0xa4))
                                  (&iStack_74,&puStack_70,param_4,puVar8,2,
                                   *(code **)(_r_ip_funcs_p + 0xa4));
                if (iVar2 != 0) goto _L41;
                puStack_70 = puVar5;
                iVar2 = (**(code **)(_r_ip_funcs_p + 0xa4))
                                  (&iStack_74,&puStack_70,param_4,puVar8,2,
                                   *(code **)(_r_ip_funcs_p + 0xa4));
                puVar5 = puVar5 + 0x10;
                if (iVar2 != 0) goto _L41;
              }
              iVar2 = 0;
            }
          }
        }
      }
    }
_L41:
    uVar3 = (short)puStack_70 - (short)param_1;
  }
  *param_3 = uVar3;
  return iVar2;
}

