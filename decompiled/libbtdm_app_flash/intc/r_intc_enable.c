/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> intc.o -> r_intc_enable
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_intc_enable(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
  if (rwble_intr_handle == 0) {
    if (bt_bb_intr_handle == 0) {
      return;
    }
    UNRECOVERED_JUMPTABLE = *(code **)(_r_osi_funcs_p + 0xcc);
  }
  else {
    (**(code **)(_r_osi_funcs_p + 0xcc))(*(code **)(_r_osi_funcs_p + 0xcc));
    if (bt_bb_intr_handle == 0) {
      return;
    }
    UNRECOVERED_JUMPTABLE = *(code **)(_r_osi_funcs_p + 0xcc);
  }
                    /* WARNING: Could not recover jumptable at 0x00010362. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(UNRECOVERED_JUMPTABLE);
  return;
}

