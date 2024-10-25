/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> lld_sync.o -> r_lld_sync_insert_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_sync_insert_eco
               (int param_1,undefined1 *param_2,uint param_3,int param_4,undefined1 *param_5)

{
  byte bVar1;
  ushort uVar2;
  undefined2 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  ushort uVar8;
  uint uVar9;
  uint uVar10;
  
  iVar7 = *(int *)(&lld_sync_env + param_1 * 4);
  *(undefined4 *)(iVar7 + 0x10) = 0x9c4;
  if (*(char *)(iVar7 + 0x57) == '\0') {
    *(undefined1 *)(iVar7 + 0x16) = 0x1f;
  }
  iVar7 = *(int *)(&lld_sync_env + param_1 * 4);
  iVar4 = (**(code **)(_r_ip_funcs_p + 0x6b0))(iVar7,*(code **)(_r_ip_funcs_p + 0x6b0));
  if (iVar4 == 0) {
    if ((param_4 << 4 & 0xffffffcfU) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))("lld_sync.c",0x18e,*(code **)(_r_plf_funcs_p + 8));
    }
    if ((param_4 << 2 & 0xfffffff3U) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_sync.c",399,*(code **)(_r_plf_funcs_p + 8));
    }
    iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    param_1 = param_1 * 0x5a;
    *(ushort *)(iVar4 + param_1 + 4) = (ushort)(param_4 << 4) | (ushort)(param_4 << 2) | 0x1000;
    iVar4 = param_1 + 0x28;
    if (*(char *)(iVar7 + 99) == '\x01') {
      bVar1 = *(byte *)(iVar7 + 0x30);
      if ((bVar1 & 0xc0) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_sync.c",0x395,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar5 + param_1 + 0x16) = bVar1 | 0x4000;
      uVar8 = 0x672 - *(short *)(iVar7 + 0x52);
      if ((uVar8 & 0xf800) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_sync.c",0x6c0,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar2 = *(ushort *)(iVar5 + iVar4);
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar5 + iVar4) = uVar2 & 0xf800 | uVar8;
      uVar10 = (uint)*(byte *)(iVar7 + 0x30) << 10;
      if ((uVar10 & 0x30000) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_sync.c",0x635,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar8 = *(ushort *)(iVar4 + param_1 + 0x26);
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar4 + param_1 + 0x26) = uVar8 & 0x3ff | (ushort)uVar10;
    }
    else {
      if ((*(char *)(iVar7 + 0x61) != '\0') &&
         ((ushort)(*(short *)(iVar7 + 0x4a) - *(short *)(iVar7 + 0x50)) < 0x7fff)) {
        uVar3 = *(undefined2 *)(iVar7 + 0x5c);
        iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
        *(undefined2 *)(iVar5 + param_1 + 0x22) = uVar3;
        uVar3 = *(undefined2 *)(iVar7 + 0x5e);
        iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
        iVar5 = _r_plf_funcs_p;
        *(undefined2 *)(iVar6 + param_1 + 0x24) = uVar3;
        bVar1 = *(byte *)(iVar7 + 0x60);
        iVar5 = (**(code **)(iVar5 + 0xbc))(0x400,*(code **)(iVar5 + 0xbc));
        uVar8 = *(ushort *)(iVar5 + param_1 + 0x26);
        iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
        *(ushort *)(iVar5 + param_1 + 0x26) = uVar8 & 0xffe0 | bVar1 & 0x1f;
        *(undefined1 *)(iVar7 + 0x61) = 0;
      }
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar5 + param_1 + 0x16) = 0xc000;
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar5 + iVar4) = 0x3e72;
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar4 + param_1 + 0x46) = 0;
    }
    uVar9 = *(uint *)(iVar7 + 0x10);
    uVar10 = (uint)_sdk_cfg_priv_opts;
    iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(short *)(iVar4 + param_1 + 0x20) = (short)((((uVar9 >> 1) - uVar10) + 0x270) / 0x271);
    if (param_3 < 0x4000) {
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar8 = (ushort)(param_3 + 0x25 >> 1);
    }
    else {
      uVar10 = (param_3 + 0x270) / 0x271;
      if ((int)(uVar10 << 0x10) < 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_sync.c",0x4ab,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar8 = (ushort)uVar10 | 0x8000;
    }
    iVar5 = _r_plf_funcs_p;
    *(ushort *)(iVar4 + param_1 + 0x1a) = uVar8;
    uVar3 = *(undefined2 *)(iVar7 + 0x4a);
    iVar4 = (**(code **)(iVar5 + 0xbc))(0x400,*(code **)(iVar5 + 0xbc));
    *(undefined2 *)(param_1 + 0x50 + iVar4) = uVar3;
    *(undefined1 *)(iVar7 + 0x5b) = 0;
    *param_5 = 1;
  }
  else {
    *param_2 = 1;
    if (*(char *)(iVar7 + 99) == '\x01') {
      (**(code **)(_r_ip_funcs_p + 0x178))(param_1,*(code **)(_r_ip_funcs_p + 0x178));
      *(undefined1 *)(iVar7 + 99) = 0;
    }
  }
  return;
}

