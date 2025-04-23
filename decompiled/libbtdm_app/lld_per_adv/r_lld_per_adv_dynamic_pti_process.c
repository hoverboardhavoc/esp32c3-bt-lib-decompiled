/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
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
  uint uVar3;
  byte bVar4;
  uint *puVar5;
  int iVar6;
  code *pcVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  undefined4 uStack_44;
  undefined4 uStack_40;
  uint uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  
  uStack_44 = 0;
  uStack_40 = 0;
  uStack_3c = 0;
  uStack_38 = 0;
  uStack_34 = 0;
  if ((param_1 != 0) &&
     (iVar6 = (**(code **)(_r_modules_funcs_p + 0x198))(*(code **)(_r_modules_funcs_p + 0x198)),
     iVar6 != 0)) {
    (**(code **)(_r_ip_funcs_p + 0x794))(param_1,&uStack_44,*(code **)(_r_ip_funcs_p + 0x794));
    uVar9 = (uint)*(byte *)(param_1 + 0x52);
    uVar2 = uStack_40 >> 0x18;
    uVar8 = uVar9 * 9 & 0xff;
    if (0xb < uVar9) {
      (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x29bb,*(code **)(_r_plf_funcs_p + 8));
    }
    if (0xf < uVar2) {
      (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x29bd,*(code **)(_r_plf_funcs_p + 8));
    }
    uVar11 = uStack_3c;
    puVar5 = (uint *)((uVar9 + 0x1800c4cb) * 4);
    *puVar5 = *puVar5 & 0xfffffff0 | uVar2;
    if (0xb < uVar9) {
      (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x295a,*(code **)(_r_plf_funcs_p + 8));
    }
    if ((uVar11 & 6) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x295c,*(code **)(_r_plf_funcs_p + 8));
    }
    uVar2 = uStack_44;
    *puVar5 = *puVar5 & 0xdfffffff | uVar11 << 0x1d;
    uVar11 = uStack_44 & 0xff;
    if (0xb < uVar9) {
      (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x299b,*(code **)(_r_plf_funcs_p + 8));
    }
    if ((uVar2 & 0xf0) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x299d,*(code **)(_r_plf_funcs_p + 8));
    }
    uVar3 = uStack_44;
    *puVar5 = *puVar5 & 0xfffff0ff | uVar11 << 8;
    uVar2 = uStack_44 >> 8;
    if (0xb < uVar9) {
      (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x294a,*(code **)(_r_plf_funcs_p + 8));
    }
    if ((uVar3 & 0x200) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x294c,*(code **)(_r_plf_funcs_p + 8));
    }
    *puVar5 = *puVar5 & 0xbfffffff | uVar2 << 0x1e;
    bVar4 = uStack_44._3_1_;
    if ((uStack_44 & 0xf0000000) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x33f,*(code **)(_r_plf_funcs_p + 8));
    }
    iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    iVar10 = uVar8 * 0xe + 10;
    uVar1 = *(ushort *)(iVar6 + iVar10);
    iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar6 + iVar10) = uVar1 & 0xf0ff | (ushort)bVar4 << 8;
    bVar4 = (byte)uStack_40;
    if ((uStack_40 & 0xfe) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x333,*(code **)(_r_plf_funcs_p + 8));
    }
    iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar1 = *(ushort *)(iVar6 + iVar10);
    iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar6 + iVar10) = uVar1 & 0xefff | (ushort)bVar4 << 0xc;
    do {
      bVar4 = uStack_40._1_1_;
      uVar8 = uVar8 + 1 & 0xff;
      if ((uStack_40 & 0xf000) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x33f,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar10 = uVar8 * 0xe + 10;
      uVar1 = *(ushort *)(iVar6 + iVar10);
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar6 + iVar10) = uVar1 & 0xf0ff | (ushort)bVar4 << 8;
      bVar4 = uStack_40._2_1_;
      if ((uStack_40 & 0xfe0000) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x333,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar1 = *(ushort *)(iVar6 + iVar10);
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      pcVar7 = *(code **)(_r_plf_funcs_p + 0xbc);
      *(ushort *)(iVar6 + iVar10) = uVar1 & 0xefff | (ushort)bVar4 << 0xc;
      iVar6 = (*pcVar7)(0x1400,pcVar7);
    } while ((*(ushort *)(iVar6 + uVar8 * 0xe) & 0x7fff) != 0);
  }
  return;
}

