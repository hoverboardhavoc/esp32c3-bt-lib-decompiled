/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> hci_msg.o -> hci_le_set_ext_scan_param_cmd_upk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int hci_le_set_ext_scan_param_cmd_upk(undefined1 *param_1,int param_2,ushort *param_3,int param_4)

{
  bool bVar1;
  undefined1 *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined1 *puVar6;
  int iVar7;
  int iStack_38;
  undefined1 *puStack_34;
  undefined1 auStack_30 [16];
  
  if (param_2 == 0) {
    *param_3 = 0x10;
    iVar3 = 0;
  }
  else {
    bVar1 = param_1 == (undefined1 *)0x0;
    if (bVar1) {
      puVar2 = &stack0xffffffe0;
      param_1 = auStack_30;
    }
    else {
      puVar2 = param_1 + *param_3;
    }
    param_4 = param_2 + param_4;
    iStack_38 = param_2;
    puStack_34 = param_1;
    iVar3 = r_hci_pack_bytes(&iStack_38,&puStack_34,param_4,puVar2,1);
    if (iVar3 == 0) {
      puStack_34 = param_1 + 1;
      iVar3 = r_hci_pack_bytes(&iStack_38,&puStack_34,param_4,puVar2,1);
      if (iVar3 == 0) {
        puStack_34 = param_1 + 2;
        iVar3 = r_hci_pack_bytes(&iStack_38,&puStack_34,param_4,puVar2,1);
        if (iVar3 == 0) {
          uVar5 = 0;
          for (uVar4 = (uint)(byte)param_1[2]; uVar4 != 0; uVar4 = uVar4 >> 1) {
            if ((uVar4 & 1) != 0) {
              uVar5 = uVar5 + 1 & 0xff;
            }
          }
          if (2 < uVar5) {
            r_assert_err(0,"hci_msg.c",0x719);
          }
          if (bVar1) {
            puVar2 = (undefined1 *)0x0;
          }
          puVar6 = param_1 + 8;
          for (iVar7 = 0; iVar7 < (int)uVar5; iVar7 = iVar7 + 1) {
            puStack_34 = puVar6 + -4;
            iVar3 = r_hci_pack_bytes(&iStack_38,&puStack_34,param_4,puVar2,1);
            if (iVar3 != 0) goto _L50;
            puStack_34 = puVar6 + -2;
            iVar3 = r_hci_pack_bytes(&iStack_38,&puStack_34,param_4,puVar2,2);
            if (iVar3 != 0) goto _L50;
            puStack_34 = puVar6;
            iVar3 = r_hci_pack_bytes(&iStack_38,&puStack_34,param_4,puVar2,2);
            puVar6 = puVar6 + 6;
            if (iVar3 != 0) goto _L50;
          }
          iVar3 = 0;
        }
      }
    }
_L50:
    *param_3 = (short)puStack_34 - (short)param_1;
  }
  return iVar3;
}

