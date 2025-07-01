/*
 * Last changed at upstream commit 0c68809d62e432427de97b5294f6619307f62f40
 * https://github.com/espressif/esp32c3-bt-lib/commit/0c68809d62e432427de97b5294f6619307f62f40
 * Upstream date: 2025-07-01 15:07:54 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2edb0b0)
 * Source: libbtdm_app_flash -> h4tl.o -> r_h4tl_out_of_sync
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_h4tl_out_of_sync(int param_1)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)r_ke_msg_alloc(0x1103,0,0x10,1);
  *puVar1 = 0;
  r_hci_send_2_host();
  memset((void *)(param_1 + 10),0,8);
  *(undefined1 *)(param_1 + 0x12) = *(undefined1 *)(param_1 + 0x13);
  r_h4tl_read_next_out_of_sync(param_1);
  r_rwip_prevent_sleep_clear_hack(4);
  return;
}

