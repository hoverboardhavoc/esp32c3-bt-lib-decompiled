/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> lld.o -> r_lld_rpa_renew_evt_canceled_cbk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_rpa_renew_evt_canceled_cbk(int param_1)

{
  code *UNRECOVERED_JUMPTABLE;
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = _r_ip_funcs_p;
  if (_lld_rpa_renew_env == 0) {
    uVar2 = 0x496;
    UNRECOVERED_JUMPTABLE = *(code **)(_r_plf_funcs_p + 8);
  }
  else {
    *(char *)(param_1 + 0x16) = *(char *)(param_1 + 0x16) + rwip_priority;
    iVar1 = (**(code **)(iVar1 + 0x6b0))(*(code **)(iVar1 + 0x6b0));
    if (iVar1 == 0) {
      return;
    }
    UNRECOVERED_JUMPTABLE = *(code **)(_r_plf_funcs_p + 8);
    uVar2 = 0x491;
  }
                    /* WARNING: Could not recover jumptable at 0x00011608. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(0,"lld.c",uVar2);
  return;
}

