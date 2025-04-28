/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
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
  bool bVar2;
  bool bVar3;
  int *piVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int *piVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  int *unaff_s3;
  uint uVar15;
  uint uVar16;
  
  if (param_1 == 1) {
    uVar16 = param_4[1];
    sVar1 = (short)param_4[3];
    uVar15 = 0;
  }
  else {
    uVar16 = *(uint *)(param_3 + 8);
    if ((param_1 == 0) && (param_2 != 0)) {
      uVar16 = *(uint *)(param_3 + 0xc);
    }
    sVar1 = *(short *)(param_3 + 0x10);
    uVar15 = (uint)*(byte *)(param_3 + 0x13);
  }
  uVar5 = r_rwip_time_get();
  bVar2 = (uVar5 & 0x8000000) != 0;
  if (uVar16 == 0) {
    r_assert_err(0,"sch_plan.c",0xcc);
  }
  _g_conflict_elt = 0;
  if ((g_time_msb != '\0') && ((uVar5 & 0x8000000) == 0)) {
    r_sch_plan_clock_wrap_offset_update();
  }
  if (param_1 == 1) {
    uVar5 = *param_4;
  }
  else {
    uVar5 = *(uint *)(param_3 + 0x14);
  }
  if ((uVar5 == 0) || (uVar16 == 0)) {
    g_time_msb = bVar2;
    return 1;
  }
  uVar9 = uVar15;
  if (param_1 == 1) {
    uVar9 = param_4[2];
  }
  bVar3 = false;
  piVar4 = _sch_plan_env;
_L31:
  do {
    piVar11 = piVar4;
    if (piVar11 == (int *)0x0) {
      if (bVar3) {
        _g_conflict_elt = (int)unaff_s3;
      }
      if (uVar5 <= uVar9) {
        g_time_msb = bVar2;
        return 3;
      }
      if (param_1 != 0) {
        g_time_msb = bVar2;
        return 0;
      }
      g_time_msb = bVar2;
      *(uint *)(param_3 + 0x18) = uVar9;
      uVar6 = r_sch_plan_offset_max_calc
                        (*(undefined4 *)(param_3 + 0x14),uVar16,*(undefined2 *)(param_3 + 0x10));
      *(undefined4 *)(param_3 + 0x1c) = uVar6;
      return 0;
    }
    if (uVar5 <= uVar9) {
_L92:
      if (!bVar3) {
        g_time_msb = bVar2;
        return 3;
      }
      g_time_msb = bVar2;
      _g_conflict_elt = (int)unaff_s3;
      return 3;
    }
    if ((param_1 == 0) && (param_2 != 0)) {
      iVar12 = piVar11[4];
    }
    else {
      iVar12 = piVar11[3];
    }
    uVar7 = piVar11[1];
    if (((uVar7 != 0) && (iVar12 != 0)) && (*(short *)(piVar11 + 5) != sVar1)) {
      uVar10 = uVar7;
      if (uVar5 < uVar7) {
        uVar10 = uVar5;
      }
      if (uVar10 < iVar12 + uVar16) goto _L92;
      if ((uVar5 % uVar10 == 0) && (uVar7 % uVar10 == 0)) {
        uVar7 = uVar9 % uVar10;
        uVar8 = (uint)piVar11[2] % uVar10;
        uVar13 = (uVar16 - 1) + uVar7;
        uVar14 = (iVar12 + uVar8) - 1;
        if (uVar7 < uVar8) {
          if (uVar13 < uVar8) {
_L54:
            if (uVar13 < uVar14) goto _L45;
          }
        }
        else if (uVar14 < uVar7) {
          if (uVar13 < uVar8) {
            if (uVar8 == uVar7) goto _L54;
          }
          else if ((uVar13 <= uVar14) || (uVar7 <= uVar8)) goto _L42;
_L45:
          if (((uVar14 < uVar10) || (uVar14 % uVar10 < uVar7)) &&
             ((uVar13 < uVar10 || (uVar13 % uVar10 < uVar8)))) goto _L34;
        }
_L42:
        if (param_1 == 1) {
          bVar3 = true;
          uVar9 = uVar5;
          piVar4 = _sch_plan_env;
          unaff_s3 = piVar11;
          goto _L31;
        }
        for (uVar7 = (iVar12 + uVar8) % uVar10; uVar7 <= uVar9; uVar7 = uVar7 + uVar10) {
        }
        uVar9 = uVar7;
        if (uVar15 == 0) {
          piVar4 = _sch_plan_env;
          if ((uVar7 & 1) == 0) goto _L31;
        }
        else {
          piVar4 = _sch_plan_env;
          if ((uVar7 & 1) != 0) goto _L31;
        }
        uVar9 = uVar7 + 1;
        piVar4 = _sch_plan_env;
        goto _L31;
      }
    }
_L34:
    piVar4 = (int *)*piVar11;
  } while( true );
}

