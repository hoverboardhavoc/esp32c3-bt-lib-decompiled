/*
 * Last changed at upstream commit 29d5555ca1febeb132f5a13556893f3419d2d640
 * https://github.com/espressif/esp32c3-bt-lib/commit/29d5555ca1febeb132f5a13556893f3419d2d640
 * Upstream date: 2024-06-03 11:12:02 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(0738a61)
 * Source: libbtdm_app -> intc.o -> r_intc_disable
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_intc_disable(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
  if (_LANCHOR0 == 0) {
    if (_LANCHOR1 == 0) {
      return;
    }
    UNRECOVERED_JUMPTABLE = *(code **)(_r_osi_funcs_p + 0xd0);
  }
  else {
    (**(code **)(_r_osi_funcs_p + 0xd0))(*(code **)(_r_osi_funcs_p + 0xd0));
    if (_LANCHOR1 == 0) {
      return;
    }
    UNRECOVERED_JUMPTABLE = *(code **)(_r_osi_funcs_p + 0xd0);
  }
                    /* WARNING: Could not recover jumptable at 0x000103e8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}

