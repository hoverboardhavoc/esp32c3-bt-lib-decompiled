/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> h4tl.o -> r_h4tl_out_of_sync
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_h4tl_out_of_sync(int param_1)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)
           (**(code **)(_r_modules_funcs_p + 200))
                     (0x1103,0,0x10,1,*(code **)(_r_modules_funcs_p + 200));
  *puVar1 = 0;
  (**(code **)(_r_ip_funcs_p + 0x8c))(*(code **)(_r_ip_funcs_p + 0x8c));
  memset((void *)(param_1 + 10),0,8);
  *(undefined1 *)(param_1 + 0x12) = *(undefined1 *)(param_1 + 0x13);
  (**(code **)(_r_modules_funcs_p + 0x70))(param_1,*(code **)(_r_modules_funcs_p + 0x70));
                    /* WARNING: Could not recover jumptable at 0x00010148. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_modules_funcs_p + 0x2b0))(4,*(code **)(_r_modules_funcs_p + 0x2b0));
  return;
}

