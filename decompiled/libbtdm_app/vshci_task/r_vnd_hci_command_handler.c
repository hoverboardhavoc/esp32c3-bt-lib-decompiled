/*
 * Last changed at upstream commit aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * https://github.com/espressif/esp32c3-bt-lib/commit/aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * Upstream date: 2025-03-20 20:31:24 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(d74042a8)
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
                    /* WARNING: Could not recover jumptable at 0x000110c2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(_r_modules_funcs_p + 0x26c))();
    return uVar1;
  }
  return 0;
}

