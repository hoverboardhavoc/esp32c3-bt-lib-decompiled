/*
 * Last changed at upstream commit 040cd0eafd8c6ee52bc7f7d5d633c9dc1b99bba2
 * https://github.com/espressif/esp32c3-bt-lib/commit/040cd0eafd8c6ee52bc7f7d5d633c9dc1b99bba2
 * Upstream date: 2023-08-03 10:45:08 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(ff6efe7)
 * Source: libbtdm_app -> lld_cca.o -> r_lld_cca_data_handle_daa
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_cca_data_handle_daa(int param_1,int param_2)

{
  char *pcVar1;
  int iVar2;
  byte *pbVar3;
  byte bVar4;
  
  iVar2 = p_lld_cca;
  pbVar3 = (byte *)(param_2 * 0xc + *(int *)(p_lld_cca + 0x28));
  bVar4 = *pbVar3;
  if ((((*(ushort *)(p_lld_cca + 4) & 2) == 0) || ((bVar4 & 0x20) == 0)) && ((bVar4 & 0xc) == 0)) {
    if ((*(ushort *)(p_lld_cca + 4) & 1) != 0) {
      pcVar1 = (char *)(p_lld_cca + 0xc);
      *(short *)(p_lld_cca + 10) = (short)param_1 + *(short *)(p_lld_cca + 10);
      *(char *)(iVar2 + 0xc) = *pcVar1 + '\x01';
      return;
    }
    pbVar3[1] = (byte)param_1;
    if (*(char *)(iVar2 + 7) < param_1) {
      bVar4 = bVar4 | 2;
    }
    else {
      pbVar3[8] = 0;
      bVar4 = bVar4 & 0xfd | 9;
    }
    *pbVar3 = bVar4;
  }
  return;
}

