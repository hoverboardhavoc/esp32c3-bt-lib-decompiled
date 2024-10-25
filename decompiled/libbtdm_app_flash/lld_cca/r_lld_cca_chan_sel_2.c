/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld_cca.o -> r_lld_cca_chan_sel_2
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint r_lld_cca_chan_sel_2(byte *param_1,int param_2)

{
  uint uVar1;
  byte *pbVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar1 = r_lld_cca_chan_prn_e();
  uVar5 = uVar1 % 0x25;
  if (((int)(uint)param_1[uVar5 >> 3] >> (uVar5 & 7) & 1U) != 0) {
    return uVar5;
  }
  uVar1 = param_2 * uVar1 >> 0x10 & 0xff;
  pbVar2 = param_1 + 5;
  uVar5 = 0;
  do {
    if (param_1 == pbVar2) {
      return uVar5;
    }
    uVar3 = (uint)*param_1;
    uVar4 = uVar5 + 8;
    for (; (uVar4 & 0xff) != uVar5; uVar5 = uVar5 + 1 & 0xff) {
      if ((uVar3 & 1) != 0) {
        if (uVar1 == 0) {
          return uVar5;
        }
        uVar1 = uVar1 - 1 & 0xff;
      }
      uVar3 = uVar3 >> 1;
    }
    param_1 = param_1 + 1;
  } while( true );
}

