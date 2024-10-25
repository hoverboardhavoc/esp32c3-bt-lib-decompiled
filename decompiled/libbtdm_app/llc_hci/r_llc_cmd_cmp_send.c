/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llc_hci.o -> r_llc_cmd_cmp_send
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llc_cmd_cmp_send(undefined4 param_1,undefined4 param_2,undefined1 param_3)

{
  int iVar1;
  undefined1 *puVar2;
  
  puVar2 = (undefined1 *)
           (**(code **)(_r_modules_funcs_p + 200))
                     (0x1101,param_1,param_2,4,*(code **)(_r_modules_funcs_p + 200));
  *puVar2 = param_3;
  iVar1 = _r_ip_funcs_p;
  *(short *)(puVar2 + 2) = (short)param_1;
                    /* WARNING: Could not recover jumptable at 0x00010584. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(iVar1 + 0x8c))();
  return;
}

