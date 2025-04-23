/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  ushort uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iStack_64;
  undefined1 *puStack_60;
  undefined1 auStack_5c [58];
  undefined1 auStack_22 [2];
  
  if (param_2 == 0) {
    uVar4 = 0x3a;
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
              for (uVar5 = (uint)(byte)param_1[9]; uVar5 != 0; uVar5 = uVar5 >> 1) {
                uVar6 = (uVar5 & 1) + uVar6 & 0xff;
              }
              if (3 < uVar6) {
                r_assert_err(0,"hci_msg.c",0x7b7);
              }
              uVar5 = (uint)puVar2 & -(uint)!bVar1;
              puVar2 = param_1 + 0x18;
              for (iVar7 = 0; iVar7 < (int)uVar6; iVar7 = iVar7 + 1) {
                puStack_60 = puVar2 + -0xe;
                iVar3 = r_hci_pack_bytes(&iStack_64,&puStack_60,param_4,uVar5,2);
                if (iVar3 != 0) goto _L32;
                puStack_60 = puVar2 + -0xc;
                iVar3 = r_hci_pack_bytes(&iStack_64,&puStack_60,param_4,uVar5,2);
                if (iVar3 != 0) goto _L32;
                puStack_60 = puVar2 + -10;
                iVar3 = r_hci_pack_bytes(&iStack_64,&puStack_60,param_4,uVar5,2);
                if (iVar3 != 0) goto _L32;
                puStack_60 = puVar2 + -8;
                iVar3 = r_hci_pack_bytes(&iStack_64,&puStack_60,param_4,uVar5,2);
                if (iVar3 != 0) goto _L32;
                puStack_60 = puVar2 + -6;
                iVar3 = r_hci_pack_bytes(&iStack_64,&puStack_60,param_4,uVar5,2);
                if (iVar3 != 0) goto _L32;
                puStack_60 = puVar2 + -4;
                iVar3 = r_hci_pack_bytes(&iStack_64,&puStack_60,param_4,uVar5,2);
                if (iVar3 != 0) goto _L32;
                puStack_60 = puVar2 + -2;
                iVar3 = r_hci_pack_bytes(&iStack_64,&puStack_60,param_4,uVar5,2);
                if (iVar3 != 0) goto _L32;
                puStack_60 = puVar2;
                iVar3 = r_hci_pack_bytes(&iStack_64,&puStack_60,param_4,uVar5,2);
                puVar2 = puVar2 + 0x10;
                if (iVar3 != 0) goto _L32;
              }
              iVar3 = 0;
            }
          }
        }
      }
    }
_L32:
    uVar4 = (short)puStack_60 - (short)param_1;
  }
  *param_3 = uVar4;
  return iVar3;
}

