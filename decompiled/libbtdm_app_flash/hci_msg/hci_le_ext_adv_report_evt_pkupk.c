/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> hci_msg.o -> hci_le_ext_adv_report_evt_pkupk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int hci_le_ext_adv_report_evt_pkupk
              (undefined1 *param_1,undefined1 *param_2,ushort *param_3,int param_4)

{
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  ushort uVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  int iVar7;
  undefined1 *puStack_128;
  undefined1 *puStack_124;
  undefined1 auStack_120 [256];
  
  if (param_2 == (undefined1 *)0x0) {
    uVar4 = 0;
    iVar2 = 0;
  }
  else {
    if (param_1 == (undefined1 *)0x0) {
      puVar5 = &stack0xffffffe0;
      param_1 = auStack_120;
    }
    else {
      puVar5 = param_1 + *param_3;
    }
    puVar1 = param_2 + param_4;
    puStack_128 = param_2;
    puStack_124 = param_1;
    iVar2 = r_hci_pack_bytes(&puStack_128,&puStack_124,puVar1,puVar5,1);
    if (iVar2 == 0) {
      puStack_128 = param_2 + 1;
      iVar3 = r_hci_pack_bytes(&puStack_128,&puStack_124,puVar1,puVar5,1);
      iVar2 = iVar3;
      if (iVar3 == 0) {
        puVar6 = param_2 + 0x19;
        for (iVar7 = 0; iVar2 = iVar3, iVar7 < (int)(uint)(byte)param_2[1]; iVar7 = iVar7 + 1) {
          puStack_128 = puVar6 + -0x17;
          iVar2 = r_hci_pack_bytes(&puStack_128,&puStack_124,puVar1,puVar5,2);
          if (iVar2 != 0) break;
          puStack_128 = puVar6 + -0x15;
          iVar2 = r_hci_pack_bytes(&puStack_128,&puStack_124,puVar1,puVar5,1);
          if (iVar2 != 0) break;
          puStack_128 = puVar6 + -0x14;
          iVar2 = r_hci_pack_bytes(&puStack_128,&puStack_124,puVar1,puVar5,6);
          if (iVar2 != 0) break;
          puStack_128 = puVar6 + -0xe;
          iVar2 = r_hci_pack_bytes(&puStack_128,&puStack_124,puVar1,puVar5,1);
          if (iVar2 != 0) break;
          puStack_128 = puVar6 + -0xd;
          iVar2 = r_hci_pack_bytes(&puStack_128,&puStack_124,puVar1,puVar5,1);
          if (iVar2 != 0) break;
          puStack_128 = puVar6 + -0xc;
          iVar2 = r_hci_pack_bytes(&puStack_128,&puStack_124,puVar1,puVar5,1);
          if (iVar2 != 0) break;
          puStack_128 = puVar6 + -0xb;
          iVar2 = r_hci_pack_bytes(&puStack_128,&puStack_124,puVar1,puVar5,1);
          if (iVar2 != 0) break;
          puStack_128 = puVar6 + -10;
          iVar2 = r_hci_pack_bytes(&puStack_128,&puStack_124,puVar1,puVar5,1);
          if (iVar2 != 0) break;
          puStack_128 = puVar6 + -9;
          iVar2 = r_hci_pack_bytes(&puStack_128,&puStack_124,puVar1,puVar5,2);
          if (iVar2 != 0) break;
          puStack_128 = puVar6 + -7;
          iVar2 = r_hci_pack_bytes(&puStack_128,&puStack_124,puVar1,puVar5,1);
          if (iVar2 != 0) break;
          puStack_128 = puVar6 + -6;
          iVar2 = r_hci_pack_bytes(&puStack_128,&puStack_124,puVar1,puVar5,6);
          if ((iVar2 != 0) ||
             (puStack_128 = puVar6,
             iVar2 = r_hci_pack_bytes(&puStack_128,&puStack_124,puVar1,puVar5,1), iVar2 != 0))
          break;
          puStack_128 = puVar6 + 1;
          iVar2 = r_hci_pack_bytes(&puStack_128,&puStack_124,puVar1,puVar5,*puVar6);
          puVar6 = puVar6 + 0xfe;
          if (iVar2 != 0) break;
        }
      }
    }
    uVar4 = (short)puStack_124 - (short)param_1;
  }
  *param_3 = uVar4;
  return iVar2;
}

