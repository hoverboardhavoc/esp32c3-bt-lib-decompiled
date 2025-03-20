/*
 * Last changed at upstream commit aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * https://github.com/espressif/esp32c3-bt-lib/commit/aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * Upstream date: 2025-03-20 20:31:24 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(d74042a8)
 * Source: libbtdm_app -> ble_util_buf.o -> r_ble_util_buf_adv_tx_free
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_ble_util_buf_adv_tx_free(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_1 - 0x2400U >> 0xb;
  uVar1 = uVar2 & 0xff;
  if (9 < (uVar2 & 0xff)) {
    (**(code **)(_r_plf_funcs_p + 0xc))
              (uVar1,param_1,"ble_util_buf.c",0x1d2,*(code **)(_r_plf_funcs_p + 0xc));
  }
  (**(code **)(_r_plf_funcs_p + 0xb4))(param_1,*(code **)(_r_plf_funcs_p + 0xb4));
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  (**(code **)(_r_modules_funcs_p + 0x44))
            (_p_ble_util_buf_env + 0x18,(uVar1 + 0x2d) * 8 + _p_ble_util_buf_env,
             *(code **)(_r_modules_funcs_p + 0x44));
                    /* WARNING: Could not recover jumptable at 0x000109c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_osi_funcs_p + 0x18))();
  return;
}

