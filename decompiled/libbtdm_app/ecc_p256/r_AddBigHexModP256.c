/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> ecc_p256.o -> r_AddBigHexModP256
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_AddBigHexModP256(int param_1)

{
  ushort uVar1;
  uint uVar2;
  
  (**(code **)(_r_modules_funcs_p + 0x350))(*(code **)(_r_modules_funcs_p + 0x350));
  if (*(int *)(param_1 + 0x28) != 0) {
                    /* WARNING: Could not recover jumptable at 0x0001012c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_modules_funcs_p + 0x358))(param_1);
    return;
  }
  uVar2 = *(uint *)(param_1 + 0x24);
  if (uVar2 <= _r_plf_funcs_p) {
    if (uVar2 < _r_plf_funcs_p) {
      return;
    }
    for (uVar2 = 0x11 - uVar2; uVar2 < 0x11; uVar2 = uVar2 + 1) {
      uVar1 = *(ushort *)(uVar2 * 2 + param_1);
      if (uVar1 < *(ushort *)(&bigHexP256 + uVar2 * 2)) {
        return;
      }
      if (*(ushort *)(&bigHexP256 + uVar2 * 2) < uVar1) break;
    }
  }
                    /* WARNING: Could not recover jumptable at 0x000100fa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_modules_funcs_p + 0x3b8))(param_1,&bigHexP256);
  return;
}

