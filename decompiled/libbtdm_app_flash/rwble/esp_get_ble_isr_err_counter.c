/*
 * Last changed at upstream commit e668c2d101ee46ee1950819607694fb852aecae0
 * https://github.com/espressif/esp32c3-bt-lib/commit/e668c2d101ee46ee1950819607694fb852aecae0
 * Upstream date: 2025-03-14 11:07:43 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(6e312587)
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
    return DAT_000106ac;
  case 2:
    return DAT_000106b0;
  case 3:
    return DAT_000106b4;
  case 4:
    return DAT_000106b8;
  case 5:
    return DAT_000106bc;
  case 6:
    return DAT_000106c0;
  case 7:
    return DAT_000106c4;
  case 8:
    return DAT_000106c8;
  case 9:
    return DAT_000106cc;
  case 10:
    return DAT_000106d0;
  case 0xb:
    return DAT_000106d4;
  case 0xc:
    return DAT_000106d8;
  case 0xd:
    return DAT_000106dc;
  case 0xe:
    return DAT_000106e0;
  case 0xf:
    return DAT_000106e4;
  case 0x10:
    return DAT_000106e8;
  case 0x11:
    return DAT_000106ec;
  case 0x12:
    return DAT_000106f0;
  case 0x13:
    return DAT_000106f4;
  case 0x14:
    return DAT_000106f8;
  case 0x15:
    return DAT_000106fc;
  case 0x16:
    return DAT_00010700;
  default:
    return 0;
  }
}

