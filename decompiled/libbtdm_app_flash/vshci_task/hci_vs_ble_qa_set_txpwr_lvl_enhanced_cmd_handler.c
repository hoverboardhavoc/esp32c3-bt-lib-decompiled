/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> vshci_task.o -> hci_vs_ble_qa_set_txpwr_lvl_enhanced_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
hci_vs_ble_qa_set_txpwr_lvl_enhanced_cmd_handler
          (undefined1 param_1,undefined1 *param_2,undefined4 param_3)

{
  undefined1 *puVar1;
  int iVar2;
  
  puVar1 = (undefined1 *)r_ke_msg_alloc(0x1101,param_3,0xfd13,2);
  *puVar1 = 0;
  iVar2 = ble_txpwr_set(*param_2,*(undefined2 *)(param_2 + 5),*(undefined4 *)(param_2 + 1));
  if (iVar2 != 0) {
    *puVar1 = 0x12;
  }
  puVar1[1] = param_1;
  r_hci_send_2_host(puVar1);
  return 0;
}

