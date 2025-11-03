/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
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
  undefined2 *puVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  
  bVar1 = *(byte *)(_p_lld_env + 0xd8);
  uVar7 = 0;
  if ((*(ushort *)(param_2 + 0x84) & 1) != 0) {
    iVar8 = (uint)bVar1 * 0x14;
    iVar6 = r_emi_get_mem_addr_by_offset(0x1000);
    uVar3 = *(ushort *)(iVar8 + 10 + iVar6);
    if ((uVar3 & 0xf000) != 0) {
      r_assert_err(0,"lld_con.c",1000);
    }
    iVar6 = r_emi_get_mem_addr_by_offset(0x1000);
    uVar7 = CONCAT22(uVar3,*(undefined2 *)(iVar8 + 8 + iVar6));
    *(uint *)(param_2 + 0x50) = uVar7;
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
    iVar6 = r_emi_get_mem_addr_by_offset(0x1000);
    uVar4 = ((uint)*(ushort *)(&lld_exp_sync_pos_tab + (uint)*(byte *)(param_2 + 0x93) * 2) * -2 +
            0x270) - (*(ushort *)((uint)bVar1 * 0x14 + 0xc + iVar6) & 0x3ff);
    iVar6 = (int)(uVar4 * 0x10000) >> 0x10;
    if ((((byte)r_ke_msg_send_basic & 1) != 0) && ((*(byte *)(param_2 + 0x93) - 2 & 0xff) < 2)) {
      iVar6 = (int)(((uVar4 & 0xffff) + (uint)_DAT_0001608e * -2) * 0x10000) >> 0x10;
    }
    if (0x751 < (iVar6 + 0x4e1U & 0xffff)) {
      r_assert_err(0,"lld_con.c",0x90e);
    }
    for (; iVar6 < 0; iVar6 = (iVar6 + 0x271) * 0x10000 >> 0x10) {
      uVar7 = uVar7 - 1 & 0xfffffff;
    }
    if ((*(char *)(param_2 + 0x46) == '\x01') && (*(char *)(param_2 + 0x42) != '\0')) {
      *(undefined1 *)(param_2 + 0x43) = 1;
      r_lld_instant_proc_end(param_1);
    }
    *(short *)(param_2 + 0x6e) = (short)iVar6;
    *(uint *)(param_2 + 0x48) = uVar7;
    *(uint *)(param_2 + 0x54) = uVar7;
  }
  bVar1 = *(byte *)(_p_lld_env + 0xd8);
  iVar6 = r_emi_get_mem_addr_by_offset(0x1000);
  uVar3 = *(ushort *)(param_2 + 0x84);
  uVar2 = *(ushort *)((uint)bVar1 * 0x14 + 4 + iVar6);
  if ((uVar3 & 2) == 0) {
    *(ushort *)(param_2 + 0x84) = uVar3 | 2;
    if ((uVar3 & 1) != 0) {
      puVar5 = (undefined2 *)r_ke_msg_alloc(0x213,param_1 << 8 | 1,0xff,2);
      uVar7 = *(uint *)(param_2 + 0x54);
      uVar4 = *(uint *)(param_2 + 100) >> 1;
      if (uVar4 == 0) {
        r_assert_err(0,"lld_con.c",0x94);
      }
      *puVar5 = (short)((uVar7 >> 1) % uVar4);
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

