/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> sch_plan.o -> r_sch_plan_interval_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_sch_plan_interval_req(uint *param_1)

{
  bool bVar1;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  char cVar7;
  uint uVar8;
  
  uVar6 = param_1[1];
  uVar2 = *param_1;
  param_1[5] = uVar6;
  if (uVar6 <= uVar2) {
    return;
  }
  uVar5 = 0xffffffff;
  cVar7 = '\0';
  for (piVar3 = (int *)_sch_plan_env; piVar3 != (int *)0x0; piVar3 = (int *)*piVar3) {
    if (*(short *)(piVar3 + 5) != (short)param_1[4]) {
      cVar7 = cVar7 + '\x01';
      if ((uint)piVar3[1] < uVar5) {
        uVar5 = piVar3[1];
      }
    }
  }
  if (cVar7 == '\0') {
    uVar8 = (uint)*(byte *)((int)param_1 + 0x12);
    if (uVar8 == 0) {
      uVar8 = 0xffffffff;
      goto _L114;
    }
    uVar5 = uVar6 / uVar8;
_L123:
    uVar8 = uVar5 * uVar8;
  }
  else {
    if (uVar5 <= uVar6) {
      uVar8 = uVar6 / uVar5;
      goto _L123;
    }
    uVar8 = 0xffffffff;
    uVar4 = uVar6;
    do {
      bVar1 = uVar5 % uVar4 != 0;
      if (!bVar1) {
        uVar8 = uVar4;
      }
      uVar4 = uVar4 - 2;
    } while ((uVar2 <= uVar4) && (bVar1));
  }
  if (uVar8 < uVar2) {
    return;
  }
_L114:
  if (uVar8 <= uVar6) {
    param_1[5] = uVar8;
  }
  return;
}

