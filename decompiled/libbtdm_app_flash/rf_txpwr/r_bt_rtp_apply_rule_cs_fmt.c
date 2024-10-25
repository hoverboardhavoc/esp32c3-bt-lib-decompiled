/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> rf_txpwr.o -> r_bt_rtp_apply_rule_cs_fmt
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 r_bt_rtp_apply_rule_cs_fmt(byte *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if (((DAT_00011019 == '\0') || (iVar2 = r_rf_util_cs_fmt_convert(), iVar2 == 0xe)) ||
     (-1 < (char)(&DAT_0001101a)[iVar2])) {
    uVar1 = 0;
  }
  else {
    *param_1 = (&DAT_0001101a)[iVar2] & 0x7f;
    uVar1 = 1;
  }
  return uVar1;
}

