/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> emi.o -> r_emi_get_em_mapping_idx_by_offset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 r_emi_get_em_mapping_idx_by_offset(uint param_1)

{
  uint uVar1;
  
  uVar1 = param_1 >> 10 & 0xffff;
  if (0x32 < uVar1) {
    (**(code **)(_r_plf_funcs_p + 0xc))(uVar1,"emi.c",0x159,*(code **)(_r_plf_funcs_p + 0xc));
  }
  return (&em_base_reg_lut)[uVar1 * 4];
}

