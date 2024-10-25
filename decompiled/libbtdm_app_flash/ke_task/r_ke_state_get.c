/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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
    if (unaff_s2 == 0) goto _L95;
    if (param_1 < *(ushort *)(unaff_s2 + 8)) goto _L94;
  }
  else {
    r_assert_err(0,"ke_task.c",0x1d3);
_L95:
    r_assert_param(uVar1,param_1,"ke_task.c",0x1da);
    piVar2 = (int *)(uint)_DAT_00000008;
    ebreak();
  }
  r_assert_param(param_1,"ke_task.c",0x1db,piVar2);
  if (*(ushort *)(unaff_s2 + 8) <= param_1) {
    return 0xff;
  }
_L94:
  return *(undefined1 *)(param_1 + *(int *)(unaff_s2 + 4));
}

