/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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
  
  if (_LANCHOR0 == 0) {
    if (_LANCHOR1 == 0) {
      return;
    }
    UNRECOVERED_JUMPTABLE = *(code **)(_r_osi_funcs_p + 0xcc);
  }
  else {
    (**(code **)(_r_osi_funcs_p + 0xcc))(*(code **)(_r_osi_funcs_p + 0xcc));
    if (_LANCHOR1 == 0) {
      return;
    }
    UNRECOVERED_JUMPTABLE = *(code **)(_r_osi_funcs_p + 0xcc);
  }
                    /* WARNING: Could not recover jumptable at 0x0001034a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}

