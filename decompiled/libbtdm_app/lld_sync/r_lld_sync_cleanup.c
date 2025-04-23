/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_sync.o -> r_lld_sync_cleanup
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_sync_cleanup(int param_1,undefined1 param_2)

{
  int iVar1;
  int *piVar2;
  undefined1 *puVar3;
  
  piVar2 = (int *)(&lld_sync_env + param_1 * 4);
  if (*piVar2 != 0) {
    puVar3 = (undefined1 *)
             (**(code **)(_r_modules_funcs_p + 200))
                       (0x205,0,0xff,2,*(code **)(_r_modules_funcs_p + 200));
    *puVar3 = (char)param_1;
    puVar3[1] = param_2;
    (**(code **)(_r_modules_funcs_p + 0xe0))(*(code **)(_r_modules_funcs_p + 0xe0));
    (**(code **)(_r_modules_funcs_p + 0x110))(*piVar2,*(code **)(_r_modules_funcs_p + 0x110));
    iVar1 = _r_ip_funcs_p;
    *piVar2 = 0;
                    /* WARNING: Could not recover jumptable at 0x00010300. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(iVar1 + 0x168))(0,1,*(code **)(iVar1 + 0x168));
    return;
  }
  return;
}

