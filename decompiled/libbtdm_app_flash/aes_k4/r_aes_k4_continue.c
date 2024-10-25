/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> aes_k4.o -> r_aes_k4_continue
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int r_aes_k4_continue(int param_1,byte *param_2)

{
  int iVar1;
  void *pvVar2;
  
  iVar1 = r_aes_cmac_continue();
  if (iVar1 != 0) {
    if (*(char *)(param_1 + 0x34) == '\0') {
      *param_2 = *param_2 & 0x3f;
    }
    else {
      pvVar2 = memcpy((void *)(param_1 + 0x35),param_2,0x10);
      *(undefined1 *)(param_1 + 0x34) = 0;
      r_aes_cmac_start(param_1,pvVar2,&aes_k4_id6,4);
      iVar1 = 0;
    }
  }
  return iVar1;
}

