/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
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
  undefined4 uVar3;
  byte *pbVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  int *piVar8;
  
  uVar3 = le_scan_duplicate_option._40_4_;
  if (param_1 == (void *)0x0) {
    return 0;
  }
  uVar5 = 0;
  if (le_scan_duplicate_option._40_4_ != 0) {
    piVar8 = (int *)le_scan_duplicate_option._44_4_;
    if ((le_scan_duplicate_option._40_4_ & 1) != 0) {
      for (; piVar8 != (int *)0x0; piVar8 = (int *)*piVar8) {
        iVar6 = memcmp(piVar8 + 1,param_1,6);
        if (iVar6 == 0) {
          return 1;
        }
      }
    }
    cVar1 = *(char *)((int)param_1 + 7);
    if ((cVar1 == ')') && ((uVar3 & 2) != 0)) {
      for (piVar8 = (int *)le_scan_duplicate_option._52_4_; piVar8 != (int *)0x0;
          piVar8 = (int *)*piVar8) {
        iVar6 = memcmp(piVar8 + 1,(void *)((int)param_1 + 8),4);
        if (iVar6 == 0) {
          return 1;
        }
      }
    }
    bVar2 = *(byte *)((int)param_1 + param_2 + -2);
    if (((((((bVar2 & 0xef) != 0) || ((uVar3 & 4) == 0)) || (uVar5 = 1, cVar1 != '+')) &&
         (((uVar3 & 8) == 0 || (uVar5 = 1, *(int *)((int)param_1 + 9) != 0x18270303)))) &&
        ((((uVar3 & 0x10) == 0 || (uVar5 = 1, *(int *)((int)param_1 + 9) != 0x18280303)) &&
         ((((uVar3 & 0x20) == 0 || (uVar5 = 1, *(int *)((int)param_1 + 9) != 0x18590303)) &&
          (uVar5 = 0, (bVar2 & 0xef) == 0)))))) && ((uVar3 & 0x40) != 0)) {
      bVar2 = *(byte *)((int)param_1 + 6);
      for (pbVar4 = (byte *)((int)param_1 + 7);
          (uVar7 = (uint)bVar2, uVar7 != 0 && ((int)pbVar4 - ((int)param_1 + 6) < param_2 + -7));
          pbVar4 = pbVar4 + uVar7 + 1) {
        if (*pbVar4 == 0x24) {
          return 1;
        }
        bVar2 = pbVar4[uVar7];
      }
      uVar5 = 0;
    }
  }
  return uVar5;
}

