/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_adv_aux_ch_idx_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_adv_aux_ch_idx_set(int param_1)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  
  iVar5 = *(int *)(&lld_adv_env + param_1 * 4);
  bVar1 = *(byte *)(iVar5 + 0x87);
  iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
  iVar4 = ((uint)bVar1 * 9 & 0xff) * 0xe;
  if ((int)((uint)*(ushort *)(iVar4 + 6 + iVar6) << 0x13) < 0) {
    bVar1 = *(byte *)(iVar5 + 0x87);
    uVar7 = r_lld_ch_idx_get_hack();
    *(char *)(iVar5 + 0x91) = (char)uVar7;
    if (0x3f < uVar7) {
      r_assert_err(0,0x10000,0x2ea);
    }
    iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
    iVar4 = iVar4 + 8;
    uVar3 = *(ushort *)(iVar6 + iVar4);
    iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
    *(ushort *)(iVar6 + iVar4) = (ushort)uVar7 | uVar3 & 0xffc0;
    bVar2 = *(byte *)(iVar5 + 0x91);
    if ((bVar2 & 0xc0) != 0) {
      r_assert_err(0,0x10000,0x635);
    }
    iVar4 = r_emi_get_mem_addr_by_offset(0x400);
    iVar6 = (uint)bVar1 * 0x5a + 0x26;
    uVar3 = *(ushort *)(iVar4 + iVar6);
    iVar4 = r_emi_get_mem_addr_by_offset(0x400);
    *(ushort *)(iVar4 + iVar6) = uVar3 & 0x3ff | (ushort)bVar2 << 10;
    uVar7 = 0;
    while( true ) {
      bVar1 = *(byte *)(iVar5 + 0x87);
      uVar7 = uVar7 + 1 & 0xff;
      iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
      iVar4 = ((uint)bVar1 * 9 + uVar7 & 0xff) * 0xe;
      uVar3 = *(ushort *)(iVar6 + iVar4);
      iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
      *(ushort *)(iVar6 + iVar4) = uVar3 & 0x7fff;
      if (uVar7 == *(byte *)(iVar5 + 0x92) - 1) break;
      bVar1 = *(byte *)(iVar5 + 0x91);
      if (0x3f < bVar1) {
        r_assert_err(0,0x10000,0x2ea);
      }
      iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
      uVar3 = *(ushort *)(iVar6 + iVar4 + 8);
      iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
      *(ushort *)(iVar6 + iVar4 + 8) = (ushort)bVar1 | uVar3 & 0xffc0;
    }
  }
  return;
}

