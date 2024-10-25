/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_rx_link_info_check
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_con_rx_link_info_check(int param_1,int param_2)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  int iVar4;
  undefined2 *puVar5;
  uint uVar6;
  uint uVar7;
  
  bVar1 = *(byte *)(_p_lld_env + 0xd8);
  iVar4 = r_emi_get_mem_addr_by_offset(0x1000);
  uVar2 = *(ushort *)(iVar4 + (uint)bVar1 * 0x14 + 4);
  uVar3 = *(ushort *)(param_2 + 0x84);
  if ((uVar3 & 2) == 0) {
    *(ushort *)(param_2 + 0x84) = uVar3 | 2;
    if ((uVar3 & 1) != 0) {
      puVar5 = (undefined2 *)r_ke_msg_alloc(0x213,param_1 << 8 | 1,0xff,2);
      uVar6 = *(uint *)(param_2 + 0x54);
      uVar7 = *(uint *)(param_2 + 100) >> 1;
      if (uVar7 == 0) {
        r_assert_err(0,"lld_con.c",0x94);
      }
      *puVar5 = (short)((uVar6 >> 1) % uVar7);
      r_ke_msg_send(puVar5);
    }
  }
  else if (((uVar3 & 1) != 0) && (*(uint *)(param_2 + 100) >> 1 == 0)) {
    r_assert_err(0,"lld_con.c",0x94);
  }
  if (((*(ushort *)(param_2 + 0x84) & 0x402) == 2) && ((uVar2 & 4) != 0)) {
    *(ushort *)(param_2 + 0x84) = *(ushort *)(param_2 + 0x84) | 0x400;
  }
  return;
}

