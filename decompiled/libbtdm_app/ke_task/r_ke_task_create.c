/*
 * Last changed at upstream commit 2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * https://github.com/espressif/esp32c3-bt-lib/commit/2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * Upstream date: 2025-02-25 15:16:47 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(723439d)
 * Source: libbtdm_app -> ke_task.o -> r_ke_task_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_ke_task_create(uint param_1,int param_2)

{
  undefined4 uVar1;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  if (param_1 < 0x1f) {
    uVar1 = 4;
    if (*(int *)(&ke_task_env + param_1 * 4) == 0) {
      *(int *)(&ke_task_env + param_1 * 4) = param_2;
      uVar1 = 0;
    }
  }
  else {
    (**(code **)(_r_plf_funcs_p + 0xc))(0x1f,"ke_task.c",0x17f,*(code **)(_r_plf_funcs_p + 0xc));
    uVar1 = 3;
  }
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return uVar1;
}

