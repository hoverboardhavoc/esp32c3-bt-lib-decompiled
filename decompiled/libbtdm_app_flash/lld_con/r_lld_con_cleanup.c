/*
 * Last changed at upstream commit d2414a5dd958b32ca53382b441d24d97a0345a55
 * https://github.com/espressif/esp32c3-bt-lib/commit/d2414a5dd958b32ca53382b441d24d97a0345a55
 * Upstream date: 2025-03-20 20:11:19 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(03d0f8a6)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_cleanup
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_con_cleanup(uint param_1,int param_2,int param_3)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  undefined1 *puVar6;
  int iVar7;
  undefined4 uVar8;
  ushort uVar9;
  int iVar10;
  uint uVar11;
  
  iVar4 = *(int *)(&lld_con_env + param_1 * 4);
  if (iVar4 == 0) {
    return;
  }
  iVar5 = r_sdk_config_get_opts_ext();
  if (((*(uint *)(iVar5 + 0x28) & 0x20) != 0) &&
     (iVar5 = r_sdk_config_get_opts_ext(), *(byte *)(iVar5 + 0x2c) < 3)) {
    r_ble_log_internal_x1(0x40030003,param_2 << 8 | param_3 << 0x10 | param_1);
  }
  if (param_2 != 0) {
    uVar11 = param_1 << 8 | 1;
    puVar6 = (undefined1 *)r_ke_msg_alloc(0x212,uVar11,0xff,1);
    *puVar6 = (char)param_3;
    r_ke_msg_send();
    iVar5 = r_co_list_pop_front(iVar4 + 0x28);
    while (*(char *)(iVar4 + 0x92) != '\0') {
      bVar1 = *(byte *)(iVar4 + 0x8e);
      bVar2 = *(byte *)(iVar4 + 0x90);
      iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
      iVar10 = ((uint)bVar1 * 9 + (uint)bVar2 & 0xff) * 0xe;
      uVar3 = *(ushort *)(iVar7 + iVar10 + 2);
      uVar9 = uVar3 & 3;
      if ((uVar3 & 3) == 0) {
_L146:
        uVar8 = 0x7a8;
_L167:
        r_assert_err(0,"lld_con.c",uVar8);
      }
      else if (2 < uVar9) {
        if (uVar9 != 3) goto _L146;
        iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
        r_ble_util_buf_llcp_tx_free(*(undefined2 *)(iVar10 + 4 + iVar7));
        uVar8 = 0x79f;
        if (*(int *)(iVar4 + 0x24) == 0) goto _L147;
        goto _L167;
      }
_L147:
      *(char *)(iVar4 + 0x92) = *(char *)(iVar4 + 0x92) + -1;
      *(byte *)(iVar4 + 0x90) = *(char *)(iVar4 + 0x90) + 1U & 1;
    }
    if (*(int *)(iVar4 + 0x24) != 0) {
      r_ble_util_buf_llcp_tx_free(*(undefined2 *)(*(int *)(iVar4 + 0x24) + 4));
    }
    while (iVar5 != 0) {
      r_ble_util_buf_acl_tx_free_in_isr(*(undefined2 *)(iVar5 + 4));
      if (DAT_0001608d != '\0') {
        r_ke_msg_send_basic(0x20e,uVar11,0xff);
      }
      iVar5 = r_co_list_pop_front(iVar4 + 0x28);
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

