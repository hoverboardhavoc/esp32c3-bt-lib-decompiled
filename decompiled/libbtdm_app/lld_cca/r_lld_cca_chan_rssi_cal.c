/*
 * Last changed at upstream commit 040cd0eafd8c6ee52bc7f7d5d633c9dc1b99bba2
 * https://github.com/espressif/esp32c3-bt-lib/commit/040cd0eafd8c6ee52bc7f7d5d633c9dc1b99bba2
 * Upstream date: 2023-08-03 10:45:08 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(ff6efe7)
 * Source: libbtdm_app -> lld_cca.o -> r_lld_cca_chan_rssi_cal
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_cca_chan_rssi_cal(byte *param_1)

{
  int iVar1;
  byte bVar2;
  
  iVar1 = p_lld_cca;
  if ((*(short *)(p_lld_cca + 10) != 0) && (*(byte *)(p_lld_cca + 0xc) != 0)) {
    bVar2 = (byte)((int)*(short *)(p_lld_cca + 10) / (int)(uint)*(byte *)(p_lld_cca + 0xc));
    param_1[1] = bVar2;
    *(undefined2 *)(iVar1 + 10) = 0;
    *(undefined1 *)(iVar1 + 0xc) = 0;
    if (*(char *)(iVar1 + 7) < (char)bVar2) {
      bVar2 = *param_1 | 2;
    }
    else {
      param_1[8] = 0;
      bVar2 = *param_1 & 0xfd | 9;
    }
    *param_1 = bVar2;
  }
  return;
}

