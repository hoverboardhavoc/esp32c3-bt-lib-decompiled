/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_con.o -> r_lld_con_pref_slave_evt_dur_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_con_pref_slave_evt_dur_set(int param_1,undefined2 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar1 = _r_ip_funcs_p;
  iVar2 = *(int *)(&lld_con_env + param_1 * 4);
  if (iVar2 == 0) {
    (**(code **)(_r_plf_funcs_p + 0xc))(0,"lld_con.c",0x1124,*(code **)(_r_plf_funcs_p + 0xc));
  }
  else {
    *(undefined2 *)(iVar2 + 0x74) = param_2;
    (**(code **)(iVar1 + 0x34c))(*(code **)(iVar1 + 0x34c));
    *(ushort *)(iVar2 + 0x84) = *(ushort *)(iVar2 + 0x84) & 0xdfff | (ushort)(param_3 << 0xd);
  }
                    /* WARNING: Could not recover jumptable at 0x00014e2e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return;
}

