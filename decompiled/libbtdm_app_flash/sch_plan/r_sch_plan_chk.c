/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> sch_plan.o -> r_sch_plan_chk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x00010272) */
/* WARNING: Removing unreachable block (ram,0x00010276) */
/* WARNING: Removing unreachable block (ram,0x000102ac) */
/* WARNING: Removing unreachable block (ram,0x0001027a) */
/* WARNING: Removing unreachable block (ram,0x000102b0) */
/* WARNING: Removing unreachable block (ram,0x00010282) */
/* WARNING: Removing unreachable block (ram,0x000102b4) */
/* WARNING: Removing unreachable block (ram,0x00010284) */
/* WARNING: Removing unreachable block (ram,0x0001022e) */
/* WARNING: Removing unreachable block (ram,0x00010220) */
/* WARNING: Removing unreachable block (ram,0x00010218) */
/* WARNING: Removing unreachable block (ram,0x0001021e) */
/* WARNING: Removing unreachable block (ram,0x00010224) */
/* WARNING: Removing unreachable block (ram,0x000101ca) */
/* WARNING: Removing unreachable block (ram,0x000101ce) */
/* WARNING: Removing unreachable block (ram,0x000102d0) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_sch_plan_chk(uint *param_1)

{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int *piVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  int *unaff_s3;
  uint uVar14;
  
  uVar14 = param_1[1];
  uVar3 = param_1[3];
  uVar5 = r_rwip_time_get();
  bVar1 = (uVar5 & 0x8000000) != 0;
  if (uVar14 == 0) {
    r_assert_err(0,"sch_plan.c",0xcc);
  }
  _g_conflict_elt = 0;
  if ((g_time_msb != '\0') && ((uVar5 & 0x8000000) == 0)) {
    r_sch_plan_clock_wrap_offset_update();
  }
  g_time_msb = bVar1;
  uVar5 = *param_1;
  if ((uVar5 == 0) || (uVar14 == 0)) {
    return 1;
  }
  bVar2 = false;
  uVar8 = param_1[2];
  piVar4 = _sch_plan_env;
_L31:
  do {
    piVar10 = piVar4;
    if (piVar10 == (int *)0x0) {
      if (bVar2) {
        _g_conflict_elt = (int)unaff_s3;
      }
      if (uVar5 <= uVar8) {
        return 3;
      }
      return 0;
    }
    if (uVar5 <= uVar8) {
_L92:
      if (!bVar2) {
        return 3;
      }
      _g_conflict_elt = (int)unaff_s3;
      return 3;
    }
    iVar11 = piVar10[3];
    uVar6 = piVar10[1];
    if (((uVar6 != 0) && (iVar11 != 0)) && (*(short *)(piVar10 + 5) != (short)uVar3)) {
      uVar9 = uVar6;
      if (uVar5 < uVar6) {
        uVar9 = uVar5;
      }
      if (uVar9 < iVar11 + uVar14) goto _L92;
      if ((uVar5 % uVar9 == 0) && (uVar6 % uVar9 == 0)) {
        uVar6 = uVar8 % uVar9;
        uVar7 = (uint)piVar10[2] % uVar9;
        uVar12 = (uVar14 - 1) + uVar6;
        uVar13 = (iVar11 + uVar7) - 1;
        if (uVar6 < uVar7) {
          if (uVar12 < uVar7) {
_L54:
            if (uVar12 < uVar13) goto _L45;
          }
        }
        else if (uVar13 < uVar6) {
          if (uVar12 < uVar7) {
            if (uVar7 == uVar6) goto _L54;
          }
          else if ((uVar12 <= uVar13) || (uVar6 <= uVar7)) goto _L57;
_L45:
          if (((uVar13 < uVar9) || (uVar13 % uVar9 < uVar6)) &&
             ((uVar12 < uVar9 || (uVar12 % uVar9 < uVar7)))) goto _L34;
        }
_L57:
        bVar2 = true;
        uVar8 = uVar5;
        piVar4 = _sch_plan_env;
        unaff_s3 = piVar10;
        goto _L31;
      }
    }
_L34:
    piVar4 = (int *)*piVar10;
  } while( true );
}

