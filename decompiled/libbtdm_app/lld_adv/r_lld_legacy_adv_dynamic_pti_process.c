/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_adv.o -> r_lld_legacy_adv_dynamic_pti_process
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_legacy_adv_dynamic_pti_process(int param_1)

{
  ushort uVar1;
  byte bVar2;
  uint uVar3;
  uint *puVar4;
  int iVar5;
  code *pcVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  undefined4 local_30;
  uint uStack_2c;
  undefined4 uStack_28;
  undefined2 uStack_24;
  
  uVar9 = (uint)*(byte *)(param_1 + 0x87);
  local_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  (**(code **)(_r_ip_funcs_p + 0x754))(&local_30,*(code **)(_r_ip_funcs_p + 0x754));
  bVar2 = (byte)local_30;
  if ((local_30 & 0xf0) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x33f,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  iVar7 = (uVar9 * 9 & 0xff) * 0xe;
  iVar10 = iVar7 + 10;
  uVar1 = *(ushort *)(iVar5 + iVar10);
  iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(ushort *)(iVar5 + iVar10) = uVar1 & 0xf0ff | (ushort)bVar2 << 8;
  bVar2 = local_30._1_1_;
  if ((local_30 & 0xfe00) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x333,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar1 = *(ushort *)(iVar5 + iVar10);
  iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  pcVar6 = *(code **)(_r_plf_funcs_p + 0xbc);
  *(ushort *)(iVar5 + iVar10) = uVar1 & 0xefff | (ushort)bVar2 << 0xc;
  iVar5 = (*pcVar6)(0x1400,pcVar6);
  if ((*(ushort *)(iVar5 + iVar7) & 0x7fff) != 0) {
    iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar1 = *(ushort *)(iVar7 + iVar5);
    bVar2 = (byte)local_30;
    if ((local_30 & 0xf0) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x33f,*(code **)(_r_plf_funcs_p + 8));
    }
    iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    iVar5 = (((uVar1 & 0x7fff) - 0x1400) / 0xe) * 0xe + 10;
    uVar1 = *(ushort *)(iVar7 + iVar5);
    iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar7 + iVar5) = uVar1 & 0xf0ff | (ushort)bVar2 << 8;
    bVar2 = local_30._1_1_;
    if ((local_30 & 0xfe00) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x333,*(code **)(_r_plf_funcs_p + 8));
    }
    iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar1 = *(ushort *)(iVar7 + iVar5);
    iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar7 + iVar5) = uVar1 & 0xefff | (ushort)bVar2 << 0xc;
  }
  uVar8 = local_30 >> 0x10 & 0xff;
  if (0xb < uVar9) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x29bb,*(code **)(_r_plf_funcs_p + 8));
  }
  if (0xf < uVar8) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x29bd,*(code **)(_r_plf_funcs_p + 8));
  }
  uVar3 = local_30;
  puVar4 = (uint *)((uVar9 + 0x1800c4cb) * 4);
  *puVar4 = *puVar4 & 0xfffffff0 | uVar8;
  uVar8 = local_30 >> 0x18;
  if (0xb < uVar9) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x295a,*(code **)(_r_plf_funcs_p + 8));
  }
  if ((uVar3 & 0x6000000) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x295c,*(code **)(_r_plf_funcs_p + 8));
  }
  uVar3 = uStack_2c;
  *puVar4 = *puVar4 & 0xdfffffff | uVar8 << 0x1d;
  uVar8 = uStack_2c & 0xff;
  if (0xb < uVar9) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x299b,*(code **)(_r_plf_funcs_p + 8));
  }
  if ((uVar3 & 0xf0) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x299d,*(code **)(_r_plf_funcs_p + 8));
  }
  uVar3 = uStack_2c;
  *puVar4 = *puVar4 & 0xfffff0ff | uVar8 << 8;
  uVar8 = uStack_2c >> 8;
  if (0xb < uVar9) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x294a,*(code **)(_r_plf_funcs_p + 8));
  }
  if ((uVar3 & 0x200) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x294c,*(code **)(_r_plf_funcs_p + 8));
  }
  *puVar4 = *puVar4 & 0xbfffffff | uVar8 << 0x1e;
  return;
}

