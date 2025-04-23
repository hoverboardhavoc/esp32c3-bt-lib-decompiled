/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llm_scan.o -> llm_scan_check_mesh_adv_data
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 llm_scan_check_mesh_adv_data(byte *param_1,int param_2)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  
  bVar1 = *param_1;
  pbVar2 = param_1 + 1;
  do {
    if ((bVar1 == 0) || (param_2 < (int)pbVar2 - (int)param_1)) {
      return 0;
    }
    bVar1 = *pbVar2;
    if (bVar1 == 0x24) {
      return 1;
    }
    if (bVar1 < 0x25) {
      if (bVar1 != 3) goto _L214;
      pbVar3 = pbVar2 + 3;
      if (((ushort)(*(short *)(pbVar2 + 1) + 0xe7d9U) < 2) || (*(short *)(pbVar2 + 1) == 0x1859)) {
        return 1;
      }
    }
    else {
      if ((byte)(bVar1 - 0x29) < 3) {
        return 1;
      }
_L214:
      pbVar3 = pbVar2 + 1;
    }
    bVar1 = pbVar3[2];
    pbVar2 = pbVar3 + 3;
  } while( true );
}

