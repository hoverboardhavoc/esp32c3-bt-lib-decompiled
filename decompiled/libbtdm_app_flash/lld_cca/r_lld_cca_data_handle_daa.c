/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_cca.o -> r_lld_cca_data_handle_daa
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_cca_data_handle_daa(int param_1,int param_2)

{
  int iVar1;
  byte *pbVar2;
  byte bVar3;
  
  iVar1 = p_lld_cca;
  pbVar2 = (byte *)(*(int *)(p_lld_cca + 0x28) + param_2 * 0xc);
  bVar3 = *pbVar2;
  if ((((*(ushort *)(p_lld_cca + 4) & 2) == 0) || ((bVar3 & 0x20) == 0)) && ((bVar3 & 0xc) == 0)) {
    if ((*(ushort *)(p_lld_cca + 4) & 1) != 0) {
      *(short *)(p_lld_cca + 10) = *(short *)(p_lld_cca + 10) + (short)param_1;
      *(char *)(iVar1 + 0xc) = *(char *)(iVar1 + 0xc) + '\x01';
      return;
    }
    pbVar2[1] = (byte)param_1;
    if (*(char *)(iVar1 + 7) < param_1) {
      bVar3 = bVar3 | 2;
    }
    else {
      pbVar2[8] = 0;
      bVar3 = bVar3 & 0xfd | 9;
    }
    *pbVar2 = bVar3;
  }
  return;
}

