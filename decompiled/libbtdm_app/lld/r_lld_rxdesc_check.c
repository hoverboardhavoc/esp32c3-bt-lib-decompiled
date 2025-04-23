/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  code *pcVar7;
  int iVar8;
  
  bVar1 = *(byte *)(_p_lld_env + 0xd8);
  while (*(char *)(_p_lld_env + 0x101) == '\0') {
    iVar5 = (**(code **)(_r_ip_funcs_p + 0x100))(*(code **)(_r_ip_funcs_p + 0x100));
    pcVar7 = *(code **)(_r_plf_funcs_p + 0xbc);
    if (iVar5 == 0) break;
    uVar3 = (*(byte *)(_p_lld_env + 0xd9) + 1) % 10;
    *(char *)(_p_lld_env + 0xd9) = (char)uVar3;
    iVar8 = (*pcVar7)(0x1000,pcVar7);
    if (-1 < *(short *)(uVar3 * 0x14 + iVar8)) {
      (**(code **)(_r_plf_funcs_p + 0xc))
                (*(undefined1 *)(_p_lld_env + 0xd9),*(undefined1 *)(_p_lld_env + 0xd8),"lld.c",0x4de
                 ,*(code **)(_r_plf_funcs_p + 0xc));
    }
    bVar2 = *(byte *)(_p_lld_env + 0xd9);
    iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
    if (*(short *)((uint)bVar2 * 0x14 + 0x12 + iVar8) != 0) {
      (**(code **)(_r_plf_funcs_p + 0xc))
                (*(undefined1 *)(_p_lld_env + 0xd9),*(undefined1 *)(_p_lld_env + 0xd8),"lld.c",0x4df
                 ,*(code **)(_r_plf_funcs_p + 0xc));
    }
    bVar2 = *(byte *)(_p_lld_env + 0xd9);
    iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
    iVar8 = _p_lld_env;
    *(short *)((uint)bVar2 * 0x14 + 0x12 + iVar6) = (short)iVar5;
    iVar5 = (uint)*(byte *)(iVar8 + 0xd9) * 0x14;
    iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar4 = *(ushort *)(iVar8 + iVar5);
    iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar5 + iVar8) = uVar4 & 0x7fff;
  }
  iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  iVar8 = (uint)bVar1 * 0x14;
  if ((*(short *)(iVar5 + iVar8) < 0) &&
     (iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc)),
     *(ushort *)(iVar8 + 0xc + iVar5) >> 0xb == param_1)) {
    iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar4 = *(ushort *)(iVar8 + 2 + iVar5) >> 0xf ^ 1;
  }
  else {
    uVar4 = 0;
  }
  return uVar4;
}

