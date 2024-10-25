/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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
    if (unaff_s2 == 0) goto _L98;
    if (param_1 < *(ushort *)(unaff_s2 + 8)) goto _L97;
  }
  else {
    (**(code **)(_r_plf_funcs_p + 8))(0,"ke_task.c",0x1d3,*(code **)(_r_plf_funcs_p + 8));
_L98:
    (**(code **)(_r_plf_funcs_p + 0xc))
              (uVar1,param_1,"ke_task.c",0x1da,*(code **)(_r_plf_funcs_p + 0xc));
    ebreak();
  }
  (**(code **)(_r_plf_funcs_p + 0xc))(param_1,"ke_task.c",0x1db,*(code **)(_r_plf_funcs_p + 0xc));
  if (*(ushort *)(unaff_s2 + 8) <= param_1) {
    return 0xff;
  }
_L97:
  return *(undefined1 *)(param_1 + *(int *)(unaff_s2 + 4));
}

