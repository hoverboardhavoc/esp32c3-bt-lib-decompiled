/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
    } while ((ushort *)pcVar2 != &coex_hook_act_id_map);
    cVar1 = '\0';
  }
  return cVar1;
}

