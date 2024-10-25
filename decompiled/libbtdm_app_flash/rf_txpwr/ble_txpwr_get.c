/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> rf_txpwr.o -> ble_txpwr_get
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 ble_txpwr_get(uint param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  
  if (4 < param_1) {
    return 0xff;
  }
  iVar1 = r_sdk_config_get_opts();
  if ((*(byte *)(iVar1 + 0xc) & 1) == 0) {
    return 0xff;
  }
  if (param_1 == 2) {
    uVar3 = 0xff;
    uVar2 = 8;
    goto _L112;
  }
  if ((int)param_1 < 3) {
    if (param_1 == 1) {
      uVar2 = 0;
      if (param_2 == 0xffff) {
        uVar3 = 0xff;
        uVar2 = 4;
        goto _L112;
      }
      goto _L114;
    }
_L102:
    uVar3 = 0xff;
  }
  else {
    if (param_1 == 3) {
      uVar3 = 0xff;
      uVar2 = 0xe;
      goto _L112;
    }
    if (param_1 != 4) goto _L102;
    uVar2 = 3;
    if (param_2 == 0xffff) {
      uVar3 = 0xff;
      uVar2 = 2;
      goto _L112;
    }
_L114:
    uVar3 = llm_hdl_to_id(uVar2);
    iVar1 = r_sdk_config_get_opts();
    if (*(byte *)(iVar1 + 0xd) <= uVar3) {
      return 0xff;
    }
  }
  uVar2 = 0xff;
_L112:
  uVar2 = r_bt_rtp_get_txpwr_idx_by_act(uVar2,uVar3);
  iVar1 = r_sdk_config_get_opts_ext();
  uVar2 = bt_controller_txpwr_index_2_level(*(undefined4 *)(iVar1 + 0xc),uVar2);
  return uVar2;
}

