/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> hci_msg.o -> hci_le_set_ext_adv_en_cmd_upk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int hci_le_set_ext_adv_en_cmd_upk(undefined1 *param_1,int param_2,ushort *param_3,int param_4)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  ushort uVar4;
  uint uVar5;
  undefined1 *puVar6;
  uint uVar7;
  int iStack_54;
  undefined1 *puStack_50;
  undefined1 auStack_4c [42];
  undefined1 auStack_22 [6];
  
  if (param_2 == 0) {
    uVar4 = 0x2a;
    iVar2 = 0;
  }
  else {
    bVar1 = param_1 == (undefined1 *)0x0;
    if (bVar1) {
      puVar6 = auStack_22;
      param_1 = auStack_4c;
    }
    else {
      puVar6 = param_1 + *param_3;
    }
    param_4 = param_2 + param_4;
    iStack_54 = param_2;
    puStack_50 = param_1;
    iVar2 = r_hci_pack_bytes(&iStack_54,&puStack_50,param_4,puVar6,1);
    if (iVar2 == 0) {
      puStack_50 = param_1 + 1;
      iVar3 = r_hci_pack_bytes(&iStack_54,&puStack_50,param_4,puVar6,1);
      iVar2 = iVar3;
      if (iVar3 == 0) {
        if (0x3f < (byte)param_1[1]) {
          r_assert_err("hci_msg.c",0x9a0);
        }
        uVar7 = (uint)puVar6 & -(uint)!bVar1;
        for (uVar5 = 0; iVar2 = iVar3, uVar5 < (byte)param_1[1]; uVar5 = uVar5 + 1 & 0xff) {
          puStack_50 = param_1 + uVar5 + 2;
          iVar2 = r_hci_pack_bytes(&iStack_54,&puStack_50,param_4,uVar7,1);
          if (iVar2 != 0) break;
          puStack_50 = param_1 + (uVar5 + 6) * 2;
          iVar2 = r_hci_pack_bytes(&iStack_54,&puStack_50,param_4,uVar7,2);
          if (iVar2 != 0) break;
          puStack_50 = param_1 + uVar5 + 0x20;
          iVar2 = r_hci_pack_bytes(&iStack_54,&puStack_50,param_4,uVar7,1);
          if (iVar2 != 0) break;
        }
      }
    }
    uVar4 = (short)puStack_50 - (short)param_1;
  }
  *param_3 = uVar4;
  return iVar2;
}

