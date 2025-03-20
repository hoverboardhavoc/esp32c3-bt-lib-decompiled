/*
 * Last changed at upstream commit d2414a5dd958b32ca53382b441d24d97a0345a55
 * https://github.com/espressif/esp32c3-bt-lib/commit/d2414a5dd958b32ca53382b441d24d97a0345a55
 * Upstream date: 2025-03-20 20:11:19 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(03d0f8a6)
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
  void *__s;
  undefined4 uVar3;
  int iVar4;
  undefined2 *puVar5;
  ushort *puVar6;
  int iVar7;
  void *__dest;
  uint uVar8;
  undefined4 uVar9;
  code *pcVar10;
  ushort uVar11;
  uint uVar12;
  byte bStack_132;
  byte bStack_131;
  byte abStack_130 [260];
  
  if (_lld_test_env != (void *)0x0) {
    return 0xc;
  }
  __s = (void *)(**(code **)(_r_modules_funcs_p + 0x120))
                          (0x2c,0,*(code **)(_r_modules_funcs_p + 0x120));
  _lld_test_env = __s;
  if (__s == (void *)0x0) {
    (**(code **)(_r_plf_funcs_p + 8))("lld_test.c",0x31b,*(code **)(_r_plf_funcs_p + 8));
    return 0xc;
  }
  uVar3 = (**(code **)(_r_ip_funcs_p + 0x264))(*(code **)(_r_ip_funcs_p + 0x264));
  memset(__s,0,0x2c);
  iVar7 = _r_ip_funcs_p;
  *(undefined4 *)((int)__s + 0x20) = *(undefined4 *)(_r_ip_funcs_p + 0x1f8);
  uVar9 = *(undefined4 *)(iVar7 + 0x1fc);
  *(undefined4 *)((int)__s + 0x1c) = 0;
  *(undefined4 *)((int)__s + 8) = 0;
  *(undefined4 *)((int)__s + 0x18) = uVar9;
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
    iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    iVar7 = _r_plf_funcs_p;
    *(undefined2 *)(iVar4 + 0x4a) = 0;
    iVar4 = (**(code **)(iVar7 + 0xbc))(0x400,*(code **)(iVar7 + 0xbc));
    iVar7 = _r_plf_funcs_p;
    *(undefined2 *)(iVar4 + 0x4c) = 0;
    iVar4 = (**(code **)(iVar7 + 0xbc))(0x400,*(code **)(iVar7 + 0xbc));
    iVar7 = _r_modules_funcs_p;
    *(undefined2 *)(iVar4 + 0x4e) = 0;
    bStack_131 = 0;
    abStack_130[0] = 0;
    (**(code **)(iVar7 + 0x1e0))(0x1d,0,&bStack_131,abStack_130,*(code **)(iVar7 + 0x1e0));
    puVar5 = (undefined2 *)
             (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    *puVar5 = 0x1d;
    uVar12 = (uint)bStack_131;
    if ((uVar12 << 7 & 0xffffff7f) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_test.c",0x82,*(code **)(_r_plf_funcs_p + 8));
    }
    puVar6 = (ushort *)(**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc))
    ;
    uVar11 = *puVar6;
    puVar6 = (ushort *)(**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc))
    ;
    *puVar6 = uVar11 & 0xff7f | (ushort)(uVar12 << 7);
    uVar12 = (uint)abStack_130[0];
    if ((uVar12 << 6 & 0xffffffbf) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_test.c",0x8e,*(code **)(_r_plf_funcs_p + 8));
    }
    puVar6 = (ushort *)(**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc))
    ;
    uVar11 = *puVar6;
    puVar6 = (ushort *)(**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc))
    ;
    pcVar10 = *(code **)(_r_plf_funcs_p + 0xbc);
    *puVar6 = uVar11 & 0xffbf | (ushort)(uVar12 << 6);
    iVar7 = (*pcVar10)(0x400,pcVar10);
    *(undefined2 *)(iVar7 + 0x1a) = 0x8026;
    iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(undefined2 *)(iVar7 + 0x28) = 0xff;
    iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    pcVar10 = _rwip_rf;
    *(undefined2 *)(iVar7 + 0x2a) = 0;
    (*pcVar10)(0,pcVar10);
  }
  else if (cVar1 == '\x01') {
    *(char *)((int)__s + 0x28) = param_1[2];
    *(char *)((int)__s + 0x29) = param_1[3];
    pcVar10 = *(code **)(iVar7 + 0xc4);
    iVar4 = (*pcVar10)(0xff,pcVar10);
    iVar7 = _r_plf_funcs_p;
    if (iVar4 == 0) {
      (**(code **)(_r_ip_funcs_p + 500))(*(code **)(_r_ip_funcs_p + 500));
      return 7;
    }
    *(short *)((int)__s + 0x24) = (short)iVar4;
    iVar7 = (**(code **)(iVar7 + 0xbc))(0x1400,*(code **)(iVar7 + 0xbc));
    *(short *)(iVar7 + 4) = (short)iVar4;
    _DAT_60031000 = _DAT_60031000 & 0xffffbfff | 0x4000;
    _DAT_600310d0 = _DAT_600310d0 & 0xfffff7ff | 0x800;
    iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    iVar7 = _r_plf_funcs_p;
    *(undefined2 *)(iVar4 + 0x44) = 0;
    iVar4 = (**(code **)(iVar7 + 0xbc))(0x400,*(code **)(iVar7 + 0xbc));
    iVar7 = _r_plf_funcs_p;
    *(undefined2 *)(iVar4 + 0x46) = 0;
    iVar7 = (**(code **)(iVar7 + 0xbc))(0x400,*(code **)(iVar7 + 0xbc));
    *(undefined2 *)(iVar7 + 0x48) = 0;
    uVar12 = (uint)(byte)param_1[3];
    if (uVar12 < 8) {
      uVar8 = 1 << (uVar12 & 0x1f);
      if ((uVar8 & 0xf6) == 0) {
        if ((uVar8 & 9) != 0) {
          _DAT_600310d0 = (uVar12 & 1) << 0xd | _DAT_600310d0 & 0xffffcfff | 0x1000;
        }
      }
      else {
        switch(uVar12 - 1 & 0xff) {
        case 0:
          iVar7 = 0xf0;
          break;
        case 1:
          iVar7 = 0xaa;
          break;
        default:
          iVar7 = 0;
          break;
        case 3:
          iVar7 = 0xff;
          break;
        case 5:
          iVar7 = 0xf;
          break;
        case 6:
          iVar7 = 0x55;
        }
        bVar2 = param_1[2];
        memset(abStack_130,iVar7,(uint)bVar2);
        __dest = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                                   (*(undefined2 *)((int)__s + 0x24),
                                    *(code **)(_r_plf_funcs_p + 0xbc));
        memcpy(__dest,abStack_130,(uint)bVar2);
        _DAT_600310d0 = _DAT_600310d0 & 0xffffefff;
      }
    }
    else {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_test.c",0x2c3,*(code **)(_r_plf_funcs_p + 8));
    }
    bVar2 = param_1[3];
    cVar1 = param_1[2];
    if ((bVar2 & 0xf0) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_test.c",0x126,*(code **)(_r_plf_funcs_p + 8));
    }
    iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    pcVar10 = *(code **)(_r_plf_funcs_p + 0xbc);
    *(ushort *)(iVar7 + 2) = CONCAT11(cVar1,bVar2);
    puVar6 = (ushort *)(*pcVar10)(0x1400,pcVar10);
    uVar11 = *puVar6;
    puVar6 = (ushort *)
             (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    iVar7 = _r_plf_funcs_p;
    *puVar6 = uVar11 & 0x7fff;
    iVar7 = (**(code **)(iVar7 + 0xbc))(0x400,*(code **)(iVar7 + 0xbc));
    *(undefined2 *)(iVar7 + 0x1c) = 0x1400;
    bStack_131 = 0;
    bStack_132 = 0;
    (**(code **)(_r_modules_funcs_p + 0x1e0))
              (0x1c,0,&bStack_132,&bStack_131,*(code **)(_r_modules_funcs_p + 0x1e0));
    puVar5 = (undefined2 *)
             (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    *puVar5 = 0x1c;
    uVar12 = (uint)bStack_132;
    if ((uVar12 << 7 & 0xffffff7f) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_test.c",0x82,*(code **)(_r_plf_funcs_p + 8));
    }
    puVar6 = (ushort *)(**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc))
    ;
    uVar11 = *puVar6;
    puVar6 = (ushort *)(**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc))
    ;
    *puVar6 = uVar11 & 0xff7f | (ushort)(uVar12 << 7);
    uVar12 = (uint)bStack_131;
    if ((uVar12 << 6 & 0xffffffbf) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_test.c",0x8e,*(code **)(_r_plf_funcs_p + 8));
    }
    puVar6 = (ushort *)(**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc))
    ;
    uVar11 = *puVar6;
    puVar6 = (ushort *)(**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc))
    ;
    pcVar10 = *(code **)(_r_ip_funcs_p + 0x214);
    *puVar6 = uVar11 & 0xffbf | (ushort)(uVar12 << 6);
    (*pcVar10)(0,0x1c,pcVar10);
  }
  else {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_test.c",0x2ed,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(undefined2 *)(iVar7 + 0xc) = 0x4129;
  iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(undefined2 *)(iVar7 + 0xe) = 0x7176;
  iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(undefined2 *)(iVar7 + 0x10) = 0x5555;
  iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(undefined2 *)(iVar7 + 0x12) = 0x55;
  uVar12 = (**(code **)(_r_ip_funcs_p + 0x200))(param_1[1],*(code **)(_r_ip_funcs_p + 0x200));
  if ((uVar12 & 0xffffffc0) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_test.c",0x3cf,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar11 = *(ushort *)(iVar7 + 0x16);
  iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(ushort *)(iVar7 + 0x16) = uVar11 & 0xffc0 | (ushort)uVar12;
  if (*param_1 == '\x01') {
    uVar11 = (byte)param_1[4] - 1 & 0xff;
  }
  else {
    if (*param_1 == '\0') {
      uVar12 = (byte)param_1[4] - 1 & 0xff;
      uVar11 = 0;
      goto _L109;
    }
    uVar11 = 0;
  }
  uVar12 = 0;
_L109:
  if ((uVar12 << 2 & 0xfffffff3) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_test.c",399,*(code **)(_r_plf_funcs_p + 8));
  }
  if ((uVar11 & 0xfffc) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_test.c",400,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  iVar7 = _r_plf_funcs_p;
  *(ushort *)(iVar4 + 4) = (ushort)(uVar12 << 2) | uVar11 | 0x1000;
  iVar4 = (**(code **)(iVar7 + 0xbc))(0x400,*(code **)(iVar7 + 0xbc));
  iVar7 = _r_plf_funcs_p;
  *(undefined2 *)(iVar4 + 0x4a) = 0;
  iVar4 = (**(code **)(iVar7 + 0xbc))(0x400,*(code **)(iVar7 + 0xbc));
  iVar7 = _r_plf_funcs_p;
  *(undefined2 *)(iVar4 + 0x4c) = 0;
  iVar4 = (**(code **)(iVar7 + 0xbc))(0x400,*(code **)(iVar7 + 0xbc));
  iVar7 = _r_ip_funcs_p;
  *(undefined2 *)(iVar4 + 0x4e) = 0;
  *(undefined4 *)((int)__s + 4) = uVar3;
  iVar7 = (**(code **)(iVar7 + 0x6b0))(__s,*(code **)(iVar7 + 0x6b0));
  if (iVar7 != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_test.c",0x314,*(code **)(_r_plf_funcs_p + 8));
    return 0;
  }
  *(undefined1 *)((int)__s + 0x2a) = 0;
  return 0;
}

