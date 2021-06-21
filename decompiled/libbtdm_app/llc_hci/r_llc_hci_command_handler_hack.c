/*
 * Last changed at upstream commit f45e6918026b6e8fdc6dec3f626a98c35960f50e
 * https://github.com/espressif/esp32c3-bt-lib/commit/f45e6918026b6e8fdc6dec3f626a98c35960f50e
 * Upstream date: 2021-06-21 17:00:22 +0530
 * Upstream subject: Fix MIC error issue during start_encryption procedure Update ESP32C3 and ESP32S3 libraries (a86af1e)
 * Source: libbtdm_app -> llc_hci.o -> r_llc_hci_command_handler_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 r_llc_hci_command_handler_hack(ushort *param_1,undefined4 param_2)

{
  ushort uVar1;
  code *UNRECOVERED_JUMPTABLE;
  int iVar2;
  undefined4 uVar3;
  
  UNRECOVERED_JUMPTABLE = (code *)llc_hci_command_handler_search(param_2);
  if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
    uVar1 = *param_1;
    iVar2 = llc_hci_command_handler_pre(param_1,param_2);
    if (iVar2 == 0) {
                    /* WARNING: Could not recover jumptable at 0x000101b8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar3 = (*UNRECOVERED_JUMPTABLE)(uVar1 & 0xff,param_1,param_2);
      return uVar3;
    }
  }
  return 0;
}

