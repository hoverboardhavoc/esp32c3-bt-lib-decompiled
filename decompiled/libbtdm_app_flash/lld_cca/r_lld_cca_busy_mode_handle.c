/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_cca.o -> r_lld_cca_busy_mode_handle
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_cca_busy_mode_handle(int param_1)

{
  byte bVar1;
  short sVar2;
  ushort uVar3;
  byte *pbVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  
  iVar6 = p_lld_cca;
  uVar7 = (int)(uint)*(ushort *)(p_lld_cca + 4) >> 8 & 0xf;
  if (uVar7 == 1) {
    if (param_1 == 0) {
      sVar2 = *(short *)(p_lld_cca + 0x18);
      if (sVar2 != 0) {
        bVar1 = *(byte *)(p_lld_cca + 0xd);
        iVar5 = r_emi_get_mem_addr_by_offset(0x400);
        iVar6 = p_lld_cca;
        *(short *)((uint)bVar1 * 0x5a + 0x1c + iVar5) = sVar2;
        *(undefined2 *)(iVar6 + 0x18) = 0;
      }
    }
    else {
      bVar1 = *(byte *)(p_lld_cca + 0xd);
      iVar5 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar6 + 0x18) = *(undefined2 *)((uint)bVar1 * 0x5a + 0x1c + iVar5);
      bVar1 = *(byte *)(p_lld_cca + 0xd);
      iVar6 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)((uint)bVar1 * 0x5a + 0x1c + iVar6) = 0;
    }
    return;
  }
  if (uVar7 == 2) {
    if (param_1 == 0) {
      return;
    }
    uVar7 = *(ushort *)(p_lld_cca + 0xe) / 10;
    uVar3 = *(ushort *)(p_lld_cca + 0x14);
    if (uVar3 < uVar7) {
      bVar1 = *(byte *)(p_lld_cca + 0xd);
      iVar5 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar6 + 0x16) = *(undefined2 *)((uint)bVar1 * 0x5a + 0x20 + iVar5);
      bVar1 = *(byte *)(p_lld_cca + 0xd);
      iVar6 = r_emi_get_mem_addr_by_offset(0x400);
      *(short *)((uint)bVar1 * 0x5a + 0x20 + iVar6) = (short)((uVar7 - uVar3) * 0x10000 >> 0x10);
    }
    else {
      pbVar4 = (byte *)(*(int *)(p_lld_cca + 0x28) + (uint)*(byte *)(p_lld_cca + 8) * 0xc);
      r_lld_cca_force_tx(1);
      *pbVar4 = *pbVar4 | 0x10;
    }
    return;
  }
  if (uVar7 != 0) {
    r_assert_err(0,"lld_cca.c",0x18a);
    return;
  }
  uVar7 = 0xffffff88;
  if (param_1 == 0) {
    uVar7 = 0;
  }
  _DAT_600110b8 = (uVar7 & 0xff) << 1 | _DAT_600110b8 & 0xfffffe01;
  return;
}

