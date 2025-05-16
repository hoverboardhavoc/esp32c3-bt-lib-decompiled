/*
 * Last changed at upstream commit b0ccea3c26a049649d2fdbaca78318af90a6dd5b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b0ccea3c26a049649d2fdbaca78318af90a6dd5b
 * Upstream date: 2025-05-16 11:55:10 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(4713205)
 * Source: libbtdm_app -> llm_hci.o -> r_llm_aes_res_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llm_aes_res_cb(undefined1 param_1,void *param_2)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)
           (**(code **)(_r_modules_funcs_p + 200))(7,0,0,0x11,*(code **)(_r_modules_funcs_p + 200));
  *puVar1 = param_1;
  memcpy(puVar1 + 1,param_2,0x10);
                    /* WARNING: Could not recover jumptable at 0x000119ca. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_modules_funcs_p + 0xe0))(puVar1,*(code **)(_r_modules_funcs_p + 0xe0));
  return;
}

