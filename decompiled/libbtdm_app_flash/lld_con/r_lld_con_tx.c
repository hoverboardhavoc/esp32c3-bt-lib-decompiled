/*
 * Last changed at upstream commit 0a08c4b32f3666003080b662a1a61794da24ff0f
 * https://github.com/espressif/esp32c3-bt-lib/commit/0a08c4b32f3666003080b662a1a61794da24ff0f
 * Upstream date: 2026-05-25 14:11:16 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(51d9dfde)
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
  int iVar3;
  byte bVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  byte bStack_42;
  byte abStack_41 [13];
  
  iVar3 = *(int *)(&lld_con_env + param_1 * 4);
  bVar4 = *(char *)(iVar3 + 0x8e) * '\t' + *(char *)(iVar3 + 0x90);
  while( true ) {
    if (*(char *)(iVar3 + 0x92) == '\0') break;
    iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
    iVar5 = (uint)bVar4 * 0xe;
    if (-1 < *(short *)(iVar8 + iVar5)) break;
    iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
    iVar9 = iVar5 + 2;
    uVar2 = *(ushort *)(iVar8 + iVar9);
    iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
    uVar10 = (uint)*(ushort *)(iVar5 + 4 + iVar8);
    if ((uVar2 & 3) == 3) {
      r_ble_util_buf_llcp_tx_free(uVar10);
      uVar7 = 0x20c;
_L397:
      r_ke_msg_send_basic(uVar7,param_1 << 8 | 1,0xff);
    }
    else if ((uVar2 & 3) == 0) {
      r_assert_err(0,"lld_con.c",0xb46);
    }
    else {
      iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
      uVar6 = (uint)(*(ushort *)(iVar5 + iVar9) >> 8);
      if (uVar6 < 5) {
        if (uVar6 == 0) goto _L373;
      }
      else if ((*(ushort *)(iVar3 + 0x84) & 0x40) != 0) {
        uVar6 = uVar6 - 4 & 0xffff;
      }
      iVar5 = *(int *)(iVar3 + 0x28);
      if (iVar5 == 0) {
        r_assert_err(0,"lld_con.c",0xb26);
      }
      if ((*(ushort *)(iVar5 + 6) & 0x3ff) + (uint)*(ushort *)(iVar5 + 4) <= uVar10 + uVar6) {
        r_co_list_pop_front(iVar3 + 0x28);
        if (*(int *)(iVar3 + 0x30) == iVar5) {
          *(undefined4 *)(iVar3 + 0x30) = 0;
        }
        r_ble_util_buf_acl_tx_free_in_isr(*(undefined2 *)(iVar5 + 4));
        uVar7 = 0x20e;
        goto _L397;
      }
    }
_L373:
    iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
    uVar2 = *(ushort *)(iVar5 + iVar9);
    iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
    *(ushort *)(iVar5 + iVar9) = uVar2 & 0xffef;
    cVar1 = *(char *)(iVar3 + 0x92);
    *(char *)(iVar3 + 0x92) = cVar1 + -1;
    if (cVar1 == '\x01') {
      bVar4 = *(byte *)(iVar3 + 0x8e);
      bStack_42 = 0;
      abStack_41[0] = 0;
      iVar5 = r_emi_get_mem_addr_by_offset(0x400);
      iVar8 = (uint)bVar4 * 0x5a;
      r_bt_rma_get_ant_by_act(*(ushort *)(iVar5 + iVar8) & 0x1f,&bStack_42,abStack_41);
      uVar10 = (uint)bStack_42;
      uVar6 = (uint)rwip_coex_cfg;
      uVar11 = (uint)abStack_41[0];
      iVar5 = r_emi_get_mem_addr_by_offset(0x400);
      uVar2 = *(ushort *)(iVar5 + iVar8);
      if ((uVar10 << 7 & 0xffffff7f) != 0) {
        r_assert_err(0,"lld_con.c",0x42);
      }
      if ((uVar11 << 6 & 0xffffffbf) != 0) {
        r_assert_err(0,"lld_con.c",0x43);
      }
      iVar5 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar5 + iVar8) =
           (ushort)(uVar10 << 7) | (ushort)(uVar11 << 6) | (ushort)((uVar6 & 1) << 10) |
           (ushort)((uVar6 & 2) << 8) | (ushort)((uVar6 & 4) << 6) | uVar2 & 0x1f;
    }
    bVar4 = *(char *)(iVar3 + 0x90) + 1U & 1;
    *(byte *)(iVar3 + 0x90) = bVar4;
    bVar4 = bVar4 + *(char *)(iVar3 + 0x8e) * '\t';
  }
  *(ushort *)(iVar3 + 0x84) =
       (ushort)(*(char *)(iVar3 + 0x92) != '\0') << 3 | *(ushort *)(iVar3 + 0x84) & 0xfff7;
  return;
}

