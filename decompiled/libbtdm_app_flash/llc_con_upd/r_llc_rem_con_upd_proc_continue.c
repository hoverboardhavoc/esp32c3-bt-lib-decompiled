/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llc_con_upd.o -> r_llc_rem_con_upd_proc_continue
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_llc_rem_con_upd_proc_continue(int param_1,int param_2,int param_3)

{
  ushort uVar1;
  char cVar2;
  undefined2 uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  int iVar8;
  
  iVar4 = r_llc_proc_get(1);
  iVar8 = *(int *)(&llc_env + param_1 * 4);
  if (param_2 == 0xb) {
    r_llc_proc_state_set(param_1,0xb);
    r_lld_con_tx_len_update_for_intv(param_1,*(undefined2 *)(iVar8 + 0xe));
  }
  iVar5 = r_llc_proc_state_get(iVar4);
  if (iVar5 != param_2) {
    r_llc_proc_state_get(iVar4);
    r_assert_warn(param_2,"llc_con_upd.c",0x1eb);
    return;
  }
  cVar2 = r_llc_proc_state_get(iVar4);
  switch(cVar2 + -7) {
  case '\0':
_L171:
    *(ushort *)(iVar8 + 0x42) = *(ushort *)(iVar8 + 0x42) | 0x10;
    if (*(char *)(iVar4 + 0x2c) == '\0') {
      uVar1 = *(ushort *)(iVar8 + 0xe);
      if (((uVar1 < *(ushort *)(iVar4 + 8)) || (*(ushort *)(iVar4 + 10) < uVar1)) ||
         (*(int *)(iVar4 + 0xc) != *(int *)(iVar8 + 0x10))) {
        r_llc_hci_con_param_req_evt_send
                  (param_1,*(undefined2 *)(iVar4 + 0xc),*(undefined2 *)(iVar4 + 0xe));
        r_llc_proc_state_set(iVar4,param_1,8);
        *(undefined1 *)(iVar4 + 0x2e) = 1;
        return;
      }
      *(ushort *)(iVar4 + 8) = uVar1;
      *(ushort *)(iVar4 + 10) = uVar1;
      goto _L170;
    }
    param_3 = r_lld_con_param_update
                        (param_1,*(undefined1 *)(iVar4 + 0x26),*(undefined2 *)(iVar4 + 0x22),
                         *(undefined2 *)(iVar4 + 0x28),*(undefined2 *)(iVar4 + 0xc),
                         *(undefined2 *)(iVar4 + 0xe),*(undefined2 *)(iVar4 + 0x24));
    if (param_3 == 0) {
      r_llc_proc_state_set(iVar4,param_1,10);
      return;
    }
    break;
  case '\x01':
_L170:
    if (param_3 == 0) {
      if ((*(ushort *)(iVar8 + 0x42) & 1) == 0) {
        uVar3 = r_lld_con_event_counter_get(param_1);
        *(undefined2 *)(iVar4 + 0x14) = uVar3;
        r_llc_pref_param_compute_eco(param_1,iVar4);
        *(undefined2 *)(iVar4 + 0x16) = *(undefined2 *)(iVar4 + 0x2a);
        llc_ll_connection_param_rsp_pdu_send(param_1,iVar4);
        r_llc_proc_state_set(iVar4,param_1,9);
        r_llc_proc_timer_set(param_1,1,1);
        r_lld_con_tx_len_update_for_intv(param_1,*(undefined2 *)(iVar4 + 8));
        return;
      }
      puVar6 = (undefined4 *)r_ke_msg_alloc(0x10b,param_1 << 8 | 1,0x30);
      memcpy(puVar6 + 1,(void *)(iVar4 + 4),0x2c);
      *puVar6 = r_llc_loc_con_upd_proc_err_cb;
      r_llc_proc_state_set(puVar6,param_1,1);
      r_ke_msg_send(puVar6);
    }
    else {
      r_llc_ll_reject_ind_pdu_send(param_1,0xf,param_3,0);
    }
    goto _L177;
  case '\x02':
    if (param_3 == 0) {
      r_llc_proc_timer_set(param_1,1,0);
      *(undefined1 *)(iVar4 + 0x2c) = 1;
      goto _L171;
    }
    break;
  case '\x03':
  case '\x04':
    break;
  default:
    uVar7 = r_llc_proc_state_get(iVar4);
    r_assert_param(param_1,uVar7,"llc_con_upd.c",0x268);
    return;
  }
  r_llc_hci_con_upd_info_send_eco(param_1,param_3,iVar4);
  *(ushort *)(iVar8 + 0x42) = *(ushort *)(iVar8 + 0x42) & 0xffef;
_L177:
  r_llc_proc_unreg(param_1,1);
  return;
}

