/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> rf_multi_antena.o -> r_bt_rma_apply_rule_cs_idx
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 r_bt_rma_apply_rule_cs_idx(uint param_1,byte *param_2,byte *param_3)

{
  byte bVar1;
  undefined4 uVar2;
  
  if (param_1 < 0xc) {
    uVar2 = 0;
    if ((g_rma_rule_db != '\0') && (bVar1 = (&r_plf_funcs_p)[param_1], (char)bVar1 < '\0')) {
      if (param_2 != (byte *)0x0) {
        *param_2 = bVar1 >> 2 & 3;
      }
      uVar2 = 1;
      if (param_3 != (byte *)0x0) {
        *param_3 = bVar1 & 3;
      }
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

