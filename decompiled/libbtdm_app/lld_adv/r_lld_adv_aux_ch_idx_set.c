/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_adv.o -> r_lld_adv_aux_ch_idx_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_adv_aux_ch_idx_set(int param_1)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  
  iVar7 = *(int *)(&lld_adv_env + param_1 * 4);
  bVar1 = *(byte *)(iVar7 + 0x87);
  iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  iVar4 = ((uint)bVar1 * 9 & 0xff) * 0xe;
  if ((int)((uint)*(ushort *)(iVar4 + 6 + iVar5) << 0x13) < 0) {
    bVar1 = *(byte *)(iVar7 + 0x87);
    uVar6 = (**(code **)(_r_ip_funcs_p + 0x230))(*(code **)(_r_ip_funcs_p + 0x230));
    *(char *)(iVar7 + 0x91) = (char)uVar6;
    if (0x3f < uVar6) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x2ea,*(code **)(_r_plf_funcs_p + 8));
    }
    iVar4 = iVar4 + 8;
    iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar3 = *(ushort *)(iVar5 + iVar4);
    iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar5 + iVar4) = (ushort)uVar6 | uVar3 & 0xffc0;
    bVar2 = *(byte *)(iVar7 + 0x91);
    if ((bVar2 & 0xc0) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x635,*(code **)(_r_plf_funcs_p + 8));
    }
    iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    iVar5 = (uint)bVar1 * 0x5a + 0x26;
    uVar3 = *(ushort *)(iVar4 + iVar5);
    iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar4 + iVar5) = uVar3 & 0x3ff | (ushort)bVar2 << 10;
    uVar6 = 0;
    while( true ) {
      bVar1 = *(byte *)(iVar7 + 0x87);
      uVar6 = uVar6 + 1 & 0xff;
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar4 = ((uint)bVar1 * 9 + uVar6 & 0xff) * 0xe;
      uVar3 = *(ushort *)(iVar5 + iVar4);
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar5 + iVar4) = uVar3 & 0x7fff;
      if (uVar6 == *(byte *)(iVar7 + 0x92) - 1) break;
      bVar1 = *(byte *)(iVar7 + 0x91);
      if (0x3f < bVar1) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x2ea,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar3 = *(ushort *)(iVar5 + iVar4 + 8);
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar5 + iVar4 + 8) = (ushort)bVar1 | uVar3 & 0xffc0;
    }
  }
  return;
}

