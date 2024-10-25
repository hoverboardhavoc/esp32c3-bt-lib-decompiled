/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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
  int iVar3;
  uint *puVar4;
  int iVar5;
  code *pcVar6;
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
  iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  iVar3 = (uVar7 * 9 & 0xff) * 0xe;
  iVar8 = iVar3 + 10;
  uVar1 = *(ushort *)(iVar5 + iVar8);
  iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(ushort *)(iVar5 + iVar8) = uVar1 & 0xf0ff | (ushort)uVar9;
  uVar9 = (local_40 >> 8 & 0xff) << 0xc;
  if ((uVar9 & 0xffffefff) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x333,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar1 = *(ushort *)(iVar5 + iVar8);
  iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  pcVar6 = *(code **)(_r_plf_funcs_p + 0xbc);
  *(ushort *)(iVar5 + iVar8) = uVar1 & 0xefff | (ushort)uVar9;
  iVar5 = (*pcVar6)(0x1400,pcVar6);
  if ((*(ushort *)(iVar5 + iVar3) & 0x7fff) != 0) {
    iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar1 = *(ushort *)(iVar5 + iVar3);
    uVar9 = (local_40 & 0xff) << 8;
    if ((uVar9 & 0xfffff0ff) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x33f,*(code **)(_r_plf_funcs_p + 8));
    }
    iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    iVar3 = (((uVar1 & 0x7fff) - 0x1400) / 0xe) * 0xe + 10;
    uVar1 = *(ushort *)(iVar5 + iVar3);
    iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar5 + iVar3) = uVar1 & 0xf0ff | (ushort)uVar9;
    uVar9 = (local_40 >> 8 & 0xff) << 0xc;
    if ((uVar9 & 0xffffefff) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x333,*(code **)(_r_plf_funcs_p + 8));
    }
    iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar1 = *(ushort *)(iVar5 + iVar3);
    iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar5 + iVar3) = uVar1 & 0xefff | (ushort)uVar9;
  }
  uVar2 = local_40;
  uVar9 = local_40 >> 0x10;
  if (0xb < uVar7) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x29bb,*(code **)(_r_plf_funcs_p + 8));
  }
  if ((uVar2 & 0xf00000) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x29bd,*(code **)(_r_plf_funcs_p + 8));
  }
  puVar4 = (uint *)((uVar7 + 0x1800c4cb) * 4);
  *puVar4 = *puVar4 & 0xfffffff0 | uVar9 & 0xff;
  uVar9 = local_40 >> 0x18;
  if (0xb < uVar7) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x295a,*(code **)(_r_plf_funcs_p + 8));
  }
  uVar9 = uVar9 << 0x1d;
  if ((uVar9 & 0xc0000000) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x295c,*(code **)(_r_plf_funcs_p + 8));
  }
  *puVar4 = *puVar4 & 0xdfffffff | uVar9;
  uVar9 = uStack_3c & 0xff;
  if (0xb < uVar7) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x299b,*(code **)(_r_plf_funcs_p + 8));
  }
  uVar9 = uVar9 << 8;
  if ((uVar9 & 0xf000) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x299d,*(code **)(_r_plf_funcs_p + 8));
  }
  *puVar4 = *puVar4 & 0xfffff0ff | uVar9;
  uVar9 = uStack_3c >> 8;
  if (0xb < uVar7) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x294a,*(code **)(_r_plf_funcs_p + 8));
  }
  uVar9 = uVar9 << 0x1e;
  if ((int)uVar9 < 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x294c,*(code **)(_r_plf_funcs_p + 8));
  }
  *puVar4 = *puVar4 & 0xbfffffff | uVar9;
  return;
}

