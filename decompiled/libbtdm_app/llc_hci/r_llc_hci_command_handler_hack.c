/*
 * Last changed at upstream commit b223604efd557d0a5314afb3b751229df424d244
 * https://github.com/espressif/esp32c3-bt-lib/commit/b223604efd557d0a5314afb3b751229df424d244
 * Upstream date: 2021-06-24 21:26:02 +0800
 * Upstream subject: Update ESP32-C3 and ESP32-S3 bt lib (9c99115)
 * Source: libbtdm_app -> llc_hci.o -> r_llc_hci_command_handler_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 r_llc_hci_command_handler_hack(undefined1 *param_1,undefined4 param_2)

{
  undefined1 uVar1;
  code *UNRECOVERED_JUMPTABLE;
  int iVar2;
  undefined4 uVar3;
  
  UNRECOVERED_JUMPTABLE = (code *)llc_hci_command_handler_search(param_2);
  if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
    uVar1 = *param_1;
    iVar2 = llc_hci_command_handler_pre(uVar1,param_1,param_2);
    if (iVar2 == 0) {
                    /* WARNING: Could not recover jumptable at 0x000101ea. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar3 = (*UNRECOVERED_JUMPTABLE)(uVar1,param_1,param_2);
      return uVar3;
    }
    if (iVar2 != 1) {
      return 2;
    }
  }
  return 0;
}

