/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> vshci_task.o -> hci_vs_ble_qa_get_txpwr_lvl_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
hci_vs_ble_qa_get_txpwr_lvl_cmd_handler(undefined1 param_1,byte *param_2,undefined4 param_3)

{
  byte bVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  undefined1 uVar5;
  
  bVar1 = *param_2;
  iVar2 = 4;
  if ((((8 < bVar1) && (iVar2 = 1, bVar1 != 9)) && (iVar2 = 2, bVar1 != 10)) &&
     (iVar2 = 0, bVar1 != 0xb)) {
    iVar2 = 5;
  }
  puVar3 = (undefined1 *)r_ke_msg_alloc(0x1101,param_3,0xfd13,6);
  uVar5 = 0x12;
  if (iVar2 != 5) {
    uVar5 = 0;
  }
  *puVar3 = uVar5;
  puVar3[1] = param_1;
  uVar4 = ble_txpwr_get(iVar2,0xffff);
  puVar3[2] = (char)uVar4;
  puVar3[3] = (char)((uint)uVar4 >> 8);
  puVar3[5] = (char)((uint)uVar4 >> 0x18);
  puVar3[4] = (char)((uint)uVar4 >> 0x10);
  r_hci_send_2_host(puVar3);
  return 0;
}

