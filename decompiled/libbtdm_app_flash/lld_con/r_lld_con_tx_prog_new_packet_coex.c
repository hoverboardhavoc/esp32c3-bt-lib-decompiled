/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_tx_prog_new_packet_coex
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_con_tx_prog_new_packet_coex(int param_1)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  ushort uVar9;
  uint uVar10;
  byte bStack_32;
  byte abStack_31 [5];
  
  uVar8 = (uint)*(byte *)(param_1 + 0x8e);
  bVar1 = *(byte *)(param_1 + 0x91);
  if (*(char *)(param_1 + 0x92) == '\0') {
    bStack_32 = 0;
    abStack_31[0] = 0;
    iVar5 = r_emi_get_mem_addr_by_offset(0x400);
    uVar9 = *(ushort *)(iVar5 + uVar8 * 0x5a) & 0x1f;
    r_bt_rma_get_ant_by_act(uVar9,uVar8,&bStack_32,abStack_31);
    uVar7 = (uint)rwip_coex_cfg;
    uVar3 = (uint)bStack_32;
    uVar10 = (uint)abStack_31[0];
    if ((uVar3 << 7 & 0xffffff7f) != 0) {
      r_assert_err(0,"lld_con.c",0x42);
    }
    if ((uVar10 << 6 & 0xffffffbf) != 0) {
      r_assert_err(0,"lld_con.c",0x43);
    }
    iVar5 = r_emi_get_mem_addr_by_offset(0x400);
    *(ushort *)(iVar5 + uVar8 * 0x5a) =
         (ushort)(uVar3 << 7) | (ushort)(uVar10 << 6) | (ushort)((uVar7 & 1) << 10) |
         (ushort)((uVar7 & 2) << 8) | (ushort)((uVar7 & 4) << 6) | uVar9;
  }
  bVar2 = *(byte *)(param_1 + 0x8e);
  iVar5 = r_emi_get_mem_addr_by_offset(0x400);
  iVar5 = r_bt_rf_coex_st_param_get((*(ushort *)((uint)bVar2 * 0x5a + iVar5) & 0x1f) != 2);
  if (iVar5 != 0) {
    if (2 < _g_bt_plf_log_level) {
      ets_printf("TX PTI [CON] [EN%d] [%d] \n",*(undefined1 *)(iVar5 + 4),*(undefined1 *)(iVar5 + 5)
                );
    }
    uVar3 = (uint)*(byte *)(iVar5 + 5) << 8;
    if ((uVar3 & 0xf000) != 0) {
      r_assert_err(0,"lld_con.c",0x33f);
    }
    iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
    iVar4 = ((uint)bVar1 + uVar8 * 9 & 0xff) * 0xe + 10;
    uVar9 = *(ushort *)(iVar6 + iVar4);
    iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
    *(ushort *)(iVar6 + iVar4) = uVar9 & 0xf0ff | (ushort)uVar3;
    bVar1 = *(byte *)(iVar5 + 4);
    iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
    uVar9 = *(ushort *)(iVar5 + iVar4);
    iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
    *(ushort *)(iVar5 + iVar4) = uVar9 & 0xefff | (ushort)bVar1 << 0xc;
  }
  return;
}

