/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> ble_log.o -> r_ble_log_hex2str
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

byte * r_ble_log_hex2str(byte *param_1,uint param_2)

{
  byte *pbVar1;
  byte *pbVar2;
  char *pcVar3;
  
  if (param_1 != (byte *)0x0) {
    if (param_2 != 0) {
      if (0x81 < param_2) {
        param_2 = 0x81;
      }
      pbVar1 = param_1;
      pcVar3 = &str_0;
      do {
        pbVar2 = pbVar1 + 1;
        *pcVar3 = "0123456789abcdef"[*pbVar1 >> 4];
        pcVar3[1] = "0123456789abcdef"[*pbVar1 & 0xf];
        pbVar1 = pbVar2;
        pcVar3 = pcVar3 + 2;
      } while (pbVar2 != param_1 + param_2);
      (&str_0)[param_2 * 2] = 0;
      return &str_0;
    }
    param_1 = (byte *)0x0;
  }
  return param_1;
}

