/*
 * Last changed at upstream commit 0c68809d62e432427de97b5294f6619307f62f40
 * https://github.com/espressif/esp32c3-bt-lib/commit/0c68809d62e432427de97b5294f6619307f62f40
 * Upstream date: 2025-07-01 15:07:54 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2edb0b0)
 * Source: libbtdm_app_flash -> rwip.o -> r_rwip_assert_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_rwip_assert_hack(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  code *UNRECOVERED_JUMPTABLE;
  
  if (_g_bt_plf_log_level < 1) {
    UNRECOVERED_JUMPTABLE = *(code **)(_r_osi_funcs_p + 0xf4);
  }
  else {
    ets_printf("BLE assert %s %d, param %08x %08x\n",param_1,param_2,param_3,param_4);
    UNRECOVERED_JUMPTABLE = *(code **)(_r_osi_funcs_p + 0xf4);
  }
                    /* WARNING: Could not recover jumptable at 0x000103a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(UNRECOVERED_JUMPTABLE);
  return;
}

