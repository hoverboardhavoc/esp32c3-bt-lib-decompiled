/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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
  r_rwip_prevent_sleep_clear(4);
  return;
}

