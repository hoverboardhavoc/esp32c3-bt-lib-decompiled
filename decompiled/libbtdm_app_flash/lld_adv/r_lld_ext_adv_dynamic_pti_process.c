/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
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
  uint uVar4;
  int iVar5;
  uint *puVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  byte bStack_48;
  byte bStack_47;
  byte bStack_45;
  byte bStack_44;
  byte bStack_43;
  byte bStack_42;
  
  memset(&bStack_48,0,0x18);
  uVar8 = (uint)*(byte *)(param_1 + 0x87);
  uVar1 = *(ushort *)(param_1 + 0x74);
  r_lld_ext_adv_dynamic_pti_get(param_1,param_2,param_3,&bStack_48);
  uVar4 = uVar8 * 9 & 0xff;
  uVar9 = uVar4 + 1 & 0xff;
  if (0xb < uVar8) {
    r_assert_err(0,0x10000,0x29bb);
  }
  if (0xf < bStack_43) {
    r_assert_err(0,0x10000,0x29bd);
  }
  puVar6 = (uint *)((uVar8 + 0x1800c4cb) * 4);
  *puVar6 = *puVar6 & 0xfffffff0 | (uint)bStack_43;
  if (0xb < uVar8) {
    r_assert_err(0,0x10000,0x295a);
  }
  if ((bStack_42 & 6) != 0) {
    r_assert_err(0,0x10000,0x295c);
  }
  *puVar6 = *puVar6 & 0xdfffffff | (uint)bStack_42 << 0x1d;
  if (0xb < uVar8) {
    r_assert_err(0,0x10000,0x299b);
  }
  if ((bStack_48 & 0xf0) != 0) {
    r_assert_err(0,0x10000,0x299d);
  }
  *puVar6 = *puVar6 & 0xfffff0ff | (uint)bStack_48 << 8;
  if (0xb < uVar8) {
    r_assert_err(0,0x10000,0x294a);
  }
  if ((bStack_47 & 2) != 0) {
    r_assert_err(0,0x10000,0x294c);
  }
  *puVar6 = *puVar6 & 0xbfffffff | (uint)bStack_47 << 0x1e;
  if ((bStack_45 & 0xf0) != 0) {
    r_assert_err(0,0x10000,0x33f);
  }
  iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
  iVar5 = uVar4 * 0xe + 10;
  uVar2 = *(ushort *)(iVar7 + iVar5);
  iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
  *(ushort *)(iVar7 + iVar5) = (ushort)bStack_45 << 8 | uVar2 & 0xf0ff;
  if ((bStack_44 & 0xfe) != 0) {
    r_assert_err(0,0x10000,0x333);
  }
  iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
  uVar2 = *(ushort *)(iVar7 + iVar5);
  iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
  uVar3 = (ushort)(((uint)bStack_44 << 0x1c) >> 0x10);
  *(ushort *)(iVar5 + iVar7) = uVar3 | uVar2 & 0xefff;
  if ((bStack_45 & 0xf0) != 0) {
    r_assert_err(0,0x10000,0x33f);
  }
  iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
  iVar5 = uVar9 * 0xe + 10;
  uVar2 = *(ushort *)(iVar7 + iVar5);
  iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
  *(ushort *)(iVar7 + iVar5) = (ushort)bStack_45 << 8 | uVar2 & 0xf0ff;
  if ((bStack_44 & 0xfe) != 0) {
    r_assert_err(0,0x10000,0x333);
  }
  iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
  uVar2 = *(ushort *)(iVar7 + iVar5);
  iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
  *(ushort *)(iVar7 + iVar5) = uVar3 | uVar2 & 0xefff;
  r_lld_ext_adv_dynamic_aux_pti_process_eco(uVar1 & 3,uVar9,&bStack_48);
  return;
}

