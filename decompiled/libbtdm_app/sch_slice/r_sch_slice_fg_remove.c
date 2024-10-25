/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> sch_slice.o -> r_sch_slice_fg_remove
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_sch_slice_fg_remove(uint param_1)

{
  int iVar1;
  
  sch_slice_env = ~(byte)(1 << (param_1 & 0x1f)) & sch_slice_env;
  if (param_1 == 2) {
    _sch_slice_params = -1;
  }
  else {
    (**(code **)(_r_plf_funcs_p + 8))(0,"sch_slice.c",0x1db,*(code **)(_r_plf_funcs_p + 8));
  }
  (**(code **)(_r_ip_funcs_p + 0x71c))(*(code **)(_r_ip_funcs_p + 0x71c));
  if ((_sch_slice_params == -1) &&
     (iVar1 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0)),
     *(char *)(iVar1 + 0x23) != '\0')) {
                    /* WARNING: Could not recover jumptable at 0x000102b6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_ip_funcs_p + 0x42c))();
    return;
  }
  return;
}

