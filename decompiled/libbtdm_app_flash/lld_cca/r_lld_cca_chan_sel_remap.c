/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld_cca.o -> r_lld_cca_chan_sel_remap
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

char r_lld_cca_chan_sel_remap(byte *param_1,uint param_2)

{
  byte *pbVar1;
  uint uVar2;
  char cVar3;
  char cVar4;
  
  pbVar1 = param_1 + 5;
  cVar4 = '\0';
  do {
    if (param_1 == pbVar1) {
      return cVar4;
    }
    uVar2 = (uint)*param_1;
    cVar3 = cVar4 + '\b';
    for (; cVar3 != cVar4; cVar4 = cVar4 + '\x01') {
      if ((uVar2 & 1) != 0) {
        if (param_2 == 0) {
          return cVar4;
        }
        param_2 = param_2 - 1 & 0xff;
      }
      uVar2 = uVar2 >> 1;
    }
    param_1 = param_1 + 1;
  } while( true );
}

