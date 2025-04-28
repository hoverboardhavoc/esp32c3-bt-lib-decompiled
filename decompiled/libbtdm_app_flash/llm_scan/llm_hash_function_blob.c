/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
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
  undefined4 uStack_4;
  
  uStack_4 = 0;
  pcVar1 = param_1 + param_2;
  for (; pcVar1 != param_1; param_1 = param_1 + 1) {
    pcVar2 = (char *)((int)&uStack_4 + 3);
    do {
      pcVar3 = pcVar2 + -1;
      *pcVar2 = *pcVar2 + ((byte)pcVar2[-1] >> 1 | *pcVar2 << 7);
      pcVar2 = pcVar3;
    } while ((char *)&uStack_4 != pcVar3);
    uStack_4 = (uint)(byte)((char)uStack_4 * -0x7f + *param_1);
  }
  return uStack_4;
}

