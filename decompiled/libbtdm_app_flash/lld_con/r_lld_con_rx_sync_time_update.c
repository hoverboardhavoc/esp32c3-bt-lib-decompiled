/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_rx_sync_time_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_con_rx_sync_time_update(int param_1,int param_2)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  uint uVar4;
  int iVar5;
  undefined2 *puVar6;
  int iVar7;
  uint uVar8;
  
  bVar1 = *(byte *)(_p_lld_env + 0xd8);
  uVar4 = 0;
  if ((*(ushort *)(param_2 + 0x84) & 1) != 0) {
    iVar5 = (uint)bVar1 * 0x14;
    iVar7 = r_emi_get_mem_addr_by_offset(0x1000);
    uVar3 = *(ushort *)(iVar7 + iVar5 + 10);
    if ((uVar3 & 0xf000) != 0) {
      r_assert_err(0,"lld_con.c",1000);
    }
    iVar7 = r_emi_get_mem_addr_by_offset(0x1000);
    uVar4 = CONCAT22(uVar3,*(undefined2 *)(iVar5 + 8 + iVar7));
    *(uint *)(param_2 + 0x50) = uVar4;
  }
  uVar3 = *(ushort *)(param_2 + 0x84);
  if ((uVar3 & 0x100) != 0) {
    return;
  }
  *(ushort *)(param_2 + 0x84) = uVar3 | 0x100;
  if ((uVar3 & 1) == 0) {
    *(undefined4 *)(param_2 + 0x50) = *(undefined4 *)(param_2 + 0x48);
  }
  else {
    iVar5 = r_emi_get_mem_addr_by_offset(0x1000);
    uVar8 = ((uint)*(ushort *)(&lld_exp_sync_pos_tab + (uint)*(byte *)(param_2 + 0x93) * 2) * -2 +
            0x270) - (*(ushort *)(iVar5 + (uint)bVar1 * 0x14 + 0xc) & 0x3ff);
    iVar5 = (int)(short)uVar8;
    if ((((byte)r_rwip_active_check & 1) != 0) && ((*(byte *)(param_2 + 0x93) - 2 & 0xff) < 2)) {
      iVar5 = (int)(((uVar8 & 0xffff) + (uint)_DAT_0001508a * -2) * 0x10000) >> 0x10;
    }
    if (0x751 < (iVar5 + 0x4e1U & 0xffff)) {
      r_assert_err(0,"lld_con.c",0x8b7);
    }
    for (; iVar5 < 0; iVar5 = (iVar5 + 0x271) * 0x10000 >> 0x10) {
      uVar4 = uVar4 - 1 & 0xfffffff;
    }
    if ((*(char *)(param_2 + 0x46) == '\x01') && (*(char *)(param_2 + 0x42) != '\0')) {
      *(undefined1 *)(param_2 + 0x43) = 1;
      r_lld_instant_proc_end(param_1);
    }
    *(short *)(param_2 + 0x6e) = (short)iVar5;
    *(uint *)(param_2 + 0x48) = uVar4;
    *(uint *)(param_2 + 0x54) = uVar4;
  }
  bVar1 = *(byte *)(_p_lld_env + 0xd8);
  iVar5 = r_emi_get_mem_addr_by_offset(0x1000);
  uVar3 = *(ushort *)(iVar5 + (uint)bVar1 * 0x14 + 4);
  uVar2 = *(ushort *)(param_2 + 0x84);
  if ((uVar2 & 2) == 0) {
    *(ushort *)(param_2 + 0x84) = uVar2 | 2;
    if ((uVar2 & 1) != 0) {
      puVar6 = (undefined2 *)r_ke_msg_alloc(0x213,param_1 << 8 | 1,0xff,2);
      uVar4 = *(uint *)(param_2 + 0x54);
      uVar8 = *(uint *)(param_2 + 100) >> 1;
      if (uVar8 == 0) {
        r_assert_err(0,"lld_con.c",0x94);
      }
      *puVar6 = (short)((uVar4 >> 1) % uVar8);
      r_ke_msg_send(puVar6);
    }
  }
  else if (((uVar2 & 1) != 0) && (*(uint *)(param_2 + 100) >> 1 == 0)) {
    r_assert_err(0,"lld_con.c",0x94);
  }
  if (((*(ushort *)(param_2 + 0x84) & 0x402) == 2) && ((uVar3 & 4) != 0)) {
    *(ushort *)(param_2 + 0x84) = *(ushort *)(param_2 + 0x84) | 0x400;
  }
  return;
}

