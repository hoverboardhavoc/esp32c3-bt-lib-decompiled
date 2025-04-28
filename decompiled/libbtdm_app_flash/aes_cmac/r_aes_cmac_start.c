/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> aes_cmac.o -> r_aes_cmac_start
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 r_aes_cmac_start(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  char cVar1;
  ushort uVar2;
  void *__src;
  undefined *puVar3;
  undefined1 *puVar4;
  uint uVar5;
  uint uVar6;
  byte abStack_40 [15];
  char cStack_31;
  undefined1 auStack_30 [15];
  undefined1 auStack_21 [13];
  
  *(short *)(param_1 + 0x30) = (short)param_4;
  *(undefined4 *)(param_1 + 0x1c) = param_2;
  *(undefined1 *)(param_1 + 0x33) = 1;
  *(undefined4 *)(param_1 + 0x18) = param_3;
  *(char *)(param_1 + 0x32) = (char)(param_4 + 0xf >> 4);
  __src = memcpy((void *)(param_1 + 0x20),&aes_cmac_zero,0x10);
  uVar5 = (uint)*(byte *)(param_1 + 0x33);
  if (uVar5 < *(byte *)(param_1 + 0x32)) {
    r_aes_xor_128(param_1 + 0x20,
                  *(int *)(param_1 + 0x18) + (uint)*(ushort *)(param_1 + 0x30) + uVar5 * -0x10,0x10)
    ;
    r_aes_start(param_1,*(undefined4 *)(param_1 + 0x1c),param_1 + 0x20);
    *(char *)(param_1 + 0x33) = *(char *)(param_1 + 0x33) + '\x01';
  }
  else {
    if (uVar5 < 0xfe) {
      *(undefined1 *)(param_1 + 0x33) = 0xfe;
      memcpy((void *)(param_1 + 0x20),__src,0x10);
      puVar3 = &aes_cmac_zero;
    }
    else {
      if (uVar5 == 0xff) {
        return 1;
      }
      *(undefined1 *)(param_1 + 0x33) = 0xff;
      cVar1 = *(char *)((int)__src + 0xf);
      uVar2 = *(ushort *)(param_1 + 0x30);
      uVar5 = uVar2 & 0xf;
      r_aes_shift_left_128(__src,abStack_40);
      if (cVar1 < '\0') {
        abStack_40[0] = abStack_40[0] ^ 0x87;
      }
      if (((uVar2 & 0xf) == 0) && (*(char *)(param_1 + 0x32) != '\0')) {
        memcpy(auStack_30,*(void **)(param_1 + 0x18),0x10);
      }
      else {
        r_aes_shift_left_128(abStack_40);
        if (cStack_31 < '\0') {
          abStack_40[0] = abStack_40[0] ^ 0x87;
        }
        puVar4 = auStack_30;
        uVar6 = 0;
        do {
          if ((uVar6 & 0xff) < uVar5) {
            auStack_21[(uVar6 - uVar5) + 1] = *(undefined1 *)(*(int *)(param_1 + 0x18) + uVar6);
          }
          else if (uVar5 == (uVar6 & 0xff)) {
            auStack_21[-uVar5] = 0x80;
          }
          else {
            puVar4[0xf] = 0;
          }
          uVar6 = uVar6 + 1;
          puVar4 = puVar4 + -1;
        } while (uVar6 != 0x10);
      }
      r_aes_xor_128(auStack_30,abStack_40,0x10);
      puVar3 = (undefined *)(param_1 + 0x20);
      r_aes_xor_128(puVar3,auStack_30,0x10);
    }
    r_aes_start(param_1,*(undefined4 *)(param_1 + 0x1c),puVar3);
  }
  return 0;
}

