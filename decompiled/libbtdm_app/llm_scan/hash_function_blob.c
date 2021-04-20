/*
 * Last changed at upstream commit 352d001fc7f5d34243047454b3f9e684577ce3e0
 * https://github.com/espressif/esp32c3-bt-lib/commit/352d001fc7f5d34243047454b3f9e684577ce3e0
 * Upstream date: 2021-04-20 15:58:00 +0800
 * Upstream subject: ESP32C3, ESP32S3: update libbtdm_app.a(47235b66)
 * Source: libbtdm_app -> llm_scan.o -> hash_function_blob
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint hash_function_blob(char *param_1,int param_2)

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
      *pcVar2 = ((byte)pcVar2[-1] >> 1 | *pcVar2 << 7) + *pcVar2;
      pcVar2 = pcVar3;
    } while ((char *)&uStack_4 != pcVar3);
    uStack_4 = (uint)(byte)((char)uStack_4 * -0x7f + *param_1);
  }
  return uStack_4;
}

