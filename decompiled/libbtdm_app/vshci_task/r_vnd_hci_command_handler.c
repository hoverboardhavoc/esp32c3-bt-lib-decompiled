/*
 * Last changed at upstream commit 0c68809d62e432427de97b5294f6619307f62f40
 * https://github.com/espressif/esp32c3-bt-lib/commit/0c68809d62e432427de97b5294f6619307f62f40
 * Upstream date: 2025-07-01 15:07:54 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2edb0b0)
 * Source: libbtdm_app -> vshci_task.o -> r_vnd_hci_command_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_vnd_hci_command_handler(uint param_1)

{
  undefined4 uVar1;
  
  if ((param_1 >> 10 == 0x3f) && (0xfc80 < param_1)) {
                    /* WARNING: Could not recover jumptable at 0x000113d4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(_r_modules_funcs_p + 0x26c))(*(code **)(_r_modules_funcs_p + 0x26c));
    return uVar1;
  }
  return 0;
}

