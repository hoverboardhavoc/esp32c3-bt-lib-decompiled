/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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
  int iVar6;
  uint uVar7;
  uint uVar8;
  ushort uStack_34;
  ushort auStack_32 [5];
  
  iVar6 = *(int *)(&llc_env + param_1 * 4);
  iVar2 = (**(code **)(_r_ip_funcs_p + 0x4f0))(*(code **)(_r_ip_funcs_p + 0x4f0));
  if (param_2 == 0) {
    uVar8 = 2;
  }
  else {
    uVar8 = (uint)*(ushort *)(param_2 + 0x10);
    if (uVar8 < 2) {
      uVar8 = 2;
    }
    uVar7 = (uint)*(ushort *)(param_2 + 0x12);
    if (1 < uVar7) goto _L119;
  }
  uVar7 = 2;
_L119:
  iVar3 = (**(code **)(_r_ip_funcs_p + 0x374))(param_1,*(code **)(_r_ip_funcs_p + 0x374));
  uVar4 = (uint)*(ushort *)(iVar6 + 0xe);
  uVar5 = uVar4 * 2;
  if (iVar2 == 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"llc_con_upd.c",0x398,*(code **)(_r_plf_funcs_p + 8));
  }
  if (uVar4 == 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"llc_con_upd.c",0x399,*(code **)(_r_plf_funcs_p + 8));
  }
  (**(code **)(_r_ip_funcs_p + 0x6f4))(iVar2,*(code **)(_r_ip_funcs_p + 0x6f4));
  uVar1 = *(ushort *)(iVar6 + 0x42);
  *(uint *)(iVar2 + 4) = uVar5;
  *(int *)(iVar2 + 8) = iVar3;
  *(uint *)(iVar2 + 0xc) = uVar8;
  *(uint *)(iVar2 + 0x10) = uVar7;
  if ((uVar1 & 1) == 0) {
    if (uVar4 == 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"llc_con_upd.c",0x94,*(code **)(_r_plf_funcs_p + 8));
    }
    *(int *)(iVar2 + 0xc) = *(int *)(iVar2 + 0xc) + 3;
    *(int *)(iVar2 + 0x10) = *(int *)(iVar2 + 0x10) + 3;
    *(uint *)(iVar2 + 8) = ((uVar5 - 1) + iVar3) % uVar5;
  }
  iVar6 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  if (*(char *)(iVar6 + 0x15) == '\x01') {
    uVar4 = *(uint *)(iVar2 + 0x10);
    uVar7 = (**(code **)(_r_ip_funcs_p + 0x340))(param_1,*(code **)(_r_ip_funcs_p + 0x340));
    iVar6 = _r_ip_funcs_p;
    uVar8 = uVar7 / 0x4e2;
    if (uVar7 / 0x4e2 < uVar4) {
      uVar8 = uVar4;
    }
    *(uint *)(iVar2 + 0x10) = uVar8;
    uVar4 = *(uint *)(iVar2 + 0xc);
    uVar7 = (**(code **)(iVar6 + 0x340))(param_1,*(code **)(iVar6 + 0x340));
    uVar8 = uVar7 / 0x4e2;
    if (uVar7 / 0x4e2 < uVar4) {
      uVar8 = uVar4;
    }
    *(uint *)(iVar2 + 0xc) = uVar8;
  }
  else {
    iVar6 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
    if ((*(char *)(iVar6 + 0x15) == '\x02') &&
       (iVar6 = (**(code **)(_r_ip_funcs_p + 0x344))
                          (param_1,&uStack_34,auStack_32,*(code **)(_r_ip_funcs_p + 0x344)),
       iVar6 == 0)) {
      *(uint *)(iVar2 + 0x10) = (uint)uStack_34;
      *(uint *)(iVar2 + 0xc) = (uint)auStack_32[0];
    }
  }
  (**(code **)(_r_ip_funcs_p + 0x6fc))(iVar2,*(code **)(_r_ip_funcs_p + 0x6fc));
  return;
}

