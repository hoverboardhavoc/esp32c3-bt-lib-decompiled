/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llm_scan.o -> llm_scan_check_mesh_adv_data
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 llm_scan_check_mesh_adv_data(char *param_1,int param_2)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  
  cVar1 = *param_1;
  pcVar2 = param_1 + 1;
  do {
    if ((cVar1 == '\0') || (param_2 < (int)pcVar2 - (int)param_1)) {
      return 0;
    }
    cVar1 = *pcVar2;
    if (cVar1 == '$') {
      return 1;
    }
    if (cVar1 == '\x03') {
      pcVar3 = pcVar2 + 3;
      if ((ushort)(*(short *)(pcVar2 + 1) + 0xe7d9U) < 2) {
        return 1;
      }
      if (*(short *)(pcVar2 + 1) == 0x1859) {
        return 1;
      }
    }
    else {
      if ((byte)(cVar1 - 0x29U) < 3) {
        return 1;
      }
      pcVar3 = pcVar2 + 1;
    }
    cVar1 = pcVar3[2];
    pcVar2 = pcVar3 + 3;
  } while( true );
}

