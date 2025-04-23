/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_con.o -> r_lld_con_evt_start_cbk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_con_evt_start_cbk(int param_1)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  ushort uVar4;
  undefined2 uVar5;
  int iVar6;
  code *pcVar7;
  uint uVar8;
  int iVar9;
  char cVar10;
  short sVar11;
  ushort uVar12;
  uint uVar13;
  byte bStack_51;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  uint uStack_40;
  undefined1 uStack_3c;
  undefined1 uStack_3b;
  undefined2 uStack_3a;
  byte bStack_38;
  undefined1 uStack_37;
  undefined1 uStack_36;
  undefined1 uStack_34;
  
  if (param_1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x00012b20. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_plf_funcs_p + 8))("lld_con.c",0xb90,*(code **)(_r_plf_funcs_p + 8));
    return;
  }
  bVar1 = *(byte *)(param_1 + 0x8e);
  uVar13 = (uint)bVar1;
  iVar9 = uVar13 * 0x5a;
  iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  sVar11 = *(short *)(param_1 + 0x7c) + *(short *)(param_1 + 0x7e);
  pcVar7 = *(code **)(_r_plf_funcs_p + 0xbc);
  uVar12 = *(ushort *)(iVar6 + iVar9);
  *(short *)(param_1 + 0x7c) = sVar11;
  iVar6 = (*pcVar7)(0x400,pcVar7);
  *(short *)(iVar9 + 0x50 + iVar6) = sVar11;
  (**(code **)(_r_ip_funcs_p + 0x3ac))(uVar13,uVar12 & 0x1f,*(code **)(_r_ip_funcs_p + 0x3ac));
  (**(code **)(_r_ip_funcs_p + 0x370))
            (*(undefined1 *)(param_1 + 0x8e),*(code **)(_r_ip_funcs_p + 0x370));
  pcVar7 = *(code **)(_r_modules_funcs_p + 0x1e0);
  iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  (*pcVar7)(*(ushort *)(iVar6 + iVar9) & 0x1f,uVar13,&bStack_51,&uStack_50);
  if ((bStack_51 & 0xfe) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x82,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar12 = *(ushort *)(iVar6 + iVar9);
  iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(ushort *)(iVar6 + iVar9) = uVar12 & 0xff7f | (ushort)bStack_51 << 7;
  if (((byte)uStack_50 & 0xfe) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x8e,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar12 = *(ushort *)(iVar6 + iVar9);
  iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(ushort *)(iVar6 + iVar9) = uVar12 & 0xffbf | (ushort)(byte)uStack_50 << 6;
  uVar12 = *(ushort *)(param_1 + 0x84);
  *(ushort *)(param_1 + 0x84) = uVar12 & 0xfeff;
  if ((uVar12 & 0x200) != 0) {
    bVar2 = *(byte *)(param_1 + 0x8d);
    uVar12 = *(ushort *)(param_1 + 0x7e);
    uVar3 = *(ushort *)(param_1 + 0x80);
    iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar4 = *(ushort *)(iVar6 + iVar9 + 0x16);
    iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar12 = (ushort)(((uint)uVar12 * (uint)bVar2 + (uint)uVar3) % 0x25);
    *(ushort *)(iVar6 + iVar9 + 0x16) = uVar12 | uVar4 & 0xffc0;
    *(ushort *)(param_1 + 0x80) = uVar12;
  }
  *(undefined2 *)(param_1 + 0x7e) = 0;
  if ((*(ushort *)(param_1 + 0x84) & 1) != 0) {
    uVar8 = *(int *)(param_1 + 0x4c) + 1U >> 1;
    if (uVar8 < 0x4000) {
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar12 = (ushort)(uVar8 + 1 >> 1);
    }
    else {
      uVar8 = (uVar8 + 0x270) / 0x271;
      if ((int)(uVar8 << 0x10) < 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x4ab,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar12 = (ushort)uVar8 | 0x8000;
    }
    *(ushort *)(iVar6 + iVar9 + 0x1a) = uVar12;
  }
  cVar10 = '\0';
  if ((*(char *)(param_1 + 0x46) != '\0') &&
     ((ushort)(*(short *)(param_1 + 0x7c) - *(short *)(param_1 + 0x44)) < 0x7fff)) {
    if (*(char *)(param_1 + 0x46) == '\x02') {
      if (0x1f < *(byte *)(param_1 + 0x38)) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0xab5,*(code **)(_r_plf_funcs_p + 8));
      }
      uVar5 = *(undefined2 *)(param_1 + 0x34);
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar9 + 0x22 + iVar6) = uVar5;
      uVar5 = *(undefined2 *)(param_1 + 0x36);
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar9 + 0x24 + iVar6) = uVar5;
      bVar2 = *(byte *)(param_1 + 0x38);
      if (0x1f < bVar2) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x64d,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar12 = *(ushort *)(iVar6 + iVar9 + 0x26);
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar6 + iVar9 + 0x26) = (ushort)bVar2 | uVar12 & 0xffe0;
    }
    if (*(char *)(param_1 + 0x46) == '\x03') {
      bVar2 = *(byte *)(param_1 + 0x35);
      if ((bVar2 & 0xfc) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x1cb,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar9 = iVar9 + 4;
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar12 = *(ushort *)(iVar6 + iVar9);
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar6 + iVar9) = uVar12 & 0xfff3 | (ushort)bVar2 << 2;
      bVar2 = *(byte *)(param_1 + 0x34);
      if (3 < bVar2) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x1d7,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar12 = *(ushort *)(iVar6 + iVar9);
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar6 + iVar9) = (ushort)bVar2 | uVar12 & 0xfffc;
    }
    cVar10 = '\x01';
    if (*(char *)(param_1 + 0x46) == '\x01') {
      cVar10 = *(char *)(param_1 + 0x43);
    }
  }
  uStack_3c = *(undefined1 *)(param_1 + 0x16);
  uStack_50 = *(undefined4 *)(_r_ip_funcs_p + 0x358);
  uStack_4c = *(undefined4 *)(param_1 + 4);
  uStack_48 = *(undefined4 *)(param_1 + 8);
  uStack_3b = 0;
  uStack_3a = 0xf00;
  uStack_37 = 0;
  uStack_44 = *(undefined4 *)(param_1 + 0x10);
  uStack_36 = 0;
  uStack_34 = 0;
  uStack_40 = uVar13;
  bStack_38 = bVar1;
  (**(code **)(_r_ip_funcs_p + 0x6c8))(&uStack_50,*(code **)(_r_ip_funcs_p + 0x6c8));
  if (*(char *)(param_1 + 0x8f) != '\x02') {
    *(undefined1 *)(param_1 + 0x8f) = 1;
  }
  if (cVar10 != '\0') {
                    /* WARNING: Could not recover jumptable at 0x00012ade. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_ip_funcs_p + 0x3d4))
              (*(undefined1 *)(param_1 + 0x8e),*(code **)(_r_ip_funcs_p + 0x3d4));
    return;
  }
  return;
}

