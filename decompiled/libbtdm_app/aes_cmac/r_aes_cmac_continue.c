/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> aes_cmac.o -> r_aes_cmac_continue
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_aes_cmac_continue(int param_1,void *param_2)

{
  char cVar1;
  ushort uVar2;
  undefined *puVar3;
  undefined1 *puVar4;
  uint uVar5;
  code *pcVar6;
  uint uVar7;
  byte abStack_40 [15];
  char cStack_31;
  undefined1 auStack_30 [15];
  undefined1 auStack_21 [9];
  
  uVar5 = (uint)*(byte *)(param_1 + 0x33);
  if (uVar5 < *(byte *)(param_1 + 0x32)) {
    (**(code **)(_r_modules_funcs_p + 0x328))
              (param_1 + 0x20,
               *(int *)(param_1 + 0x18) + (uint)*(ushort *)(param_1 + 0x30) + uVar5 * -0x10,0x10,
               *(code **)(_r_modules_funcs_p + 0x328));
    (**(code **)(_r_modules_funcs_p + 0x324))
              (param_1,*(undefined4 *)(param_1 + 0x1c),param_1 + 0x20,
               *(code **)(_r_modules_funcs_p + 0x324));
    *(char *)(param_1 + 0x33) = *(char *)(param_1 + 0x33) + '\x01';
  }
  else {
    if (uVar5 < 0xfe) {
      *(undefined1 *)(param_1 + 0x33) = 0xfe;
      memcpy((void *)(param_1 + 0x20),param_2,0x10);
      puVar3 = &aes_cmac_zero;
      pcVar6 = *(code **)(_r_modules_funcs_p + 0x324);
    }
    else {
      if (uVar5 == 0xff) {
        return 1;
      }
      *(undefined1 *)(param_1 + 0x33) = 0xff;
      uVar2 = *(ushort *)(param_1 + 0x30);
      cVar1 = *(char *)((int)param_2 + 0xf);
      uVar5 = uVar2 & 0xf;
      (**(code **)(_r_modules_funcs_p + 800))
                (param_2,abStack_40,*(code **)(_r_modules_funcs_p + 800));
      if (cVar1 < '\0') {
        abStack_40[0] = abStack_40[0] ^ 0x87;
      }
      if (((uVar2 & 0xf) == 0) && (*(char *)(param_1 + 0x32) != '\0')) {
        memcpy(auStack_30,*(void **)(param_1 + 0x18),0x10);
      }
      else {
        (**(code **)(_r_modules_funcs_p + 800))(abStack_40,*(code **)(_r_modules_funcs_p + 800));
        if (cStack_31 < '\0') {
          abStack_40[0] = abStack_40[0] ^ 0x87;
        }
        puVar4 = auStack_30;
        uVar7 = 0;
        do {
          if ((uVar7 & 0xff) < uVar5) {
            auStack_21[(uVar7 - uVar5) + 1] = *(undefined1 *)(*(int *)(param_1 + 0x18) + uVar7);
          }
          else if (uVar5 == (uVar7 & 0xff)) {
            auStack_21[-uVar5] = 0x80;
          }
          else {
            puVar4[0xf] = 0;
          }
          uVar7 = uVar7 + 1;
          puVar4 = puVar4 + -1;
        } while (uVar7 != 0x10);
      }
      (**(code **)(_r_modules_funcs_p + 0x328))
                (auStack_30,abStack_40,0x10,*(code **)(_r_modules_funcs_p + 0x328));
      puVar3 = (undefined *)(param_1 + 0x20);
      (**(code **)(_r_modules_funcs_p + 0x328))
                (puVar3,auStack_30,0x10,*(code **)(_r_modules_funcs_p + 0x328));
      pcVar6 = *(code **)(_r_modules_funcs_p + 0x324);
    }
    (*pcVar6)(param_1,*(undefined4 *)(param_1 + 0x1c),puVar3,pcVar6);
  }
  return 0;
}

