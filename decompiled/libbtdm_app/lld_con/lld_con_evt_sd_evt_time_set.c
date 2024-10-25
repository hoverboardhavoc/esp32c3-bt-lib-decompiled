/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> lld_con.o -> lld_con_evt_sd_evt_time_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 lld_con_evt_sd_evt_time_set(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_2 != 0) {
    uVar1 = 2;
    if (param_3 != 0) {
      (**(code **)(_r_osi_funcs_p + 0x14))(2,*(code **)(_r_osi_funcs_p + 0x14));
      iVar2 = *(int *)(&lld_con_env + param_1 * 4);
      uVar1 = 2;
      if (iVar2 != 0) {
        *(short *)(iVar2 + 0x76) = (short)param_3;
        *(short *)(iVar2 + 0x78) = (short)param_2;
        (**(code **)(_r_ip_funcs_p + 0x34c))(param_1,*(code **)(_r_ip_funcs_p + 0x34c));
        (**(code **)(_r_ip_funcs_p + 0x5e4))(param_1,0,*(code **)(_r_ip_funcs_p + 0x5e4));
        uVar1 = 0;
      }
      (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
    }
    return uVar1;
  }
  return 2;
}

