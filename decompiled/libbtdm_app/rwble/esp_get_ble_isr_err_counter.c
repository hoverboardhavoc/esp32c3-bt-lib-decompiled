/*
 * Last changed at upstream commit 4dd1838c81fc41eab863e284a53f029faab5372d
 * https://github.com/espressif/esp32c3-bt-lib/commit/4dd1838c81fc41eab863e284a53f029faab5372d
 * Upstream date: 2022-10-31 20:02:57 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(76c24c96)
 * Source: libbtdm_app -> rwble.o -> esp_get_ble_isr_err_counter
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_get_ble_isr_err_counter(undefined4 param_1)

{
  switch(param_1) {
  case 0:
    return _LANCHOR1;
  case 1:
    return DAT_000105e8;
  case 2:
    return DAT_000105ec;
  case 3:
    return DAT_000105f0;
  case 4:
    return DAT_000105f4;
  case 5:
    return DAT_000105f8;
  case 6:
    return DAT_000105fc;
  case 7:
    return DAT_00010600;
  case 8:
    return DAT_00010604;
  case 9:
    return DAT_00010608;
  case 10:
    return DAT_0001060c;
  case 0xb:
    return DAT_00010610;
  case 0xc:
    return DAT_00010614;
  case 0xd:
    return DAT_00010618;
  case 0xe:
    return DAT_0001061c;
  case 0xf:
    return DAT_00010620;
  case 0x10:
    return DAT_00010624;
  case 0x11:
    return DAT_00010628;
  case 0x12:
    return DAT_0001062c;
  case 0x13:
    return DAT_00010630;
  case 0x14:
    return DAT_00010634;
  case 0x15:
    return DAT_00010638;
  case 0x16:
    return DAT_0001063c;
  default:
    return 0;
  }
}

