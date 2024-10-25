/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> ble_util_buf.o -> r_ble_util_buf_rx_free
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_ble_util_buf_rx_free(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = param_1 - 0x7805U >> 10;
  uVar3 = uVar1 & 0xff;
  if (8 < uVar3) {
    r_assert_param(uVar3,param_1,"ble_util_buf.c",0x11e);
  }
  iVar2 = r_emi_get_mem_addr_by_offset(param_1);
  if (iVar2 != param_2) {
    if (param_2 == 0) {
      param_2 = r_emi_get_mem_addr_by_offset(param_1);
    }
                    /* WARNING: Could not recover jumptable at 0x0001047e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_osi_funcs_p + 0x7c))(param_2 + -5);
    return;
  }
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  r_co_list_push_back(_p_ble_util_buf_env + 8,((uVar1 & 0xff) + 0x18) * 8 + _p_ble_util_buf_env);
  r_lld_rxdesc_check_hack(0);
                    /* WARNING: Could not recover jumptable at 0x000104c2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_osi_funcs_p + 0x18))();
  return;
}

