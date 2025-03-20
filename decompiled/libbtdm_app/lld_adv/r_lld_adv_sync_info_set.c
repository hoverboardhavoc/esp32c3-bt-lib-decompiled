/*
 * Last changed at upstream commit daab5dbba958a13041bd496e4a6ed506c9284a06
 * https://github.com/espressif/esp32c3-bt-lib/commit/daab5dbba958a13041bd496e4a6ed506c9284a06
 * Upstream date: 2025-03-20 20:43:40 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(86a4da5c)
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
  short sVar8;
  undefined2 uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  bool bVar13;
  short sStack_3e;
  uint uStack_3c;
  undefined1 auStack_38 [4];
  byte bStack_34;
  
  iVar4 = *(int *)(&lld_adv_env + param_1 * 4);
  iVar5 = iVar4 + 0x34;
  if (*(char *)(iVar4 + 0x95) == '\0') {
    iVar5 = iVar4;
  }
  if ((((*(ushort *)(iVar4 + 0x74) & 0x13) != 0) || (*(int *)(iVar4 + 0x68) == 0)) ||
     (*(char *)(iVar4 + 0x94) != '\0')) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x4b0,*(code **)(_r_plf_funcs_p + 8));
  }
  (**(code **)(_r_ip_funcs_p + 0x310))
            (*(undefined1 *)(iVar4 + 0x88),&uStack_3c,&sStack_3e,auStack_38,
             *(code **)(_r_ip_funcs_p + 0x310));
  iVar5 = *(int *)(iVar5 + 4);
  uVar10 = uStack_3c - iVar5 & 0xfffffff;
  if (0x8000000 < uVar10) {
    uVar10 = -(iVar5 - uStack_3c & 0xfffffff);
  }
  bVar13 = false;
  uVar12 = uStack_3c;
  sVar8 = sStack_3e;
  while (iVar11 = ((int)(uVar10 * 0x271) >> 1) + (uint)*(ushort *)(iVar4 + 0x7a) * -0x1e,
        iVar11 <= *(int *)(iVar4 + 0x70) + 300) {
    uVar12 = *(int *)(iVar4 + 0x68) * 4 + uVar12 & 0xfffffff;
    uVar10 = uVar12 - iVar5 & 0xfffffff;
    if (0x8000000 < uVar10) {
      uVar10 = -(iVar5 - uVar12 & 0xfffffff);
    }
    sVar8 = sVar8 + 1;
    bVar13 = true;
  }
  if (bVar13) {
    sStack_3e = sVar8;
    uStack_3c = uVar12;
  }
  sVar8 = sStack_3e;
  if (iVar11 < 0x257ed5) {
    if (iVar11 < 0x3bfc4) {
      iVar5 = 0x1e;
    }
    else {
      iVar5 = 300;
    }
    uVar10 = iVar11 < 0x3bfc4 ^ 1;
    uVar9 = (undefined2)(iVar11 / iVar5);
  }
  else {
    uVar10 = 0;
    uVar9 = 0;
  }
  bVar1 = *(byte *)(iVar4 + 0x87);
  bStack_34 = (char)*(undefined2 *)(_p_lld_env + 0xd6) << 5 | bStack_34 & 0x1f;
  iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  iVar11 = ((uint)bVar1 * 9 + 1 & 0xff) * 0xe;
  sVar2 = *(short *)(iVar5 + iVar11 + 0xc);
  if (sVar2 == 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x4df,*(code **)(_r_plf_funcs_p + 8));
  }
  sVar3 = 0;
  if ((*(ushort *)(iVar4 + 0x74) & 0x20) == 0) {
    sVar3 = 6;
  }
  if ((*(ushort *)(iVar4 + 0x74) & 4) != 0) {
    sVar3 = sVar3 + 6;
  }
  iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  if ((int)((uint)*(ushort *)(iVar11 + 6 + iVar5) << 0x13) < 0) {
    sVar3 = sVar3 + 5;
  }
  else {
    sVar3 = sVar3 + 2;
  }
  sVar3 = sVar3 + sVar2;
  puVar6 = (undefined1 *)
           (**(code **)(_r_plf_funcs_p + 0xbc))(sVar3,*(code **)(_r_plf_funcs_p + 0xbc));
  *puVar6 = (char)uVar9;
  pbVar7 = (byte *)(**(code **)(_r_plf_funcs_p + 0xbc))(sVar3 + 1,*(code **)(_r_plf_funcs_p + 0xbc))
  ;
  *pbVar7 = (byte)((ushort)uVar9 >> 8) & 0x1f | (byte)(uVar10 << 5);
  puVar6 = (undefined1 *)
           (**(code **)(_r_plf_funcs_p + 0xbc))(sVar3 + 0x10,*(code **)(_r_plf_funcs_p + 0xbc));
  *puVar6 = (char)sVar8;
  puVar6 = (undefined1 *)
           (**(code **)(_r_plf_funcs_p + 0xbc))(sVar3 + 0x11,*(code **)(_r_plf_funcs_p + 0xbc));
  *puVar6 = (char)((ushort)sVar8 >> 8);
  __dest = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))(sVar3 + 4,*(code **)(_r_plf_funcs_p + 0xbc))
  ;
  memcpy(__dest,auStack_38,5);
  return;
}

