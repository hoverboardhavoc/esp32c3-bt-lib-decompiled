/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> llm_scan.o -> llm_scan_check_mesh_adv_data
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 llm_scan_check_mesh_adv_data(byte *param_1,int param_2)

{
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  byte *pbVar4;
  
  bVar1 = *param_1;
  pbVar3 = param_1 + 1;
  while( true ) {
    uVar2 = (uint)bVar1;
    if ((uVar2 == 0) || (param_2 < (int)pbVar3 - (int)param_1)) {
      return 0;
    }
    bVar1 = *pbVar3;
    pbVar4 = pbVar3 + 1;
    if ((bVar1 == 0x24) || ((byte)(bVar1 - 0x29) < 3)) break;
    if ((uVar2 == 3) && (bVar1 == 3)) {
      pbVar4 = pbVar3 + 3;
      if ((ushort)(*(short *)(pbVar3 + 1) + 0xe7d9U) < 2) {
        return 1;
      }
      if (*(short *)(pbVar3 + 1) == 0x1859) {
        return 1;
      }
    }
    pbVar3 = pbVar4 + uVar2;
    bVar1 = pbVar3[-1];
  }
  return 1;
}

