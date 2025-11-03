/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> llc_llcp.o -> lld_llcp_tx_cfm_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 lld_llcp_tx_cfm_handler(uint param_1)

{
  int iVar1;
  int iVar2;
  
  param_1 = param_1 >> 8;
  iVar2 = *(int *)(&llc_env + param_1 * 4);
  if (iVar2 == 0) {
    r_assert_param(0,"llc_llcp.c",0x3ff);
  }
  else {
    iVar1 = r_co_list_pop_front(iVar2 + 0x28);
    if (*(code **)(iVar1 + 4) != (code *)0x0) {
      (**(code **)(iVar1 + 4))(param_1,*(undefined1 *)(iVar1 + 9));
    }
    r_ke_free(iVar1);
    *(ushort *)(iVar2 + 0x42) = *(ushort *)(iVar2 + 0x42) & 0xfffd;
  }
  r_llc_llcp_tx_check_hack(param_1);
  return 0;
}

