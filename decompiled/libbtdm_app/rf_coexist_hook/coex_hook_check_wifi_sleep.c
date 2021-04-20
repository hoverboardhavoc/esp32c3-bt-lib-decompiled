/*
 * Last changed at upstream commit 352d001fc7f5d34243047454b3f9e684577ce3e0
 * https://github.com/espressif/esp32c3-bt-lib/commit/352d001fc7f5d34243047454b3f9e684577ce3e0
 * Upstream date: 2021-04-20 15:58:00 +0800
 * Upstream subject: ESP32C3, ESP32S3: update libbtdm_app.a(47235b66)
 * Source: libbtdm_app -> rf_coexist_hook.o -> coex_hook_check_wifi_sleep
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
    } while (pcVar2 != (char *)0x1043e);
    cVar1 = '\0';
  }
  return cVar1;
}

