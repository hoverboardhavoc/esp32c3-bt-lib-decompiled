/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_adv_start_hook
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 r_lld_adv_start_hook(int param_1,undefined4 param_2,int param_3)

{
  if (param_1 == 0) {
    r_lld_adv_start_hook_part_1(param_2,param_3);
  }
  else {
    llm_ext_adv_get_own_addr(param_2,*(undefined1 *)(param_3 + 0x1e),param_3);
  }
  return 0;
}

