/*
 * Last changed at upstream commit 27af69ccbb02f3b820436f47eaa0b1cd544edfbc
 * https://github.com/espressif/esp32c3-bt-lib/commit/27af69ccbb02f3b820436f47eaa0b1cd544edfbc
 * Upstream date: 2023-09-26 16:09:19 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(c8aa206)
 * Source: libbtdm_app -> lld_scan.o -> ble_ll_scan_channel_setting
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ble_ll_scan_channel_setting(uint param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(_r_ip_funcs_p + 0x914))(*(code **)(_r_ip_funcs_p + 0x914));
  if (param_1 != 0) {
    param_1 = (uint)*(byte *)(param_1 + 0x10a77);
  }
  *(short *)(iVar1 + 0x18) = (short)param_1;
  return;
}

