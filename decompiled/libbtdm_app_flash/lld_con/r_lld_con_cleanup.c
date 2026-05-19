/*
 * Last changed at upstream commit 7e73ebf92e5aa995065351043c13d2ac0f00772e
 * https://github.com/espressif/esp32c3-bt-lib/commit/7e73ebf92e5aa995065351043c13d2ac0f00772e
 * Upstream date: 2026-05-19 17:43:45 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(bc853c5)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_cleanup
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_con_cleanup(int param_1,int param_2,uint param_3)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  undefined1 *puVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  
  iVar10 = *(int *)(&lld_con_env + param_1 * 4);
  if (iVar10 == 0) {
    return;
  }
  r_ble_log_internal_x3
            (0x4003010a,(int)(uint)*(ushort *)(iVar10 + 0x84) >> 1 & 1,
             (uint)*(ushort *)(iVar10 + 0x7c) | param_1 << 0x10 | param_2 << 0x18,
             (uint)*(byte *)(iVar10 + 0x8f) << 8 | (uint)*(byte *)(iVar10 + 0x92) << 0x10 | param_3)
  ;
  if (param_2 != 0) {
    uVar9 = param_1 << 8 | 1;
    puVar4 = (undefined1 *)r_ke_msg_alloc(0x212,uVar9,0xff,1);
    *puVar4 = (char)param_3;
    r_ke_msg_send();
    iVar5 = r_co_list_pop_front(iVar10 + 0x28);
    while (*(char *)(iVar10 + 0x92) != '\0') {
      bVar1 = *(byte *)(iVar10 + 0x8e);
      bVar2 = *(byte *)(iVar10 + 0x90);
      iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
      iVar8 = ((uint)bVar1 * 9 + (uint)bVar2 & 0xff) * 0xe;
      uVar3 = *(ushort *)(iVar8 + 2 + iVar6);
      if ((uVar3 & 3) == 3) {
        iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
        r_ble_util_buf_llcp_tx_free(*(undefined2 *)(iVar8 + 4 + iVar6));
        uVar7 = 0x89b;
        if (*(int *)(iVar10 + 0x24) != 0) goto _L165;
      }
      else {
        uVar7 = 0x8a4;
        if ((uVar3 & 3) == 0) {
_L165:
          r_assert_err(0,"lld_con.c",uVar7);
        }
      }
      *(char *)(iVar10 + 0x92) = *(char *)(iVar10 + 0x92) + -1;
      *(byte *)(iVar10 + 0x90) = *(char *)(iVar10 + 0x90) + 1U & 1;
    }
    if (*(int *)(iVar10 + 0x24) != 0) {
      r_ble_util_buf_llcp_tx_free(*(undefined2 *)(*(int *)(iVar10 + 0x24) + 4));
    }
    while (iVar5 != 0) {
      r_ble_util_buf_acl_tx_free_in_isr(*(undefined2 *)(iVar5 + 4));
      if (DAT_00016091 != '\0') {
        r_ke_msg_send_basic(0x20e,uVar9,0xff);
      }
      iVar5 = r_co_list_pop_front(iVar10 + 0x28);
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

