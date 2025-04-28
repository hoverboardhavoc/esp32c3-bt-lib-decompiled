/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
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
  int iVar4;
  byte *pbVar5;
  int iVar6;
  byte *pbVar7;
  
  sVar2 = *(short *)(p_lld_cca + 0x16);
  pbVar5 = (byte *)(*(int *)(p_lld_cca + 0x28) + (uint)*(byte *)(p_lld_cca + 8) * 0xc);
  if (sVar2 != 0) {
    bVar1 = *(byte *)(p_lld_cca + 0xd);
    iVar6 = r_emi_get_mem_addr_by_offset(0x400);
    iVar4 = p_lld_cca;
    *(short *)((uint)bVar1 * 0x5a + 0x20 + iVar6) = sVar2;
    *(undefined2 *)(iVar4 + 0x16) = 0;
  }
  if ((*pbVar5 & 0x10) != 0) {
    r_lld_cca_force_tx(0);
    *pbVar5 = *pbVar5 & 0xef;
  }
  iVar4 = p_lld_cca;
  uVar3 = *(ushort *)(p_lld_cca + 4);
  if ((uVar3 & 0x10) == 0) {
    if (((uVar3 & 2) == 0) || ((*pbVar5 & 0x20) == 0)) {
      if ((*pbVar5 & 8) == 0) {
        if ((uVar3 & 1) != 0) {
          r_lld_cca_chan_rssi_cal(pbVar5);
        }
        if ((*pbVar5 & 2) != 0) {
          *pbVar5 = *pbVar5 & 0xfe | 8;
          pbVar5[8] = pbVar5[8] + 1;
        }
        if ((*(ushort *)(iVar4 + 4) & 4) != 0) {
          if (pbVar5[8] == *(byte *)(p_lld_cca + 0x1a)) {
            pbVar7 = (byte *)(*(int *)(p_lld_cca + 0x1c) + (uint)(*(byte *)(p_lld_cca + 8) >> 3));
            *pbVar7 = ~(byte)(1 << (*(byte *)(p_lld_cca + 8) & 7)) & *pbVar7;
            pbVar5[8] = 0;
            *pbVar5 = *pbVar5 | 4;
          }
          return;
        }
      }
    }
    else {
      r_lld_cca_set_thresh(0);
      *pbVar5 = *pbVar5 & 0xdf;
    }
  }
  return;
}

