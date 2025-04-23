/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llc_dl_upd.o -> r_llc_loc_dl_upd_proc_continue
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llc_loc_dl_upd_proc_continue(uint param_1,int param_2)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  ushort uVar8;
  ushort uVar9;
  
  iVar4 = *(int *)(&llc_env + param_1 * 4);
  iVar5 = r_llc_proc_get(0);
  iVar6 = r_llc_proc_state_get();
  if (iVar6 != 0) {
    if (iVar6 == 1) {
      r_llc_proc_timer_set(param_1,0,0);
      if (param_2 == 0) {
        if (*(char *)(iVar4 + 0x1c) == '\x03') {
          uVar8 = *(ushort *)(iVar5 + 10);
          if (uVar8 < 0xa90) {
            uVar8 = 0xa90;
          }
          *(ushort *)(iVar5 + 10) = uVar8;
        }
        if (*(char *)(iVar4 + 0x1d) == '\x03') {
          uVar8 = *(ushort *)(iVar5 + 0xe);
          if (uVar8 < 0xa90) {
            uVar8 = 0xa90;
          }
          *(ushort *)(iVar5 + 0xe) = uVar8;
        }
        if (((((*(short *)(iVar4 + 0x16) != *(short *)(iVar5 + 0xc)) ||
              (*(short *)(iVar4 + 0x14) != *(short *)(iVar5 + 8))) ||
             (*(short *)(iVar4 + 0x1a) != *(short *)(iVar5 + 0xe))) ||
            (*(short *)(iVar4 + 0x18) != *(short *)(iVar5 + 10))) &&
           (iVar6 = r_lld_con_data_len_update(param_1), iVar6 == 0)) {
          uVar1 = *(undefined2 *)(iVar5 + 8);
          uVar2 = *(undefined2 *)(iVar5 + 0xe);
          uVar3 = *(undefined2 *)(iVar5 + 10);
          *(undefined2 *)(iVar4 + 0x16) = *(undefined2 *)(iVar5 + 0xc);
          *(undefined2 *)(iVar4 + 0x14) = uVar1;
          *(undefined2 *)(iVar4 + 0x1a) = uVar2;
          *(undefined2 *)(iVar4 + 0x18) = uVar3;
          r_llc_hci_dl_upd_info_send(param_1,0);
        }
      }
    }
    else {
      uVar7 = r_llc_proc_state_get(iVar5);
      r_assert_param(param_1,uVar7,"llc_dl_upd.c",0x162);
    }
    if (*(char *)(iVar5 + 0x10) != '\0') {
      *(byte *)(iVar4 + 0x45) = *(byte *)(iVar4 + 0x45) & 0xdf;
    }
    r_llc_proc_unreg(param_1,0);
    return;
  }
  r_llc_proc_state_set(iVar5,param_1,1);
  if (*(char *)(iVar4 + 0x1c) == '\x03') {
    uVar8 = *(ushort *)(iVar5 + 10);
    if (*(ushort *)(iVar5 + 10) < 0xa90) {
      uVar8 = 0xa90;
    }
    *(ushort *)(iVar5 + 10) = uVar8;
    iVar6 = r_bt_rf_coex_conn_phy_coded_data_time_limit_en_get();
    if (iVar6 != 0) {
      iVar6 = r_bt_rf_coex_conn_phy_coded_data_time_limit_en_get();
      uVar8 = 0xa90;
      if (iVar6 != 0) {
        uVar8 = *(ushort *)(*(int *)(_bt_rf_coex_cfg_p + 0x44) + 2);
      }
      if (uVar8 < 0xa90) {
        uVar8 = 0xa90;
      }
      uVar9 = *(ushort *)(iVar5 + 10);
      if (uVar8 < *(ushort *)(iVar5 + 10)) {
        uVar9 = uVar8;
      }
      *(ushort *)(iVar5 + 10) = uVar9;
    }
    if (*(char *)(iVar4 + 0x1d) != '\x03') goto _L25;
  }
  else if (*(char *)(iVar4 + 0x1d) != '\x03') {
    if ((((*(ushort *)(iVar4 + 0x42) & 0x80) == 0) ||
        (iVar4 = r_sdk_config_get_opts(), *(byte *)(iVar4 + 0xd) <= param_1)) ||
       ((iVar4 = *(int *)(&llc_env + param_1 * 4), iVar4 == 0 ||
        (((int)(uint)*(byte *)(iVar4 + 0x31) >> 3 & 1U) == 0)))) {
      uVar8 = *(ushort *)(iVar5 + 10);
      if (0x848 < uVar8) {
        uVar8 = 0x848;
      }
      uVar9 = *(ushort *)(iVar5 + 0xe);
      *(ushort *)(iVar5 + 10) = uVar8;
      if (0x848 < uVar9) {
        uVar9 = 0x848;
      }
      *(ushort *)(iVar5 + 0xe) = uVar9;
    }
    goto _L25;
  }
  uVar8 = *(ushort *)(iVar5 + 0xe);
  if (*(ushort *)(iVar5 + 0xe) < 0xa90) {
    uVar8 = 0xa90;
  }
  *(ushort *)(iVar5 + 0xe) = uVar8;
  iVar4 = r_bt_rf_coex_conn_phy_coded_data_time_limit_en_get();
  if (iVar4 != 0) {
    iVar4 = r_bt_rf_coex_conn_phy_coded_data_time_limit_en_get();
    uVar8 = 0xa90;
    if (iVar4 != 0) {
      uVar8 = **(ushort **)(_bt_rf_coex_cfg_p + 0x44);
    }
    if (uVar8 < 0xa90) {
      uVar8 = 0xa90;
    }
    uVar9 = *(ushort *)(iVar5 + 0xe);
    if (uVar8 < *(ushort *)(iVar5 + 0xe)) {
      uVar9 = uVar8;
    }
    *(ushort *)(iVar5 + 0xe) = uVar9;
  }
_L25:
  llc_ll_length_req_pdu_send
            (param_1,*(undefined2 *)(iVar5 + 10),*(undefined2 *)(iVar5 + 8),
             *(undefined2 *)(iVar5 + 0xe),*(undefined2 *)(iVar5 + 0xc));
  r_llc_proc_timer_set(param_1,0,1);
  return;
}

