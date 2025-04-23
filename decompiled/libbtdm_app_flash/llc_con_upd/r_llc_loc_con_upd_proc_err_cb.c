/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llc_con_upd.o -> r_llc_loc_con_upd_proc_err_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_llc_loc_con_upd_proc_err_cb(uint param_1,uint param_2,byte *param_3)

{
  short sVar1;
  uint uVar2;
  undefined2 uVar3;
  short sVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  
  uVar2 = 3 - (*(ushort *)(*(int *)(&llc_env + param_1 * 4) + 0x42) & 1) & 0xff;
  if (param_2 == 2) {
    uVar9 = (uint)param_3[1];
_L154:
    if (uVar9 == 0) {
      return;
    }
    if ((uVar9 - 0x19 & 0xff) < 2) goto _L155;
  }
  else {
    if (2 < param_2) {
      if (param_2 != 3) {
        return;
      }
      if (param_3[1] != 0xf) {
        return;
      }
      uVar9 = (uint)param_3[2];
      goto _L154;
    }
    if (param_2 == 0) {
      uVar9 = (uint)*param_3;
      uVar2 = 6;
      goto _L154;
    }
    if (param_3[1] != 0xf) {
      return;
    }
    uVar9 = 0x1a;
_L155:
    iVar8 = r_sdk_config_get_opts();
    if ((param_1 < *(byte *)(iVar8 + 0xd)) && (iVar8 = *(int *)(&llc_env + param_1 * 4), iVar8 != 0)
       ) {
      *(byte *)(iVar8 + 0x30) = *(byte *)(iVar8 + 0x30) & 0xfd;
    }
  }
  iVar11 = param_1 * 4;
  iVar10 = *(int *)(&llc_env + iVar11);
  iVar8 = r_llc_proc_get(0);
  if (uVar2 == 6) {
    r_llc_proc_state_set(param_1,6);
    r_lld_con_tx_len_update_for_intv(param_1,*(undefined2 *)(iVar10 + 0xe));
  }
  uVar5 = r_llc_proc_state_get(iVar8);
  if (uVar5 != uVar2) {
    r_llc_proc_state_get(iVar8);
    r_assert_warn(uVar2,"llc_con_upd.c",0x127);
    return;
  }
  uVar6 = r_llc_proc_state_get(iVar8);
  switch(uVar6) {
  case 2:
    r_llc_proc_timer_set(param_1,0,0);
    if ((((uVar9 != 0) && (iVar7 = r_sdk_config_get_opts(), param_1 < *(byte *)(iVar7 + 0xd))) &&
        (*(int *)(&llc_env + iVar11) != 0)) &&
       (((int)(uint)*(byte *)(*(int *)(&llc_env + iVar11) + 0x30) >> 1 & 1U) != 0)) {
      if ((*(ushort *)(iVar10 + 0x42) & 1) == 0) {
        iVar11 = r_llm_plan_elt_get(param_1);
        if (iVar11 == 0) {
          r_assert_err("llc_con_upd.c",0x13a);
        }
        if (*(int *)(iVar11 + 4) == 0) {
          r_assert_err(0,"llc_con_upd.c",0x13b);
        }
        *(undefined4 *)(iVar11 + 0x18) = 0;
        *(undefined1 *)(iVar11 + 0x16) = 0;
      }
      goto _L136;
    }
  case 1:
    if ((*(ushort *)(iVar10 + 0x42) & 1) == 0) {
      r_assert_param(param_1,uVar9,"llc_con_upd.c",0x149);
    }
    *(undefined1 *)(iVar8 + 0x2c) = 1;
  case 0:
    *(ushort *)(iVar10 + 0x42) = *(ushort *)(iVar10 + 0x42) | 0x10;
    if (*(char *)(iVar8 + 0x2c) != '\0') {
      sVar4 = r_lld_con_event_counter_get(param_1);
      sVar1 = *(short *)(*(int *)(&llc_env + iVar11) + 0x10);
      *(undefined1 *)(iVar8 + 0x26) = 1;
      *(short *)(iVar8 + 0x24) = sVar4 + sVar1 + 9;
      uVar2 = r_lld_con_count_get();
      if (1 < uVar2) {
        *(undefined2 *)(iVar8 + 0x14) = *(undefined2 *)(iVar8 + 0x24);
      }
      r_llc_pref_param_compute_eco(param_1,iVar8);
      *(undefined2 *)(iVar8 + 0x22) = *(undefined2 *)(iVar8 + 0x2a);
      uVar9 = r_lld_con_param_update
                        (param_1,*(undefined1 *)(iVar8 + 0x26),*(undefined2 *)(iVar8 + 0x28),
                         *(undefined2 *)(iVar8 + 0xc),*(undefined2 *)(iVar8 + 0xe),
                         *(undefined2 *)(iVar8 + 0x24));
      r_llc_proc_state_set(iVar8,param_1,4);
      if (uVar9 == 0) {
        r_llc_llcp_send_eco(param_1,&stack0xffffffe4,0);
        return;
      }
_L136:
      if (*(char *)(iVar8 + 0x2d) == '\0') {
        *(byte *)(iVar10 + 0x45) = *(byte *)(iVar10 + 0x45) & 0x7f;
      }
      r_llc_hci_con_upd_info_send_eco(param_1,uVar9,iVar8);
      r_llc_proc_unreg(param_1,0);
      *(ushort *)(iVar10 + 0x42) = *(ushort *)(iVar10 + 0x42) & 0xffef;
      return;
    }
    uVar3 = r_lld_con_event_counter_get();
    *(undefined2 *)(iVar8 + 0x14) = uVar3;
    r_llc_pref_param_compute_eco(param_1,iVar8);
    *(undefined2 *)(iVar8 + 0x16) = *(undefined2 *)(iVar8 + 0x2a);
    *(undefined4 *)(iVar8 + 0x18) = 0xffffffff;
    *(undefined4 *)(iVar8 + 0x1c) = 0xffffffff;
    *(undefined2 *)(iVar8 + 0x20) = 0xffff;
    llc_ll_connection_param_req_pdu_send(param_1,iVar8);
    r_llc_proc_timer_set(param_1,0,1);
    uVar6 = 2;
    if ((*(ushort *)(iVar10 + 0x42) & 1) == 0) {
      r_lld_con_tx_len_update_for_intv(param_1,*(undefined2 *)(iVar8 + 8),2);
      uVar6 = 3;
    }
    break;
  case 3:
    r_llc_proc_timer_set(param_1,0,0);
    if (uVar9 != 0) goto _L136;
    uVar9 = r_lld_con_param_update
                      (param_1,*(undefined1 *)(iVar8 + 0x26),*(undefined2 *)(iVar8 + 0x22),
                       *(undefined2 *)(iVar8 + 0x28),*(undefined2 *)(iVar8 + 0xc),
                       *(undefined2 *)(iVar8 + 0xe),*(undefined2 *)(iVar8 + 0x24));
    uVar6 = 4;
    if (uVar9 != 0) goto _L136;
    break;
  case 4:
  case 6:
    goto _L136;
  default:
    uVar6 = r_llc_proc_state_get(iVar8);
    r_assert_param(param_1,uVar6,"llc_con_upd.c",0x1c0);
    return;
  }
  r_llc_proc_state_set(iVar8,param_1,uVar6);
  return;
}

