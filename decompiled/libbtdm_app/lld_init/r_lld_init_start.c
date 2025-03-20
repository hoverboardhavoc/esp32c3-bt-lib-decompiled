/*
 * Last changed at upstream commit daab5dbba958a13041bd496e4a6ed506c9284a06
 * https://github.com/espressif/esp32c3-bt-lib/commit/daab5dbba958a13041bd496e4a6ed506c9284a06
 * Upstream date: 2025-03-20 20:43:40 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(86a4da5c)
 * Source: libbtdm_app -> lld_init.o -> r_lld_init_start
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

undefined1 r_lld_init_start(undefined2 *param_1)

{
  byte bVar1;
  undefined1 uVar2;
  char cVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  undefined1 uVar7;
  undefined2 uVar8;
  undefined2 uVar9;
  undefined2 uVar10;
  undefined2 uVar11;
  uint uVar12;
  uint uVar13;
  byte bVar14;
  uint uVar15;
  uint uVar16;
  int iVar17;
  void *pvVar18;
  int iVar19;
  byte *pbVar20;
  undefined4 uVar21;
  uint uVar22;
  short sVar23;
  int *piVar24;
  undefined4 uVar25;
  int *piVar26;
  code *pcVar27;
  undefined1 *puVar28;
  int iVar29;
  int iVar30;
  uint *puVar31;
  uint uVar32;
  ushort uVar33;
  int iVar34;
  uint uVar35;
  uint uVar36;
  uint uStack_f8;
  int *piStack_f4;
  ushort uStack_f0;
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
  
  uStack_b3 = 0xc;
  bVar1 = *(byte *)((int)param_1 + 0x13);
  uVar15 = (**(code **)(_r_ip_funcs_p + 0x264))(*(code **)(_r_ip_funcs_p + 0x264));
  uVar16 = (**(code **)(_r_osi_funcs_p + 0x88))(*(code **)(_r_osi_funcs_p + 0x88));
  iVar17 = (**(code **)(_r_ip_funcs_p + 0x838))
                     (1,&uStack_b3,param_1,*(code **)(_r_ip_funcs_p + 0x838));
  if (iVar17 != 0) {
    return uStack_b3;
  }
  if (_lld_init_env != (int *)0x0) goto _L296;
  piStack_f4 = (int *)(**(code **)(_r_modules_funcs_p + 0x120))
                                (0x5c,0,*(code **)(_r_modules_funcs_p + 0x120));
  _lld_init_env = piStack_f4;
  if (piStack_f4 == (int *)0x0) {
    (**(code **)(_r_plf_funcs_p + 8))("lld_init.c",0x819,*(code **)(_r_plf_funcs_p + 8));
    goto _L296;
  }
  uVar16 = uVar16 & 0xffffff;
  memset(piStack_f4,0,0x5c);
  *(undefined1 *)(piStack_f4 + 0xb) = *(undefined1 *)((int)param_1 + 0x13);
  *(undefined1 *)((int)piStack_f4 + 0x32) = *(undefined1 *)(param_1 + 10);
  *(undefined1 *)((int)piStack_f4 + 0x33) = *(undefined1 *)((int)param_1 + 0x15);
  uVar2 = *(undefined1 *)(param_1 + 0xb);
  *(undefined1 *)(piStack_f4 + 0x14) = 0;
  *(undefined1 *)(piStack_f4 + 0x16) = 0;
  *(undefined1 *)((int)piStack_f4 + 0x4f) = uVar2;
  memcpy((void *)((int)piStack_f4 + 0x3e),param_1,6);
  memcpy(piStack_f4 + 0x11,param_1 + 3,6);
  memcpy((void *)((int)piStack_f4 + 0x2d),param_1 + 6,5);
  (**(code **)(_r_ip_funcs_p + 0x220))
            (piStack_f4 + 0xd,*(undefined1 *)((int)param_1 + 0x13),*(code **)(_r_ip_funcs_p + 0x220)
            );
  *(short *)(piStack_f4 + 0xe) = (short)uVar16;
  iVar17 = _p_lld_env;
  *(char *)((int)piStack_f4 + 0x3a) = (char)(uVar16 >> 0x10);
  *(undefined1 *)((int)piStack_f4 + 0x3b) = 2;
  bVar14 = (char)(uVar16 % 0xc) + 5;
  *(byte *)(piStack_f4 + 0xf) = bVar14;
  cVar3 = *(char *)(iVar17 + 0xd6);
  *(char *)((int)piStack_f4 + 0x3d) = cVar3;
  memcpy(auStack_b0,piStack_f4 + 0xd,4);
  memcpy(auStack_ac,piStack_f4 + 0xe,3);
  uStack_a9 = 2;
  uStack_a8 = 0;
  memcpy(auStack_a0,param_1 + 6,5);
  uVar8 = param_1[0xe];
  uVar9 = param_1[0xf];
  uVar10 = param_1[0x10];
  uVar11 = param_1[0x11];
  bStack_9b = cVar3 << 5 | bVar14;
  piVar24 = piStack_f4 + 3;
  do {
    *(undefined2 *)piVar24 = uVar8;
    *(undefined2 *)((int)piVar24 + 2) = uVar9;
    *(undefined2 *)(piVar24 + 1) = uVar10;
    *(undefined2 *)((int)piVar24 + 6) = uVar11;
    *(undefined1 *)(piVar24 + 2) = 0;
    piVar24 = (int *)((int)piVar24 + 10);
  } while ((int *)((int)piStack_f4 + 0x2a) != piVar24);
  iVar17 = 0;
  if ((*(byte *)(param_1 + 9) & 1) != 0) {
    pvVar18 = (void *)(**(code **)(_r_modules_funcs_p + 0x120))
                                (0x54,0,*(code **)(_r_modules_funcs_p + 0x120));
    *piStack_f4 = (int)pvVar18;
    if (pvVar18 == (void *)0x0) {
      (**(code **)(_r_plf_funcs_p + 8))("lld_init.c",0x6d3,*(code **)(_r_plf_funcs_p + 8));
    }
    else {
      memset(pvVar18,0,0x54);
      uVar21 = *(undefined4 *)(_r_ip_funcs_p + 0x458);
      uVar25 = *(undefined4 *)(_r_ip_funcs_p + 0x45c);
      *(undefined4 *)((int)pvVar18 + 0x1c) = 0;
      *(undefined4 *)((int)pvVar18 + 0x20) = uVar21;
      *(undefined4 *)((int)pvVar18 + 0x18) = uVar25;
      uVar2 = DAT_00013022;
      *(undefined4 *)((int)pvVar18 + 8) = 0;
      *(undefined1 *)((int)pvVar18 + 0x16) = uVar2;
      uVar33 = param_1[0xd];
      uVar16 = (uint)uVar33 * 0x4e2;
      if (_sch_slice_params < uVar16) {
        uVar16 = (uint)_sch_slice_params;
      }
      *(uint *)((int)pvVar18 + 0x10) = uVar16;
      iVar17 = 1;
      *(ushort *)((int)pvVar18 + 0x14) = DAT_00013023 & 0xf | 0x6000;
      uVar8 = param_1[0xc];
      *(undefined1 *)((int)pvVar18 + 0x30) = 0;
      *(undefined1 *)((int)pvVar18 + 0x51) = 0;
      *(undefined2 *)((int)pvVar18 + 0x2c) = uVar8;
      *(undefined2 *)((int)pvVar18 + 0x3c) = 0x7f;
      *(undefined1 *)((int)pvVar18 + 0x3e) = 1;
      *(ushort *)((int)pvVar18 + 0x2e) = uVar33;
      *(uint *)((int)pvVar18 + 0x24) = (uint)uVar33;
      *(undefined1 *)((int)pvVar18 + 0x52) = *(undefined1 *)((int)param_1 + 0x13);
      *(undefined2 *)(piStack_f4 + 3) = param_1[0xe];
      *(undefined2 *)((int)piStack_f4 + 0xe) = param_1[0xf];
      *(undefined2 *)(piStack_f4 + 4) = param_1[0x10];
      uVar8 = param_1[0x11];
      *(undefined1 *)(piStack_f4 + 5) = 0;
      *(undefined2 *)((int)piStack_f4 + 0x12) = uVar8;
      *(byte *)((int)piStack_f4 + 0x2b) = *(byte *)((int)piStack_f4 + 0x2b) | 1;
    }
  }
  uStack_a6 = (undefined2)piStack_f4[3];
  uStack_a4 = (undefined2)piStack_f4[4];
  uStack_a2 = *(undefined2 *)((int)piStack_f4 + 0x12);
  (**(code **)(_r_ip_funcs_p + 0x450))(auStack_98,auStack_b0,*(code **)(_r_ip_funcs_p + 0x450));
  pvVar18 = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))(0x7400,*(code **)(_r_plf_funcs_p + 0xbc));
  memcpy(pvVar18,auStack_98,0x16);
  if ((*(byte *)(param_1 + 9) & 2) != 0) {
    *(undefined2 *)((int)piStack_f4 + 0x16) = param_1[iVar17 * 6 + 0xe];
    *(undefined2 *)(piStack_f4 + 6) = param_1[iVar17 * 6 + 0xf];
    uVar8 = param_1[iVar17 * 6 + 0x10];
    uVar9 = param_1[iVar17 * 6 + 0x11];
    *(char *)((int)piStack_f4 + 0x1e) = (char)iVar17;
    iVar17 = iVar17 + 1;
    *(undefined2 *)((int)piStack_f4 + 0x1a) = uVar8;
    *(undefined2 *)(piStack_f4 + 7) = uVar9;
  }
  uStack_a6 = *(undefined2 *)((int)piStack_f4 + 0x16);
  uStack_a4 = *(undefined2 *)((int)piStack_f4 + 0x1a);
  uStack_a2 = (undefined2)piStack_f4[7];
  (**(code **)(_r_ip_funcs_p + 0x450))(auStack_98,auStack_b0,*(code **)(_r_ip_funcs_p + 0x450));
  pvVar18 = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))(0x7422,*(code **)(_r_plf_funcs_p + 0xbc));
  memcpy(pvVar18,auStack_98,0x16);
  if ((*(byte *)(param_1 + 9) & 4) != 0) {
    pvVar18 = (void *)(**(code **)(_r_modules_funcs_p + 0x120))
                                (0x54,0,*(code **)(_r_modules_funcs_p + 0x120));
    piStack_f4[1] = (int)pvVar18;
    if (pvVar18 == (void *)0x0) {
      (**(code **)(_r_plf_funcs_p + 8))("lld_init.c",0x734,*(code **)(_r_plf_funcs_p + 8));
    }
    else {
      memset(pvVar18,0,0x54);
      uVar21 = *(undefined4 *)(_r_ip_funcs_p + 0x458);
      uVar25 = *(undefined4 *)(_r_ip_funcs_p + 0x45c);
      *(undefined4 *)((int)pvVar18 + 0x1c) = 0;
      *(undefined4 *)((int)pvVar18 + 0x20) = uVar21;
      *(undefined4 *)((int)pvVar18 + 0x18) = uVar25;
      *(undefined1 *)((int)pvVar18 + 0x16) = DAT_00013022;
      uVar33 = param_1[iVar17 * 6 + 0xd];
      uVar16 = (uint)uVar33 * 0x4e2;
      if (_sch_slice_params < uVar16) {
        uVar16 = (uint)_sch_slice_params;
      }
      *(uint *)((int)pvVar18 + 0x10) = uVar16;
      *(ushort *)((int)pvVar18 + 0x14) = DAT_00013023 & 0xf | 0x6000;
      uVar8 = param_1[iVar17 * 6 + 0xc];
      *(ushort *)((int)pvVar18 + 0x2e) = uVar33;
      *(uint *)((int)pvVar18 + 0x24) = (uint)uVar33;
      *(undefined2 *)((int)pvVar18 + 0x2c) = uVar8;
      *(undefined1 *)((int)pvVar18 + 0x51) = 1;
      *(undefined2 *)((int)pvVar18 + 0x30) = 3;
      *(undefined1 *)((int)pvVar18 + 0x3e) = 1;
      *(undefined2 *)((int)pvVar18 + 0x3c) = 0x7f;
      *(undefined1 *)((int)pvVar18 + 0x52) = 10;
      *(undefined2 *)(piStack_f4 + 8) = param_1[iVar17 * 6 + 0xe];
      *(undefined2 *)((int)piStack_f4 + 0x22) = param_1[iVar17 * 6 + 0xf];
      uVar8 = param_1[iVar17 * 6 + 0x10];
      uVar9 = param_1[iVar17 * 6 + 0x11];
      *(char *)(piStack_f4 + 10) = (char)iVar17;
      *(undefined2 *)(piStack_f4 + 9) = uVar8;
      *(undefined2 *)((int)piStack_f4 + 0x26) = uVar9;
      *(byte *)((int)piStack_f4 + 0x2b) = *(byte *)((int)piStack_f4 + 0x2b) | 2;
    }
  }
  uStack_a6 = (undefined2)piStack_f4[8];
  uStack_a4 = (undefined2)piStack_f4[9];
  uStack_a2 = *(undefined2 *)((int)piStack_f4 + 0x26);
  (**(code **)(_r_ip_funcs_p + 0x450))(auStack_98,auStack_b0,*(code **)(_r_ip_funcs_p + 0x450));
  pvVar18 = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))(0x7444,*(code **)(_r_plf_funcs_p + 0xbc));
  memcpy(pvVar18,auStack_98,0x16);
  *(undefined1 *)((int)piStack_f4 + 0x2a) = *(undefined1 *)((int)param_1 + 0x11);
  if (((*(byte *)(param_1 + 10) & 2) == 0) && (*(char *)(param_1 + 0x1e) == '\0')) {
_L308:
    uStack_f0 = 0;
_L417:
    uStack_f8 = 0;
  }
  else {
    if (*(char *)(param_1 + 0xb) != '\0') {
      uStack_f0 = 1;
      goto _L417;
    }
    uVar16 = (**(code **)(_r_ip_funcs_p + 0x260))
                       (param_1 + 3,*(undefined1 *)((int)param_1 + 0x15),
                        *(code **)(_r_ip_funcs_p + 0x260));
    if (9 < uVar16) goto _L308;
    uStack_f8 = uVar16 * 0x34 + 0xc60 & 0xffff;
    uStack_f0 = 1;
  }
  uVar16 = (uint)bVar1 * 9 & 0xff;
  bVar1 = *(byte *)(param_1 + 10);
  *(bool *)((int)piStack_f4 + 0x4a) = uStack_f8 != 0;
  piVar26 = piStack_f4 + 2;
  sVar23 = (short)uVar16 * 0xe + 0x1400;
  piVar24 = piStack_f4;
  do {
    bStack_b2 = 0;
    bStack_b1 = 0;
    iVar17 = *piVar24;
    if (iVar17 != 0) {
      bVar14 = *(byte *)(iVar17 + 0x52);
      uVar32 = (uint)bVar14;
      iVar30 = uVar32 * 0x5a;
      uVar33 = (*(char *)((int)param_1 + 0x11) != '\0') + 0xe;
      (**(code **)(_r_ip_funcs_p + 0x490))(uVar32,uVar33,*(code **)(_r_ip_funcs_p + 0x490));
      iVar19 = piStack_f4[3];
      iVar34 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar29 = _r_plf_funcs_p;
      *(short *)(iVar34 + iVar30 + 0x22) = (short)iVar19;
      uVar8 = *(undefined2 *)((int)piStack_f4 + 0x16);
      iVar19 = (**(code **)(iVar29 + 0xbc))(0x400,*(code **)(iVar29 + 0xbc));
      iVar29 = _r_plf_funcs_p;
      *(undefined2 *)(iVar19 + iVar30 + 0x38) = uVar8;
      iVar19 = piStack_f4[8];
      iVar34 = (**(code **)(iVar29 + 0xbc))(0x400,*(code **)(iVar29 + 0xbc));
      iVar29 = _r_plf_funcs_p;
      *(short *)(iVar34 + iVar30 + 0x3c) = (short)iVar19;
      iVar19 = (**(code **)(iVar29 + 0xbc))(0x400,*(code **)(iVar29 + 0xbc));
      *(short *)(iVar19 + iVar30 + 0x1c) = sVar23;
      iVar19 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(short *)(iVar19 + iVar30 + 0x34) = sVar23;
      (**(code **)(_r_modules_funcs_p + 0x1e0))
                (uVar33,uVar32,&bStack_b2,&bStack_b1,*(code **)(_r_modules_funcs_p + 0x1e0));
      uVar22 = (uint)bStack_b1;
      uVar13 = _g_bt_plf_log_level >> 2;
      uVar35 = _g_bt_plf_log_level & 1;
      uVar36 = (uint)bStack_b2;
      uVar12 = _g_bt_plf_log_level & 2;
      if ((uVar36 << 8 & 0xfffffeff) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_init.c",0x41,*(code **)(_r_plf_funcs_p + 8));
      }
      if ((uVar22 << 7 & 0xffffff7f) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_init.c",0x42,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar19 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      pcVar27 = *(code **)(_r_plf_funcs_p + 0xbc);
      *(ushort *)(iVar19 + iVar30) =
           (ushort)(uVar36 << 8) | (ushort)(uVar22 << 7) | (ushort)(uVar35 << 10) |
           (ushort)(uVar12 << 8) | (ushort)((uVar13 & 1) << 5) | uVar33;
      iVar19 = (*pcVar27)(0x400,pcVar27);
      *(undefined2 *)(iVar19 + iVar30 + 0xc) = 0xbed6;
      iVar19 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar19 + iVar30 + 0xe) = 0x8e89;
      iVar19 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar19 + iVar30 + 0x10) = 0x5555;
      iVar19 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar19 + iVar30 + 0x12) = 0x55;
      iVar19 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar19 + iVar30 + 0x46) = 0;
      bVar4 = *(byte *)(param_1 + 0xb);
      bVar5 = *(byte *)(param_1 + 0x1e);
      bVar6 = *(byte *)((int)piStack_f4 + 0x4a);
      iVar19 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      cVar3 = *(char *)((int)piStack_f4 + 0x4a);
      *(ushort *)(iVar19 + iVar30 + 0x14) =
           (ushort)(((bVar1 & 2) << 0x11) >> 0x10) | (ushort)bVar4 << 8 | (ushort)bVar5 << 6 |
           (ushort)bVar6 << 1 | uStack_f0;
      if (cVar3 != '\0') {
        iVar19 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
        *(short *)(iVar19 + iVar30 + 0x2c) = (short)uStack_f8;
      }
      if ((*(char *)(param_1 + 0xb) == '\0') && (*(char *)((int)piStack_f4 + 0x4a) == '\0')) {
        puVar28 = (undefined1 *)((int)param_1 + 7);
        iVar19 = 0;
        do {
          uVar2 = *puVar28;
          uVar7 = puVar28[-1];
          iVar29 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
          *(ushort *)(iVar29 + iVar30 + 0x2c + iVar19) = CONCAT11(uVar2,uVar7);
          iVar19 = iVar19 + 2;
          puVar28 = puVar28 + 2;
        } while (iVar19 != 6);
        bVar4 = *(byte *)((int)param_1 + 0x15);
        iVar19 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
        *(ushort *)(iVar19 + iVar30 + 0x32) = bVar4 & 1;
      }
      iVar19 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar19 + iVar30 + 0x16) = 0x8027;
      iVar29 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar19 = _r_plf_funcs_p;
      *(undefined2 *)(iVar29 + iVar30 + 0x28) = 0;
      iVar19 = (**(code **)(iVar19 + 0xbc))(0x400,*(code **)(iVar19 + 0xbc));
      *(undefined2 *)(iVar19 + iVar30 + 0x2a) = 0;
      bVar4 = *(byte *)(param_1 + 10);
      if ((bVar14 & 0xe0) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_init.c",0xe6,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar19 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar19 + iVar30 + 2) = (ushort)((bVar4 & 1) << 7) | (ushort)bVar14 | 0x800;
      uVar8 = *param_1;
      iVar19 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar19 + iVar30 + 6) = uVar8;
      uVar8 = param_1[1];
      iVar19 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar19 + iVar30 + 8) = uVar8;
      uVar8 = param_1[2];
      iVar19 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar19 + iVar30 + 10) = uVar8;
      bVar14 = *(byte *)(iVar17 + 0x30);
      if (((uint)bVar14 << 2 & 0xfffffff3) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_init.c",399,*(code **)(_r_plf_funcs_p + 8));
      }
      if ((bVar14 & 0xfc) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_init.c",400,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar29 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar19 = _r_plf_funcs_p;
      *(ushort *)(iVar29 + iVar30 + 4) = (ushort)((uint)bVar14 << 2) | (ushort)bVar14 | 0x2000;
      uVar8 = *(undefined2 *)(iVar17 + 0x24);
      iVar19 = (**(code **)(iVar19 + 0xbc))(0x400,*(code **)(iVar19 + 0xbc));
      *(undefined2 *)(iVar19 + iVar30 + 0x20) = uVar8;
      iVar17 = *(int *)(iVar17 + 0x24);
      if (iVar17 << 0x10 < 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_init.c",0x4ab,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar19 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      cVar3 = *(char *)((int)param_1 + 0x11);
      pcVar27 = *(code **)(_r_modules_funcs_p + 0x1a0);
      *(ushort *)(iVar30 + 0x1a + iVar19) = (ushort)iVar17 | 0x8000;
      pbVar20 = (byte *)(*pcVar27)((cVar3 != '\0') + '\t',pcVar27);
      if (pbVar20 != (byte *)0x0) {
        bVar14 = pbVar20[1];
        if (0xb < uVar32) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_init.c",0x299b,*(code **)(_r_plf_funcs_p + 8));
        }
        if (((uint)bVar14 << 8 & 0xf000) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_init.c",0x299d,*(code **)(_r_plf_funcs_p + 8));
        }
        puVar31 = (uint *)((uVar32 + 0x1800c4cb) * 4);
        *puVar31 = *puVar31 & 0xfffff0ff | (uint)bVar14 << 8;
        bVar14 = *pbVar20;
        if (0xb < uVar32) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_init.c",0x294a,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar31 = (uint)bVar14 << 0x1e | *puVar31 & 0xbfffffff;
        bVar14 = pbVar20[3];
        if (0xb < uVar32) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_init.c",0x29bb,*(code **)(_r_plf_funcs_p + 8));
        }
        if ((bVar14 & 0xf0) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_init.c",0x29bd,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar31 = *puVar31 & 0xfffffff0 | (uint)bVar14;
        bVar14 = pbVar20[2];
        if (0xb < uVar32) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_init.c",0x295a,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar31 = (uint)bVar14 << 0x1d | *puVar31 & 0xdfffffff;
        bVar14 = pbVar20[7];
        if (0xb < uVar32) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_init.c",0x298b,*(code **)(_r_plf_funcs_p + 8));
        }
        if (((uint)bVar14 << 0xc & 0xf0000) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_init.c",0x298d,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar31 = *puVar31 & 0xffff0fff | (uint)bVar14 << 0xc;
        bVar14 = pbVar20[8];
        if (0xb < uVar32) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_init.c",0x29ab,*(code **)(_r_plf_funcs_p + 8));
        }
        if (((uint)bVar14 << 4 & 0xffffff0f) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_init.c",0x29ad,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar31 = *puVar31 & 0xffffff0f | (uint)bVar14 << 4;
        bVar14 = pbVar20[9];
        if (0xb < uVar32) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_init.c",0x297b,*(code **)(_r_plf_funcs_p + 8));
        }
        if (((uint)bVar14 << 0x10 & 0xf00000) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_init.c",0x297d,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar31 = *puVar31 & 0xfff0ffff | (uint)bVar14 << 0x10;
        uVar33 = *(ushort *)(pbVar20 + 10);
        if (0xb < uVar32) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_init.c",0x296a,*(code **)(_r_plf_funcs_p + 8));
        }
        if (((uint)uVar33 << 0x14 & 0xe0000000) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_init.c",0x296c,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar31 = *puVar31 & 0xe00fffff | (uint)uVar33 << 0x14;
        bVar14 = pbVar20[6];
        if (0xb < uVar32) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_init.c",0x293a,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar31 = *puVar31 & 0x7fffffff | (uint)bVar14 << 0x1f;
        if (2 < (int)_g_bt_plf_log_level) {
          ets_printf("PTI CNTL CS[%d] REG[%08x] TYPE[INITIATOR] RXEN[%d] RX[%d] IFSEN[%d] IFS[%d] PRTEN[%d] TIME[%d] DIFS[%d] DRX[%d] DTX[%d]\n"
                     ,uVar32,puVar31,pbVar20[2],pbVar20[3],*pbVar20,pbVar20[1],pbVar20[6]);
        }
      }
    }
    piVar24 = piVar24 + 1;
  } while (piVar26 != piVar24);
  iVar17 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  iVar29 = uVar16 * 0xe;
  iVar34 = iVar29 + 2;
  uVar33 = *(ushort *)(iVar17 + iVar34);
  iVar17 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  pcVar27 = *(code **)(_r_plf_funcs_p + 0xbc);
  *(ushort *)(iVar17 + iVar34) = uVar33 & 0xfff0 | 5;
  iVar17 = (*pcVar27)(0x1400,pcVar27);
  *(undefined2 *)(iVar17 + iVar29 + 4) = 0x7400;
  iVar17 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar33 = *(ushort *)(iVar17 + iVar34);
  iVar19 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  iVar17 = _r_plf_funcs_p;
  *(ushort *)(iVar19 + iVar34) = uVar33 & 0xff | 0x2200;
  iVar17 = (**(code **)(iVar17 + 0xbc))(0x1400,*(code **)(iVar17 + 0xbc));
  uVar33 = *(ushort *)(iVar17 + iVar29);
  iVar19 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  iVar17 = _r_plf_funcs_p;
  *(ushort *)(iVar19 + iVar29) = uVar33 & 0x8000;
  bVar1 = *(byte *)((int)param_1 + 0x15);
  iVar17 = (**(code **)(iVar17 + 0xbc))(0x1400,*(code **)(iVar17 + 0xbc));
  pcVar27 = *(code **)(_r_plf_funcs_p + 0xbc);
  *(ushort *)(iVar17 + iVar34) = (ushort)((bVar1 & 1) << 7) | 0x2225;
  iVar17 = (*pcVar27)(0x1400,pcVar27);
  uVar33 = *(ushort *)(iVar17 + iVar29);
  iVar19 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  iVar17 = _r_modules_funcs_p;
  *(ushort *)(iVar19 + iVar29) = uVar33 & 0x7fff;
  iVar17 = (**(code **)(iVar17 + 0x1a0))
                     ((*(char *)((int)param_1 + 0x11) != '\0') + '\t',*(code **)(iVar17 + 0x1a0));
  if (iVar17 != 0) {
    if (2 < (int)_g_bt_plf_log_level) {
      ets_printf("TX PTI [Initiator] [EN%d] [%d] \n",*(undefined1 *)(iVar17 + 4),
                 *(undefined1 *)(iVar17 + 5));
    }
    uVar16 = (uint)*(byte *)(iVar17 + 5) << 8;
    if ((uVar16 & 0xf000) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_init.c",0x33f,*(code **)(_r_plf_funcs_p + 8));
    }
    iVar29 = iVar29 + 10;
    iVar19 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar33 = *(ushort *)(iVar19 + iVar29);
    iVar19 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    pcVar27 = *(code **)(_r_plf_funcs_p + 0xbc);
    *(ushort *)(iVar19 + iVar29) = uVar33 & 0xf0ff | (ushort)uVar16;
    bVar1 = *(byte *)(iVar17 + 4);
    iVar17 = (*pcVar27)(0x1400,pcVar27);
    uVar33 = *(ushort *)(iVar17 + iVar29);
    iVar17 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar17 + iVar29) = uVar33 & 0xefff | (ushort)bVar1 << 0xc;
  }
  piStack_f4[2] = 0;
  do {
    iVar17 = *piStack_f4;
    if (iVar17 != 0) {
      pcVar27 = *(code **)(_r_ip_funcs_p + 0x6b0);
      *(uint *)(iVar17 + 4) = uVar15;
      *(uint *)(iVar17 + 0x28) = uVar15;
      iVar19 = (*pcVar27)(iVar17,pcVar27);
      if (iVar19 == 0) {
        *(undefined1 *)(iVar17 + 0x50) = 0;
        uVar15 = uVar15 + (uint)*(ushort *)(iVar17 + 0x2e) * 2 & 0xfffffff;
      }
      else {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_init.c",0x811,*(code **)(_r_plf_funcs_p + 8));
      }
      uStack_b3 = 0;
    }
    piStack_f4 = piStack_f4 + 1;
  } while (piVar26 != piStack_f4);
_L296:
  (**(code **)(_r_ip_funcs_p + 0x838))(0,&uStack_b3,param_1,*(code **)(_r_ip_funcs_p + 0x838));
  return uStack_b3;
}

