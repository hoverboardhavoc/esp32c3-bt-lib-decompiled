/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> sch_slice.o -> r_sch_slice_fg_remove
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_sch_slice_fg_remove(uint param_1)

{
  int iVar1;
  
  sch_slice_env = ~(byte)(1 << (param_1 & 0x1f)) & sch_slice_env;
  if (param_1 == 2) {
    _sch_slice_params = -1;
  }
  else {
    r_assert_err(0,0x10000,0x1db);
  }
  r_sch_slice_compute();
  if (_sch_slice_params == -1) {
    iVar1 = r_sdk_config_get_opts_ext();
    if (*(char *)(iVar1 + 0x23) != '\0') {
      r_lld_scan_restart();
      return;
    }
  }
  return;
}

