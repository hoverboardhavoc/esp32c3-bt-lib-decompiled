/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld.o -> r_lld_rxdesc_check
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort r_lld_rxdesc_check(uint param_1)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  
  bVar1 = *(byte *)(_p_lld_env + 0xd8);
  while ((*(char *)(_p_lld_env + 0x101) == '\0' &&
         (iVar4 = r_ble_util_buf_rx_alloc_in_isr(), iVar4 != 0))) {
    uVar5 = (*(byte *)(_p_lld_env + 0xd9) + 1) % 10;
    *(char *)(_p_lld_env + 0xd9) = (char)uVar5;
    iVar6 = r_emi_get_mem_addr_by_offset(0x1000);
    if (-1 < *(short *)(uVar5 * 0x14 + iVar6)) {
      r_assert_param(*(undefined1 *)(_p_lld_env + 0xd9),*(undefined1 *)(_p_lld_env + 0xd8),"lld.c",
                     0x4de);
    }
    bVar2 = *(byte *)(_p_lld_env + 0xd9);
    iVar6 = r_emi_get_mem_addr_by_offset(0x1000);
    if (*(short *)((uint)bVar2 * 0x14 + 0x12 + iVar6) != 0) {
      r_assert_param(*(undefined1 *)(_p_lld_env + 0xd9),*(undefined1 *)(_p_lld_env + 0xd8),"lld.c",
                     0x4df);
    }
    bVar2 = *(byte *)(_p_lld_env + 0xd9);
    iVar7 = r_emi_get_mem_addr_by_offset(0x1000);
    iVar6 = _p_lld_env;
    *(short *)((uint)bVar2 * 0x14 + 0x12 + iVar7) = (short)iVar4;
    bVar2 = *(byte *)(iVar6 + 0xd9);
    iVar6 = r_emi_get_mem_addr_by_offset(0x1000);
    iVar4 = (uint)bVar2 * 0x14;
    uVar3 = *(ushort *)(iVar6 + iVar4);
    iVar6 = r_emi_get_mem_addr_by_offset(0x1000);
    *(ushort *)(iVar4 + iVar6) = uVar3 & 0x7fff;
  }
  iVar6 = r_emi_get_mem_addr_by_offset(0x1000);
  iVar4 = (uint)bVar1 * 0x14;
  if ((*(short *)(iVar6 + iVar4) < 0) &&
     (iVar6 = r_emi_get_mem_addr_by_offset(0x1000),
     *(ushort *)(iVar4 + 0xc + iVar6) >> 0xb == param_1)) {
    iVar6 = r_emi_get_mem_addr_by_offset(0x1000);
    return *(ushort *)(iVar4 + 2 + iVar6) >> 0xf ^ 1;
  }
  return 0;
}

