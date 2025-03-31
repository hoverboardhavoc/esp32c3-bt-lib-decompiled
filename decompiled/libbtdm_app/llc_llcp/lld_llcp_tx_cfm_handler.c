/*
 * Last changed at upstream commit 2fd7ad255fceabdfba56882ce4523efdba2fc255
 * https://github.com/espressif/esp32c3-bt-lib/commit/2fd7ad255fceabdfba56882ce4523efdba2fc255
 * Upstream date: 2025-03-31 11:18:40 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(566c8e3)
 * Source: libbtdm_app -> llc_llcp.o -> lld_llcp_tx_cfm_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 lld_llcp_tx_cfm_handler(uint param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = *(int *)(&llc_env + (param_1 >> 8) * 4);
  uVar3 = param_1 >> 8 & 0xff;
  if (iVar1 == 0) {
    (**(code **)(_r_plf_funcs_p + 0xc))(0,"llc_llcp.c",0x3e9,*(code **)(_r_plf_funcs_p + 0xc));
  }
  else {
    iVar2 = (**(code **)(_r_modules_funcs_p + 0x40))
                      (iVar1 + 0x28,*(code **)(_r_modules_funcs_p + 0x40));
    if (*(code **)(iVar2 + 4) != (code *)0x0) {
      (**(code **)(iVar2 + 4))(uVar3,*(undefined1 *)(iVar2 + 9));
    }
    (**(code **)(_r_modules_funcs_p + 0x110))(iVar2,*(code **)(_r_modules_funcs_p + 0x110));
    *(ushort *)(iVar1 + 0x42) = *(ushort *)(iVar1 + 0x42) & 0xfffd;
  }
  (**(code **)(_r_ip_funcs_p + 0x5b8))(uVar3,*(code **)(_r_ip_funcs_p + 0x5b8));
  return 0;
}

