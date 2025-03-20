/*
 * Last changed at upstream commit d2414a5dd958b32ca53382b441d24d97a0345a55
 * https://github.com/espressif/esp32c3-bt-lib/commit/d2414a5dd958b32ca53382b441d24d97a0345a55
 * Upstream date: 2025-03-20 20:11:19 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(03d0f8a6)
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
                    /* WARNING: Could not recover jumptable at 0x00012828. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)*_r_vs_funcs_p)();
    return;
  }
  return;
}

