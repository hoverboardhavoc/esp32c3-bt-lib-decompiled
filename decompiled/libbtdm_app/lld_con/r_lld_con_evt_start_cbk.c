/*
 * Last changed at upstream commit aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * https://github.com/espressif/esp32c3-bt-lib/commit/aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * Upstream date: 2025-03-20 20:31:24 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(d74042a8)
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
  char cVar6;
  int iVar7;
  code *pcVar8;
  int iVar9;
  short sVar10;
  ushort uVar11;
  uint uVar12;
  uint uVar13;
  byte bStack_51;
  uint uStack_50;
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
    (**(code **)(_r_plf_funcs_p + 8))("lld_con.c",0xb76,*(code **)(_r_plf_funcs_p + 8));
    return;
  }
  bVar1 = *(byte *)(param_1 + 0x8e);
  uVar12 = (uint)bVar1;
  iVar9 = uVar12 * 0x5a;
  iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  sVar10 = *(short *)(param_1 + 0x7c) + *(short *)(param_1 + 0x7e);
  pcVar8 = *(code **)(_r_plf_funcs_p + 0xbc);
  uVar11 = *(ushort *)(iVar7 + iVar9);
  *(short *)(param_1 + 0x7c) = sVar10;
  iVar7 = (*pcVar8)(0x400,pcVar8);
  pcVar8 = *(code **)(_r_ip_funcs_p + 0x3ac);
  *(short *)(iVar7 + iVar9 + 0x50) = sVar10;
  (*pcVar8)(uVar12,uVar11 & 0x1f,pcVar8);
  (**(code **)(_r_ip_funcs_p + 0x370))
            (*(undefined1 *)(param_1 + 0x8e),*(code **)(_r_ip_funcs_p + 0x370));
  pcVar8 = *(code **)(_r_modules_funcs_p + 0x1e0);
  iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  (*pcVar8)(*(ushort *)(iVar7 + iVar9) & 0x1f,uVar12,&bStack_51,&uStack_50);
  if (((uint)bStack_51 << 7 & 0xffffff7f) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x82,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar11 = *(ushort *)(iVar7 + iVar9);
  iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(ushort *)(iVar7 + iVar9) = uVar11 & 0xff7f | (ushort)((uint)bStack_51 << 7);
  uVar13 = (uStack_50 & 0xff) << 6;
  if ((uVar13 & 0xffffffbf) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x8e,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar11 = *(ushort *)(iVar7 + iVar9);
  iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(ushort *)(iVar7 + iVar9) = uVar11 & 0xffbf | (ushort)uVar13;
  uVar11 = *(ushort *)(param_1 + 0x84);
  *(ushort *)(param_1 + 0x84) = uVar11 & 0xfeff;
  if ((uVar11 & 0x200) != 0) {
    bVar2 = *(byte *)(param_1 + 0x8d);
    uVar11 = *(ushort *)(param_1 + 0x7e);
    uVar3 = *(ushort *)(param_1 + 0x80);
    iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar4 = *(ushort *)(iVar7 + iVar9 + 0x16);
    iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar11 = (ushort)(((uint)uVar11 * (uint)bVar2 + (uint)uVar3) % 0x25);
    *(ushort *)(iVar7 + iVar9 + 0x16) = uVar4 & 0xffc0 | uVar11;
    *(ushort *)(param_1 + 0x80) = uVar11;
  }
  *(undefined2 *)(param_1 + 0x7e) = 0;
  if ((*(ushort *)(param_1 + 0x84) & 1) != 0) {
    uVar13 = *(int *)(param_1 + 0x4c) + 1U >> 1;
    if (uVar13 < 0x4000) {
      iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar11 = (ushort)(uVar13 + 1 >> 1);
    }
    else {
      uVar13 = (uVar13 + 0x270) / 0x271;
      if ((int)(uVar13 << 0x10) < 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x4ab,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar11 = (ushort)uVar13 | 0x8000;
    }
    *(ushort *)(iVar7 + iVar9 + 0x1a) = uVar11;
  }
  if ((*(char *)(param_1 + 0x46) != '\0') &&
     ((ushort)(*(short *)(param_1 + 0x7c) - *(short *)(param_1 + 0x44)) < 0x7fff)) {
    if (*(char *)(param_1 + 0x46) == '\x02') {
      if ((*(byte *)(param_1 + 0x38) & 0xe0) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0xa9b,*(code **)(_r_plf_funcs_p + 8));
      }
      uVar5 = *(undefined2 *)(param_1 + 0x34);
      iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar7 + iVar9 + 0x22) = uVar5;
      uVar5 = *(undefined2 *)(param_1 + 0x36);
      iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar7 + iVar9 + 0x24) = uVar5;
      bVar2 = *(byte *)(param_1 + 0x38);
      if ((bVar2 & 0xe0) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x64d,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar11 = *(ushort *)(iVar7 + iVar9 + 0x26);
      iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar7 + iVar9 + 0x26) = uVar11 & 0xffe0 | (ushort)bVar2;
    }
    if (*(char *)(param_1 + 0x46) == '\x03') {
      uVar13 = (uint)*(byte *)(param_1 + 0x35) << 2;
      if ((uVar13 & 0xfffffff3) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x1cb,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar9 = iVar9 + 4;
      iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar11 = *(ushort *)(iVar7 + iVar9);
      iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar7 + iVar9) = uVar11 & 0xfff3 | (ushort)uVar13;
      bVar2 = *(byte *)(param_1 + 0x34);
      if ((bVar2 & 0xfc) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x1d7,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar11 = *(ushort *)(iVar7 + iVar9);
      iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar9 + iVar7) = uVar11 & 0xfffc | (ushort)bVar2;
    }
    cVar6 = '\x01';
    if ((*(char *)(param_1 + 0x46) != '\x01') || (cVar6 = *(char *)(param_1 + 0x43), cVar6 != '\0'))
    goto _L502;
  }
  cVar6 = '\0';
_L502:
  uStack_50 = *(uint *)(_r_ip_funcs_p + 0x358);
  uStack_3b = 0;
  uStack_4c = *(undefined4 *)(param_1 + 4);
  uStack_37 = 0;
  uStack_48 = *(undefined4 *)(param_1 + 8);
  uStack_36 = 0;
  uStack_34 = 0;
  uStack_44 = *(undefined4 *)(param_1 + 0x10);
  uStack_3c = *(undefined1 *)(param_1 + 0x16);
  uStack_3a = 0xf00;
  uStack_40 = uVar12;
  bStack_38 = bVar1;
  (**(code **)(_r_ip_funcs_p + 0x6c8))(&uStack_50,*(code **)(_r_ip_funcs_p + 0x6c8));
  if (*(char *)(param_1 + 0x8f) != '\x02') {
    *(undefined1 *)(param_1 + 0x8f) = 1;
  }
  if (cVar6 != '\0') {
    (**(code **)(_r_ip_funcs_p + 0x3d4))
              (*(undefined1 *)(param_1 + 0x8e),*(code **)(_r_ip_funcs_p + 0x3d4));
  }
  return;
}

