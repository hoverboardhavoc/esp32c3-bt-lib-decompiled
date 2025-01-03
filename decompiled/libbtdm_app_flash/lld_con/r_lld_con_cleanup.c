/*
 * Last changed at upstream commit ed99228396aaa18935b575d600bc19da38dc4746
 * https://github.com/espressif/esp32c3-bt-lib/commit/ed99228396aaa18935b575d600bc19da38dc4746
 * Upstream date: 2025-01-03 16:50:09 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(fd62b31)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_cleanup
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_con_cleanup(int param_1,int param_2,undefined1 param_3)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  undefined1 *puVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  ushort uVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  
  iVar11 = *(int *)(&lld_con_env + param_1 * 4);
  if (iVar11 == 0) {
    return;
  }
  if (param_2 != 0) {
    uVar10 = param_1 << 8 | 1;
    puVar4 = (undefined1 *)r_ke_msg_alloc(0x212,uVar10,0xff,1);
    *puVar4 = param_3;
    r_ke_msg_send();
    iVar5 = r_co_list_pop_front(iVar11 + 0x28);
    while (*(char *)(iVar11 + 0x92) != '\0') {
      bVar1 = *(byte *)(iVar11 + 0x8e);
      bVar2 = *(byte *)(iVar11 + 0x90);
      iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
      iVar9 = ((uint)bVar1 * 9 + (uint)bVar2 & 0xff) * 0xe;
      uVar3 = *(ushort *)(iVar6 + iVar9 + 2);
      uVar8 = uVar3 & 3;
      if ((uVar3 & 3) == 0) {
_L140:
        uVar7 = 0x795;
_L161:
        r_assert_err(0,"lld_con.c",uVar7);
      }
      else if (2 < uVar8) {
        if (uVar8 != 3) goto _L140;
        iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
        r_ble_util_buf_llcp_tx_free(*(undefined2 *)(iVar9 + 4 + iVar6));
        uVar7 = 0x78c;
        if (*(int *)(iVar11 + 0x24) == 0) goto _L141;
        goto _L161;
      }
_L141:
      *(char *)(iVar11 + 0x92) = *(char *)(iVar11 + 0x92) + -1;
      *(byte *)(iVar11 + 0x90) = *(char *)(iVar11 + 0x90) + 1U & 1;
    }
    if (*(int *)(iVar11 + 0x24) != 0) {
      r_ble_util_buf_llcp_tx_free(*(undefined2 *)(*(int *)(iVar11 + 0x24) + 4));
    }
    while (iVar5 != 0) {
      r_ble_util_buf_acl_tx_free_in_isr(*(undefined2 *)(iVar5 + 4));
      if (DAT_0001508d != '\0') {
        r_ke_msg_send_basic(0x20e,uVar10,0xff);
      }
      iVar5 = r_co_list_pop_front(iVar11 + 0x28);
    }
  }
  r_sch_slice_per_remove(4,param_1);
  r_ke_free(*(undefined4 *)(&lld_con_env + param_1 * 4));
  *(undefined4 *)(&lld_con_env + param_1 * 4) = 0;
  (&g_event_empty)[param_1] = 0;
  r_bt_rtp_deregister_rule_cs_idx(param_1);
  r_bt_rma_deregister_rule_cs_idx(param_1);
  return;
}

