/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app -> rf_coexist_hook.o -> bt_rf_coex_hook_register
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void bt_rf_coex_hook_register(void)

{
  undefined1 *puVar1;
  int iVar2;
  
  coex_hook_act_id_map = 0;
  s_ble_st_group_map = 0;
  DAT_00010500 = 0;
  DAT_00010504 = 0;
  puVar1 = &coex_hook_wifi_sleep_flag;
  iVar2 = 0;
  do {
    if (iVar2 == 0) {
      DAT_00010511 = 0;
    }
    else {
      puVar1[1] = 1;
    }
    *puVar1 = 0;
    iVar2 = iVar2 + 1;
    puVar1 = puVar1 + 2;
  } while (iVar2 != 9);
  _bt_rf_coex_hooks_p = &bt_rf_coex_hooks;
  return;
}

