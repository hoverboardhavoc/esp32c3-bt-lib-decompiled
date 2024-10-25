/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld_cca.o -> r_lld_cca_chan_sel_1
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint r_lld_cca_chan_sel_1(int param_1,int param_2,int param_3,byte *param_4,uint param_5)

{
  uint uVar1;
  byte *pbVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar3 = ((param_3 + 1) * param_2 + param_1) % 0x25;
  uVar1 = uVar3 & 0xff;
  if (((int)(uint)param_4[uVar1 >> 3] >> (uVar3 & 7) & 1U) != 0) {
    return uVar1;
  }
  uVar1 = uVar1 % param_5;
  pbVar2 = param_4 + 5;
  uVar3 = 0;
  do {
    if (param_4 == pbVar2) {
      return uVar3;
    }
    uVar4 = (uint)*param_4;
    uVar5 = uVar3 + 8;
    for (; (uVar5 & 0xff) != uVar3; uVar3 = uVar3 + 1 & 0xff) {
      if ((uVar4 & 1) != 0) {
        if (uVar1 == 0) {
          return uVar3;
        }
        uVar1 = uVar1 - 1 & 0xff;
      }
      uVar4 = uVar4 >> 1;
    }
    param_4 = param_4 + 1;
  } while( true );
}

