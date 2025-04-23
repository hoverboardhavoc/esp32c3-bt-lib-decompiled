/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_cca.o -> r_lld_cca_sw_handle
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_cca_sw_handle(int param_1,uint param_2,int param_3)

{
  ushort uVar1;
  byte *pbVar2;
  int iVar3;
  byte *pbVar4;
  byte bVar5;
  int iVar6;
  
  if ((byte)ble_2_rf_chan_tab[*(byte *)(p_lld_cca + 8)] == param_2) {
    iVar3 = r_lld_read_clock();
    iVar6 = p_lld_cca;
    pbVar2 = (byte *)(*(int *)(p_lld_cca + 0x28) + (uint)*(byte *)(p_lld_cca + 8) * 0xc);
    if ((0x7fffffe < (iVar3 - *(int *)(pbVar2 + 4) & 0xfffffffU)) && (param_3 == 0)) {
      pbVar2[1] = (byte)param_1;
      uVar1 = *(ushort *)(iVar6 + 4);
      iVar6 = (int)*(char *)(iVar6 + 7);
      if ((uVar1 & 0x10) == 0) {
        if (iVar6 < param_1) {
          r_lld_cca_set_thresh(0xffffff88);
          *pbVar2 = *pbVar2 | 0x20;
          pbVar2[8] = pbVar2[8] + 1;
          if ((uVar1 & 4) != 0) {
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
        if (iVar6 < param_1) {
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

