/*
 * Last changed at upstream commit ec7ef197cb8018c468cd59dca893dbe018f47a2a
 * https://github.com/espressif/esp32c3-bt-lib/commit/ec7ef197cb8018c468cd59dca893dbe018f47a2a
 * Upstream date: 2023-10-26 19:39:25 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(f817304)
 * Source: libbtdm_app -> rf_txpwr.o -> ble_txpwr_lvl_range_get
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ble_txpwr_lvl_range_get(undefined1 *param_1,undefined1 *param_2)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)
           (**(code **)(_r_modules_funcs_p + 0x3c0))(*(code **)(_r_modules_funcs_p + 0x3c0));
  if (param_1 != (undefined1 *)0x0) {
    *param_1 = puVar1[1];
  }
  if (param_2 != (undefined1 *)0x0) {
    *param_2 = *puVar1;
  }
  return;
}

