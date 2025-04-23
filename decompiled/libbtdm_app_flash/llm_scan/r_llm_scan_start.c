/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llm_scan.o -> r_llm_scan_start
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
  uint uVar6;
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
    uStack_1c = (uint)*(ushort *)(pbVar4 + 8);
  }
  uVar6 = uStack_1c;
  if ((bStack_21 & 4) != 0) {
    uVar5 = -(uint)bVar1 & 6;
    bStack_17 = pbVar4[uVar5 + 4];
    uStack_1e = *(ushort *)(pbVar4 + uVar5 + 6);
    uStack_1c = CONCAT22(*(ushort *)(pbVar4 + uVar5 + 8),(undefined2)uStack_1c);
    if (bStack_21 == 5) {
      uVar6 = uVar6 + *(ushort *)(pbVar4 + uVar5 + 8);
      if (uStack_20 < uVar6) {
        uStack_20 = (ushort)uVar6;
      }
      if (uStack_1e < uVar6) {
        uStack_1e = (ushort)uVar6;
      }
    }
  }
  bStack_16 = *pbVar4;
  bStack_15 = pbVar4[1];
  uStack_12 = *(undefined2 *)(puVar3 + 10);
  uStack_14 = *(undefined1 *)(_p_llm_env + 0xc6);
  uStack_22 = param_2;
  if (bStack_16 == 2) {
_L365:
    uStack_28 = *(undefined4 *)(_p_llm_env + 0xc);
    uStack_24 = *(undefined2 *)(_p_llm_env + 0x10);
  }
  else {
    if (bStack_16 < 3) {
      if (bStack_16 == 0) goto _L365;
    }
    else if (bStack_16 != 3) {
      r_assert_param(0,"llm_scan.c",0x8e5);
      goto _L369;
    }
    memcpy(&uStack_28,(void *)(_p_llm_env + 0x12),6);
  }
_L369:
  iVar2 = r_lld_scan_start_eco(param_1,&uStack_28);
  if (iVar2 != 0) {
    r_assert_err(0,"llm_scan.c",0x8ed);
  }
  return;
}

