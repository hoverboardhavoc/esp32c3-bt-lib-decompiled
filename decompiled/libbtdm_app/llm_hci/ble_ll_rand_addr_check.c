/*
 * Last changed at upstream commit e5c0f7256ecf5b5f8eb28c1793051a6b88f95124
 * https://github.com/espressif/esp32c3-bt-lib/commit/e5c0f7256ecf5b5f8eb28c1793051a6b88f95124
 * Upstream date: 2024-02-04 11:46:50 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(30b57c45)
 * Source: libbtdm_app -> llm_hci.o -> ble_ll_rand_addr_check
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool ble_ll_rand_addr_check(void)

{
  int iVar1;
  
  if (_p_llm_env != 0) {
    iVar1 = memcmp((void *)(_p_llm_env + 0x12),&co_null_bdaddr,6);
    return iVar1 != 0;
  }
  return false;
}

