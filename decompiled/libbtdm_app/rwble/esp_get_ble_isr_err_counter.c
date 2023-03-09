/*
 * Last changed at upstream commit 5c6ab5248a124cffc731a9e4764473fdeef38054
 * https://github.com/espressif/esp32c3-bt-lib/commit/5c6ab5248a124cffc731a9e4764473fdeef38054
 * Upstream date: 2023-03-09 14:58:19 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(85a1090)
 * Source: libbtdm_app -> rwble.o -> esp_get_ble_isr_err_counter
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 esp_get_ble_isr_err_counter(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = (undefined4 *)(**(code **)(_r_ip_funcs_p + 0x918))(*(code **)(_r_ip_funcs_p + 0x918));
  switch(param_1) {
  case 0:
    uVar2 = *puVar1;
    break;
  case 1:
    uVar2 = puVar1[1];
    break;
  case 2:
    uVar2 = puVar1[2];
    break;
  case 3:
    uVar2 = puVar1[3];
    break;
  case 4:
    uVar2 = puVar1[4];
    break;
  case 5:
    uVar2 = puVar1[5];
    break;
  case 6:
    uVar2 = puVar1[6];
    break;
  case 7:
    uVar2 = puVar1[7];
    break;
  case 8:
    uVar2 = puVar1[8];
    break;
  case 9:
    uVar2 = puVar1[9];
    break;
  case 10:
    uVar2 = puVar1[10];
    break;
  case 0xb:
    uVar2 = puVar1[0xb];
    break;
  case 0xc:
    uVar2 = puVar1[0xc];
    break;
  case 0xd:
    uVar2 = puVar1[0xd];
    break;
  case 0xe:
    uVar2 = puVar1[0xe];
    break;
  case 0xf:
    uVar2 = puVar1[0xf];
    break;
  case 0x10:
    uVar2 = puVar1[0x10];
    break;
  case 0x11:
    uVar2 = puVar1[0x11];
    break;
  case 0x12:
    uVar2 = puVar1[0x12];
    break;
  case 0x13:
    uVar2 = puVar1[0x13];
    break;
  case 0x14:
    uVar2 = puVar1[0x14];
    break;
  case 0x15:
    uVar2 = puVar1[0x15];
    break;
  case 0x16:
    uVar2 = puVar1[0x16];
    break;
  default:
    uVar2 = 0;
  }
  return uVar2;
}

