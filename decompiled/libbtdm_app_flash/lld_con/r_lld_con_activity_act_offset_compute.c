/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_activity_act_offset_compute
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint r_lld_con_activity_act_offset_compute
               (int param_1,int param_2,int param_3,int *param_4,int *param_5)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar1 = *(int *)(&lld_con_env + param_1 * 4);
  if (iVar1 == 0) {
    uVar4 = 0;
    uVar3 = 0;
    iVar5 = 0;
    iVar6 = 0;
  }
  else {
    iVar6 = *(int *)(iVar1 + 100);
    iVar5 = *(int *)(iVar1 + 0x48);
    uVar4 = (uint)*(ushort *)(iVar1 + 0x6e);
    uVar3 = (uint)*(ushort *)(iVar1 + 0x7c) + (uint)*(ushort *)(iVar1 + 0x7e) & 0xffff;
  }
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  iVar1 = uVar3 - param_2;
  if (iVar1 < 0x8001) {
    iVar1 = param_2 - uVar3;
  }
  uVar2 = (iVar1 * 0x10000 >> 0x10) * iVar6 + iVar5 & 0xfffffff;
  uVar3 = (*param_4 * 2 + uVar4) / 0x271 + uVar2;
  if (param_3 << 1 == 0) {
    r_assert_err(0,"lld_con.c",0x94);
  }
  iVar1 = ((uVar3 & 0xffffffe) - uVar2 & 0xfffffff) * 0x271 - uVar4;
  if (iVar1 < 1) {
    iVar1 = (iVar1 + -1) / 2;
  }
  else {
    iVar1 = iVar1 + 1 >> 1;
  }
  *param_4 = *param_4 - iVar1;
  *param_5 = *param_5 - iVar1;
  return (uVar3 * 0x10 >> 5) % (uint)(param_3 << 1) & 0xffff;
}

