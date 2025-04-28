/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> sch_plan.o -> r_sch_plan_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x000102b8) */
/* WARNING: Removing unreachable block (ram,0x000101aa) */
/* WARNING: Removing unreachable block (ram,0x00010196) */
/* WARNING: Removing unreachable block (ram,0x00010220) */
/* WARNING: Removing unreachable block (ram,0x00010132) */
/* WARNING: Removing unreachable block (ram,0x000101ce) */
/* WARNING: Removing unreachable block (ram,0x000102ea) */
/* WARNING: Removing unreachable block (ram,0x000102c6) */
/* WARNING: Removing unreachable block (ram,0x000101f2) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int r_sch_plan_req(int param_1)

{
  byte bVar1;
  short sVar2;
  bool bVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int *piVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  
  r_sch_plan_interval_req();
  iVar6 = r_sch_plan_offset_req(0,1,param_1,0);
  if ((iVar6 == 0) || (*(uint *)(param_1 + 0xc) <= *(uint *)(param_1 + 8))) {
    return iVar6;
  }
  iVar6 = *(int *)(param_1 + 8);
  sVar2 = *(short *)(param_1 + 0x10);
  bVar1 = *(byte *)(param_1 + 0x13);
  uVar4 = r_rwip_time_get();
  bVar3 = (uVar4 & 0x8000000) != 0;
  if (iVar6 == 0) {
    r_assert_err(0,"sch_plan.c",0xcc);
  }
  _g_conflict_elt = 0;
  if ((g_time_msb != '\0') && ((uVar4 & 0x8000000) == 0)) {
    r_sch_plan_clock_wrap_offset_update();
  }
  uVar4 = *(uint *)(param_1 + 0x14);
  if ((uVar4 == 0) || (iVar6 == 0)) {
    g_time_msb = bVar3;
    return 1;
  }
  uVar12 = (uint)bVar1;
  piVar10 = _sch_plan_env;
_L31:
  do {
    if (piVar10 == (int *)0x0) {
      if (uVar4 <= uVar12) {
        g_time_msb = bVar3;
        return 3;
      }
      g_time_msb = bVar3;
      *(uint *)(param_1 + 0x18) = uVar12;
      uVar5 = r_sch_plan_offset_max_calc
                        (*(undefined4 *)(param_1 + 0x14),iVar6,*(undefined2 *)(param_1 + 0x10));
      *(undefined4 *)(param_1 + 0x1c) = uVar5;
      return 0;
    }
    if (uVar4 <= uVar12) {
      g_time_msb = bVar3;
      return 3;
    }
    iVar11 = piVar10[3];
    uVar7 = piVar10[1];
    if (((uVar7 != 0) && (iVar11 != 0)) && (*(short *)(piVar10 + 5) != sVar2)) {
      uVar9 = uVar7;
      if (uVar4 < uVar7) {
        uVar9 = uVar4;
      }
      if (uVar9 < (uint)(iVar11 + iVar6)) {
        g_time_msb = bVar3;
        return 3;
      }
      if ((uVar4 % uVar9 == 0) && (uVar7 % uVar9 == 0)) {
        uVar7 = uVar12 % uVar9;
        uVar8 = (uint)piVar10[2] % uVar9;
        uVar13 = iVar6 + -1 + uVar7;
        uVar14 = (iVar11 + uVar8) - 1;
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
          else if ((uVar13 <= uVar14) || (uVar7 <= uVar8)) goto code_r0x00010272;
_L45:
          if (((uVar14 < uVar9) || (uVar14 % uVar9 < uVar7)) &&
             ((uVar13 < uVar9 || (uVar13 % uVar9 < uVar8)))) goto _L34;
        }
code_r0x00010272:
        for (uVar7 = (iVar11 + uVar8) % uVar9; uVar7 <= uVar12; uVar7 = uVar7 + uVar9) {
        }
        uVar12 = uVar7;
        if (bVar1 == 0) {
          piVar10 = _sch_plan_env;
          if ((uVar7 & 1) == 0) goto _L31;
        }
        else {
          piVar10 = _sch_plan_env;
          if ((uVar7 & 1) != 0) goto _L31;
        }
        uVar12 = uVar7 + 1;
        piVar10 = _sch_plan_env;
        goto _L31;
      }
    }
_L34:
    piVar10 = (int *)*piVar10;
  } while( true );
}

