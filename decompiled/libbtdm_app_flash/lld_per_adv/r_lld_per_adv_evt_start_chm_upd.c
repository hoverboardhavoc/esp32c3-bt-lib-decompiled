/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_per_adv.o -> r_lld_per_adv_evt_start_chm_upd
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_per_adv_evt_start_chm_upd(int param_1)

{
  byte bVar1;
  byte bVar2;
  short sVar3;
  ushort uVar4;
  undefined2 uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  undefined1 *puVar9;
  void *__dest;
  int iVar10;
  
  bVar1 = *(byte *)(param_1 + 0x52);
  uVar6 = (uint)bVar1 * 9 & 0xff;
  if (*(char *)(param_1 + 0x3c) == '\0') {
    if ((*(char *)(param_1 + 0x3d) != '\0') &&
       ((ushort)(*(short *)(param_1 + 0x4c) - *(short *)(param_1 + 0x3a)) < 0x7fff)) {
      uVar5 = *(undefined2 *)(param_1 + 0x34);
      iVar7 = r_emi_get_mem_addr_by_offset(0x400);
      iVar8 = (uint)bVar1 * 0x5a;
      *(undefined2 *)(iVar8 + 0x22 + iVar7) = uVar5;
      uVar5 = *(undefined2 *)(param_1 + 0x36);
      iVar7 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar8 + 0x24 + iVar7) = uVar5;
      bVar1 = *(byte *)(param_1 + 0x38);
      iVar7 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar8 + 0x26 + iVar7) = (ushort)bVar1;
      memcpy((void *)(param_1 + 0x2f),(void *)(param_1 + 0x34),5);
      bVar1 = *(byte *)(param_1 + 0x5a);
      *(undefined1 *)(param_1 + 0x3d) = 0;
      if (0x3f < bVar1) {
        r_assert_err(0,0x10000,0x27d);
      }
      iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
      iVar7 = uVar6 * 0xe;
      iVar10 = iVar7 + 6;
      uVar4 = *(ushort *)(iVar8 + iVar10);
      iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
      *(ushort *)(iVar8 + iVar10) = (ushort)bVar1 | uVar4 & 0xffc0;
      bVar1 = *(byte *)(param_1 + 0x5a);
      bVar2 = *(byte *)(param_1 + 0x5b);
      iVar7 = iVar7 + 2;
      iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
      uVar4 = *(ushort *)(iVar8 + iVar7);
      iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
      *(ushort *)(iVar8 + iVar7) =
           uVar4 & 0xff | (ushort)(((uint)bVar1 + (uint)bVar2 + 1 & 0xff) << 8);
    }
  }
  else {
    iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
    iVar7 = uVar6 * 0xe;
    sVar3 = *(short *)(iVar7 + 0xc + iVar8);
    if (sVar3 == 0) {
      r_assert_err(0,0x10000,0x303);
    }
    iVar8 = *(ushort *)(param_1 + 0x4c) + 10;
    iVar10 = iVar8 * 0x10000;
    *(short *)(param_1 + 0x3a) = (short)((uint)iVar10 >> 0x10);
    puVar9 = (undefined1 *)r_emi_get_mem_addr_by_offset(*(byte *)(param_1 + 0x59) + 7 + sVar3);
    *puVar9 = (char)((uint)iVar10 >> 0x10);
    puVar9 = (undefined1 *)r_emi_get_mem_addr_by_offset(*(byte *)(param_1 + 0x59) + 8 + sVar3);
    *puVar9 = (char)((uint)iVar8 >> 8);
    uVar6 = 10;
    __dest = (void *)r_emi_get_mem_addr_by_offset(sVar3 + *(byte *)(param_1 + 0x59) + 2);
    memcpy(__dest,(void *)(param_1 + 0x34),5);
    if ((*(char *)(param_1 + 0x5a) != '\0') &&
       (uVar6 = (uint)(byte)(*(char *)(param_1 + 0x5a) + 9), 0x3f < uVar6)) {
      r_assert_err(0,0x10000,0x27d);
    }
    iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
    uVar4 = *(ushort *)(iVar8 + iVar7 + 6);
    iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
    *(ushort *)(iVar8 + iVar7 + 6) = (ushort)uVar6 | uVar4 & 0xffc0;
    bVar1 = *(byte *)(param_1 + 0x5b);
    iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
    uVar4 = *(ushort *)(iVar8 + iVar7 + 2);
    iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
    *(ushort *)(iVar8 + iVar7 + 2) = uVar4 & 0xff | (ushort)((uVar6 + bVar1 + 1 & 0xff) << 8);
    *(undefined2 *)(param_1 + 0x3c) = 0x100;
  }
  return;
}

