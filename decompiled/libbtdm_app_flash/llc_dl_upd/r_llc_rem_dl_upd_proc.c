/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llc_dl_upd.o -> r_llc_rem_dl_upd_proc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llc_rem_dl_upd_proc(uint param_1,uint param_2,uint param_3,uint param_4,uint param_5)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  iVar4 = *(int *)(&llc_env + param_1 * 4);
  uVar5 = (uint)*(ushort *)(iVar4 + 0x20);
  if (param_5 < *(ushort *)(iVar4 + 0x20)) {
    uVar5 = param_5;
  }
  uVar6 = uVar5 & 0xffff;
  uVar3 = (uint)*(ushort *)(iVar4 + 0x22);
  if (param_4 < *(ushort *)(iVar4 + 0x22)) {
    uVar3 = param_4;
  }
  if (0xfb < param_3) {
    param_3 = 0xfb;
  }
  uVar7 = param_3 & 0xffff;
  if (0x4290 < param_2) {
    param_2 = 0x4290;
  }
  param_2 = param_2 & 0xffff;
  if (*(char *)(iVar4 + 0x1c) == '\x03') {
    if (uVar3 < 0xa90) {
      uVar3 = 0xa90;
    }
    iVar2 = r_bt_rf_coex_conn_phy_coded_data_time_limit_en_get();
    uVar1 = uVar3;
    if (iVar2 != 0) {
      iVar2 = r_bt_rf_coex_conn_phy_coded_data_time_limit_en_get();
      uVar1 = 0xa90;
      if (iVar2 != 0) {
        uVar1 = (uint)*(ushort *)(*(int *)(_bt_rf_coex_cfg_p + 0x44) + 2);
      }
      if (uVar1 < 0xa90) {
        uVar1 = 0xa90;
      }
      if (uVar3 < uVar1) {
        uVar1 = uVar3;
      }
    }
    uVar1 = uVar1 & 0xffff;
  }
  else {
    uVar1 = uVar3 & 0xffff;
    if (*(char *)(iVar4 + 0x1d) != '\x03') {
      if (((((*(ushort *)(iVar4 + 0x42) & 0x80) == 0) ||
           (iVar2 = r_sdk_config_get_opts(), *(byte *)(iVar2 + 0xd) <= param_1)) ||
          (*(int *)(&llc_env + param_1 * 4) == 0)) ||
         (((int)(uint)*(byte *)(*(int *)(&llc_env + param_1 * 4) + 0x31) >> 3 & 1U) == 0)) {
        if (0x848 < uVar3) {
          uVar3 = 0x848;
        }
        uVar1 = uVar3 & 0xffff;
        if (0x848 < param_2) {
          param_2 = 0x848;
        }
      }
      goto _L92;
    }
  }
  if (*(char *)(iVar4 + 0x1d) == '\x03') {
    uVar3 = param_2;
    if (param_2 < 0xa90) {
      uVar3 = 0xa90;
    }
    iVar2 = r_bt_rf_coex_conn_phy_coded_data_time_limit_en_get();
    param_2 = uVar3;
    if (iVar2 != 0) {
      iVar2 = r_bt_rf_coex_conn_phy_coded_data_time_limit_en_get();
      param_2 = 0xa90;
      if (iVar2 != 0) {
        param_2 = (uint)**(ushort **)(_bt_rf_coex_cfg_p + 0x44);
      }
      if (param_2 < 0xa90) {
        param_2 = 0xa90;
      }
      if (uVar3 < param_2) {
        param_2 = uVar3;
      }
    }
  }
_L92:
  if (((*(ushort *)(iVar4 + 0x16) != uVar7) || (*(ushort *)(iVar4 + 0x14) != uVar6)) ||
     ((*(ushort *)(iVar4 + 0x1a) != param_2 || (*(ushort *)(iVar4 + 0x18) != uVar1)))) {
    *(short *)(iVar4 + 0x16) = (short)param_3;
    *(short *)(iVar4 + 0x14) = (short)uVar5;
    *(short *)(iVar4 + 0x1a) = (short)param_2;
    *(short *)(iVar4 + 0x18) = (short)uVar1;
    r_lld_con_data_len_update(param_1,uVar1,uVar6,param_2,uVar7);
    r_llc_hci_dl_upd_info_send(param_1,0,uVar1,uVar6,param_2,uVar7);
  }
  r_llc_llcp_send_eco(param_1,&stack0xffffffe4,0);
  return;
}

