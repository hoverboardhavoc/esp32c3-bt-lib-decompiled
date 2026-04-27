/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
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
    r_ble_log_internal_x1(0x404e01c5,bVar1 | 0xa00);
  }
  return 0;
}

