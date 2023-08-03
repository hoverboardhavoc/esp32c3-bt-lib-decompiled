/*
 * Last changed at upstream commit 040cd0eafd8c6ee52bc7f7d5d633c9dc1b99bba2
 * https://github.com/espressif/esp32c3-bt-lib/commit/040cd0eafd8c6ee52bc7f7d5d633c9dc1b99bba2
 * Upstream date: 2023-08-03 10:45:08 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(ff6efe7)
 * Source: libbtdm_app -> llc_phy_upd.o -> r_llc_rem_phy_upd_proc_continue_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llc_rem_phy_upd_proc_continue_eco(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(&llc_env + param_1 * 4);
  (**(code **)(_r_ip_funcs_p + 0x674))(1,*(code **)(_r_ip_funcs_p + 0x674));
  iVar1 = (**(code **)(_r_ip_funcs_p + 0x680))(*(code **)(_r_ip_funcs_p + 0x680));
  if (iVar1 == 5) {
    (**(code **)(_r_ip_funcs_p + 0x938))
              (iVar2 + 0x26,iVar2 + 0x27,param_3,*(code **)(_r_ip_funcs_p + 0x938));
  }
  r_llc_rem_phy_upd_proc_continue(param_1,param_2,param_3);
  return;
}

