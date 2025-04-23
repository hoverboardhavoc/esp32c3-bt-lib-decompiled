/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_init.o -> r_lld_init_start
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 r_lld_init_start(undefined2 *param_1)

{
  byte bVar1;
  char cVar2;
  byte bVar3;
  byte bVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  undefined2 uVar7;
  undefined2 uVar8;
  undefined2 uVar9;
  undefined2 uVar10;
  ushort uVar11;
  byte bVar12;
  byte bVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  void *pvVar17;
  int iVar18;
  byte *pbVar19;
  short sVar20;
  undefined1 *puVar21;
  ushort uVar22;
  int *piVar23;
  undefined4 uVar24;
  uint uVar25;
  int *piVar26;
  code *pcVar27;
  uint uVar28;
  int iVar29;
  uint *puVar30;
  int iVar31;
  uint uVar32;
  int *piStack_f0;
  ushort uStack_ec;
  undefined1 uStack_b3;
  byte bStack_b2;
  byte bStack_b1;
  undefined1 auStack_b0 [4];
  undefined1 auStack_ac [3];
  undefined1 uStack_a9;
  undefined2 uStack_a8;
  undefined2 uStack_a6;
  undefined2 uStack_a4;
  undefined2 uStack_a2;
  undefined1 auStack_a0 [5];
  byte bStack_9b;
  undefined1 auStack_98 [100];
  
  bVar1 = *(byte *)((int)param_1 + 0x13);
  uStack_b3 = 0xc;
  uVar14 = (**(code **)(_r_ip_funcs_p + 0x264))(*(code **)(_r_ip_funcs_p + 0x264));
  uVar15 = (**(code **)(_r_osi_funcs_p + 0x88))(*(code **)(_r_osi_funcs_p + 0x88));
  iVar16 = (**(code **)(_r_ip_funcs_p + 0x838))
                     (1,&uStack_b3,param_1,*(code **)(_r_ip_funcs_p + 0x838));
  if (iVar16 != 0) {
    return uStack_b3;
  }
  if (_lld_init_env != (int *)0x0) goto _L293;
  piStack_f0 = (int *)(**(code **)(_r_modules_funcs_p + 0x120))
                                (0x5c,0,*(code **)(_r_modules_funcs_p + 0x120));
  _lld_init_env = piStack_f0;
  if (piStack_f0 == (int *)0x0) {
    (**(code **)(_r_plf_funcs_p + 8))(0x10000,0x819,*(code **)(_r_plf_funcs_p + 8));
    goto _L293;
  }
  memset(piStack_f0,0,0x5c);
  *(undefined1 *)(piStack_f0 + 0xb) = *(undefined1 *)((int)param_1 + 0x13);
  *(undefined1 *)((int)piStack_f0 + 0x32) = *(undefined1 *)(param_1 + 10);
  *(undefined1 *)((int)piStack_f0 + 0x33) = *(undefined1 *)((int)param_1 + 0x15);
  *(undefined1 *)((int)piStack_f0 + 0x4f) = *(undefined1 *)(param_1 + 0xb);
  memcpy((void *)((int)piStack_f0 + 0x3e),param_1,6);
  memcpy(piStack_f0 + 0x11,param_1 + 3,6);
  memcpy((void *)((int)piStack_f0 + 0x2d),param_1 + 6,5);
  (**(code **)(_r_ip_funcs_p + 0x220))
            (piStack_f0 + 0xd,*(undefined1 *)((int)param_1 + 0x13),*(code **)(_r_ip_funcs_p + 0x220)
            );
  *(short *)(piStack_f0 + 0xe) = (short)uVar15;
  iVar16 = _p_lld_env;
  *(char *)((int)piStack_f0 + 0x3a) = (char)((uVar15 & 0xffffff) >> 0x10);
  *(undefined1 *)((int)piStack_f0 + 0x3b) = 2;
  bVar13 = (char)((uVar15 & 0xffffff) % 0xc) + 5;
  *(byte *)(piStack_f0 + 0xf) = bVar13;
  cVar2 = *(char *)(iVar16 + 0xd6);
  *(char *)((int)piStack_f0 + 0x3d) = cVar2;
  memcpy(auStack_b0,piStack_f0 + 0xd,4);
  memcpy(auStack_ac,piStack_f0 + 0xe,3);
  uStack_a9 = 2;
  uStack_a8 = 0;
  memcpy(auStack_a0,param_1 + 6,5);
  uVar7 = param_1[0xe];
  uVar8 = param_1[0xf];
  uVar9 = param_1[0x10];
  uVar10 = param_1[0x11];
  bStack_9b = bVar13 | cVar2 << 5;
  piVar23 = piStack_f0 + 3;
  do {
    *(undefined2 *)piVar23 = uVar7;
    *(undefined2 *)((int)piVar23 + 2) = uVar8;
    *(undefined2 *)(piVar23 + 1) = uVar9;
    *(undefined2 *)((int)piVar23 + 6) = uVar10;
    *(undefined1 *)(piVar23 + 2) = 0;
    piVar23 = (int *)((int)piVar23 + 10);
  } while ((int *)((int)piStack_f0 + 0x2a) != piVar23);
  bVar13 = *(byte *)(param_1 + 9);
  uVar15 = 0;
  if ((bVar13 & 1) != 0) {
    pvVar17 = (void *)(**(code **)(_r_modules_funcs_p + 0x120))
                                (0x54,0,*(code **)(_r_modules_funcs_p + 0x120));
    *piStack_f0 = (int)pvVar17;
    if (pvVar17 == (void *)0x0) {
      (**(code **)(_r_plf_funcs_p + 8))(0x10000,0x6d3,*(code **)(_r_plf_funcs_p + 8));
    }
    else {
      memset(pvVar17,0,0x54);
      uVar24 = *(undefined4 *)(_r_ip_funcs_p + 0x45c);
      *(undefined4 *)((int)pvVar17 + 0x20) = *(undefined4 *)(_r_ip_funcs_p + 0x458);
      *(undefined4 *)((int)pvVar17 + 0x18) = uVar24;
      *(undefined1 *)((int)pvVar17 + 0x16) = DAT_00013022;
      uVar11 = param_1[0xd];
      uVar15 = (uint)uVar11 * 0x4e2;
      if (_sch_slice_params < uVar15) {
        uVar15 = (uint)_sch_slice_params;
      }
      *(uint *)((int)pvVar17 + 0x10) = uVar15;
      *(ushort *)((int)pvVar17 + 0x14) = DAT_00013023 & 0xf | 0x6000;
      uVar7 = param_1[0xc];
      *(ushort *)((int)pvVar17 + 0x2e) = uVar11;
      *(uint *)((int)pvVar17 + 0x24) = (uint)uVar11;
      *(undefined2 *)((int)pvVar17 + 0x2c) = uVar7;
      *(undefined1 *)((int)pvVar17 + 0x3c) = 0x7f;
      *(undefined1 *)((int)pvVar17 + 0x3e) = 1;
      *(undefined1 *)((int)pvVar17 + 0x52) = *(undefined1 *)((int)param_1 + 0x13);
      *(undefined2 *)(piStack_f0 + 3) = param_1[0xe];
      *(undefined2 *)((int)piStack_f0 + 0xe) = param_1[0xf];
      *(undefined2 *)(piStack_f0 + 4) = param_1[0x10];
      uVar7 = param_1[0x11];
      *(undefined1 *)(piStack_f0 + 5) = 0;
      *(undefined2 *)((int)piStack_f0 + 0x12) = uVar7;
      *(byte *)((int)piStack_f0 + 0x2b) = *(byte *)((int)piStack_f0 + 0x2b) | 1;
      uVar15 = bVar13 & 1;
    }
  }
  uStack_a6 = (undefined2)piStack_f0[3];
  uStack_a4 = (undefined2)piStack_f0[4];
  uStack_a2 = *(undefined2 *)((int)piStack_f0 + 0x12);
  (**(code **)(_r_ip_funcs_p + 0x450))(auStack_98,auStack_b0,*(code **)(_r_ip_funcs_p + 0x450));
  pvVar17 = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))(0x7400,*(code **)(_r_plf_funcs_p + 0xbc));
  memcpy(pvVar17,auStack_98,0x16);
  if ((*(byte *)(param_1 + 9) & 2) != 0) {
    *(undefined2 *)((int)piStack_f0 + 0x16) = param_1[uVar15 * 6 + 0xe];
    *(undefined2 *)(piStack_f0 + 6) = param_1[uVar15 * 6 + 0xf];
    uVar7 = param_1[uVar15 * 6 + 0x10];
    uVar8 = param_1[uVar15 * 6 + 0x11];
    *(char *)((int)piStack_f0 + 0x1e) = (char)uVar15;
    uVar15 = uVar15 + 1;
    *(undefined2 *)((int)piStack_f0 + 0x1a) = uVar7;
    *(undefined2 *)(piStack_f0 + 7) = uVar8;
  }
  uStack_a6 = *(undefined2 *)((int)piStack_f0 + 0x16);
  uStack_a4 = *(undefined2 *)((int)piStack_f0 + 0x1a);
  uStack_a2 = (undefined2)piStack_f0[7];
  (**(code **)(_r_ip_funcs_p + 0x450))(auStack_98,auStack_b0,*(code **)(_r_ip_funcs_p + 0x450));
  pvVar17 = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))(0x7422,*(code **)(_r_plf_funcs_p + 0xbc));
  memcpy(pvVar17,auStack_98,0x16);
  if ((*(byte *)(param_1 + 9) & 4) != 0) {
    pvVar17 = (void *)(**(code **)(_r_modules_funcs_p + 0x120))
                                (0x54,0,*(code **)(_r_modules_funcs_p + 0x120));
    piStack_f0[1] = (int)pvVar17;
    if (pvVar17 == (void *)0x0) {
      (**(code **)(_r_plf_funcs_p + 8))(0x10000,0x734,*(code **)(_r_plf_funcs_p + 8));
    }
    else {
      memset(pvVar17,0,0x54);
      uVar24 = *(undefined4 *)(_r_ip_funcs_p + 0x45c);
      *(undefined4 *)((int)pvVar17 + 0x20) = *(undefined4 *)(_r_ip_funcs_p + 0x458);
      *(undefined4 *)((int)pvVar17 + 0x18) = uVar24;
      *(undefined1 *)((int)pvVar17 + 0x16) = DAT_00013022;
      uVar11 = param_1[uVar15 * 6 + 0xd];
      uVar25 = (uint)uVar11 * 0x4e2;
      if (_sch_slice_params < uVar25) {
        uVar25 = (uint)_sch_slice_params;
      }
      *(uint *)((int)pvVar17 + 0x10) = uVar25;
      *(ushort *)((int)pvVar17 + 0x14) = DAT_00013023 & 0xf | 0x6000;
      uVar7 = param_1[uVar15 * 6 + 0xc];
      *(ushort *)((int)pvVar17 + 0x2e) = uVar11;
      *(uint *)((int)pvVar17 + 0x24) = (uint)uVar11;
      *(undefined2 *)((int)pvVar17 + 0x2c) = uVar7;
      *(undefined1 *)((int)pvVar17 + 0x30) = 3;
      *(undefined1 *)((int)pvVar17 + 0x51) = 1;
      *(undefined1 *)((int)pvVar17 + 0x3e) = 1;
      *(undefined1 *)((int)pvVar17 + 0x3c) = 0x7f;
      *(undefined1 *)((int)pvVar17 + 0x52) = 10;
      *(undefined2 *)(piStack_f0 + 8) = param_1[uVar15 * 6 + 0xe];
      *(undefined2 *)((int)piStack_f0 + 0x22) = param_1[uVar15 * 6 + 0xf];
      uVar7 = param_1[uVar15 * 6 + 0x10];
      uVar8 = param_1[uVar15 * 6 + 0x11];
      *(char *)(piStack_f0 + 10) = (char)uVar15;
      *(undefined2 *)(piStack_f0 + 9) = uVar7;
      *(undefined2 *)((int)piStack_f0 + 0x26) = uVar8;
      *(byte *)((int)piStack_f0 + 0x2b) = *(byte *)((int)piStack_f0 + 0x2b) | 2;
    }
  }
  uStack_a6 = (undefined2)piStack_f0[8];
  uStack_a4 = (undefined2)piStack_f0[9];
  uStack_a2 = *(undefined2 *)((int)piStack_f0 + 0x26);
  (**(code **)(_r_ip_funcs_p + 0x450))(auStack_98,auStack_b0,*(code **)(_r_ip_funcs_p + 0x450));
  pvVar17 = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))(0x7444,*(code **)(_r_plf_funcs_p + 0xbc));
  memcpy(pvVar17,auStack_98,0x16);
  *(undefined1 *)((int)piStack_f0 + 0x2a) = *(undefined1 *)((int)param_1 + 0x11);
  if (((*(byte *)(param_1 + 10) & 2) == 0) && (*(char *)(param_1 + 0x1e) == '\0')) {
_L306:
    uStack_ec = 0;
_L397:
    uVar15 = 0;
  }
  else {
    if (*(char *)(param_1 + 0xb) != '\0') {
      uStack_ec = 1;
      goto _L397;
    }
    uVar15 = (**(code **)(_r_ip_funcs_p + 0x260))
                       (param_1 + 3,*(undefined1 *)((int)param_1 + 0x15),
                        *(code **)(_r_ip_funcs_p + 0x260));
    if (9 < uVar15) goto _L306;
    uVar15 = uVar15 * 0x34 + 0xc60 & 0xffff;
    uStack_ec = 1;
  }
  uVar25 = (uint)bVar1 * 9 & 0xff;
  uVar11 = param_1[10];
  *(bool *)((int)piStack_f0 + 0x4a) = uVar15 != 0;
  sVar20 = (short)uVar25 * 0xe + 0x1400;
  piVar26 = piStack_f0 + 2;
  piVar23 = piStack_f0;
  do {
    iVar16 = *piVar23;
    bStack_b2 = 0;
    bStack_b1 = 0;
    if (iVar16 != 0) {
      bVar1 = *(byte *)(iVar16 + 0x52);
      uVar32 = (uint)bVar1;
      uVar22 = *(byte *)((int)param_1 + 0x11) + 0xe & 0xff;
      (**(code **)(_r_ip_funcs_p + 0x490))(uVar32,uVar22,*(code **)(_r_ip_funcs_p + 0x490));
      iVar18 = piStack_f0[3];
      iVar29 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar31 = uVar32 * 0x5a;
      *(short *)(iVar31 + 0x22 + iVar29) = (short)iVar18;
      uVar7 = *(undefined2 *)((int)piStack_f0 + 0x16);
      iVar18 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar31 + 0x38 + iVar18) = uVar7;
      iVar18 = piStack_f0[8];
      iVar29 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(short *)(iVar31 + 0x3c + iVar29) = (short)iVar18;
      iVar18 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(short *)(iVar31 + 0x1c + iVar18) = sVar20;
      iVar18 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(short *)(iVar31 + 0x34 + iVar18) = sVar20;
      (**(code **)(_r_modules_funcs_p + 0x1e0))
                (uVar22,uVar32,&bStack_b2,&bStack_b1,*(code **)(_r_modules_funcs_p + 0x1e0));
      bVar12 = bStack_b1;
      bVar4 = bStack_b2;
      uVar28 = (uint)DAT_00013050;
      bVar13 = DAT_00013050 >> 1;
      bVar3 = DAT_00013050 >> 2;
      if ((bStack_b2 & 0xfe) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x41,*(code **)(_r_plf_funcs_p + 8));
      }
      if ((bVar12 & 0xfe) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x42,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar29 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar18 = _r_plf_funcs_p;
      *(ushort *)(iVar29 + iVar31) =
           (ushort)bVar4 << 8 | (ushort)bVar12 << 7 | (ushort)((uVar28 & 1) << 10) |
           (ushort)((bVar13 & 1) << 9) | (ushort)((bVar3 & 1) << 5) | uVar22;
      iVar18 = (**(code **)(iVar18 + 0xbc))(0x400,*(code **)(iVar18 + 0xbc));
      *(undefined2 *)(iVar31 + 0xc + iVar18) = 0xbed6;
      iVar18 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar31 + 0xe + iVar18) = 0x8e89;
      iVar18 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar31 + 0x10 + iVar18) = 0x5555;
      iVar18 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar31 + 0x12 + iVar18) = 0x55;
      iVar18 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar31 + 0x46 + iVar18) = 0;
      bVar13 = *(byte *)(param_1 + 0xb);
      bVar3 = *(byte *)(param_1 + 0x1e);
      bVar4 = *(byte *)((int)piStack_f0 + 0x4a);
      iVar18 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar31 + 0x14 + iVar18) =
           (ushort)bVar13 << 8 | (ushort)bVar3 << 6 | (ushort)((uVar11 >> 1 & 1) << 2) |
           (ushort)bVar4 << 1 | uStack_ec;
      if (*(char *)((int)piStack_f0 + 0x4a) != '\0') {
        iVar18 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
        *(short *)(iVar31 + 0x2c + iVar18) = (short)uVar15;
      }
      if ((*(char *)(param_1 + 0xb) == '\0') && (*(char *)((int)piStack_f0 + 0x4a) == '\0')) {
        puVar21 = (undefined1 *)((int)param_1 + 7);
        iVar18 = 0;
        do {
          uVar5 = *puVar21;
          uVar6 = puVar21[-1];
          iVar29 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
          *(ushort *)(iVar29 + iVar31 + 0x2c + iVar18) = CONCAT11(uVar5,uVar6);
          iVar18 = iVar18 + 2;
          puVar21 = puVar21 + 2;
        } while (iVar18 != 6);
        bVar13 = *(byte *)((int)param_1 + 0x15);
        iVar18 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
        *(ushort *)(iVar31 + 0x32 + iVar18) = bVar13 & 1;
      }
      iVar18 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar31 + 0x16 + iVar18) = 0x8027;
      iVar18 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar31 + 0x28 + iVar18) = 0;
      iVar18 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar31 + 0x2a + iVar18) = 0;
      bVar13 = *(byte *)(param_1 + 10);
      if (0x1f < uVar32) {
        (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0xe6,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar18 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar31 + 2 + iVar18) = (ushort)((bVar13 & 1) << 7) | (ushort)bVar1 | 0x800;
      uVar7 = *param_1;
      iVar18 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar31 + 6 + iVar18) = uVar7;
      uVar7 = param_1[1];
      iVar18 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar31 + 8 + iVar18) = uVar7;
      uVar7 = param_1[2];
      iVar18 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar31 + 10 + iVar18) = uVar7;
      bVar1 = *(byte *)(iVar16 + 0x30);
      if ((bVar1 & 0xfc) == 0) {
        if (3 < bVar1) goto _L317;
      }
      else {
        (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,399,*(code **)(_r_plf_funcs_p + 8));
_L317:
        (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,400,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar18 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar31 + 4 + iVar18) =
           (ushort)bVar1 | (ushort)((int)(short)(ushort)bVar1 << 2) | 0x2000;
      uVar7 = *(undefined2 *)(iVar16 + 0x24);
      iVar18 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar31 + 0x20 + iVar18) = uVar7;
      iVar16 = *(int *)(iVar16 + 0x24);
      if (iVar16 << 0x10 < 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x4ab,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar18 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      bVar1 = *(byte *)((int)param_1 + 0x11);
      pcVar27 = *(code **)(_r_modules_funcs_p + 0x1a0);
      *(ushort *)(iVar31 + 0x1a + iVar18) = (ushort)iVar16 | 0x8000;
      pbVar19 = (byte *)(*pcVar27)(bVar1 + 9,pcVar27);
      if (pbVar19 != (byte *)0x0) {
        bVar1 = pbVar19[1];
        if (0xb < uVar32) {
          (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x299b,*(code **)(_r_plf_funcs_p + 8));
        }
        if ((bVar1 & 0xf0) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x299d,*(code **)(_r_plf_funcs_p + 8));
        }
        puVar30 = (uint *)((uVar32 + 0x1800c4cb) * 4);
        *puVar30 = *puVar30 & 0xfffff0ff | (uint)bVar1 << 8;
        bVar1 = *pbVar19;
        if (0xb < uVar32) {
          (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x294a,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar30 = *puVar30 & 0xbfffffff | (uint)bVar1 << 0x1e;
        bVar1 = pbVar19[3];
        if (0xb < uVar32) {
          (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x29bb,*(code **)(_r_plf_funcs_p + 8));
        }
        if (0xf < bVar1) {
          (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x29bd,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar30 = *puVar30 & 0xfffffff0 | (uint)bVar1;
        bVar1 = pbVar19[2];
        if (0xb < uVar32) {
          (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x295a,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar30 = *puVar30 & 0xdfffffff | (uint)bVar1 << 0x1d;
        bVar1 = pbVar19[7];
        if (0xb < uVar32) {
          (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x298b,*(code **)(_r_plf_funcs_p + 8));
        }
        if ((bVar1 & 0xf0) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x298d,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar30 = *puVar30 & 0xffff0fff | (uint)bVar1 << 0xc;
        bVar1 = pbVar19[8];
        if (0xb < uVar32) {
          (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x29ab,*(code **)(_r_plf_funcs_p + 8));
        }
        if ((bVar1 & 0xf0) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x29ad,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar30 = *puVar30 & 0xffffff0f | (uint)bVar1 << 4;
        bVar1 = pbVar19[9];
        if (0xb < uVar32) {
          (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x297b,*(code **)(_r_plf_funcs_p + 8));
        }
        if ((bVar1 & 0xf0) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x297d,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar30 = *puVar30 & 0xfff0ffff | (uint)bVar1 << 0x10;
        uVar22 = *(ushort *)(pbVar19 + 10);
        if (0xb < uVar32) {
          (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x296a,*(code **)(_r_plf_funcs_p + 8));
        }
        if ((uVar22 >> 9 & 7) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x296c,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar30 = *puVar30 & 0xe00fffff | (uint)uVar22 << 0x14;
        bVar1 = pbVar19[6];
        if (0xb < uVar32) {
          (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x293a,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar30 = *puVar30 & 0x7fffffff | (uint)bVar1 << 0x1f;
        if (2 < _g_bt_plf_log_level) {
          ets_printf("PTI CNTL CS[%d] REG[%08x] TYPE[INITIATOR] RXEN[%d] RX[%d] IFSEN[%d] IFS[%d] PRTEN[%d] TIME[%d] DIFS[%d] DRX[%d] DTX[%d]\n"
                     ,uVar32,puVar30,pbVar19[2],pbVar19[3],*pbVar19,pbVar19[1],pbVar19[6]);
        }
      }
    }
    piVar23 = piVar23 + 1;
  } while (piVar26 != piVar23);
  iVar16 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  iVar29 = uVar25 * 0xe;
  iVar31 = iVar29 + 2;
  uVar11 = *(ushort *)(iVar16 + iVar31);
  iVar16 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  pcVar27 = *(code **)(_r_plf_funcs_p + 0xbc);
  *(ushort *)(iVar16 + iVar31) = uVar11 & 0xfff0 | 5;
  iVar16 = (*pcVar27)(0x1400,pcVar27);
  *(undefined2 *)(iVar29 + 4 + iVar16) = 0x7400;
  iVar16 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar11 = *(ushort *)(iVar16 + iVar31);
  iVar18 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  iVar16 = _r_plf_funcs_p;
  *(ushort *)(iVar18 + iVar31) = uVar11 & 0xff | 0x2200;
  iVar16 = (**(code **)(iVar16 + 0xbc))(0x1400,*(code **)(iVar16 + 0xbc));
  uVar11 = *(ushort *)(iVar16 + iVar29);
  iVar16 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(ushort *)(iVar16 + iVar29) = uVar11 & 0x8000;
  bVar1 = *(byte *)((int)param_1 + 0x15);
  iVar16 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  pcVar27 = *(code **)(_r_plf_funcs_p + 0xbc);
  *(ushort *)(iVar31 + iVar16) = (ushort)((bVar1 & 1) << 7) | 0x2225;
  iVar16 = (*pcVar27)(0x1400,pcVar27);
  uVar11 = *(ushort *)(iVar16 + iVar29);
  iVar18 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  iVar16 = _r_modules_funcs_p;
  *(ushort *)(iVar18 + iVar29) = (ushort)(((uint)uVar11 << 0x11) >> 0x11);
  iVar16 = (**(code **)(iVar16 + 0x1a0))
                     (*(byte *)((int)param_1 + 0x11) + 9,*(code **)(iVar16 + 0x1a0));
  if (iVar16 != 0) {
    if (2 < _g_bt_plf_log_level) {
      ets_printf("TX PTI [Initiator] [EN%d] [%d] \n",*(undefined1 *)(iVar16 + 4),
                 *(undefined1 *)(iVar16 + 5));
    }
    bVar1 = *(byte *)(iVar16 + 5);
    if ((bVar1 & 0xf0) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x33f,*(code **)(_r_plf_funcs_p + 8));
    }
    iVar29 = iVar29 + 10;
    iVar18 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar11 = *(ushort *)(iVar18 + iVar29);
    iVar18 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    pcVar27 = *(code **)(_r_plf_funcs_p + 0xbc);
    *(ushort *)(iVar18 + iVar29) = uVar11 & 0xf0ff | (ushort)bVar1 << 8;
    bVar1 = *(byte *)(iVar16 + 4);
    iVar16 = (*pcVar27)(0x1400,pcVar27);
    uVar11 = *(ushort *)(iVar16 + iVar29);
    iVar16 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar16 + iVar29) = uVar11 & 0xefff | (ushort)bVar1 << 0xc;
  }
  piStack_f0[2] = 0;
  do {
    iVar16 = *piStack_f0;
    if (iVar16 != 0) {
      pcVar27 = *(code **)(_r_ip_funcs_p + 0x6b0);
      *(uint *)(iVar16 + 4) = uVar14;
      *(uint *)(iVar16 + 0x28) = uVar14;
      iVar18 = (*pcVar27)(iVar16,pcVar27);
      if (iVar18 == 0) {
        *(undefined1 *)(iVar16 + 0x50) = 0;
        uVar14 = (uint)*(ushort *)(iVar16 + 0x2e) * 2 + uVar14 & 0xfffffff;
      }
      else {
        (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x811,*(code **)(_r_plf_funcs_p + 8));
      }
      uStack_b3 = 0;
    }
    piStack_f0 = piStack_f0 + 1;
  } while (piStack_f0 != piVar26);
_L293:
  (**(code **)(_r_ip_funcs_p + 0x838))(0,&uStack_b3,param_1,*(code **)(_r_ip_funcs_p + 0x838));
  return uStack_b3;
}

