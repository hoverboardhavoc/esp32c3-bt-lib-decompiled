/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
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
    r_assert_param(uVar3,param_1,"ble_util_buf.c",0x123);
  }
  iVar2 = r_emi_get_mem_addr_by_offset(param_1);
  if (iVar2 == param_2) {
    (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
    r_co_list_push_back(_p_ble_util_buf_env + 8,_p_ble_util_buf_env + ((uVar1 & 0xff) + 0x18) * 8);
    r_lld_rxdesc_check_hack(0);
    (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  }
  else {
    iVar2 = param_2;
    if (param_2 == 0) {
      iVar2 = r_emi_get_mem_addr_by_offset(param_1);
    }
    (**(code **)(_r_osi_funcs_p + 0x7c))(iVar2 + -5,*(code **)(_r_osi_funcs_p + 0x7c));
  }
  r_ble_log_internal_x2(0x20480004,param_2,param_1);
  return;
}

