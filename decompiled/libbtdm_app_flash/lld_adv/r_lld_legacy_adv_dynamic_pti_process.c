/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_legacy_adv_dynamic_pti_process
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_legacy_adv_dynamic_pti_process(int param_1)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint *puVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  int iVar17;
  uint local_50;
  uint uStack_4c;
  undefined4 uStack_48;
  undefined2 uStack_44;
  
  uVar14 = (uint)*(byte *)(param_1 + 0x87);
  local_50 = 0;
  uStack_4c = 0;
  uStack_48 = 0;
  uStack_44 = 0;
  r_lld_legacy_adv_dynamic_pti_get(&local_50);
  uVar9 = uStack_4c;
  uVar8 = local_50;
  uVar13 = local_50 & 0xff;
  uVar5 = local_50 >> 8;
  uVar16 = local_50 >> 0x10 & 0xff;
  uVar4 = local_50 & 0xf0;
  uVar6 = local_50 >> 0x18;
  uVar15 = uStack_4c & 0xff;
  uVar7 = uStack_4c >> 8;
  if ((local_50 & 0xf0) != 0) {
    r_assert_err(0,0x10000,0x33f);
  }
  iVar12 = r_emi_get_mem_addr_by_offset(0x1400);
  iVar10 = (uVar14 * 9 & 0xff) * 0xe;
  iVar17 = iVar10 + 10;
  uVar1 = *(ushort *)(iVar12 + iVar17);
  iVar12 = r_emi_get_mem_addr_by_offset(0x1400);
  uVar2 = (ushort)(uVar13 << 8);
  *(ushort *)(iVar12 + iVar17) = uVar2 | uVar1 & 0xf0ff;
  if ((uVar8 & 0xfe00) != 0) {
    r_assert_err(0,0x10000,0x333);
  }
  iVar12 = r_emi_get_mem_addr_by_offset(0x1400);
  uVar1 = *(ushort *)(iVar12 + iVar17);
  iVar12 = r_emi_get_mem_addr_by_offset(0x1400);
  uVar3 = (ushort)((uVar5 << 0x1c) >> 0x10);
  *(ushort *)(iVar17 + iVar12) = uVar3 | uVar1 & 0xefff;
  iVar12 = r_emi_get_mem_addr_by_offset(0x1400);
  if ((*(ushort *)(iVar12 + iVar10) & 0x7fff) != 0) {
    iVar12 = r_emi_get_mem_addr_by_offset(0x1400);
    uVar1 = *(ushort *)(iVar10 + iVar12);
    if (uVar4 != 0) {
      r_assert_err(0,0x10000,0x33f);
    }
    iVar12 = r_emi_get_mem_addr_by_offset(0x1400);
    iVar10 = (((uVar1 & 0x7fff) - 0x1400) / 0xe) * 0xe + 10;
    uVar1 = *(ushort *)(iVar12 + iVar10);
    iVar12 = r_emi_get_mem_addr_by_offset(0x1400);
    *(ushort *)(iVar12 + iVar10) = uVar2 | uVar1 & 0xf0ff;
    if ((uVar8 & 0xfe00) != 0) {
      r_assert_err(0,0x10000,0x333);
    }
    iVar12 = r_emi_get_mem_addr_by_offset(0x1400);
    uVar1 = *(ushort *)(iVar12 + iVar10);
    iVar12 = r_emi_get_mem_addr_by_offset(0x1400);
    *(ushort *)(iVar12 + iVar10) = uVar3 | uVar1 & 0xefff;
  }
  if (0xb < uVar14) {
    r_assert_err(0,0x10000,0x29bb);
  }
  if (0xf < uVar16) {
    r_assert_err(0,0x10000,0x29bd);
  }
  puVar11 = (uint *)((uVar14 + 0x1800c4cb) * 4);
  *puVar11 = *puVar11 & 0xfffffff0 | uVar16;
  if (0xb < uVar14) {
    r_assert_err(0,0x10000,0x295a);
  }
  if ((uVar8 & 0x6000000) != 0) {
    r_assert_err(0,0x10000,0x295c);
  }
  *puVar11 = *puVar11 & 0xdfffffff | uVar6 << 0x1d;
  if (0xb < uVar14) {
    r_assert_err(0,0x10000,0x299b);
  }
  if ((uVar9 & 0xf0) != 0) {
    r_assert_err(0,0x10000,0x299d);
  }
  *puVar11 = *puVar11 & 0xfffff0ff | uVar15 << 8;
  if (0xb < uVar14) {
    r_assert_err(0,0x10000,0x294a);
  }
  if ((uVar9 & 0x200) != 0) {
    r_assert_err(0,0x10000,0x294c);
  }
  *puVar11 = *puVar11 & 0xbfffffff | uVar7 << 0x1e;
  return;
}

