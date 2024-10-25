/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llc_hci.o -> hci_rd_rssi_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 hci_rd_rssi_cmd_handler(uint param_1,undefined2 *param_2)

{
  char cVar1;
  undefined1 *puVar2;
  int iVar3;
  
  puVar2 = (undefined1 *)r_ke_msg_alloc(0x1101,*param_2,0x1405,6);
  iVar3 = r_sdk_config_get_opts();
  if (((param_1 < *(byte *)(iVar3 + 0xd)) && (*(int *)(&llc_env + param_1 * 4) != 0)) &&
     ((*(byte *)(*(int *)(&llc_env + param_1 * 4) + 0x44) & 3) != 3)) {
    *puVar2 = 0;
    cVar1 = r_lld_con_rssi_get(param_1);
    iVar3 = r_llm_rx_path_comp_get();
    puVar2[4] = (char)(iVar3 / 10) + cVar1;
  }
  else {
    *puVar2 = 0xc;
    puVar2[4] = 0;
  }
  *(undefined2 *)(puVar2 + 2) = *param_2;
  r_hci_send_2_host(puVar2);
  return 0;
}

