/*
 * Last changed at upstream commit 0cfafa1e0aa30b7d59f53c38588f0598e228d127
 * https://github.com/espressif/esp32c3-bt-lib/commit/0cfafa1e0aa30b7d59f53c38588f0598e228d127
 * Upstream date: 2025-02-27 20:50:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(b34b7d6)
 * Source: libbtdm_app_flash -> rf_txpwr.o -> ble_txpwr_set_inter
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 ble_txpwr_set_inter(uint param_1,uint param_2,uint param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  if (4 < param_1) {
    return 0xffffffff;
  }
  if (0xf < param_3) {
    return 0xfffffffe;
  }
  iVar1 = r_sdk_config_get_opts();
  if ((*(byte *)(iVar1 + 0xc) & 1) == 0) {
    return 0xfffffffd;
  }
  iVar1 = r_sdk_config_get_opts_ext();
  uVar2 = bt_controller_txpwr_level_2_index(*(undefined4 *)(iVar1 + 0xc),param_3);
  if (param_1 == 2) {
    r_bt_rtp_register_rule_cs_fmt(8,uVar2);
    r_bt_rtp_register_rule_cs_fmt(9,uVar2);
    r_bt_rtp_register_rule_cs_fmt(10,uVar2);
    uVar3 = 0xb;
  }
  else if ((int)param_1 < 3) {
    if (param_1 != 1) {
_L68:
      iVar1 = r_sdk_cfg_priv_opts_ext_get();
      *(char *)(iVar1 + 1) = (char)uVar2;
      return 0;
    }
    iVar1 = r_sdk_config_get_opts();
    if (param_2 < *(byte *)(iVar1 + 0xd)) {
_L78:
      r_bt_rtp_register_rule_cs_idx(param_2);
      return 0;
    }
    r_bt_rtp_register_rule_cs_fmt(4,uVar2);
    r_bt_rtp_register_rule_cs_fmt(5,uVar2);
    uVar3 = 6;
  }
  else if (param_1 == 3) {
    r_bt_rtp_register_rule_cs_fmt(0xe,uVar2);
    uVar3 = 0xf;
  }
  else {
    if (param_1 != 4) goto _L68;
    iVar1 = r_sdk_config_get_opts();
    if (param_2 < *(byte *)(iVar1 + 0xd)) goto _L78;
    r_bt_rtp_register_rule_cs_fmt(2,uVar2);
    uVar3 = 3;
  }
  r_bt_rtp_register_rule_cs_fmt(uVar3,uVar2);
  return 0;
}

