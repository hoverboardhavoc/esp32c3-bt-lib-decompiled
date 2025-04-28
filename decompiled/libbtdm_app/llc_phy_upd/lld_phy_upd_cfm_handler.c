/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llc_phy_upd.o -> lld_phy_upd_cfm_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 lld_phy_upd_cfm_handler(uint param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  code *pcVar3;
  
  iVar1 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  if (*(char *)(iVar1 + 0x18) == '\0') {
    (**(code **)(_r_plf_funcs_p + 8))
              (0,"llc_phy_upd.c",0x608,param_2,*(code **)(_r_plf_funcs_p + 8));
    return 0;
  }
  param_1 = param_1 >> 8;
  iVar1 = (**(code **)(_r_ip_funcs_p + 0x678))(param_1,0,*(code **)(_r_ip_funcs_p + 0x678));
  if (iVar1 == 9) {
    pcVar3 = *(code **)(_r_ip_funcs_p + 0x648);
    uVar2 = 4;
  }
  else {
    iVar1 = (**(code **)(_r_ip_funcs_p + 0x678))(param_1,1,*(code **)(_r_ip_funcs_p + 0x678));
    if (iVar1 != 9) {
      return 0;
    }
    uVar2 = 7;
    pcVar3 = *(code **)(_r_ip_funcs_p + 0x650);
  }
  (*pcVar3)(param_1,uVar2,0,pcVar3);
  return 0;
}

