/*
 * Last changed at upstream commit 7fb979154bec81163d55aa4e3134425aea0d52ab
 * https://github.com/espressif/esp32c3-bt-lib/commit/7fb979154bec81163d55aa4e3134425aea0d52ab
 * Upstream date: 2023-10-09 11:09:21 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(510fd043)
 * Source: libbtdm_app -> llm.o -> llm_adv_is_in_duplicate_scan_duplicate_exceptional_list
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 llm_adv_is_in_duplicate_scan_duplicate_exceptional_list(void *param_1,int param_2)

{
  char cVar1;
  char cVar2;
  byte bVar3;
  byte *pbVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  
  iVar6 = (**(code **)(_r_ip_funcs_p + 0x924))(*(code **)(_r_ip_funcs_p + 0x924));
  if (param_1 != (void *)0x0) {
    uVar5 = *(uint *)(iVar6 + 0x28);
    if (uVar5 == 0) {
      return 0;
    }
    if ((uVar5 & 1) != 0) {
      for (piVar8 = *(int **)(iVar6 + 0x2c); piVar8 != (int *)0x0; piVar8 = (int *)*piVar8) {
        iVar7 = memcmp(piVar8 + 1,param_1,6);
        if (iVar7 == 0) {
          return 1;
        }
      }
    }
    cVar1 = *(char *)((int)param_1 + 7);
    if ((cVar1 == ')') && ((uVar5 & 2) != 0)) {
      for (piVar8 = *(int **)(iVar6 + 0x34); piVar8 != (int *)0x0; piVar8 = (int *)*piVar8) {
        iVar6 = memcmp(piVar8 + 1,(void *)((int)param_1 + 8),4);
        if (iVar6 == 0) {
          return 1;
        }
      }
    }
    cVar2 = *(char *)((int)param_1 + param_2 + -2);
    if (((cVar2 == '\x03') && ((uVar5 & 4) != 0)) && (cVar1 == '+')) {
      return 1;
    }
    if (((uVar5 & 8) != 0) && (*(int *)((int)param_1 + 9) == 0x18270303)) {
      return 1;
    }
    if (((uVar5 & 0x10) != 0) && (*(int *)((int)param_1 + 9) == 0x18280303)) {
      return 1;
    }
    if (((uVar5 & 0x20) != 0) && (*(int *)((int)param_1 + 9) == 0x18590303)) {
      return 1;
    }
    if (cVar2 != '\x03') {
      return 0;
    }
    if ((uVar5 & 0x40) == 0) {
      return 0;
    }
    bVar3 = *(byte *)((int)param_1 + 6);
    for (pbVar4 = (byte *)((int)param_1 + 7);
        (uVar5 = (uint)bVar3, uVar5 != 0 && ((int)pbVar4 - ((int)param_1 + 6) < param_2 + -7));
        pbVar4 = pbVar4 + uVar5 + 1) {
      if (*pbVar4 == 0x24) {
        return 1;
      }
      bVar3 = pbVar4[uVar5];
    }
  }
  return 0;
}

