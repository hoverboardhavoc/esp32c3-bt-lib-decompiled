/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llc_ver_exch.o -> r_llc_hci_version_info_send
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llc_hci_version_info_send(undefined4 param_1,int param_2,undefined1 *param_3)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)
           (**(code **)(_r_modules_funcs_p + 200))
                     (0x1103,param_1,0xc,10,*(code **)(_r_modules_funcs_p + 200));
  *(short *)(puVar1 + 2) = (short)param_1;
  *puVar1 = (char)param_2;
  if (param_2 == 0) {
    *(undefined2 *)(puVar1 + 6) = *(undefined2 *)(param_3 + 2);
    *(undefined2 *)(puVar1 + 8) = *(undefined2 *)(param_3 + 4);
    puVar1[4] = *param_3;
  }
                    /* WARNING: Could not recover jumptable at 0x0001009a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_ip_funcs_p + 0x8c))(*(code **)(_r_ip_funcs_p + 0x8c));
  return;
}

