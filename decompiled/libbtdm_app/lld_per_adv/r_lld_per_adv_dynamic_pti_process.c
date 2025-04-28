/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  code *pcVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
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
    uVar7 = (uint)*(byte *)(param_1 + 0x52);
    uVar8 = uStack_50 >> 0x18;
    uVar6 = uVar7 * 9 & 0xff;
    if (0xb < uVar7) {
      (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x29bb,*(code **)(_r_plf_funcs_p + 8));
    }
    if ((uVar2 & 0xf0000000) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x29bd,*(code **)(_r_plf_funcs_p + 8));
    }
    iVar4 = iStack_4c;
    puVar3 = (uint *)((uVar7 + 0x1800c4cb) * 4);
    *puVar3 = *puVar3 & 0xfffffff0 | uVar8;
    if (0xb < uVar7) {
      (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x295a,*(code **)(_r_plf_funcs_p + 8));
    }
    if ((iVar4 << 0x1d & 0xc0000000U) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x295c,*(code **)(_r_plf_funcs_p + 8));
    }
    *puVar3 = *puVar3 & 0xdfffffff | iVar4 << 0x1d;
    uVar8 = uStack_54 & 0xff;
    if (0xb < uVar7) {
      (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x299b,*(code **)(_r_plf_funcs_p + 8));
    }
    uVar8 = uVar8 << 8;
    if ((uVar8 & 0xf000) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x299d,*(code **)(_r_plf_funcs_p + 8));
    }
    *puVar3 = *puVar3 & 0xfffff0ff | uVar8;
    uVar8 = uStack_54 >> 8;
    if (0xb < uVar7) {
      (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x294a,*(code **)(_r_plf_funcs_p + 8));
    }
    uVar8 = uVar8 << 0x1e;
    if ((int)uVar8 < 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x294c,*(code **)(_r_plf_funcs_p + 8));
    }
    *puVar3 = *puVar3 & 0xbfffffff | uVar8;
    uVar8 = (uStack_54 >> 0x18) << 8;
    if ((uVar8 & 0xf000) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x33f,*(code **)(_r_plf_funcs_p + 8));
    }
    iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    iVar9 = uVar6 * 0xe + 10;
    uVar1 = *(ushort *)(iVar4 + iVar9);
    iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar4 + iVar9) = uVar1 & 0xf0ff | (ushort)uVar8;
    uVar8 = (uStack_50 & 0xff) << 0xc;
    if ((uVar8 & 0xffffefff) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x333,*(code **)(_r_plf_funcs_p + 8));
    }
    iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar1 = *(ushort *)(iVar4 + iVar9);
    iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar4 + iVar9) = uVar1 & 0xefff | (ushort)uVar8;
    do {
      uVar6 = uVar6 + 1 & 0xff;
      uVar8 = (uStack_50 >> 8 & 0xff) << 8;
      if ((uVar8 & 0xfffff0ff) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x33f,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar9 = uVar6 * 0xe + 10;
      uVar1 = *(ushort *)(iVar4 + iVar9);
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar4 + iVar9) = uVar1 & 0xf0ff | (ushort)uVar8;
      uVar8 = (uStack_50 >> 0x10 & 0xff) << 0xc;
      if ((uVar8 & 0xffffefff) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x333,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar1 = *(ushort *)(iVar4 + iVar9);
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      pcVar5 = *(code **)(_r_plf_funcs_p + 0xbc);
      *(ushort *)(iVar4 + iVar9) = uVar1 & 0xefff | (ushort)uVar8;
      iVar4 = (*pcVar5)(0x1400,pcVar5);
    } while ((*(ushort *)(iVar4 + uVar6 * 0xe) & 0x7fff) != 0);
  }
  return;
}

