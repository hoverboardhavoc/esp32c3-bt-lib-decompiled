/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
    (**(code **)(_r_modules_funcs_p + 0x358))(param_1,*(code **)(_r_modules_funcs_p + 0x358));
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
  (**(code **)(_r_modules_funcs_p + 0x3b8))
            (param_1,&bigHexP256,*(code **)(_r_modules_funcs_p + 0x3b8));
  return;
}

