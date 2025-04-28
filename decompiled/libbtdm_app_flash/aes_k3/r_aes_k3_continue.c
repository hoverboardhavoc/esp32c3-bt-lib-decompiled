/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> aes_k3.o -> r_aes_k3_continue
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int r_aes_k3_continue(int param_1,void *param_2)

{
  int iVar1;
  void *pvVar2;
  
  iVar1 = r_aes_cmac_continue();
  if ((iVar1 != 0) && (*(char *)(param_1 + 0x34) != '\0')) {
    pvVar2 = memcpy((void *)(param_1 + 0x35),param_2,0x10);
    *(undefined1 *)(param_1 + 0x34) = 0;
    r_aes_cmac_start(param_1,pvVar2,&aes_k3_id64,5);
    iVar1 = 0;
  }
  return iVar1;
}

