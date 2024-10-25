/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld_cca.o -> r_lld_cca_chan_rssi_cal
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

