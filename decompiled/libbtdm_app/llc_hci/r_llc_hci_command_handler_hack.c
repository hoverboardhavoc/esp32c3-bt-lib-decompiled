/*
 * Last changed at upstream commit 022b7da7fcf0043f891c2e8ccd8c241243018e2f
 * https://github.com/espressif/esp32c3-bt-lib/commit/022b7da7fcf0043f891c2e8ccd8c241243018e2f
 * Upstream date: 2021-04-20 16:00:04 +0800
 * Upstream subject: ESP32-C3, ESP32-S3: update libbtdm_app.a(d1d0c6f1)
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
                    /* WARNING: Could not recover jumptable at 0x00010090. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar3 = (*UNRECOVERED_JUMPTABLE)(uVar1 & 0xff,param_1,param_2);
      return uVar3;
    }
  }
  return 0;
}

