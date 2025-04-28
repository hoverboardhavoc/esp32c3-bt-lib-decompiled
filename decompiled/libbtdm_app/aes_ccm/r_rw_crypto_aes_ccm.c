/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> aes_ccm.o -> r_rw_crypto_aes_ccm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_rw_crypto_aes_ccm(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,
                        undefined2 param_5,undefined1 param_6,byte param_7,undefined4 param_8)

{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  int iVar5;
  undefined1 in_stack_00000000;
  undefined4 in_stack_00000004;
  undefined4 in_stack_00000008;
  
  iVar2 = (**(code **)(_r_modules_funcs_p + 0x31c))
                    (0x54,*(undefined4 *)(_r_modules_funcs_p + 0x304),0,in_stack_00000008,
                     *(code **)(_r_modules_funcs_p + 0x31c));
  *(undefined4 *)(iVar2 + 0x18) = in_stack_00000004;
  *(undefined4 *)(iVar2 + 0x1c) = param_1;
  *(undefined4 *)(iVar2 + 0x20) = param_8;
  *(undefined4 *)(iVar2 + 0x24) = param_3;
  *(undefined4 *)(iVar2 + 0x28) = param_4;
  *(undefined1 *)(iVar2 + 0x4f) = in_stack_00000000;
  *(undefined2 *)(iVar2 + 0x2c) = param_5;
  *(undefined1 *)(iVar2 + 0x50) = param_6;
  iVar5 = 0xc;
  puVar4 = (undefined1 *)(iVar2 + 0x31);
  do {
    puVar3 = (undefined1 *)(param_2 + iVar5);
    iVar5 = iVar5 + -1;
    *puVar4 = *puVar3;
    iVar1 = _r_modules_funcs_p;
    puVar4 = puVar4 + 1;
  } while (iVar5 != -1);
  *(byte *)(iVar2 + 0x51) = (*(byte *)(iVar2 + 0x51) & 0xfe | param_7) & 0xf3 | 0x12;
                    /* WARNING: Could not recover jumptable at 0x00010446. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(iVar1 + 0x300))(*(code **)(iVar1 + 0x300));
  return;
}

