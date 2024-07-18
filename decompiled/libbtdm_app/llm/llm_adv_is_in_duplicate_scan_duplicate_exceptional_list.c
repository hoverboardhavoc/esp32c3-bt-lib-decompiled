/*
 * Last changed at upstream commit bfdfe8f851c99ced8316b133b0b15521917ea049
 * https://github.com/espressif/esp32c3-bt-lib/commit/bfdfe8f851c99ced8316b133b0b15521917ea049
 * Upstream date: 2024-07-18 14:51:28 +0800
 * Upstream subject: feat(bt): Support mesh duplicate with extend scan (aa16a46)
 * Source: libbtdm_app -> llm.o -> llm_adv_is_in_duplicate_scan_duplicate_exceptional_list
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

byte llm_adv_is_in_duplicate_scan_duplicate_exceptional_list(void *param_1,int param_2)

{
  char cVar1;
  byte bVar2;
  byte *pbVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  
  iVar5 = (**(code **)(_r_ip_funcs_p + 0x924))(*(code **)(_r_ip_funcs_p + 0x924));
  if (param_1 != (void *)0x0) {
    uVar4 = *(uint *)(iVar5 + 0x28);
    if (uVar4 == 0) {
      return 0;
    }
    if ((uVar4 & 1) != 0) {
      for (piVar7 = *(int **)(iVar5 + 0x2c); piVar7 != (int *)0x0; piVar7 = (int *)*piVar7) {
        iVar6 = memcmp(piVar7 + 1,param_1,6);
        if (iVar6 == 0) {
          return 1;
        }
      }
    }
    cVar1 = *(char *)((int)param_1 + 7);
    if ((cVar1 == ')') && ((uVar4 & 2) != 0)) {
      for (piVar7 = *(int **)(iVar5 + 0x34); piVar7 != (int *)0x0; piVar7 = (int *)*piVar7) {
        iVar5 = memcmp(piVar7 + 1,(void *)((int)param_1 + 8),4);
        if (iVar5 == 0) {
          return 1;
        }
      }
    }
    bVar2 = *(byte *)((int)param_1 + param_2 + -2);
    if ((((bVar2 & 0xef) == 0) && ((uVar4 & 4) != 0)) && (cVar1 == '+')) {
      return 1;
    }
    if (((uVar4 & 8) != 0) && (*(int *)((int)param_1 + 9) == 0x18270303)) {
      return 1;
    }
    if (((uVar4 & 0x10) != 0) && (*(int *)((int)param_1 + 9) == 0x18280303)) {
      return 1;
    }
    if (((uVar4 & 0x20) != 0) && (*(int *)((int)param_1 + 9) == 0x18590303)) {
      return 1;
    }
    if ((bVar2 & 0xef) != 0) {
      return 0;
    }
    if ((uVar4 & 0x40) == 0) {
      return bVar2 & 0xef;
    }
    bVar2 = *(byte *)((int)param_1 + 6);
    for (pbVar3 = (byte *)((int)param_1 + 7);
        (uVar4 = (uint)bVar2, uVar4 != 0 && ((int)pbVar3 - ((int)param_1 + 6) < param_2 + -7));
        pbVar3 = pbVar3 + uVar4 + 1) {
      if (*pbVar3 == 0x24) {
        return 1;
      }
      bVar2 = pbVar3[uVar4];
    }
  }
  return 0;
}

