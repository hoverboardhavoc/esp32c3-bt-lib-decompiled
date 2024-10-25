/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_adv_aux_ch_idx_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_adv_aux_ch_idx_set(int param_1)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  
  iVar6 = *(int *)(&lld_adv_env + param_1 * 4);
  bVar1 = *(byte *)(iVar6 + 0x87);
  iVar4 = r_emi_get_mem_addr_by_offset(0x1400);
  iVar3 = ((uint)bVar1 * 9 & 0xff) * 0xe;
  if ((int)((uint)*(ushort *)(iVar4 + iVar3 + 6) << 0x13) < 0) {
    bVar1 = *(byte *)(iVar6 + 0x87);
    uVar5 = r_lld_ch_idx_get_hack();
    *(char *)(iVar6 + 0x91) = (char)uVar5;
    if ((uVar5 & 0xffffffc0) != 0) {
      r_assert_err(0,"lld_adv.c",0x2ea);
    }
    iVar4 = r_emi_get_mem_addr_by_offset(0x1400);
    iVar3 = iVar3 + 8;
    uVar2 = *(ushort *)(iVar4 + iVar3);
    iVar4 = r_emi_get_mem_addr_by_offset(0x1400);
    *(ushort *)(iVar3 + iVar4) = uVar2 & 0xffc0 | (ushort)uVar5;
    uVar5 = (uint)*(byte *)(iVar6 + 0x91) << 10;
    if ((uVar5 & 0x30000) != 0) {
      r_assert_err(0,"lld_adv.c",0x635);
    }
    iVar4 = r_emi_get_mem_addr_by_offset(0x400);
    iVar3 = (uint)bVar1 * 0x5a + 0x26;
    uVar2 = *(ushort *)(iVar4 + iVar3);
    iVar4 = r_emi_get_mem_addr_by_offset(0x400);
    *(ushort *)(iVar4 + iVar3) = uVar2 & 0x3ff | (ushort)uVar5;
    uVar5 = 0;
    while( true ) {
      bVar1 = *(byte *)(iVar6 + 0x87);
      uVar5 = uVar5 + 1 & 0xff;
      iVar4 = r_emi_get_mem_addr_by_offset(0x1400);
      iVar3 = ((uint)bVar1 * 9 + uVar5 & 0xff) * 0xe;
      uVar2 = *(ushort *)(iVar4 + iVar3);
      iVar4 = r_emi_get_mem_addr_by_offset(0x1400);
      *(ushort *)(iVar4 + iVar3) = uVar2 & 0x7fff;
      if (uVar5 == *(byte *)(iVar6 + 0x92) - 1) break;
      bVar1 = *(byte *)(iVar6 + 0x91);
      if ((bVar1 & 0xc0) != 0) {
        r_assert_err(0,"lld_adv.c",0x2ea);
      }
      iVar4 = r_emi_get_mem_addr_by_offset(0x1400);
      uVar2 = *(ushort *)(iVar4 + iVar3 + 8);
      iVar4 = r_emi_get_mem_addr_by_offset(0x1400);
      *(ushort *)(iVar3 + 8 + iVar4) = uVar2 & 0xffc0 | (ushort)bVar1;
    }
  }
  return;
}

