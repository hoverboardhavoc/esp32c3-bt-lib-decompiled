/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_cca.o -> r_lld_cca_lbt_handle
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_cca_lbt_handle(int param_1)

{
  byte bVar1;
  ushort uVar2;
  short sVar3;
  short sVar4;
  byte *pbVar5;
  int iVar6;
  
  iVar6 = p_lld_cca;
  uVar2 = *(ushort *)(p_lld_cca + 4);
  pbVar5 = (byte *)(*(int *)(p_lld_cca + 0x28) + (uint)*(byte *)(p_lld_cca + 8) * 0xc);
  if (((int)(uint)uVar2 >> 8 & 0xfU) == 2) {
    r_lld_cca_set_thresh(0);
    *pbVar5 = *pbVar5 & 0x7f;
  }
  else {
    r_lld_cca_set_thresh((int)*(char *)(p_lld_cca + 7));
  }
  if (uVar2 >> 0xc == 1) {
    sVar3 = *(short *)(iVar6 + 0x10);
    sVar4 = *(short *)(iVar6 + 0x14);
    bVar1 = *(byte *)(iVar6 + 0xd);
    iVar6 = r_emi_get_mem_addr_by_offset(0x400);
    *(short *)((uint)bVar1 * 0x5a + 0x20 + iVar6) = sVar3 - sVar4;
  }
  *(uint *)(pbVar5 + 4) = (rwip_prog_delay - 1) + param_1;
  *pbVar5 = *pbVar5 & 0xf5 | 0x41;
  return;
}

