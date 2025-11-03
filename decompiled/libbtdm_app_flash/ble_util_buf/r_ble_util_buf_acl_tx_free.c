/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> ble_util_buf.o -> r_ble_util_buf_acl_tx_free
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_ble_util_buf_acl_tx_free(uint param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = param_1 - 0x9c00 >> 10;
  if (0xb < (uVar1 & 0xff)) {
    r_assert_param(uVar1 & 0xff,param_1,"ble_util_buf.c",0x196);
  }
  iVar2 = ((uVar1 & 0xff) + 0x21) * 8;
  if ((uVar1 & 0xff) < (uint)*(byte *)(_p_ble_util_buf_env + 0x1bb)) {
    (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
    r_co_list_push_front(_p_ble_util_buf_env + 0x10,_p_ble_util_buf_env + iVar2);
  }
  else {
    r_emi_free_em_mapping_by_offset(param_1);
    (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
    r_co_list_push_back(_p_ble_util_buf_env + 0x10,_p_ble_util_buf_env + iVar2);
  }
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  r_ble_log_internal_x2(0x20e30008,_p_ble_util_buf_env + iVar2,(uVar1 & 0xff) << 0x10 | param_1);
  return;
}

