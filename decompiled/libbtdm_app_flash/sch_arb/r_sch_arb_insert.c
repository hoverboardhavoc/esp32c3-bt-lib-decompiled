/*
 * Last changed at upstream commit e668c2d101ee46ee1950819607694fb852aecae0
 * https://github.com/espressif/esp32c3-bt-lib/commit/e668c2d101ee46ee1950819607694fb852aecae0
 * Upstream date: 2025-03-14 11:07:43 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(6e312587)
 * Source: libbtdm_app_flash -> sch_arb.o -> r_sch_arb_insert
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_sch_arb_insert(int param_1)

{
  undefined4 uVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  int extraout_a1;
  uint uVar6;
  int *piVar7;
  int *piVar8;
  int *piVar9;
  char cVar10;
  
  if (0x6180f < *(int *)(param_1 + 0x10) - 0x271U) {
    r_assert_param(0,"sch_arb.c",0x293);
  }
  if (0x270 < *(uint *)(param_1 + 8)) {
    r_assert_err(0,"sch_arb.c",0x294);
  }
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar4 = r_rwip_time_get();
  uVar5 = iVar4 + (uint)rwip_prog_delay;
  for (uVar6 = extraout_a1 + 1000; uVar5 = uVar5 & 0xfffffff, 0x270 < uVar6; uVar6 = uVar6 - 0x271)
  {
    uVar5 = uVar5 + 1;
  }
  if (((*(uint *)(param_1 + 4) - uVar5 & 0xfffffff) < 0x7ffffff) &&
     ((*(uint *)(param_1 + 4) != uVar5 || (uVar6 <= *(uint *)(param_1 + 8))))) {
_L83:
    if (1 < *(ushort *)(param_1 + 0x14) >> 0xe) {
      uVar5 = *(int *)(param_1 + 0xc) - *(int *)(param_1 + 4) & 0xfffffff;
      if (0x8000000 < uVar5) {
        uVar5 = -(*(int *)(param_1 + 4) - *(int *)(param_1 + 0xc) & 0xfffffffU);
      }
      if ((int)uVar5 < (int)(*(uint *)(param_1 + 0x10) / 0x271)) goto _L90;
    }
    piVar2 = _r_co_list_extract_after;
    if (_r_co_list_extract_after == (int *)0x0) {
      piVar2 = _sch_arb_env;
    }
    cVar10 = '\0';
    piVar8 = (int *)0x0;
    piVar9 = (int *)0x0;
    piVar7 = (int *)0x0;
    while (piVar3 = piVar2, piVar3 != (int *)0x0) {
      if (piVar3 == (int *)param_1) {
        r_assert_err(0,"sch_arb.c",0x2eb);
      }
      uVar5 = r_sch_arb_conflict_check(param_1,piVar3);
      if (uVar5 == 0) break;
      if (uVar5 != 5) {
        if ((*(byte *)((int)piVar3 + 0x16) < *(byte *)(param_1 + 0x16)) &&
           (_r_co_list_extract_after != piVar3)) {
          if (piVar9 == (int *)0x0) {
            piVar9 = piVar3;
          }
          cVar10 = cVar10 + '\x01';
          piVar8 = piVar3;
          if ((uVar5 & 0xfd) == 1) break;
        }
        else if (*(ushort *)(param_1 + 0x14) >> 0xe == 0) {
          if (((*(byte *)(param_1 + 0x16) <= *(byte *)((int)piVar3 + 0x16)) ||
              (_r_co_list_extract_after != piVar3)) || (1 < (uVar5 - 3 & 0xff))) goto _L90;
          if (uVar5 == 3) break;
        }
        else {
          uVar5 = (uint)(piVar3[2] + piVar3[4]) / 0x271 + piVar3[1];
          if (*(uint *)(param_1 + 8) < (uint)(piVar3[2] + piVar3[4]) % 0x271) {
            uVar5 = uVar5 + 1;
          }
          *(uint *)(param_1 + 4) = uVar5 & 0xfffffff;
          cVar10 = '\0';
          piVar8 = (int *)0x0;
          piVar9 = (int *)0x0;
        }
      }
      if (1 < *(ushort *)(param_1 + 0x14) >> 0xe) {
        uVar5 = *(int *)(param_1 + 0xc) - *(int *)(param_1 + 4) & 0xfffffff;
        if (0x8000000 < uVar5) {
          uVar5 = -(*(int *)(param_1 + 4) - *(int *)(param_1 + 0xc) & 0xfffffffU);
        }
        if ((int)uVar5 < (int)(*(uint *)(param_1 + 0x10) / 0x271)) goto _L90;
      }
      piVar2 = _sch_arb_env;
      if (_r_co_list_extract_after != piVar3) {
        if (cVar10 == '\0') {
          piVar7 = piVar3;
        }
        piVar2 = (int *)*piVar3;
      }
    }
    if (piVar9 != (int *)0x0) {
      r_co_list_extract_sublist(&sch_arb_env,piVar7,piVar8);
      r_co_list_push_back_sublist(&sch_arb_env,piVar9,piVar8);
    }
    if (piVar7 == (int *)0x0) {
      r_co_list_push_front(&sch_arb_env,param_1);
      r_sch_arb_prog_timer();
    }
    else {
      r_co_list_insert_after(&sch_arb_env,piVar7,param_1);
    }
    uVar1 = 0;
    if (piVar9 != (int *)0x0) {
      r_sch_arb_elt_cancel(param_1);
      uVar1 = 0;
    }
  }
  else {
    if (*(ushort *)(param_1 + 0x14) >> 0xe != 0) {
      *(uint *)(param_1 + 4) = uVar5;
      if (*(uint *)(param_1 + 8) < uVar6) {
        *(uint *)(param_1 + 4) = uVar5 + 1 & 0xfffffff;
      }
      goto _L83;
    }
_L90:
    uVar1 = 1;
  }
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return uVar1;
}

