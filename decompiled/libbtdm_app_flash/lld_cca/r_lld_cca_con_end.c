/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_cca.o -> r_lld_cca_con_end
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_cca_con_end(void)

{
  byte bVar1;
  short sVar2;
  ushort uVar3;
  byte *pbVar4;
  int iVar5;
  byte *pbVar6;
  
  sVar2 = *(short *)(p_lld_cca + 0x16);
  pbVar4 = (byte *)(*(int *)(p_lld_cca + 0x28) + (uint)*(byte *)(p_lld_cca + 8) * 0xc);
  iVar5 = p_lld_cca;
  if (sVar2 != 0) {
    bVar1 = *(byte *)(p_lld_cca + 0xd);
    iVar5 = r_emi_get_mem_addr_by_offset(0x400);
    *(short *)((uint)bVar1 * 0x5a + 0x20 + iVar5) = sVar2;
    iVar5 = p_lld_cca;
    *(undefined2 *)(p_lld_cca + 0x16) = 0;
  }
  if ((*pbVar4 & 0x10) != 0) {
    r_lld_cca_force_tx(0);
    *pbVar4 = *pbVar4 & 0xef;
  }
  uVar3 = *(ushort *)(iVar5 + 4);
  if ((uVar3 & 0x10) == 0) {
    if (((uVar3 & 2) == 0) || ((*pbVar4 & 0x20) == 0)) {
      if ((*pbVar4 & 8) == 0) {
        if ((uVar3 & 1) != 0) {
          r_lld_cca_chan_rssi_cal(pbVar4);
        }
        if ((*pbVar4 & 2) != 0) {
          *pbVar4 = *pbVar4 & 0xfe | 8;
          pbVar4[8] = pbVar4[8] + 1;
        }
        if ((*(ushort *)(iVar5 + 4) & 4) != 0) {
          if (pbVar4[8] == *(byte *)(p_lld_cca + 0x1a)) {
            pbVar6 = (byte *)(*(int *)(p_lld_cca + 0x1c) + (uint)(*(byte *)(p_lld_cca + 8) >> 3));
            *pbVar6 = ~(byte)(1 << (*(byte *)(p_lld_cca + 8) & 7)) & *pbVar6;
            pbVar4[8] = 0;
            *pbVar4 = *pbVar4 | 4;
          }
          return;
        }
      }
    }
    else {
      r_lld_cca_set_thresh(0);
      *pbVar4 = *pbVar4 & 0xdf;
    }
  }
  return;
}

