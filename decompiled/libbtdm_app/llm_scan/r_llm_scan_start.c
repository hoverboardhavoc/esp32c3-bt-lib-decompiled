/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app -> llm_scan.o -> r_llm_scan_start
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llm_scan_start(int param_1,undefined1 param_2)

{
  bool bVar1;
  int iVar2;
  undefined4 *puVar3;
  byte *pbVar4;
  uint uVar5;
  undefined4 uStack_28;
  undefined2 uStack_24;
  undefined1 uStack_22;
  byte bStack_21;
  ushort uStack_20;
  ushort uStack_1e;
  ushort uStack_1c;
  ushort uStack_1a;
  byte bStack_18;
  byte bStack_17;
  byte bStack_16;
  byte bStack_15;
  undefined1 uStack_14;
  undefined2 uStack_12;
  
  puVar3 = (undefined4 *)(*(int *)(_p_llm_env + 8) + param_1 * 0x44);
  pbVar4 = (byte *)*puVar3;
  bStack_21 = pbVar4[2];
  uStack_1c = 0;
  bVar1 = (bStack_21 & 1) != 0;
  if (bVar1) {
    bStack_18 = pbVar4[4];
    uStack_20 = *(ushort *)(pbVar4 + 6);
    uStack_1c = *(ushort *)(pbVar4 + 8);
  }
  uStack_1a = 0;
  if ((bStack_21 & 4) != 0) {
    bStack_17 = pbVar4[(uint)bVar1 * 6 + 4];
    uStack_1e = *(ushort *)(pbVar4 + (uint)bVar1 * 6 + 6);
    uStack_1a = *(ushort *)(pbVar4 + (uint)bVar1 * 6 + 8);
  }
  if (bStack_21 == 5) {
    uVar5 = (uint)uStack_1c + (uint)uStack_1a;
    if (uStack_20 < uVar5) {
      uStack_20 = (ushort)uVar5;
    }
    if (uStack_1e < uVar5) {
      uStack_1e = (ushort)uVar5;
    }
  }
  bStack_16 = *pbVar4;
  bStack_15 = pbVar4[1];
  uStack_12 = *(undefined2 *)(puVar3 + 10);
  uStack_14 = *(undefined1 *)(_p_llm_env + 0xc6);
  uStack_22 = param_2;
  if (bStack_16 == 2) {
_L673:
    uStack_28 = *(undefined4 *)(_p_llm_env + 0xc);
    uStack_24 = *(undefined2 *)(_p_llm_env + 0x10);
  }
  else {
    if (bStack_16 < 3) {
      if (bStack_16 == 0) goto _L673;
    }
    else if (bStack_16 != 3) {
      (**(code **)(_r_plf_funcs_p + 0xc))(0,"llm_scan.c",0x945,*(code **)(_r_plf_funcs_p + 0xc));
      goto _L677;
    }
    memcpy(&uStack_28,(void *)(_p_llm_env + 0x12),6);
  }
_L677:
  iVar2 = (**(code **)(_r_ip_funcs_p + 0x438))(param_1,&uStack_28,*(code **)(_r_ip_funcs_p + 0x438))
  ;
  if (iVar2 != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"llm_scan.c",0x94d,*(code **)(_r_plf_funcs_p + 8));
  }
  return;
}

