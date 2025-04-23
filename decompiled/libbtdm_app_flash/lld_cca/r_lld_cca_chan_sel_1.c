/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_cca.o -> r_lld_cca_chan_sel_1
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_cca_chan_sel_1(int param_1,int param_2,int param_3,byte *param_4,uint param_5)

{
  char cVar1;
  char cVar2;
  uint uVar3;
  byte *pbVar4;
  
  uVar3 = ((param_3 + 1) * param_2 + param_1) % 0x25;
  if (((int)(uint)param_4[uVar3 >> 3] >> (uVar3 & 7) & 1U) != 0) {
    return;
  }
  param_5 = (uVar3 & 0xff) % param_5;
  pbVar4 = param_4 + 5;
  cVar1 = '\0';
  do {
    uVar3 = (uint)*param_4;
    cVar2 = cVar1 + '\b';
    do {
      if ((uVar3 & 1) != 0) {
        if (param_5 == 0) {
          return;
        }
        param_5 = param_5 - 1 & 0xff;
      }
      cVar1 = cVar1 + '\x01';
      uVar3 = uVar3 >> 1;
    } while (cVar2 != cVar1);
    param_4 = param_4 + 1;
  } while (pbVar4 != param_4);
  return;
}

