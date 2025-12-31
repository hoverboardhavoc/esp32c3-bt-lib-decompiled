/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
 * Source: libbtdm_app_flash -> llm_adv.o -> lld_per_adv_end_ind_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 lld_per_adv_end_ind_handler(byte *param_1)

{
  byte bVar1;
  
  if (*(char *)(*(int *)(_p_llm_env + 8) + (uint)*param_1 * 0x44 + 0x40) == '\r') {
    r_llm_cmd_cmp_send(0x2040,0);
    bVar1 = *param_1;
    *(undefined1 *)(*(int *)(_p_llm_env + 8) + (uint)bVar1 * 0x44 + 0x40) = 10;
    r_ble_log_internal_x1(0x404e019a,bVar1 | 0xa00);
  }
  return 0;
}

