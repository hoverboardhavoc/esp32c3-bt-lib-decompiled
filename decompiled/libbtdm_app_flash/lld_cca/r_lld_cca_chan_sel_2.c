/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_cca.o -> r_lld_cca_chan_sel_2
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_cca_chan_sel_2(byte *param_1,int param_2)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char cVar4;
  byte *pbVar5;
  
  uVar2 = r_lld_cca_chan_prn_e();
  if (((int)(uint)param_1[uVar2 % 0x25 >> 3] >> (uVar2 % 0x25 & 7) & 1U) != 0) {
    return;
  }
  uVar2 = param_2 * uVar2 >> 0x10 & 0xff;
  pbVar5 = param_1 + 5;
  cVar1 = '\0';
  do {
    if (param_1 == pbVar5) {
      return;
    }
    uVar3 = (uint)*param_1;
    cVar4 = cVar1 + '\b';
    for (; cVar4 != cVar1; cVar1 = cVar1 + '\x01') {
      if ((uVar3 & 1) != 0) {
        if (uVar2 == 0) {
          return;
        }
        uVar2 = uVar2 - 1 & 0xff;
      }
      uVar3 = uVar3 >> 1;
    }
    param_1 = param_1 + 1;
  } while( true );
}

