/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llm_hci.o -> hci_host_buf_size_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 hci_host_buf_size_cmd_handler(undefined2 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = r_hci_fc_acl_buf_size_set(*param_1,param_1[2]);
  r_llm_cmd_cmp_send(param_2,uVar1);
  return 0;
}

