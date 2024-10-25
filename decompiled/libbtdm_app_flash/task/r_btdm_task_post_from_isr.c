/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> task.o -> r_btdm_task_post_from_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_btdm_task_post_from_isr(uint param_1)

{
  int iVar1;
  uint auStack_28 [5];
  
  if (param_1 < 0xe) {
    if ((0x2f84U >> (param_1 & 0x1f) & 1) != 0) {
      auStack_28[0] = param_1 & 0xff;
      auStack_28[1] = 0;
      iVar1 = (**(code **)(_r_osi_funcs_p + 0x58))
                        (_g_rw_schd_queue,auStack_28,0,*(code **)(_r_osi_funcs_p + 0x58));
      if (iVar1 != 1) {
        r_assert_param(param_1 & 0xff,0,"task.c",0x5f);
      }
    }
    auStack_28[0] = 0;
    (**(code **)(_r_osi_funcs_p + 0x30))
              (btdm_ol_task_env,auStack_28,*(code **)(_r_osi_funcs_p + 0x30));
    if (auStack_28[0] != 0) {
      (**(code **)(_r_osi_funcs_p + 0x20))(*(code **)(_r_osi_funcs_p + 0x20));
    }
    return 0;
  }
  return 0xffffffff;
}

