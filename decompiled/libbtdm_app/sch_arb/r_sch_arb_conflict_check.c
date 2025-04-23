/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> sch_arb.o -> r_sch_arb_conflict_check
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

char r_sch_arb_conflict_check(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  uVar3 = *(int *)(param_2 + 4) - *(int *)(param_1 + 4) & 0xfffffff;
  uVar5 = *(uint *)(param_1 + 8);
  uVar6 = *(uint *)(param_2 + 8);
  if (uVar3 < 0x8000001) {
    if (uVar3 == 0) goto _L25;
_L27:
    cVar1 = '\0';
    iVar2 = (uVar5 + *(int *)(param_1 + 0x10)) - uVar6;
    if ((0 < iVar2) && ((int)((iVar2 + -1) / -0x271 + uVar3) < 1)) {
      cVar1 = '\x01';
      iVar2 = iVar2 - *(int *)(param_2 + 0x10);
      if (0 < iVar2) {
        return ((int)((iVar2 + -1) / -0x271 + uVar3) < 1) + '\x01';
      }
    }
  }
  else {
    uVar3 = *(int *)(param_1 + 4) - *(int *)(param_2 + 4) & 0xfffffff;
    iVar2 = -uVar3;
    if (uVar3 == 0) {
_L25:
      if (uVar5 < uVar6) {
        uVar3 = 0;
        goto _L27;
      }
      iVar2 = 0;
    }
    cVar1 = '\x05';
    iVar4 = (uVar6 + *(int *)(param_2 + 0x10)) - uVar5;
    if ((0 < iVar4) && (-1 < (iVar4 + -1) / 0x271 + iVar2)) {
      cVar1 = '\x04';
      iVar4 = ((uVar5 + *(int *)(param_1 + 0x10)) - uVar6) - *(int *)(param_2 + 0x10);
      if (iVar4 < 1) {
        cVar1 = (iVar4 / -0x271 + iVar2 < 0) + '\x03';
      }
    }
  }
  return cVar1;
}

