/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> hci_fc.o -> r_hci_fc_host_nb_acl_pkts_complete
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_hci_fc_host_nb_acl_pkts_complete(uint param_1)

{
  if (param_1 < _DAT_00011006) {
    _DAT_00011006 = _DAT_00011006 - (short)param_1;
    return;
  }
  _DAT_00011006 = 0;
  return;
}

