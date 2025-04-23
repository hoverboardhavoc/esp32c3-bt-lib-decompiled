/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_cca.o -> r_lld_cca_chm_restore
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_cca_chm_restore(void)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  uint uVar5;
  byte *pbVar6;
  uint uVar7;
  uint uVar8;
  
  iVar3 = r_lld_read_clock();
  iVar2 = p_lld_cca;
  uVar7 = 0;
  pbVar6 = *(byte **)(p_lld_cca + 0x28);
  do {
    bVar1 = *pbVar6;
    if ((bVar1 & 4) != 0) {
      uVar8 = (uint)*(byte *)(iVar2 + 0x25) * 0x280;
      uVar5 = (uint)*(ushort *)(iVar2 + 0x12) << 1;
      if (uVar5 < uVar8) {
        uVar5 = uVar8;
      }
      if (uVar5 <= (iVar3 - *(int *)(pbVar6 + 4) & 0xfffffffU)) {
        pbVar4 = (byte *)(*(int *)(iVar2 + 0x1c) + (uVar7 >> 3));
        *pbVar4 = (byte)(1 << (uVar7 & 7)) | *pbVar4;
        *pbVar6 = bVar1 & 0xf9 | 1;
      }
    }
    uVar7 = uVar7 + 1 & 0xff;
    pbVar6 = pbVar6 + 0xc;
  } while (uVar7 != 0x28);
  return;
}

