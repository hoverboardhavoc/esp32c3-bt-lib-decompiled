/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  undefined1 *puVar4;
  byte *pbVar5;
  void *__dest;
  int iVar6;
  short sVar7;
  undefined2 uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  bool bVar12;
  ushort uVar13;
  int iVar14;
  short sStack_2e;
  uint uStack_2c;
  undefined1 auStack_28 [4];
  byte bStack_24;
  
  iVar14 = *(int *)(&lld_adv_env + param_1 * 4);
  iVar6 = iVar14 + 0x34;
  if (*(char *)(iVar14 + 0x95) == '\0') {
    iVar6 = iVar14;
  }
  if ((((*(ushort *)(iVar14 + 0x74) & 0x13) != 0) || (*(int *)(iVar14 + 0x68) == 0)) ||
     (*(char *)(iVar14 + 0x94) != '\0')) {
    r_assert_err(0,0x10000,0x4a1);
  }
  r_lld_per_adv_sync_info_get(*(undefined1 *)(iVar14 + 0x88),&uStack_2c,&sStack_2e,auStack_28);
  iVar6 = *(int *)(iVar6 + 4);
  uVar10 = uStack_2c - iVar6 & 0xfffffff;
  if (0x8000000 < uVar10) {
    uVar10 = -(iVar6 - uStack_2c & 0xfffffff);
  }
  bVar12 = false;
  uVar9 = uStack_2c;
  sVar7 = sStack_2e;
  while (iVar11 = ((int)(uVar10 * 0x271) >> 1) + (uint)*(ushort *)(iVar14 + 0x7a) * -0x1e,
        iVar11 <= *(int *)(iVar14 + 0x70) + 300) {
    uVar9 = *(int *)(iVar14 + 0x68) * 4 + uVar9 & 0xfffffff;
    uVar10 = uVar9 - iVar6 & 0xfffffff;
    if (0x8000000 < uVar10) {
      uVar10 = -(iVar6 - uVar9 & 0xfffffff);
    }
    sVar7 = sVar7 + 1;
    bVar12 = true;
  }
  if (bVar12) {
    sStack_2e = sVar7;
    uStack_2c = uVar9;
  }
  sVar7 = sStack_2e;
  if (iVar11 < 0x257ed5) {
    if (iVar11 < 0x3bfc4) {
      iVar6 = 0x1e;
    }
    else {
      iVar6 = 300;
    }
    uVar10 = (uint)(0x3bfc3 < iVar11);
    uVar8 = (undefined2)(iVar11 / iVar6);
  }
  else {
    uVar10 = 0;
    uVar8 = 0;
  }
  bVar1 = *(byte *)(iVar14 + 0x87);
  bStack_24 = (char)*(undefined2 *)(_p_lld_env + 0xd6) << 5 | bStack_24 & 0x1f;
  iVar11 = r_emi_get_mem_addr_by_offset(0x1400);
  iVar6 = ((uint)bVar1 * 9 + 1 & 0xff) * 0xe;
  sVar2 = *(short *)(iVar6 + 0xc + iVar11);
  if (sVar2 == 0) {
    r_assert_err(0,0x10000,0x4d0);
  }
  uVar13 = -(ushort)((*(ushort *)(iVar14 + 0x74) & 0x20) == 0) & 6;
  if ((*(ushort *)(iVar14 + 0x74) & 4) != 0) {
    uVar13 = uVar13 + 6;
  }
  iVar14 = r_emi_get_mem_addr_by_offset(0x1400);
  sVar3 = uVar13 + 5;
  if (-1 < (int)((uint)*(ushort *)(iVar6 + 6 + iVar14) << 0x13)) {
    sVar3 = uVar13 + 2;
  }
  sVar3 = sVar3 + sVar2;
  puVar4 = (undefined1 *)r_emi_get_mem_addr_by_offset(sVar3);
  *puVar4 = (char)uVar8;
  pbVar5 = (byte *)r_emi_get_mem_addr_by_offset(sVar3 + 1);
  *pbVar5 = (byte)((ushort)uVar8 >> 8) & 0x1f | (byte)(uVar10 << 5);
  puVar4 = (undefined1 *)r_emi_get_mem_addr_by_offset(sVar3 + 0x10);
  *puVar4 = (char)sVar7;
  puVar4 = (undefined1 *)r_emi_get_mem_addr_by_offset(sVar3 + 0x11);
  *puVar4 = (char)((ushort)sVar7 >> 8);
  __dest = (void *)r_emi_get_mem_addr_by_offset(sVar3 + 4);
  memcpy(__dest,auStack_28,5);
  return;
}

