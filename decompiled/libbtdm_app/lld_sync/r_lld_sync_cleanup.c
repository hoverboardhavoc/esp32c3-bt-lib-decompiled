/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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
                    /* WARNING: Could not recover jumptable at 0x000102f6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(iVar1 + 0x168))(0,1);
    return;
  }
  return;
}

