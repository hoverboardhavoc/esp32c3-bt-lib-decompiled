/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> sch_plan.o -> r_sch_plan_offset_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 r_sch_plan_offset_req(int param_1,int param_2,int param_3,uint *param_4)

{
  short sVar1;
  int *piVar2;
  undefined1 uVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 extraout_a1;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  code *pcVar12;
  int *piVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  undefined1 uStack_49;
  uint uStack_48;
  undefined4 uStack_44;
  
  uStack_49 = 0;
  iVar4 = (**(code **)(_r_ip_funcs_p + 0x864))
                    (1,&uStack_49,param_1,param_2,param_3,param_4,*(code **)(_r_ip_funcs_p + 0x864))
  ;
  uVar3 = uStack_49;
  if (iVar4 == 0) {
    if (param_1 == 1) {
      uVar15 = param_4[1];
      sVar1 = (short)param_4[3];
      uVar14 = 0;
    }
    else {
      uVar15 = *(uint *)(param_3 + 8);
      if ((param_1 == 0) && (param_2 != 0)) {
        uVar15 = *(uint *)(param_3 + 0xc);
      }
      sVar1 = *(short *)(param_3 + 0x10);
      uVar14 = (uint)*(byte *)(param_3 + 0x13);
    }
    uStack_48 = (**(code **)(_r_modules_funcs_p + 0x2c4))(*(code **)(_r_modules_funcs_p + 0x2c4));
    uVar16 = uStack_48 & 0x8000000;
    uStack_44 = extraout_a1;
    if (uVar15 == 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"sch_plan.c",0xcc,*(code **)(_r_plf_funcs_p + 8));
    }
    _g_conflict_elt = 0;
    if ((g_time_msb != 0) && (uVar16 == 0)) {
      (**(code **)(_r_ip_funcs_p + 0x6dc))(*(code **)(_r_ip_funcs_p + 0x6dc));
    }
    g_time_msb = (byte)(uVar16 >> 0x1b);
    if (param_1 == 1) {
      uVar16 = *param_4;
    }
    else {
      uVar16 = *(uint *)(param_3 + 0x14);
    }
    uVar3 = 1;
    if ((uVar16 != 0) && (uVar3 = 1, uVar15 != 0)) {
      uVar10 = uVar14;
      piVar2 = _sch_plan_env;
      piVar13 = (int *)_g_conflict_elt;
      if (param_1 == 1) {
        uVar10 = param_4[2];
      }
_L42:
      do {
        _g_conflict_elt = (int)piVar13;
        piVar13 = piVar2;
        uVar7 = uVar10;
        if (piVar13 == (int *)0x0) {
          if (uVar7 < uVar16) {
            if (param_1 == 0) {
              pcVar12 = *(code **)(_r_ip_funcs_p + 0x6e8);
              *(uint *)(param_3 + 0x18) = uVar7;
              uVar6 = (*pcVar12)(*(undefined4 *)(param_3 + 0x14),uVar15,
                                 *(undefined2 *)(param_3 + 0x10),pcVar12);
              *(undefined4 *)(param_3 + 0x1c) = uVar6;
            }
          }
          else {
_L63:
            uStack_49 = 3;
          }
          (**(code **)(_r_ip_funcs_p + 0x864))
                    (0,&uStack_49,param_1,param_2,param_3,param_4,*(code **)(_r_ip_funcs_p + 0x864))
          ;
          return uStack_49;
        }
        if (uVar16 <= uVar7) goto _L63;
        if ((param_1 == 0) && (param_2 != 0)) {
          iVar4 = piVar13[4];
        }
        else {
          iVar4 = piVar13[3];
        }
        uVar10 = piVar13[1];
        if (((uVar10 == 0) || (iVar4 == 0)) || (*(short *)(piVar13 + 5) == sVar1)) {
_L45:
          uVar10 = uVar7;
          piVar2 = (int *)*piVar13;
          piVar13 = (int *)_g_conflict_elt;
          goto _L42;
        }
        uVar9 = uVar10;
        if (uVar16 < uVar10) {
          uVar9 = uVar16;
        }
        if (uVar9 < iVar4 + uVar15) {
          return 3;
        }
        if ((uVar16 % uVar9 != 0) || (uVar10 % uVar9 != 0)) goto _L45;
        uVar10 = uVar7 % uVar9;
        uVar8 = (uint)piVar13[2] % uVar9;
        uVar11 = (uVar15 - 1) + uVar10;
        uVar5 = (iVar4 + uVar8) - 1;
        if (uVar10 < uVar8) {
          if (uVar11 < uVar8) {
_L66:
            if (uVar11 < uVar5) goto _L54;
          }
        }
        else if (uVar5 < uVar10) {
          if (uVar11 < uVar8) {
            if (uVar8 == uVar10) goto _L66;
          }
          else if ((uVar11 <= uVar5) || (uVar10 <= uVar8)) goto _L51;
_L54:
          if (((uVar5 < uVar9) || (uVar5 % uVar9 < uVar10)) &&
             ((uVar11 < uVar9 || (uVar11 % uVar9 < uVar8)))) goto _L45;
        }
_L51:
        uVar10 = uVar16;
        piVar2 = _sch_plan_env;
      } while (param_1 == 1);
      for (uVar10 = (iVar4 + uVar8) % uVar9; uVar10 <= uVar7; uVar10 = uVar10 + uVar9) {
      }
      if (uVar14 == 0) {
        piVar13 = (int *)_g_conflict_elt;
        if ((uVar10 & 1) == 0) goto _L42;
      }
      else {
        piVar13 = (int *)_g_conflict_elt;
        if ((uVar10 & 1) != 0) goto _L42;
      }
      uVar10 = uVar10 + 1;
      piVar13 = (int *)_g_conflict_elt;
      goto _L42;
    }
  }
  return uVar3;
}

