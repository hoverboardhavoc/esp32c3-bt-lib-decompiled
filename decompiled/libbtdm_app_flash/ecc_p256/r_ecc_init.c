/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> ecc_p256.o -> r_ecc_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_ecc_init(int param_1)

{
  int iVar1;
  
  if (param_1 != 1) {
    if (param_1 != 2) {
      if (param_1 != 0) {
        return;
      }
      r_ke_event_callback_set(r_ecc_multiplication_event_handler);
      return;
    }
    r_ke_event_clear();
    while (_ecc_env != 0) {
      iVar1 = r_co_list_pop_front(&ecc_env);
      if (*(int *)(iVar1 + 0x148) != 0) {
        r_ke_free();
      }
      r_ke_free(iVar1);
    }
  }
  r_co_list_init(&ecc_env);
  return;
}

