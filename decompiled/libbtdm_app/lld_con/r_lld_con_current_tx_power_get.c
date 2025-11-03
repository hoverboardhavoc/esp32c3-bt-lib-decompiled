/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app -> lld_con.o -> r_lld_con_current_tx_power_get
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_lld_con_current_tx_power_get(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  if (*(int *)(&lld_con_env + param_1 * 4) == 0) {
    (**(code **)(_r_plf_funcs_p + 0xc))
              (param_1,0,"lld_con.c",0x1110,*(code **)(_r_plf_funcs_p + 0xc));
    uVar2 = 0;
  }
  else {
    iVar1 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar2 = (*_lld_exp_sync_pos_tab)
                      (*(ushort *)(param_1 * 0x5a + 0x18 + iVar1) & 0xff,param_2,
                       _lld_exp_sync_pos_tab);
  }
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return uVar2;
}

