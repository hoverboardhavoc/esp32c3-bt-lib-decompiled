/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_sync.o -> r_lld_sync_insert
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_sync_insert(int param_1,undefined1 *param_2,uint param_3,int param_4,undefined1 *param_5)

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
  iVar4 = r_sch_arb_insert(iVar6);
  if (iVar4 == 0) {
    if ((param_4 << 4 & 0xffffffcfU) != 0) {
      r_assert_err(0x10000,0x18e);
    }
    if ((param_4 << 2 & 0xfffffff3U) != 0) {
      r_assert_err(0,0x10000,399);
    }
    iVar4 = r_emi_get_mem_addr_by_offset(0x400);
    param_1 = param_1 * 0x5a;
    *(ushort *)(iVar4 + param_1 + 4) = (ushort)(param_4 << 4) | (ushort)(param_4 << 2) | 0x1000;
    iVar4 = param_1 + 0x28;
    if (*(char *)(iVar6 + 99) == '\x01') {
      bVar1 = *(byte *)(iVar6 + 0x30);
      if ((bVar1 & 0xc0) != 0) {
        r_assert_err(0,0x10000,0x395);
      }
      iVar5 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar5 + param_1 + 0x16) = bVar1 | 0x4000;
      uVar7 = 0x672 - *(short *)(iVar6 + 0x52);
      if ((uVar7 & 0xf800) != 0) {
        r_assert_err(0,0x10000,0x6c0);
      }
      iVar5 = r_emi_get_mem_addr_by_offset(0x400);
      uVar2 = *(ushort *)(iVar5 + iVar4);
      iVar5 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar5 + iVar4) = uVar7 | uVar2 & 0xf800;
      uVar9 = (uint)*(byte *)(iVar6 + 0x30) << 10;
      if ((uVar9 & 0x30000) != 0) {
        r_assert_err(0,0x10000,0x635);
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
        *(undefined2 *)(param_1 + 0x22 + iVar5) = uVar3;
        uVar3 = *(undefined2 *)(iVar6 + 0x5e);
        iVar5 = r_emi_get_mem_addr_by_offset(0x400);
        *(undefined2 *)(param_1 + 0x24 + iVar5) = uVar3;
        bVar1 = *(byte *)(iVar6 + 0x60);
        iVar5 = r_emi_get_mem_addr_by_offset(0x400);
        uVar7 = *(ushort *)(iVar5 + param_1 + 0x26);
        iVar5 = r_emi_get_mem_addr_by_offset(0x400);
        *(ushort *)(iVar5 + param_1 + 0x26) = uVar7 & 0xffe0 | bVar1 & 0x1f;
        *(undefined1 *)(iVar6 + 0x61) = 0;
      }
      iVar5 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(param_1 + 0x16 + iVar5) = 0xc000;
      iVar5 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar4 + iVar5) = 0x3e72;
      iVar4 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(param_1 + 0x46 + iVar4) = 0;
    }
    uVar8 = *(uint *)(iVar6 + 0x10);
    uVar9 = (uint)_sdk_cfg_priv_opts;
    iVar4 = r_emi_get_mem_addr_by_offset(0x400);
    *(short *)(param_1 + 0x20 + iVar4) = (short)((((uVar8 >> 1) - uVar9) + 0x270) / 0x271);
    if (param_3 < 0x4000) {
      iVar4 = r_emi_get_mem_addr_by_offset(0x400);
      *(short *)(iVar4 + param_1 + 0x1a) = (short)(param_3 + 0x25 >> 1);
    }
    else {
      uVar9 = (param_3 + 0x270) / 0x271;
      if ((uVar9 >> 0xf & 1) != 0) {
        r_assert_err(0,0x10000,0x4ab);
      }
      iVar4 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar4 + param_1 + 0x1a) = (ushort)uVar9 | 0x8000;
    }
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

