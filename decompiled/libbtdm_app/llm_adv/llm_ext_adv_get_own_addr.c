/*
 * Last changed at upstream commit 27af69ccbb02f3b820436f47eaa0b1cd544edfbc
 * https://github.com/espressif/esp32c3-bt-lib/commit/27af69ccbb02f3b820436f47eaa0b1cd544edfbc
 * Upstream date: 2023-09-26 16:09:19 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(c8aa206)
 * Source: libbtdm_app -> llm_adv.o -> llm_ext_adv_get_own_addr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void llm_ext_adv_get_own_addr(int param_1,uint param_2,void *param_3)

{
  void *__src;
  
  if (*(char *)(_p_llm_env + 0xd7) != '\x01') {
    __src = (void *)(_p_llm_env + 0xc);
    if ((param_2 & 1) != 0) {
      __src = (void *)(*(int *)(_p_llm_env + 8) + param_1 * 0x44 + 4);
    }
    memcpy(param_3,__src,6);
    return;
  }
  return;
}

