/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> vshci_task.o -> hci_vs_ble_qa_set_txpwr_lvl_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
hci_vs_ble_qa_set_txpwr_lvl_cmd_handler(undefined1 param_1,byte *param_2,undefined4 param_3)

{
  byte bVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  int iVar4;
  
  bVar1 = *param_2;
  uVar2 = 4;
  if (8 < bVar1) {
    uVar2 = 1;
    if (bVar1 != 9) {
      uVar2 = 2;
      if (bVar1 != 10) {
        uVar2 = 0;
        if (bVar1 != 0xb) {
          uVar2 = 5;
        }
      }
    }
  }
  puVar3 = (undefined1 *)r_ke_msg_alloc(0x1101,param_3,0xfd13,2);
  *puVar3 = 0;
  iVar4 = ble_txpwr_set(uVar2,0xffff,*(undefined4 *)(param_2 + 1));
  if (iVar4 != 0) {
    *puVar3 = 0x12;
  }
  puVar3[1] = param_1;
  r_hci_send_2_host(puVar3);
  return 0;
}

