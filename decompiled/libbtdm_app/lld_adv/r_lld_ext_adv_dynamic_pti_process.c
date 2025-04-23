/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_adv.o -> r_lld_ext_adv_dynamic_pti_process
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_ext_adv_dynamic_pti_process(int param_1,undefined4 param_2,undefined4 param_3)

{
  ushort uVar1;
  ushort uVar2;
  byte bVar3;
  byte bVar4;
  uint *puVar5;
  int iVar6;
  code *pcVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  byte bStack_48;
  byte bStack_47;
  byte bStack_45;
  byte bStack_44;
  byte bStack_43;
  byte bStack_42;
  
  memset(&bStack_48,0,0x18);
  uVar11 = (uint)*(byte *)(param_1 + 0x87);
  uVar1 = *(ushort *)(param_1 + 0x74);
  (**(code **)(_r_ip_funcs_p + 0x75c))
            (param_1,param_2,param_3,&bStack_48,*(code **)(_r_ip_funcs_p + 0x75c));
  uVar9 = uVar11 * 9 & 0xff;
  uVar8 = uVar9 + 1 & 0xff;
  if (0xb < uVar11) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x29bb,*(code **)(_r_plf_funcs_p + 8));
  }
  if (0xf < bStack_43) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x29bd,*(code **)(_r_plf_funcs_p + 8));
  }
  puVar5 = (uint *)((uVar11 + 0x1800c4cb) * 4);
  *puVar5 = *puVar5 & 0xfffffff0 | (uint)bStack_43;
  if (0xb < uVar11) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x295a,*(code **)(_r_plf_funcs_p + 8));
  }
  if ((bStack_42 & 6) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x295c,*(code **)(_r_plf_funcs_p + 8));
  }
  *puVar5 = *puVar5 & 0xdfffffff | (uint)bStack_42 << 0x1d;
  if (0xb < uVar11) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x299b,*(code **)(_r_plf_funcs_p + 8));
  }
  if ((bStack_48 & 0xf0) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x299d,*(code **)(_r_plf_funcs_p + 8));
  }
  *puVar5 = *puVar5 & 0xfffff0ff | (uint)bStack_48 << 8;
  if (0xb < uVar11) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x294a,*(code **)(_r_plf_funcs_p + 8));
  }
  if ((bStack_47 & 2) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x294c,*(code **)(_r_plf_funcs_p + 8));
  }
  bVar3 = bStack_45;
  *puVar5 = *puVar5 & 0xbfffffff | (uint)bStack_47 << 0x1e;
  if ((bStack_45 & 0xf0) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x33f,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  iVar10 = uVar9 * 0xe + 10;
  uVar2 = *(ushort *)(iVar6 + iVar10);
  iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  bVar4 = bStack_44;
  *(ushort *)(iVar6 + iVar10) = uVar2 & 0xf0ff | (ushort)bVar3 << 8;
  if ((bStack_44 & 0xfe) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x333,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar2 = *(ushort *)(iVar6 + iVar10);
  iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(ushort *)(iVar6 + iVar10) = uVar2 & 0xefff | (ushort)bVar4 << 0xc;
  if ((bStack_45 & 0xf0) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x33f,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  iVar10 = uVar8 * 0xe + 10;
  uVar2 = *(ushort *)(iVar6 + iVar10);
  iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(ushort *)(iVar6 + iVar10) = uVar2 & 0xf0ff | (ushort)bStack_45 << 8;
  if ((bStack_44 & 0xfe) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x333,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar2 = *(ushort *)(iVar6 + iVar10);
  iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  pcVar7 = *(code **)(_r_ip_funcs_p + 0x760);
  *(ushort *)(iVar6 + iVar10) = uVar2 & 0xefff | (ushort)bStack_44 << 0xc;
  (*pcVar7)(uVar1 & 3,uVar8,&bStack_48,pcVar7);
  return;
}

