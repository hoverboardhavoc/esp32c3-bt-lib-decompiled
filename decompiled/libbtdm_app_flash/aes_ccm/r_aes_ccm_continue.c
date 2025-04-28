/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> aes_ccm.o -> r_aes_ccm_continue
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_aes_ccm_continue(int param_1)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  byte bVar4;
  byte bVar5;
  uint uVar6;
  uint uVar7;
  short sStack_12;
  
  bVar1 = *(byte *)(param_1 + 0x51);
  bVar5 = bVar1 & 2;
  bVar4 = bVar1 & 0x10;
  if ((bVar1 & 2) == 0) {
    if ((bVar1 & 0x10) == 0) {
      bVar5 = *(char *)(param_1 + 0x2e) + 1;
    }
    *(undefined1 *)(param_1 + 0x3e) = 1;
    iVar2 = param_1 + 0x2f;
    *(byte *)(param_1 + 0x2f) = bVar5;
    *(undefined1 *)(param_1 + 0x30) = 0;
  }
  else if ((bVar1 & 0x10) == 0) {
    iVar2 = param_1 + 0x3f;
    if ((bVar1 & 4) != 0) {
      uVar7 = (uint)*(byte *)(param_1 + 0x2e) * 0x10;
      if (*(byte *)(param_1 + 0x2e) == 0) {
        sStack_12 = (ushort)*(byte *)(param_1 + 0x4f) << 8;
        r_aes_ccm_xor_128_lsb(iVar2,iVar2,&sStack_12,2,0);
        bVar4 = 2;
        uVar3 = 0xe;
      }
      else {
        uVar7 = uVar7 - 2 & 0xffff;
        uVar3 = 0x10;
      }
      uVar6 = *(byte *)(param_1 + 0x4f) - uVar7;
      if ((int)uVar6 < (int)uVar3) {
        uVar3 = uVar6 & 0xff;
      }
      r_aes_ccm_xor_128_lsb(iVar2,iVar2,*(int *)(param_1 + 0x20) + uVar7,uVar3,bVar4);
    }
  }
  else {
    *(byte *)(param_1 + 0x3e) =
         *(byte *)(param_1 + 0x3e) & 0x3f | (*(char *)(param_1 + 0x4f) != '\0') << 6;
    if (((int)(*(byte *)(param_1 + 0x50) - 2) / 2 & 0x1ffffff8U) != 0) {
      r_assert_param(0x38,"aes_ccm.c",0xcf);
    }
    iVar2 = param_1 + 0x2f;
    *(byte *)(param_1 + 0x3e) =
         *(byte *)(param_1 + 0x3e) & 0xc0 | (byte)((int)(*(byte *)(param_1 + 0x50) - 2) / 2 << 3) |
         1;
    *(char *)(param_1 + 0x2f) = (char)*(undefined2 *)(param_1 + 0x2c);
    *(char *)(param_1 + 0x30) = (char)((ushort)*(undefined2 *)(param_1 + 0x2c) >> 8);
  }
  r_aes_start(param_1,*(undefined4 *)(param_1 + 0x1c),iVar2);
  return;
}

