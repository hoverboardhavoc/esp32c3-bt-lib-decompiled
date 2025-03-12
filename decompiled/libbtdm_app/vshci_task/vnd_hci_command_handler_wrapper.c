/*
 * Last changed at upstream commit b5ead6b6d5758629370c91897168b8bcdfdcc169
 * https://github.com/espressif/esp32c3-bt-lib/commit/b5ead6b6d5758629370c91897168b8bcdfdcc169
 * Upstream date: 2025-03-12 20:14:26 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(9f6be86f)
 * Source: libbtdm_app -> vshci_task.o -> vnd_hci_command_handler_wrapper
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void vnd_hci_command_handler_wrapper(void)

{
                    /* WARNING: Could not recover jumptable at 0x000111ea. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_modules_funcs_p + 0x274))();
  return;
}

