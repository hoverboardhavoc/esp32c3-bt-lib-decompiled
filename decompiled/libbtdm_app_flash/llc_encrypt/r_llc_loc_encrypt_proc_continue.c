/*
 * Last changed at upstream commit aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * https://github.com/espressif/esp32c3-bt-lib/commit/aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * Upstream date: 2025-03-20 20:31:24 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(d74042a8)
 * Source: libbtdm_app_flash -> llc_encrypt.o -> r_llc_loc_encrypt_proc_continue
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_llc_loc_encrypt_proc_continue(uint param_1,int param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  ushort uVar5;
  uint uVar6;
  int iVar7;
  
  iVar7 = *(int *)(&llc_env + param_1 * 4);
  iVar1 = r_llc_proc_get(0);
  iVar2 = r_llc_proc_state_get();
  if (iVar2 != param_2) {
    if (param_2 == 9) {
      if (param_3 != 0x13) {
        if (param_3 < 0x14) {
          if (param_3 == 6) {
            if (iVar2 != 5) goto _L30;
          }
          else {
            uVar6 = 8;
_L53:
            if (param_3 != uVar6) goto _L26;
          }
        }
        else {
          if (param_3 != 0x1a) {
            uVar6 = 0x22;
            goto _L53;
          }
_L30:
          if (iVar2 != 4) goto _L26;
        }
      }
    }
    else {
_L26:
      r_llc_disconnect(param_1,0x3d,1);
      param_3 = 0x3d;
    }
_L27:
    iVar2 = r_sdk_config_get_opts();
    if (((param_1 < *(byte *)(iVar2 + 0xd)) && (*(int *)(&llc_env + param_1 * 4) != 0)) &&
       ((*(byte *)(*(int *)(&llc_env + param_1 * 4) + 0x44) & 3) != 3)) {
      *(byte *)(iVar7 + 0x45) = *(byte *)(iVar7 + 0x45) & 0xf7;
      r_lld_con_data_flow_set(param_1,1);
      r_llc_llcp_state_set(param_1,2,0);
      r_llc_proc_timer_pause_set(param_1,1,0);
      *(ushort *)(iVar7 + 0x42) = *(ushort *)(iVar7 + 0x42) & 0xffdf | (ushort)(param_3 == 0) << 5;
      r_llc_le_ping_restart(param_1);
    }
    r_llc_hci_enc_evt_send(param_1,param_3,*(undefined1 *)(iVar1 + 0x3a));
    r_llc_proc_unreg(param_1,0);
    uVar5 = *(ushort *)(iVar7 + 0x42) & 0xfdff;
_L54:
    *(ushort *)(iVar7 + 0x42) = uVar5;
    return;
  }
  switch(param_2) {
  case 0:
    r_lld_con_data_flow_set(param_1,0);
    if (*(char *)(iVar1 + 0x3a) == '\0') goto _L58;
    llc_ll_pause_enc_req_pdu_send();
    r_llc_proc_state_set(iVar1,param_1,1);
    uVar4 = 1;
    break;
  case 1:
    r_llc_llcp_state_set(param_1,0,1);
    r_llc_proc_timer_pause_set(param_1,1,1);
    r_llc_proc_timer_set(param_1,0,0);
    r_lld_con_rx_enc(param_1,0);
    r_lld_con_tx_enc(param_1,0);
    llc_ll_pause_enc_rsp_pdu_send(param_1,r_llc_ll_pause_enc_rsp_ack_handler);
    uVar4 = 2;
    goto _L56;
  case 2:
_L58:
    r_llc_iv_skd_rand_gen(param_1);
    uVar4 = 3;
_L56:
    r_llc_proc_state_set(iVar1,param_1,uVar4);
    return;
  case 3:
    llc_ll_enc_req_pdu_send
              (param_1,*(undefined2 *)(iVar1 + 0x38),iVar1 + 8,iVar1 + 0x28,iVar1 + 0x20);
    r_llc_proc_state_set(iVar1,param_1,4);
    r_llc_proc_timer_set(param_1,0,1);
    uVar4 = 2;
    if (*(char *)(iVar1 + 0x3a) != '\0') {
      uVar3 = 2;
      uVar4 = 2;
      goto _L55;
    }
    break;
  case 4:
    r_llc_llcp_state_set(param_1,0,2);
    r_llc_proc_timer_pause_set(param_1,1,1);
    r_llc_proc_state_set(iVar1,param_1,5);
    uVar4 = 1;
    goto _L57;
  case 5:
    r_llc_sk_gen(param_1,iVar1 + 0x10,iVar1 + 0x28);
    r_llc_proc_state_set(iVar1,param_1,6);
    uVar4 = 0;
_L57:
    r_llc_proc_timer_set(param_1,0,uVar4);
    return;
  case 6:
    r_lld_con_enc_key_load(param_1,iVar1 + 0x10,iVar1 + 0x20);
    r_lld_con_rx_enc(param_1,1);
    r_lld_con_tx_enc(param_1,1);
    llc_ll_start_enc_rsp_pdu_send(param_1,0);
    r_llc_proc_state_set(iVar1,param_1,8);
    r_llc_proc_timer_set(param_1,0,1);
    uVar5 = *(ushort *)(iVar7 + 0x42) | 0x200;
    goto _L54;
  default:
    r_assert_param(param_1,param_2,"llc_encrypt.c",0x28b);
    return;
  case 8:
    r_llc_proc_timer_set(param_1,0,0);
    goto _L27;
  }
  uVar3 = 1;
_L55:
  r_llc_llcp_state_set(param_1,uVar3,uVar4);
  return;
}

