/*
 * Last changed at upstream commit d23ae97bb91d66e08c58bfaabaeed0a5ba7b7b5d
 * https://github.com/espressif/esp32c3-bt-lib/commit/d23ae97bb91d66e08c58bfaabaeed0a5ba7b7b5d
 * Upstream date: 2024-11-25 10:28:56 +0800
 * Upstream subject: fix(bt): Fixed BLE assert ke_mem.c line 267(d7561c2)
 * Source: libbtdm_app -> rwip.o -> r_rwip_schedule
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_rwip_schedule(void)

{
  if ((_rwip_env & 1) == 0) {
                    /* WARNING: Could not recover jumptable at 0x000103a6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_modules_funcs_p + 0x104))();
    return;
  }
  return;
}

