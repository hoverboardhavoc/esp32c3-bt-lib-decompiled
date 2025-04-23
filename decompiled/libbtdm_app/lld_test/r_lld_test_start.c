/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_test.o -> r_lld_test_start
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_lld_test_start(byte *param_1)

{
  byte bVar1;
  undefined2 uVar2;
  byte bVar3;
  void *__s;
  undefined4 uVar4;
  int iVar5;
  undefined2 *puVar6;
  ushort *puVar7;
  int iVar8;
  uint uVar9;
  void *__dest;
  code *pcVar10;
  ushort uVar11;
  byte bStack_122;
  byte bStack_121;
  byte abStack_120 [256];
  
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
  uVar4 = (**(code **)(_r_ip_funcs_p + 0x264))(*(code **)(_r_ip_funcs_p + 0x264));
  memset(__s,0,0x2c);
  pcVar10 = _r_ip_funcs_p;
  *(undefined4 *)((int)__s + 0x20) = *(undefined4 *)(_r_ip_funcs_p + 0x1f8);
  *(undefined4 *)((int)__s + 0x18) = *(undefined4 *)(pcVar10 + 0x1fc);
  bVar1 = DAT_00011025;
  *(undefined1 *)((int)__s + 0x16) = DAT_00011024;
  *(undefined4 *)((int)__s + 0x10) = 0x9c4;
  *(ushort *)((int)__s + 0x14) = bVar1 & 0xf | 0x6000;
  bVar1 = *param_1;
  *(byte *)((int)__s + 0x26) = bVar1;
  *(byte *)((int)__s + 0x27) = param_1[1];
  if (bVar1 == 0) {
    _DAT_60031000 = _DAT_60031000 | 0x4000;
    _DAT_600310d0 = _DAT_600310d0 | 0x8000000;
    iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    iVar8 = _r_plf_funcs_p;
    *(undefined2 *)(iVar5 + 0x4a) = 0;
    iVar5 = (**(code **)(iVar8 + 0xbc))(0x400,*(code **)(iVar8 + 0xbc));
    iVar8 = _r_plf_funcs_p;
    *(undefined2 *)(iVar5 + 0x4c) = 0;
    iVar5 = (**(code **)(iVar8 + 0xbc))(0x400,*(code **)(iVar8 + 0xbc));
    iVar8 = _r_modules_funcs_p;
    *(undefined2 *)(iVar5 + 0x4e) = 0;
    bStack_121 = 0;
    abStack_120[0] = 0;
    (**(code **)(iVar8 + 0x1e0))(0x1d,0,&bStack_121,abStack_120,*(code **)(iVar8 + 0x1e0));
    puVar6 = (undefined2 *)
             (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    bVar1 = bStack_121;
    *puVar6 = 0x1d;
    if ((bStack_121 & 0xfe) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_test.c",0x82,*(code **)(_r_plf_funcs_p + 8));
    }
    puVar7 = (ushort *)(**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc))
    ;
    uVar11 = *puVar7;
    puVar7 = (ushort *)(**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc))
    ;
    bVar3 = abStack_120[0];
    *puVar7 = uVar11 & 0xff7f | (ushort)bVar1 << 7;
    if ((abStack_120[0] & 0xfe) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_test.c",0x8e,*(code **)(_r_plf_funcs_p + 8));
    }
    puVar7 = (ushort *)(**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc))
    ;
    uVar11 = *puVar7;
    puVar7 = (ushort *)(**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc))
    ;
    pcVar10 = *(code **)(_r_plf_funcs_p + 0xbc);
    *puVar7 = uVar11 & 0xffbf | (ushort)bVar3 << 6;
    iVar8 = (*pcVar10)(0x400,pcVar10);
    *(undefined2 *)(iVar8 + 0x1a) = 0x8026;
    iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(undefined2 *)(iVar8 + 0x28) = 0xff;
    iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    pcVar10 = _r_ip_funcs_p;
    *(undefined2 *)(iVar8 + 0x2a) = 0;
    (*pcVar10)(0,pcVar10);
    goto _L90;
  }
  if (bVar1 != 1) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_test.c",0x2ed,*(code **)(_r_plf_funcs_p + 8));
    goto _L90;
  }
  *(byte *)((int)__s + 0x28) = param_1[2];
  *(byte *)((int)__s + 0x29) = param_1[3];
  pcVar10 = *(code **)(pcVar10 + 0xc4);
  iVar5 = (*pcVar10)(0xff,pcVar10);
  iVar8 = _r_plf_funcs_p;
  if (iVar5 == 0) {
    (**(code **)(_r_ip_funcs_p + 500))(*(code **)(_r_ip_funcs_p + 500));
    return 7;
  }
  *(short *)((int)__s + 0x24) = (short)iVar5;
  iVar8 = (**(code **)(iVar8 + 0xbc))(0x1400,*(code **)(iVar8 + 0xbc));
  *(short *)(iVar8 + 4) = (short)iVar5;
  _DAT_60031000 = _DAT_60031000 | 0x4000;
  _DAT_600310d0 = _DAT_600310d0 | 0x800;
  iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  iVar8 = _r_plf_funcs_p;
  *(undefined2 *)(iVar5 + 0x44) = 0;
  iVar5 = (**(code **)(iVar8 + 0xbc))(0x400,*(code **)(iVar8 + 0xbc));
  iVar8 = _r_plf_funcs_p;
  *(undefined2 *)(iVar5 + 0x46) = 0;
  iVar8 = (**(code **)(iVar8 + 0xbc))(0x400,*(code **)(iVar8 + 0xbc));
  *(undefined2 *)(iVar8 + 0x48) = 0;
  uVar9 = (uint)param_1[3];
  if (uVar9 == 3) {
_L93:
    _DAT_600310d0 = (uVar9 & 1) << 0xd | _DAT_600310d0 & 0xffffdfff | 0x1000;
  }
  else {
    if (uVar9 < 4) {
      if (uVar9 == 0) goto _L93;
    }
    else if (3 < (uVar9 - 4 & 0xff)) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_test.c",0x2c3,*(code **)(_r_plf_funcs_p + 8));
      goto _L97;
    }
    bVar1 = param_1[2];
    switch(uVar9 - 1 & 0xff) {
    case 0:
      iVar8 = 0xf0;
      break;
    case 1:
      iVar8 = 0xaa;
      break;
    default:
      if (7 < uVar9) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_test.c",0x16f,*(code **)(_r_plf_funcs_p + 8));
      }
    case 4:
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
    memset(abStack_120,iVar8,(uint)bVar1);
    bVar1 = param_1[2];
    __dest = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                               (*(undefined2 *)((int)__s + 0x24),*(code **)(_r_plf_funcs_p + 0xbc));
    memcpy(__dest,abStack_120,(uint)bVar1);
    _DAT_600310d0 = _DAT_600310d0 & 0xffffefff;
  }
