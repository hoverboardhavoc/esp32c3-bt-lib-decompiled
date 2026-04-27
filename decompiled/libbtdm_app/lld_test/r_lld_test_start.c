/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app -> lld_test.o -> r_lld_test_start
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_lld_test_start(char *param_1)

{
  char cVar1;
  byte bVar2;
  undefined2 uVar3;
  void *__s;
  undefined4 uVar4;
  int iVar5;
  undefined2 *puVar6;
  ushort *puVar7;
  int iVar8;
  void *__dest;
  code *pcVar9;
  ushort uVar10;
  uint uVar11;
  byte bStack_132;
  byte bStack_131;
  byte abStack_130 [268];
  
  if (_lld_test_env != (void *)0x0) {
    return 0xc;
  }
  __s = (void *)(**(code **)(_r_modules_funcs_p + 0x120))
                          (0x2c,0,*(code **)(_r_modules_funcs_p + 0x120));
  _lld_test_env = __s;
  if (__s == (void *)0x0) {
    (**(code **)(_r_plf_funcs_p + 8))("lld_test.c",799,*(code **)(_r_plf_funcs_p + 8));
    return 0xc;
  }
  uVar4 = (**(code **)(_r_ip_funcs_p + 0x264))(*(code **)(_r_ip_funcs_p + 0x264));
  memset(__s,0,0x2c);
  pcVar9 = _r_ip_funcs_p;
  *(undefined4 *)((int)__s + 0x20) = *(undefined4 *)(_r_ip_funcs_p + 0x1f8);
  *(undefined4 *)((int)__s + 0x18) = *(undefined4 *)(pcVar9 + 0x1fc);
  bVar2 = DAT_00011025;
  *(undefined1 *)((int)__s + 0x16) = DAT_00011024;
  *(undefined4 *)((int)__s + 0x10) = 0x9c4;
  *(ushort *)((int)__s + 0x14) = bVar2 & 0xf | 0x6000;
  cVar1 = *param_1;
  *(char *)((int)__s + 0x26) = cVar1;
  *(char *)((int)__s + 0x27) = param_1[1];
  if (cVar1 == '\0') {
    _DAT_60031000 = _DAT_60031000 & 0xffffbfff | 0x4000;
    _DAT_600310d0 = _DAT_600310d0 & 0xf7ffffff | 0x8000000;
    iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    iVar8 = _r_plf_funcs_p;
    *(undefined2 *)(iVar5 + 0x4a) = 0;
    iVar5 = (**(code **)(iVar8 + 0xbc))(0x400,*(code **)(iVar8 + 0xbc));
    iVar8 = _r_plf_funcs_p;
    *(undefined2 *)(iVar5 + 0x4c) = 0;
    iVar5 = (**(code **)(iVar8 + 0xbc))(0x400,*(code **)(iVar8 + 0xbc));
    iVar8 = _r_modules_funcs_p;
    *(undefined2 *)(iVar5 + 0x4e) = 0;
    bStack_131 = 0;
    abStack_130[0] = 0;
    (**(code **)(iVar8 + 0x1e0))(0x1d,0,&bStack_131,abStack_130,*(code **)(iVar8 + 0x1e0));
    puVar6 = (undefined2 *)
             (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    *puVar6 = 0x1d;
    uVar11 = (uint)bStack_131;
    if ((uVar11 << 7 & 0xffffff7f) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_test.c",0x82,*(code **)(_r_plf_funcs_p + 8));
    }
    puVar7 = (ushort *)(**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc))
    ;
    uVar10 = *puVar7;
    puVar7 = (ushort *)(**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc))
    ;
    *puVar7 = uVar10 & 0xff7f | (ushort)(uVar11 << 7);
    uVar11 = (uint)abStack_130[0];
    if ((uVar11 << 6 & 0xffffffbf) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_test.c",0x8e,*(code **)(_r_plf_funcs_p + 8));
    }
    puVar7 = (ushort *)(**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc))
    ;
    uVar10 = *puVar7;
    puVar7 = (ushort *)(**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc))
    ;
    pcVar9 = *(code **)(_r_plf_funcs_p + 0xbc);
    *puVar7 = uVar10 & 0xffbf | (ushort)(uVar11 << 6);
    iVar8 = (*pcVar9)(0x400,pcVar9);
    *(undefined2 *)(iVar8 + 0x1a) = 0x8026;
    iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(undefined2 *)(iVar8 + 0x28) = 0xff;
    iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    pcVar9 = _r_ip_funcs_p;
    *(undefined2 *)(iVar8 + 0x2a) = 0;
    (*pcVar9)(0,pcVar9);
  }
  else if (cVar1 == '\x01') {
    *(char *)((int)__s + 0x28) = param_1[2];
    *(char *)((int)__s + 0x29) = param_1[3];
    pcVar9 = *(code **)(pcVar9 + 0xc4);
    iVar5 = (*pcVar9)(0xff,pcVar9);
    iVar8 = _r_plf_funcs_p;
    if (iVar5 == 0) {
      (**(code **)(_r_ip_funcs_p + 500))(*(code **)(_r_ip_funcs_p + 500));
      return 7;
    }
    *(short *)((int)__s + 0x24) = (short)iVar5;
    iVar8 = (**(code **)(iVar8 + 0xbc))(0x1400,*(code **)(iVar8 + 0xbc));
    *(short *)(iVar8 + 4) = (short)iVar5;
    _DAT_60031000 = _DAT_60031000 & 0xffffbfff | 0x4000;
    _DAT_600310d0 = _DAT_600310d0 & 0xfffff7ff | 0x800;
    iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    iVar8 = _r_plf_funcs_p;
    *(undefined2 *)(iVar5 + 0x44) = 0;
    iVar5 = (**(code **)(iVar8 + 0xbc))(0x400,*(code **)(iVar8 + 0xbc));
    iVar8 = _r_plf_funcs_p;
    *(undefined2 *)(iVar5 + 0x46) = 0;
    iVar8 = (**(code **)(iVar8 + 0xbc))(0x400,*(code **)(iVar8 + 0xbc));
    *(undefined2 *)(iVar8 + 0x48) = 0;
    uVar11 = (uint)(byte)param_1[3];
    if (uVar11 == 3) {
_L93:
      _DAT_600310d0 = (uVar11 & 1) << 0xd | _DAT_600310d0 & 0xffffcfff | 0x1000;
    }
    else {
      if (uVar11 < 4) {
        if (uVar11 == 0) goto _L93;
      }
      else if (3 < (uVar11 - 4 & 0xff)) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_test.c",0x2c7,*(code **)(_r_plf_funcs_p + 8));
        goto _L97;
      }
      bVar2 = param_1[2];
      switch(uVar11 - 1 & 0xff) {
      case 0:
        iVar8 = 0xf0;
        break;
      case 1:
        iVar8 = 0xaa;
        break;
      default:
        iVar8 = 0;
        break;
      case 3:
        iVar8 = 0xff;
        break;
      case 5:
        iVar8 = 0xf;
        break;
      case 6:
        iVar8 = 0x55;
      }
      memset(abStack_130,iVar8,(uint)bVar2);
      __dest = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                                 (*(undefined2 *)((int)__s + 0x24),*(code **)(_r_plf_funcs_p + 0xbc)
                                 );
      memcpy(__dest,abStack_130,(uint)bVar2);
      _DAT_600310d0 = _DAT_600310d0 & 0xffffefff;
    }
