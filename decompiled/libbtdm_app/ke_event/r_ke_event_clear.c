/*
 * Last changed at upstream commit daab5dbba958a13041bd496e4a6ed506c9284a06
 * https://github.com/espressif/esp32c3-bt-lib/commit/daab5dbba958a13041bd496e4a6ed506c9284a06
 * Upstream date: 2025-03-20 20:43:40 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(86a4da5c)
 * Source: libbtdm_app -> ke_event.o -> r_ke_event_clear
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_ke_event_clear(uint param_1)

{
  if (0xe < param_1) {
    (**(code **)(_r_plf_funcs_p + 0xc))(0,"ke_event.c",0x85,*(code **)(_r_plf_funcs_p + 0xc));
  }
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  if (param_1 < 0xf) {
    _ke_event_env = ~(1 << (param_1 & 0x1f)) & _ke_event_env;
  }
                    /* WARNING: Could not recover jumptable at 0x00010130. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_osi_funcs_p + 0x18))();
  return;
}

