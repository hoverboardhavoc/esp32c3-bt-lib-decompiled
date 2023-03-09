/*
 * Last changed at upstream commit 5c6ab5248a124cffc731a9e4764473fdeef38054
 * https://github.com/espressif/esp32c3-bt-lib/commit/5c6ab5248a124cffc731a9e4764473fdeef38054
 * Upstream date: 2023-03-09 14:58:19 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(85a1090)
 * Source: libbtdm_app -> nvds.o -> r_nvds_init_memory
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_nvds_init_memory(void)

{
  (*DAT_000106a8)(0,DAT_000106b0,DAT_000106a8);
                    /* WARNING: Could not recover jumptable at 0x00010258. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_000106a4)(0,4,"NVDSNVDS MAGIC FAILED\n");
  return;
}