_L97:
    bVar2 = param_1[3];
    uVar3 = *(undefined2 *)(param_1 + 2);
    if ((bVar2 & 0xf0) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_test.c",0x126,*(code **)(_r_plf_funcs_p + 8));
    }
    iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    iVar8 = _r_plf_funcs_p;
    *(short *)(iVar5 + 2) = (short)CONCAT21(uVar3,bVar2);
    puVar7 = (ushort *)(**(code **)(iVar8 + 0xbc))(0x1400,*(code **)(iVar8 + 0xbc));
    uVar10 = *puVar7;
    puVar7 = (ushort *)
             (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    pcVar9 = *(code **)(_r_plf_funcs_p + 0xbc);
    *puVar7 = (ushort)(((uint)uVar10 << 0x11) >> 0x11);
    iVar5 = (*pcVar9)(0x400,pcVar9);
    iVar8 = _r_modules_funcs_p;
    *(undefined2 *)(iVar5 + 0x1c) = 0x1400;
    bStack_131 = 0;
    bStack_132 = 0;
    (**(code **)(iVar8 + 0x1e0))(0x1c,0,&bStack_132,&bStack_131,*(code **)(iVar8 + 0x1e0));
    puVar6 = (undefined2 *)
             (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    *puVar6 = 0x1c;
    uVar11 = (uint)bStack_132;
    if ((uVar11 << 7 & 0xffffff7f) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_test.c",0x82,*(code **)(_r_plf_funcs_p + 8));
    }
    puVar7 = (ushort *)(**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc))
    ;
    uVar10 = *puVar7;
    puVar7 = (ushort *)(**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc))
    ;
    *puVar7 = uVar10 & 0xff7f | (ushort)(uVar11 << 7);
    uVar11 = (uint)bStack_131;
    if ((uVar11 << 6 & 0xffffffbf) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_test.c",0x8e,*(code **)(_r_plf_funcs_p + 8));
    }
    puVar7 = (ushort *)(**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc))
    ;
    uVar10 = *puVar7;
    puVar7 = (ushort *)(**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc))
    ;
    pcVar9 = *(code **)(_r_ip_funcs_p + 0x214);
    *puVar7 = uVar10 & 0xffbf | (ushort)(uVar11 << 6);
    (*pcVar9)(0,0x1c,pcVar9);
  }
  else {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_test.c",0x2f1,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(undefined2 *)(iVar8 + 0xc) = 0x4129;
  iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(undefined2 *)(iVar8 + 0xe) = 0x7176;
  iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(undefined2 *)(iVar8 + 0x10) = 0x5555;
  iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(undefined2 *)(iVar8 + 0x12) = 0x55;
  uVar11 = (**(code **)(_r_ip_funcs_p + 0x200))(param_1[1],*(code **)(_r_ip_funcs_p + 0x200));
  if ((uVar11 & 0xffffffc0) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_test.c",0x3cf,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar10 = *(ushort *)(iVar8 + 0x16);
  iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(ushort *)(iVar8 + 0x16) = uVar10 & 0xffc0 | (ushort)uVar11;
  if (*param_1 == '\x01') {
    uVar10 = (byte)param_1[4] - 1 & 0xff;
  }
  else {
    if (*param_1 == '\0') {
      uVar11 = (byte)param_1[4] - 1 & 0xff;
      uVar10 = 0;
      goto _L110;
    }
    uVar10 = 0;
  }
  uVar11 = 0;
_L110:
  if ((uVar11 << 2 & 0xfffffff3) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_test.c",399,*(code **)(_r_plf_funcs_p + 8));
  }
  if ((uVar10 & 0xfffc) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_test.c",400,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(ushort *)(iVar8 + 4) = (ushort)(uVar11 << 2) | uVar10 | 0x1000;
  iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  iVar8 = _r_plf_funcs_p;
  *(undefined2 *)(iVar5 + 0x4a) = 0;
  iVar5 = (**(code **)(iVar8 + 0xbc))(0x400,*(code **)(iVar8 + 0xbc));
  iVar8 = _r_plf_funcs_p;
  *(undefined2 *)(iVar5 + 0x4c) = 0;
  iVar8 = (**(code **)(iVar8 + 0xbc))(0x400,*(code **)(iVar8 + 0xbc));
  pcVar9 = _r_ip_funcs_p;
  *(undefined2 *)(iVar8 + 0x4e) = 0;
  *(undefined4 *)((int)__s + 4) = uVar4;
  iVar8 = (**(code **)(pcVar9 + 0x6b0))(__s,*(code **)(pcVar9 + 0x6b0));
  if (iVar8 != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_test.c",0x318,*(code **)(_r_plf_funcs_p + 8));
    return 0;
  }
  *(undefined1 *)((int)__s + 0x2a) = 0;
  return 0;
}

