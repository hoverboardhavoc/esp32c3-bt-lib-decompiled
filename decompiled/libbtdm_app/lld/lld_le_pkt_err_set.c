/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> lld.o -> lld_le_pkt_err_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void lld_le_pkt_err_set(uint param_1,uint param_2)

{
  if (9 < param_1) {
    (**(code **)(_r_plf_funcs_p + 0xc))(10,"lld.c",0x2ca,*(code **)(_r_plf_funcs_p + 0xc));
  }
  if ((param_2 & 0xf) != 0) {
    if ((param_2 & 1) != 0) {
      *(short *)(&lld_le_pkt_env + param_1) = *(short *)(&lld_le_pkt_env + param_1) + 1;
    }
    if ((param_2 & 8) != 0) {
      *(short *)((int)&lld_le_pkt_env + param_1 * 4 + 2) =
           *(short *)((int)&lld_le_pkt_env + param_1 * 4 + 2) + 1;
    }
  }
  return;
}

