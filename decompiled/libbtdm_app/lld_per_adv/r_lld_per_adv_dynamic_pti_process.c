/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> lld_per_adv.o -> r_lld_per_adv_dynamic_pti_process
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_per_adv_dynamic_pti_process(int param_1)

{
  ushort uVar1;
  uint uVar2;
  uint *puVar3;
  int iVar4;
  int iVar5;
  code *pcVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uStack_54;
  uint uStack_50;
  int iStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  
  uStack_54 = 0;
  uStack_50 = 0;
  iStack_4c = 0;
  uStack_48 = 0;
  uStack_44 = 0;
  if ((param_1 != 0) &&
     (iVar4 = (**(code **)(_r_modules_funcs_p + 0x198))(*(code **)(_r_modules_funcs_p + 0x198)),
     iVar4 != 0)) {
    (**(code **)(_r_ip_funcs_p + 0x794))(param_1,&uStack_54,*(code **)(_r_ip_funcs_p + 0x794));
    uVar2 = uStack_50;
    uVar8 = (uint)*(byte *)(param_1 + 0x52);
    uVar9 = uStack_50 >> 0x18;
    uVar7 = uVar8 * 9 & 0xff;
    if (0xb < uVar8) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_per_adv.c",0x29bb,*(code **)(_r_plf_funcs_p + 8));
    }
    if ((uVar2 & 0xf0000000) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_per_adv.c",0x29bd,*(code **)(_r_plf_funcs_p + 8));
    }
    iVar4 = iStack_4c;
    puVar3 = (uint *)((uVar8 + 0x1800c4cb) * 4);
    *puVar3 = *puVar3 & 0xfffffff0 | uVar9;
    if (0xb < uVar8) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_per_adv.c",0x295a,*(code **)(_r_plf_funcs_p + 8));
    }
    if ((iVar4 << 0x1d & 0xc0000000U) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_per_adv.c",0x295c,*(code **)(_r_plf_funcs_p + 8));
    }
    *puVar3 = *puVar3 & 0xdfffffff | iVar4 << 0x1d;
    uVar9 = uStack_54 & 0xff;
    if (0xb < uVar8) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_per_adv.c",0x299b,*(code **)(_r_plf_funcs_p + 8));
    }
    uVar9 = uVar9 << 8;
    if ((uVar9 & 0xf000) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_per_adv.c",0x299d,*(code **)(_r_plf_funcs_p + 8));
    }
    *puVar3 = *puVar3 & 0xfffff0ff | uVar9;
    uVar9 = uStack_54 >> 8;
    if (0xb < uVar8) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_per_adv.c",0x294a,*(code **)(_r_plf_funcs_p + 8));
    }
    uVar9 = uVar9 << 0x1e;
    if ((int)uVar9 < 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_per_adv.c",0x294c,*(code **)(_r_plf_funcs_p + 8));
    }
    *puVar3 = *puVar3 & 0xbfffffff | uVar9;
    uVar9 = (uStack_54 >> 0x18) << 8;
    if ((uVar9 & 0xf000) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_per_adv.c",0x33f,*(code **)(_r_plf_funcs_p + 8));
    }
    iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    iVar4 = uVar7 * 0xe + 10;
    uVar1 = *(ushort *)(iVar5 + iVar4);
    iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar5 + iVar4) = uVar1 & 0xf0ff | (ushort)uVar9;
    uVar9 = (uStack_50 & 0xff) << 0xc;
    if ((uVar9 & 0xffffefff) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_per_adv.c",0x333,*(code **)(_r_plf_funcs_p + 8));
    }
    iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar1 = *(ushort *)(iVar5 + iVar4);
    iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar5 + iVar4) = uVar1 & 0xefff | (ushort)uVar9;
    do {
      uVar7 = uVar7 + 1 & 0xff;
      uVar9 = (uStack_50 >> 8 & 0xff) << 8;
      if ((uVar9 & 0xfffff0ff) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_per_adv.c",0x33f,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar5 = uVar7 * 0xe + 10;
      uVar1 = *(ushort *)(iVar4 + iVar5);
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar4 + iVar5) = uVar1 & 0xf0ff | (ushort)uVar9;
      uVar9 = (uStack_50 >> 0x10 & 0xff) << 0xc;
      if ((uVar9 & 0xffffefff) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_per_adv.c",0x333,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar1 = *(ushort *)(iVar4 + iVar5);
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      pcVar6 = *(code **)(_r_plf_funcs_p + 0xbc);
      *(ushort *)(iVar4 + iVar5) = uVar1 & 0xefff | (ushort)uVar9;
      iVar4 = (*pcVar6)(0x1400,pcVar6);
    } while ((*(ushort *)(iVar4 + uVar7 * 0xe) & 0x7fff) != 0);
  }
  return;
}

