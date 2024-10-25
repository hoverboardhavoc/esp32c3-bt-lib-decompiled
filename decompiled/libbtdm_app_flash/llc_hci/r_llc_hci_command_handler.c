/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llc_hci.o -> r_llc_hci_command_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 r_llc_hci_command_handler(undefined1 *param_1,undefined4 param_2)

{
  undefined1 uVar1;
  code *UNRECOVERED_JUMPTABLE;
  int iVar2;
  undefined4 uVar3;
  
  UNRECOVERED_JUMPTABLE = (code *)r_llc_hci_command_handler_search(param_2);
  if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
    uVar1 = *param_1;
    iVar2 = r_llc_hci_command_handler_pre(uVar1,param_1,param_2);
    if (iVar2 == 0) {
                    /* WARNING: Could not recover jumptable at 0x00010366. Too many branches */
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

