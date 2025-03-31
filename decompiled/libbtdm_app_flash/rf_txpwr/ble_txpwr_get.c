/*
 * Last changed at upstream commit 2fd7ad255fceabdfba56882ce4523efdba2fc255
 * https://github.com/espressif/esp32c3-bt-lib/commit/2fd7ad255fceabdfba56882ce4523efdba2fc255
 * Upstream date: 2025-03-31 11:18:40 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(566c8e3)
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
  if (param_1 == 1) {
    iVar1 = adv_itf_version_is_legacy();
    if (iVar1 == 0) {
_L104:
      uVar2 = 0;
      if (param_2 != 0xffff) {
_L122:
        uVar3 = llm_hdl_to_id(uVar2);
        iVar1 = r_sdk_config_get_opts();
        if (*(byte *)(iVar1 + 0xd) <= uVar3) {
          return 0xff;
        }
        goto _L121;
      }
    }
    uVar3 = 0xff;
    uVar2 = 4;
  }
  else {
    if (param_1 == 2) {
      uVar3 = 0xff;
      uVar2 = 8;
      goto _L120;
    }
    if ((int)param_1 < 3) {
      if (param_1 == 1) goto _L104;
    }
    else {
      if (param_1 == 3) {
        uVar3 = 0xff;
        uVar2 = 0xe;
        goto _L120;
      }
      if (param_1 == 4) {
        uVar2 = 3;
        if (param_2 == 0xffff) {
          uVar3 = 0xff;
          uVar2 = 2;
          goto _L120;
        }
        goto _L122;
      }
    }
    uVar3 = 0xff;
_L121:
    uVar2 = 0xff;
  }
_L120:
  uVar2 = r_bt_rtp_get_txpwr_idx_by_act(uVar2,uVar3);
  iVar1 = r_sdk_config_get_opts_ext();
  uVar2 = bt_controller_txpwr_index_2_level(*(undefined4 *)(iVar1 + 0xc),uVar2);
  return uVar2;
}

