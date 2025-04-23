/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> hci_msg.o -> hci_host_nb_cmp_pkts_cmd_pkupk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int hci_host_nb_cmp_pkts_cmd_pkupk(int param_1,byte *param_2,ushort *param_3,int param_4)

{
  int iVar1;
  int iVar2;
  ushort uVar3;
  uint uVar4;
  byte *pbVar5;
  int iVar6;
  int iVar7;
  byte *pbStack_38;
  int aiStack_34 [2];
  
  if (param_2 == (byte *)0x0) {
    uVar3 = 0x2e;
    iVar2 = 0;
  }
  else {
    pbVar5 = param_2 + param_4;
    iVar7 = (uint)*param_3 + param_1;
    pbStack_38 = param_2;
    aiStack_34[0] = param_1;
    iVar1 = (**(code **)(_r_ip_funcs_p + 0xa4))
                      (&pbStack_38,aiStack_34,pbVar5,iVar7,1,*(code **)(_r_ip_funcs_p + 0xa4));
    iVar2 = iVar1;
    if (iVar1 == 0) {
      uVar4 = 0;
      while ((iVar2 = iVar1, uVar4 < *param_2 && ((uint)(aiStack_34[0] - param_1) < 0x2f))) {
        iVar6 = (uVar4 + 1) * 2;
        aiStack_34[0] = param_1 + iVar6;
        iVar2 = (**(code **)(_r_ip_funcs_p + 0xa4))
                          (&pbStack_38,aiStack_34,pbVar5,iVar7,2,*(code **)(_r_ip_funcs_p + 0xa4));
        if (iVar2 != 0) break;
        aiStack_34[0] = iVar6 + 0x16 + param_1;
        iVar2 = (**(code **)(_r_ip_funcs_p + 0xa4))
                          (&pbStack_38,aiStack_34,pbVar5,iVar7,2,*(code **)(_r_ip_funcs_p + 0xa4));
        if (iVar2 != 0) break;
        uVar4 = uVar4 + 1 & 0xff;
      }
    }
    uVar3 = (short)aiStack_34[0] - (short)param_1;
  }
  *param_3 = uVar3;
  return iVar2;
}

