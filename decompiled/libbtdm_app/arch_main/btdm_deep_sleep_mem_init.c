/*
 * Last changed at upstream commit 5c6ab5248a124cffc731a9e4764473fdeef38054
 * https://github.com/espressif/esp32c3-bt-lib/commit/5c6ab5248a124cffc731a9e4764473fdeef38054
 * Upstream date: 2023-03-09 14:58:19 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(85a1090)
 * Source: libbtdm_app -> arch_main.o -> btdm_deep_sleep_mem_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 btdm_deep_sleep_mem_init(void)

{
  _LANCHOR2 = (**(code **)(_r_osi_funcs_p + 0x74))(0x44c,*(code **)(_r_osi_funcs_p + 0x74));
  if (((_LANCHOR2 != 0) &&
      (_LANCHOR3 = (**(code **)(_r_osi_funcs_p + 0x74))(300,*(code **)(_r_osi_funcs_p + 0x74)),
      _LANCHOR3 != 0)) &&
     (_LANCHOR4 = (**(code **)(_r_osi_funcs_p + 0x74))(0xb4,*(code **)(_r_osi_funcs_p + 0x74)),
     _LANCHOR4 != 0)) {
    return 1;
  }
  btdm_deep_sleep_mem_deinit();
  return 0;
}

