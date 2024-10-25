/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llm_hci.o -> hci_le_rd_max_data_len_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 hci_le_rd_max_data_len_cmd_handler(undefined4 param_1)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)r_ke_msg_alloc(0x1101,0,param_1,10);
  *(undefined2 *)(puVar1 + 6) = 0xfb;
  *(undefined2 *)(puVar1 + 8) = 0x4290;
  *(undefined2 *)(puVar1 + 2) = 0xfb;
  *(undefined2 *)(puVar1 + 4) = 0x4290;
  *puVar1 = 0;
  r_hci_send_2_host();
  return 0;
}

