/*
 * Last changed at upstream commit d2414a5dd958b32ca53382b441d24d97a0345a55
 * https://github.com/espressif/esp32c3-bt-lib/commit/d2414a5dd958b32ca53382b441d24d97a0345a55
 * Upstream date: 2025-03-20 20:11:19 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(03d0f8a6)
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
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  bVar1 = *(byte *)(_p_lld_env + 0xd8);
  while ((*(char *)(_p_lld_env + 0x101) == '\0' &&
         (iVar5 = r_ble_util_buf_rx_alloc_in_isr(), iVar5 != 0))) {
    uVar4 = (*(byte *)(_p_lld_env + 0xd9) + 1) % 10;
    *(char *)(_p_lld_env + 0xd9) = (char)uVar4;
    iVar7 = r_emi_get_mem_addr_by_offset(0x1000);
    if (-1 < *(short *)(uVar4 * 0x14 + iVar7)) {
      r_assert_param(*(undefined1 *)(_p_lld_env + 0xd9),*(undefined1 *)(_p_lld_env + 0xd8),"lld.c",
                     0x4de);
    }
    bVar2 = *(byte *)(_p_lld_env + 0xd9);
    iVar7 = r_emi_get_mem_addr_by_offset(0x1000);
    if (*(short *)((uint)bVar2 * 0x14 + 0x12 + iVar7) != 0) {
      r_assert_param(*(undefined1 *)(_p_lld_env + 0xd9),*(undefined1 *)(_p_lld_env + 0xd8),"lld.c",
                     0x4df);
    }
    bVar2 = *(byte *)(_p_lld_env + 0xd9);
    iVar6 = r_emi_get_mem_addr_by_offset(0x1000);
    iVar7 = _p_lld_env;
    *(short *)((uint)bVar2 * 0x14 + 0x12 + iVar6) = (short)iVar5;
    bVar2 = *(byte *)(iVar7 + 0xd9);
    iVar7 = r_emi_get_mem_addr_by_offset(0x1000);
    iVar5 = (uint)bVar2 * 0x14;
    uVar3 = *(ushort *)(iVar7 + iVar5);
    iVar7 = r_emi_get_mem_addr_by_offset(0x1000);
    *(ushort *)(iVar7 + iVar5) = uVar3 & 0x7fff;
  }
  iVar5 = r_emi_get_mem_addr_by_offset(0x1000);
  iVar7 = (uint)bVar1 * 0x14;
  if ((*(short *)(iVar5 + iVar7) < 0) &&
     (iVar5 = r_emi_get_mem_addr_by_offset(0x1000),
     *(ushort *)(iVar5 + iVar7 + 0xc) >> 0xb == param_1)) {
    iVar5 = r_emi_get_mem_addr_by_offset(0x1000);
    return *(ushort *)(iVar7 + 2 + iVar5) >> 0xf ^ 1;
  }
  return 0;
}

