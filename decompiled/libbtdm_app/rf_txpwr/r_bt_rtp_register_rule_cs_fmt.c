/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> rf_txpwr.o -> r_bt_rtp_register_rule_cs_fmt
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_bt_rtp_register_rule_cs_fmt(byte param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (**(code **)(_r_modules_funcs_p + 0x20c))(*(code **)(_r_modules_funcs_p + 0x20c));
  if (iVar1 == 0xe) {
    uVar2 = 0;
  }
  else {
    (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
    if (-1 < (char)(&DAT_00011012)[iVar1]) {
      DAT_00011011 = DAT_00011011 + '\x01';
    }
    (&DAT_00011012)[iVar1] = param_1 | 0x80;
    (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
    uVar2 = 1;
  }
  return uVar2;
}

