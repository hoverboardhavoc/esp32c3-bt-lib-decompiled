/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> rf_coexist_hook.o -> coex_hook_check_coex_schm_st
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 coex_hook_check_coex_schm_st(uint param_1)

{
  int iVar1;
  short *psVar2;
  
  psVar2 = (short *)&s_ble_st_group_map;
  iVar1 = 0;
  while (((byte)(&coex_hook_st_group_to_coex_schm_st_tab)[iVar1] != param_1 || (*psVar2 == 0))) {
    iVar1 = iVar1 + 1;
    psVar2 = psVar2 + 1;
    if (iVar1 == 5) {
      return 0;
    }
  }
  return 1;
}

