/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> sch_arb.o -> r_sch_arb_conflict_check
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

char r_sch_arb_conflict_check(int param_1,int param_2)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar4 = *(int *)(param_2 + 4) - *(int *)(param_1 + 4) & 0xfffffff;
  uVar5 = *(uint *)(param_1 + 8);
  uVar6 = *(uint *)(param_2 + 8);
  if (uVar4 < 0x8000001) {
    if (uVar4 == 0) goto _L15;
_L4:
    iVar3 = (uVar5 + *(int *)(param_1 + 0x10)) - uVar6;
    cVar1 = '\0';
    if ((0 < iVar3) && (cVar1 = '\0', (int)((iVar3 + -1) / -0x271 + uVar4) < 1)) {
      cVar1 = '\x01';
      iVar3 = iVar3 - *(int *)(param_2 + 0x10);
      if (0 < iVar3) {
        return ((int)((iVar3 + -1) / -0x271 + uVar4) < 1) + '\x01';
      }
    }
  }
  else {
    uVar2 = *(int *)(param_1 + 4) - *(int *)(param_2 + 4) & 0xfffffff;
    uVar4 = -uVar2;
    if (uVar2 == 0) {
_L15:
      if (uVar5 < uVar6) goto _L4;
    }
    iVar3 = (uVar6 + *(int *)(param_2 + 0x10)) - uVar5;
    cVar1 = '\x05';
    if ((0 < iVar3) && (-1 < (int)((iVar3 + -1) / 0x271 + uVar4))) {
      iVar3 = ((uVar5 + *(int *)(param_1 + 0x10)) - uVar6) - *(int *)(param_2 + 0x10);
      cVar1 = '\x04';
      if (iVar3 < 1) {
        cVar1 = ((int)(iVar3 / -0x271 + uVar4) < 0) + '\x03';
      }
    }
  }
  return cVar1;
}

