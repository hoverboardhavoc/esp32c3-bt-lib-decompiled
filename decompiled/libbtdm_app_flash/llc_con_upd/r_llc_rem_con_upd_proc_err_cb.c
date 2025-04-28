/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  undefined2 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  
  if (param_2 == 2) {
    bVar1 = param_3[1];
_L187:
    iVar9 = 9;
  }
  else {
    if (param_2 == 3) {
      if (param_3[1] != 0x10) {
        return;
      }
      bVar1 = param_3[2];
      goto _L187;
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
  iVar4 = r_llc_proc_get(1);
  iVar11 = *(int *)(&llc_env + param_1 * 4);
  if (iVar9 == 0xb) {
    r_llc_proc_state_set(param_1,0xb);
    r_lld_con_tx_len_update_for_intv(param_1,*(undefined2 *)(iVar11 + 0xe));
  }
  iVar5 = r_llc_proc_state_get(iVar4);
  if (iVar5 != iVar9) {
    r_llc_proc_state_get(iVar4);
    r_assert_warn(iVar9,"llc_con_upd.c",0x1eb);
    return;
  }
  uVar6 = r_llc_proc_state_get(iVar4);
  if (uVar6 == 9) {
    if (uVar10 == 0) {
      r_llc_proc_timer_set(param_1,1,0);
      *(undefined1 *)(iVar4 + 0x2c) = 1;
_L166:
      *(ushort *)(iVar11 + 0x42) = *(ushort *)(iVar11 + 0x42) | 0x10;
      if (*(char *)(iVar4 + 0x2c) == '\0') {
        uVar2 = *(ushort *)(iVar11 + 0xe);
        if (((uVar2 < *(ushort *)(iVar4 + 8)) || (*(ushort *)(iVar4 + 10) < uVar2)) ||
           (*(int *)(iVar4 + 0xc) != *(int *)(iVar11 + 0x10))) {
          r_llc_hci_con_param_req_evt_send
                    (param_1,*(undefined2 *)(iVar4 + 0xc),*(undefined2 *)(iVar4 + 0xe));
          r_llc_proc_state_set(iVar4,param_1,8);
          *(undefined1 *)(iVar4 + 0x2e) = 1;
          return;
        }
        *(ushort *)(iVar4 + 8) = uVar2;
        *(ushort *)(iVar4 + 10) = uVar2;
        goto _L167;
      }
      uVar10 = r_lld_con_param_update
                         (param_1,*(undefined1 *)(iVar4 + 0x26),*(undefined2 *)(iVar4 + 0x22),
                          *(undefined2 *)(iVar4 + 0x28),*(undefined2 *)(iVar4 + 0xc),
                          *(undefined2 *)(iVar4 + 0xe),*(undefined2 *)(iVar4 + 0x24));
      if (uVar10 == 0) {
        r_llc_proc_state_set(iVar4,param_1,10);
        return;
      }
    }
  }
  else {
    if (uVar6 < 10) {
      if (uVar6 == 7) goto _L166;
      if (uVar6 != 8) goto _L168;
_L167:
      if (uVar10 == 0) {
        if ((*(ushort *)(iVar11 + 0x42) & 1) == 0) {
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
        puVar8 = (undefined4 *)r_ke_msg_alloc(0x10b,param_1 << 8 | 1,0x30);
        memcpy(puVar8 + 1,(void *)(iVar4 + 4),0x2c);
        *puVar8 = r_llc_loc_con_upd_proc_err_cb;
        r_llc_proc_state_set(puVar8,param_1,1);
        r_ke_msg_send(puVar8);
      }
      else {
        r_llc_ll_reject_ind_pdu_send(param_1,0xf,uVar10,0);
      }
      goto _L175;
    }
    if (1 < (uVar6 - 10 & 0xff)) {
_L168:
      uVar7 = r_llc_proc_state_get(iVar4);
      r_assert_param(param_1,uVar7,"llc_con_upd.c",0x268);
      return;
    }
  }
  r_llc_hci_con_upd_info_send_eco(param_1,uVar10,iVar4);
  *(ushort *)(iVar11 + 0x42) = *(ushort *)(iVar11 + 0x42) & 0xffef;
_L175:
  r_llc_proc_unreg(param_1,1);
  return;
}

