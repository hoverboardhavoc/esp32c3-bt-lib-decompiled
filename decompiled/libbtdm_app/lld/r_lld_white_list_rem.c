/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> lld.o -> r_lld_white_list_rem
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_white_list_rem(int param_1,undefined4 param_2,int param_3)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  code *pcVar4;
  
  if (param_3 != 0xff) {
    iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc00,*(code **)(_r_plf_funcs_p + 0xbc));
    param_1 = param_1 * 8;
    uVar1 = *(ushort *)(iVar2 + param_1);
    iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc00,*(code **)(_r_plf_funcs_p + 0xbc));
    pcVar4 = *(code **)(_r_plf_funcs_p + 0xbc);
    *(ushort *)(iVar2 + param_1) = uVar1 & 0xfffd;
    iVar2 = (*pcVar4)(0xc00,pcVar4);
    if ((*(ushort *)(iVar2 + param_1) & 1) == 0) {
      iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc00,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar1 = *(ushort *)(iVar2 + param_1);
      iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc00,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar2 + param_1) = uVar1 & 0x7fff;
    }
    uVar3 = (**(code **)(_r_ip_funcs_p + 0x260))(param_2,param_3,*(code **)(_r_ip_funcs_p + 0x260));
    if (uVar3 < 10) {
      iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar1 = *(ushort *)(iVar2 + uVar3 * 0x34);
      iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar2 + uVar3 * 0x34) = uVar1 & 0xdfff;
    }
    return;
  }
  _DAT_60031000 = _DAT_60031000 | 0x400;
  return;
}

