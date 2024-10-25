/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> rf_txpwr.o -> r_bt_rtp_register_rule_cs_idx
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_bt_rtp_register_rule_cs_idx(uint param_1,byte param_2)

{
  int iVar1;
  
  if (param_1 < 0xc) {
    (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
    iVar1 = _r_osi_funcs_p;
    if (-1 < *(char *)(param_1 + 0x11020)) {
      g_rtp_rule_db = g_rtp_rule_db + '\x01';
    }
    *(byte *)(param_1 + 0x11020) = param_2 | 0x80;
    (**(code **)(iVar1 + 0x18))(*(code **)(iVar1 + 0x18));
    return 1;
  }
  return 0;
}

