/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_cleanup
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_con_cleanup(uint param_1,int param_2,int param_3)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined1 *puVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  
  iVar3 = *(int *)(&lld_con_env + param_1 * 4);
  if (iVar3 == 0) {
    return;
  }
  iVar4 = r_sdk_config_get_opts_ext();
  if (((*(uint *)(iVar4 + 0x28) & 0x20) != 0) &&
     (iVar4 = r_sdk_config_get_opts_ext(), *(byte *)(iVar4 + 0x2c) < 3)) {
    r_ble_log_internal_x1(0x40030003,param_3 << 0x10 | param_2 << 8 | param_1);
  }
  if (param_2 != 0) {
    uVar8 = param_1 << 8 | 1;
    puVar5 = (undefined1 *)r_ke_msg_alloc(0x212,uVar8,0xff,1);
    *puVar5 = (char)param_3;
    r_ke_msg_send();
    iVar4 = r_co_list_pop_front(iVar3 + 0x28);
    while (*(char *)(iVar3 + 0x92) != '\0') {
      iVar2 = ((uint)*(byte *)(iVar3 + 0x8e) * 9 + (uint)*(byte *)(iVar3 + 0x90) & 0xff) * 0xe;
      iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
      uVar1 = *(ushort *)(iVar2 + 2 + iVar6);
      if ((uVar1 & 3) == 3) {
        iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
        r_ble_util_buf_llcp_tx_free(*(undefined2 *)(iVar2 + 4 + iVar6));
        uVar7 = 0x79f;
        if (*(int *)(iVar3 + 0x24) != 0) goto _L165;
      }
      else if ((uVar1 & 3) == 0) {
        uVar7 = 0x7a8;
_L165:
        r_assert_err(0,"lld_con.c",uVar7);
      }
      *(char *)(iVar3 + 0x92) = *(char *)(iVar3 + 0x92) + -1;
      *(byte *)(iVar3 + 0x90) = *(char *)(iVar3 + 0x90) + 1U & 1;
    }
    if (*(int *)(iVar3 + 0x24) != 0) {
      r_ble_util_buf_llcp_tx_free(*(undefined2 *)(*(int *)(iVar3 + 0x24) + 4));
    }
    while (iVar4 != 0) {
      r_ble_util_buf_acl_tx_free_in_isr(*(undefined2 *)(iVar4 + 4));
      if (DAT_0001608d != '\0') {
        r_ke_msg_send_basic(0x20e,uVar8,0xff);
      }
      iVar4 = r_co_list_pop_front(iVar3 + 0x28);
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

