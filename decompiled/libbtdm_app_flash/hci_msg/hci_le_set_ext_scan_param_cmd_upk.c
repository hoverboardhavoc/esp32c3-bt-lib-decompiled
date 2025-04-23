/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> hci_msg.o -> hci_le_set_ext_scan_param_cmd_upk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int hci_le_set_ext_scan_param_cmd_upk(undefined1 *param_1,int param_2,ushort *param_3,int param_4)

{
  bool bVar1;
  int iVar2;
  ushort uVar3;
  undefined1 *puVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iStack_38;
  undefined1 *puStack_34;
  undefined1 auStack_30 [16];
  
  if (param_2 == 0) {
    uVar3 = 0x10;
    iVar2 = 0;
  }
  else {
    bVar1 = param_1 == (undefined1 *)0x0;
    if (bVar1) {
      puVar4 = &stack0xffffffe0;
      param_1 = auStack_30;
    }
    else {
      puVar4 = param_1 + *param_3;
    }
    param_4 = param_2 + param_4;
    iStack_38 = param_2;
    puStack_34 = param_1;
    iVar2 = r_hci_pack_bytes(&iStack_38,&puStack_34,param_4,puVar4,1);
    if (iVar2 == 0) {
      puStack_34 = param_1 + 1;
      iVar2 = r_hci_pack_bytes(&iStack_38,&puStack_34,param_4,puVar4,1);
      if (iVar2 == 0) {
        puStack_34 = param_1 + 2;
        iVar2 = r_hci_pack_bytes(&iStack_38,&puStack_34,param_4,puVar4,1);
        if (iVar2 == 0) {
          uVar6 = 0;
          for (uVar5 = (uint)(byte)param_1[2]; uVar5 != 0; uVar5 = uVar5 >> 1) {
            uVar6 = (uVar5 & 1) + uVar6 & 0xff;
          }
          if (2 < uVar6) {
            r_assert_err(0,"hci_msg.c",0x719);
          }
          uVar5 = (uint)puVar4 & -(uint)!bVar1;
          puVar4 = param_1 + 8;
          for (iVar7 = 0; iVar7 < (int)uVar6; iVar7 = iVar7 + 1) {
            puStack_34 = puVar4 + -4;
            iVar2 = r_hci_pack_bytes(&iStack_38,&puStack_34,param_4,uVar5,1);
            if (iVar2 != 0) goto _L46;
            puStack_34 = puVar4 + -2;
            iVar2 = r_hci_pack_bytes(&iStack_38,&puStack_34,param_4,uVar5,2);
            if (iVar2 != 0) goto _L46;
            puStack_34 = puVar4;
            iVar2 = r_hci_pack_bytes(&iStack_38,&puStack_34,param_4,uVar5,2);
            puVar4 = puVar4 + 6;
            if (iVar2 != 0) goto _L46;
          }
          iVar2 = 0;
        }
      }
    }
_L46:
    uVar3 = (short)puStack_34 - (short)param_1;
  }
  *param_3 = uVar3;
  return iVar2;
}

