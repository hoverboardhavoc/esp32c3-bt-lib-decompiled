/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> hci_tl.o -> r_hci_tl_save_pkt
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_hci_tl_save_pkt(void *param_1,size_t param_2)

{
  if (_DAT_00012030 == (void *)0x0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"hci_tl.c",0x597,*(code **)(_r_plf_funcs_p + 8));
  }
  memcpy(_DAT_00012030,param_1,param_2);
  return;
}

