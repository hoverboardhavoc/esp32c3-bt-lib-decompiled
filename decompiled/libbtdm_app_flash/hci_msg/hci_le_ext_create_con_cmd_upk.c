/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> hci_msg.o -> hci_le_ext_create_con_cmd_upk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int hci_le_ext_create_con_cmd_upk(undefined1 *param_1,int param_2,ushort *param_3,int param_4)

{
  bool bVar1;
  undefined1 *puVar2;
  int iVar3;
  uint uVar4;
  undefined1 *puVar5;
  uint uVar6;
  int iVar7;
  int iStack_64;
  undefined1 *puStack_60;
  undefined1 auStack_5c [58];
  undefined1 auStack_22 [2];
  
  if (param_2 == 0) {
    *param_3 = 0x3a;
    iVar3 = 0;
  }
  else {
    bVar1 = param_1 == (undefined1 *)0x0;
    if (bVar1) {
      puVar2 = auStack_22;
      param_1 = auStack_5c;
    }
    else {
      puVar2 = param_1 + *param_3;
    }
    param_4 = param_2 + param_4;
    iStack_64 = param_2;
    puStack_60 = param_1;
    iVar3 = r_hci_pack_bytes(&iStack_64,&puStack_60,param_4,puVar2,1);
    if (iVar3 == 0) {
      puStack_60 = param_1 + 1;
      iVar3 = r_hci_pack_bytes(&iStack_64,&puStack_60,param_4,puVar2,1);
      if (iVar3 == 0) {
        puStack_60 = param_1 + 2;
        iVar3 = r_hci_pack_bytes(&iStack_64,&puStack_60,param_4,puVar2,1);
        if (iVar3 == 0) {
          puStack_60 = param_1 + 3;
          iVar3 = r_hci_pack_bytes(&iStack_64,&puStack_60,param_4,puVar2,6);
          if (iVar3 == 0) {
            puStack_60 = param_1 + 9;
            iVar3 = r_hci_pack_bytes(&iStack_64,&puStack_60,param_4,puVar2,1);
            if (iVar3 == 0) {
              uVar6 = 0;
              for (uVar4 = (uint)(byte)param_1[9]; uVar4 != 0; uVar4 = uVar4 >> 1) {
                if ((uVar4 & 1) != 0) {
                  uVar6 = uVar6 + 1 & 0xff;
                }
              }
              if (3 < uVar6) {
                r_assert_err(0,"hci_msg.c",0x7b7);
              }
              if (bVar1) {
                puVar2 = (undefined1 *)0x0;
              }
              puVar5 = param_1 + 0x18;
              for (iVar7 = 0; iVar7 < (int)uVar6; iVar7 = iVar7 + 1) {
                puStack_60 = puVar5 + -0xe;
                iVar3 = r_hci_pack_bytes(&iStack_64,&puStack_60,param_4,puVar2,2);
                if (iVar3 != 0) goto _L33;
                puStack_60 = puVar5 + -0xc;
                iVar3 = r_hci_pack_bytes(&iStack_64,&puStack_60,param_4,puVar2,2);
                if (iVar3 != 0) goto _L33;
                puStack_60 = puVar5 + -10;
                iVar3 = r_hci_pack_bytes(&iStack_64,&puStack_60,param_4,puVar2,2);
                if (iVar3 != 0) goto _L33;
                puStack_60 = puVar5 + -8;
                iVar3 = r_hci_pack_bytes(&iStack_64,&puStack_60,param_4,puVar2,2);
                if (iVar3 != 0) goto _L33;
                puStack_60 = puVar5 + -6;
                iVar3 = r_hci_pack_bytes(&iStack_64,&puStack_60,param_4,puVar2,2);
                if (iVar3 != 0) goto _L33;
                puStack_60 = puVar5 + -4;
                iVar3 = r_hci_pack_bytes(&iStack_64,&puStack_60,param_4,puVar2,2);
                if (iVar3 != 0) goto _L33;
                puStack_60 = puVar5 + -2;
                iVar3 = r_hci_pack_bytes(&iStack_64,&puStack_60,param_4,puVar2,2);
                if (iVar3 != 0) goto _L33;
                puStack_60 = puVar5;
                iVar3 = r_hci_pack_bytes(&iStack_64,&puStack_60,param_4,puVar2,2);
                puVar5 = puVar5 + 0x10;
                if (iVar3 != 0) goto _L33;
              }
              iVar3 = 0;
            }
          }
        }
      }
    }
_L33:
    *param_3 = (short)puStack_60 - (short)param_1;
  }
  return iVar3;
}

