/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app -> llm.o -> esp_ble_enable_ch_assess
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void esp_ble_enable_ch_assess(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = _p_llm_env;
  *(bool *)(_p_llm_env + 0xd9) = param_1 != 0;
  iVar1 = _r_modules_funcs_p;
  if (param_2 != 0) {
    *(undefined1 *)(iVar2 + 0x22) = 0;
                    /* WARNING: Could not recover jumptable at 0x00010d34. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(iVar1 + 0xc4))(4,0,(uint)_sdk_cfg_priv_opts * 100,*(code **)(iVar1 + 0xc4));
    return;
  }
  (**(code **)(_r_modules_funcs_p + 0xb8))(4,*(code **)(_r_modules_funcs_p + 0xb8));
  *(undefined1 *)(_p_llm_env + 0x22) = 1;
  return;
}

