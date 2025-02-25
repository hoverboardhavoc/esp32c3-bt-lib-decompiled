/*
 * Last changed at upstream commit 2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * https://github.com/espressif/esp32c3-bt-lib/commit/2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * Upstream date: 2025-02-25 15:16:47 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(723439d)
 * Source: libbtdm_app_flash -> lld_per_adv.o -> r_lld_per_adv_evt_start_chm_upd
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_per_adv_evt_start_chm_upd(int param_1)

{
  byte bVar1;
  short sVar2;
  ushort uVar3;
  undefined2 uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  undefined1 *puVar8;
  void *__dest;
  char cVar9;
  int iVar11;
  byte bVar10;
  
  bVar10 = *(byte *)(param_1 + 0x52);
  uVar5 = (uint)bVar10 * 9 & 0xff;
  if (*(char *)(param_1 + 0x3c) == '\0') {
    if ((*(char *)(param_1 + 0x3d) != '\0') &&
       ((ushort)(*(short *)(param_1 + 0x4c) - *(short *)(param_1 + 0x3a)) < 0x7fff)) {
      uVar4 = *(undefined2 *)(param_1 + 0x34);
      iVar6 = r_emi_get_mem_addr_by_offset(0x400);
      iVar7 = (uint)bVar10 * 0x5a;
      *(undefined2 *)(iVar6 + iVar7 + 0x22) = uVar4;
      uVar4 = *(undefined2 *)(param_1 + 0x36);
      iVar6 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar6 + iVar7 + 0x24) = uVar4;
      bVar10 = *(byte *)(param_1 + 0x38);
      iVar6 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar7 + 0x26 + iVar6) = (ushort)bVar10;
      memcpy((void *)(param_1 + 0x2f),(void *)(param_1 + 0x34),5);
      bVar10 = *(byte *)(param_1 + 0x5a);
      *(undefined1 *)(param_1 + 0x3d) = 0;
      if ((bVar10 & 0xc0) != 0) {
        r_assert_err(0,"lld_per_adv.c",0x27d);
      }
      iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
      iVar6 = uVar5 * 0xe;
      iVar11 = iVar6 + 6;
      uVar3 = *(ushort *)(iVar7 + iVar11);
      iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
      *(ushort *)(iVar7 + iVar11) = uVar3 & 0xffc0 | (ushort)bVar10;
      bVar10 = *(byte *)(param_1 + 0x5a);
      bVar1 = *(byte *)(param_1 + 0x5b);
      iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
      iVar6 = iVar6 + 2;
      uVar3 = *(ushort *)(iVar7 + iVar6);
      iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
      *(ushort *)(iVar6 + iVar7) =
           uVar3 & 0xff | (ushort)(((uint)bVar1 + (uint)bVar10 + 1 & 0xff) << 8);
    }
  }
  else {
    iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
    iVar6 = uVar5 * 0xe;
    sVar2 = *(short *)(iVar7 + iVar6 + 0xc);
    if (sVar2 == 0) {
      r_assert_err(0,"lld_per_adv.c",0x303);
    }
    iVar7 = *(ushort *)(param_1 + 0x4c) + 10;
    iVar11 = iVar7 * 0x10000;
    *(short *)(param_1 + 0x3a) = (short)((uint)iVar11 >> 0x10);
    puVar8 = (undefined1 *)r_emi_get_mem_addr_by_offset(*(byte *)(param_1 + 0x59) + 7 + sVar2);
    *puVar8 = (char)((uint)iVar11 >> 0x10);
    puVar8 = (undefined1 *)r_emi_get_mem_addr_by_offset(*(byte *)(param_1 + 0x59) + 8 + sVar2);
    *puVar8 = (char)((uint)iVar7 >> 8);
    __dest = (void *)r_emi_get_mem_addr_by_offset(*(byte *)(param_1 + 0x59) + 2 + sVar2);
    memcpy(__dest,(void *)(param_1 + 0x34),5);
    cVar9 = *(char *)(param_1 + 0x5a);
    if (cVar9 == '\0') {
      cVar9 = '\x01';
    }
    bVar10 = cVar9 + 9;
    if ((bVar10 & 0xc0) != 0) {
      r_assert_err(0,"lld_per_adv.c",0x27d);
    }
    iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
    uVar3 = *(ushort *)(iVar7 + iVar6 + 6);
    iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
    *(ushort *)(iVar7 + iVar6 + 6) = uVar3 & 0xffc0 | (ushort)bVar10;
    bVar1 = *(byte *)(param_1 + 0x5b);
    iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
    uVar3 = *(ushort *)(iVar7 + iVar6 + 2);
    iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
    *(ushort *)(iVar6 + 2 + iVar7) = uVar3 & 0xff | (ushort)(((uint)bVar10 + bVar1 + 1 & 0xff) << 8)
    ;
    *(undefined2 *)(param_1 + 0x3c) = 0x100;
  }
  return;
}

