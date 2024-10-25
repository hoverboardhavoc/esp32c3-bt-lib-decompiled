/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> ble_util_buf.o -> r_ble_util_buf_acl_tx_elt_get
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int r_ble_util_buf_acl_tx_elt_get(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_1 - 0x9c00U >> 10;
  uVar1 = uVar2 & 0xff;
  if (0xb < (uVar2 & 0xff)) {
    (**(code **)(_r_plf_funcs_p + 0xc))
              (uVar1,param_1,"ble_util_buf.c",0x181,*(code **)(_r_plf_funcs_p + 0xc));
  }
  return _p_ble_util_buf_env + (uVar1 + 0x21) * 8;
}

