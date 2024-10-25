/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> vshci_task.o -> hci_vendor_ble_clear_adv_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 hci_vendor_ble_clear_adv_cmd_handler(undefined4 param_1)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  
  uVar1 = llm_clear_adv();
  puVar2 = (undefined1 *)r_ke_msg_alloc(0x1101,param_1,0xfd0c,1);
  *puVar2 = uVar1;
  r_hci_send_2_host();
  return 0;
}

