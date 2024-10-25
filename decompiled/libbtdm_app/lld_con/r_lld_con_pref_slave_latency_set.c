/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> lld_con.o -> r_lld_con_pref_slave_latency_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_con_pref_slave_latency_set(int param_1,uint param_2)

{
  ushort uVar1;
  int iVar2;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar2 = *(int *)(&lld_con_env + param_1 * 4);
  if (iVar2 == 0) {
    (**(code **)(_r_plf_funcs_p + 0xc))(0,"lld_con.c",0x10d6,*(code **)(_r_plf_funcs_p + 0xc));
  }
  else {
    uVar1 = *(ushort *)(iVar2 + 0x72);
    if (param_2 < uVar1) {
      uVar1 = (ushort)param_2;
    }
    *(ushort *)(iVar2 + 0x72) = uVar1;
  }
                    /* WARNING: Could not recover jumptable at 0x00014da2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_osi_funcs_p + 0x18))();
  return;
}

