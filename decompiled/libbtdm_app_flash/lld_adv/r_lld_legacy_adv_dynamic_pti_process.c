/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
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
  int iVar6;
  uint *puVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  uint local_40;
  uint uStack_3c;
  undefined4 uStack_38;
  undefined2 uStack_34;
  
  uVar10 = (uint)*(byte *)(param_1 + 0x87);
  local_40 = 0;
  uStack_3c = 0;
  uStack_38 = 0;
  uStack_34 = 0;
  r_lld_legacy_adv_dynamic_pti_get(&local_40);
  uVar4 = local_40;
  uVar8 = local_40 & 0xf0;
  if (uVar8 != 0) {
    r_assert_err(0,0x10000,0x33f);
  }
  iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
  iVar6 = (uVar10 * 9 & 0xff) * 0xe;
  iVar11 = iVar6 + 10;
  uVar1 = *(ushort *)(iVar9 + iVar11);
  uVar2 = (ushort)((uVar4 << 0x18) >> 0x10);
  iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
  *(ushort *)(iVar9 + iVar11) = uVar2 | uVar1 & 0xf0ff;
  uVar5 = local_40 >> 8;
  uVar4 = uVar5 & 0xfe;
  if (uVar4 != 0) {
    r_assert_err(0,0x10000,0x333);
  }
  iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
  uVar1 = *(ushort *)(iVar9 + iVar11);
  uVar3 = (ushort)((uVar5 << 0x1c) >> 0x10);
  iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
  *(ushort *)(iVar9 + iVar11) = uVar3 | uVar1 & 0xefff;
  iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
  if ((*(ushort *)(iVar9 + iVar6) & 0x7fff) != 0) {
    iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
    uVar1 = *(ushort *)(iVar6 + iVar9);
    if (uVar8 != 0) {
      r_assert_err(0,0x10000,0x33f);
    }
    iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
    iVar6 = (((uVar1 & 0x7fff) - 0x1400) / 0xe) * 0xe + 10;
    uVar1 = *(ushort *)(iVar9 + iVar6);
    iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
    *(ushort *)(iVar9 + iVar6) = uVar2 | uVar1 & 0xf0ff;
    if (uVar4 != 0) {
      r_assert_err(0,0x10000,0x333);
    }
    iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
    uVar1 = *(ushort *)(iVar9 + iVar6);
    iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
    *(ushort *)(iVar9 + iVar6) = uVar3 | uVar1 & 0xefff;
  }
  uVar4 = local_40;
  uVar8 = local_40 >> 0x10;
  if (0xb < uVar10) {
    r_assert_err(0,0x10000,0x29bb);
  }
  if ((uVar4 & 0xf00000) != 0) {
    r_assert_err(0,0x10000,0x29bd);
  }
  puVar7 = (uint *)((uVar10 + 0x1800c4cb) * 4);
  *puVar7 = *puVar7 & 0xfffffff0 | uVar8 & 0xff;
  uVar8 = local_40 >> 0x18;
  if (0xb < uVar10) {
    r_assert_err(0,0x10000,0x295a);
  }
  uVar8 = uVar8 << 0x1d;
  if ((uVar8 & 0xc0000000) != 0) {
    r_assert_err(0,0x10000,0x295c);
  }
  *puVar7 = *puVar7 & 0xdfffffff | uVar8;
  uVar8 = uStack_3c & 0xff;
  if (0xb < uVar10) {
    r_assert_err(0,0x10000,0x299b);
  }
  uVar8 = uVar8 << 8;
  if ((uVar8 & 0xf000) != 0) {
    r_assert_err(0,0x10000,0x299d);
  }
  *puVar7 = *puVar7 & 0xfffff0ff | uVar8;
  uVar8 = uStack_3c >> 8;
  if (0xb < uVar10) {
    r_assert_err(0,0x10000,0x294a);
  }
  uVar8 = uVar8 << 0x1e;
  if ((int)uVar8 < 0) {
    r_assert_err(0,0x10000,0x294c);
  }
  *puVar7 = *puVar7 & 0xbfffffff | uVar8;
  return;
}

