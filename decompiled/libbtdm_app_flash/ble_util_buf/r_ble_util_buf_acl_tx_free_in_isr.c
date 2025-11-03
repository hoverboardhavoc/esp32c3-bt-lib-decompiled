/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> ble_util_buf.o -> r_ble_util_buf_acl_tx_free_in_isr
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
    r_assert_param(uVar2,param_1,"ble_util_buf.c",0x1b0);
  }
  if (uVar2 < *(byte *)(_p_ble_util_buf_env + 0x1bb)) {
    (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
    r_co_list_push_front
              (_p_ble_util_buf_env + 0x10,((uVar1 & 0xff) + 0x21) * 8 + _p_ble_util_buf_env);
                    /* WARNING: Could not recover jumptable at 0x000108ea. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
    return;
  }
  r_misc_free_em_buf_in_isr(0,param_1);
  return;
}

