/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> hci_msg.o -> hci_le_set_ext_adv_en_cmd_upk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int hci_le_set_ext_adv_en_cmd_upk(undefined1 *param_1,int param_2,ushort *param_3,int param_4)

{
  bool bVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iStack_54;
  undefined1 *puStack_50;
  undefined1 auStack_4c [42];
  undefined1 auStack_22 [2];
  
  if (param_2 == 0) {
    *param_3 = 0x2a;
    iVar3 = 0;
  }
  else {
    bVar1 = param_1 == (undefined1 *)0x0;
    if (bVar1) {
      puVar2 = auStack_22;
      param_1 = auStack_4c;
    }
    else {
      puVar2 = param_1 + *param_3;
    }
    param_4 = param_2 + param_4;
    iStack_54 = param_2;
    puStack_50 = param_1;
    iVar3 = (**(code **)(_r_ip_funcs_p + 0xa4))
                      (&iStack_54,&puStack_50,param_4,puVar2,1,*(code **)(_r_ip_funcs_p + 0xa4));
    if (iVar3 == 0) {
      puStack_50 = param_1 + 1;
      iVar4 = (**(code **)(_r_ip_funcs_p + 0xa4))
                        (&iStack_54,&puStack_50,param_4,puVar2,1,*(code **)(_r_ip_funcs_p + 0xa4));
      iVar3 = iVar4;
      if (iVar4 == 0) {
        if (0x3f < (byte)param_1[1]) {
          (**(code **)(_r_plf_funcs_p + 8))("hci_msg.c",0x9a0,*(code **)(_r_plf_funcs_p + 8));
        }
        if (bVar1) {
          puVar2 = (undefined1 *)0x0;
        }
        for (uVar5 = 0; iVar3 = iVar4, uVar5 < (byte)param_1[1]; uVar5 = uVar5 + 1 & 0xff) {
          puStack_50 = param_1 + uVar5 + 2;
          iVar3 = (**(code **)(_r_ip_funcs_p + 0xa4))
                            (&iStack_54,&puStack_50,param_4,puVar2,1,
                             *(code **)(_r_ip_funcs_p + 0xa4));
          if (iVar3 != 0) break;
          puStack_50 = param_1 + (uVar5 + 6) * 2;
          iVar3 = (**(code **)(_r_ip_funcs_p + 0xa4))
                            (&iStack_54,&puStack_50,param_4,puVar2,2,
                             *(code **)(_r_ip_funcs_p + 0xa4));
          if (iVar3 != 0) break;
          puStack_50 = param_1 + uVar5 + 0x20;
          iVar3 = (**(code **)(_r_ip_funcs_p + 0xa4))
                            (&iStack_54,&puStack_50,param_4,puVar2,1,
                             *(code **)(_r_ip_funcs_p + 0xa4));
          if (iVar3 != 0) break;
        }
      }
    }
    *param_3 = (short)puStack_50 - (short)param_1;
  }
  return iVar3;
}

