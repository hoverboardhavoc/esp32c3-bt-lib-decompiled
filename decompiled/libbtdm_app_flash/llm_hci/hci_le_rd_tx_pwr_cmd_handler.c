/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llm_hci.o -> hci_le_rd_tx_pwr_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_rd_tx_pwr_cmd_handler(void)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  
  pbVar2 = (byte *)r_ke_msg_alloc(0x1101,0,0x204b,3);
  iVar3 = r_sdk_config_get_opts_ext();
  *pbVar2 = -(*(char *)(iVar3 + 0x18) == '\0') & 0xc;
  bVar1 = (*_r_lld_res_list_peer_rpa_get)(r_co_bdaddr_compare,1,_r_lld_res_list_peer_rpa_get);
  pbVar2[1] = bVar1;
  bVar1 = (*_r_lld_res_list_peer_rpa_get)(DAT_00012049,1,_r_lld_res_list_peer_rpa_get);
  pbVar2[2] = bVar1;
  r_hci_send_2_host(pbVar2);
  return 0;
}

