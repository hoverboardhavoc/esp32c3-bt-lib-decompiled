/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> ecc_p256.o -> r_SubtractBigHexUint32_256
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_SubtractBigHexUint32_256(void *param_1,uint param_2,void *param_3)

{
  ushort uVar1;
  undefined1 auStack_4c [32];
  short sStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  memset(param_3,0,0x22);
  uVar1 = *(ushort *)((int)param_1 + 0x20);
  *(undefined4 *)((int)param_3 + 0x24) = 0;
  *(undefined4 *)((int)param_3 + 0x28) = 0;
  if (uVar1 < param_2) {
    memset(auStack_4c,0,0x20);
    uStack_24 = 0;
    uStack_28 = 1;
    sStack_2c = (short)param_2;
    r_SubtractBigHexMod256(param_1,auStack_4c,param_3);
  }
  else {
    memcpy(param_3,param_1,0x22);
    *(undefined4 *)((int)param_3 + 0x24) = *(undefined4 *)((int)param_1 + 0x24);
    *(undefined4 *)((int)param_3 + 0x28) = *(undefined4 *)((int)param_1 + 0x28);
    *(short *)((int)param_3 + 0x20) = *(short *)((int)param_1 + 0x20) - (short)param_2;
  }
  return;
}

