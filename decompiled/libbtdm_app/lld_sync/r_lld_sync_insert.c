/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_sync.o -> r_lld_sync_insert
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_sync_insert(int param_1,undefined1 *param_2,uint param_3,ushort param_4,
                      undefined1 *param_5)

{
  byte bVar1;
  ushort uVar2;
  undefined2 uVar3;
  int iVar4;
  int iVar5;
  code *pcVar6;
  uint uVar7;
  int iVar8;
  ushort uVar9;
  uint uVar10;
  
  iVar8 = *(int *)(&lld_sync_env + param_1 * 4);
  iVar4 = (**(code **)(_r_ip_funcs_p + 0x6b0))(iVar8,*(code **)(_r_ip_funcs_p + 0x6b0));
  if (iVar4 == 0) {
    if ((param_4 & 0xfc) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0x10000,0x18e,*(code **)(_r_plf_funcs_p + 8));
      (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,399,*(code **)(_r_plf_funcs_p + 8));
    }
    iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    iVar4 = _r_plf_funcs_p;
    param_1 = param_1 * 0x5a;
    *(ushort *)(iVar5 + param_1 + 4) =
         (ushort)((int)(short)param_4 << 4) | (ushort)((int)(short)param_4 << 2) | 0x1000;
    iVar5 = param_1 + 0x28;
    if (*(char *)(iVar8 + 99) == '\x01') {
      bVar1 = *(byte *)(iVar8 + 0x30);
      if (0x3f < bVar1) {
        pcVar6 = *(code **)(iVar4 + 8);
        (*pcVar6)(0,0x10000,0x395,pcVar6);
      }
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar4 + param_1 + 0x16) = bVar1 | 0x4000;
      uVar9 = 0x672 - *(short *)(iVar8 + 0x52);
      if (0x7ff < uVar9) {
        (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x6c0,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar2 = *(ushort *)(iVar4 + iVar5);
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar4 + iVar5) = uVar9 | uVar2 & 0xf800;
      bVar1 = *(byte *)(iVar8 + 0x30);
      if ((bVar1 & 0xc0) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x635,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar9 = *(ushort *)(iVar4 + param_1 + 0x26);
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar4 + param_1 + 0x26) = uVar9 & 0x3ff | (ushort)bVar1 << 10;
    }
    else {
      if ((*(char *)(iVar8 + 0x61) != '\0') &&
         ((ushort)(*(short *)(iVar8 + 0x4a) - *(short *)(iVar8 + 0x50)) < 0x7fff)) {
        uVar3 = *(undefined2 *)(iVar8 + 0x5c);
        pcVar6 = *(code **)(iVar4 + 0xbc);
        iVar4 = (*pcVar6)(0x400,pcVar6);
        *(undefined2 *)(param_1 + 0x22 + iVar4) = uVar3;
        uVar3 = *(undefined2 *)(iVar8 + 0x5e);
        iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
        *(undefined2 *)(param_1 + 0x24 + iVar4) = uVar3;
        bVar1 = *(byte *)(iVar8 + 0x60);
        iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
        uVar9 = *(ushort *)(iVar4 + param_1 + 0x26);
        iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
        *(ushort *)(iVar4 + param_1 + 0x26) = bVar1 & 0x1f | uVar9 & 0xffe0;
        *(undefined1 *)(iVar8 + 0x61) = 0;
      }
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(param_1 + 0x16 + iVar4) = 0xc000;
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar5 + iVar4) = 0x3e72;
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(param_1 + 0x46 + iVar4) = 0;
    }
    uVar10 = *(uint *)(iVar8 + 0x10);
    uVar7 = (uint)_sdk_cfg_priv_opts;
    iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(short *)(param_1 + 0x20 + iVar4) = (short)((((uVar10 >> 1) - uVar7) + 0x270) / 0x271);
    if (param_3 < 0x4000) {
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(short *)(iVar4 + param_1 + 0x1a) = (short)(param_3 + 0x25 >> 1);
    }
    else {
      uVar7 = (param_3 + 0x270) / 0x271;
      if ((int)(uVar7 << 0x10) < 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x4ab,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar4 + param_1 + 0x1a) = (ushort)uVar7 | 0x8000;
    }
    uVar3 = *(undefined2 *)(iVar8 + 0x4a);
    iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(undefined2 *)(param_1 + 0x50 + iVar4) = uVar3;
    *(undefined1 *)(iVar8 + 0x5b) = 0;
    *param_5 = 1;
  }
  else {
    *param_2 = 1;
    if (*(char *)(iVar8 + 99) == '\x01') {
      (**(code **)(_r_ip_funcs_p + 0x178))(param_1,*(code **)(_r_ip_funcs_p + 0x178));
      *(undefined1 *)(iVar8 + 99) = 0;
    }
  }
  return;
}

