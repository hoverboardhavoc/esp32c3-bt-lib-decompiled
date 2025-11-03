/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app -> hci.o -> r_hci_ble_conhdl_unregister
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_hci_ble_conhdl_unregister(uint param_1)

{
  code *pcVar1;
  int iVar2;
  
  iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  if (*(byte *)(iVar2 + 0xd) <= param_1) {
    pcVar1 = *(code **)(_r_plf_funcs_p + 0xc);
    iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
    (*pcVar1)(param_1,*(undefined1 *)(iVar2 + 0xd),"hci.c",0x4f5);
  }
  if ((&hci_rsvd_evt_msk)[param_1] == '\0') {
    (**(code **)(_r_plf_funcs_p + 8))(0,"hci.c",0x4f6,*(code **)(_r_plf_funcs_p + 8));
  }
  (&hci_rsvd_evt_msk)[param_1] = 0;
  return;
}

