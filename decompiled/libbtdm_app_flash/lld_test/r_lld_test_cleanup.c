/*
 * Last changed at upstream commit daab5dbba958a13041bd496e4a6ed506c9284a06
 * https://github.com/espressif/esp32c3-bt-lib/commit/daab5dbba958a13041bd496e4a6ed506c9284a06
 * Upstream date: 2025-03-20 20:43:40 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(86a4da5c)
 * Source: libbtdm_app_flash -> lld_test.o -> r_lld_test_cleanup
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_test_cleanup(uint param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = _lld_test_env;
  if (_lld_test_env != 0) {
    iVar2 = r_sdk_config_get_opts_ext();
    if ((*(uint *)(iVar2 + 0x28) & 0x400) != 0) {
      iVar2 = r_sdk_config_get_opts_ext();
      if (*(byte *)(iVar2 + 0x2c) < 3) {
        r_ble_log_internal_x1(0x400e0003,(uint)*(byte *)(iVar1 + 0x26) << 8 | param_1);
      }
    }
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

