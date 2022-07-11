/*
 * Last changed at upstream commit d1c2082e5633a89c6fd6051c7761c1e697cb7a2e
 * https://github.com/espressif/esp32c3-bt-lib/commit/d1c2082e5633a89c6fd6051c7761c1e697cb7a2e
 * Upstream date: 2022-07-11 09:57:43 +0800
 * Upstream subject: fix adv report duplicate check
 * Source: libbtdm_app -> llm.o -> llm_adv_is_in_duplicate_scan_duplicate_exceptional_list
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool llm_adv_is_in_duplicate_scan_duplicate_exceptional_list(void *param_1,int param_2)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  bool bVar4;
  int *piVar5;
  
  uVar2 = DAT_000107f4;
  if (param_1 == (void *)0x0) {
    return false;
  }
  bVar4 = false;
  if (DAT_000107f4 != 0) {
    piVar5 = DAT_000107f8;
    if ((DAT_000107f4 & 1) != 0) {
      for (; piVar5 != (int *)0x0; piVar5 = (int *)*piVar5) {
        iVar3 = memcmp(piVar5 + 1,param_1,6);
        if (iVar3 == 0) {
          return true;
        }
      }
    }
    cVar1 = *(char *)((int)param_1 + 7);
    if ((cVar1 == ')') && ((uVar2 & 2) != 0)) {
      for (piVar5 = (int *)DAT_00010800; piVar5 != (int *)0x0; piVar5 = (int *)*piVar5) {
        iVar3 = memcmp(piVar5 + 1,(void *)((int)param_1 + 8),4);
        if (iVar3 == 0) {
          return true;
        }
      }
    }
    if ((((*(char *)((int)param_1 + param_2 + -2) != '\x03') || ((uVar2 & 4) == 0)) ||
        (bVar4 = true, cVar1 != '+')) &&
       ((((uVar2 & 8) == 0 || (bVar4 = true, *(int *)((int)param_1 + 9) != 0x18270303)) &&
        (bVar4 = false, (uVar2 & 0x10) != 0)))) {
      bVar4 = *(int *)((int)param_1 + 9) == 0x18280303;
    }
  }
  return bVar4;
}

