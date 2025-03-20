/*
 * Last changed at upstream commit aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * https://github.com/espressif/esp32c3-bt-lib/commit/aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * Upstream date: 2025-03-20 20:31:24 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(d74042a8)
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
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  ushort uVar11;
  uint uVar12;
  byte bStack_42;
  byte abStack_41 [13];
  
  iVar5 = *(int *)(&lld_con_env + param_1 * 4);
  bVar3 = *(char *)(iVar5 + 0x8e) * '\t' + *(char *)(iVar5 + 0x90);
  uVar8 = (uint)rwip_coex_cfg;
  while( true ) {
    if (*(char *)(iVar5 + 0x92) == '\0') break;
    iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
    iVar4 = (uint)bVar3 * 0xe;
    if (-1 < *(short *)(iVar6 + iVar4)) break;
    iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
    iVar9 = iVar4 + 2;
    uVar2 = *(ushort *)(iVar6 + iVar9);
    iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
    uVar10 = (uint)*(ushort *)(iVar4 + 4 + iVar6);
    uVar11 = uVar2 & 3;
    if ((uVar2 & 3) == 0) {
_L343:
      r_assert_err(0,"lld_con.c",0x9c7);
    }
    else {
      if (uVar11 < 3) {
        iVar4 = r_emi_get_mem_addr_by_offset(0x1400);
        uVar12 = (uint)(*(ushort *)(iVar4 + iVar9) >> 8);
        if (uVar12 < 5) {
          if (uVar12 == 0) goto _L345;
        }
        else if ((*(ushort *)(iVar5 + 0x84) & 0x40) != 0) {
          uVar12 = uVar12 - 4 & 0xffff;
        }
        iVar4 = *(int *)(iVar5 + 0x28);
        if (iVar4 == 0) {
          r_assert_err(0,"lld_con.c",0x9a7);
        }
        if (uVar12 + uVar10 < (*(ushort *)(iVar4 + 6) & 0x3ff) + (uint)*(ushort *)(iVar4 + 4))
        goto _L345;
        r_co_list_pop_front(iVar5 + 0x28);
        if (*(int *)(iVar5 + 0x30) == iVar4) {
          *(undefined4 *)(iVar5 + 0x30) = 0;
        }
        r_ble_util_buf_acl_tx_free_in_isr(*(undefined2 *)(iVar4 + 4));
        uVar7 = 0x20e;
      }
      else {
        if (uVar11 != 3) goto _L343;
        r_ble_util_buf_llcp_tx_free(uVar10);
        uVar7 = 0x20c;
      }
      r_ke_msg_send_basic(uVar7,param_1 << 8 | 1,0xff);
    }
_L345:
    iVar4 = r_emi_get_mem_addr_by_offset(0x1400);
    uVar2 = *(ushort *)(iVar4 + iVar9);
    iVar4 = r_emi_get_mem_addr_by_offset(0x1400);
    *(ushort *)(iVar4 + iVar9) = uVar2 & 0xffef;
    cVar1 = *(char *)(iVar5 + 0x92);
    *(char *)(iVar5 + 0x92) = cVar1 + -1;
    if (cVar1 == '\x01') {
      bVar3 = *(byte *)(iVar5 + 0x8e);
      bStack_42 = 0;
      abStack_41[0] = 0;
      iVar4 = r_emi_get_mem_addr_by_offset(0x400);
      iVar6 = (uint)bVar3 * 0x5a;
      r_bt_rma_get_ant_by_act(*(ushort *)(iVar4 + iVar6) & 0x1f,&bStack_42,abStack_41);
      uVar12 = (uint)bStack_42;
      uVar10 = (uint)abStack_41[0];
      iVar4 = r_emi_get_mem_addr_by_offset(0x400);
      uVar2 = *(ushort *)(iVar4 + iVar6);
      if ((uVar12 << 7 & 0xffffff7f) != 0) {
        r_assert_err(0,"lld_con.c",0x42);
      }
      if ((uVar10 << 6 & 0xffffffbf) != 0) {
        r_assert_err(0,"lld_con.c",0x43);
      }
      iVar4 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar4 + iVar6) =
           (ushort)(uVar12 << 7) | (ushort)(uVar10 << 6) | (ushort)((uVar8 & 1) << 10) |
           (ushort)((uVar8 & 2) << 8) | (ushort)((uVar8 & 4) << 6) | uVar2 & 0x1f;
    }
    bVar3 = *(char *)(iVar5 + 0x90) + 1U & 1;
    *(byte *)(iVar5 + 0x90) = bVar3;
    bVar3 = bVar3 + *(char *)(iVar5 + 0x8e) * '\t';
  }
  *(ushort *)(iVar5 + 0x84) =
       *(ushort *)(iVar5 + 0x84) & 0xfff7 | (ushort)(*(char *)(iVar5 + 0x92) != '\0') << 3;
  return;
}