_L97:
  bVar1 = param_1[3];
  uVar2 = *(undefined2 *)(param_1 + 2);
  if (0xf < bVar1) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_test.c",0x126,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  iVar8 = _r_plf_funcs_p;
  *(short *)(iVar5 + 2) = (short)CONCAT21(uVar2,bVar1);
  puVar7 = (ushort *)(**(code **)(iVar8 + 0xbc))(0x1400,*(code **)(iVar8 + 0xbc));
  uVar11 = *puVar7;
  puVar7 = (ushort *)(**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  iVar8 = _r_plf_funcs_p;
  *puVar7 = (ushort)(((uint)uVar11 << 0x11) >> 0x11);
  iVar8 = (**(code **)(iVar8 + 0xbc))(0x400,*(code **)(iVar8 + 0xbc));
  *(undefined2 *)(iVar8 + 0x1c) = 0x1400;
  bStack_121 = 0;
  bStack_122 = 0;
  (**(code **)(_r_modules_funcs_p + 0x1e0))
            (0x1c,0,&bStack_122,&bStack_121,*(code **)(_r_modules_funcs_p + 0x1e0));
  puVar6 = (undefined2 *)
           (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  bVar1 = bStack_122;
  *puVar6 = 0x1c;
  if ((bStack_122 & 0xfe) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_test.c",0x82,*(code **)(_r_plf_funcs_p + 8));
  }
  puVar7 = (ushort *)(**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar11 = *puVar7;
  puVar7 = (ushort *)(**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  bVar3 = bStack_121;
  *puVar7 = uVar11 & 0xff7f | (ushort)bVar1 << 7;
  if ((bStack_121 & 0xfe) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_test.c",0x8e,*(code **)(_r_plf_funcs_p + 8));
  }
  puVar7 = (ushort *)(**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar11 = *puVar7;
  puVar7 = (ushort *)(**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  pcVar10 = *(code **)(_r_ip_funcs_p + 0x214);
  *puVar7 = uVar11 & 0xffbf | (ushort)bVar3 << 6;
  (*pcVar10)(0,0x1c,pcVar10);
_L90:
  iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(undefined2 *)(iVar8 + 0xc) = 0x4129;
  iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(undefined2 *)(iVar8 + 0xe) = 0x7176;
  iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(undefined2 *)(iVar8 + 0x10) = 0x5555;
  iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(undefined2 *)(iVar8 + 0x12) = 0x55;
  uVar9 = (**(code **)(_r_ip_funcs_p + 0x200))(param_1[1],*(code **)(_r_ip_funcs_p + 0x200));
  if (0x3f < uVar9) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_test.c",0x3cf,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar11 = *(ushort *)(iVar8 + 0x16);
  iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(ushort *)(iVar8 + 0x16) = (ushort)uVar9 | uVar11 & 0xffc0;
  bVar1 = *param_1;
  uVar11 = (ushort)bVar1;
  if (bVar1 == 1) {
    uVar11 = param_1[4] - 1 & 0xff;
    if (3 < uVar11) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_test.c",400,*(code **)(_r_plf_funcs_p + 8));
    }
    uVar9 = 0;
  }
  else if (bVar1 == 0) {
    uVar9 = (uint)(byte)(param_1[4] - 1);
    if ((param_1[4] - 1 & 0xfc) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_test.c",399,*(code **)(_r_plf_funcs_p + 8));
    }
  }
  else {
    uVar9 = 0;
    uVar11 = 0;
  }
  iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  iVar8 = _r_plf_funcs_p;
  *(ushort *)(iVar5 + 4) = (ushort)(uVar9 << 2) | uVar11 | 0x1000;
  iVar5 = (**(code **)(iVar8 + 0xbc))(0x400,*(code **)(iVar8 + 0xbc));
  iVar8 = _r_plf_funcs_p;
  *(undefined2 *)(iVar5 + 0x4a) = 0;
  iVar5 = (**(code **)(iVar8 + 0xbc))(0x400,*(code **)(iVar8 + 0xbc));
  iVar8 = _r_plf_funcs_p;
  *(undefined2 *)(iVar5 + 0x4c) = 0;
  iVar8 = (**(code **)(iVar8 + 0xbc))(0x400,*(code **)(iVar8 + 0xbc));
  pcVar10 = _r_ip_funcs_p;
  *(undefined2 *)(iVar8 + 0x4e) = 0;
  *(undefined4 *)((int)__s + 4) = uVar4;
  iVar8 = (**(code **)(pcVar10 + 0x6b0))(__s,*(code **)(pcVar10 + 0x6b0));
  if (iVar8 == 0) {
    *(undefined1 *)((int)__s + 0x2a) = 0;
  }
  else {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_test.c",0x314,*(code **)(_r_plf_funcs_p + 8));
  }
  return 0;
}

