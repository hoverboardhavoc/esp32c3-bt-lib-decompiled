/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> aes_cmac.o -> r_aes_cmac_start
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_aes_cmac_start(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  void *pvVar1;
  
  *(short *)(param_1 + 0x30) = (short)param_4;
  *(undefined4 *)(param_1 + 0x1c) = param_2;
  *(undefined1 *)(param_1 + 0x33) = 1;
  *(undefined4 *)(param_1 + 0x18) = param_3;
  *(char *)(param_1 + 0x32) = (char)(param_4 + 0xf >> 4);
  pvVar1 = memcpy((void *)(param_1 + 0x20),&aes_cmac_zero,0x10);
                    /* WARNING: Could not recover jumptable at 0x00010094. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_modules_funcs_p + 0x340))(param_1,pvVar1,*(code **)(_r_modules_funcs_p + 0x340));
  return;
}

