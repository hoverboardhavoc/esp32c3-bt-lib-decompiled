/*
 * Last changed at upstream commit 022b7da7fcf0043f891c2e8ccd8c241243018e2f
 * https://github.com/espressif/esp32c3-bt-lib/commit/022b7da7fcf0043f891c2e8ccd8c241243018e2f
 * Upstream date: 2021-04-20 16:00:04 +0800
 * Upstream subject: ESP32-C3, ESP32-S3: update libbtdm_app.a(d1d0c6f1)
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
    if (uVar2 == 0) goto _L57;
_L46:
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
_L57:
      if (uVar5 < uVar3) goto _L46;
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

