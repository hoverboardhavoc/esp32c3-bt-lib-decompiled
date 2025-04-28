/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> aes_ccm.o -> r_rw_crypto_aes_ccm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_rw_crypto_aes_ccm(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,
                        undefined2 param_5,undefined1 param_6,byte param_7,undefined4 param_8)

{
  int iVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined1 in_stack_00000000;
  undefined4 in_stack_00000004;
  undefined4 in_stack_00000008;
  
  iVar1 = r_aes_alloc(0x54,r_aes_ccm_process_e,0,in_stack_00000008);
  *(undefined4 *)(iVar1 + 0x18) = in_stack_00000004;
  *(undefined4 *)(iVar1 + 0x1c) = param_1;
  *(undefined4 *)(iVar1 + 0x20) = param_8;
  *(undefined4 *)(iVar1 + 0x24) = param_3;
  *(undefined4 *)(iVar1 + 0x28) = param_4;
  *(undefined1 *)(iVar1 + 0x4f) = in_stack_00000000;
  *(undefined2 *)(iVar1 + 0x2c) = param_5;
  *(undefined1 *)(iVar1 + 0x50) = param_6;
  iVar4 = 0xc;
  puVar3 = (undefined1 *)(iVar1 + 0x31);
  do {
    puVar2 = (undefined1 *)(param_2 + iVar4);
    iVar4 = iVar4 + -1;
    *puVar3 = *puVar2;
    puVar3 = puVar3 + 1;
  } while (iVar4 != -1);
  *(byte *)(iVar1 + 0x51) = (*(byte *)(iVar1 + 0x51) & 0xfe | param_7) & 0xf3 | 0x12;
  r_aes_ccm_continue();
  return;
}

