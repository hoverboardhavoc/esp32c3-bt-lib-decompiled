/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> lld.o -> r_lld_rpa_renew_evt_start_cbk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_rpa_renew_evt_start_cbk(int param_1)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  int iVar2;
  
  if (_lld_rpa_renew_env != 0) {
    iVar2 = (**(code **)(_r_ip_funcs_p + 0x264))(*(code **)(_r_ip_funcs_p + 0x264));
    iVar1 = _r_ip_funcs_p;
    _DAT_60031000 = _DAT_60031000 & 0xfcffffff | 0x3000000;
    *(uint *)(param_1 + 0x28) = iVar2 + (uint)rwip_prog_delay & 0xfffffff;
    UNRECOVERED_JUMPTABLE = *(code **)(iVar1 + 0x70c);
    *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(iVar1 + 0x2a0);
                    /* WARNING: Could not recover jumptable at 0x0001159c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)(param_1 + 0x24);
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x000115b8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_plf_funcs_p + 8))(0,"lld.c",0x47e);
  return;
}

