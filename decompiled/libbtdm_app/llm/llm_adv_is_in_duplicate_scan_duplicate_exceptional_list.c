/*
 * Last changed at upstream commit 5c6ab5248a124cffc731a9e4764473fdeef38054
 * https://github.com/espressif/esp32c3-bt-lib/commit/5c6ab5248a124cffc731a9e4764473fdeef38054
 * Upstream date: 2023-03-09 14:58:19 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(85a1090)
 * Source: libbtdm_app -> llm.o -> llm_adv_is_in_duplicate_scan_duplicate_exceptional_list
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool llm_adv_is_in_duplicate_scan_duplicate_exceptional_list(void *param_1,int param_2)

{
  char cVar1;
  uint uVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  
  iVar4 = (**(code **)(_r_ip_funcs_p + 0x924))(*(code **)(_r_ip_funcs_p + 0x924));
  if (param_1 == (void *)0x0) {
    bVar3 = false;
  }
  else {
    uVar2 = *(uint *)(iVar4 + 0x28);
    bVar3 = false;
    if (uVar2 != 0) {
      if ((uVar2 & 1) != 0) {
        for (piVar6 = *(int **)(iVar4 + 0x2c); piVar6 != (int *)0x0; piVar6 = (int *)*piVar6) {
          iVar5 = memcmp(piVar6 + 1,param_1,6);
          if (iVar5 == 0) {
            return true;
          }
        }
      }
      cVar1 = *(char *)((int)param_1 + 7);
      if ((cVar1 == ')') && ((uVar2 & 2) != 0)) {
        for (piVar6 = *(int **)(iVar4 + 0x34); piVar6 != (int *)0x0; piVar6 = (int *)*piVar6) {
          iVar4 = memcmp(piVar6 + 1,(void *)((int)param_1 + 8),4);
          if (iVar4 == 0) {
            return true;
          }
        }
      }
      if ((((*(char *)((int)param_1 + param_2 + -2) != '\x03') || ((uVar2 & 4) == 0)) ||
          (bVar3 = true, cVar1 != '+')) &&
         ((((uVar2 & 8) == 0 || (bVar3 = true, *(int *)((int)param_1 + 9) != 0x18270303)) &&
          (bVar3 = false, (uVar2 & 0x10) != 0)))) {
        bVar3 = *(int *)((int)param_1 + 9) == 0x18280303;
      }
    }
  }
  return bVar3;
}

