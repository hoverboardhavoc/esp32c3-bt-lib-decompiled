/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llc_con_upd.o -> r_llc_rem_con_upd_proc_err_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_llc_rem_con_upd_proc_err_cb(int param_1,int param_2,byte *param_3)

{
  byte bVar1;
  ushort uVar2;
  char cVar3;
  undefined2 uVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  
  if (param_2 == 2) {
    bVar1 = param_3[1];
_L189:
    iVar9 = 9;
  }
  else {
    if (param_2 == 3) {
      if (param_3[1] != 0x10) {
        return;
      }
      bVar1 = param_3[2];
      goto _L189;
    }
    if (param_2 != 0) {
      return;
    }
    bVar1 = *param_3;
    iVar9 = 0xb;
  }
  uVar10 = (uint)bVar1;
  if (uVar10 == 0) {
    return;
  }
  iVar5 = r_llc_proc_get(1);
  iVar11 = *(int *)(&llc_env + param_1 * 4);
  if (iVar9 == 0xb) {
    r_llc_proc_state_set(param_1,0xb);
    r_lld_con_tx_len_update_for_intv(param_1,*(undefined2 *)(iVar11 + 0xe));
  }
  iVar6 = r_llc_proc_state_get(iVar5);
  if (iVar6 != iVar9) {
    r_llc_proc_state_get(iVar5);
    r_assert_warn(iVar9,"llc_con_upd.c",0x1eb);
    return;
  }
  cVar3 = r_llc_proc_state_get(iVar5);
  switch(cVar3 + -7) {
  case '\0':
_L171:
    *(ushort *)(iVar11 + 0x42) = *(ushort *)(iVar11 + 0x42) | 0x10;
    if (*(char *)(iVar5 + 0x2c) == '\0') {
      uVar2 = *(ushort *)(iVar11 + 0xe);
      if (((uVar2 < *(ushort *)(iVar5 + 8)) || (*(ushort *)(iVar5 + 10) < uVar2)) ||
         (*(int *)(iVar5 + 0xc) != *(int *)(iVar11 + 0x10))) {
        r_llc_hci_con_param_req_evt_send
                  (param_1,*(undefined2 *)(iVar5 + 0xc),*(undefined2 *)(iVar5 + 0xe));
        r_llc_proc_state_set(iVar5,param_1,8);
        *(undefined1 *)(iVar5 + 0x2e) = 1;
        return;
      }
      *(ushort *)(iVar5 + 8) = uVar2;
      *(ushort *)(iVar5 + 10) = uVar2;
      goto _L170;
    }
    uVar10 = r_lld_con_param_update
                       (param_1,*(undefined1 *)(iVar5 + 0x26),*(undefined2 *)(iVar5 + 0x22),
                        *(undefined2 *)(iVar5 + 0x28),*(undefined2 *)(iVar5 + 0xc),
                        *(undefined2 *)(iVar5 + 0xe),*(undefined2 *)(iVar5 + 0x24));
    if (uVar10 == 0) {
      r_llc_proc_state_set(iVar5,param_1,10);
      return;
    }
    break;
  case '\x01':
_L170:
    if (uVar10 == 0) {
      if ((*(ushort *)(iVar11 + 0x42) & 1) == 0) {
        uVar4 = r_lld_con_event_counter_get(param_1);
        *(undefined2 *)(iVar5 + 0x14) = uVar4;
        r_llc_pref_param_compute_eco(param_1,iVar5);
        *(undefined2 *)(iVar5 + 0x16) = *(undefined2 *)(iVar5 + 0x2a);
        llc_ll_connection_param_rsp_pdu_send(param_1,iVar5);
        r_llc_proc_state_set(iVar5,param_1,9);
        r_llc_proc_timer_set(param_1,1,1);
        r_lld_con_tx_len_update_for_intv(param_1,*(undefined2 *)(iVar5 + 8));
        return;
      }
      puVar7 = (undefined4 *)r_ke_msg_alloc(0x10b,param_1 << 8 | 1,0x30);
      memcpy(puVar7 + 1,(void *)(iVar5 + 4),0x2c);
      *puVar7 = r_llc_loc_con_upd_proc_err_cb;
      r_llc_proc_state_set(puVar7,param_1,1);
      r_ke_msg_send(puVar7);
    }
    else {
      r_llc_ll_reject_ind_pdu_send(param_1,0xf,uVar10,0);
    }
    goto _L177;
  case '\x02':
    if (uVar10 == 0) {
      r_llc_proc_timer_set(param_1,1,0);
      *(undefined1 *)(iVar5 + 0x2c) = 1;
      goto _L171;
    }
    break;
  case '\x03':
  case '\x04':
    break;
  default:
    uVar8 = r_llc_proc_state_get(iVar5);
    r_assert_param(param_1,uVar8,"llc_con_upd.c",0x268);
    return;
  }
  r_llc_hci_con_upd_info_send_eco(param_1,uVar10,iVar5);
  *(ushort *)(iVar11 + 0x42) = *(ushort *)(iVar11 + 0x42) & 0xffef;
_L177:
  r_llc_proc_unreg(param_1,1);
  return;
}

