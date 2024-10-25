/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llc_con_upd.o -> r_llc_loc_con_upd_proc_err_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_llc_loc_con_upd_proc_err_cb(uint param_1,int param_2,byte *param_3)

{
  short sVar1;
  int iVar2;
  undefined2 uVar3;
  short sVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  
  iVar2 = ((*(ushort *)(*(int *)(&llc_env + param_1 * 4) + 0x42) & 1) == 0) + 2;
  if (param_2 == 1) {
    if (param_3[1] != 0xf) {
      return;
    }
    uVar8 = 0x1a;
_L152:
    iVar7 = r_sdk_config_get_opts();
    if ((param_1 < *(byte *)(iVar7 + 0xd)) && (iVar7 = *(int *)(&llc_env + param_1 * 4), iVar7 != 0)
       ) {
      *(byte *)(iVar7 + 0x30) = *(byte *)(iVar7 + 0x30) & 0xfd;
    }
  }
  else {
    if (param_2 == 0) {
      uVar8 = (uint)*param_3;
      iVar2 = 6;
    }
    else if (param_2 == 2) {
      uVar8 = (uint)param_3[1];
    }
    else {
      if (param_2 != 3) {
        return;
      }
      if (param_3[1] != 0xf) {
        return;
      }
      uVar8 = (uint)param_3[2];
    }
    if (uVar8 == 0) {
      return;
    }
    if ((uVar8 - 0x19 & 0xff) < 2) goto _L152;
  }
  iVar10 = param_1 * 4;
  iVar9 = *(int *)(&llc_env + iVar10);
  iVar7 = r_llc_proc_get(0);
  if (iVar2 == 6) {
    r_llc_proc_state_set(param_1,6);
    r_lld_con_tx_len_update_for_intv(param_1,*(undefined2 *)(iVar9 + 0xe));
  }
  iVar5 = r_llc_proc_state_get(iVar7);
  if (iVar5 != iVar2) {
    r_llc_proc_state_get(iVar7);
    r_assert_warn(iVar2,"llc_con_upd.c",0x127);
    return;
  }
  uVar6 = r_llc_proc_state_get(iVar7);
  switch(uVar6) {
  case 2:
    r_llc_proc_timer_set(param_1,0,0);
    if ((((uVar8 != 0) && (iVar2 = r_sdk_config_get_opts(), param_1 < *(byte *)(iVar2 + 0xd))) &&
        (*(int *)(&llc_env + iVar10) != 0)) &&
       (((int)(uint)*(byte *)(*(int *)(&llc_env + iVar10) + 0x30) >> 1 & 1U) != 0)) {
      if ((*(ushort *)(iVar9 + 0x42) & 1) == 0) {
        iVar2 = r_llm_plan_elt_get(param_1);
        if (iVar2 == 0) {
          r_assert_err("llc_con_upd.c",0x13a);
        }
        if (*(int *)(iVar2 + 4) == 0) {
          r_assert_err(0,"llc_con_upd.c",0x13b);
        }
        *(undefined4 *)(iVar2 + 0x18) = 0;
        *(undefined1 *)(iVar2 + 0x16) = 0;
      }
      goto _L119;
    }
  case 1:
    if ((*(ushort *)(iVar9 + 0x42) & 1) == 0) {
      r_assert_param(param_1,uVar8,"llc_con_upd.c",0x149);
    }
    *(undefined1 *)(iVar7 + 0x2c) = 1;
  case 0:
    *(ushort *)(iVar9 + 0x42) = *(ushort *)(iVar9 + 0x42) | 0x10;
    if (*(char *)(iVar7 + 0x2c) != '\0') {
      sVar4 = r_lld_con_event_counter_get(param_1);
      sVar1 = *(short *)(*(int *)(&llc_env + iVar10) + 0x10);
      *(undefined1 *)(iVar7 + 0x26) = 1;
      *(short *)(iVar7 + 0x24) = sVar4 + sVar1 + 9;
      uVar8 = r_lld_con_count_get();
      if (1 < uVar8) {
        *(undefined2 *)(iVar7 + 0x14) = *(undefined2 *)(iVar7 + 0x24);
      }
      r_llc_pref_param_compute_eco(param_1,iVar7);
      *(undefined2 *)(iVar7 + 0x22) = *(undefined2 *)(iVar7 + 0x2a);
      uVar8 = r_lld_con_param_update
                        (param_1,*(undefined1 *)(iVar7 + 0x26),*(undefined2 *)(iVar7 + 0x28),
                         *(undefined2 *)(iVar7 + 0xc),*(undefined2 *)(iVar7 + 0xe),
                         *(undefined2 *)(iVar7 + 0x24));
      r_llc_proc_state_set(iVar7,param_1,4);
      if (uVar8 == 0) {
        r_llc_llcp_send_eco(param_1,&stack0xffffffe4,0);
        return;
      }
_L119:
      if (*(char *)(iVar7 + 0x2d) == '\0') {
        *(byte *)(iVar9 + 0x45) = *(byte *)(iVar9 + 0x45) & 0x7f;
      }
      r_llc_hci_con_upd_info_send_eco(param_1,uVar8,iVar7);
      r_llc_proc_unreg(param_1,0);
      *(ushort *)(iVar9 + 0x42) = *(ushort *)(iVar9 + 0x42) & 0xffef;
      return;
    }
    uVar3 = r_lld_con_event_counter_get();
    *(undefined2 *)(iVar7 + 0x14) = uVar3;
    r_llc_pref_param_compute_eco(param_1,iVar7);
    *(undefined2 *)(iVar7 + 0x16) = *(undefined2 *)(iVar7 + 0x2a);
    *(undefined4 *)(iVar7 + 0x18) = 0xffffffff;
    *(undefined4 *)(iVar7 + 0x1c) = 0xffffffff;
    *(undefined2 *)(iVar7 + 0x20) = 0xffff;
    llc_ll_connection_param_req_pdu_send(param_1,iVar7);
    r_llc_proc_timer_set(param_1,0,1);
    uVar6 = 2;
    if ((*(ushort *)(iVar9 + 0x42) & 1) == 0) {
      r_lld_con_tx_len_update_for_intv(param_1,*(undefined2 *)(iVar7 + 8),2);
      uVar6 = 3;
    }
    break;
  case 3:
    r_llc_proc_timer_set(param_1,0,0);
    if (uVar8 != 0) goto _L119;
    uVar8 = r_lld_con_param_update
                      (param_1,*(undefined1 *)(iVar7 + 0x26),*(undefined2 *)(iVar7 + 0x22),
                       *(undefined2 *)(iVar7 + 0x28),*(undefined2 *)(iVar7 + 0xc),
                       *(undefined2 *)(iVar7 + 0xe),*(undefined2 *)(iVar7 + 0x24));
    uVar6 = 4;
    if (uVar8 != 0) goto _L119;
    break;
  case 4:
  case 6:
    goto _L119;
  default:
    uVar6 = r_llc_proc_state_get(iVar7);
    r_assert_param(param_1,uVar6,"llc_con_upd.c",0x1c0);
    return;
  }
  r_llc_proc_state_set(iVar7,param_1,uVar6);
  return;
}

