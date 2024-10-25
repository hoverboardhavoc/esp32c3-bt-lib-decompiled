/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> hci_msg.o -> hci_le_ext_adv_report_evt_pkupk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int hci_le_ext_adv_report_evt_pkupk
              (undefined1 *param_1,undefined1 *param_2,ushort *param_3,int param_4)

{
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  int iVar6;
  undefined1 *puStack_138;
  undefined1 *puStack_134;
  undefined1 auStack_130 [256];
  undefined1 auStack_30 [8];
  
  if (param_2 == (undefined1 *)0x0) {
    *param_3 = 0;
    iVar2 = 0;
  }
  else {
    if (param_1 == (undefined1 *)0x0) {
      puVar1 = auStack_30;
      param_1 = auStack_130;
    }
    else {
      puVar1 = param_1 + *param_3;
    }
    puVar4 = param_2 + param_4;
    puStack_138 = param_2;
    puStack_134 = param_1;
    iVar2 = (**(code **)(_r_ip_funcs_p + 0xa4))
                      (&puStack_138,&puStack_134,puVar4,puVar1,1,*(code **)(_r_ip_funcs_p + 0xa4));
    if (iVar2 == 0) {
      puStack_138 = param_2 + 1;
      iVar3 = (**(code **)(_r_ip_funcs_p + 0xa4))
                        (&puStack_138,&puStack_134,puVar4,puVar1,1,*(code **)(_r_ip_funcs_p + 0xa4))
      ;
      iVar2 = iVar3;
      if (iVar3 == 0) {
        puVar5 = param_2 + 0x19;
        for (iVar6 = 0; iVar2 = iVar3, iVar6 < (int)(uint)(byte)param_2[1]; iVar6 = iVar6 + 1) {
          puStack_138 = puVar5 + -0x17;
          iVar2 = (**(code **)(_r_ip_funcs_p + 0xa4))
                            (&puStack_138,&puStack_134,puVar4,puVar1,2,
                             *(code **)(_r_ip_funcs_p + 0xa4));
          if (iVar2 != 0) break;
          puStack_138 = puVar5 + -0x15;
          iVar2 = (**(code **)(_r_ip_funcs_p + 0xa4))
                            (&puStack_138,&puStack_134,puVar4,puVar1,1,
                             *(code **)(_r_ip_funcs_p + 0xa4));
          if (iVar2 != 0) break;
          puStack_138 = puVar5 + -0x14;
          iVar2 = (**(code **)(_r_ip_funcs_p + 0xa4))
                            (&puStack_138,&puStack_134,puVar4,puVar1,6,
                             *(code **)(_r_ip_funcs_p + 0xa4));
          if (iVar2 != 0) break;
          puStack_138 = puVar5 + -0xe;
          iVar2 = (**(code **)(_r_ip_funcs_p + 0xa4))
                            (&puStack_138,&puStack_134,puVar4,puVar1,1,
                             *(code **)(_r_ip_funcs_p + 0xa4));
          if (iVar2 != 0) break;
          puStack_138 = puVar5 + -0xd;
          iVar2 = (**(code **)(_r_ip_funcs_p + 0xa4))
                            (&puStack_138,&puStack_134,puVar4,puVar1,1,
                             *(code **)(_r_ip_funcs_p + 0xa4));
          if (iVar2 != 0) break;
          puStack_138 = puVar5 + -0xc;
          iVar2 = (**(code **)(_r_ip_funcs_p + 0xa4))
                            (&puStack_138,&puStack_134,puVar4,puVar1,1,
                             *(code **)(_r_ip_funcs_p + 0xa4));
          if (iVar2 != 0) break;
          puStack_138 = puVar5 + -0xb;
          iVar2 = (**(code **)(_r_ip_funcs_p + 0xa4))
                            (&puStack_138,&puStack_134,puVar4,puVar1,1,
                             *(code **)(_r_ip_funcs_p + 0xa4));
          if (iVar2 != 0) break;
          puStack_138 = puVar5 + -10;
          iVar2 = (**(code **)(_r_ip_funcs_p + 0xa4))
                            (&puStack_138,&puStack_134,puVar4,puVar1,1,
                             *(code **)(_r_ip_funcs_p + 0xa4));
          if (iVar2 != 0) break;
          puStack_138 = puVar5 + -9;
          iVar2 = (**(code **)(_r_ip_funcs_p + 0xa4))
                            (&puStack_138,&puStack_134,puVar4,puVar1,2,
                             *(code **)(_r_ip_funcs_p + 0xa4));
          if (iVar2 != 0) break;
          puStack_138 = puVar5 + -7;
          iVar2 = (**(code **)(_r_ip_funcs_p + 0xa4))
                            (&puStack_138,&puStack_134,puVar4,puVar1,1,
                             *(code **)(_r_ip_funcs_p + 0xa4));
          if (iVar2 != 0) break;
          puStack_138 = puVar5 + -6;
          iVar2 = (**(code **)(_r_ip_funcs_p + 0xa4))
                            (&puStack_138,&puStack_134,puVar4,puVar1,6,
                             *(code **)(_r_ip_funcs_p + 0xa4));
          if ((iVar2 != 0) ||
             (puStack_138 = puVar5,
             iVar2 = (**(code **)(_r_ip_funcs_p + 0xa4))
                               (&puStack_138,&puStack_134,puVar4,puVar1,1,
                                *(code **)(_r_ip_funcs_p + 0xa4)), iVar2 != 0)) break;
          puStack_138 = puVar5 + 1;
          iVar2 = (**(code **)(_r_ip_funcs_p + 0xa4))
                            (&puStack_138,&puStack_134,puVar4,puVar1,*puVar5,
                             *(code **)(_r_ip_funcs_p + 0xa4));
          puVar5 = puVar5 + 0xfe;
          if (iVar2 != 0) break;
        }
      }
    }
    *param_3 = (short)puStack_134 - (short)param_1;
  }
  return iVar2;
}

