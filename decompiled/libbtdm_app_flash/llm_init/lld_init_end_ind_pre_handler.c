/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llm_init.o -> lld_init_end_ind_pre_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void lld_init_end_ind_pre_handler(byte *param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  
  uVar1 = (uint)*param_1;
  iVar2 = r_sdk_config_get_opts();
  if (*(byte *)(iVar2 + 0xd) <= uVar1) {
    r_assert_param(uVar1,0,"llm_init.c",0x4d);
  }
  piVar4 = (int *)(*(int *)(_p_llm_env + 8) + uVar1 * 0x44);
  if (((((char)piVar4[0x10] == '\x05') && (*piVar4 != 0)) &&
      (_bt_rf_coex_hooks_p != (undefined4 *)0x0)) && ((code *)*_bt_rf_coex_hooks_p != (code *)0x0))
  {
    uVar3 = 3;
    if (*(char *)(_p_llm_env + 0xd7) != '\x02') {
      uVar3 = 1;
    }
    (*(code *)*_bt_rf_coex_hooks_p)(uVar1,uVar3,0);
  }
  return;
}

