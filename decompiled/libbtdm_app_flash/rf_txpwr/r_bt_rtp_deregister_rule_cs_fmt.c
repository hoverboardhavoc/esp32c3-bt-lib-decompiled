/*
 * Last changed at upstream commit 2fd7ad255fceabdfba56882ce4523efdba2fc255
 * https://github.com/espressif/esp32c3-bt-lib/commit/2fd7ad255fceabdfba56882ce4523efdba2fc255
 * Upstream date: 2025-03-31 11:18:40 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(566c8e3)
 * Source: libbtdm_app_flash -> rf_txpwr.o -> r_bt_rtp_deregister_rule_cs_fmt
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_bt_rtp_deregister_rule_cs_fmt(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = r_rf_util_cs_fmt_convert();
  if (iVar1 == 0xe) {
    uVar2 = 0;
  }
  else {
    (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
    if ((char)(&DAT_0001101e)[iVar1] < '\0') {
      (&DAT_0001101e)[iVar1] = 0;
      DAT_0001101d = DAT_0001101d + -1;
    }
    (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
    uVar2 = 1;
  }
  return uVar2;
}

