/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> aes_cmac.o -> r_aes_cmac_continue
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 r_aes_cmac_continue(int param_1,void *param_2)

{
  char cVar1;
  ushort uVar2;
  undefined *puVar3;
  undefined1 *puVar4;
  uint uVar5;
  uint uVar6;
  byte local_40 [15];
  char cStack_31;
  undefined1 auStack_30 [15];
  undefined1 auStack_21 [13];
  
  uVar6 = (uint)*(byte *)(param_1 + 0x33);
  if (uVar6 < *(byte *)(param_1 + 0x32)) {
    r_aes_xor_128(param_1 + 0x20,
                  *(int *)(param_1 + 0x18) + (uint)*(ushort *)(param_1 + 0x30) + uVar6 * -0x10,0x10)
    ;
    r_aes_start(param_1,*(undefined4 *)(param_1 + 0x1c),param_1 + 0x20);
    *(char *)(param_1 + 0x33) = *(char *)(param_1 + 0x33) + '\x01';
  }
  else {
    if (uVar6 < 0xfe) {
      *(undefined1 *)(param_1 + 0x33) = 0xfe;
      memcpy((void *)(param_1 + 0x20),param_2,0x10);
      puVar3 = &aes_cmac_zero;
    }
    else {
      if (uVar6 == 0xff) {
        return 1;
      }
      *(undefined1 *)(param_1 + 0x33) = 0xff;
      cVar1 = *(char *)((int)param_2 + 0xf);
      uVar2 = *(ushort *)(param_1 + 0x30);
      uVar6 = uVar2 & 0xf;
      r_aes_shift_left_128(param_2,local_40);
      if (cVar1 < '\0') {
        local_40[0] = local_40[0] ^ 0x87;
      }
      if (((uVar2 & 0xf) == 0) && (*(char *)(param_1 + 0x32) != '\0')) {
        memcpy(auStack_30,*(void **)(param_1 + 0x18),0x10);
      }
      else {
        r_aes_shift_left_128(local_40,local_40);
        if (cStack_31 < '\0') {
          local_40[0] = local_40[0] ^ 0x87;
        }
        puVar4 = auStack_30;
        uVar5 = 0;
        do {
          if ((uVar5 & 0xff) < uVar6) {
            auStack_21[(uVar5 - uVar6) + 1] = *(undefined1 *)(*(int *)(param_1 + 0x18) + uVar5);
          }
          else if (uVar6 == (uVar5 & 0xff)) {
            auStack_21[-uVar6] = 0x80;
          }
          else {
            puVar4[0xf] = 0;
          }
          uVar5 = uVar5 + 1;
          puVar4 = puVar4 + -1;
        } while (uVar5 != 0x10);
      }
      r_aes_xor_128(auStack_30,local_40,0x10);
      puVar3 = (undefined *)(param_1 + 0x20);
      r_aes_xor_128(puVar3,auStack_30,puVar3,0x10);
    }
    r_aes_start(param_1,*(undefined4 *)(param_1 + 0x1c),puVar3);
  }
  return 0;
}

