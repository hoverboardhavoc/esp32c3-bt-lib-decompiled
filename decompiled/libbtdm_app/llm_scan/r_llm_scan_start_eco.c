/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llm_scan.o -> r_llm_scan_start_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llm_scan_start_eco(int param_1,undefined4 param_2)

{
  bool bVar1;
  int iVar2;
  char *pcVar3;
  undefined4 *puVar4;
  byte *pbVar5;
  uint uVar6;
  uint uVar7;
  undefined4 uStack_28;
  undefined2 uStack_24;
  undefined1 uStack_22;
  byte bStack_21;
  ushort uStack_20;
  ushort uStack_1e;
  undefined4 uStack_1c;
  byte bStack_18;
  byte bStack_17;
  byte bStack_16;
  byte bStack_15;
  undefined4 uStack_14;
  
  uStack_14 = param_2;
  pcVar3 = (char *)(**(code **)(_r_ip_funcs_p + 0x914))(*(code **)(_r_ip_funcs_p + 0x914));
  if (*pcVar3 != '\0') {
    pcVar3[8] = '\0';
    pcVar3[9] = '\0';
    pcVar3[10] = '\0';
    pcVar3[0xb] = '\0';
  }
  puVar4 = (undefined4 *)(*(int *)(_p_llm_env + 8) + param_1 * 0x44);
  pbVar5 = (byte *)*puVar4;
  bStack_21 = pbVar5[2];
  uStack_1c = 0;
  bVar1 = (bStack_21 & 1) != 0;
  if (bVar1) {
    bStack_18 = pbVar5[4];
    uStack_20 = *(ushort *)(pbVar5 + 6);
    uStack_1c = (uint)*(ushort *)(pbVar5 + 8);
  }
  uVar7 = uStack_1c;
  if ((bStack_21 & 4) != 0) {
    uVar6 = -(uint)bVar1 & 6;
    bStack_17 = pbVar5[uVar6 + 4];
    uStack_1e = *(ushort *)(pbVar5 + uVar6 + 6);
    uStack_1c = CONCAT22(*(ushort *)(pbVar5 + uVar6 + 8),(undefined2)uStack_1c);
    if (bStack_21 == 5) {
      uVar7 = uVar7 + *(ushort *)(pbVar5 + uVar6 + 8);
      if (uStack_20 < uVar7) {
        uStack_20 = (ushort)uVar7;
      }
      if (uStack_1e < uVar7) {
        uStack_1e = (ushort)uVar7;
      }
    }
  }
  bStack_16 = *pbVar5;
  bStack_15 = pbVar5[1];
  uStack_22 = (undefined1)uStack_14;
  uStack_14 = CONCAT22(*(undefined2 *)(puVar4 + 10),(undefined2)uStack_14);
  uStack_14 = CONCAT31(uStack_14._1_3_,*(undefined1 *)(_p_llm_env + 0xc6));
  if (bStack_16 == 2) {
_L674:
    uStack_28 = *(undefined4 *)(_p_llm_env + 0xc);
    uStack_24 = *(undefined2 *)(_p_llm_env + 0x10);
  }
  else {
    if (bStack_16 < 3) {
      if (bStack_16 == 0) goto _L674;
    }
    else if (bStack_16 != 3) {
      (**(code **)(_r_plf_funcs_p + 0xc))(0,"llm_scan.c",0x8e5,*(code **)(_r_plf_funcs_p + 0xc));
      goto _L678;
    }
    memcpy(&uStack_28,(void *)(_p_llm_env + 0x12),6);
  }
_L678:
  iVar2 = (**(code **)(_r_ip_funcs_p + 0x438))(param_1,&uStack_28,*(code **)(_r_ip_funcs_p + 0x438))
  ;
  if (iVar2 != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"llm_scan.c",0x8ed,*(code **)(_r_plf_funcs_p + 8));
  }
  return;
}

