/*
 * Last changed at upstream commit 5c6ab5248a124cffc731a9e4764473fdeef38054
 * https://github.com/espressif/esp32c3-bt-lib/commit/5c6ab5248a124cffc731a9e4764473fdeef38054
 * Upstream date: 2023-03-09 14:58:19 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(85a1090)
 * Source: libbtdm_app -> llc_hci.o -> r_llc_hci_command_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_llc_hci_command_handler(undefined1 *param_1,undefined4 param_2)

{
  undefined1 uVar1;
  code *UNRECOVERED_JUMPTABLE;
  int iVar2;
  undefined4 uVar3;
  
  UNRECOVERED_JUMPTABLE =
       (code *)(**(code **)(_r_ip_funcs_p + 0x8e0))(param_2,*(code **)(_r_ip_funcs_p + 0x8e0));
  if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
    uVar1 = *param_1;
    iVar2 = (**(code **)(_r_ip_funcs_p + 0x8dc))
                      (uVar1,param_1,param_2,*(code **)(_r_ip_funcs_p + 0x8dc));
    if (iVar2 == 0) {
                    /* WARNING: Could not recover jumptable at 0x00010228. Too many branches */
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

