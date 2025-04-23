/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_cca.o -> r_lld_cca_con_evt_end_handle
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_cca_con_evt_end_handle(void)

{
  if ((code *)*p_lld_cca != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00010d14. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)*p_lld_cca)(0,1);
    return;
  }
  return;
}

