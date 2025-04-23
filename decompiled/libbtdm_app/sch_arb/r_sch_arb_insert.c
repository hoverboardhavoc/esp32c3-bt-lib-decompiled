/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> sch_arb.o -> r_sch_arb_insert
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char r_sch_arb_insert(uint *param_1)

{
  uint *puVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  int extraout_a1;
  uint uVar5;
  char cVar6;
  uint *puVar7;
  uint *puVar8;
  uint *puVar9;
  char cStack_49;
  int iStack_48;
  int iStack_44;
  
  cStack_49 = '\0';
  if (0x6180f < param_1[4] - 0x271) {
    (**(code **)(_r_plf_funcs_p + 0xc))(0,"sch_arb.c",0x295,*(code **)(_r_plf_funcs_p + 0xc));
  }
  if (0x270 < param_1[2]) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"sch_arb.c",0x296,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar3 = (**(code **)(_r_ip_funcs_p + 0x860))
                    (1,&cStack_49,param_1,*(code **)(_r_ip_funcs_p + 0x860));
  if (iVar3 != 0) {
    return cStack_49;
  }
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iStack_48 = (**(code **)(_r_modules_funcs_p + 0x2c4))(*(code **)(_r_modules_funcs_p + 0x2c4));
  uVar4 = iStack_48 + ((uint)_rwip_prog_delay & 0xff);
  for (uVar5 = extraout_a1 + 1000; uVar4 = uVar4 & 0xfffffff, 0x270 < uVar5; uVar5 = uVar5 - 0x271)
  {
    uVar4 = uVar4 + 1;
  }
  iStack_44 = extraout_a1;
  if (((param_1[1] - uVar4 & 0xfffffff) < 0x7ffffff) &&
     ((param_1[1] != uVar4 || (uVar5 <= param_1[2])))) {
_L86:
    if (1 < (ushort)((ushort)param_1[5] >> 0xe)) {
      uVar4 = param_1[3] - param_1[1] & 0xfffffff;
      if (0x8000000 < uVar4) {
        uVar4 = -(param_1[1] - param_1[3] & 0xfffffff);
      }
      if ((int)uVar4 < (int)(param_1[4] / 0x271)) goto _L92;
    }
    puVar1 = _rwip_prog_delay;
    if (_rwip_prog_delay == (uint *)0x0) {
      puVar1 = _sch_arb_env;
    }
    cVar6 = '\0';
    puVar9 = (uint *)0x0;
    puVar7 = (uint *)0x0;
    puVar8 = (uint *)0x0;
    while (puVar2 = puVar1, puVar2 != (uint *)0x0) {
      if (puVar2 == param_1) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"sch_arb.c",0x2ed,*(code **)(_r_plf_funcs_p + 8));
      }
      uVar4 = (**(code **)(_r_ip_funcs_p + 0x6a0))(param_1,puVar2,*(code **)(_r_ip_funcs_p + 0x6a0))
      ;
      if (uVar4 == 0) break;
      if (uVar4 != 5) {
        if ((*(byte *)((int)puVar2 + 0x16) < *(byte *)((int)param_1 + 0x16)) &&
           (_rwip_prog_delay != puVar2)) {
          if (puVar7 == (uint *)0x0) {
            puVar7 = puVar2;
          }
          cVar6 = cVar6 + '\x01';
          puVar9 = puVar2;
          if ((uVar4 & 0xfd) != 1) goto _L96;
        }
        else {
          if ((ushort)((ushort)param_1[5] >> 0xe) != 0) {
            cVar6 = '\0';
            puVar9 = (uint *)0x0;
            puVar7 = (uint *)0x0;
            param_1[1] = (puVar2[2] + puVar2[4]) / 0x271 + puVar2[1] +
                         (uint)(param_1[2] < (puVar2[2] + puVar2[4]) % 0x271) & 0xfffffff;
            goto _L96;
          }
          if (((*(byte *)((int)puVar2 + 0x16) < *(byte *)((int)param_1 + 0x16)) &&
              (_rwip_prog_delay == puVar2)) && ((uVar4 - 3 & 0xff) < 2)) {
            if (uVar4 != 3) goto _L96;
          }
          else {
_L128:
            cStack_49 = '\x01';
          }
        }
        break;
      }
_L96:
      if (1 < (ushort)((ushort)param_1[5] >> 0xe)) {
        uVar4 = param_1[3] - param_1[1] & 0xfffffff;
        if (0x8000000 < uVar4) {
          uVar4 = -(param_1[1] - param_1[3] & 0xfffffff);
        }
        if ((int)uVar4 < (int)(param_1[4] / 0x271)) goto _L128;
      }
      puVar1 = _sch_arb_env;
      if (_rwip_prog_delay != puVar2) {
        if (cVar6 == '\0') {
          puVar8 = puVar2;
        }
        puVar1 = (uint *)*puVar2;
      }
    }
  }
  else {
    if ((ushort)((ushort)param_1[5] >> 0xe) != 0) {
      param_1[1] = uVar4;
      if (param_1[2] < uVar5) {
        param_1[1] = uVar4 + 1 & 0xfffffff;
      }
      goto _L86;
    }
_L92:
    cStack_49 = '\x01';
    puVar7 = (uint *)0x0;
    puVar8 = (uint *)0x0;
    puVar9 = (uint *)0x0;
  }
  if (cStack_49 != '\x01') {
    if (puVar7 != (uint *)0x0) {
      (**(code **)(_r_modules_funcs_p + 0x24))
                (&sch_arb_env,puVar8,puVar9,*(code **)(_r_modules_funcs_p + 0x24));
      (**(code **)(_r_modules_funcs_p + 0x48))
                (&sch_arb_env,puVar7,puVar9,*(code **)(_r_modules_funcs_p + 0x48));
    }
    if (puVar8 == (uint *)0x0) {
      (**(code **)(_r_modules_funcs_p + 0x4c))
                (&sch_arb_env,param_1,*(code **)(_r_modules_funcs_p + 0x4c));
      (**(code **)(_r_ip_funcs_p + 0x6b4))(*(code **)(_r_ip_funcs_p + 0x6b4));
    }
    else {
      (**(code **)(_r_modules_funcs_p + 0x30))
                (&sch_arb_env,puVar8,param_1,*(code **)(_r_modules_funcs_p + 0x30));
    }
    if (puVar7 != (uint *)0x0) {
      (**(code **)(_r_ip_funcs_p + 0x6a4))(param_1,*(code **)(_r_ip_funcs_p + 0x6a4));
    }
  }
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  (**(code **)(_r_ip_funcs_p + 0x860))(0,&cStack_49,param_1,*(code **)(_r_ip_funcs_p + 0x860));
  return cStack_49;
}

