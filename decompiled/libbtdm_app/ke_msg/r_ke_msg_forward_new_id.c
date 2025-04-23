/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> ke_msg.o -> r_ke_msg_forward_new_id
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_ke_msg_forward_new_id(int param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar1 = _r_modules_funcs_p;
  *(undefined2 *)(param_1 + -8) = param_2;
  *(undefined2 *)(param_1 + -6) = param_3;
  UNRECOVERED_JUMPTABLE = *(code **)(iVar1 + 0xe0);
  *(undefined2 *)(param_1 + -4) = param_4;
                    /* WARNING: Could not recover jumptable at 0x00010128. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(UNRECOVERED_JUMPTABLE);
  return;
}

