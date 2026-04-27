/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_adv_sync_info_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_adv_sync_info_set(int param_1)

{
  byte bVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  undefined1 *puVar5;
  byte *pbVar6;
  void *__dest;
  int iVar7;
  short sVar8;
  undefined2 uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  bool bVar13;
  short sStack_2e;
  uint uStack_2c;
  undefined1 auStack_28 [4];
  byte bStack_24;
  
  iVar4 = *(int *)(&lld_adv_env + param_1 * 4);
  iVar7 = iVar4 + 0x34;
  if (*(char *)(iVar4 + 0x95) == '\0') {
    iVar7 = iVar4;
  }
  if ((((*(ushort *)(iVar4 + 0x74) & 0x13) != 0) || (*(int *)(iVar4 + 0x68) == 0)) ||
     (*(char *)(iVar4 + 0x94) != '\0')) {
    r_assert_err(0,0x10000,0x4db);
  }
  r_lld_per_adv_sync_info_get(*(undefined1 *)(iVar4 + 0x88),&uStack_2c,&sStack_2e,auStack_28);
  iVar7 = *(int *)(iVar7 + 4);
  uVar11 = uStack_2c - iVar7 & 0xfffffff;
  if (0x8000000 < uVar11) {
    uVar11 = -(iVar7 - uStack_2c & 0xfffffff);
  }
  bVar13 = false;
  uVar10 = uStack_2c;
  sVar8 = sStack_2e;
  while (iVar12 = ((int)(uVar11 * 0x271) >> 1) + (uint)*(ushort *)(iVar4 + 0x7a) * -0x1e,
        iVar12 <= *(int *)(iVar4 + 0x70) + 300) {
    uVar10 = *(int *)(iVar4 + 0x68) * 4 + uVar10 & 0xfffffff;
    uVar11 = uVar10 - iVar7 & 0xfffffff;
    if (0x8000000 < uVar11) {
      uVar11 = -(iVar7 - uVar10 & 0xfffffff);
    }
    sVar8 = sVar8 + 1;
    bVar13 = true;
  }
  if (bVar13) {
    sStack_2e = sVar8;
    uStack_2c = uVar10;
  }
  sVar8 = sStack_2e;
  if (iVar12 < 0x257ed5) {
    if (iVar12 < 0x3bfc4) {
      iVar7 = 0x1e;
    }
    else {
      iVar7 = 300;
    }
    uVar11 = iVar12 < 0x3bfc4 ^ 1;
    uVar9 = (undefined2)(iVar12 / iVar7);
  }
  else {
    uVar11 = 0;
    uVar9 = 0;
  }
  bVar1 = *(byte *)(iVar4 + 0x87);
  bStack_24 = (char)*(undefined2 *)(_p_lld_env + 0xd6) << 5 | bStack_24 & 0x1f;
  iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
  iVar12 = ((uint)bVar1 * 9 + 1 & 0xff) * 0xe;
  sVar2 = *(short *)(iVar12 + 0xc + iVar7);
  if (sVar2 == 0) {
    r_assert_err(0,0x10000,0x50a);
  }
  sVar3 = 0;
  if ((*(ushort *)(iVar4 + 0x74) & 0x20) == 0) {
    sVar3 = 6;
  }
  if ((*(ushort *)(iVar4 + 0x74) & 4) != 0) {
    sVar3 = sVar3 + 6;
  }
  iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
  if ((*(ushort *)(iVar12 + 6 + iVar7) >> 0xc & 1) == 0) {
    sVar3 = sVar3 + 2;
  }
  else {
    sVar3 = sVar3 + 5;
  }
  sVar3 = sVar3 + sVar2;
  puVar5 = (undefined1 *)r_emi_get_mem_addr_by_offset(sVar3);
  *puVar5 = (char)uVar9;
  pbVar6 = (byte *)r_emi_get_mem_addr_by_offset(sVar3 + 1);
  *pbVar6 = (byte)((ushort)uVar9 >> 8) & 0x1f | (byte)(uVar11 << 5);
  puVar5 = (undefined1 *)r_emi_get_mem_addr_by_offset(sVar3 + 0x10);
  *puVar5 = (char)sVar8;
  puVar5 = (undefined1 *)r_emi_get_mem_addr_by_offset(sVar3 + 0x11);
  *puVar5 = (char)((ushort)sVar8 >> 8);
  __dest = (void *)r_emi_get_mem_addr_by_offset(sVar3 + 4);
  memcpy(__dest,auStack_28,5);
  return;
}

