/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> eif.o -> r_h4tl_eif_register
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_h4tl_eif_register(int *param_1)

{
  undefined4 uVar1;
  
  if (param_1 != (int *)0x0) {
    if (3 < _g_bt_plf_log_level) {
      ets_printf(0x10000,0xfadebead,0x10000);
    }
    if (*param_1 == -0x5214153) {
      if (param_1[1] == 0x10000) {
        uVar1 = 0;
        _r_h4tl_eif_p = param_1;
      }
      else {
        if (0 < _g_bt_plf_log_level) {
          ets_printf("H4TL EIF Version mismatch: %08x\n");
        }
        uVar1 = 0xfffffffd;
      }
    }
    else {
      if (0 < _g_bt_plf_log_level) {
        ets_printf("H4TL EIF Magic mismatch: %08x\n");
      }
      uVar1 = 0xfffffffe;
    }
    return uVar1;
  }
  return 0xffffffff;
}

