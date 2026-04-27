/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app -> lld_adv.o -> r_lld_adv_sync_info_set
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
  int iVar5;
  undefined1 *puVar6;
  byte *pbVar7;
  void *__dest;
  uint uVar8;
  short sVar9;
  undefined2 uVar10;
  uint uVar11;
  int iVar12;
  bool bVar13;
  short sStack_3e;
  uint local_3c;
  undefined1 auStack_38 [4];
  byte bStack_34;
  
  iVar4 = *(int *)(&lld_adv_env + param_1 * 4);
  iVar5 = iVar4 + 0x34;
  if (*(char *)(iVar4 + 0x95) == '\0') {
    iVar5 = iVar4;
  }
  if ((((*(ushort *)(iVar4 + 0x74) & 0x13) != 0) || (*(int *)(iVar4 + 0x68) == 0)) ||
     (*(char *)(iVar4 + 0x94) != '\0')) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x4db,*(code **)(_r_plf_funcs_p + 8));
  }
  (**(code **)(_r_ip_funcs_p + 0x310))
            (*(undefined1 *)(iVar4 + 0x88),&local_3c,&sStack_3e,auStack_38,
             *(code **)(_r_ip_funcs_p + 0x310));
  iVar5 = *(int *)(iVar5 + 4);
  uVar11 = local_3c - iVar5 & 0xfffffff;
  if (0x8000000 < uVar11) {
    uVar11 = -(iVar5 - local_3c & 0xfffffff);
  }
  bVar13 = false;
  uVar8 = local_3c;
  sVar9 = sStack_3e;
  while (iVar12 = ((int)(uVar11 * 0x271) >> 1) + (uint)*(ushort *)(iVar4 + 0x7a) * -0x1e,
        iVar12 <= *(int *)(iVar4 + 0x70) + 300) {
    uVar8 = *(int *)(iVar4 + 0x68) * 4 + uVar8 & 0xfffffff;
    uVar11 = uVar8 - iVar5 & 0xfffffff;
    if (0x8000000 < uVar11) {
      uVar11 = -(iVar5 - uVar8 & 0xfffffff);
    }
    sVar9 = sVar9 + 1;
    bVar13 = true;
  }
  if (bVar13) {
    sStack_3e = sVar9;
    local_3c = uVar8;
  }
  sVar9 = sStack_3e;
  if (iVar12 < 0x257ed5) {
    if (iVar12 < 0x3bfc4) {
      iVar5 = 0x1e;
    }
    else {
      iVar5 = 300;
    }
    uVar11 = iVar12 < 0x3bfc4 ^ 1;
    uVar10 = (undefined2)(iVar12 / iVar5);
  }
  else {
    uVar11 = 0;
    uVar10 = 0;
  }
  bVar1 = *(byte *)(iVar4 + 0x87);
  bStack_34 = (char)*(undefined2 *)(_p_lld_env + 0xd6) << 5 | bStack_34 & 0x1f;
  iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  iVar12 = ((uint)bVar1 * 9 + 1 & 0xff) * 0xe;
  sVar2 = *(short *)(iVar12 + 0xc + iVar5);
  if (sVar2 == 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x50a,*(code **)(_r_plf_funcs_p + 8));
  }
  sVar3 = 0;
  if ((*(ushort *)(iVar4 + 0x74) & 0x20) == 0) {
    sVar3 = 6;
  }
  if ((*(ushort *)(iVar4 + 0x74) & 4) != 0) {
    sVar3 = sVar3 + 6;
  }
  iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  if ((*(ushort *)(iVar12 + 6 + iVar5) >> 0xc & 1) == 0) {
    sVar3 = sVar3 + 2;
  }
  else {
    sVar3 = sVar3 + 5;
  }
  sVar3 = sVar3 + sVar2;
  puVar6 = (undefined1 *)
           (**(code **)(_r_plf_funcs_p + 0xbc))(sVar3,*(code **)(_r_plf_funcs_p + 0xbc));
  *puVar6 = (char)uVar10;
  pbVar7 = (byte *)(**(code **)(_r_plf_funcs_p + 0xbc))(sVar3 + 1,*(code **)(_r_plf_funcs_p + 0xbc))
  ;
  *pbVar7 = (byte)((ushort)uVar10 >> 8) & 0x1f | (byte)(uVar11 << 5);
  puVar6 = (undefined1 *)
           (**(code **)(_r_plf_funcs_p + 0xbc))(sVar3 + 0x10,*(code **)(_r_plf_funcs_p + 0xbc));
  *puVar6 = (char)sVar9;
  puVar6 = (undefined1 *)
           (**(code **)(_r_plf_funcs_p + 0xbc))(sVar3 + 0x11,*(code **)(_r_plf_funcs_p + 0xbc));
  *puVar6 = (char)((ushort)sVar9 >> 8);
  __dest = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))(sVar3 + 4,*(code **)(_r_plf_funcs_p + 0xbc))
  ;
  memcpy(__dest,auStack_38,5);
  return;
}

