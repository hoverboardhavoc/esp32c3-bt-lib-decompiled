/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> hci_msg.o -> hci_le_dir_adv_report_evt_pkupk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int hci_le_dir_adv_report_evt_pkupk(undefined1 *param_1,int param_2,ushort *param_3,int param_4)

{
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iStack_4c;
  undefined1 *puStack_48;
  undefined1 auStack_44 [18];
  undefined1 auStack_32 [10];
  
  if (param_2 == 0) {
    *param_3 = 0;
    iVar2 = 0;
  }
  else {
    if (param_1 == (undefined1 *)0x0) {
      puVar1 = auStack_32;
      param_1 = auStack_44;
    }
    else {
      puVar1 = param_1 + *param_3;
    }
    param_4 = param_2 + param_4;
    iStack_4c = param_2;
    puStack_48 = param_1;
    iVar2 = (**(code **)(_r_ip_funcs_p + 0xa4))
                      (&iStack_4c,&puStack_48,param_4,puVar1,1,*(code **)(_r_ip_funcs_p + 0xa4));
    if (iVar2 == 0) {
      iStack_4c = param_2 + 1;
      iVar3 = (**(code **)(_r_ip_funcs_p + 0xa4))
                        (&iStack_4c,&puStack_48,param_4,puVar1,1,*(code **)(_r_ip_funcs_p + 0xa4));
      iVar2 = iVar3;
      if (iVar3 == 0) {
        iVar4 = param_2 + 0x11;
        for (iVar5 = 0; iVar2 = iVar3, iVar5 < (int)(uint)*(byte *)(param_2 + 1); iVar5 = iVar5 + 1)
        {
          iStack_4c = iVar4 + -0xf;
          iVar2 = (**(code **)(_r_ip_funcs_p + 0xa4))
                            (&iStack_4c,&puStack_48,param_4,puVar1,1,
                             *(code **)(_r_ip_funcs_p + 0xa4));
          if (iVar2 != 0) break;
          iStack_4c = iVar4 + -0xe;
          iVar2 = (**(code **)(_r_ip_funcs_p + 0xa4))
                            (&iStack_4c,&puStack_48,param_4,puVar1,1,
                             *(code **)(_r_ip_funcs_p + 0xa4));
          if (iVar2 != 0) break;
          iStack_4c = iVar4 + -0xd;
          iVar2 = (**(code **)(_r_ip_funcs_p + 0xa4))
                            (&iStack_4c,&puStack_48,param_4,puVar1,6,
                             *(code **)(_r_ip_funcs_p + 0xa4));
          if (iVar2 != 0) break;
          iStack_4c = iVar4 + -7;
          iVar2 = (**(code **)(_r_ip_funcs_p + 0xa4))
                            (&iStack_4c,&puStack_48,param_4,puVar1,1,
                             *(code **)(_r_ip_funcs_p + 0xa4));
          if (iVar2 != 0) break;
          iStack_4c = iVar4 + -6;
          iVar2 = (**(code **)(_r_ip_funcs_p + 0xa4))
                            (&iStack_4c,&puStack_48,param_4,puVar1,6,
                             *(code **)(_r_ip_funcs_p + 0xa4));
          if (iVar2 != 0) break;
          iStack_4c = iVar4;
          iVar2 = (**(code **)(_r_ip_funcs_p + 0xa4))
                            (&iStack_4c,&puStack_48,param_4,puVar1,1,
                             *(code **)(_r_ip_funcs_p + 0xa4));
          iVar4 = iVar4 + 0x10;
          if (iVar2 != 0) break;
        }
      }
    }
    *param_3 = (short)puStack_48 - (short)param_1;
  }
  return iVar2;
}

