/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> sch_plan.o -> r_sch_plan_chk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x00010274) */
/* WARNING: Removing unreachable block (ram,0x00010278) */
/* WARNING: Removing unreachable block (ram,0x0001028a) */
/* WARNING: Removing unreachable block (ram,0x0001027c) */
/* WARNING: Removing unreachable block (ram,0x0001028e) */
/* WARNING: Removing unreachable block (ram,0x00010284) */
/* WARNING: Removing unreachable block (ram,0x00010286) */
/* WARNING: Removing unreachable block (ram,0x000101da) */
/* WARNING: Removing unreachable block (ram,0x000101cc) */
/* WARNING: Removing unreachable block (ram,0x000101c4) */
/* WARNING: Removing unreachable block (ram,0x000101ca) */
/* WARNING: Removing unreachable block (ram,0x000101d0) */
/* WARNING: Removing unreachable block (ram,0x000101e4) */
/* WARNING: Removing unreachable block (ram,0x000101e6) */
/* WARNING: Removing unreachable block (ram,0x000102a0) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_sch_plan_chk(uint *param_1)

{
  uint uVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int *piVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  
  uVar14 = param_1[1];
  uVar1 = param_1[3];
  uVar4 = r_rwip_time_get();
  if (uVar14 == 0) {
    r_assert_err(0,"sch_plan.c",0xcc);
  }
  _g_conflict_elt = 0;
  if ((g_time_msb != '\0') && ((uVar4 & 0x8000000) == 0)) {
    r_sch_plan_clock_wrap_offset_update();
  }
  g_time_msb = (byte)((uVar4 & 0x8000000) >> 0x1b);
  uVar4 = *param_1;
  uVar5 = 1;
  if ((uVar4 != 0) && (uVar14 != 0)) {
    uVar7 = param_1[2];
    piVar2 = _sch_plan_env;
    piVar11 = (int *)_g_conflict_elt;
_L31:
    while (_g_conflict_elt = (int)piVar11, piVar11 = piVar2, uVar9 = uVar7, piVar11 != (int *)0x0) {
      if (uVar4 <= uVar9) {
        return 3;
      }
      iVar12 = piVar11[3];
      uVar7 = piVar11[1];
      if (((uVar7 == 0) || (iVar12 == 0)) || (*(short *)(piVar11 + 5) == (short)uVar1)) goto _L34;
      uVar10 = uVar7;
      if (uVar4 < uVar7) {
        uVar10 = uVar4;
      }
      if (uVar10 < iVar12 + uVar14) {
        return 3;
      }
      if ((uVar4 % uVar10 != 0) || (uVar7 % uVar10 != 0)) goto _L34;
      uVar3 = uVar9 % uVar10;
      uVar8 = (uint)piVar11[2] % uVar10;
      uVar13 = (uVar14 - 1) + uVar3;
      uVar6 = (iVar12 + uVar8) - 1;
      uVar7 = uVar4;
      if (uVar3 < uVar8) goto _L39;
      piVar2 = _sch_plan_env;
      if (uVar6 < uVar3) {
        if (uVar13 < uVar8) {
          if (uVar8 != uVar3) goto _L43;
          goto _L53;
        }
        if ((uVar6 < uVar13) && (uVar8 < uVar3)) goto _L43;
      }
    }
    uVar5 = 3;
    if (uVar9 < uVar4) {
      uVar5 = 0;
    }
  }
  return uVar5;
_L39:
  piVar2 = _sch_plan_env;
  if (uVar13 < uVar8) {
_L53:
    piVar2 = _sch_plan_env;
    if (uVar13 < uVar6) {
_L43:
      if (((uVar6 < uVar10) || (piVar2 = _sch_plan_env, uVar6 % uVar10 < uVar3)) &&
         ((uVar13 < uVar10 || (piVar2 = _sch_plan_env, uVar13 % uVar10 < uVar8)))) {
_L34:
        uVar7 = uVar9;
        piVar2 = (int *)*piVar11;
        piVar11 = (int *)_g_conflict_elt;
      }
    }
  }
  goto _L31;
}

