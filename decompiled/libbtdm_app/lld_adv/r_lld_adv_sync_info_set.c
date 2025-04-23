/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  undefined1 uVar3;
  short sVar4;
  undefined1 *puVar5;
  byte *pbVar6;
  void *__dest;
  int iVar7;
  uint uVar8;
  undefined2 uVar9;
  short sVar10;
  uint uVar11;
  int iVar12;
  bool bVar13;
  ushort uVar14;
  int iVar15;
  short sStack_3e;
  uint uStack_3c;
  undefined1 auStack_38 [4];
  byte bStack_34;
  
  iVar15 = *(int *)(&lld_adv_env + param_1 * 4);
  iVar7 = iVar15 + 0x34;
  if (*(char *)(iVar15 + 0x95) == '\0') {
    iVar7 = iVar15;
  }
  if ((((*(ushort *)(iVar15 + 0x74) & 0x13) != 0) || (*(int *)(iVar15 + 0x68) == 0)) ||
     (*(char *)(iVar15 + 0x94) != '\0')) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x4a1,*(code **)(_r_plf_funcs_p + 8));
  }
  (**(code **)(_r_ip_funcs_p + 0x310))
            (*(undefined1 *)(iVar15 + 0x88),&uStack_3c,&sStack_3e,auStack_38,
             *(code **)(_r_ip_funcs_p + 0x310));
  iVar7 = *(int *)(iVar7 + 4);
  uVar11 = uStack_3c - iVar7 & 0xfffffff;
  if (0x8000000 < uVar11) {
    uVar11 = -(iVar7 - uStack_3c & 0xfffffff);
  }
  bVar13 = false;
  uVar8 = uStack_3c;
  sVar10 = sStack_3e;
  while (iVar12 = ((int)(uVar11 * 0x271) >> 1) + (uint)*(ushort *)(iVar15 + 0x7a) * -0x1e,
        iVar12 <= *(int *)(iVar15 + 0x70) + 300) {
    uVar8 = *(int *)(iVar15 + 0x68) * 4 + uVar8 & 0xfffffff;
    uVar11 = uVar8 - iVar7 & 0xfffffff;
    if (0x8000000 < uVar11) {
      uVar11 = -(iVar7 - uVar8 & 0xfffffff);
    }
    sVar10 = sVar10 + 1;
    bVar13 = true;
  }
  if (bVar13) {
    sStack_3e = sVar10;
    uStack_3c = uVar8;
  }
  sVar10 = sStack_3e;
  if (iVar12 < 0x257ed5) {
    if (iVar12 < 0x3bfc4) {
      iVar7 = 0x1e;
    }
    else {
      iVar7 = 300;
    }
    uVar11 = (uint)(0x3bfc3 < iVar12);
    uVar9 = (undefined2)(iVar12 / iVar7);
  }
  else {
    uVar11 = 0;
    uVar9 = 0;
  }
  bVar1 = *(byte *)(iVar15 + 0x87);
  bStack_34 = (char)*(undefined2 *)(_p_lld_env + 0xd6) << 5 | bStack_34 & 0x1f;
  uVar3 = (undefined1)sStack_3e;
  iVar12 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  iVar7 = ((uint)bVar1 * 9 + 1 & 0xff) * 0xe;
  sVar2 = *(short *)(iVar7 + 0xc + iVar12);
  if (sVar2 == 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x4d0,*(code **)(_r_plf_funcs_p + 8));
  }
  uVar14 = -(ushort)((*(ushort *)(iVar15 + 0x74) & 0x20) == 0) & 6;
  if ((*(ushort *)(iVar15 + 0x74) & 4) != 0) {
    uVar14 = uVar14 + 6;
  }
  iVar15 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  sVar4 = uVar14 + 5;
  if (-1 < (int)((uint)*(ushort *)(iVar7 + 6 + iVar15) << 0x13)) {
    sVar4 = uVar14 + 2;
  }
  sVar4 = sVar4 + sVar2;
  puVar5 = (undefined1 *)
           (**(code **)(_r_plf_funcs_p + 0xbc))(sVar4,*(code **)(_r_plf_funcs_p + 0xbc));
  *puVar5 = (char)uVar9;
  pbVar6 = (byte *)(**(code **)(_r_plf_funcs_p + 0xbc))(sVar4 + 1,*(code **)(_r_plf_funcs_p + 0xbc))
  ;
  *pbVar6 = (byte)((ushort)uVar9 >> 8) & 0x1f | (byte)(uVar11 << 5);
  puVar5 = (undefined1 *)
           (**(code **)(_r_plf_funcs_p + 0xbc))(sVar4 + 0x10,*(code **)(_r_plf_funcs_p + 0xbc));
  *puVar5 = uVar3;
  puVar5 = (undefined1 *)
           (**(code **)(_r_plf_funcs_p + 0xbc))(sVar4 + 0x11,*(code **)(_r_plf_funcs_p + 0xbc));
  *puVar5 = (char)((ushort)sVar10 >> 8);
  __dest = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))(sVar4 + 4,*(code **)(_r_plf_funcs_p + 0xbc))
  ;
  memcpy(__dest,auStack_38,5);
  return;
}

