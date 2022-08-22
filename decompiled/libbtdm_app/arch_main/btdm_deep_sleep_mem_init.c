/*
 * Last changed at upstream commit 068bceb41f08099d1e831f6c7ef8153ec7a344ca
 * https://github.com/espressif/esp32c3-bt-lib/commit/068bceb41f08099d1e831f6c7ef8153ec7a344ca
 * Upstream date: 2022-08-22 15:06:11 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(3a49744)
 * Source: libbtdm_app -> arch_main.o -> btdm_deep_sleep_mem_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 btdm_deep_sleep_mem_init(void)

{
  _LANCHOR1 = (**(code **)(_r_osi_funcs_p + 0x74))(0x44c,*(code **)(_r_osi_funcs_p + 0x74));
  if (((_LANCHOR1 != 0) &&
      (_LANCHOR2 = (**(code **)(_r_osi_funcs_p + 0x74))(300,*(code **)(_r_osi_funcs_p + 0x74)),
      _LANCHOR2 != 0)) &&
     (_LANCHOR3 = (**(code **)(_r_osi_funcs_p + 0x74))(0xb4,*(code **)(_r_osi_funcs_p + 0x74)),
     _LANCHOR3 != 0)) {
    return 1;
  }
  btdm_deep_sleep_mem_deinit();
  return 0;
}

