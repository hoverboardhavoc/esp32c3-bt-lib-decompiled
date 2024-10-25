/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> ecc_p256.o -> r_ecc_gen_new_secret_key
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_ecc_gen_new_secret_key(undefined1 *param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_2 != 0) {
    return;
  }
  do {
    uVar1 = (**(code **)(_r_osi_funcs_p + 0x88))(*(code **)(_r_osi_funcs_p + 0x88));
    *param_1 = (char)uVar1;
    param_1[1] = (char)((uint)uVar1 >> 8);
    param_1[2] = (char)((uint)uVar1 >> 0x10);
    param_1[3] = (char)((uint)uVar1 >> 0x18);
    uVar1 = (**(code **)(_r_osi_funcs_p + 0x88))(*(code **)(_r_osi_funcs_p + 0x88));
    param_1[5] = (char)((uint)uVar1 >> 8);
    param_1[6] = (char)((uint)uVar1 >> 0x10);
    iVar2 = _r_osi_funcs_p;
    param_1[4] = (char)uVar1;
    param_1[7] = (char)((uint)uVar1 >> 0x18);
    uVar1 = (**(code **)(iVar2 + 0x88))(*(code **)(iVar2 + 0x88));
    param_1[9] = (char)((uint)uVar1 >> 8);
    param_1[10] = (char)((uint)uVar1 >> 0x10);
    iVar2 = _r_osi_funcs_p;
    param_1[8] = (char)uVar1;
    param_1[0xb] = (char)((uint)uVar1 >> 0x18);
    uVar1 = (**(code **)(iVar2 + 0x88))(*(code **)(iVar2 + 0x88));
    param_1[0xd] = (char)((uint)uVar1 >> 8);
    param_1[0xe] = (char)((uint)uVar1 >> 0x10);
    iVar2 = _r_osi_funcs_p;
    param_1[0xc] = (char)uVar1;
    param_1[0xf] = (char)((uint)uVar1 >> 0x18);
    uVar1 = (**(code **)(iVar2 + 0x88))(*(code **)(iVar2 + 0x88));
    param_1[0x11] = (char)((uint)uVar1 >> 8);
    param_1[0x12] = (char)((uint)uVar1 >> 0x10);
    iVar2 = _r_osi_funcs_p;
    param_1[0x10] = (char)uVar1;
    param_1[0x13] = (char)((uint)uVar1 >> 0x18);
    uVar1 = (**(code **)(iVar2 + 0x88))(*(code **)(iVar2 + 0x88));
    param_1[0x15] = (char)((uint)uVar1 >> 8);
    param_1[0x16] = (char)((uint)uVar1 >> 0x10);
    iVar2 = _r_osi_funcs_p;
    param_1[0x14] = (char)uVar1;
    param_1[0x17] = (char)((uint)uVar1 >> 0x18);
    uVar1 = (**(code **)(iVar2 + 0x88))(*(code **)(iVar2 + 0x88));
    param_1[0x19] = (char)((uint)uVar1 >> 8);
    param_1[0x1a] = (char)((uint)uVar1 >> 0x10);
    iVar2 = _r_osi_funcs_p;
    param_1[0x18] = (char)uVar1;
    param_1[0x1b] = (char)((uint)uVar1 >> 0x18);
    uVar1 = (**(code **)(iVar2 + 0x88))(*(code **)(iVar2 + 0x88));
    param_1[0x1d] = (char)((uint)uVar1 >> 8);
    param_1[0x1e] = (char)((uint)uVar1 >> 0x10);
    iVar2 = _r_modules_funcs_p;
    param_1[0x1c] = (char)uVar1;
    param_1[0x1f] = (char)((uint)uVar1 >> 0x18);
    iVar2 = (**(code **)(iVar2 + 0x394))(param_1,*(code **)(iVar2 + 0x394));
  } while (iVar2 == 0);
  return;
}

