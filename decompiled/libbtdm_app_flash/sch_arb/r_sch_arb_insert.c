/*
 * Last changed at upstream commit daab5dbba958a13041bd496e4a6ed506c9284a06
 * https://github.com/espressif/esp32c3-bt-lib/commit/daab5dbba958a13041bd496e4a6ed506c9284a06
 * Upstream date: 2025-03-20 20:43:40 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(86a4da5c)
 * Source: libbtdm_app_flash -> sch_arb.o -> r_sch_arb_insert
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint r_sch_arb_insert(int param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int extraout_a1;
  uint uVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  char cVar9;
  
  if (0x6180f < *(int *)(param_1 + 0x10) - 0x271U) {
    r_assert_param(0,"sch_arb.c",0x295);
  }
  if (0x270 < *(uint *)(param_1 + 8)) {
    r_assert_err(0,"sch_arb.c",0x296);
  }
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar3 = r_rwip_time_get();
  uVar4 = iVar3 + (uint)rwip_prog_delay;
  for (uVar5 = extraout_a1 + 1000; uVar4 = uVar4 & 0xfffffff, 0x270 < uVar5; uVar5 = uVar5 - 0x271)
  {
    uVar4 = uVar4 + 1;
  }
  if (((*(uint *)(param_1 + 4) - uVar4 & 0xfffffff) < 0x7ffffff) &&
     ((*(uint *)(param_1 + 4) != uVar4 || (uVar5 <= *(uint *)(param_1 + 8))))) {
_L90:
    if (1 < *(ushort *)(param_1 + 0x14) >> 0xe) {
      uVar4 = *(int *)(param_1 + 0xc) - *(int *)(param_1 + 4) & 0xfffffff;
      if (0x8000000 < uVar4) {
        uVar4 = -(*(int *)(param_1 + 4) - *(int *)(param_1 + 0xc) & 0xfffffffU);
      }
      if ((int)uVar4 < (int)(*(uint *)(param_1 + 0x10) / 0x271)) goto _L97;
    }
    piVar1 = _r_co_list_extract_after;
    if (_r_co_list_extract_after == (int *)0x0) {
      piVar1 = _sch_arb_env;
    }
    cVar9 = '\0';
    piVar7 = (int *)0x0;
    piVar8 = (int *)0x0;
    piVar6 = (int *)0x0;
    while (piVar2 = piVar1, piVar2 != (int *)0x0) {
      if (piVar2 == (int *)param_1) {
        r_assert_err(0,"sch_arb.c",0x2ed);
      }
      uVar4 = r_sch_arb_conflict_check(param_1,piVar2);
      if (uVar4 == 0) break;
      if (uVar4 != 5) {
        if ((*(byte *)((int)piVar2 + 0x16) < *(byte *)(param_1 + 0x16)) &&
           (_r_co_list_extract_after != piVar2)) {
          if (piVar8 == (int *)0x0) {
            piVar8 = piVar2;
          }
          cVar9 = cVar9 + '\x01';
          piVar7 = piVar2;
          if ((uVar4 & 0xfd) == 1) break;
        }
        else if (*(ushort *)(param_1 + 0x14) >> 0xe == 0) {
          if (((*(byte *)(param_1 + 0x16) <= *(byte *)((int)piVar2 + 0x16)) ||
              (_r_co_list_extract_after != piVar2)) || (1 < (uVar4 - 3 & 0xff))) goto _L97;
          if (uVar4 == 3) break;
        }
        else {
          uVar4 = (uint)(piVar2[2] + piVar2[4]) / 0x271 + piVar2[1];
          if (*(uint *)(param_1 + 8) < (uint)(piVar2[2] + piVar2[4]) % 0x271) {
            uVar4 = uVar4 + 1;
          }
          *(uint *)(param_1 + 4) = uVar4 & 0xfffffff;
          cVar9 = '\0';
          piVar7 = (int *)0x0;
          piVar8 = (int *)0x0;
        }
      }
      if (1 < *(ushort *)(param_1 + 0x14) >> 0xe) {
        uVar4 = *(int *)(param_1 + 0xc) - *(int *)(param_1 + 4) & 0xfffffff;
        if (0x8000000 < uVar4) {
          uVar4 = -(*(int *)(param_1 + 4) - *(int *)(param_1 + 0xc) & 0xfffffffU);
        }
        if ((int)uVar4 < (int)(*(uint *)(param_1 + 0x10) / 0x271)) goto _L97;
      }
      piVar1 = _sch_arb_env;
      if (_r_co_list_extract_after != piVar2) {
        if (cVar9 == '\0') {
          piVar6 = piVar2;
        }
        piVar1 = (int *)*piVar2;
      }
    }
    if (piVar8 != (int *)0x0) {
      r_co_list_extract_sublist(&sch_arb_env,piVar6,piVar7);
      r_co_list_push_back_sublist(&sch_arb_env,piVar8,piVar7);
    }
    if (piVar6 == (int *)0x0) {
      r_co_list_push_front(&sch_arb_env,param_1);
      r_sch_arb_prog_timer();
    }
    else {
      r_co_list_insert_after(&sch_arb_env,piVar6,param_1);
    }
    uVar4 = 0;
    if (piVar8 != (int *)0x0) {
      r_sch_arb_elt_cancel(param_1);
      uVar4 = 0;
    }
  }
  else {
    if (*(ushort *)(param_1 + 0x14) >> 0xe != 0) {
      *(uint *)(param_1 + 4) = uVar4;
      if (*(uint *)(param_1 + 8) < uVar5) {
        *(uint *)(param_1 + 4) = uVar4 + 1 & 0xfffffff;
      }
      goto _L90;
    }
_L97:
    uVar4 = 1;
  }
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  iVar3 = r_sdk_config_get_opts_ext();
  if (((*(uint *)(iVar3 + 0x28) & 1) != 0) &&
     (iVar3 = r_sdk_config_get_opts_ext(), *(byte *)(iVar3 + 0x2c) < 3)) {
    r_ble_log_internal_x3
              (0x40040002,(uint)*(byte *)(param_1 + 0x16) << 8 | uVar4,*(undefined4 *)(param_1 + 4),
               *(undefined4 *)(param_1 + 0x10));
  }
  return uVar4;
}

