/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_ext_adv_dynamic_pti_process
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_ext_adv_dynamic_pti_process(int param_1,undefined4 param_2,undefined4 param_3)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  uint *puVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  byte bStack_48;
  byte bStack_47;
  byte bStack_45;
  byte bStack_44;
  byte bStack_43;
  byte bStack_42;
  
  memset(&bStack_48,0,0x18);
  uVar6 = (uint)*(byte *)(param_1 + 0x87);
  uVar1 = *(ushort *)(param_1 + 0x74);
  r_lld_ext_adv_dynamic_pti_get(param_1,param_2,param_3,&bStack_48);
  uVar8 = uVar6 * 9 & 0xff;
  uVar10 = uVar8 + 1 & 0xff;
  if (0xb < uVar6) {
    r_assert_err(0,0x10000,0x29bb);
  }
  if ((bStack_43 & 0xf0) != 0) {
    r_assert_err(0,0x10000,0x29bd);
  }
  puVar5 = (uint *)((uVar6 + 0x1800c4cb) * 4);
  *puVar5 = *puVar5 & 0xfffffff0 | (uint)bStack_43;
  if (0xb < uVar6) {
    r_assert_err(0,0x10000,0x295a);
  }
  if (((uint)bStack_42 << 0x1d & 0xc0000000) != 0) {
    r_assert_err(0,0x10000,0x295c);
  }
  *puVar5 = *puVar5 & 0xdfffffff | (uint)bStack_42 << 0x1d;
  if (0xb < uVar6) {
    r_assert_err(0,0x10000,0x299b);
  }
  if (((uint)bStack_48 << 8 & 0xf000) != 0) {
    r_assert_err(0,0x10000,0x299d);
  }
  *puVar5 = *puVar5 & 0xfffff0ff | (uint)bStack_48 << 8;
  if (0xb < uVar6) {
    r_assert_err(0,0x10000,0x294a);
  }
  if ((int)((uint)bStack_47 << 0x1e) < 0) {
    r_assert_err(0,0x10000,0x294c);
  }
  *puVar5 = *puVar5 & 0xbfffffff | (uint)bStack_47 << 0x1e;
  if ((bStack_45 & 0xf0) != 0) {
    r_assert_err(0,0x10000,0x33f);
  }
  iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
  iVar9 = uVar8 * 0xe + 10;
  uVar2 = *(ushort *)(iVar7 + iVar9);
  uVar3 = (ushort)(((uint)bStack_45 << 0x18) >> 0x10);
  iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
  *(ushort *)(iVar7 + iVar9) = uVar2 & 0xf0ff | uVar3;
  if ((bStack_44 & 0xfe) != 0) {
    r_assert_err(0,0x10000,0x333);
  }
  iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
  uVar2 = *(ushort *)(iVar7 + iVar9);
  uVar4 = (ushort)(((uint)bStack_44 << 0x1c) >> 0x10);
  iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
  *(ushort *)(iVar7 + iVar9) = uVar4 | uVar2 & 0xefff;
  if ((bStack_45 & 0xf0) != 0) {
    r_assert_err(0,0x10000,0x33f);
  }
  iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
  iVar9 = uVar10 * 0xe + 10;
  uVar2 = *(ushort *)(iVar7 + iVar9);
  iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
  *(ushort *)(iVar7 + iVar9) = uVar3 | uVar2 & 0xf0ff;
  if ((bStack_44 & 0xfe) != 0) {
    r_assert_err(0,0x10000,0x333);
  }
  iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
  uVar2 = *(ushort *)(iVar7 + iVar9);
  iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
  *(ushort *)(iVar7 + iVar9) = uVar4 | uVar2 & 0xefff;
  r_lld_ext_adv_dynamic_aux_pti_process_eco(uVar1 & 3,uVar10,&bStack_48);
  return;
}

