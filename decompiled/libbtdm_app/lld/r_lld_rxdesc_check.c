/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> lld.o -> r_lld_rxdesc_check
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort r_lld_rxdesc_check(uint param_1)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  
  bVar1 = *(byte *)(_p_lld_env + 0xd8);
  while ((*(char *)(_p_lld_env + 0x101) == '\0' &&
         (iVar4 = (**(code **)(_r_ip_funcs_p + 0x100))(*(code **)(_r_ip_funcs_p + 0x100)),
         iVar4 != 0))) {
    uVar6 = (*(byte *)(_p_lld_env + 0xd9) + 1) % 10;
    *(char *)(_p_lld_env + 0xd9) = (char)uVar6;
    iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
    if (-1 < *(short *)(uVar6 * 0x14 + iVar7)) {
      (**(code **)(_r_plf_funcs_p + 0xc))
                (*(undefined1 *)(_p_lld_env + 0xd9),*(undefined1 *)(_p_lld_env + 0xd8),"lld.c",0x4d0
                 ,*(code **)(_r_plf_funcs_p + 0xc));
    }
    bVar2 = *(byte *)(_p_lld_env + 0xd9);
    iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
    if (*(short *)((uint)bVar2 * 0x14 + 0x12 + iVar7) != 0) {
      (**(code **)(_r_plf_funcs_p + 0xc))
                (*(undefined1 *)(_p_lld_env + 0xd9),*(undefined1 *)(_p_lld_env + 0xd8),"lld.c",0x4d1
                 ,*(code **)(_r_plf_funcs_p + 0xc));
    }
    bVar2 = *(byte *)(_p_lld_env + 0xd9);
    iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
    iVar7 = _p_lld_env;
    *(short *)((uint)bVar2 * 0x14 + 0x12 + iVar5) = (short)iVar4;
    iVar7 = (uint)*(byte *)(iVar7 + 0xd9) * 0x14;
    iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar3 = *(ushort *)(iVar4 + iVar7);
    iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar4 + iVar7) = uVar3 & 0x7fff;
  }
  iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  iVar7 = (uint)bVar1 * 0x14;
  if ((*(short *)(iVar4 + iVar7) < 0) &&
     (iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc)),
     *(ushort *)(iVar4 + iVar7 + 0xc) >> 0xb == param_1)) {
    iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar3 = *(ushort *)(iVar7 + 2 + iVar4) >> 0xf ^ 1;
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}

