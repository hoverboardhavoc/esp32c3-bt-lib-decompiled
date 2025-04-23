/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_tx
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_con_tx(int param_1)

{
  char cVar1;
  ushort uVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  byte bStack_42;
  byte abStack_41 [13];
  
  iVar8 = *(int *)(&lld_con_env + param_1 * 4);
  bVar5 = *(char *)(iVar8 + 0x8e) * '\t' + *(char *)(iVar8 + 0x90);
  while( true ) {
    if (*(char *)(iVar8 + 0x92) == '\0') break;
    iVar7 = (uint)bVar5 * 0xe;
    iVar10 = r_emi_get_mem_addr_by_offset(0x1400);
    if (-1 < *(short *)(iVar10 + iVar7)) break;
    iVar10 = r_emi_get_mem_addr_by_offset(0x1400);
    iVar11 = iVar7 + 2;
    uVar2 = *(ushort *)(iVar10 + iVar11);
    iVar10 = r_emi_get_mem_addr_by_offset(0x1400);
    uVar12 = (uint)*(ushort *)(iVar7 + 4 + iVar10);
    if ((uVar2 & 3) == 3) {
      r_ble_util_buf_llcp_tx_free(uVar12);
      uVar9 = 0x20c;
_L400:
      r_ke_msg_send_basic(uVar9,param_1 << 8 | 1,0xff);
    }
    else if ((uVar2 & 3) == 0) {
      r_assert_err(0,"lld_con.c",0x9e1);
    }
    else {
      iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
      uVar6 = (uint)(*(ushort *)(iVar7 + iVar11) >> 8);
      if (uVar6 < 5) {
        if (uVar6 == 0) goto _L376;
      }
      else if ((*(ushort *)(iVar8 + 0x84) & 0x40) != 0) {
        uVar6 = uVar6 - 4 & 0xffff;
      }
      iVar7 = *(int *)(iVar8 + 0x28);
      if (iVar7 == 0) {
        r_assert_err(0,"lld_con.c",0x9c1);
      }
      if ((*(ushort *)(iVar7 + 6) & 0x3ff) + (uint)*(ushort *)(iVar7 + 4) <= uVar12 + uVar6) {
        r_co_list_pop_front(iVar8 + 0x28);
        if (*(int *)(iVar8 + 0x30) == iVar7) {
          *(undefined4 *)(iVar8 + 0x30) = 0;
        }
        r_ble_util_buf_acl_tx_free_in_isr(*(undefined2 *)(iVar7 + 4));
        uVar9 = 0x20e;
        goto _L400;
      }
    }
_L376:
    iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
    uVar2 = *(ushort *)(iVar7 + iVar11);
    iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
    *(ushort *)(iVar7 + iVar11) = uVar2 & 0xffef;
    cVar1 = *(char *)(iVar8 + 0x92);
    *(char *)(iVar8 + 0x92) = cVar1 + -1;
    if (cVar1 == '\x01') {
      bVar5 = *(byte *)(iVar8 + 0x8e);
      bStack_42 = 0;
      abStack_41[0] = 0;
      iVar7 = r_emi_get_mem_addr_by_offset(0x400);
      iVar10 = (uint)bVar5 * 0x5a;
      r_bt_rma_get_ant_by_act(*(ushort *)(iVar7 + iVar10) & 0x1f,&bStack_42,abStack_41);
      bVar4 = abStack_41[0];
      bVar3 = bStack_42;
      bVar5 = rwip_coex_cfg;
      uVar12 = (uint)rwip_coex_cfg;
      iVar7 = r_emi_get_mem_addr_by_offset(0x400);
      uVar2 = *(ushort *)(iVar7 + iVar10);
      if ((bVar3 & 0xfe) != 0) {
        r_assert_err(0,"lld_con.c",0x42);
      }
      if ((bVar4 & 0xfe) != 0) {
        r_assert_err(0,"lld_con.c",0x43);
      }
      iVar7 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar7 + iVar10) =
           (ushort)bVar3 << 7 | (ushort)bVar4 << 6 | (ushort)((uVar12 & 1) << 10) |
           (ushort)((bVar5 >> 1 & 1) << 9) | (ushort)((bVar5 >> 2 & 1) << 8) | uVar2 & 0x1f;
    }
    bVar5 = *(char *)(iVar8 + 0x90) + 1U & 1;
    *(byte *)(iVar8 + 0x90) = bVar5;
    bVar5 = bVar5 + *(char *)(iVar8 + 0x8e) * '\t';
  }
  *(ushort *)(iVar8 + 0x84) =
       (ushort)(*(char *)(iVar8 + 0x92) != '\0') << 3 | *(ushort *)(iVar8 + 0x84) & 0xfff7;
  return;
}

