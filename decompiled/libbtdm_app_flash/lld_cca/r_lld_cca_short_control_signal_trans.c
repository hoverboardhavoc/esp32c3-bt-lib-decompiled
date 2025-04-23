/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_cca.o -> r_lld_cca_short_control_signal_trans
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_cca_short_control_signal_trans(int param_1)

{
  byte bVar1;
  ushort uVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  iVar5 = p_lld_cca;
  if (param_1 != 0) {
    uVar6 = *(ushort *)(p_lld_cca + 0xe) / 10;
    uVar2 = *(ushort *)(p_lld_cca + 0x14);
    if (uVar2 < uVar6) {
      bVar1 = *(byte *)(p_lld_cca + 0xd);
      iVar4 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar5 + 0x16) = *(undefined2 *)((uint)bVar1 * 0x5a + 0x20 + iVar4);
      bVar1 = *(byte *)(p_lld_cca + 0xd);
      iVar5 = r_emi_get_mem_addr_by_offset(0x400);
      *(short *)((uint)bVar1 * 0x5a + 0x20 + iVar5) = (short)((uVar6 - uVar2) * 0x10000 >> 0x10);
    }
    else {
      pbVar3 = (byte *)(*(int *)(p_lld_cca + 0x28) + (uint)*(byte *)(p_lld_cca + 8) * 0xc);
      r_lld_cca_force_tx(1);
      *pbVar3 = *pbVar3 | 0x10;
    }
    return;
  }
  return;
}

