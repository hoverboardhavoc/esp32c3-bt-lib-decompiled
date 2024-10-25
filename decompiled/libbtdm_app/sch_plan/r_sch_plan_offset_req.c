/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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
  bool bVar2;
  bool bVar3;
  int *piVar4;
  undefined1 uVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  undefined4 extraout_a1;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int *piVar13;
  code *pcVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  int *piVar19;
  undefined1 uStack_49;
  uint uStack_48;
  undefined4 uStack_44;
  
  uStack_49 = 0;
  iVar6 = (**(code **)(_r_ip_funcs_p + 0x864))
                    (1,&uStack_49,param_1,param_2,param_3,param_4,*(code **)(_r_ip_funcs_p + 0x864))
  ;
  uVar5 = uStack_49;
  if (iVar6 == 0) {
    if (param_1 == 1) {
      uVar17 = param_4[1];
      sVar1 = (short)param_4[3];
      uVar16 = 0;
    }
    else {
      uVar17 = *(uint *)(param_3 + 8);
      if ((param_1 == 0) && (param_2 != 0)) {
        uVar17 = *(uint *)(param_3 + 0xc);
      }
      sVar1 = *(short *)(param_3 + 0x10);
      uVar16 = (uint)*(byte *)(param_3 + 0x13);
    }
    uStack_48 = (**(code **)(_r_modules_funcs_p + 0x2c4))(*(code **)(_r_modules_funcs_p + 0x2c4));
    uVar18 = uStack_48 & 0x8000000;
    bVar2 = uVar18 != 0;
    uStack_44 = extraout_a1;
    if (uVar17 == 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"sch_plan.c",0xcc,*(code **)(_r_plf_funcs_p + 8));
    }
    _g_conflict_elt = 0;
    if ((g_time_msb != '\0') && (uVar18 == 0)) {
      (**(code **)(_r_ip_funcs_p + 0x6dc))(*(code **)(_r_ip_funcs_p + 0x6dc));
    }
    if (param_1 == 1) {
      uVar18 = *param_4;
    }
    else {
      uVar18 = *(uint *)(param_3 + 0x14);
    }
    g_time_msb = bVar2;
    uVar5 = 1;
    if ((uVar18 != 0) && (uVar17 != 0)) {
      uVar11 = uVar16;
      if (param_1 == 1) {
        uVar11 = param_4[2];
      }
      bVar3 = false;
      piVar4 = _sch_plan_env;
      piVar19 = (int *)_g_conflict_elt;
_L43:
      do {
        piVar13 = piVar4;
        if (piVar13 == (int *)0x0) {
          if (bVar3) {
            _g_conflict_elt = (int)piVar19;
          }
          if (uVar11 < uVar18) {
            if (param_1 == 0) {
              pcVar14 = *(code **)(_r_ip_funcs_p + 0x6e8);
              *(uint *)(param_3 + 0x18) = uVar11;
              uVar8 = (*pcVar14)(*(undefined4 *)(param_3 + 0x14),uVar17,
                                 *(undefined2 *)(param_3 + 0x10),pcVar14);
              *(undefined4 *)(param_3 + 0x1c) = uVar8;
            }
          }
          else {
_L66:
            uStack_49 = 3;
          }
          (**(code **)(_r_ip_funcs_p + 0x864))
                    (0,&uStack_49,param_1,param_2,param_3,param_4,*(code **)(_r_ip_funcs_p + 0x864))
          ;
          return uStack_49;
        }
        if (uVar18 <= uVar11) {
          if (bVar3) {
            _g_conflict_elt = (int)piVar19;
          }
          goto _L66;
        }
        if ((param_1 == 0) && (param_2 != 0)) {
          iVar6 = piVar13[4];
        }
        else {
          iVar6 = piVar13[3];
        }
        uVar9 = piVar13[1];
        if (((uVar9 == 0) || (iVar6 == 0)) || (*(short *)(piVar13 + 5) == sVar1)) {
_L46:
          piVar4 = (int *)*piVar13;
        }
        else {
          uVar12 = uVar9;
          if (uVar18 < uVar9) {
            uVar12 = uVar18;
          }
          if (uVar12 < iVar6 + uVar17) {
            if (bVar3) {
              _g_conflict_elt = (int)piVar19;
            }
            return 3;
          }
          if ((uVar18 % uVar12 != 0) || (uVar9 % uVar12 != 0)) goto _L46;
          uVar9 = uVar11 % uVar12;
          uVar10 = (uint)piVar13[2] % uVar12;
          uVar7 = (uVar17 - 1) + uVar9;
          uVar15 = (iVar6 + uVar10) - 1;
          if (uVar9 < uVar10) {
            if (uVar7 < uVar10) {
_L71:
              if (uVar7 < uVar15) goto _L57;
            }
          }
          else if (uVar15 < uVar9) {
            if (uVar7 < uVar10) {
              if (uVar10 == uVar9) goto _L71;
            }
            else if ((uVar7 <= uVar15) || (uVar9 <= uVar10)) goto _L54;
_L57:
            if (((uVar15 < uVar12) || (uVar15 % uVar12 < uVar9)) &&
               ((uVar7 < uVar12 || (uVar7 % uVar12 < uVar10)))) goto _L46;
          }
_L54:
          if (param_1 == 1) {
            bVar3 = true;
            uVar11 = uVar18;
            piVar4 = _sch_plan_env;
            piVar19 = piVar13;
          }
          else {
            for (uVar9 = (iVar6 + uVar10) % uVar12; uVar9 <= uVar11; uVar9 = uVar9 + uVar12) {
            }
            uVar11 = uVar9;
            if (uVar16 == 0) goto _L61;
            piVar4 = _sch_plan_env;
            if ((uVar9 & 1) == 0) goto _L62;
          }
        }
      } while( true );
    }
  }
  return uVar5;
_L61:
  piVar4 = _sch_plan_env;
  if ((uVar9 & 1) != 0) {
_L62:
    uVar11 = uVar9 + 1;
    piVar4 = _sch_plan_env;
  }
  goto _L43;
}

