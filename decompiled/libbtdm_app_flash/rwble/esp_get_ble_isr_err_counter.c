/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> rwble.o -> esp_get_ble_isr_err_counter
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_get_ble_isr_err_counter(undefined4 param_1)

{
  switch(param_1) {
  case 0:
    return ble_isr_state;
  case 1:
    return DAT_00010738;
  case 2:
    return DAT_0001073c;
  case 3:
    return DAT_00010740;
  case 4:
    return DAT_00010744;
  case 5:
    return DAT_00010748;
  case 6:
    return DAT_0001074c;
  case 7:
    return DAT_00010750;
  case 8:
    return DAT_00010754;
  case 9:
    return DAT_00010758;
  case 10:
    return DAT_0001075c;
  case 0xb:
    return DAT_00010760;
  case 0xc:
    return DAT_00010764;
  case 0xd:
    return DAT_00010768;
  case 0xe:
    return DAT_0001076c;
  case 0xf:
    return DAT_00010770;
  case 0x10:
    return DAT_00010774;
  case 0x11:
    return DAT_00010778;
  case 0x12:
    return DAT_0001077c;
  case 0x13:
    return DAT_00010780;
  case 0x14:
    return DAT_00010784;
  case 0x15:
    return DAT_00010788;
  case 0x16:
    return DAT_0001078c;
  default:
    return 0;
  }
}

