/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> rf_coexist_hook.o -> coex_hook_check_wifi_sleep
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

char coex_hook_check_wifi_sleep(void)

{
  char cVar1;
  char *pcVar2;
  
  cVar1 = '\x01';
  if ((_LANCHOR0 - 1 & _LANCHOR0) == 0) {
    pcVar2 = &_LANCHOR1;
    do {
      if ((*pcVar2 == '\x01') && (pcVar2[1] != '\0')) {
        return pcVar2[1];
      }
      pcVar2 = pcVar2 + 2;
    } while (pcVar2 != (char *)0x1049e);
    cVar1 = '\0';
  }
  return cVar1;
}

