/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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
                    /* WARNING: Could not recover jumptable at 0x00010646. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_ip_funcs_p + 0x664))(param_1,2,3);
    return;
  }
  return;
}

