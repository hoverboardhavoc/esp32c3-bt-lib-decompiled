/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llm_hci.o -> hci_le_rd_peer_rslv_addr_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 hci_le_rd_peer_rslv_addr_cmd_handler(byte *param_1,undefined4 param_2)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  
  puVar2 = (undefined1 *)r_ke_msg_alloc(0x1101,0,param_2,7);
  *puVar2 = 0x12;
  if (*param_1 < 2) {
    uVar1 = r_lld_res_list_peer_rpa_get(param_1 + 1,puVar2 + 1);
    *puVar2 = uVar1;
  }
  r_hci_send_2_host(puVar2);
  return 0;
}

