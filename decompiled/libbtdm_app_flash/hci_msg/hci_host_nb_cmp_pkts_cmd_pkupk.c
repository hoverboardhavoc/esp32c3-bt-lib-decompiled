/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> hci_msg.o -> hci_host_nb_cmp_pkts_cmd_pkupk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int hci_host_nb_cmp_pkts_cmd_pkupk(int param_1,byte *param_2,ushort *param_3,int param_4)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  byte *pbStack_38;
  int aiStack_34 [3];
  
  if (param_2 == (byte *)0x0) {
    *param_3 = 0x2e;
    iVar3 = 0;
  }
  else {
    pbVar1 = param_2 + param_4;
    iVar6 = (uint)*param_3 + param_1;
    pbStack_38 = param_2;
    aiStack_34[0] = param_1;
    iVar2 = r_hci_pack_bytes(&pbStack_38,aiStack_34,pbVar1,iVar6,1);
    iVar3 = iVar2;
    if (iVar2 == 0) {
      uVar4 = 0;
      while ((iVar3 = iVar2, uVar4 < *param_2 && ((uint)(aiStack_34[0] - param_1) < 0x2f))) {
        iVar5 = (uVar4 + 1) * 2;
        aiStack_34[0] = param_1 + iVar5;
        iVar3 = r_hci_pack_bytes(&pbStack_38,aiStack_34,pbVar1,iVar6,2);
        if (iVar3 != 0) break;
        aiStack_34[0] = iVar5 + 0x16 + param_1;
        iVar3 = r_hci_pack_bytes(&pbStack_38,aiStack_34,pbVar1,iVar6,2);
        if (iVar3 != 0) break;
        uVar4 = uVar4 + 1 & 0xff;
      }
    }
    *param_3 = (short)aiStack_34[0] - (short)param_1;
  }
  return iVar3;
}

