/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> aes_k2.o -> r_aes_k2_continue
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int r_aes_k2_continue(int param_1,void *param_2)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  void *pvVar4;
  
  iVar3 = r_aes_cmac_continue();
  if (iVar3 == 0) {
    return 0;
  }
  cVar1 = *(char *)(param_1 + 0x38);
  if (cVar1 == '\x01') {
    memcpy((void *)(param_1 + 0x5a),param_2,0x10);
    memcpy((void *)(*(byte *)(param_1 + 0x39) + 0x5a + param_1),param_2,0x10);
    uVar2 = 2;
  }
  else {
    if (cVar1 == '\0') {
      pvVar4 = (void *)(param_1 + 0x3a);
      memcpy(pvVar4,param_2,0x10);
      r_aes_cmac_start(param_1,pvVar4,0,0);
      *(undefined1 *)(param_1 + 0x6a) = 1;
      r_aes_cmac_start(param_1,pvVar4,param_1 + 0x6a,*(byte *)(param_1 + 0x39) - 0x10);
      *(undefined1 *)(param_1 + 0x38) = 1;
      return 0;
    }
    if (cVar1 != '\x02') {
      if (cVar1 != '\x03') {
        r_assert_param(0,"aes_k2.c",0xbb);
        return iVar3;
      }
      pvVar4 = memcpy((void *)(param_1 + 0x3a),param_2,0x10);
      *(byte *)(param_1 + 0x5a) = *(byte *)(param_1 + 0x5a) & 0x7f;
      if (*(code **)(param_1 + 0x34) != (code *)0x0) {
        (**(code **)(param_1 + 0x34))(0,pvVar4,*(undefined4 *)(param_1 + 0x14));
        return iVar3;
      }
      return iVar3;
    }
    memcpy((void *)(param_1 + 0x4a),param_2,0x10);
    memcpy((void *)(*(byte *)(param_1 + 0x39) + 0x5a + param_1),param_2,0x10);
    uVar2 = 3;
  }
  *(undefined1 *)(param_1 + 0x6a) = uVar2;
  r_aes_cmac_start(param_1,param_1 + 0x3a,param_1 + 0x6a,*(undefined1 *)(param_1 + 0x39));
  *(undefined1 *)(param_1 + 0x38) = uVar2;
  return 0;
}

