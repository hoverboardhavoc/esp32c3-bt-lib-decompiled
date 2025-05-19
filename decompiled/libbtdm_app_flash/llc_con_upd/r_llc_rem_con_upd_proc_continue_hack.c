/*
 * Last changed at upstream commit 72599d583c232ea78d6461b5b502426c6e5a1ec9
 * https://github.com/espressif/esp32c3-bt-lib/commit/72599d583c232ea78d6461b5b502426c6e5a1ec9
 * Upstream date: 2025-05-19 16:27:45 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(6cfabcd8)
 * Source: libbtdm_app_flash -> llc_con_upd.o -> r_llc_rem_con_upd_proc_continue_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_llc_rem_con_upd_proc_continue_hack(int param_1,int param_2,int param_3)

{
  ushort uVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  int iVar8;
  
  iVar3 = r_llc_proc_get(1);
  iVar8 = *(int *)(&llc_env + param_1 * 4);
  if (param_2 == 0xb) {
    r_llc_proc_state_set(param_1,0xb);
    r_lld_con_tx_len_update_for_intv(param_1,*(undefined2 *)(iVar8 + 0xe));
  }
  iVar4 = r_llc_proc_state_get(iVar3);
  if (iVar4 != param_2) {
    r_llc_proc_state_get(iVar3);
    r_assert_warn(param_2,"llc_con_upd.c",0x1eb);
    return;
  }
  uVar5 = r_llc_proc_state_get(iVar3);
  if (uVar5 == 9) {
    if (param_3 == 0) {
      r_llc_proc_timer_set(param_1,1,0);
      *(undefined1 *)(iVar3 + 0x2c) = 1;
_L166:
      *(ushort *)(iVar8 + 0x42) = *(ushort *)(iVar8 + 0x42) | 0x10;
      if (*(char *)(iVar3 + 0x2c) == '\0') {
        uVar1 = *(ushort *)(iVar8 + 0xe);
        if (((uVar1 < *(ushort *)(iVar3 + 8)) || (*(ushort *)(iVar3 + 10) < uVar1)) ||
           (*(int *)(iVar3 + 0xc) != *(int *)(iVar8 + 0x10))) {
          r_llc_hci_con_param_req_evt_send
                    (param_1,*(undefined2 *)(iVar3 + 0xc),*(undefined2 *)(iVar3 + 0xe));
          r_llc_proc_state_set(iVar3,param_1,8);
          *(undefined1 *)(iVar3 + 0x2e) = 1;
          return;
        }
        *(ushort *)(iVar3 + 8) = uVar1;
        *(ushort *)(iVar3 + 10) = uVar1;
        goto _L167;
      }
      param_3 = r_lld_con_param_update
                          (param_1,*(undefined1 *)(iVar3 + 0x26),*(undefined2 *)(iVar3 + 0x22),
                           *(undefined2 *)(iVar3 + 0x28),*(undefined2 *)(iVar3 + 0xc),
                           *(undefined2 *)(iVar3 + 0xe),*(undefined2 *)(iVar3 + 0x24));
      if (param_3 == 0) {
        r_llc_proc_state_set(iVar3,param_1,10);
        return;
      }
    }
  }
  else {
    if (uVar5 < 10) {
      if (uVar5 == 7) goto _L166;
      if (uVar5 != 8) goto _L168;
_L167:
      if (param_3 == 0) {
        if ((*(ushort *)(iVar8 + 0x42) & 1) == 0) {
          uVar2 = r_lld_con_event_counter_get(param_1);
          *(undefined2 *)(iVar3 + 0x14) = uVar2;
          r_llc_pref_param_compute_eco(param_1,iVar3);
          *(undefined2 *)(iVar3 + 0x16) = *(undefined2 *)(iVar3 + 0x2a);
          llc_ll_connection_param_rsp_pdu_send(param_1,iVar3);
          r_llc_proc_state_set(iVar3,param_1,9);
          r_llc_proc_timer_set(param_1,1,1);
          r_lld_con_tx_len_update_for_intv(param_1,*(undefined2 *)(iVar3 + 8));
          return;
        }
        puVar7 = (undefined4 *)r_ke_msg_alloc(0x10b,param_1 << 8 | 1,0x30);
        memcpy(puVar7 + 1,(void *)(iVar3 + 4),0x2c);
        *puVar7 = r_llc_loc_con_upd_proc_err_cb;
        r_llc_proc_state_set(puVar7,param_1,1);
        r_ke_msg_send(puVar7);
      }
      else {
        r_llc_ll_reject_ind_pdu_send(param_1,0xf,param_3,0);
      }
      goto _L175;
    }
    if (1 < (uVar5 - 10 & 0xff)) {
_L168:
      uVar6 = r_llc_proc_state_get(iVar3);
      r_assert_param(param_1,uVar6,"llc_con_upd.c",0x268);
      return;
    }
  }
  r_llc_hci_con_upd_info_send_eco(param_1,param_3,iVar3);
  *(ushort *)(iVar8 + 0x42) = *(ushort *)(iVar8 + 0x42) & 0xffef;
_L175:
  r_llc_proc_unreg(param_1,1);
  return;
}

