/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app -> llc_con_upd.o -> r_llc_con_plan_set_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llc_con_plan_set_update(int param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  ushort uStack_34;
  ushort auStack_32 [5];
  
  iVar8 = *(int *)(&llc_env + param_1 * 4);
  iVar2 = (**(code **)(_r_ip_funcs_p + 0x4f0))(*(code **)(_r_ip_funcs_p + 0x4f0));
  if (param_2 == 0) {
    uVar7 = 2;
  }
  else {
    uVar7 = (uint)*(ushort *)(param_2 + 0x10);
    if (uVar7 < 2) {
      uVar7 = 2;
    }
    uVar6 = (uint)*(ushort *)(param_2 + 0x12);
    if (1 < uVar6) goto _L117;
  }
  uVar6 = 2;
_L117:
  iVar3 = (**(code **)(_r_ip_funcs_p + 0x374))(param_1,*(code **)(_r_ip_funcs_p + 0x374));
  uVar4 = (uint)*(ushort *)(iVar8 + 0xe);
  uVar5 = uVar4 * 2;
  if (iVar2 == 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"llc_con_upd.c",0x3a5,*(code **)(_r_plf_funcs_p + 8));
  }
  if (uVar4 == 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"llc_con_upd.c",0x3a6,*(code **)(_r_plf_funcs_p + 8));
  }
  (**(code **)(_r_ip_funcs_p + 0x6f4))(iVar2,*(code **)(_r_ip_funcs_p + 0x6f4));
  uVar1 = *(ushort *)(iVar8 + 0x42);
  *(uint *)(iVar2 + 4) = uVar5;
  *(int *)(iVar2 + 8) = iVar3;
  *(uint *)(iVar2 + 0xc) = uVar7;
  *(uint *)(iVar2 + 0x10) = uVar6;
  if ((uVar1 & 1) == 0) {
    if (uVar4 == 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"llc_con_upd.c",0x94,*(code **)(_r_plf_funcs_p + 8));
    }
    *(int *)(iVar2 + 0xc) = *(int *)(iVar2 + 0xc) + 3;
    *(int *)(iVar2 + 0x10) = *(int *)(iVar2 + 0x10) + 3;
    *(uint *)(iVar2 + 8) = ((uVar5 - 1) + iVar3) % uVar5;
  }
  iVar8 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  if (*(char *)(iVar8 + 0x15) == '\x01') {
    uVar4 = *(uint *)(iVar2 + 0x10);
    uVar6 = (**(code **)(_r_ip_funcs_p + 0x340))(param_1,*(code **)(_r_ip_funcs_p + 0x340));
    iVar8 = _r_ip_funcs_p;
    uVar7 = uVar6 / 0x4e2;
    if (uVar6 / 0x4e2 < uVar4) {
      uVar7 = uVar4;
    }
    *(uint *)(iVar2 + 0x10) = uVar7;
    uVar4 = *(uint *)(iVar2 + 0xc);
    uVar6 = (**(code **)(iVar8 + 0x340))(param_1,*(code **)(iVar8 + 0x340));
    uVar7 = uVar6 / 0x4e2;
    if (uVar6 / 0x4e2 < uVar4) {
      uVar7 = uVar4;
    }
    *(uint *)(iVar2 + 0xc) = uVar7;
  }
  else {
    iVar8 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
    if ((*(char *)(iVar8 + 0x15) == '\x02') &&
       (iVar8 = (**(code **)(_r_ip_funcs_p + 0x344))
                          (param_1,&uStack_34,auStack_32,*(code **)(_r_ip_funcs_p + 0x344)),
       iVar8 == 0)) {
      *(uint *)(iVar2 + 0x10) = (uint)uStack_34;
      *(uint *)(iVar2 + 0xc) = (uint)auStack_32[0];
    }
  }
                    /* WARNING: Could not recover jumptable at 0x00010ee0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_ip_funcs_p + 0x6fc))(iVar2,*(code **)(_r_ip_funcs_p + 0x6fc));
  return;
}

