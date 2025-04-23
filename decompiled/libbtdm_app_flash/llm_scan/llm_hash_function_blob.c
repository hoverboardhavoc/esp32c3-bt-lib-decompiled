/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llm_scan.o -> llm_hash_function_blob
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint llm_hash_function_blob(char *param_1,int param_2)

{
  char *pcVar1;
  char *pcVar2;
  char *pcVar3;
  byte bVar4;
  undefined4 uStack_4;
  
  uStack_4 = 0;
  pcVar1 = param_1 + param_2;
  bVar4 = 0;
  for (; param_1 != pcVar1; param_1 = param_1 + 1) {
    pcVar2 = (char *)((int)&uStack_4 + 3);
    do {
      pcVar3 = pcVar2 + -1;
      *pcVar2 = *pcVar2 + ((byte)pcVar2[-1] >> 1 | *pcVar2 << 7);
      pcVar2 = pcVar3;
    } while ((char *)&uStack_4 != pcVar3);
    bVar4 = bVar4 * -0x7f + *param_1;
    uStack_4 = (uint)bVar4;
  }
  return uStack_4;
}

