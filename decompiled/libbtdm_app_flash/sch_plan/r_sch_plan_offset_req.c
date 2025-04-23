/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> sch_plan.o -> r_sch_plan_offset_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_sch_plan_offset_req(int param_1,int param_2,int param_3,uint *param_4)

{
  short sVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int *piVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  
  if (param_1 == 1) {
    uVar14 = param_4[1];
    sVar1 = (short)param_4[3];
    uVar13 = 0;
  }
  else {
    uVar14 = *(uint *)(param_3 + 8);
    if ((param_1 == 0) && (param_2 != 0)) {
      uVar14 = *(uint *)(param_3 + 0xc);
    }
    sVar1 = *(short *)(param_3 + 0x10);
    uVar13 = (uint)*(byte *)(param_3 + 0x13);
  }
  uVar3 = r_rwip_time_get();
  if (uVar14 == 0) {
    r_assert_err(0,"sch_plan.c",0xcc);
  }
  _g_conflict_elt = 0;
  if ((g_time_msb != '\0') && ((uVar3 & 0x8000000) == 0)) {
    r_sch_plan_clock_wrap_offset_update();
  }
  g_time_msb = (byte)((uVar3 & 0x8000000) >> 0x1b);
  if (param_1 == 1) {
    uVar3 = *param_4;
  }
  else {
    uVar3 = *(uint *)(param_3 + 0x14);
  }
  if ((uVar3 == 0) || (uVar14 == 0)) {
    return 1;
  }
  uVar6 = uVar13;
  piVar2 = _sch_plan_env;
  piVar10 = (int *)_g_conflict_elt;
  if (param_1 == 1) {
    uVar6 = param_4[2];
  }
_L31:
  do {
    _g_conflict_elt = (int)piVar10;
    piVar10 = piVar2;
    uVar8 = uVar6;
    if (piVar10 == (int *)0x0) {
      if (uVar8 < uVar3) {
        if (param_1 == 0) {
          *(uint *)(param_3 + 0x18) = uVar8;
          uVar5 = r_sch_plan_offset_max_calc
                            (*(undefined4 *)(param_3 + 0x14),uVar14,*(undefined2 *)(param_3 + 0x10))
          ;
          *(undefined4 *)(param_3 + 0x1c) = uVar5;
        }
        return 0;
      }
      return 3;
    }
    if (uVar3 <= uVar8) {
      return 3;
    }
    if ((param_1 == 0) && (param_2 != 0)) {
      iVar11 = piVar10[4];
    }
    else {
      iVar11 = piVar10[3];
    }
    uVar6 = piVar10[1];
    if (((uVar6 != 0) && (iVar11 != 0)) && (*(short *)(piVar10 + 5) != sVar1)) {
      uVar9 = uVar6;
      if (uVar3 < uVar6) {
        uVar9 = uVar3;
      }
      if (uVar9 < iVar11 + uVar14) {
        return 3;
      }
      if ((uVar3 % uVar9 == 0) && (uVar6 % uVar9 == 0)) {
        uVar6 = uVar8 % uVar9;
        uVar7 = (uint)piVar10[2] % uVar9;
        uVar12 = (uVar14 - 1) + uVar6;
        uVar4 = (iVar11 + uVar7) - 1;
        if (uVar6 < uVar7) {
          if (uVar12 < uVar7) {
_L53:
            if (uVar12 < uVar4) goto _L43;
          }
        }
        else if (uVar4 < uVar6) {
          if (uVar12 < uVar7) {
            if (uVar7 == uVar6) goto _L53;
          }
          else if ((uVar12 <= uVar4) || (uVar6 <= uVar7)) goto _L40;
_L43:
          if (((uVar4 < uVar9) || (uVar4 % uVar9 < uVar6)) &&
             ((uVar12 < uVar9 || (uVar12 % uVar9 < uVar7)))) goto _L34;
        }
_L40:
        uVar6 = uVar3;
        piVar2 = _sch_plan_env;
        if (param_1 != 1) {
          for (uVar6 = (iVar11 + uVar7) % uVar9; uVar6 <= uVar8; uVar6 = uVar6 + uVar9) {
          }
          if (uVar13 == 0) {
            piVar10 = (int *)_g_conflict_elt;
            if ((uVar6 & 1) == 0) goto _L31;
          }
          else {
            piVar10 = (int *)_g_conflict_elt;
            if ((uVar6 & 1) != 0) goto _L31;
          }
          uVar6 = uVar6 + 1;
          piVar10 = (int *)_g_conflict_elt;
        }
        goto _L31;
      }
    }
_L34:
    uVar6 = uVar8;
    piVar2 = (int *)*piVar10;
    piVar10 = (int *)_g_conflict_elt;
  } while( true );
}

