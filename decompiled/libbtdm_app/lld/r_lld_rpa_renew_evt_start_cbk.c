/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  
  if (_lld_rpa_renew_env != 0) {
    iVar1 = (**(code **)(_r_ip_funcs_p + 0x264))(*(code **)(_r_ip_funcs_p + 0x264));
    _DAT_60031000 = _DAT_60031000 & 0xfcffffff | 0x3000000;
    *(uint *)(param_1 + 0x28) = (uint)rwip_prog_delay + iVar1 & 0xfffffff;
    UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x70c);
    *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(_r_ip_funcs_p + 0x2a0);
                    /* WARNING: Could not recover jumptable at 0x00011668. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)(param_1 + 0x24,UNRECOVERED_JUMPTABLE);
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00011682. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_plf_funcs_p + 8))(0,"lld.c",0x48b,*(code **)(_r_plf_funcs_p + 8));
  return;
}

