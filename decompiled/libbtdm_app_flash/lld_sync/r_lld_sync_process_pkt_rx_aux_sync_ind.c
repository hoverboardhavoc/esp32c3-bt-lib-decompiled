/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld_sync.o -> r_lld_sync_process_pkt_rx_aux_sync_ind
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_sync_process_pkt_rx_aux_sync_ind(int param_1,int param_2)

{
  byte bVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  
  bVar1 = *(byte *)(_p_lld_env + 0xd8);
  iVar6 = *(int *)(&lld_sync_env + param_1 * 4);
  iVar4 = r_emi_get_mem_addr_by_offset(0x1000);
  if ((param_2 != 0) && ((*(ushort *)(iVar4 + (uint)bVar1 * 0x14 + 2) & 1) == 0)) {
    bVar1 = *(byte *)(_p_lld_env + 0xd8);
    iVar4 = r_emi_get_mem_addr_by_offset(0x1000);
    uVar2 = *(ushort *)((uint)bVar1 * 0x14 + 10 + iVar4);
    if ((uVar2 & 0xf000) != 0) {
      r_assert_err(0,"lld_sync.c",1000);
    }
    bVar1 = *(byte *)(_p_lld_env + 0xd8);
    iVar4 = r_emi_get_mem_addr_by_offset(0x1000);
    uVar3 = CONCAT22(uVar2,*(undefined2 *)((uint)bVar1 * 0x14 + 8 + iVar4));
    bVar1 = *(byte *)(_p_lld_env + 0xd8);
    iVar4 = r_emi_get_mem_addr_by_offset(0x1000);
    uVar5 = ((uint)*(ushort *)(&lld_exp_sync_pos_tab + (uint)*(byte *)(iVar6 + 0x58) * 2) * -2 +
            0x270) - (*(ushort *)(iVar4 + (uint)bVar1 * 0x14 + 0xc) & 0x3ff);
    iVar4 = (int)(short)uVar5;
    if ((((byte)r_sdk_config_get_opts & 4) != 0) && ((*(byte *)(iVar6 + 0x58) - 2 & 0xff) < 2)) {
      iVar4 = (int)(((uVar5 & 0xffff) + (uint)_DAT_00012072 * -2) * 0x10000) >> 0x10;
    }
    uVar5 = uVar3;
    if (0x751 < (iVar4 + 0x4e1U & 0xffff)) {
      r_assert_err(0,"lld_sync.c",0x19b);
    }
    for (; iVar4 < 0; iVar4 = (iVar4 + 0x271) * 0x10000 >> 0x10) {
      uVar5 = uVar5 - 1 & 0xfffffff;
    }
    *(uint *)(iVar6 + 0x44) = uVar5;
    *(short *)(iVar6 + 0x48) = (short)iVar4;
    *(uint *)(iVar6 + 0x38) = uVar3;
    *(undefined2 *)(iVar6 + 0x52) = 0;
    *(undefined1 *)(iVar6 + 0x54) = 0;
  }
  return;
}

