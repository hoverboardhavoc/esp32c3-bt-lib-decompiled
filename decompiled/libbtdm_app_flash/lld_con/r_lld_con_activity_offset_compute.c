/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_activity_offset_compute
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int r_lld_con_activity_offset_compute(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar2 = *(int *)(&lld_con_env + param_1 * 4);
  if (iVar2 == 0) {
    uVar4 = 0;
    uVar3 = 0;
    iVar5 = 0;
    iVar6 = 0;
  }
  else {
    iVar6 = *(int *)(iVar2 + 100);
    uVar3 = (uint)*(ushort *)(iVar2 + 0x7c) + (uint)*(ushort *)(iVar2 + 0x7e) & 0xffff;
    iVar5 = *(int *)(iVar2 + 0x48);
    uVar4 = 0;
    if (param_5 != 0) {
      uVar4 = (uint)*(ushort *)(iVar2 + 0x6e);
    }
  }
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  iVar2 = uVar3 - param_2;
  if (iVar2 < 0x8001) {
    iVar2 = param_2 - uVar3;
  }
  uVar3 = (uint)(param_3 << 0x12) >> 0x10;
  if (uVar3 == 0) {
    r_assert_err(0,"lld_con.c",0x94);
  }
  uVar1 = uVar3 - (((iVar2 * 0x10000 >> 0x10) * iVar6 + iVar5 & 0xfffffffU) + param_4 * -2 &
                  0xfffffff) % uVar3;
  if (uVar3 == uVar1) {
    uVar1 = 0;
  }
  iVar2 = uVar1 * 0x271 - uVar4;
  if (iVar2 < 0) {
    iVar2 = iVar2 + -1;
  }
  else {
    iVar2 = iVar2 + 1;
  }
  return iVar2 >> 1;
}

