/*
 * Last changed at upstream commit 2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * https://github.com/espressif/esp32c3-bt-lib/commit/2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * Upstream date: 2025-02-25 15:16:47 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(723439d)
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
                    /* WARNING: Could not recover jumptable at 0x000103f2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(ble_log_env + 0xc))();
    return uVar1;
  }
  return 1;
}

