/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_rx_llcp_check
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_lld_con_rx_llcp_check(int param_1,int param_2,int param_3,short param_4)

{
  byte bVar1;
  undefined2 uVar2;
  int iVar3;
  undefined2 *puVar4;
  undefined4 uVar5;
  
  bVar1 = *(byte *)(_p_lld_env + 0xd8);
  iVar3 = r_emi_get_mem_addr_by_offset(0x1000);
  uVar2 = *(undefined2 *)((uint)bVar1 * 0x14 + 0x12 + iVar3);
  if (param_3 == 3) {
    puVar4 = (undefined2 *)r_ke_msg_alloc(0x20b,param_1 << 8 | 1,0xff,param_4 + 0xc);
    *(char *)(puVar4 + 1) = (char)param_4;
    puVar4[2] = uVar2;
    uVar5 = r_emi_get_mem_addr_by_offset(uVar2);
    uVar2 = *(undefined2 *)(param_2 + 0x7c);
    *(undefined4 *)(puVar4 + 4) = uVar5;
    *puVar4 = uVar2;
  }
  else {
    if (1 < (param_3 - 1U & 0xff)) {
      r_assert_param(param_3,param_1,"lld_con.c",0x856);
      return 1;
    }
    puVar4 = (undefined2 *)r_ke_msg_alloc(0x20d,param_1 << 8 | 1,0xff,0xc);
    *puVar4 = uVar2;
    uVar5 = r_emi_get_mem_addr_by_offset(uVar2);
    *(undefined4 *)(puVar4 + 2) = uVar5;
    puVar4[4] = param_4;
    *(char *)(puVar4 + 5) = (char)param_3;
  }
  r_ke_msg_send(puVar4);
  *(ushort *)(param_2 + 0x84) = *(ushort *)(param_2 + 0x84) | 4;
  return 0;
}

