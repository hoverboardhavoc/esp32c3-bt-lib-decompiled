/*
 * Last changed at upstream commit 9b50531537e755792ac827d00d233eab499a0b37
 * https://github.com/espressif/esp32c3-bt-lib/commit/9b50531537e755792ac827d00d233eab499a0b37
 * Upstream date: 2025-12-17 10:51:37 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(5106725)
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
    (**(code **)(_r_plf_funcs_p + 0xc))(0,"lld_con.c",0x1155,*(code **)(_r_plf_funcs_p + 0xc));
  }
  else {
    uVar1 = *(ushort *)(iVar2 + 0x72);
    if (param_2 < uVar1) {
      uVar1 = (ushort)param_2;
    }
    *(ushort *)(iVar2 + 0x72) = uVar1;
  }
                    /* WARNING: Could not recover jumptable at 0x00014d94. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return;
}

