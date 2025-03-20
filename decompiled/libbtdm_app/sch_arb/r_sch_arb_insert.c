/*
 * Last changed at upstream commit d2414a5dd958b32ca53382b441d24d97a0345a55
 * https://github.com/espressif/esp32c3-bt-lib/commit/d2414a5dd958b32ca53382b441d24d97a0345a55
 * Upstream date: 2025-03-20 20:11:19 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(03d0f8a6)
 * Source: libbtdm_app -> sch_arb.o -> r_sch_arb_insert
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char r_sch_arb_insert(int param_1)

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
  char cStack_49;
  int iStack_48;
  int iStack_44;
  
  cStack_49 = '\0';
  if (0x6180f < *(int *)(param_1 + 0x10) - 0x271U) {
    (**(code **)(_r_plf_funcs_p + 0xc))(0,"sch_arb.c",0x295,*(code **)(_r_plf_funcs_p + 0xc));
  }
  if (0x270 < *(uint *)(param_1 + 8)) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"sch_arb.c",0x296,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar3 = (*(code *)_r_ip_funcs_p[0x218])(1,&cStack_49,param_1,(code *)_r_ip_funcs_p[0x218]);
  if (iVar3 != 0) {
    return cStack_49;
  }
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iStack_48 = (**(code **)(_r_modules_funcs_p + 0x2c4))(*(code **)(_r_modules_funcs_p + 0x2c4));
  uVar4 = iStack_48 + (uint)rwip_prog_delay;
  for (uVar5 = extraout_a1 + 1000; uVar4 = uVar4 & 0xfffffff, 0x270 < uVar5; uVar5 = uVar5 - 0x271)
  {
    uVar4 = uVar4 + 1;
  }
  iStack_44 = extraout_a1;
  if (((*(uint *)(param_1 + 4) - uVar4 & 0xfffffff) < 0x7ffffff) &&
     ((*(uint *)(param_1 + 4) != uVar4 || (uVar5 <= *(uint *)(param_1 + 8))))) {
_L85:
    if (1 < *(ushort *)(param_1 + 0x14) >> 0xe) {
      uVar4 = *(int *)(param_1 + 0xc) - *(int *)(param_1 + 4) & 0xfffffff;
      if (0x8000000 < uVar4) {
        uVar4 = -(*(int *)(param_1 + 4) - *(int *)(param_1 + 0xc) & 0xfffffffU);
      }
      if ((int)uVar4 < (int)(*(uint *)(param_1 + 0x10) / 0x271)) goto _L92;
    }
    piVar1 = _r_ip_funcs_p;
    if (_r_ip_funcs_p == (int *)0x0) {
      piVar1 = _sch_arb_env;
    }
    cVar9 = '\0';
    piVar8 = (int *)0x0;
    piVar6 = (int *)0x0;
    piVar7 = (int *)0x0;
    while (piVar2 = piVar1, piVar2 != (int *)0x0) {
      if (piVar2 == (int *)param_1) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"sch_arb.c",0x2ed,*(code **)(_r_plf_funcs_p + 8));
      }
      uVar4 = (*(code *)_r_ip_funcs_p[0x1a8])(param_1,piVar2,(code *)_r_ip_funcs_p[0x1a8]);
      if (uVar4 == 0) break;
      if (uVar4 != 5) {
        if ((*(byte *)((int)piVar2 + 0x16) < *(byte *)(param_1 + 0x16)) && (_r_ip_funcs_p != piVar2)
           ) {
          if (piVar6 == (int *)0x0) {
            piVar6 = piVar2;
          }
          cVar9 = cVar9 + '\x01';
          piVar8 = piVar2;
          if ((uVar4 & 0xfd) != 1) goto _L96;
        }
        else {
          if (*(ushort *)(param_1 + 0x14) >> 0xe != 0) {
            uVar4 = (uint)(piVar2[2] + piVar2[4]) / 0x271 + piVar2[1];
            if (*(uint *)(param_1 + 8) < (uint)(piVar2[2] + piVar2[4]) % 0x271) {
              uVar4 = uVar4 + 1;
            }
            *(uint *)(param_1 + 4) = uVar4 & 0xfffffff;
            cVar9 = '\0';
            piVar8 = (int *)0x0;
            piVar6 = (int *)0x0;
            goto _L96;
          }
          if (((*(byte *)((int)piVar2 + 0x16) < *(byte *)(param_1 + 0x16)) &&
              (_r_ip_funcs_p == piVar2)) && ((uVar4 - 3 & 0xff) < 2)) {
            if (uVar4 != 3) goto _L96;
          }
          else {
_L126:
            cStack_49 = '\x01';
          }
        }
        break;
      }
_L96:
      if (1 < *(ushort *)(param_1 + 0x14) >> 0xe) {
        uVar4 = *(int *)(param_1 + 0xc) - *(int *)(param_1 + 4) & 0xfffffff;
        if (0x8000000 < uVar4) {
          uVar4 = -(*(int *)(param_1 + 4) - *(int *)(param_1 + 0xc) & 0xfffffffU);
        }
        if ((int)uVar4 < (int)(*(uint *)(param_1 + 0x10) / 0x271)) goto _L126;
      }
      piVar1 = _sch_arb_env;
      if (_r_ip_funcs_p != piVar2) {
        if (cVar9 == '\0') {
          piVar7 = piVar2;
        }
        piVar1 = (int *)*piVar2;
      }
    }
  }
  else {
    if (*(ushort *)(param_1 + 0x14) >> 0xe != 0) {
      *(uint *)(param_1 + 4) = uVar4;
      if (*(uint *)(param_1 + 8) < uVar5) {
        *(uint *)(param_1 + 4) = uVar4 + 1 & 0xfffffff;
      }
      goto _L85;
    }
_L92:
    cStack_49 = '\x01';
    piVar6 = (int *)0x0;
    piVar7 = (int *)0x0;
    piVar8 = (int *)0;
  }
  if (cStack_49 != '\x01') {
    if (piVar6 != (int *)0x0) {
      (**(code **)(_r_modules_funcs_p + 0x24))
                (&sch_arb_env,piVar7,piVar8,*(code **)(_r_modules_funcs_p + 0x24));
      (**(code **)(_r_modules_funcs_p + 0x48))
                (&sch_arb_env,piVar6,piVar8,*(code **)(_r_modules_funcs_p + 0x48));
    }
    if (piVar7 == (int *)0x0) {
      (**(code **)(_r_modules_funcs_p + 0x4c))
                (&sch_arb_env,param_1,*(code **)(_r_modules_funcs_p + 0x4c));
      (*(code *)_r_ip_funcs_p[0x1ad])((code *)_r_ip_funcs_p[0x1ad]);
    }
    else {
      (**(code **)(_r_modules_funcs_p + 0x30))
                (&sch_arb_env,piVar7,param_1,*(code **)(_r_modules_funcs_p + 0x30));
    }
    if (piVar6 != (int *)0x0) {
      (*(code *)_r_ip_funcs_p[0x1a9])(param_1,(code *)_r_ip_funcs_p[0x1a9]);
    }
  }
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  (*(code *)_r_ip_funcs_p[0x218])(0,&cStack_49,param_1,(code *)_r_ip_funcs_p[0x218]);
  return cStack_49;
}

