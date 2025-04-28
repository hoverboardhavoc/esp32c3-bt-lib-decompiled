/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llc_hci.o -> r_llc_hci_command_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int r_llc_hci_command_handler(undefined1 *param_1,undefined4 param_2)

{
  undefined1 uVar1;
  code *UNRECOVERED_JUMPTABLE;
  int iVar2;
  
  UNRECOVERED_JUMPTABLE =
       (code *)(**(code **)(_r_ip_funcs_p + 0x8e0))(param_2,*(code **)(_r_ip_funcs_p + 0x8e0));
  if (UNRECOVERED_JUMPTABLE == (code *)0x0) {
    iVar2 = 0;
  }
  else {
    uVar1 = *param_1;
    iVar2 = (**(code **)(_r_ip_funcs_p + 0x8dc))
                      (uVar1,param_1,param_2,*(code **)(_r_ip_funcs_p + 0x8dc));
    if (iVar2 == 0) {
                    /* WARNING: Could not recover jumptable at 0x000104f2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar2 = (*UNRECOVERED_JUMPTABLE)(uVar1,param_1,param_2,UNRECOVERED_JUMPTABLE);
      return iVar2;
    }
    iVar2 = (uint)(iVar2 != 1) << 1;
  }
  return iVar2;
}

