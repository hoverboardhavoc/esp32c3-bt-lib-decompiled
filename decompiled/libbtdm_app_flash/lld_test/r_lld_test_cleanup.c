/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
 * Source: libbtdm_app_flash -> lld_test.o -> r_lld_test_cleanup
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_test_cleanup(int param_1)

{
  int iVar1;
  
  iVar1 = _lld_test_env;
  if (_lld_test_env != 0) {
    r_ble_log_internal_x1(0x4006013b,(uint)*(byte *)(_lld_test_env + 0x26) | param_1 << 8);
    if (*(char *)(iVar1 + 0x26) == '\x01') {
      if (param_1 == 0) {
        r_ble_util_buf_acl_tx_free(*(undefined2 *)(iVar1 + 0x24));
      }
      else {
        r_ble_util_buf_acl_tx_free_in_isr();
      }
    }
    r_ke_free(_lld_test_env);
    _lld_test_env = 0;
  }
  return;
}

