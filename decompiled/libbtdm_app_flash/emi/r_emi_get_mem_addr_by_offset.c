/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> emi.o -> r_emi_get_mem_addr_by_offset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int r_emi_get_mem_addr_by_offset(uint param_1)

{
  int iVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = param_1 >> 10;
  if (0x32 < uVar5) {
    r_assert_param(uVar5,0x10000,0x146);
  }
  iVar3 = uVar5 * 4;
  uVar4 = (uint)(byte)(&em_base_reg_lut)[iVar3];
  if (uVar4 < 0x38) {
    if (uVar4 < 0x30) {
      iVar1 = 0x481;
      goto _L103;
    }
  }
  else {
    r_assert_err(0,0x10000,0x27b9);
  }
  iVar1 = 0x488;
_L103:
  puVar2 = (uint *)((iVar1 + 0x1800c000 + uVar4) * 4);
  if ((uint)*(ushort *)(&DAT_0001201a + iVar3) != (*puVar2 >> 0x12) << 2) {
    r_assert_param(0x10000,0x14b);
  }
  iVar3 = param_1 - *(ushort *)(&DAT_0001201a + iVar3);
  if (iVar3 < 0) {
    r_assert_param(iVar3,uVar5,0x10000,0x14e);
  }
  if (0x37 < uVar4) {
    r_assert_err(0,0x10000,0x27c8);
  }
  return ((*puVar2 & 0x3ffff) << 2 | 0x3fc00000) + iVar3;
}

