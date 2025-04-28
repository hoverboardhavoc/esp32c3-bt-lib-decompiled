/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> rf_espressif.o -> r_rf_em_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_rf_em_init(void)

{
  void *__dest;
  char *pcVar1;
  char cVar2;
  char local_38 [48];
  
  cVar2 = '\0';
  pcVar1 = local_38;
  do {
    *pcVar1 = cVar2;
    cVar2 = cVar2 + '\x02';
    pcVar1 = pcVar1 + 1;
  } while (cVar2 != 'P');
  if (2 < _g_bt_plf_log_level) {
    ets_printf("write freq table, offset %04x\n",0x100);
  }
  __dest = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))(0x100,*(code **)(_r_plf_funcs_p + 0xbc));
  memcpy(__dest,local_38,0x28);
  return;
}

