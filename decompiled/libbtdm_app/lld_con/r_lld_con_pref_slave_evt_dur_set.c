/*
 * Last changed at upstream commit aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * https://github.com/espressif/esp32c3-bt-lib/commit/aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * Upstream date: 2025-03-20 20:31:24 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(d74042a8)
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
  code *pcVar2;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar1 = *(int *)(&lld_con_env + param_1 * 4);
  if (iVar1 == 0) {
    (**(code **)(_r_plf_funcs_p + 0xc))(0,"lld_con.c",0x10f0,*(code **)(_r_plf_funcs_p + 0xc));
  }
  else {
    pcVar2 = *(code **)(_r_ip_funcs_p + 0x34c);
    *(undefined2 *)(iVar1 + 0x74) = param_2;
    (*pcVar2)(pcVar2);
    *(ushort *)(iVar1 + 0x84) = *(ushort *)(iVar1 + 0x84) & 0xdfff | (ushort)(param_3 << 0xd);
  }
                    /* WARNING: Could not recover jumptable at 0x00014e36. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_osi_funcs_p + 0x18))();
  return;
}

