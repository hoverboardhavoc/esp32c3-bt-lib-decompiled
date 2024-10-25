/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> ble_util_buf.o -> r_ble_util_buf_rx_alloc_in_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 r_ble_util_buf_rx_alloc_in_isr(void)

{
  undefined2 uVar1;
  code *pcVar2;
  int iVar3;
  undefined4 uVar4;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar3 = (**(code **)(_r_modules_funcs_p + 0x40))
                    (_p_ble_util_buf_env + 8,*(code **)(_r_modules_funcs_p + 0x40));
  uVar1 = 0;
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  if (iVar3 != 0) {
    uVar1 = *(undefined2 *)(iVar3 + 4);
    iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(uVar1,*(code **)(_r_plf_funcs_p + 0xbc));
    if (iVar3 == 0) {
      pcVar2 = *(code **)(_r_plf_funcs_p + 0xc);
      uVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(uVar1,*(code **)(_r_plf_funcs_p + 0xbc));
      (*pcVar2)(uVar1,uVar4,"ble_util_buf.c",0x13f);
    }
  }
  return uVar1;
}

