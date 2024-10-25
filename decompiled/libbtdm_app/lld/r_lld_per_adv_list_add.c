/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> lld.o -> r_lld_per_adv_list_add
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_per_adv_list_add(int param_1,void *param_2,int param_3,uint param_4)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  void *__dest;
  uint uVar5;
  code *pcVar6;
  
  iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc00,*(code **)(_r_plf_funcs_p + 0xbc));
  iVar2 = param_1 * 8;
  uVar1 = *(ushort *)(iVar3 + iVar2);
  iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc00,*(code **)(_r_plf_funcs_p + 0xbc));
  *(ushort *)(iVar3 + iVar2) = uVar1 & 0x7fff | 0x8000;
  if ((param_3 << 0xe & 0x3f8000U) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld.c",0x60,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc00,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar1 = *(ushort *)(iVar3 + iVar2);
  iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc00,*(code **)(_r_plf_funcs_p + 0xbc));
  pcVar6 = *(code **)(_r_plf_funcs_p + 0xbc);
  *(ushort *)(iVar3 + iVar2) = uVar1 & 0xbfff | (ushort)(param_3 << 0xe);
  iVar3 = (*pcVar6)(0xc00,pcVar6);
  uVar1 = *(ushort *)(iVar3 + iVar2);
  iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc00,*(code **)(_r_plf_funcs_p + 0xbc));
  iVar3 = _r_plf_funcs_p;
  *(ushort *)(iVar4 + iVar2) = uVar1 & 0xfffe | 1;
  __dest = (void *)(**(code **)(iVar3 + 0xbc))(iVar2 + 0xc02U & 0xffff,*(code **)(iVar3 + 0xbc));
  memcpy(__dest,param_2,6);
  iVar2 = _r_ip_funcs_p;
  iVar3 = param_1 * 2 + _p_lld_env;
  *(ushort *)(iVar3 + 0xbc) = (ushort)(1 << (param_4 & 0x1f)) | *(ushort *)(iVar3 + 0xbc);
  uVar5 = (**(code **)(iVar2 + 0x260))(param_2,param_3,*(code **)(iVar2 + 0x260));
  if (uVar5 < 10) {
    iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar1 = *(ushort *)(iVar2 + uVar5 * 0x34);
    iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar2 + uVar5 * 0x34) = uVar1 & 0xefff | 0x1000;
  }
  return;
}

