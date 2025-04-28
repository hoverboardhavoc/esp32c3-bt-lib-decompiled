/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  int iVar9;
  uint uVar10;
  
  iVar4 = *(int *)(&lld_con_env + param_1 * 4);
  if (iVar4 == 0) {
    return;
  }
  iVar5 = r_sdk_config_get_opts_ext();
  if (((*(uint *)(iVar5 + 0x28) & 0x20) != 0) &&
     (iVar5 = r_sdk_config_get_opts_ext(), *(byte *)(iVar5 + 0x2c) < 3)) {
    r_ble_log_internal_x1(0x40030003,param_3 << 0x10 | param_2 << 8 | param_1);
  }
  if (param_2 != 0) {
    uVar10 = param_1 << 8 | 1;
    puVar6 = (undefined1 *)r_ke_msg_alloc(0x212,uVar10,0xff,1);
    *puVar6 = (char)param_3;
    r_ke_msg_send();
    iVar5 = r_co_list_pop_front(iVar4 + 0x28);
    while (*(char *)(iVar4 + 0x92) != '\0') {
      bVar1 = *(byte *)(iVar4 + 0x8e);
      bVar2 = *(byte *)(iVar4 + 0x90);
      iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
      iVar9 = ((uint)bVar1 * 9 + (uint)bVar2 & 0xff) * 0xe;
      uVar3 = *(ushort *)(iVar9 + 2 + iVar7);
      if ((uVar3 & 3) == 3) {
        iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
        r_ble_util_buf_llcp_tx_free(*(undefined2 *)(iVar9 + 4 + iVar7));
        uVar8 = 0x79f;
        if (*(int *)(iVar4 + 0x24) != 0) goto _L165;
      }
      else {
        uVar8 = 0x7a8;
        if ((uVar3 & 3) == 0) {
_L165:
          r_assert_err(0,"lld_con.c",uVar8);
        }
      }
      *(char *)(iVar4 + 0x92) = *(char *)(iVar4 + 0x92) + -1;
      *(byte *)(iVar4 + 0x90) = *(char *)(iVar4 + 0x90) + 1U & 1;
    }
    if (*(int *)(iVar4 + 0x24) != 0) {
      r_ble_util_buf_llcp_tx_free(*(undefined2 *)(*(int *)(iVar4 + 0x24) + 4));
    }
    while (iVar5 != 0) {
      r_ble_util_buf_acl_tx_free_in_isr(*(undefined2 *)(iVar5 + 4));
      if (DAT_0001608d != '\0') {
        r_ke_msg_send_basic(0x20e,uVar10,0xff);
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

