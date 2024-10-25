/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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
  uint uVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int *piVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  int *piVar17;
  
  if (param_1 == 1) {
    uVar16 = param_4[1];
    sVar1 = (short)param_4[3];
    uVar5 = 0;
  }
  else {
    uVar16 = *(uint *)(param_3 + 8);
    if ((param_1 == 0) && (param_2 != 0)) {
      uVar16 = *(uint *)(param_3 + 0xc);
    }
    sVar1 = *(short *)(param_3 + 0x10);
    uVar5 = (uint)*(byte *)(param_3 + 0x13);
  }
  uVar6 = r_rwip_time_get();
  bVar2 = (uVar6 & 0x8000000) != 0;
  if (uVar16 == 0) {
    r_assert_err(0,"sch_plan.c",0xcc);
  }
  _g_conflict_elt = 0;
  if ((g_time_msb != '\0') && ((uVar6 & 0x8000000) == 0)) {
    r_sch_plan_clock_wrap_offset_update();
  }
  if (param_1 == 1) {
    uVar6 = *param_4;
  }
  else {
    uVar6 = *(uint *)(param_3 + 0x14);
  }
  if ((uVar6 == 0) || (uVar16 == 0)) {
    g_time_msb = bVar2;
    return 1;
  }
  uVar10 = uVar5;
  if (param_1 == 1) {
    uVar10 = param_4[2];
  }
  bVar3 = false;
  piVar4 = _sch_plan_env;
  piVar17 = (int *)_g_conflict_elt;
_L31:
  do {
    piVar12 = piVar4;
    if (piVar12 == (int *)0x0) {
      if (bVar3) {
        _g_conflict_elt = (int)piVar17;
      }
      if (uVar6 <= uVar10) {
        g_time_msb = bVar2;
        return 3;
      }
      if (param_1 != 0) {
        g_time_msb = bVar2;
        return 0;
      }
      g_time_msb = bVar2;
      *(uint *)(param_3 + 0x18) = uVar10;
      uVar7 = r_sch_plan_offset_max_calc
                        (*(undefined4 *)(param_3 + 0x14),uVar16,*(undefined2 *)(param_3 + 0x10));
      *(undefined4 *)(param_3 + 0x1c) = uVar7;
      return 0;
    }
    if (uVar6 <= uVar10) {
_L92:
      if (!bVar3) {
        g_time_msb = bVar2;
        return 3;
      }
      g_time_msb = bVar2;
      _g_conflict_elt = (int)piVar17;
      return 3;
    }
    if ((param_1 == 0) && (param_2 != 0)) {
      iVar13 = piVar12[4];
    }
    else {
      iVar13 = piVar12[3];
    }
    uVar8 = piVar12[1];
    if (((uVar8 != 0) && (iVar13 != 0)) && (*(short *)(piVar12 + 5) != sVar1)) {
      uVar11 = uVar8;
      if (uVar6 < uVar8) {
        uVar11 = uVar6;
      }
      if (uVar11 < iVar13 + uVar16) goto _L92;
      if ((uVar6 % uVar11 == 0) && (uVar8 % uVar11 == 0)) {
        uVar8 = uVar10 % uVar11;
        uVar9 = (uint)piVar12[2] % uVar11;
        uVar14 = (uVar16 - 1) + uVar8;
        uVar15 = (iVar13 + uVar9) - 1;
        if (uVar8 < uVar9) {
          if (uVar14 < uVar9) {
_L54:
            if (uVar14 < uVar15) goto _L45;
          }
        }
        else if (uVar15 < uVar8) {
          if (uVar14 < uVar9) {
            if (uVar9 == uVar8) goto _L54;
          }
          else if ((uVar14 <= uVar15) || (uVar8 <= uVar9)) goto _L42;
_L45:
          if (((uVar15 < uVar11) || (uVar15 % uVar11 < uVar8)) &&
             ((uVar14 < uVar11 || (uVar14 % uVar11 < uVar9)))) goto _L34;
        }
_L42:
        if (param_1 == 1) {
          bVar3 = true;
          uVar10 = uVar6;
          piVar4 = _sch_plan_env;
          piVar17 = piVar12;
          goto _L31;
        }
        for (uVar8 = (iVar13 + uVar9) % uVar11; uVar8 <= uVar10; uVar8 = uVar8 + uVar11) {
        }
        uVar10 = uVar8;
        if (uVar5 == 0) {
          piVar4 = _sch_plan_env;
          if ((uVar8 & 1) == 0) goto _L31;
        }
        else {
          piVar4 = _sch_plan_env;
          if ((uVar8 & 1) != 0) goto _L31;
        }
        uVar10 = uVar8 + 1;
        piVar4 = _sch_plan_env;
        goto _L31;
      }
    }
_L34:
    piVar4 = (int *)*piVar12;
  } while( true );
}

