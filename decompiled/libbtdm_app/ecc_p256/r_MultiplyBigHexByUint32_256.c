/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> ecc_p256.o -> r_MultiplyBigHexByUint32_256
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_MultiplyBigHexByUint32_256(int param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = 0x20;
  uVar1 = 0;
  do {
    uVar1 = uVar1 + (uint)*(ushort *)(param_1 + iVar2) * param_2;
    *(short *)(param_3 + iVar2) = (short)uVar1;
    iVar2 = iVar2 + -2;
    uVar1 = uVar1 >> 0x10;
  } while (iVar2 != -2);
  iVar2 = 0;
  do {
    if (*(short *)(iVar2 * 2 + param_3) != 0) break;
    iVar2 = iVar2 + 1;
  } while (iVar2 != 0x11);
  *(int *)(param_3 + 0x24) = 0x11 - iVar2;
  *(undefined4 *)(param_3 + 0x28) = *(undefined4 *)(param_1 + 0x28);
                    /* WARNING: Could not recover jumptable at 0x00010864. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_modules_funcs_p + 0x3a8))(*(code **)(_r_modules_funcs_p + 0x3a8));
  return;
}

