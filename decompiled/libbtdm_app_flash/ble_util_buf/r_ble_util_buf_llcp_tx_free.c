/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> ble_util_buf.o -> r_ble_util_buf_llcp_tx_free
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_ble_util_buf_llcp_tx_free(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (param_1 - 0x1c00U) / 0x1b;
  uVar1 = uVar2 & 0xff;
  if (0x13 < (uVar2 & 0xff)) {
    r_assert_param(uVar1,param_1,"ble_util_buf.c",0xea);
  }
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  r_co_list_push_back((uVar1 + 4) * 8 + _p_ble_util_buf_env);
                    /* WARNING: Could not recover jumptable at 0x0001031a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return;
}

