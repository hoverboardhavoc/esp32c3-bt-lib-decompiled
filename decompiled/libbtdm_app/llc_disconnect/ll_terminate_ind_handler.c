/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llc_disconnect.o -> ll_terminate_ind_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 ll_terminate_ind_handler(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(&llc_env + param_1 * 4);
  (**(code **)(_r_ip_funcs_p + 0x68c))(0,0,*(code **)(_r_ip_funcs_p + 0x68c));
  (**(code **)(_r_ip_funcs_p + 0x68c))(param_1,1,0,*(code **)(_r_ip_funcs_p + 0x68c));
  (**(code **)(_r_ip_funcs_p + 0x55c))
            (param_1,*(undefined1 *)(param_2 + 1),~*(ushort *)(iVar1 + 0x42) & 1,
             *(code **)(_r_ip_funcs_p + 0x55c));
  return 0;
}

