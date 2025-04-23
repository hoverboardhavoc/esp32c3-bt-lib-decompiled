/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llc_disconnect.o -> r_llc_disconnect_end
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llc_disconnect_end(undefined4 param_1,undefined1 param_2,undefined1 param_3)

{
  int iVar1;
  undefined1 *puVar2;
  
  puVar2 = (undefined1 *)
           (**(code **)(_r_modules_funcs_p + 200))
                     (0x1103,param_1,5,6,*(code **)(_r_modules_funcs_p + 200));
  *puVar2 = param_2;
  iVar1 = _r_ip_funcs_p;
  puVar2[4] = param_3;
  *(short *)(puVar2 + 2) = (short)param_1;
                    /* WARNING: Could not recover jumptable at 0x0001004c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(iVar1 + 0x8c))(*(code **)(iVar1 + 0x8c));
  return;
}

