/*
 * Last changed at upstream commit aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * https://github.com/espressif/esp32c3-bt-lib/commit/aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * Upstream date: 2025-03-20 20:31:24 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(d74042a8)
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
    uVar2 = 0x49e;
    UNRECOVERED_JUMPTABLE = *(code **)(_r_plf_funcs_p + 8);
  }
  else {
    *(char *)(param_1 + 0x16) = *(char *)(param_1 + 0x16) + rwip_priority;
    iVar1 = (**(code **)(iVar1 + 0x6b0))(*(code **)(iVar1 + 0x6b0));
    if (iVar1 == 0) {
      return;
    }
    UNRECOVERED_JUMPTABLE = *(code **)(_r_plf_funcs_p + 8);
    uVar2 = 0x499;
  }
                    /* WARNING: Could not recover jumptable at 0x000116b2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(0,"lld.c",uVar2);
  return;
}

