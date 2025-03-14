/*
 * Last changed at upstream commit e668c2d101ee46ee1950819607694fb852aecae0
 * https://github.com/espressif/esp32c3-bt-lib/commit/e668c2d101ee46ee1950819607694fb852aecae0
 * Upstream date: 2025-03-14 11:07:43 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(6e312587)
 * Source: libbtdm_app_flash -> lld_sync.o -> r_lld_sync_cleanup
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_sync_cleanup(int param_1,undefined1 param_2)

{
  int *piVar1;
  undefined1 *puVar2;
  
  piVar1 = (int *)(&lld_sync_env + param_1 * 4);
  if (*piVar1 != 0) {
    puVar2 = (undefined1 *)r_ke_msg_alloc(0x205,0,0xff,2);
    *puVar2 = (char)param_1;
    puVar2[1] = param_2;
    r_ke_msg_send();
    r_ke_free(*piVar1);
    *piVar1 = 0;
  }
  return;
}

