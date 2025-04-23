/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> ble_log.o -> r_ble_log_hci_vs_cmd_proc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 r_ble_log_hci_vs_cmd_proc(void)

{
  undefined4 uVar1;
  
  if (ble_log_env == 0) {
    return 0xc;
  }
  if (*(code **)(ble_log_env + 0xc) != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x000103ea. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(ble_log_env + 0xc))();
    return uVar1;
  }
  return 1;
}

