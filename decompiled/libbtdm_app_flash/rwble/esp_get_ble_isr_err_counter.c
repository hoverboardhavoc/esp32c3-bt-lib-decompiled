/*
 * Last changed at upstream commit d2414a5dd958b32ca53382b441d24d97a0345a55
 * https://github.com/espressif/esp32c3-bt-lib/commit/d2414a5dd958b32ca53382b441d24d97a0345a55
 * Upstream date: 2025-03-20 20:11:19 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(03d0f8a6)
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
    return DAT_00010764;
  case 2:
    return DAT_00010768;
  case 3:
    return DAT_0001076c;
  case 4:
    return DAT_00010770;
  case 5:
    return DAT_00010774;
  case 6:
    return DAT_00010778;
  case 7:
    return DAT_0001077c;
  case 8:
    return DAT_00010780;
  case 9:
    return DAT_00010784;
  case 10:
    return DAT_00010788;
  case 0xb:
    return DAT_0001078c;
  case 0xc:
    return DAT_00010790;
  case 0xd:
    return DAT_00010794;
  case 0xe:
    return DAT_00010798;
  case 0xf:
    return DAT_0001079c;
  case 0x10:
    return DAT_000107a0;
  case 0x11:
    return DAT_000107a4;
  case 0x12:
    return DAT_000107a8;
  case 0x13:
    return DAT_000107ac;
  case 0x14:
    return DAT_000107b0;
  case 0x15:
    return DAT_000107b4;
  case 0x16:
    return DAT_000107b8;
  default:
    return 0;
  }
}

