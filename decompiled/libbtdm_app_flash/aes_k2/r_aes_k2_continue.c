/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> aes_k2.o -> r_aes_k2_continue
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int r_aes_k2_continue(int param_1,void *param_2)

{
  byte bVar1;
  undefined1 uVar2;
  int iVar3;
  ushort uVar4;
  void *pvVar5;
  
  iVar3 = r_aes_cmac_continue();
  if (iVar3 != 0) {
    bVar1 = *(byte *)(param_1 + 0x38);
    if (bVar1 == 2) {
      memcpy((void *)(param_1 + 0x4a),param_2,0x10);
      memcpy((void *)(*(byte *)(param_1 + 0x39) + 0x5a + param_1),param_2,0x10);
      uVar2 = 3;
      uVar4 = (ushort)*(byte *)(param_1 + 0x39);
      *(undefined1 *)(param_1 + 0x6a) = 3;
    }
    else {
      if (2 < bVar1) {
        if (bVar1 != 3) {
          r_assert_param(0,0x10000,0xbb);
          return iVar3;
        }
        pvVar5 = memcpy((void *)(param_1 + 0x3a),param_2,0x10);
        *(byte *)(param_1 + 0x5a) = *(byte *)(param_1 + 0x5a) & 0x7f;
        if (*(code **)(param_1 + 0x34) != (code *)0x0) {
          (**(code **)(param_1 + 0x34))(0,pvVar5,*(undefined4 *)(param_1 + 0x14));
          return iVar3;
        }
        return iVar3;
      }
      pvVar5 = (void *)(param_1 + 0x3a);
      if (bVar1 != 0) {
        memcpy((void *)(param_1 + 0x5a),param_2,0x10);
        memcpy((void *)(*(byte *)(param_1 + 0x39) + 0x5a + param_1),param_2,0x10);
        *(undefined1 *)(param_1 + 0x6a) = 2;
        r_aes_cmac_start(param_1,pvVar5,param_1 + 0x6a,*(undefined1 *)(param_1 + 0x39));
        *(undefined1 *)(param_1 + 0x38) = 2;
        return 0;
      }
      memcpy(pvVar5,param_2,0x10);
      r_aes_cmac_start(param_1,pvVar5,0,0);
      uVar2 = 1;
      *(undefined1 *)(param_1 + 0x6a) = 1;
      uVar4 = *(byte *)(param_1 + 0x39) - 0x10;
    }
    r_aes_cmac_start(param_1,param_1 + 0x3a,param_1 + 0x6a,uVar4);
    *(undefined1 *)(param_1 + 0x38) = uVar2;
  }
  return 0;
}

