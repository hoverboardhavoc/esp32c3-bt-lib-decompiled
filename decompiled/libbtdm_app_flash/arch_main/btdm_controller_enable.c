/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> arch_main.o -> btdm_controller_enable
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 btdm_controller_enable(uint param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = r_sdk_config_get_opts();
  uVar2 = 0xffffffff;
  if (*(byte *)(iVar1 + 0xc) == param_1) {
    r_btdm_task_post(9,0,0,1);
    (**(code **)(_r_osi_funcs_p + 0x34))
              (_g_rw_init_sem,0xffffffff,*(code **)(_r_osi_funcs_p + 0x34));
    uVar2 = 0;
  }
  return uVar2;
}

