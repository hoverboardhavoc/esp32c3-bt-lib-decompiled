/*
 * Last changed at upstream commit bc9fd38197fb6a50e1b09791498782a1797e4757
 * https://github.com/espressif/esp32c3-bt-lib/commit/bc9fd38197fb6a50e1b09791498782a1797e4757
 * Upstream date: 2025-03-14 10:49:41 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(99e9a8dd)
 * Source: libbtdm_app_flash -> llc_encrypt.o -> r_llc_ll_start_enc_rsp_ack_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x000106cc) */

void r_llc_ll_start_enc_rsp_ack_handler(uint param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  ushort *puVar4;
  int iVar5;
  ushort uVar6;
  int iVar7;
  int iVar8;
  
  iVar5 = r_llc_proc_id_get(1);
  if (iVar5 != 3) {
    return;
  }
  uVar3 = r_llc_proc_get(1);
  puVar4 = (ushort *)r_llc_enc_state_get();
  iVar5 = r_llc_proc_state_get(uVar3);
  if (((iVar5 != 0x11) || (iVar5 = r_llc_proc_state_get(uVar3), iVar5 == 0x11)) || (iVar5 == 0x12))
  {
    *puVar4 = ~(ushort)(1 << (param_1 & 0x1f)) & *puVar4;
  }
  iVar7 = 0;
  iVar8 = *(int *)(&llc_env + param_1 * 4);
  iVar5 = r_llc_proc_get(1);
  iVar2 = r_llc_proc_state_get();
  if (iVar2 != 0x11) {
    r_llc_disconnect(param_1,0x3d,1);
    iVar7 = 0x3d;
    goto _L75;
  }
  cVar1 = r_llc_proc_state_get(iVar5);
  switch(cVar1 + -10) {
  case '\0':
    r_lld_con_data_flow_set(param_1,0);
    r_llc_proc_timer_pause_set(param_1,0,1);
    if ((uint)*(byte *)(iVar5 + 0x3a) != ((int)(uint)*(ushort *)(iVar8 + 0x42) >> 5 & 1U)) {
      r_llc_ll_reject_ind_pdu_send(param_1,3,0x24,r_llc_ll_reject_ind_ack_handler);
      r_llc_proc_state_set(iVar5,param_1,0x12);
    }
    if (*(char *)(iVar5 + 0x3a) == '\0') {
      r_llc_llcp_state_set(param_1,2,2);
      r_llc_iv_skd_rand_gen(param_1);
      uVar3 = 0xd;
      goto _L107;
    }
    r_lld_con_rx_enc(param_1,0);
    r_llc_llcp_state_set(param_1,2,1);
    llc_ll_pause_enc_rsp_pdu_send(param_1,0);
    uVar3 = 0xb;
    break;
  case '\x01':
    r_lld_con_tx_enc(param_1,0);
    uVar3 = 0xc;
    break;
  case '\x02':
    r_llc_llcp_state_set(param_1,2,2);
    r_llc_iv_skd_rand_gen(param_1);
    r_llc_proc_state_set(iVar5,param_1,0xd);
    uVar3 = 0;
    goto _L109;
  case '\x03':
    iVar2 = r_llm_le_evt_mask_check(4);
    if (iVar2 == 0) {
      r_llc_ll_reject_ind_pdu_send(param_1,3,6,r_llc_ll_reject_ind_ack_handler);
      uVar3 = 0x12;
    }
    else {
      llc_ll_enc_rsp_pdu_send(param_1,iVar5 + 0x30,iVar5 + 0x24);
      r_llc_hci_ltk_request_evt_send(param_1,*(undefined2 *)(iVar5 + 0x38),iVar5 + 8);
      uVar3 = 0xe;
    }
    goto _L107;
  case '\x04':
    r_llc_sk_gen(param_1,iVar5 + 0x10,iVar5 + 0x28);
    uVar3 = 0xf;
_L107:
    r_llc_proc_state_set(iVar5,param_1,uVar3);
    return;
  case '\x05':
    r_lld_con_enc_key_load(param_1,iVar5 + 0x10,iVar5 + 0x20);
    r_lld_con_rx_enc(param_1,1);
    llc_ll_start_enc_req_pdu_send(param_1);
    r_llc_proc_state_set(iVar5,param_1,0x10);
    r_llc_proc_timer_set(param_1,1,1);
    uVar6 = *(ushort *)(iVar8 + 0x42) | 0x200;
    goto _L106;
  case '\x06':
    r_llc_proc_timer_set(param_1,1,0);
    r_lld_con_tx_enc(param_1,1);
    r_llc_proc_state_set(iVar5,param_1,0x11);
    r_llc_llcp_send_eco(param_1,&stack0xffffffec,r_llc_ll_start_enc_rsp_ack_handler);
    return;
  case '\b':
    iVar7 = 6;
  case '\a':
_L75:
    iVar2 = r_sdk_config_get_opts();
    if (((param_1 < *(byte *)(iVar2 + 0xd)) && (*(int *)(&llc_env + param_1 * 4) != 0)) &&
       ((*(byte *)(*(int *)(&llc_env + param_1 * 4) + 0x44) & 3) != 3)) {
      r_lld_con_data_flow_set(param_1,1);
      r_llc_llcp_state_set(param_1,2,0);
      if ((iVar7 == 0) || (*(char *)(iVar5 + 0x3a) != '\0')) {
        r_llc_hci_enc_evt_send(param_1,iVar7);
      }
      *(ushort *)(iVar8 + 0x42) = *(ushort *)(iVar8 + 0x42) & 0xffdf | (ushort)(iVar7 == 0) << 5;
      r_llc_le_ping_restart(param_1);
      r_llc_proc_timer_pause_set(param_1,0,0);
    }
    r_llc_proc_unreg(param_1,1);
    uVar6 = *(ushort *)(iVar8 + 0x42) & 0xfdff;
_L106:
    *(ushort *)(iVar8 + 0x42) = uVar6;
    return;
  default:
    uVar3 = r_llc_proc_state_get(iVar5);
    r_assert_param(param_1,uVar3,"llc_encrypt.c",0x452);
    return;
  }
  r_llc_proc_state_set(iVar5,param_1,uVar3);
  uVar3 = 1;
_L109:
  r_llc_proc_timer_set(param_1,1,uVar3);
  return;
}

