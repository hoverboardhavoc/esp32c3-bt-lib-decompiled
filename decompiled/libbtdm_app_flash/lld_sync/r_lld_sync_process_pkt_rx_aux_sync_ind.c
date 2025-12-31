/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
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
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  
  iVar7 = *(int *)(&lld_sync_env + param_1 * 4);
  bVar1 = *(byte *)(_p_lld_env + 0xd8);
  iVar5 = r_emi_get_mem_addr_by_offset(0x1000);
  uVar4 = param_1 << 0x10 | (uint)bVar1 << 0x18;
  uVar2 = *(ushort *)((uint)bVar1 * 0x14 + 2 + iVar5);
  r_ble_log_internal_x2(0x20a5012b,uVar2 | uVar4,param_2);
  if ((param_2 != 0) && ((uVar2 & 1) == 0)) {
    bVar1 = *(byte *)(_p_lld_env + 0xd8);
    iVar5 = r_emi_get_mem_addr_by_offset(0x1000);
    uVar2 = *(ushort *)((uint)bVar1 * 0x14 + 10 + iVar5);
    if ((uVar2 & 0xf000) != 0) {
      r_assert_err(0,0x10000,1000);
    }
    bVar1 = *(byte *)(_p_lld_env + 0xd8);
    iVar5 = r_emi_get_mem_addr_by_offset(0x1000);
    uVar6 = CONCAT22(uVar2,*(undefined2 *)((uint)bVar1 * 0x14 + 8 + iVar5));
    bVar1 = *(byte *)(_p_lld_env + 0xd8);
    iVar5 = r_emi_get_mem_addr_by_offset(0x1000);
    uVar3 = ((uint)*(ushort *)(&lld_exp_sync_pos_tab + (uint)*(byte *)(iVar7 + 0x58) * 2) * -2 +
            0x270) - (*(ushort *)((uint)bVar1 * 0x14 + 0xc + iVar5) & 0x3ff);
    iVar5 = (int)(uVar3 * 0x10000) >> 0x10;
    if ((((byte)r_rwip_active_check & 4) != 0) && ((*(byte *)(iVar7 + 0x58) - 2 & 0xff) < 2)) {
      iVar5 = (int)(((uVar3 & 0xffff) + (uint)_DAT_0001307a * -2) * 0x10000) >> 0x10;
    }
    uVar3 = uVar6;
    if (0x751 < (iVar5 + 0x4e1U & 0xffff)) {
      r_assert_err(0,0x10000,0x1a2);
    }
    for (; iVar5 < 0; iVar5 = (iVar5 + 0x271) * 0x10000 >> 0x10) {
      uVar3 = uVar3 - 1 & 0xfffffff;
    }
    *(undefined1 *)(iVar7 + 0x54) = 0;
    *(short *)(iVar7 + 0x48) = (short)iVar5;
    *(uint *)(iVar7 + 0x38) = uVar6;
    *(uint *)(iVar7 + 0x44) = uVar3;
    *(undefined2 *)(iVar7 + 0x52) = 0;
    r_ble_log_internal_x2(0x2045012c,uVar6,*(ushort *)(iVar7 + 0x4a) | uVar4);
    return;
  }
  return;
}

