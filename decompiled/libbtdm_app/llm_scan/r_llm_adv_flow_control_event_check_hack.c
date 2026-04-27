/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app -> llm_scan.o -> r_llm_adv_flow_control_event_check_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llm_adv_flow_control_event_check_hack(void)

{
  if ((code *)*_r_vs_funcs_p != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00012854. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)*_r_vs_funcs_p)();
    return;
  }
  return;
}

