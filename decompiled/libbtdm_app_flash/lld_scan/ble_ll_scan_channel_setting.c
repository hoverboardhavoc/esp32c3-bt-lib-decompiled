/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> lld_scan.o -> ble_ll_scan_channel_setting
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ble_ll_scan_channel_setting(uint param_1)

{
  int iVar1;
  
  iVar1 = r_ble_ll_qa_config_get();
  if (param_1 != 0) {
    param_1 = (uint)*(byte *)(param_1 + 0x149ef);
  }
  *(short *)(iVar1 + 0x18) = (short)param_1;
  return;
}

