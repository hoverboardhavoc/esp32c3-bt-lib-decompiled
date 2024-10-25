/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld_sync.o -> r_lld_sync_insert_eco
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
  ushort uVar7;
  uint uVar8;
  uint uVar9;
  
  iVar6 = *(int *)(&lld_sync_env + param_1 * 4);
  *(undefined4 *)(iVar6 + 0x10) = 0x9c4;
  if (*(char *)(iVar6 + 0x57) == '\0') {
    *(undefined1 *)(iVar6 + 0x16) = 0x1f;
  }
  iVar6 = *(int *)(&lld_sync_env + param_1 * 4);
  iVar4 = r_sch_arb_insert(iVar6);
  if (iVar4 == 0) {
    if ((param_4 << 4 & 0xffffffcfU) != 0) {
      r_assert_err("lld_sync.c",0x18e);
    }
    if ((param_4 << 2 & 0xfffffff3U) != 0) {
      r_assert_err(0,"lld_sync.c",399);
    }
    iVar4 = r_emi_get_mem_addr_by_offset(0x400);
    param_1 = param_1 * 0x5a;
    *(ushort *)(iVar4 + param_1 + 4) = (ushort)(param_4 << 4) | (ushort)(param_4 << 2) | 0x1000;
    iVar4 = param_1 + 0x28;
    if (*(char *)(iVar6 + 99) == '\x01') {
      bVar1 = *(byte *)(iVar6 + 0x30);
      if ((bVar1 & 0xc0) != 0) {
        r_assert_err(0,"lld_sync.c",0x395);
      }
      iVar5 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar5 + param_1 + 0x16) = bVar1 | 0x4000;
      uVar7 = 0x672 - *(short *)(iVar6 + 0x52);
      if ((uVar7 & 0xf800) != 0) {
        r_assert_err(0,"lld_sync.c",0x6c0);
      }
      iVar5 = r_emi_get_mem_addr_by_offset(0x400);
      uVar2 = *(ushort *)(iVar5 + iVar4);
      iVar5 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar5 + iVar4) = uVar2 & 0xf800 | uVar7;
      uVar9 = (uint)*(byte *)(iVar6 + 0x30) << 10;
      if ((uVar9 & 0x30000) != 0) {
        r_assert_err(0,"lld_sync.c",0x635);
      }
      iVar4 = r_emi_get_mem_addr_by_offset(0x400);
      uVar7 = *(ushort *)(iVar4 + param_1 + 0x26);
      iVar4 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar4 + param_1 + 0x26) = uVar7 & 0x3ff | (ushort)uVar9;
    }
    else {
      if ((*(char *)(iVar6 + 0x61) != '\0') &&
         ((ushort)(*(short *)(iVar6 + 0x4a) - *(short *)(iVar6 + 0x50)) < 0x7fff)) {
        uVar3 = *(undefined2 *)(iVar6 + 0x5c);
        iVar5 = r_emi_get_mem_addr_by_offset(0x400);
        *(undefined2 *)(iVar5 + param_1 + 0x22) = uVar3;
        uVar3 = *(undefined2 *)(iVar6 + 0x5e);
        iVar5 = r_emi_get_mem_addr_by_offset(0x400);
        *(undefined2 *)(iVar5 + param_1 + 0x24) = uVar3;
        bVar1 = *(byte *)(iVar6 + 0x60);
        iVar5 = r_emi_get_mem_addr_by_offset(0x400);
        uVar7 = *(ushort *)(iVar5 + param_1 + 0x26);
        iVar5 = r_emi_get_mem_addr_by_offset(0x400);
        *(ushort *)(iVar5 + param_1 + 0x26) = uVar7 & 0xffe0 | bVar1 & 0x1f;
        *(undefined1 *)(iVar6 + 0x61) = 0;
      }
      iVar5 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar5 + param_1 + 0x16) = 0xc000;
      iVar5 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar5 + iVar4) = 0x3e72;
      iVar4 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar4 + param_1 + 0x46) = 0;
    }
    uVar8 = *(uint *)(iVar6 + 0x10);
    uVar9 = (uint)_sdk_cfg_priv_opts;
    iVar4 = r_emi_get_mem_addr_by_offset(0x400);
    *(short *)(iVar4 + param_1 + 0x20) = (short)((((uVar8 >> 1) - uVar9) + 0x270) / 0x271);
    if (param_3 < 0x4000) {
      iVar4 = r_emi_get_mem_addr_by_offset(0x400);
      uVar7 = (ushort)(param_3 + 0x25 >> 1);
    }
    else {
      uVar9 = (param_3 + 0x270) / 0x271;
      if ((int)(uVar9 << 0x10) < 0) {
        r_assert_err(0,"lld_sync.c",0x4ab);
      }
      iVar4 = r_emi_get_mem_addr_by_offset(0x400);
      uVar7 = (ushort)uVar9 | 0x8000;
    }
    *(ushort *)(iVar4 + param_1 + 0x1a) = uVar7;
    uVar3 = *(undefined2 *)(iVar6 + 0x4a);
    iVar4 = r_emi_get_mem_addr_by_offset(0x400);
    *(undefined2 *)(param_1 + 0x50 + iVar4) = uVar3;
    *(undefined1 *)(iVar6 + 0x5b) = 0;
    *param_5 = 1;
  }
  else {
    *param_2 = 1;
    if (*(char *)(iVar6 + 99) == '\x01') {
      r_lld_sync_trunc_ind(param_1);
      *(undefined1 *)(iVar6 + 99) = 0;
    }
  }
  return;
}

