/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_sync.o -> r_lld_sync_insert_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_sync_insert_eco
               (int param_1,undefined1 *param_2,uint param_3,ushort param_4,undefined1 *param_5)

{
  byte bVar1;
  ushort uVar2;
  undefined2 uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  ushort uVar8;
  uint uVar9;
  
  iVar6 = *(int *)(&lld_sync_env + param_1 * 4);
  *(undefined4 *)(iVar6 + 0x10) = 0x9c4;
  if (*(char *)(iVar6 + 0x57) == '\0') {
    *(undefined1 *)(iVar6 + 0x16) = 0x1f;
  }
  iVar7 = *(int *)(&lld_sync_env + param_1 * 4);
  iVar6 = r_sch_arb_insert(iVar7);
  if (iVar6 == 0) {
    if ((param_4 & 0xfc) != 0) {
      r_assert_err(0x10000,0x18e);
      r_assert_err(0,0x10000,399);
    }
    iVar6 = r_emi_get_mem_addr_by_offset(0x400);
    param_1 = param_1 * 0x5a;
    *(ushort *)(iVar6 + param_1 + 4) =
         (ushort)((int)(short)param_4 << 4) | (ushort)((int)(short)param_4 << 2) | 0x1000;
    iVar6 = param_1 + 0x28;
    if (*(char *)(iVar7 + 99) == '\x01') {
      bVar1 = *(byte *)(iVar7 + 0x30);
      if (0x3f < bVar1) {
        r_assert_err(0,0x10000,0x395);
      }
      iVar4 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar4 + param_1 + 0x16) = bVar1 | 0x4000;
      uVar8 = 0x672 - *(short *)(iVar7 + 0x52);
      if (0x7ff < uVar8) {
        r_assert_err(0,0x10000,0x6c0);
      }
      iVar4 = r_emi_get_mem_addr_by_offset(0x400);
      uVar2 = *(ushort *)(iVar4 + iVar6);
      iVar4 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar4 + iVar6) = uVar8 | uVar2 & 0xf800;
      bVar1 = *(byte *)(iVar7 + 0x30);
      if ((bVar1 & 0xc0) != 0) {
        r_assert_err(0,0x10000,0x635);
      }
      iVar6 = r_emi_get_mem_addr_by_offset(0x400);
      uVar8 = *(ushort *)(iVar6 + param_1 + 0x26);
      iVar6 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar6 + param_1 + 0x26) = uVar8 & 0x3ff | (ushort)bVar1 << 10;
    }
    else {
      if ((*(char *)(iVar7 + 0x61) != '\0') &&
         ((ushort)(*(short *)(iVar7 + 0x4a) - *(short *)(iVar7 + 0x50)) < 0x7fff)) {
        uVar3 = *(undefined2 *)(iVar7 + 0x5c);
        iVar4 = r_emi_get_mem_addr_by_offset(0x400);
        *(undefined2 *)(param_1 + 0x22 + iVar4) = uVar3;
        uVar3 = *(undefined2 *)(iVar7 + 0x5e);
        iVar4 = r_emi_get_mem_addr_by_offset(0x400);
        *(undefined2 *)(param_1 + 0x24 + iVar4) = uVar3;
        bVar1 = *(byte *)(iVar7 + 0x60);
        iVar4 = r_emi_get_mem_addr_by_offset(0x400);
        uVar8 = *(ushort *)(iVar4 + param_1 + 0x26);
        iVar4 = r_emi_get_mem_addr_by_offset(0x400);
        *(ushort *)(iVar4 + param_1 + 0x26) = bVar1 & 0x1f | uVar8 & 0xffe0;
        *(undefined1 *)(iVar7 + 0x61) = 0;
      }
      iVar4 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(param_1 + 0x16 + iVar4) = 0xc000;
      iVar4 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar6 + iVar4) = 0x3e72;
      iVar6 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(param_1 + 0x46 + iVar6) = 0;
    }
    uVar9 = *(uint *)(iVar7 + 0x10);
    uVar5 = (uint)_sdk_cfg_priv_opts;
    iVar6 = r_emi_get_mem_addr_by_offset(0x400);
    *(short *)(param_1 + 0x20 + iVar6) = (short)((((uVar9 >> 1) - uVar5) + 0x270) / 0x271);
    if (param_3 < 0x4000) {
      iVar6 = r_emi_get_mem_addr_by_offset(0x400);
      *(short *)(iVar6 + param_1 + 0x1a) = (short)(param_3 + 0x25 >> 1);
    }
    else {
      uVar5 = (param_3 + 0x270) / 0x271;
      if ((int)(uVar5 << 0x10) < 0) {
        r_assert_err(0,0x10000,0x4ab);
      }
      iVar6 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar6 + param_1 + 0x1a) = (ushort)uVar5 | 0x8000;
    }
    uVar3 = *(undefined2 *)(iVar7 + 0x4a);
    iVar6 = r_emi_get_mem_addr_by_offset(0x400);
    *(undefined2 *)(param_1 + 0x50 + iVar6) = uVar3;
    *(undefined1 *)(iVar7 + 0x5b) = 0;
    *param_5 = 1;
  }
  else {
    *param_2 = 1;
    if (*(char *)(iVar7 + 99) == '\x01') {
      r_lld_sync_trunc_ind(param_1);
      *(undefined1 *)(iVar7 + 99) = 0;
    }
  }
  return;
}

