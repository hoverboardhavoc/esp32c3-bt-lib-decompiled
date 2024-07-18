/*
 * Last changed at upstream commit bfdfe8f851c99ced8316b133b0b15521917ea049
 * https://github.com/espressif/esp32c3-bt-lib/commit/bfdfe8f851c99ced8316b133b0b15521917ea049
 * Upstream date: 2024-07-18 14:51:28 +0800
 * Upstream subject: feat(bt): Support mesh duplicate with extend scan (aa16a46)
 * Source: libbtdm_app -> llm_scan.o -> llm_scan_check_mesh_adv_data
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
  while( true ) {
    if ((cVar1 == '\0') || (param_2 < (int)pcVar2 - (int)param_1)) {
      return 0;
    }
    cVar1 = *pcVar2;
    if ((cVar1 == '$') || ((byte)(cVar1 - 0x29U) < 3)) break;
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
      pcVar3 = pcVar2 + 1;
    }
    cVar1 = pcVar3[2];
    pcVar2 = pcVar3 + 3;
  }
  return 1;
}

