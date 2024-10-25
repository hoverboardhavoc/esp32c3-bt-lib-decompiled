/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llc_disconnect.o -> llc_stopped_ind_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 llc_stopped_ind_handler(uint param_1)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = *(int *)(&llc_env + (param_1 >> 8) * 4);
  uVar1 = param_1 >> 8 & 0xff;
  if (iVar2 == 0) {
    (**(code **)(_r_plf_funcs_p + 0xc))(0,"llc_disconnect.c",0x17b,*(code **)(_r_plf_funcs_p + 0xc))
    ;
  }
  (**(code **)(_r_ip_funcs_p + 0x560))
            (uVar1,0,*(undefined1 *)(iVar2 + 0x46),*(code **)(_r_ip_funcs_p + 0x560));
  (**(code **)(_r_ip_funcs_p + 0x65c))(uVar1,0,*(code **)(_r_ip_funcs_p + 0x65c));
  (**(code **)(_r_ip_funcs_p + 0x4e8))(uVar1,*(code **)(_r_ip_funcs_p + 0x4e8));
  return 0;
}

