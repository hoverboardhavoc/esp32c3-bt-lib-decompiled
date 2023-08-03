/*
 * Last changed at upstream commit 040cd0eafd8c6ee52bc7f7d5d633c9dc1b99bba2
 * https://github.com/espressif/esp32c3-bt-lib/commit/040cd0eafd8c6ee52bc7f7d5d633c9dc1b99bba2
 * Upstream date: 2023-08-03 10:45:08 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(ff6efe7)
 * Source: libbtdm_app -> lld_cca.o -> r_lld_cca_chan_sel_remap
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

