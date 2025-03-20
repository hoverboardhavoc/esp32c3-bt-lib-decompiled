/*
 * Last changed at upstream commit aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * https://github.com/espressif/esp32c3-bt-lib/commit/aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * Upstream date: 2025-03-20 20:31:24 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(d74042a8)
 * Source: libbtdm_app_flash -> llc_encrypt.o -> r_llc_rem_encrypt_proc_continue
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_llc_rem_encrypt_proc_continue(uint param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  ushort uVar5;
  int iVar6;
  
  iVar6 = *(int *)(&llc_env + param_1 * 4);
  iVar2 = r_llc_proc_get(1);
  iVar3 = r_llc_proc_state_get();
  if (iVar3 != param_2) {
    if ((param_2 != 0x13) || (param_3 == 0x3d)) {
      r_llc_disconnect(param_1,0x3d,1);
      param_3 = 0x3d;
    }
    goto _L75;
  }
  cVar1 = r_llc_proc_state_get(iVar2);
  switch(cVar1 + -10) {
  case '\0':
    r_lld_con_data_flow_set(param_1,0);
    r_llc_proc_timer_pause_set(param_1,0,1);
    if ((uint)*(byte *)(iVar2 + 0x3a) != ((int)(uint)*(ushort *)(iVar6 + 0x42) >> 5 & 1U)) {
      r_llc_ll_reject_ind_pdu_send(param_1,3,0x24,r_llc_ll_reject_ind_ack_handler);
      r_llc_proc_state_set(iVar2,param_1,0x12);
    }
    if (*(char *)(iVar2 + 0x3a) == '\0') {
      r_llc_llcp_state_set(param_1,2,2);
      r_llc_iv_skd_rand_gen(param_1);
      uVar4 = 0xd;
      goto _L107;
    }
    r_lld_con_rx_enc(param_1,0);
    r_llc_llcp_state_set(param_1,2,1);
    llc_ll_pause_enc_rsp_pdu_send(param_1,0);
    uVar4 = 0xb;
    break;
  case '\x01':
    r_lld_con_tx_enc(param_1,0);
    uVar4 = 0xc;
    break;
  case '\x02':
    r_llc_llcp_state_set(param_1,2,2);
    r_llc_iv_skd_rand_gen(param_1);
    r_llc_proc_state_set(iVar2,param_1,0xd);
    uVar4 = 0;
    goto _L109;
  case '\x03':
    iVar3 = r_llm_le_evt_mask_check(4);
    if (iVar3 != 0) {
      llc_ll_enc_rsp_pdu_send(param_1,iVar2 + 0x30,iVar2 + 0x24);
      r_llc_hci_ltk_request_evt_send(param_1,*(undefined2 *)(iVar2 + 0x38),iVar2 + 8);
      uVar4 = 0xe;
      goto _L107;
    }
    goto _L89;
  case '\x04':
    if (param_3 == 0) {
      r_llc_sk_gen(param_1,iVar2 + 0x10,iVar2 + 0x28);
      uVar4 = 0xf;
      goto _L107;
    }
_L89:
    r_llc_ll_reject_ind_pdu_send(param_1,3,6,r_llc_ll_reject_ind_ack_handler);
    uVar4 = 0x12;
_L107:
    r_llc_proc_state_set(iVar2,param_1,uVar4);
    return;
  case '\x05':
    r_lld_con_enc_key_load(param_1,iVar2 + 0x10,iVar2 + 0x20);
    r_lld_con_rx_enc(param_1,1);
    llc_ll_start_enc_req_pdu_send(param_1);
    r_llc_proc_state_set(iVar2,param_1,0x10);
    r_llc_proc_timer_set(param_1,1,1);
    uVar5 = *(ushort *)(iVar6 + 0x42) | 0x200;
    goto _L106;
  case '\x06':
    r_llc_proc_timer_set(param_1,1,0);
    r_lld_con_tx_enc(param_1,1);
    r_llc_proc_state_set(iVar2,param_1,0x11);
    r_llc_llcp_send_eco(param_1,&stack0xffffffec,r_llc_ll_start_enc_rsp_ack_handler);
    return;
  case '\a':
    goto _L75;
  case '\b':
    param_3 = 6;
    goto _L75;
  default:
    uVar4 = r_llc_proc_state_get(iVar2);
    r_assert_param(param_1,uVar4,"llc_encrypt.c",0x452);
    return;
  }
  r_llc_proc_state_set(iVar2,param_1,uVar4);
  uVar4 = 1;
_L109:
  r_llc_proc_timer_set(param_1,1,uVar4);
  return;
_L75:
  iVar3 = r_sdk_config_get_opts();
  if (((param_1 < *(byte *)(iVar3 + 0xd)) && (*(int *)(&llc_env + param_1 * 4) != 0)) &&
     ((*(byte *)(*(int *)(&llc_env + param_1 * 4) + 0x44) & 3) != 3)) {
    r_lld_con_data_flow_set(param_1,1);
    r_llc_llcp_state_set(param_1,2,0);
    if ((param_3 == 0) || (*(char *)(iVar2 + 0x3a) != '\0')) {
      r_llc_hci_enc_evt_send(param_1,param_3);
    }
    *(ushort *)(iVar6 + 0x42) = *(ushort *)(iVar6 + 0x42) & 0xffdf | (ushort)(param_3 == 0) << 5;
    r_llc_le_ping_restart(param_1);
    r_llc_proc_timer_pause_set(param_1,0,0);
  }
  r_llc_proc_unreg(param_1,1);
  uVar5 = *(ushort *)(iVar6 + 0x42) & 0xfdff;
_L106:
  *(ushort *)(iVar6 + 0x42) = uVar5;
  return;
}

