/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
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
  if ((coex_hook_act_id_map - 1 & coex_hook_act_id_map) == 0) {
    pcVar2 = &coex_hook_wifi_sleep_flag;
    do {
      if ((*pcVar2 == '\x01') && (pcVar2[1] != '\0')) {
        return pcVar2[1];
      }
      pcVar2 = pcVar2 + 2;
    } while (pcVar2 != (char *)0x10522);
    cVar1 = '\0';
  }
  return cVar1;
}

