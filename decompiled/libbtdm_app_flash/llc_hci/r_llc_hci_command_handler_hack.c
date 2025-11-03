/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> llc_hci.o -> r_llc_hci_command_handler_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int r_llc_hci_command_handler_hack(undefined1 *param_1,undefined4 param_2)

{
  undefined1 uVar1;
  code *UNRECOVERED_JUMPTABLE;
  int iVar2;
  
  UNRECOVERED_JUMPTABLE = (code *)r_llc_hci_command_handler_search(param_2);
  if (UNRECOVERED_JUMPTABLE == (code *)0x0) {
    iVar2 = 0;
  }
  else {
    uVar1 = *param_1;
    iVar2 = r_llc_hci_command_handler_pre(uVar1,param_1,param_2);
    if (iVar2 == 0) {
                    /* WARNING: Could not recover jumptable at 0x00010394. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar2 = (*UNRECOVERED_JUMPTABLE)(uVar1,param_1,param_2,UNRECOVERED_JUMPTABLE);
      return iVar2;
    }
    iVar2 = (uint)(iVar2 != 1) << 1;
  }
  return iVar2;
}

