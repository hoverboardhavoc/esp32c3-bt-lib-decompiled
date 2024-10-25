/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llc_le_ping.o -> r_llc_le_ping_proc_err_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llc_le_ping_proc_err_cb(uint param_1,undefined1 *param_2)

{
  code *UNRECOVERED_JUMPTABLE;
  undefined1 uVar1;
  
  if (param_1 == 1) {
    if (param_2[1] != '\x12') {
      return;
    }
    uVar1 = 0;
    UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x608);
  }
  else {
    if (param_1 != 0) {
      if (param_1 < 4) {
        return;
      }
                    /* WARNING: Could not recover jumptable at 0x000100d8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(_r_plf_funcs_p + 0xc))("llc_le_ping.c",0x12e);
      return;
    }
    uVar1 = *param_2;
    UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x608);
  }
                    /* WARNING: Could not recover jumptable at 0x000100a4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(1,uVar1);
  return;
}

