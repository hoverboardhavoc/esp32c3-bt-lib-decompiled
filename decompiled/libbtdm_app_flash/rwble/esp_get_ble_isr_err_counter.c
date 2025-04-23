/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
    return DAT_000107fc;
  case 2:
    return DAT_00010800;
  case 3:
    return DAT_00010804;
  case 4:
    return DAT_00010808;
  case 5:
    return DAT_0001080c;
  case 6:
    return DAT_00010810;
  case 7:
    return DAT_00010814;
  case 8:
    return DAT_00010818;
  case 9:
    return DAT_0001081c;
  case 10:
    return DAT_00010820;
  case 0xb:
    return DAT_00010824;
  case 0xc:
    return DAT_00010828;
  case 0xd:
    return DAT_0001082c;
  case 0xe:
    return DAT_00010830;
  case 0xf:
    return DAT_00010834;
  case 0x10:
    return DAT_00010838;
  case 0x11:
    return DAT_0001083c;
  case 0x12:
    return DAT_00010840;
  case 0x13:
    return DAT_00010844;
  case 0x14:
    return DAT_00010848;
  case 0x15:
    return DAT_0001084c;
  case 0x16:
    return DAT_00010850;
  default:
    return 0;
  }
}

