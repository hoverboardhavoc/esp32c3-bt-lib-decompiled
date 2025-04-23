/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_cca.o -> r_lld_cca_idle_mode_handle
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_cca_idle_mode_handle(int param_1)

{
  byte bVar1;
  ushort uVar2;
  short sVar3;
  int iVar4;
  uint uVar5;
  
  if (param_1 != 0) {
    return;
  }
  uVar5 = (uint)*(ushort *)(p_lld_cca + 0xe);
  if (*(ushort *)(p_lld_cca + 0x10) < uVar5) {
    uVar2 = *(ushort *)(p_lld_cca + 4) >> 0xc;
    if (uVar2 == 1) {
      bVar1 = *(byte *)(p_lld_cca + 0xd);
      sVar3 = *(ushort *)(p_lld_cca + 0x10) - *(short *)(p_lld_cca + 0x14);
    }
    else {
      if (uVar2 != 2) {
        return;
      }
      bVar1 = *(byte *)(p_lld_cca + 0xd);
      sVar3 = (short)(((uVar5 - *(ushort *)(p_lld_cca + 0x14)) + (int)uVar5 / -0x14) * 0x10000 >>
                     0x10);
    }
    iVar4 = r_emi_get_mem_addr_by_offset(0x400);
    *(short *)((uint)bVar1 * 0x5a + 0x20 + iVar4) = sVar3;
    return;
  }
  return;
}

