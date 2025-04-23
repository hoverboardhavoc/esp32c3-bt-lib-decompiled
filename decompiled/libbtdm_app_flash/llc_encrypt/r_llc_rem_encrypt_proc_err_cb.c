/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llc_encrypt.o -> r_llc_rem_encrypt_proc_err_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_llc_rem_encrypt_proc_err_cb(uint param_1,int param_2,char *param_3)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  ushort *puVar4;
  int iVar5;
  char cVar6;
  ushort uVar7;
  int iVar8;
  
  if (param_2 == 0) {
    cVar6 = *param_3;
  }
  else {
    if (2 < (param_2 - 1U & 0xff)) {
      r_assert_param("llc_encrypt.c",0x614);
      return;
    }
    if ((*(byte *)(*(int *)(&llc_env + param_1 * 4) + 0x44) & 3) == 0) {
      return;
    }
    cVar6 = '=';
  }
  iVar8 = *(int *)(&llc_env + param_1 * 4);
  iVar3 = r_llc_proc_get(1);
  puVar4 = (ushort *)r_llc_enc_state_get();
  iVar5 = r_llc_proc_state_get(iVar3);
  if (iVar5 == 0x13) {
    iVar5 = r_llc_proc_state_get(iVar3);
    if (iVar5 == 0x10) {
      r_llc_proc_timer_set(param_1,1,0);
      r_lld_con_tx_enc(param_1,1);
      llc_ll_start_enc_rsp_pdu_send(param_1,0);
      *puVar4 = ~(ushort)(1 << (param_1 & 0x1f)) & *puVar4;
      iVar5 = r_sdk_config_get_opts();
      if (((param_1 < *(byte *)(iVar5 + 0xd)) &&
          (iVar5 = *(int *)(&llc_env + param_1 * 4), iVar5 != 0)) &&
         ((*(byte *)(iVar5 + 0x44) & 3) != 3)) {
        r_lld_con_data_flow_set(param_1,1);
        r_llc_llcp_state_set(param_1,2,0);
        if ((cVar6 == '\0') || (*(char *)(iVar3 + 0x3a) != '\0')) {
          r_llc_hci_enc_evt_send(param_1,cVar6);
        }
        *(ushort *)(iVar8 + 0x42) =
             (ushort)(cVar6 == '\0') << 5 | *(ushort *)(iVar8 + 0x42) & 0xffdf;
        r_llc_le_ping_restart(param_1);
        r_llc_proc_timer_pause_set(param_1,0,0);
      }
      r_llc_proc_unreg(param_1,1);
      *(ushort *)(iVar8 + 0x42) = *(ushort *)(iVar8 + 0x42) & 0xfdff;
      return;
    }
    if (iVar5 == 0x12) goto _L113;
  }
  else {
_L113:
    *puVar4 = ~(ushort)(1 << (param_1 & 0x1f)) & *puVar4;
  }
  iVar8 = *(int *)(&llc_env + param_1 * 4);
  iVar3 = r_llc_proc_get(1);
  iVar5 = r_llc_proc_state_get();
  if (iVar5 != 0x13) {
    if (cVar6 == '=') {
      r_llc_disconnect(param_1,0x3d,1);
      cVar6 = '=';
    }
    goto _L76;
  }
  cVar1 = r_llc_proc_state_get(iVar3);
  switch(cVar1 + -10) {
  case '\0':
    r_lld_con_data_flow_set(param_1,0);
    r_llc_proc_timer_pause_set(param_1,0,1);
    if ((uint)*(byte *)(iVar3 + 0x3a) != ((int)(uint)*(ushort *)(iVar8 + 0x42) >> 5 & 1U)) {
      r_llc_ll_reject_ind_pdu_send(param_1,3,0x24,r_llc_ll_reject_ind_ack_handler);
      r_llc_proc_state_set(iVar3,param_1,0x12);
    }
    if (*(char *)(iVar3 + 0x3a) == '\0') {
      r_llc_llcp_state_set(param_1,2);
      r_llc_iv_skd_rand_gen(param_1);
      uVar2 = 0xd;
      goto _L106;
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
    r_llc_llcp_state_set(param_1,2);
    r_llc_iv_skd_rand_gen(param_1);
    r_llc_proc_state_set(iVar3,param_1,0xd);
    uVar2 = 0;
    goto _L108;
  case '\x03':
    iVar5 = r_llm_le_evt_mask_check(4);
    if (iVar5 != 0) {
      llc_ll_enc_rsp_pdu_send(param_1,iVar3 + 0x30,iVar3 + 0x24);
      r_llc_hci_ltk_request_evt_send(param_1,*(undefined2 *)(iVar3 + 0x38),iVar3 + 8);
      uVar2 = 0xe;
      goto _L106;
    }
    goto _L89;
  case '\x04':
    if (cVar6 == '\0') {
      r_llc_sk_gen(param_1,iVar3 + 0x10,iVar3 + 0x28);
      uVar2 = 0xf;
      goto _L106;
    }
_L89:
    r_llc_ll_reject_ind_pdu_send(param_1,3,6,r_llc_ll_reject_ind_ack_handler);
    uVar2 = 0x12;
_L106:
    r_llc_proc_state_set(iVar3,param_1,uVar2);
    return;
  case '\x05':
    r_lld_con_enc_key_load(param_1,iVar3 + 0x10,iVar3 + 0x20);
    r_lld_con_rx_enc(param_1,1);
    llc_ll_start_enc_req_pdu_send(param_1);
    r_llc_proc_state_set(iVar3,param_1,0x10);
    r_llc_proc_timer_set(param_1,1);
    uVar7 = *(ushort *)(iVar8 + 0x42) | 0x200;
    goto _L105;
  case '\x06':
    r_llc_proc_timer_set(param_1,1,0);
    r_lld_con_tx_enc(param_1,1);
    r_llc_proc_state_set(iVar3,param_1,0x11);
    r_llc_llcp_send_eco(param_1,&stack0xffffffec,r_llc_ll_start_enc_rsp_ack_handler);
    return;
  case '\a':
    goto _L76;
  case '\b':
    cVar6 = '\x06';
    goto _L76;
  default:
    uVar2 = r_llc_proc_state_get(iVar3);
    r_assert_param(param_1,uVar2,"llc_encrypt.c",0x473);
    return;
  }
  r_llc_proc_state_set(iVar3,param_1,uVar2);
  uVar2 = 1;
_L108:
  r_llc_proc_timer_set(param_1,1,uVar2);
  return;
_L76:
  iVar5 = r_sdk_config_get_opts();
  if (((param_1 < *(byte *)(iVar5 + 0xd)) && (*(int *)(&llc_env + param_1 * 4) != 0)) &&
     ((*(byte *)(*(int *)(&llc_env + param_1 * 4) + 0x44) & 3) != 3)) {
    r_lld_con_data_flow_set(param_1,1);
    r_llc_llcp_state_set(param_1,2,0);
    if ((cVar6 == '\0') || (*(char *)(iVar3 + 0x3a) != '\0')) {
      r_llc_hci_enc_evt_send(param_1,cVar6);
    }
    *(ushort *)(iVar8 + 0x42) = (ushort)(cVar6 == '\0') << 5 | *(ushort *)(iVar8 + 0x42) & 0xffdf;
    r_llc_le_ping_restart(param_1);
    r_llc_proc_timer_pause_set(param_1,0,0);
  }
  r_llc_proc_unreg(param_1,1);
  uVar7 = *(ushort *)(iVar8 + 0x42) & 0xfdff;
_L105:
  *(ushort *)(iVar8 + 0x42) = uVar7;
  return;
}

