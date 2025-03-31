/*
 * Last changed at upstream commit 2fd7ad255fceabdfba56882ce4523efdba2fc255
 * https://github.com/espressif/esp32c3-bt-lib/commit/2fd7ad255fceabdfba56882ce4523efdba2fc255
 * Upstream date: 2025-03-31 11:18:40 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(566c8e3)
 * Source: libbtdm_app_flash -> llc_encrypt.o -> r_llc_ll_reject_ind_ack_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x000106cc) */
/* WARNING: Removing unreachable block (ram,0x00010b7a) */

void r_llc_ll_reject_ind_ack_handler(uint param_1)

{
  char cVar1;
  undefined4 uVar2;
  ushort *puVar3;
  int iVar4;
  ushort uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  iVar4 = r_llc_proc_id_get(1);
  if (iVar4 != 3) {
    return;
  }
  iVar8 = *(int *)(&llc_env + param_1 * 4);
  uVar2 = r_llc_proc_get(1);
  puVar3 = (ushort *)r_llc_enc_state_get();
  iVar4 = r_llc_proc_state_get(uVar2);
  if (iVar4 == 0x12) {
    iVar4 = r_llc_proc_state_get(uVar2);
    if (iVar4 == 0x10) {
      r_llc_proc_timer_set(param_1,1,0);
      r_lld_con_tx_enc(param_1,1);
      llc_ll_start_enc_rsp_pdu_send(param_1,0);
      *puVar3 = ~(ushort)(1 << (param_1 & 0x1f)) & *puVar3;
      iVar4 = r_sdk_config_get_opts();
      if (((param_1 < *(byte *)(iVar4 + 0xd)) &&
          (iVar4 = *(int *)(&llc_env + param_1 * 4), iVar4 != 0)) &&
         ((*(byte *)(iVar4 + 0x44) & 3) != 3)) {
        r_lld_con_data_flow_set(param_1,1);
        r_llc_llcp_state_set(param_1,2,0);
        r_llc_hci_enc_evt_send(param_1,0);
        *(ushort *)(iVar8 + 0x42) = *(ushort *)(iVar8 + 0x42) & 0xffdf | 0x20;
        r_llc_le_ping_restart(param_1);
        r_llc_proc_timer_pause_set(param_1,0,0);
      }
      r_llc_proc_unreg(param_1,1);
      *(ushort *)(iVar8 + 0x42) = *(ushort *)(iVar8 + 0x42) & 0xfdff;
      return;
    }
    if (iVar4 == 0x12) goto _L114;
  }
  else {
_L114:
    *puVar3 = ~(ushort)(1 << (param_1 & 0x1f)) & *puVar3;
  }
  iVar6 = 0;
  iVar7 = *(int *)(&llc_env + param_1 * 4);
  iVar4 = r_llc_proc_get(1);
  iVar8 = r_llc_proc_state_get();
  if (iVar8 != 0x12) {
    r_llc_disconnect(param_1,0x3d,1);
    iVar6 = 0x3d;
    goto _L75;
  }
  cVar1 = r_llc_proc_state_get(iVar4);
  switch(cVar1 + -10) {
  case '\0':
    r_lld_con_data_flow_set(param_1,0);
    r_llc_proc_timer_pause_set(param_1,0,1);
    if ((uint)*(byte *)(iVar4 + 0x3a) != ((int)(uint)*(ushort *)(iVar7 + 0x42) >> 5 & 1U)) {
      r_llc_ll_reject_ind_pdu_send(param_1,3,0x24,r_llc_ll_reject_ind_ack_handler);
      r_llc_proc_state_set(iVar4,param_1,0x12);
    }
    if (*(char *)(iVar4 + 0x3a) == '\0') {
      r_llc_llcp_state_set(param_1,2,2);
      r_llc_iv_skd_rand_gen(param_1);
      uVar2 = 0xd;
      goto _L107;
    }
    r_lld_con_rx_enc(param_1,0);
    r_llc_llcp_state_set(param_1,2,1);
    llc_ll_pause_enc_rsp_pdu_send(param_1,0);
    uVar2 = 0xb;
    break;
  case '\x01':
    r_lld_con_tx_enc(param_1,0);
    uVar2 = 0xc;
    break;
  case '\x02':
    r_llc_llcp_state_set(param_1,2,2);
    r_llc_iv_skd_rand_gen(param_1);
    r_llc_proc_state_set(iVar4,param_1,0xd);
    uVar2 = 0;
    goto _L109;
  case '\x03':
    iVar8 = r_llm_le_evt_mask_check(4);
    if (iVar8 == 0) {
      r_llc_ll_reject_ind_pdu_send(param_1,3,6,r_llc_ll_reject_ind_ack_handler);
      uVar2 = 0x12;
    }
    else {
      llc_ll_enc_rsp_pdu_send(param_1,iVar4 + 0x30,iVar4 + 0x24);
      r_llc_hci_ltk_request_evt_send(param_1,*(undefined2 *)(iVar4 + 0x38),iVar4 + 8);
      uVar2 = 0xe;
    }
    goto _L107;
  case '\x04':
    r_llc_sk_gen(param_1,iVar4 + 0x10,iVar4 + 0x28);
    uVar2 = 0xf;
_L107:
    r_llc_proc_state_set(iVar4,param_1,uVar2);
    return;
  case '\x05':
    r_lld_con_enc_key_load(param_1,iVar4 + 0x10,iVar4 + 0x20);
    r_lld_con_rx_enc(param_1,1);
    llc_ll_start_enc_req_pdu_send(param_1);
    r_llc_proc_state_set(iVar4,param_1,0x10);
    r_llc_proc_timer_set(param_1,1,1);
    uVar5 = *(ushort *)(iVar7 + 0x42) | 0x200;
    goto _L106;
  case '\x06':
    r_llc_proc_timer_set(param_1,1,0);
    r_lld_con_tx_enc(param_1,1);
    r_llc_proc_state_set(iVar4,param_1,0x11);
    r_llc_llcp_send_eco(param_1,&stack0xffffffec,r_llc_ll_start_enc_rsp_ack_handler);
    return;
  case '\b':
    iVar6 = 6;
  case '\a':
_L75:
    iVar8 = r_sdk_config_get_opts();
    if (((param_1 < *(byte *)(iVar8 + 0xd)) && (*(int *)(&llc_env + param_1 * 4) != 0)) &&
       ((*(byte *)(*(int *)(&llc_env + param_1 * 4) + 0x44) & 3) != 3)) {
      r_lld_con_data_flow_set(param_1,1);
      r_llc_llcp_state_set(param_1,2,0);
      if ((iVar6 == 0) || (*(char *)(iVar4 + 0x3a) != '\0')) {
        r_llc_hci_enc_evt_send(param_1,iVar6);
      }
      *(ushort *)(iVar7 + 0x42) = *(ushort *)(iVar7 + 0x42) & 0xffdf | (ushort)(iVar6 == 0) << 5;
      r_llc_le_ping_restart(param_1);
      r_llc_proc_timer_pause_set(param_1,0,0);
    }
    r_llc_proc_unreg(param_1,1);
    uVar5 = *(ushort *)(iVar7 + 0x42) & 0xfdff;
_L106:
    *(ushort *)(iVar7 + 0x42) = uVar5;
    return;
  default:
    uVar2 = r_llc_proc_state_get(iVar4);
    r_assert_param(param_1,uVar2,"llc_encrypt.c",0x473);
    return;
  }
  r_llc_proc_state_set(iVar4,param_1,uVar2);
  uVar2 = 1;
_L109:
  r_llc_proc_timer_set(param_1,1,uVar2);
  return;
}

