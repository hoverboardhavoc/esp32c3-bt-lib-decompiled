/*
 * Last changed at upstream commit 2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * https://github.com/espressif/esp32c3-bt-lib/commit/2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * Upstream date: 2025-02-25 15:16:47 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(723439d)
 * Source: libbtdm_app -> ke_task.o -> r_ke_state_get
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 r_ke_state_get(uint param_1)

{
  uint uVar1;
  int unaff_s2;
  
  uVar1 = param_1 & 0xff;
  param_1 = param_1 >> 8;
  if (uVar1 < 0x1f) {
    unaff_s2 = *(int *)(&ke_task_env + uVar1 * 4);
    if (unaff_s2 == 0) goto _L100;
    if (param_1 < *(ushort *)(unaff_s2 + 8)) goto _L99;
  }
  else {
    (**(code **)(_r_plf_funcs_p + 8))(0,"ke_task.c",0x1db,*(code **)(_r_plf_funcs_p + 8));
_L100:
    (**(code **)(_r_plf_funcs_p + 0xc))
              (uVar1,param_1,"ke_task.c",0x1e2,*(code **)(_r_plf_funcs_p + 0xc));
    ebreak();
  }
  (**(code **)(_r_plf_funcs_p + 0xc))(param_1,"ke_task.c",0x1e3,*(code **)(_r_plf_funcs_p + 0xc));
  if (*(ushort *)(unaff_s2 + 8) <= param_1) {
    return 0xff;
  }
_L99:
  return *(undefined1 *)(param_1 + *(int *)(unaff_s2 + 4));
}

