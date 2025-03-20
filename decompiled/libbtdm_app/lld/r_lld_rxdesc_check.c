/*
 * Last changed at upstream commit d2414a5dd958b32ca53382b441d24d97a0345a55
 * https://github.com/espressif/esp32c3-bt-lib/commit/d2414a5dd958b32ca53382b441d24d97a0345a55
 * Upstream date: 2025-03-20 20:11:19 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(03d0f8a6)
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
                (*(undefined1 *)(_p_lld_env + 0xd9),*(undefined1 *)(_p_lld_env + 0xd8),"lld.c",0x4de
                 ,*(code **)(_r_plf_funcs_p + 0xc));
    }
    bVar2 = *(byte *)(_p_lld_env + 0xd9);
    iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
    if (*(short *)((uint)bVar2 * 0x14 + 0x12 + iVar7) != 0) {
      (**(code **)(_r_plf_funcs_p + 0xc))
                (*(undefined1 *)(_p_lld_env + 0xd9),*(undefined1 *)(_p_lld_env + 0xd8),"lld.c",0x4df
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

