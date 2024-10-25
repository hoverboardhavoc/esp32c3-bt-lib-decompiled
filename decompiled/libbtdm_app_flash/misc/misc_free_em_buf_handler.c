/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> misc.o -> misc_free_em_buf_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 misc_free_em_buf_handler(char *param_1)

{
  if (*param_1 == '\0') {
    r_ble_util_buf_acl_tx_free(*(undefined2 *)(param_1 + 2));
  }
  else if (*param_1 == '\x01') {
    r_ble_util_buf_adv_tx_free(*(undefined2 *)(param_1 + 2));
  }
  return 0;
}

