/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld_cca.o -> r_lld_cca_sw_handle
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_cca_sw_handle(int param_1,uint param_2,int param_3)

{
  int iVar1;
  byte *pbVar2;
  int iVar3;
  byte *pbVar4;
  byte bVar5;
  
  if ((byte)ble_2_rf_chan_tab[*(byte *)(p_lld_cca + 8)] == param_2) {
    iVar3 = r_lld_read_clock();
    iVar1 = p_lld_cca;
    pbVar2 = (byte *)(*(int *)(p_lld_cca + 0x28) + (uint)*(byte *)(p_lld_cca + 8) * 0xc);
    if ((0x7fffffe < (iVar3 - *(int *)(pbVar2 + 4) & 0xfffffffU)) && (param_3 == 0)) {
      pbVar2[1] = (byte)param_1;
      iVar3 = (int)*(char *)(iVar1 + 7);
      if ((*(ushort *)(iVar1 + 4) & 0x10) == 0) {
        if (iVar3 < param_1) {
          r_lld_cca_set_thresh(0xffffff88);
          *pbVar2 = *pbVar2 | 0x20;
          pbVar2[8] = pbVar2[8] + 1;
          if ((*(ushort *)(p_lld_cca + 4) & 4) != 0) {
            if (pbVar2[8] == *(byte *)(p_lld_cca + 0x1a)) {
              pbVar4 = (byte *)(*(int *)(p_lld_cca + 0x1c) + (uint)(*(byte *)(p_lld_cca + 8) >> 3));
              *pbVar4 = ~(byte)(1 << (*(byte *)(p_lld_cca + 8) & 7)) & *pbVar4;
              pbVar2[8] = 0;
              *pbVar2 = *pbVar2 | 4;
            }
            return;
          }
        }
        else {
          pbVar2[8] = 0;
          *pbVar2 = *pbVar2 & 0xdf;
        }
      }
      else {
        if (iVar3 < param_1) {
          r_lld_cca_chan_handle(1);
          bVar5 = *pbVar2 | 8;
        }
        else {
          r_lld_cca_chan_handle(0);
          bVar5 = *pbVar2 & 0xf5;
        }
        *pbVar2 = bVar5;
      }
    }
  }
  return;
}

