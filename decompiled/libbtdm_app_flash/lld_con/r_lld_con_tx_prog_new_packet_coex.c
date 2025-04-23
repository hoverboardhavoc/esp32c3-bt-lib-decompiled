/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
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
  byte bVar3;
  byte bVar4;
  byte bVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  ushort uVar11;
  byte bStack_32;
  byte abStack_31 [5];
  
  uVar10 = (uint)*(byte *)(param_1 + 0x8e);
  bVar1 = *(byte *)(param_1 + 0x91);
  if (*(char *)(param_1 + 0x92) == '\0') {
    bStack_32 = 0;
    abStack_31[0] = 0;
    iVar7 = r_emi_get_mem_addr_by_offset(0x400);
    uVar11 = *(ushort *)(iVar7 + uVar10 * 0x5a) & 0x1f;
    r_bt_rma_get_ant_by_act(uVar11,uVar10,&bStack_32,abStack_31);
    bVar5 = abStack_31[0];
    bVar4 = bStack_32;
    uVar9 = (uint)rwip_coex_cfg;
    bVar2 = rwip_coex_cfg >> 1;
    bVar3 = rwip_coex_cfg >> 2;
    if ((bStack_32 & 0xfe) != 0) {
      r_assert_err(0,"lld_con.c",0x42);
    }
    if ((bVar5 & 0xfe) != 0) {
      r_assert_err(0,"lld_con.c",0x43);
    }
    iVar7 = r_emi_get_mem_addr_by_offset(0x400);
    *(ushort *)(iVar7 + uVar10 * 0x5a) =
         (ushort)bVar4 << 7 | (ushort)bVar5 << 6 | (ushort)((uVar9 & 1) << 10) |
         (ushort)((bVar2 & 1) << 9) | (ushort)((bVar3 & 1) << 8) | uVar11;
  }
  bVar2 = *(byte *)(param_1 + 0x8e);
  iVar7 = r_emi_get_mem_addr_by_offset(0x400);
  iVar7 = r_bt_rf_coex_st_param_get((*(ushort *)((uint)bVar2 * 0x5a + iVar7) & 0x1f) != 2);
  if (iVar7 != 0) {
    if (2 < _g_bt_plf_log_level) {
      ets_printf("TX PTI [CON] [EN%d] [%d] \n",*(undefined1 *)(iVar7 + 4),*(undefined1 *)(iVar7 + 5)
                );
    }
    bVar2 = *(byte *)(iVar7 + 5);
    if ((bVar2 & 0xf0) != 0) {
      r_assert_err(0,"lld_con.c",0x33f);
    }
    iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
    iVar6 = ((uint)bVar1 + uVar10 * 9 & 0xff) * 0xe + 10;
    uVar11 = *(ushort *)(iVar8 + iVar6);
    iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
    *(ushort *)(iVar8 + iVar6) = uVar11 & 0xf0ff | (ushort)bVar2 << 8;
    bVar1 = *(byte *)(iVar7 + 4);
    iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
    uVar11 = *(ushort *)(iVar7 + iVar6);
    iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
    *(ushort *)(iVar7 + iVar6) = uVar11 & 0xefff | (ushort)bVar1 << 0xc;
  }
  return;
}

