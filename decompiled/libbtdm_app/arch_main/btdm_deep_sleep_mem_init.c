/*
 * Last changed at upstream commit ebd6043a8e3c3bbde45ee483895303b9c1229ab5
 * https://github.com/espressif/esp32c3-bt-lib/commit/ebd6043a8e3c3bbde45ee483895303b9c1229ab5
 * Upstream date: 2026-02-06 15:59:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(b7de11e)
 * Source: libbtdm_app -> arch_main.o -> btdm_deep_sleep_mem_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 btdm_deep_sleep_mem_init(void)

{
  lc_mem_addr = (**(code **)(_r_osi_funcs_p + 0xe0))(0x44c,*(code **)(_r_osi_funcs_p + 0xe0));
  if (((lc_mem_addr != 0) &&
      (bb_mem_addr = (**(code **)(_r_osi_funcs_p + 0xe0))(300,*(code **)(_r_osi_funcs_p + 0xe0)),
      bb_mem_addr != 0)) &&
     (bb_agc_mem_addr = (**(code **)(_r_osi_funcs_p + 0xe0))(0xb4,*(code **)(_r_osi_funcs_p + 0xe0))
     , bb_agc_mem_addr != 0)) {
    return 1;
  }
  btdm_deep_sleep_mem_deinit();
  return 0;
}

