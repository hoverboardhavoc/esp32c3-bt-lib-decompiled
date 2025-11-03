/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> ble_util_buf.o -> r_ble_util_buf_adv_tx_alloc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 r_ble_util_buf_adv_tx_alloc(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (0x674 < param_1) {
    return 0;
  }
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar1 = r_co_list_pop_front(_p_ble_util_buf_env + 0x18);
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  if (iVar1 != 0) {
    iVar2 = r_emi_alloc_em_mapping_by_offset(*(undefined2 *)(iVar1 + 4),param_1);
    if (iVar2 == 0) {
      r_ble_log_internal_x3(0x20c00009,iVar1,param_1,*(undefined2 *)(iVar1 + 4));
      return *(undefined2 *)(iVar1 + 4);
    }
    (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
    r_co_list_push_back(_p_ble_util_buf_env + 0x18,iVar1);
    (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  }
  return 0;
}

