/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llc_le_ping.o -> ll_ping_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 ll_ping_rsp_handler(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  if (*(char *)(iVar1 + 0x20) == '\0') {
    return 0xc;
  }
  iVar1 = (**(code **)(_r_ip_funcs_p + 0x678))(0,param_2,*(code **)(_r_ip_funcs_p + 0x678));
  if (iVar1 == 8) {
    (**(code **)(_r_ip_funcs_p + 0x608))(param_1,1,0,*(code **)(_r_ip_funcs_p + 0x608));
  }
  return 0;
}

