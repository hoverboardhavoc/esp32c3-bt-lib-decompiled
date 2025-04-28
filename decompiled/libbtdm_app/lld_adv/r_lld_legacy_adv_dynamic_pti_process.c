/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
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
  uint uVar2;
  uint *puVar3;
  int iVar4;
  code *pcVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint local_40;
  uint uStack_3c;
  undefined4 uStack_38;
  undefined2 uStack_34;
  
  uVar7 = (uint)*(byte *)(param_1 + 0x87);
  local_40 = 0;
  uStack_3c = 0;
  uStack_38 = 0;
  uStack_34 = 0;
  (**(code **)(_r_ip_funcs_p + 0x754))(&local_40,*(code **)(_r_ip_funcs_p + 0x754));
  uVar9 = (local_40 & 0xff) << 8;
  if ((uVar9 & 0xf000) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x33f,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  iVar6 = (uVar7 * 9 & 0xff) * 0xe;
  iVar8 = iVar6 + 10;
  uVar1 = *(ushort *)(iVar4 + iVar8);
  iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(ushort *)(iVar4 + iVar8) = uVar1 & 0xf0ff | (ushort)uVar9;
  uVar9 = (local_40 >> 8 & 0xff) << 0xc;
  if ((uVar9 & 0xffffefff) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x333,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar1 = *(ushort *)(iVar4 + iVar8);
  iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  pcVar5 = *(code **)(_r_plf_funcs_p + 0xbc);
  *(ushort *)(iVar4 + iVar8) = uVar1 & 0xefff | (ushort)uVar9;
  iVar4 = (*pcVar5)(0x1400,pcVar5);
  if ((*(ushort *)(iVar4 + iVar6) & 0x7fff) != 0) {
    iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar1 = *(ushort *)(iVar6 + iVar4);
    uVar9 = (local_40 & 0xff) << 8;
    if ((uVar9 & 0xfffff0ff) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x33f,*(code **)(_r_plf_funcs_p + 8));
    }
    iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    iVar4 = (((uVar1 & 0x7fff) - 0x1400) / 0xe) * 0xe + 10;
    uVar1 = *(ushort *)(iVar6 + iVar4);
    iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar6 + iVar4) = uVar1 & 0xf0ff | (ushort)uVar9;
    uVar9 = (local_40 >> 8 & 0xff) << 0xc;
    if ((uVar9 & 0xffffefff) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x333,*(code **)(_r_plf_funcs_p + 8));
    }
    iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar1 = *(ushort *)(iVar6 + iVar4);
    iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar6 + iVar4) = uVar1 & 0xefff | (ushort)uVar9;
  }
  uVar2 = local_40;
  uVar9 = local_40 >> 0x10;
  if (0xb < uVar7) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x29bb,*(code **)(_r_plf_funcs_p + 8));
  }
  if ((uVar2 & 0xf00000) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x29bd,*(code **)(_r_plf_funcs_p + 8));
  }
  puVar3 = (uint *)((uVar7 + 0x1800c4cb) * 4);
  *puVar3 = *puVar3 & 0xfffffff0 | uVar9 & 0xff;
  uVar9 = local_40 >> 0x18;
  if (0xb < uVar7) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x295a,*(code **)(_r_plf_funcs_p + 8));
  }
  uVar9 = uVar9 << 0x1d;
  if ((uVar9 & 0xc0000000) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x295c,*(code **)(_r_plf_funcs_p + 8));
  }
  *puVar3 = *puVar3 & 0xdfffffff | uVar9;
  uVar9 = uStack_3c & 0xff;
  if (0xb < uVar7) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x299b,*(code **)(_r_plf_funcs_p + 8));
  }
  uVar9 = uVar9 << 8;
  if ((uVar9 & 0xf000) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x299d,*(code **)(_r_plf_funcs_p + 8));
  }
  *puVar3 = *puVar3 & 0xfffff0ff | uVar9;
  uVar9 = uStack_3c >> 8;
  if (0xb < uVar7) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x294a,*(code **)(_r_plf_funcs_p + 8));
  }
  uVar9 = uVar9 << 0x1e;
  if ((int)uVar9 < 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x294c,*(code **)(_r_plf_funcs_p + 8));
  }
  *puVar3 = *puVar3 & 0xbfffffff | uVar9;
  return;
}

