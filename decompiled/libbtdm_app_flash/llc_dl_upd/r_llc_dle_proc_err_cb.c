/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> llc_dl_upd.o -> r_llc_dle_proc_err_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llc_dle_proc_err_cb(uint param_1,uint param_2,char *param_3)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  char cVar8;
  ushort uVar9;
  ushort uVar10;
  
  if (param_2 == 2) {
    cVar8 = param_3[1];
_L69:
    if (cVar8 == '\0') {
      return;
    }
    if ((byte)(cVar8 - 0x19U) < 2) goto _L70;
  }
  else {
    if (2 < param_2) {
      if (param_2 != 3) {
        return;
      }
      if (param_3[1] != '\x14') {
        return;
      }
      cVar8 = param_3[2];
      goto _L69;
    }
    if (param_2 == 0) {
      cVar8 = *param_3;
      goto _L69;
    }
    if (param_3[1] != '\x14') {
      return;
    }
    cVar8 = '\x19';
_L70:
    iVar7 = r_sdk_config_get_opts();
    if ((param_1 < *(byte *)(iVar7 + 0xd)) && (iVar7 = *(int *)(&llc_env + param_1 * 4), iVar7 != 0)
       ) {
      *(byte *)(iVar7 + 0x30) = *(byte *)(iVar7 + 0x30) & 0xdf;
    }
  }
  iVar7 = *(int *)(&llc_env + param_1 * 4);
  iVar4 = r_llc_proc_get(0);
  iVar5 = r_llc_proc_state_get();
  if (iVar5 != 0) {
    if (iVar5 == 1) {
      r_llc_proc_timer_set(param_1,0,0);
      if (cVar8 == '\0') {
        if (*(char *)(iVar7 + 0x1c) == '\x03') {
          uVar9 = *(ushort *)(iVar4 + 10);
          if (uVar9 < 0xa90) {
            uVar9 = 0xa90;
          }
          *(ushort *)(iVar4 + 10) = uVar9;
        }
        if (*(char *)(iVar7 + 0x1d) == '\x03') {
          uVar9 = *(ushort *)(iVar4 + 0xe);
          if (uVar9 < 0xa90) {
            uVar9 = 0xa90;
          }
          *(ushort *)(iVar4 + 0xe) = uVar9;
        }
        if (((((*(short *)(iVar7 + 0x16) != *(short *)(iVar4 + 0xc)) ||
              (*(short *)(iVar7 + 0x14) != *(short *)(iVar4 + 8))) ||
             (*(short *)(iVar7 + 0x1a) != *(short *)(iVar4 + 0xe))) ||
            (*(short *)(iVar7 + 0x18) != *(short *)(iVar4 + 10))) &&
           (iVar5 = r_lld_con_data_len_update(param_1), iVar5 == 0)) {
          uVar1 = *(undefined2 *)(iVar4 + 8);
          uVar2 = *(undefined2 *)(iVar4 + 0xe);
          uVar3 = *(undefined2 *)(iVar4 + 10);
          *(undefined2 *)(iVar7 + 0x16) = *(undefined2 *)(iVar4 + 0xc);
          *(undefined2 *)(iVar7 + 0x14) = uVar1;
          *(undefined2 *)(iVar7 + 0x1a) = uVar2;
          *(undefined2 *)(iVar7 + 0x18) = uVar3;
          r_llc_hci_dl_upd_info_send(param_1,0);
        }
      }
    }
    else {
      iVar5 = r_llc_proc_state_get(iVar4);
      r_ble_log_internal_x1(0x804f0098,iVar5 << 8 | param_1);
      uVar6 = r_llc_proc_state_get(iVar4);
      r_assert_param(param_1,uVar6,"llc_dl_upd.c",0x164);
    }
    if (*(char *)(iVar4 + 0x10) != '\0') {
      *(byte *)(iVar7 + 0x45) = *(byte *)(iVar7 + 0x45) & 0xdf;
    }
    r_llc_proc_unreg(param_1,0);
    return;
  }
  r_llc_proc_state_set(iVar4,param_1,1);
  if (*(char *)(iVar7 + 0x1c) == '\x03') {
    uVar9 = *(ushort *)(iVar4 + 10);
    if (*(ushort *)(iVar4 + 10) < 0xa90) {
      uVar9 = 0xa90;
    }
    *(ushort *)(iVar4 + 10) = uVar9;
    iVar5 = r_bt_rf_coex_conn_phy_coded_data_time_limit_en_get_hack();
    if (iVar5 != 0) {
      iVar5 = r_bt_rf_coex_conn_phy_coded_data_time_limit_en_get_hack();
      if (iVar5 == 0) {
        uVar9 = 0xa90;
      }
      else {
        uVar9 = *(ushort *)(*(int *)(_bt_rf_coex_cfg_p + 0x44) + 2);
      }
      if (uVar9 < 0xa90) {
        uVar9 = 0xa90;
      }
      uVar10 = *(ushort *)(iVar4 + 10);
      if (uVar9 < *(ushort *)(iVar4 + 10)) {
        uVar10 = uVar9;
      }
      *(ushort *)(iVar4 + 10) = uVar10;
    }
    if (*(char *)(iVar7 + 0x1d) != '\x03') goto _L25;
  }
  else if (*(char *)(iVar7 + 0x1d) != '\x03') {
    if ((((*(ushort *)(iVar7 + 0x42) & 0x80) == 0) ||
        (iVar7 = r_sdk_config_get_opts(), *(byte *)(iVar7 + 0xd) <= param_1)) ||
       ((iVar7 = *(int *)(&llc_env + param_1 * 4), iVar7 == 0 ||
        (((int)(uint)*(byte *)(iVar7 + 0x31) >> 3 & 1U) == 0)))) {
      uVar9 = *(ushort *)(iVar4 + 10);
      if (0x848 < uVar9) {
        uVar9 = 0x848;
      }
      uVar10 = *(ushort *)(iVar4 + 0xe);
      *(ushort *)(iVar4 + 10) = uVar9;
      if (0x848 < uVar10) {
        uVar10 = 0x848;
      }
      *(ushort *)(iVar4 + 0xe) = uVar10;
    }
    goto _L25;
  }
  uVar9 = *(ushort *)(iVar4 + 0xe);
  if (*(ushort *)(iVar4 + 0xe) < 0xa90) {
    uVar9 = 0xa90;
  }
  *(ushort *)(iVar4 + 0xe) = uVar9;
  iVar7 = r_bt_rf_coex_conn_phy_coded_data_time_limit_en_get_hack();
  if (iVar7 != 0) {
    iVar7 = r_bt_rf_coex_conn_phy_coded_data_time_limit_en_get_hack();
    if (iVar7 == 0) {
      uVar9 = 0xa90;
    }
    else {
      uVar9 = **(ushort **)(_bt_rf_coex_cfg_p + 0x44);
    }
    if (uVar9 < 0xa90) {
      uVar9 = 0xa90;
    }
    uVar10 = *(ushort *)(iVar4 + 0xe);
    if (uVar9 < *(ushort *)(iVar4 + 0xe)) {
      uVar10 = uVar9;
    }
    *(ushort *)(iVar4 + 0xe) = uVar10;
  }
_L25:
  llc_ll_length_req_pdu_send
            (param_1,*(undefined2 *)(iVar4 + 10),*(undefined2 *)(iVar4 + 8),
             *(undefined2 *)(iVar4 + 0xe),*(undefined2 *)(iVar4 + 0xc));
  r_llc_proc_timer_set(param_1,0,1);
  return;
}

