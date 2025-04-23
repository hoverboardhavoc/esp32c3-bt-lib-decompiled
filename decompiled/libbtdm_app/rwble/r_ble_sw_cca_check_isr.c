/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> rwble.o -> r_ble_sw_cca_check_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_ble_sw_cca_check_isr(void)

{
                    /* WARNING: Could not recover jumptable at 0x000103be. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_ip_funcs_p + 0x2b0))
            (_DAT_60031360 >> 0xc & 0xff,_DAT_60031360 >> 4 & 0x7f,_DAT_60031360 >> 0x1d & 1,
             *(code **)(_r_ip_funcs_p + 0x2b0));
  return;
}

