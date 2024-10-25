/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> ble_util_buf.o -> r_ble_util_buf_rx_alloc_in_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 r_ble_util_buf_rx_alloc_in_isr(void)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar2 = r_co_list_pop_front(_p_ble_util_buf_env + 8);
  uVar1 = 0;
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  if (iVar2 != 0) {
    uVar1 = *(undefined2 *)(iVar2 + 4);
    iVar2 = r_emi_get_mem_addr_by_offset(uVar1);
    if (iVar2 == 0) {
      uVar3 = r_emi_get_mem_addr_by_offset(uVar1);
      r_assert_param(uVar1,uVar3,"ble_util_buf.c",0x13f);
    }
  }
  return uVar1;
}

