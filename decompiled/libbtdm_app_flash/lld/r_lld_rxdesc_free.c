/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld.o -> r_lld_rxdesc_free
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_rxdesc_free(void)

{
  byte bVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  bVar1 = *(byte *)(_p_lld_env + 0xd8);
  iVar4 = r_emi_get_mem_addr_by_offset(0x1000);
  if (*(short *)((uint)bVar1 * 0x14 + 0x12 + iVar4) != 0) {
    bVar1 = *(byte *)(_p_lld_env + 0xd8);
    iVar4 = r_emi_get_mem_addr_by_offset(0x1000);
    r_ble_util_buf_rx_free_in_isr(*(undefined2 *)((uint)bVar1 * 0x14 + 0x12 + iVar4));
  }
  bVar1 = *(byte *)(_p_lld_env + 0xd8);
  iVar5 = r_emi_get_mem_addr_by_offset(0x1000);
  iVar4 = _p_lld_env;
  *(undefined2 *)((uint)bVar1 * 0x14 + 0x12 + iVar5) = 0;
  bVar1 = *(byte *)(iVar4 + 0xd8);
  iVar4 = r_emi_get_mem_addr_by_offset(0x1000);
  iVar5 = (uint)bVar1 * 0x14;
  uVar2 = *(ushort *)(iVar4 + iVar5);
  iVar4 = r_emi_get_mem_addr_by_offset(0x1000);
  *(ushort *)(iVar4 + iVar5) = uVar2 & 0x7fff | 0x8000;
  bVar1 = *(byte *)(_p_lld_env + 0xd8);
  iVar4 = r_emi_get_mem_addr_by_offset(0x1000);
  iVar6 = (uint)bVar1 * 0x14 + 2;
  uVar2 = *(ushort *)(iVar4 + iVar6);
  iVar5 = r_emi_get_mem_addr_by_offset(0x1000);
  iVar4 = _p_lld_env;
  *(ushort *)(iVar5 + iVar6) = uVar2 & 0x7fff | 0x8000;
  *(char *)(iVar4 + 0xd8) = (char)((*(byte *)(iVar4 + 0xd8) + 1) % 10);
  if (*(char *)(iVar4 + 0x101) == '\0') {
    while (iVar4 = r_ble_util_buf_rx_alloc_in_isr(), iVar4 != 0) {
      uVar3 = (*(byte *)(_p_lld_env + 0xd9) + 1) % 10;
      *(char *)(_p_lld_env + 0xd9) = (char)uVar3;
      iVar5 = r_emi_get_mem_addr_by_offset(0x1000);
      if (-1 < *(short *)(uVar3 * 0x14 + iVar5)) {
        r_assert_param(*(undefined1 *)(_p_lld_env + 0xd9),*(undefined1 *)(_p_lld_env + 0xd8),"lld.c"
                       ,0x4b7);
      }
      bVar1 = *(byte *)(_p_lld_env + 0xd9);
      iVar5 = r_emi_get_mem_addr_by_offset(0x1000);
      if (*(short *)((uint)bVar1 * 0x14 + 0x12 + iVar5) != 0) {
        r_assert_param(*(undefined1 *)(_p_lld_env + 0xd9),*(undefined1 *)(_p_lld_env + 0xd8),"lld.c"
                       ,0x4b8);
      }
      bVar1 = *(byte *)(_p_lld_env + 0xd9);
      iVar6 = r_emi_get_mem_addr_by_offset(0x1000);
      iVar5 = _p_lld_env;
      *(short *)((uint)bVar1 * 0x14 + 0x12 + iVar6) = (short)iVar4;
      bVar1 = *(byte *)(iVar5 + 0xd9);
      iVar5 = r_emi_get_mem_addr_by_offset(0x1000);
      iVar4 = (uint)bVar1 * 0x14;
      uVar2 = *(ushort *)(iVar5 + iVar4);
      iVar5 = r_emi_get_mem_addr_by_offset(0x1000);
      *(ushort *)(iVar5 + iVar4) = uVar2 & 0x7fff;
    }
  }
  return;
}

