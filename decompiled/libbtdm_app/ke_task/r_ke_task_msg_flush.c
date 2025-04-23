/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> ke_task.o -> r_ke_task_msg_flush
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_ke_task_msg_flush(uint param_1)

{
  bool bVar1;
  int *piVar2;
  int *piVar3;
  
  bVar1 = false;
  piVar2 = _ke_env;
  while( true ) {
    if (piVar2 == (int *)0x0) {
      return;
    }
    do {
      piVar3 = (int *)*piVar2;
      if (param_1 == *(byte *)((int)piVar2 + 6)) {
        (**(code **)(_r_modules_funcs_p + 0x1c))
                  (&ke_env,piVar2,*(code **)(_r_modules_funcs_p + 0x1c));
        (**(code **)(_r_modules_funcs_p + 0xd8))(piVar2,*(code **)(_r_modules_funcs_p + 0xd8));
      }
      piVar2 = piVar3;
    } while (piVar3 != (int *)0x0);
    if (bVar1) break;
    bVar1 = true;
    piVar2 = _ke_task_env;
  }
  return;
}

