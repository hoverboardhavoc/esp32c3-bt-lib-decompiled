/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> sch_arb.o -> r_sch_arb_conflict_check
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

char r_sch_arb_conflict_check(int param_1,int param_2)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  uVar2 = *(int *)(param_2 + 4) - *(int *)(param_1 + 4) & 0xfffffff;
  uVar5 = *(uint *)(param_1 + 8);
  uVar3 = *(uint *)(param_2 + 8);
  if (uVar2 < 0x8000001) {
    if (uVar2 == 0) goto _L35;
_L24:
    iVar4 = (uVar5 + *(int *)(param_1 + 0x10)) - uVar3;
    cVar1 = '\0';
    if ((0 < iVar4) && (cVar1 = '\0', (int)((iVar4 + -1) / -0x271 + uVar2) < 1)) {
      cVar1 = '\x01';
      iVar4 = iVar4 - *(int *)(param_2 + 0x10);
      if (0 < iVar4) {
        return ((int)((iVar4 + -1) / -0x271 + uVar2) < 1) + '\x01';
      }
    }
  }
  else {
    uVar2 = -(*(int *)(param_1 + 4) - *(int *)(param_2 + 4) & 0xfffffffU);
    if (uVar2 == 0) {
_L35:
      if (uVar5 < uVar3) goto _L24;
    }
    iVar4 = (uVar3 + *(int *)(param_2 + 0x10)) - uVar5;
    cVar1 = '\x05';
    if ((0 < iVar4) && (-1 < (int)((iVar4 + -1) / 0x271 + uVar2))) {
      iVar4 = ((uVar5 + *(int *)(param_1 + 0x10)) - uVar3) - *(int *)(param_2 + 0x10);
      cVar1 = '\x04';
      if (iVar4 < 1) {
        cVar1 = ((int)(iVar4 / -0x271 + uVar2) < 0) + '\x03';
      }
    }
  }
  return cVar1;
}

