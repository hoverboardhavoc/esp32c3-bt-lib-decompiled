/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> hci_fc.o -> r_hci_fc_host_nb_acl_pkts_complete
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_hci_fc_host_nb_acl_pkts_complete(uint param_1)

{
  short sVar1;
  
  sVar1 = 0;
  if (param_1 < _DAT_00011006) {
    sVar1 = _DAT_00011006 - (short)param_1;
  }
  _DAT_00011006 = sVar1;
  return;
}

