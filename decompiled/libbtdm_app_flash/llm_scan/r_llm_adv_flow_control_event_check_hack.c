/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> llm_scan.o -> r_llm_adv_flow_control_event_check_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llm_adv_flow_control_event_check_hack(void)

{
  if ((code *)*_r_vs_funcs_p != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x000117c2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)*_r_vs_funcs_p)();
    return;
  }
  return;
}

