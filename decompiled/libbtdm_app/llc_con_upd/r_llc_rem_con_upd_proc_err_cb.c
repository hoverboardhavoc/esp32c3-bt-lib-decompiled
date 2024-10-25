/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llc_con_upd.o -> r_llc_rem_con_upd_proc_err_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llc_rem_con_upd_proc_err_cb(int param_1,char *param_2)

{
  char cVar1;
  undefined4 uVar2;
  
  if (param_1 == 2) {
    cVar1 = param_2[1];
  }
  else {
    if (param_1 != 3) {
      if (param_1 != 0) {
        return;
      }
      cVar1 = *param_2;
      uVar2 = 0xb;
      goto _L187;
    }
    if (param_2[1] != '\x10') {
      return;
    }
    cVar1 = param_2[2];
  }
  uVar2 = 9;
_L187:
  if (cVar1 == '\0') {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x000111d4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_ip_funcs_p + 0x600))(uVar2);
  return;
}

