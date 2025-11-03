/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
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
  
  param_1 = param_1 >> 8;
  iVar2 = *(int *)(&llc_env + param_1 * 4);
  if (iVar2 == 0) {
    (**(code **)(_r_plf_funcs_p + 0xc))(0,"llc_llcp.c",0x3ff,*(code **)(_r_plf_funcs_p + 0xc));
  }
  else {
    iVar1 = (**(code **)(_r_modules_funcs_p + 0x40))
                      (iVar2 + 0x28,*(code **)(_r_modules_funcs_p + 0x40));
    if (*(code **)(iVar1 + 4) != (code *)0x0) {
      (**(code **)(iVar1 + 4))(param_1,*(undefined1 *)(iVar1 + 9));
    }
    (**(code **)(_r_modules_funcs_p + 0x110))(iVar1,*(code **)(_r_modules_funcs_p + 0x110));
    *(ushort *)(iVar2 + 0x42) = *(ushort *)(iVar2 + 0x42) & 0xfffd;
  }
  (**(code **)(_r_ip_funcs_p + 0x5b8))(param_1,*(code **)(_r_ip_funcs_p + 0x5b8));
  return 0;
}

