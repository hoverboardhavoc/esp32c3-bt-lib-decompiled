/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
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
  int iVar3;
  uint uVar4;
  ushort uVar5;
  int iVar6;
  int iVar7;
  
  bVar1 = *(byte *)(_p_lld_env + 0xd8);
  while ((*(char *)(_p_lld_env + 0x101) == '\0' &&
         (iVar3 = r_ble_util_buf_rx_alloc_in_isr(), iVar3 != 0))) {
    uVar4 = (*(byte *)(_p_lld_env + 0xd9) + 1) % 10;
    *(char *)(_p_lld_env + 0xd9) = (char)uVar4;
    iVar6 = r_emi_get_mem_addr_by_offset(0x1000);
    if (-1 < *(short *)(uVar4 * 0x14 + iVar6)) {
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
    *(short *)((uint)bVar2 * 0x14 + 0x12 + iVar7) = (short)iVar3;
    bVar2 = *(byte *)(iVar6 + 0xd9);
    iVar6 = r_emi_get_mem_addr_by_offset(0x1000);
    iVar3 = (uint)bVar2 * 0x14;
    uVar5 = *(ushort *)(iVar6 + iVar3);
    iVar6 = r_emi_get_mem_addr_by_offset(0x1000);
    *(ushort *)(iVar3 + iVar6) = uVar5 & 0x7fff;
  }
  iVar6 = r_emi_get_mem_addr_by_offset(0x1000);
  iVar3 = (uint)bVar1 * 0x14;
  if (*(short *)(iVar6 + iVar3) < 0) {
    iVar6 = r_emi_get_mem_addr_by_offset(0x1000);
    if (*(ushort *)(iVar3 + 0xc + iVar6) >> 0xb == param_1) {
      iVar6 = r_emi_get_mem_addr_by_offset(0x1000);
      uVar5 = (*(short *)(iVar3 + 2 + iVar6) >> 0xf) + 1;
      goto _L316;
    }
  }
  uVar5 = 0;
_L316:
  return uVar5 & 1;
}

