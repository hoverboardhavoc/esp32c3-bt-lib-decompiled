/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_cca.o -> r_lld_cca_con_evt_end_handle
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_cca_con_evt_end_handle(void)

{
  if ((code *)*p_lld_cca != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00010f14. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)*p_lld_cca)(0,1);
    return;
  }
  return;
}

