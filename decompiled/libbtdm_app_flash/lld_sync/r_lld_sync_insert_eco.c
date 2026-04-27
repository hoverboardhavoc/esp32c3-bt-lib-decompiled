/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
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
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int iVar10;
  ushort uVar11;
  uint uVar12;
  uint uVar13;
  
  iVar10 = *(int *)(&lld_sync_env + param_1 * 4);
  *(undefined4 *)(iVar10 + 0x10) = 0x9c4;
  if (*(char *)(iVar10 + 0x57) == '\0') {
    *(undefined1 *)(iVar10 + 0x16) = 0x1f;
  }
  iVar10 = *(int *)(&lld_sync_env + param_1 * 4);
  iVar4 = r_sch_arb_insert(iVar10);
  if (iVar4 == 0) {
    if ((param_4 << 4 & 0xffffffcfU) != 0) {
      r_assert_err(0x10000,0x18e);
    }
    if ((param_4 << 2 & 0xfffffff3U) != 0) {
      r_assert_err(0,0x10000,399);
    }
    iVar5 = r_emi_get_mem_addr_by_offset(0x400);
    iVar4 = param_1 * 0x5a;
    *(ushort *)(iVar5 + iVar4 + 4) = (ushort)(param_4 << 4) | (ushort)(param_4 << 2) | 0x1000;
    iVar5 = iVar4 + 0x28;
    if (*(char *)(iVar10 + 99) == '\x01') {
      bVar1 = *(byte *)(iVar10 + 0x30);
      if ((bVar1 & 0xc0) != 0) {
        r_assert_err(0,0x10000,0x395);
      }
      iVar6 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar6 + iVar4 + 0x16) = bVar1 | 0x4000;
      uVar11 = 0x672 - *(short *)(iVar10 + 0x52);
      if ((uVar11 & 0xf800) != 0) {
        r_assert_err(0,0x10000,0x6c0);
      }
      iVar6 = r_emi_get_mem_addr_by_offset(0x400);
      uVar2 = *(ushort *)(iVar6 + iVar5);
      iVar6 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar6 + iVar5) = uVar11 | uVar2 & 0xf800;
      uVar13 = (uint)*(byte *)(iVar10 + 0x30) << 10;
      if ((uVar13 & 0x30000) != 0) {
        r_assert_err(0,0x10000,0x635);
      }
      iVar5 = r_emi_get_mem_addr_by_offset(0x400);
      uVar11 = *(ushort *)(iVar5 + iVar4 + 0x26);
      iVar5 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar5 + iVar4 + 0x26) = uVar11 & 0x3ff | (ushort)uVar13;
    }
    else {
      if ((*(char *)(iVar10 + 0x61) != '\0') &&
         ((ushort)(*(short *)(iVar10 + 0x4a) - *(short *)(iVar10 + 0x50)) < 0x7fff)) {
        uVar3 = *(undefined2 *)(iVar10 + 0x5c);
        iVar6 = r_emi_get_mem_addr_by_offset(0x400);
        *(undefined2 *)(iVar4 + 0x22 + iVar6) = uVar3;
        uVar3 = *(undefined2 *)(iVar10 + 0x5e);
        iVar6 = r_emi_get_mem_addr_by_offset(0x400);
        *(undefined2 *)(iVar4 + 0x24 + iVar6) = uVar3;
        bVar1 = *(byte *)(iVar10 + 0x60);
        iVar6 = r_emi_get_mem_addr_by_offset(0x400);
        uVar11 = *(ushort *)(iVar6 + iVar4 + 0x26);
        iVar6 = r_emi_get_mem_addr_by_offset(0x400);
        *(ushort *)(iVar6 + iVar4 + 0x26) = uVar11 & 0xffe0 | bVar1 & 0x1f;
        *(undefined1 *)(iVar10 + 0x61) = 0;
      }
      iVar6 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar4 + 0x16 + iVar6) = 0xc000;
      iVar6 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar5 + iVar6) = 0x3e72;
      iVar5 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar4 + 0x46 + iVar5) = 0;
    }
    uVar12 = *(uint *)(iVar10 + 0x10);
    uVar13 = (uint)_sdk_cfg_priv_opts;
    iVar5 = r_emi_get_mem_addr_by_offset(0x400);
    *(short *)(iVar4 + 0x20 + iVar5) = (short)((((uVar12 >> 1) - uVar13) + 0x270) / 0x271);
    if (param_3 < 0x4000) {
      iVar5 = r_emi_get_mem_addr_by_offset(0x400);
      *(short *)(iVar5 + iVar4 + 0x1a) = (short)(param_3 + 0x25 >> 1);
    }
    else {
      uVar13 = (param_3 + 0x270) / 0x271;
      if ((uVar13 >> 0xf & 1) != 0) {
        r_assert_err(0,0x10000,0x4ab);
      }
      iVar5 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar5 + iVar4 + 0x1a) = (ushort)uVar13 | 0x8000;
    }
    uVar3 = *(undefined2 *)(iVar10 + 0x4a);
    iVar5 = r_emi_get_mem_addr_by_offset(0x400);
    *(undefined2 *)(iVar4 + 0x50 + iVar5) = uVar3;
    *(undefined1 *)(iVar10 + 0x5b) = 0;
    *param_5 = 1;
    uVar9 = *(undefined4 *)(iVar10 + 0x10);
    uVar8 = *(undefined4 *)(iVar10 + 4);
    uVar13 = (uint)*(ushort *)(iVar10 + 0x4a) | param_1 << 0x10 |
             (uint)*(byte *)(iVar10 + 0x16) << 0x18;
    uVar7 = 0x4045015b;
  }
  else {
    *param_2 = 1;
    if (*(char *)(iVar10 + 99) == '\x01') {
      r_lld_sync_trunc_ind(param_1);
      *(undefined1 *)(iVar10 + 99) = 0;
    }
    uVar9 = *(undefined4 *)(iVar10 + 0x10);
    uVar8 = *(undefined4 *)(iVar10 + 4);
    uVar13 = (uint)*(ushort *)(iVar10 + 0x4a) | param_1 << 0x10 |
             (uint)*(byte *)(iVar10 + 0x16) << 0x18;
    uVar7 = 0x6045015c;
  }
  r_ble_log_internal_x3(uVar7,uVar8,uVar9,uVar13);
  return;
}

