/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> aes_ccm.o -> r_aes_ccm_continue
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_aes_ccm_continue(int param_1)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  char cVar5;
  uint uVar6;
  int iVar7;
  short sStack_12;
  
  bVar1 = *(byte *)(param_1 + 0x51);
  if ((bVar1 & 2) == 0) {
    cVar5 = '\0';
    if ((bVar1 & 0x10) == 0) {
      cVar5 = *(char *)(param_1 + 0x2e) + '\x01';
    }
    *(undefined1 *)(param_1 + 0x3e) = 1;
    iVar7 = param_1 + 0x2f;
    *(char *)(param_1 + 0x2f) = cVar5;
    *(undefined1 *)(param_1 + 0x30) = 0;
  }
  else if ((bVar1 & 0x10) == 0) {
    iVar7 = param_1 + 0x3f;
    if ((bVar1 & 4) != 0) {
      uVar2 = (uint)*(byte *)(param_1 + 0x2e) * 0x10;
      if (*(byte *)(param_1 + 0x2e) == 0) {
        sStack_12 = (ushort)*(byte *)(param_1 + 0x4f) << 8;
        r_aes_ccm_xor_128_lsb(iVar7,iVar7,&sStack_12,2,0);
        uVar4 = 2;
        uVar3 = 0xe;
      }
      else {
        uVar2 = uVar2 - 2 & 0xffff;
        uVar4 = 0;
        uVar3 = 0x10;
      }
      uVar6 = *(byte *)(param_1 + 0x4f) - uVar2;
      if ((int)uVar6 < (int)uVar3) {
        uVar3 = uVar6 & 0xff;
      }
      r_aes_ccm_xor_128_lsb(iVar7,iVar7,*(int *)(param_1 + 0x20) + uVar2,uVar3,uVar4);
    }
  }
  else {
    *(byte *)(param_1 + 0x3e) =
         *(byte *)(param_1 + 0x3e) & 0x3f | (*(char *)(param_1 + 0x4f) != '\0') << 6;
    if (((int)(*(byte *)(param_1 + 0x50) - 2) / 2 & 0x1ffffff8U) != 0) {
      r_assert_param(0x38,"aes_ccm.c",0xcf);
    }
    iVar7 = param_1 + 0x2f;
    *(byte *)(param_1 + 0x3e) =
         *(byte *)(param_1 + 0x3e) & 0xc0 | (byte)((int)(*(byte *)(param_1 + 0x50) - 2) / 2 << 3) |
         1;
    *(char *)(param_1 + 0x2f) = (char)*(undefined2 *)(param_1 + 0x2c);
    *(char *)(param_1 + 0x30) = (char)((ushort)*(undefined2 *)(param_1 + 0x2c) >> 8);
  }
  r_aes_start(param_1,*(undefined4 *)(param_1 + 0x1c),iVar7);
  return;
}

