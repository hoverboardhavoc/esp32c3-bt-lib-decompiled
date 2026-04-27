/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
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
  uint uVar3;
  ushort uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  bVar1 = *(byte *)(_p_lld_env + 0xd8);
  while ((*(char *)(_p_lld_env + 0x101) == '\0' &&
         (iVar5 = (**(code **)(_r_ip_funcs_p + 0x100))(*(code **)(_r_ip_funcs_p + 0x100)),
         iVar5 != 0))) {
    uVar3 = (*(byte *)(_p_lld_env + 0xd9) + 1) % 10;
    *(char *)(_p_lld_env + 0xd9) = (char)uVar3;
    iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
    if (-1 < *(short *)(uVar3 * 0x14 + iVar7)) {
      (**(code **)(_r_plf_funcs_p + 0xc))
                (*(undefined1 *)(_p_lld_env + 0xd9),*(undefined1 *)(_p_lld_env + 0xd8),"lld.c",0x4e3
                 ,*(code **)(_r_plf_funcs_p + 0xc));
    }
    bVar2 = *(byte *)(_p_lld_env + 0xd9);
    iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
    if (*(short *)((uint)bVar2 * 0x14 + 0x12 + iVar7) != 0) {
      (**(code **)(_r_plf_funcs_p + 0xc))
                (*(undefined1 *)(_p_lld_env + 0xd9),*(undefined1 *)(_p_lld_env + 0xd8),"lld.c",0x4e4
                 ,*(code **)(_r_plf_funcs_p + 0xc));
    }
    bVar2 = *(byte *)(_p_lld_env + 0xd9);
    iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
    iVar7 = _p_lld_env;
    *(short *)((uint)bVar2 * 0x14 + 0x12 + iVar6) = (short)iVar5;
    iVar5 = (uint)*(byte *)(iVar7 + 0xd9) * 0x14;
    iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar4 = *(ushort *)(iVar7 + iVar5);
    iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar5 + iVar7) = uVar4 & 0x7fff;
  }
  iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  iVar7 = (uint)bVar1 * 0x14;
  if ((*(short *)(iVar5 + iVar7) < 0) &&
     (iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc)),
     *(ushort *)(iVar7 + 0xc + iVar5) >> 0xb == param_1)) {
    iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar4 = (*(short *)(iVar7 + 2 + iVar5) >> 0xf) + 1;
  }
  else {
    uVar4 = 0;
  }
  return uVar4 & 1;
}

