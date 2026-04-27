/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
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
    r_ble_log_internal_x1(0x40060166,(uint)*(byte *)(_lld_test_env + 0x26) | param_1 << 8);
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

