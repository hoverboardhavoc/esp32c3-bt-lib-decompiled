/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> ble_util_buf.o -> r_ble_util_buf_rx_alloc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 r_ble_util_buf_rx_alloc(void)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar2 = r_co_list_pop_front(_p_ble_util_buf_env + 8);
  uVar1 = 0;
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  if (iVar2 != 0) {
    uVar1 = *(undefined2 *)(iVar2 + 4);
    iVar3 = r_emi_get_mem_addr_by_offset(uVar1);
    if (iVar3 == 0) {
      uVar4 = r_emi_get_mem_addr_by_offset(uVar1);
      r_assert_param(uVar1,uVar4,"ble_util_buf.c",0x116);
    }
  }
  r_ble_log_internal_x2(0x20480003,iVar2,uVar1);
  return uVar1;
}

