/*
 * Last changed at upstream commit b223604efd557d0a5314afb3b751229df424d244
 * https://github.com/espressif/esp32c3-bt-lib/commit/b223604efd557d0a5314afb3b751229df424d244
 * Upstream date: 2021-06-24 21:26:02 +0800
 * Upstream subject: Update ESP32-C3 and ESP32-S3 bt lib (9c99115)
 * Source: libbtdm_app -> sch_arb.o -> r_sch_arb_insert_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_sch_arb_insert_hack(int param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  int extraout_a1;
  char cVar6;
  uint uVar7;
  int *piVar8;
  int *piVar9;
  int *piVar10;
  
  if (0x6180f < *(int *)(param_1 + 0x10) - 0x271U) {
    (**(code **)(_r_plf_funcs_p + 0xc))(0,"sch_arb.c",0x119,*(code **)(_r_plf_funcs_p + 0xc));
  }
  if (0x270 < *(uint *)(param_1 + 8)) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"sch_arb.c",0x11a,*(code **)(_r_plf_funcs_p + 8));
  }
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar3 = (**(code **)(_r_modules_funcs_p + 0x2c4))(*(code **)(_r_modules_funcs_p + 0x2c4));
  uVar4 = iVar3 + (uint)rwip_prog_delay;
  for (uVar7 = extraout_a1 + 1000; uVar4 = uVar4 & 0xfffffff, 0x270 < uVar7; uVar7 = uVar7 - 0x271)
  {
    uVar4 = uVar4 + 1;
  }
  if (((*(uint *)(param_1 + 4) - uVar4 & 0xfffffff) < 0x7ffffff) &&
     ((*(uint *)(param_1 + 4) != uVar4 || (uVar7 <= *(uint *)(param_1 + 8))))) {
_L8:
    if (1 < *(ushort *)(param_1 + 0x14) >> 0xe) {
      uVar4 = *(int *)(param_1 + 0xc) - *(int *)(param_1 + 4) & 0xfffffff;
      if (0x8000000 < uVar4) {
        uVar4 = -(*(int *)(param_1 + 4) - *(int *)(param_1 + 0xc) & 0xfffffffU);
      }
      if ((int)uVar4 < (int)(*(uint *)(param_1 + 0x10) / 0x271)) goto _L15;
    }
    piVar1 = _ets_printf;
    if (_ets_printf == (int *)0x0) {
      piVar1 = _sch_arb_env;
    }
    cVar6 = '\0';
    piVar9 = (int *)0x0;
    piVar8 = (int *)0x0;
    piVar10 = (int *)0x0;
    while (piVar2 = piVar1, piVar2 != (int *)0x0) {
      if (piVar2 == (int *)param_1) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"sch_arb.c",0x16e,*(code **)(_r_plf_funcs_p + 8));
      }
      uVar4 = (**(code **)(_r_ip_funcs_p + 0x6a0))(param_1,piVar2,*(code **)(_r_ip_funcs_p + 0x6a0))
      ;
      if (uVar4 == 0) break;
      if (uVar4 != 5) {
        if ((*(byte *)((int)piVar2 + 0x16) < *(byte *)(param_1 + 0x16)) && (_ets_printf != piVar2))
        {
          if (piVar8 == (int *)0x0) {
            piVar8 = piVar2;
          }
          cVar6 = cVar6 + '\x01';
          piVar9 = piVar2;
          if ((uVar4 & 0xfd) == 1) break;
        }
        else if (*(ushort *)(param_1 + 0x14) >> 0xe == 0) {
          if (((*(byte *)(param_1 + 0x16) <= *(byte *)((int)piVar2 + 0x16)) ||
              (_ets_printf != piVar2)) || (1 < (uVar4 - 3 & 0xff))) goto _L15;
          if (uVar4 == 3) break;
        }
        else {
          uVar4 = (uint)(piVar2[2] + piVar2[4]) / 0x271 + piVar2[1];
          if (*(uint *)(param_1 + 8) < (uint)(piVar2[2] + piVar2[4]) % 0x271) {
            uVar4 = uVar4 + 1;
          }
          *(uint *)(param_1 + 4) = uVar4 & 0xfffffff;
          cVar6 = '\0';
          piVar9 = (int *)0x0;
          piVar8 = (int *)0x0;
        }
      }
      if (1 < *(ushort *)(param_1 + 0x14) >> 0xe) {
        uVar4 = *(int *)(param_1 + 0xc) - *(int *)(param_1 + 4) & 0xfffffff;
        if (0x8000000 < uVar4) {
          uVar4 = -(*(int *)(param_1 + 4) - *(int *)(param_1 + 0xc) & 0xfffffffU);
        }
        if ((int)uVar4 < (int)(*(uint *)(param_1 + 0x10) / 0x271)) goto _L15;
      }
      piVar1 = _sch_arb_env;
      if (_ets_printf != piVar2) {
        if (cVar6 == '\0') {
          piVar10 = piVar2;
        }
        piVar1 = (int *)*piVar2;
      }
    }
    if (piVar8 != (int *)0x0) {
      (**(code **)(_r_modules_funcs_p + 0x24))
                (&sch_arb_env,piVar10,piVar9,*(code **)(_r_modules_funcs_p + 0x24));
      (**(code **)(_r_modules_funcs_p + 0x48))
                (&sch_arb_env,piVar8,piVar9,*(code **)(_r_modules_funcs_p + 0x48));
      ets_printf("cle status %d min %d\n",0,*(undefined4 *)((int)piVar9 + 0x10));
    }
    if (piVar10 == (int *)0x0) {
      (**(code **)(_r_modules_funcs_p + 0x4c))
                (&sch_arb_env,param_1,*(code **)(_r_modules_funcs_p + 0x4c));
      (**(code **)(_r_ip_funcs_p + 0x6b4))(*(code **)(_r_ip_funcs_p + 0x6b4));
    }
    else {
      (**(code **)(_r_modules_funcs_p + 0x30))
                (&sch_arb_env,piVar10,param_1,*(code **)(_r_modules_funcs_p + 0x30));
    }
    uVar5 = 0;
    if (piVar8 != (int *)0x0) {
      (**(code **)(_r_ip_funcs_p + 0x6a4))(param_1,*(code **)(_r_ip_funcs_p + 0x6a4));
      uVar5 = 0;
    }
  }
  else {
    if (*(ushort *)(param_1 + 0x14) >> 0xe != 0) {
      *(uint *)(param_1 + 4) = uVar4;
      if (*(uint *)(param_1 + 8) < uVar7) {
        *(uint *)(param_1 + 4) = uVar4 + 1 & 0xfffffff;
      }
      goto _L8;
    }
_L15:
    uVar5 = 1;
  }
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return uVar5;
}

