/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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
  uint uVar4;
  undefined1 *puVar5;
  uint uVar6;
  int iVar7;
  int iStack_74;
  undefined1 *puStack_70;
  undefined1 auStack_6c [58];
  undefined1 auStack_32 [14];
  
  if (param_2 == 0) {
    *param_3 = 0x3a;
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
                puVar2 = (undefined1 *)0x0;
              }
              puVar5 = param_1 + 0x18;
              for (iVar7 = 0; iVar7 < (int)uVar6; iVar7 = iVar7 + 1) {
                puStack_70 = puVar5 + -0xe;
                iVar3 = (**(code **)(_r_ip_funcs_p + 0xa4))
                                  (&iStack_74,&puStack_70,param_4,puVar2,2,
                                   *(code **)(_r_ip_funcs_p + 0xa4));
                if (iVar3 != 0) goto _L41;
                puStack_70 = puVar5 + -0xc;
                iVar3 = (**(code **)(_r_ip_funcs_p + 0xa4))
                                  (&iStack_74,&puStack_70,param_4,puVar2,2,
                                   *(code **)(_r_ip_funcs_p + 0xa4));
                if (iVar3 != 0) goto _L41;
                puStack_70 = puVar5 + -10;
                iVar3 = (**(code **)(_r_ip_funcs_p + 0xa4))
                                  (&iStack_74,&puStack_70,param_4,puVar2,2,
                                   *(code **)(_r_ip_funcs_p + 0xa4));
                if (iVar3 != 0) goto _L41;
                puStack_70 = puVar5 + -8;
                iVar3 = (**(code **)(_r_ip_funcs_p + 0xa4))
                                  (&iStack_74,&puStack_70,param_4,puVar2,2,
                                   *(code **)(_r_ip_funcs_p + 0xa4));
                if (iVar3 != 0) goto _L41;
                puStack_70 = puVar5 + -6;
                iVar3 = (**(code **)(_r_ip_funcs_p + 0xa4))
                                  (&iStack_74,&puStack_70,param_4,puVar2,2,
                                   *(code **)(_r_ip_funcs_p + 0xa4));
                if (iVar3 != 0) goto _L41;
                puStack_70 = puVar5 + -4;
                iVar3 = (**(code **)(_r_ip_funcs_p + 0xa4))
                                  (&iStack_74,&puStack_70,param_4,puVar2,2,
                                   *(code **)(_r_ip_funcs_p + 0xa4));
                if (iVar3 != 0) goto _L41;
                puStack_70 = puVar5 + -2;
                iVar3 = (**(code **)(_r_ip_funcs_p + 0xa4))
                                  (&iStack_74,&puStack_70,param_4,puVar2,2,
                                   *(code **)(_r_ip_funcs_p + 0xa4));
                if (iVar3 != 0) goto _L41;
                puStack_70 = puVar5;
                iVar3 = (**(code **)(_r_ip_funcs_p + 0xa4))
                                  (&iStack_74,&puStack_70,param_4,puVar2,2,
                                   *(code **)(_r_ip_funcs_p + 0xa4));
                puVar5 = puVar5 + 0x10;
                if (iVar3 != 0) goto _L41;
              }
              iVar3 = 0;
            }
          }
        }
      }
    }
_L41:
    *param_3 = (short)puStack_70 - (short)param_1;
  }
  return iVar3;
}

