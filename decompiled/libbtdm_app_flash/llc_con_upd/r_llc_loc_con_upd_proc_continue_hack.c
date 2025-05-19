/*
 * Last changed at upstream commit 72599d583c232ea78d6461b5b502426c6e5a1ec9
 * https://github.com/espressif/esp32c3-bt-lib/commit/72599d583c232ea78d6461b5b502426c6e5a1ec9
 * Upstream date: 2025-05-19 16:27:45 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(6cfabcd8)
 * Source: libbtdm_app_flash -> llc_con_upd.o -> r_llc_loc_con_upd_proc_continue_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_llc_loc_con_upd_proc_continue_hack(uint param_1,int param_2,int param_3)

{
  short sVar1;
  undefined2 uVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  
  iVar9 = param_1 * 4;
  iVar8 = *(int *)(&llc_env + iVar9);
  iVar4 = r_llc_proc_get(0);
  if (param_2 == 6) {
    r_llc_proc_state_set(param_1,6);
    r_lld_con_tx_len_update_for_intv(param_1,*(undefined2 *)(iVar8 + 0xe));
  }
  iVar5 = r_llc_proc_state_get(iVar4);
  if (iVar5 != param_2) {
    r_llc_proc_state_get(iVar4);
    r_assert_warn(param_2,"llc_con_upd.c",0x127);
    return;
  }
  uVar6 = r_llc_proc_state_get(iVar4);
  switch(uVar6) {
  case 2:
    r_llc_proc_timer_set(param_1,0,0);
    if ((param_3 != 0) && (iVar5 = r_sdk_config_get_opts(), param_1 < *(byte *)(iVar5 + 0xd))) {
      if ((*(int *)(&llc_env + iVar9) != 0) &&
         (((int)(uint)*(byte *)(*(int *)(&llc_env + iVar9) + 0x30) >> 1 & 1U) != 0)) {
        if ((*(ushort *)(iVar8 + 0x42) & 1) == 0) {
          iVar9 = r_llm_plan_elt_get(param_1);
          if (iVar9 == 0) {
            r_assert_err("llc_con_upd.c",0x13a);
          }
          if (*(int *)(iVar9 + 4) == 0) {
            r_assert_err(0,"llc_con_upd.c",0x13b);
          }
          *(undefined4 *)(iVar9 + 0x18) = 0;
          *(undefined1 *)(iVar9 + 0x16) = 0;
        }
        goto _L117;
      }
    }
  case 1:
    if ((*(ushort *)(iVar8 + 0x42) & 1) == 0) {
      r_assert_param(param_1,param_3,"llc_con_upd.c",0x149);
    }
    *(undefined1 *)(iVar4 + 0x2c) = 1;
  case 0:
    *(ushort *)(iVar8 + 0x42) = *(ushort *)(iVar8 + 0x42) | 0x10;
    if (*(char *)(iVar4 + 0x2c) != '\0') {
      sVar3 = r_lld_con_event_counter_get(param_1);
      sVar1 = *(short *)(*(int *)(&llc_env + iVar9) + 0x10);
      *(undefined1 *)(iVar4 + 0x26) = 1;
      *(short *)(iVar4 + 0x24) = sVar3 + sVar1 + 9;
      uVar7 = r_lld_con_count_get();
      if (1 < uVar7) {
        *(undefined2 *)(iVar4 + 0x14) = *(undefined2 *)(iVar4 + 0x24);
      }
      r_llc_pref_param_compute_eco(param_1,iVar4);
      *(undefined2 *)(iVar4 + 0x22) = *(undefined2 *)(iVar4 + 0x2a);
      param_3 = r_lld_con_param_update
                          (param_1,*(undefined1 *)(iVar4 + 0x26),*(undefined2 *)(iVar4 + 0x28),
                           *(undefined2 *)(iVar4 + 0xc),*(undefined2 *)(iVar4 + 0xe),
                           *(undefined2 *)(iVar4 + 0x24));
      r_llc_proc_state_set(iVar4,param_1,4);
      if (param_3 == 0) {
        r_llc_llcp_send_eco(param_1,&stack0xffffffe4,0);
        return;
      }
_L117:
      if (*(char *)(iVar4 + 0x2d) == '\0') {
        *(byte *)(iVar8 + 0x45) = *(byte *)(iVar8 + 0x45) & 0x7f;
      }
      r_llc_hci_con_upd_info_send_eco(param_1,param_3,iVar4);
      r_llc_proc_unreg(param_1,0);
      *(ushort *)(iVar8 + 0x42) = *(ushort *)(iVar8 + 0x42) & 0xffef;
      return;
    }
    uVar2 = r_lld_con_event_counter_get();
    *(undefined2 *)(iVar4 + 0x14) = uVar2;
    r_llc_pref_param_compute_eco(param_1,iVar4);
    *(undefined2 *)(iVar4 + 0x16) = *(undefined2 *)(iVar4 + 0x2a);
    *(undefined4 *)(iVar4 + 0x18) = 0xffffffff;
    *(undefined4 *)(iVar4 + 0x1c) = 0xffffffff;
    *(undefined2 *)(iVar4 + 0x20) = 0xffff;
    llc_ll_connection_param_req_pdu_send(param_1,iVar4);
    r_llc_proc_timer_set(param_1,0,1);
    uVar6 = 2;
    if ((*(ushort *)(iVar8 + 0x42) & 1) == 0) {
      r_lld_con_tx_len_update_for_intv(param_1,*(undefined2 *)(iVar4 + 8),2);
      uVar6 = 3;
    }
    break;
  case 3:
    r_llc_proc_timer_set(param_1,0,0);
    if (param_3 != 0) goto _L117;
    param_3 = r_lld_con_param_update
                        (param_1,*(undefined1 *)(iVar4 + 0x26),*(undefined2 *)(iVar4 + 0x22),
                         *(undefined2 *)(iVar4 + 0x28),*(undefined2 *)(iVar4 + 0xc),
                         *(undefined2 *)(iVar4 + 0xe),*(undefined2 *)(iVar4 + 0x24));
    uVar6 = 4;
    if (param_3 != 0) goto _L117;
    break;
  case 4:
  case 6:
    goto _L117;
  default:
    uVar6 = r_llc_proc_state_get(iVar4);
    r_assert_param(param_1,uVar6,"llc_con_upd.c",0x1c0);
    return;
  }
  r_llc_proc_state_set(iVar4,param_1,uVar6);
  return;
}

