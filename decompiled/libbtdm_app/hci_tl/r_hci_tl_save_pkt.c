/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
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
    (**(code **)(_r_plf_funcs_p + 8))(0,"hci_tl.c",0x598,*(code **)(_r_plf_funcs_p + 8));
  }
  memcpy(_DAT_00012030,param_1,param_2);
  return;
}

