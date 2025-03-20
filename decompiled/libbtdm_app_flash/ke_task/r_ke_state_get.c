/*
 * Last changed at upstream commit aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * https://github.com/espressif/esp32c3-bt-lib/commit/aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * Upstream date: 2025-03-20 20:31:24 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(d74042a8)
 * Source: libbtdm_app_flash -> ke_task.o -> r_ke_state_get
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 r_ke_state_get(uint param_1)

{
  uint uVar1;
  int *piVar2;
  int unaff_s2;
  
  uVar1 = param_1 & 0xff;
  param_1 = param_1 >> 8;
  if (uVar1 < 0x1f) {
    piVar2 = (int *)(&ke_task_env + uVar1 * 4);
    unaff_s2 = *piVar2;
    if (unaff_s2 == 0) goto _L97;
    if (param_1 < *(ushort *)(unaff_s2 + 8)) goto _L96;
  }
  else {
    r_assert_err(0,"ke_task.c",0x1d7);
_L97:
    r_assert_param(uVar1,param_1,"ke_task.c",0x1de);
    piVar2 = (int *)(uint)_DAT_00000008;
    ebreak();
  }
  r_assert_param(param_1,"ke_task.c",0x1df,piVar2);
  if (*(ushort *)(unaff_s2 + 8) <= param_1) {
    return 0xff;
  }
_L96:
  return *(undefined1 *)(param_1 + *(int *)(unaff_s2 + 4));
}

