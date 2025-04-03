/*
 * Last changed at upstream commit f23a340e82d6a4be40f83214385a98c5bd30ccdd
 * https://github.com/espressif/esp32c3-bt-lib/commit/f23a340e82d6a4be40f83214385a98c5bd30ccdd
 * Upstream date: 2025-04-03 18:07:15 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(a684dd5)
 * Source: libbtdm_app -> llm.o -> r_llm_activity_free_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llm_activity_free_set(int param_1)

{
  int iVar1;
  int iVar2;
  
  *(undefined4 *)((param_1 + 0x1800c4cb) * 4) = 0;
  iVar1 = _r_ip_funcs_p;
  iVar2 = *(int *)(_p_llm_env + 8) + param_1 * 0x44;
  *(undefined1 *)(iVar2 + 0x40) = 0;
                    /* WARNING: Could not recover jumptable at 0x000114e4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(iVar1 + 0x6f4))(iVar2 + 0xc);
  return;
}

