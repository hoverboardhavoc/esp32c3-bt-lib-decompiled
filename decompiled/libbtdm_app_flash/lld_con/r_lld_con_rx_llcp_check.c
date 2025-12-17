/*
 * Last changed at upstream commit 9b50531537e755792ac827d00d233eab499a0b37
 * https://github.com/espressif/esp32c3-bt-lib/commit/9b50531537e755792ac827d00d233eab499a0b37
 * Upstream date: 2025-12-17 10:51:37 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(5106725)
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
      r_assert_param(param_3,param_1,"lld_con.c",0x8a9);
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

