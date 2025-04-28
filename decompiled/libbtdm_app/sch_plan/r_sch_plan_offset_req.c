/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
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
  bool bVar2;
  bool bVar3;
  int *piVar4;
  undefined1 uVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 extraout_a1;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  code *pcVar13;
  int *piVar14;
  int *unaff_s4;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
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
    uStack_48 = (**(code **)(_r_modules_funcs_p + 0x2c4))(*(code **)(_r_modules_funcs_p + 0x2c4));
    uVar17 = uStack_48 & 0x8000000;
    bVar2 = uVar17 != 0;
    uStack_44 = extraout_a1;
    if (uVar16 == 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"sch_plan.c",0xcc,*(code **)(_r_plf_funcs_p + 8));
    }
    _g_conflict_elt = 0;
    if ((g_time_msb != '\0') && (uVar17 == 0)) {
      (**(code **)(_r_ip_funcs_p + 0x6dc))(*(code **)(_r_ip_funcs_p + 0x6dc));
    }
    if (param_1 == 1) {
      uVar17 = *param_4;
    }
    else {
      uVar17 = *(uint *)(param_3 + 0x14);
    }
    g_time_msb = bVar2;
    uVar5 = 1;
    if ((uVar17 != 0) && (uVar16 != 0)) {
      uVar9 = uVar15;
      if (param_1 == 1) {
        uVar9 = param_4[2];
      }
      bVar3 = false;
      piVar4 = _sch_plan_env;
_L43:
      do {
        piVar14 = piVar4;
        if (piVar14 == (int *)0x0) {
          if (bVar3) {
            _g_conflict_elt = (int)unaff_s4;
          }
          if (uVar9 < uVar17) {
            if (param_1 == 0) {
              pcVar13 = *(code **)(_r_ip_funcs_p + 0x6e8);
              *(uint *)(param_3 + 0x18) = uVar9;
              uVar7 = (*pcVar13)(*(undefined4 *)(param_3 + 0x14),uVar16,
                                 *(undefined2 *)(param_3 + 0x10),pcVar13);
              *(undefined4 *)(param_3 + 0x1c) = uVar7;
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
        if (uVar17 <= uVar9) {
          if (bVar3) {
            _g_conflict_elt = (int)unaff_s4;
          }
          goto _L66;
        }
        if ((param_1 == 0) && (param_2 != 0)) {
          iVar6 = piVar14[4];
        }
        else {
          iVar6 = piVar14[3];
        }
        uVar11 = piVar14[1];
        if (((uVar11 == 0) || (iVar6 == 0)) || (*(short *)(piVar14 + 5) == sVar1)) {
_L46:
          piVar4 = (int *)*piVar14;
        }
        else {
          uVar10 = uVar11;
          if (uVar17 < uVar11) {
            uVar10 = uVar17;
          }
          if (uVar10 < iVar6 + uVar16) {
            if (bVar3) {
              _g_conflict_elt = (int)unaff_s4;
            }
            return 3;
          }
          if ((uVar17 % uVar10 != 0) || (uVar11 % uVar10 != 0)) goto _L46;
          uVar18 = uVar9 % uVar10;
          uVar12 = (uint)piVar14[2] % uVar10;
          uVar8 = (uVar16 - 1) + uVar18;
          uVar11 = (iVar6 + uVar12) - 1;
          if (uVar18 < uVar12) {
            if (uVar8 < uVar12) {
_L71:
              if (uVar8 < uVar11) goto _L57;
            }
          }
          else if (uVar11 < uVar18) {
            if (uVar8 < uVar12) {
              if (uVar12 == uVar18) goto _L71;
            }
            else if ((uVar8 <= uVar11) || (uVar18 <= uVar12)) goto _L54;
_L57:
            if (((uVar11 < uVar10) || (uVar11 % uVar10 < uVar18)) &&
               ((uVar8 < uVar10 || (uVar8 % uVar10 < uVar12)))) goto _L46;
          }
_L54:
          if (param_1 == 1) {
            bVar3 = true;
            uVar9 = uVar17;
            piVar4 = _sch_plan_env;
            unaff_s4 = piVar14;
          }
          else {
            for (uVar11 = (iVar6 + uVar12) % uVar10; uVar11 <= uVar9; uVar11 = uVar11 + uVar10) {
            }
            uVar9 = uVar11;
            if (uVar15 == 0) goto _L61;
            piVar4 = _sch_plan_env;
            if ((uVar11 & 1) == 0) goto _L62;
          }
        }
      } while( true );
    }
  }
  return uVar5;
_L61:
  piVar4 = _sch_plan_env;
  if ((uVar11 & 1) != 0) {
_L62:
    uVar9 = uVar11 + 1;
    piVar4 = _sch_plan_env;
  }
  goto _L43;
}

