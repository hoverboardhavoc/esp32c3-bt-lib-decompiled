/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llc_disconnect.o -> r_llc_disconnect
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llc_disconnect(int param_1,undefined1 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = _r_ip_funcs_p;
  iVar2 = *(int *)(&llc_env + param_1 * 4);
  if (*(char *)(iVar2 + 0x49) == '\0') {
    *(undefined1 *)(iVar2 + 0x46) = param_2;
    *(undefined1 *)(iVar2 + 0x47) = 0;
    (**(code **)(iVar1 + 0x3b4))(param_3,*(code **)(iVar1 + 0x3b4));
    *(undefined1 *)(iVar2 + 0x49) = 1;
                    /* WARNING: Could not recover jumptable at 0x0001064e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_ip_funcs_p + 0x664))(param_1,2,3,*(code **)(_r_ip_funcs_p + 0x664));
    return;
  }
  return;
}

