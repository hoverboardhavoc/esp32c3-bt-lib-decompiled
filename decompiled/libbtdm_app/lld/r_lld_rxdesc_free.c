/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld.o -> r_lld_rxdesc_free
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_rxdesc_free(void)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  code *pcVar6;
  int iVar7;
  
  bVar1 = *(byte *)(_p_lld_env + 0xd8);
  iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  if (*(short *)((uint)bVar1 * 0x14 + 0x12 + iVar3) != 0) {
    bVar1 = *(byte *)(_p_lld_env + 0xd8);
    pcVar6 = *(code **)(_r_ip_funcs_p + 0x108);
    iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
    (*pcVar6)(*(undefined2 *)((uint)bVar1 * 0x14 + 0x12 + iVar3));
  }
  bVar1 = *(byte *)(_p_lld_env + 0xd8);
  iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  iVar3 = _p_lld_env;
  *(undefined2 *)((uint)bVar1 * 0x14 + 0x12 + iVar4) = 0;
  iVar7 = (uint)*(byte *)(iVar3 + 0xd8) * 0x14;
  iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar2 = *(ushort *)(iVar3 + iVar7);
  iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  iVar3 = _p_lld_env;
  *(ushort *)(iVar7 + iVar4) = uVar2 | 0x8000;
  bVar1 = *(byte *)(iVar3 + 0xd8);
  iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  iVar7 = (uint)bVar1 * 0x14 + 2;
  uVar2 = *(ushort *)(iVar3 + iVar7);
  iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  iVar3 = _p_lld_env;
  *(ushort *)(iVar4 + iVar7) = uVar2 | 0x8000;
  *(char *)(iVar3 + 0xd8) = (char)((*(byte *)(iVar3 + 0xd8) + 1) % 10);
  if (*(char *)(iVar3 + 0x101) == '\0') {
    while (iVar3 = (**(code **)(_r_ip_funcs_p + 0x100))(*(code **)(_r_ip_funcs_p + 0x100)),
          iVar3 != 0) {
      uVar5 = (*(byte *)(_p_lld_env + 0xd9) + 1) % 10;
      *(char *)(_p_lld_env + 0xd9) = (char)uVar5;
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
      if (-1 < *(short *)(uVar5 * 0x14 + iVar4)) {
        (**(code **)(_r_plf_funcs_p + 0xc))
                  (*(undefined1 *)(_p_lld_env + 0xd9),*(undefined1 *)(_p_lld_env + 0xd8),"lld.c",
                   0x4c5,*(code **)(_r_plf_funcs_p + 0xc));
      }
      bVar1 = *(byte *)(_p_lld_env + 0xd9);
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
      if (*(short *)((uint)bVar1 * 0x14 + 0x12 + iVar4) != 0) {
        (**(code **)(_r_plf_funcs_p + 0xc))
                  (*(undefined1 *)(_p_lld_env + 0xd9),*(undefined1 *)(_p_lld_env + 0xd8),"lld.c",
                   0x4c6,*(code **)(_r_plf_funcs_p + 0xc));
      }
      bVar1 = *(byte *)(_p_lld_env + 0xd9);
      iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar4 = _p_lld_env;
      *(short *)((uint)bVar1 * 0x14 + 0x12 + iVar7) = (short)iVar3;
      iVar4 = (uint)*(byte *)(iVar4 + 0xd9) * 0x14;
      iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar2 = *(ushort *)(iVar3 + iVar4);
      iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar4 + iVar3) = uVar2 & 0x7fff;
    }
  }
  return;
}

