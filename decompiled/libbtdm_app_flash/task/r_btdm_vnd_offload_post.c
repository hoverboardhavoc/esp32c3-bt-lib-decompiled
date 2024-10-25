/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> task.o -> r_btdm_vnd_offload_post
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x0001004a) */
/* WARNING: Removing unreachable block (ram,0x00010062) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_btdm_vnd_offload_post(uint param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 uStack_28;
  undefined1 uStack_27;
  undefined2 uStack_26;
  undefined4 uStack_24;
  
  if (param_1 < 2) {
    uStack_26 = 0;
    uStack_28 = 0xd;
    uStack_27 = (undefined1)param_1;
    uStack_24 = param_2;
    iVar2 = (**(code **)(_r_osi_funcs_p + 0x54))
                      (_g_rw_schd_queue,&uStack_28,0xffffffff,*(code **)(_r_osi_funcs_p + 0x54));
    if (iVar2 == 1) {
      uVar1 = 0;
    }
    else {
      if (0 < _g_bt_plf_log_level) {
        ets_printf("Send Queue Failed\n");
      }
      uVar1 = 0xfffffffd;
      (**(code **)(_r_osi_funcs_p + 0x7c))(uStack_24,*(code **)(_r_osi_funcs_p + 0x7c));
    }
    (**(code **)(_r_osi_funcs_p + 0x38))(btdm_ol_task_env,*(code **)(_r_osi_funcs_p + 0x38));
    return uVar1;
  }
  return 0xffffffff;
}

