/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> ble_util_buf.o -> r_ble_util_buf_acl_tx_free_in_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_ble_util_buf_acl_tx_free_in_isr(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 - 0x9c00U >> 10;
  uVar2 = uVar1 & 0xff;
  if (0xb < uVar2) {
    (**(code **)(_r_plf_funcs_p + 0xc))
              (uVar2,param_1,"ble_util_buf.c",0x1a5,*(code **)(_r_plf_funcs_p + 0xc));
  }
  if (uVar2 < *(byte *)(_p_ble_util_buf_env + 0x1bb)) {
    (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
    (**(code **)(_r_modules_funcs_p + 0x4c))
              (_p_ble_util_buf_env + 0x10,((uVar1 & 0xff) + 0x21) * 8 + _p_ble_util_buf_env,
               *(code **)(_r_modules_funcs_p + 0x4c));
                    /* WARNING: Could not recover jumptable at 0x00010882. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0001089c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_ip_funcs_p + 0x738))(0,param_1,*(code **)(_r_ip_funcs_p + 0x738));
  return;
}

