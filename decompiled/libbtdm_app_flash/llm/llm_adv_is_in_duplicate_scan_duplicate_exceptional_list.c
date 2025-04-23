/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llm.o -> llm_adv_is_in_duplicate_scan_duplicate_exceptional_list
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 llm_adv_is_in_duplicate_scan_duplicate_exceptional_list(void *param_1,int param_2)

{
  char cVar1;
  byte bVar2;
  byte *pbVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  
  uVar6 = DAT_000113a8;
  if (param_1 == (void *)0x0) {
    return 0;
  }
  uVar4 = 0;
  if (DAT_000113a8 != 0) {
    piVar7 = DAT_000113ac;
    if ((DAT_000113a8 & 1) != 0) {
      for (; piVar7 != (int *)0x0; piVar7 = (int *)*piVar7) {
        iVar5 = memcmp(piVar7 + 1,param_1,6);
        if (iVar5 == 0) {
          return 1;
        }
      }
    }
    cVar1 = *(char *)((int)param_1 + 7);
    if ((cVar1 == ')') && ((uVar6 & 2) != 0)) {
      for (piVar7 = (int *)DAT_000113b4; piVar7 != (int *)0x0; piVar7 = (int *)*piVar7) {
        iVar5 = memcmp(piVar7 + 1,(void *)((int)param_1 + 8),4);
        if (iVar5 == 0) {
          return 1;
        }
      }
    }
    bVar2 = *(byte *)((int)param_1 + param_2 + -2);
    if (((((((bVar2 & 0xef) != 0) || ((uVar6 & 4) == 0)) || (uVar4 = 1, cVar1 != '+')) &&
         (((uVar6 & 8) == 0 || (uVar4 = 1, *(int *)((int)param_1 + 9) != 0x18270303)))) &&
        ((((uVar6 & 0x10) == 0 || (uVar4 = 1, *(int *)((int)param_1 + 9) != 0x18280303)) &&
         ((((uVar6 & 0x20) == 0 || (uVar4 = 1, *(int *)((int)param_1 + 9) != 0x18590303)) &&
          (uVar4 = 0, (bVar2 & 0xef) == 0)))))) && ((uVar6 & 0x40) != 0)) {
      bVar2 = *(byte *)((int)param_1 + 6);
      for (pbVar3 = (byte *)((int)param_1 + 7);
          (uVar6 = (uint)bVar2, uVar6 != 0 && ((int)pbVar3 - ((int)param_1 + 6) < param_2 + -7));
          pbVar3 = pbVar3 + uVar6 + 1) {
        if (*pbVar3 == 0x24) {
          return 1;
        }
        bVar2 = pbVar3[uVar6];
      }
      uVar4 = 0;
    }
  }
  return uVar4;
}

