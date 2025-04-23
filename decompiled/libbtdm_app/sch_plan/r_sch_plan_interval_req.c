/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
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
  uint uVar9;
  
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
      goto _L102;
    }
    uVar5 = uVar6 / uVar8;
_L111:
    uVar8 = uVar5 * uVar8;
  }
  else {
    if (uVar5 <= uVar6) {
      uVar8 = uVar6 / uVar5;
      goto _L111;
    }
    uVar4 = uVar6;
    uVar9 = 0xffffffff;
    do {
      bVar1 = uVar5 % uVar4 != 0;
      uVar8 = uVar4;
      if (bVar1) {
        uVar8 = uVar9;
      }
      uVar4 = uVar4 - 2;
    } while ((uVar2 <= uVar4) && (uVar9 = uVar8, bVar1));
  }
  if (uVar8 < uVar2) {
    return;
  }
_L102:
  if (uVar8 <= uVar6) {
    param_1[5] = uVar8;
  }
  return;
}

