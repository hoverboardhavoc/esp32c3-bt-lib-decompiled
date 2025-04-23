/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llm_hci.o -> hci_le_rd_tx_pwr_cmd_handler
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
  
  pbVar2 = (byte *)(**(code **)(_r_modules_funcs_p + 200))
                             (0x1101,0,0x204b,3,*(code **)(_r_modules_funcs_p + 200));
  iVar3 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  *pbVar2 = -(*(char *)(iVar3 + 0x18) == '\0') & 0xc;
  bVar1 = (*_lld_peer_rpa_to_id)(rw_rf_le_enter_test_mode,1,_lld_peer_rpa_to_id);
  pbVar2[1] = bVar1;
  bVar1 = (*_lld_peer_rpa_to_id)(DAT_00012049,1,_lld_peer_rpa_to_id);
  pbVar2[2] = bVar1;
  (**(code **)(_r_ip_funcs_p + 0x8c))(pbVar2,*(code **)(_r_ip_funcs_p + 0x8c));
  return 0;
}

