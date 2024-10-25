/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> ble_util_buf.o -> r_ble_util_buf_rx_free_in_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_ble_util_buf_rx_free_in_isr(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_1 - 0x7805U >> 10;
  uVar1 = uVar2 & 0xff;
  if (8 < (uVar2 & 0xff)) {
    r_assert_param(uVar1,param_1,"ble_util_buf.c",0x14b);
  }
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  r_co_list_push_back(_p_ble_util_buf_env + 8,(uVar1 + 0x18) * 8 + _p_ble_util_buf_env);
                    /* WARNING: Could not recover jumptable at 0x000105a2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_osi_funcs_p + 0x18))();
  return;
}

