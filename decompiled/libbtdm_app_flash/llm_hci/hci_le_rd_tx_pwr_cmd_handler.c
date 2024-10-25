/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llm_hci.o -> hci_le_rd_tx_pwr_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_rd_tx_pwr_cmd_handler(void)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  int iVar3;
  
  puVar2 = (undefined1 *)r_ke_msg_alloc(0x1101,0,0x204b,3);
  iVar3 = r_sdk_config_get_opts_ext();
  uVar1 = 0xc;
  if (*(char *)(iVar3 + 0x18) != '\0') {
    uVar1 = 0;
  }
  *puVar2 = uVar1;
  uVar1 = (*_r_lld_res_list_peer_rpa_get)(r_hci_evt_mask_set,1,_r_lld_res_list_peer_rpa_get);
  puVar2[1] = uVar1;
  uVar1 = (*_r_lld_res_list_peer_rpa_get)(DAT_00012045,1,_r_lld_res_list_peer_rpa_get);
  puVar2[2] = uVar1;
  r_hci_send_2_host(puVar2);
  return 0;
}

