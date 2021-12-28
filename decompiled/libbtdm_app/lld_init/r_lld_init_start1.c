/*
 * Last changed at upstream commit a3f7d7ffa2b261b1415042d8b7cd457cc2b4b1de
 * https://github.com/espressif/esp32c3-bt-lib/commit/a3f7d7ffa2b261b1415042d8b7cd457cc2b4b1de
 * Upstream date: 2021-12-28 18:10:18 +0800
 * Upstream subject: Update ESP32-C3 and ESP32-S3 bt lib (33175c8)
 * Source: libbtdm_app -> lld_init.o -> r_lld_init_start1
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

undefined4 r_lld_init_start1(undefined2 *param_1)

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
  void *pvVar17;
  int iVar18;
  undefined4 uVar19;
  byte *pbVar20;
  uint uVar21;
  short sVar22;
  int *piVar23;
  int *piVar24;
  code *pcVar25;
  undefined1 *puVar26;
  int iVar27;
  uint *puVar28;
  uint uVar29;
  ushort uVar30;
  int iVar31;
  int iVar32;
  int iVar33;
  uint uVar34;
  uint uVar35;
  uint uStack_f8;
  int *piStack_f4;
  ushort uStack_f0;
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
  uVar15 = (**(code **)(_r_ip_funcs_p + 0x264))(*(code **)(_r_ip_funcs_p + 0x264));
  uVar16 = (**(code **)(_r_osi_funcs_p + 0x88))(*(code **)(_r_osi_funcs_p + 0x88));
  if (lld_init_env != (int *)0x0) {
    return 0xc;
  }
  piStack_f4 = (int *)(**(code **)(_r_modules_funcs_p + 0x120))
                                (0x5c,0,*(code **)(_r_modules_funcs_p + 0x120));
  lld_init_env = piStack_f4;
  if (piStack_f4 == (int *)0x0) {
    (**(code **)(_r_plf_funcs_p + 8))("lld_init.c",0x7ad,*(code **)(_r_plf_funcs_p + 8));
    return 0xc;
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
  *(char *)((int)piStack_f4 + 0x3a) = (char)(uVar16 >> 0x10);
  *(short *)(piStack_f4 + 0xe) = (short)uVar16;
  iVar31 = _p_lld_env;
  *(undefined1 *)((int)piStack_f4 + 0x3b) = 2;
  bVar14 = (char)(uVar16 % 0xc) + 5;
  *(byte *)(piStack_f4 + 0xf) = bVar14;
  cVar3 = *(char *)(iVar31 + 0xd6);
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
  piVar23 = piStack_f4 + 3;
  do {
    *(undefined2 *)piVar23 = uVar8;
    *(undefined2 *)((int)piVar23 + 2) = uVar9;
    *(undefined2 *)(piVar23 + 1) = uVar10;
    *(undefined2 *)((int)piVar23 + 6) = uVar11;
    *(undefined1 *)(piVar23 + 2) = 0;
    piVar23 = (int *)((int)piVar23 + 10);
  } while ((int *)((int)piStack_f4 + 0x2a) != piVar23);
  iVar31 = 0;
  if ((*(byte *)(param_1 + 9) & 1) != 0) {
    pvVar17 = (void *)(**(code **)(_r_modules_funcs_p + 0x120))
                                (0x54,0,*(code **)(_r_modules_funcs_p + 0x120));
    *piStack_f4 = (int)pvVar17;
    if (pvVar17 == (void *)0x0) {
      (**(code **)(_r_plf_funcs_p + 8))("lld_init.c",0x667,*(code **)(_r_plf_funcs_p + 8));
    }
    else {
      memset(pvVar17,0,0x54);
      *(code **)((int)pvVar17 + 0x20) = r_lld_init_evt_canceled_cbk1;
      *(undefined4 *)((int)pvVar17 + 0x18) = 0x10000;
      uVar2 = DAT_00013012;
      *(undefined4 *)((int)pvVar17 + 0x1c) = 0;
      *(undefined4 *)((int)pvVar17 + 8) = 0;
      *(undefined1 *)((int)pvVar17 + 0x16) = uVar2;
      uVar30 = param_1[0xd];
      uVar16 = (uint)uVar30 * 0x4e2;
      if (_sch_slice_params < uVar16) {
        uVar16 = (uint)_sch_slice_params;
      }
      *(uint *)((int)pvVar17 + 0x10) = uVar16;
      iVar31 = 1;
      *(ushort *)((int)pvVar17 + 0x14) = DAT_00013013 & 0xf | 0x6000;
      uVar8 = param_1[0xc];
      *(undefined1 *)((int)pvVar17 + 0x30) = 0;
      *(undefined1 *)((int)pvVar17 + 0x51) = 0;
      *(undefined2 *)((int)pvVar17 + 0x2c) = uVar8;
      *(undefined2 *)((int)pvVar17 + 0x3c) = 0x7f;
      *(undefined1 *)((int)pvVar17 + 0x3e) = 1;
      *(ushort *)((int)pvVar17 + 0x2e) = uVar30;
      *(uint *)((int)pvVar17 + 0x24) = (uint)uVar30;
      *(undefined1 *)((int)pvVar17 + 0x52) = *(undefined1 *)((int)param_1 + 0x13);
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
  pvVar17 = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))(0x7400,*(code **)(_r_plf_funcs_p + 0xbc));
  memcpy(pvVar17,auStack_98,0x16);
  if ((*(byte *)(param_1 + 9) & 2) != 0) {
    *(undefined2 *)((int)piStack_f4 + 0x16) = param_1[iVar31 * 6 + 0xe];
    *(undefined2 *)(piStack_f4 + 6) = param_1[iVar31 * 6 + 0xf];
    uVar8 = param_1[iVar31 * 6 + 0x10];
    uVar9 = param_1[iVar31 * 6 + 0x11];
    *(char *)((int)piStack_f4 + 0x1e) = (char)iVar31;
    iVar31 = iVar31 + 1;
    *(undefined2 *)((int)piStack_f4 + 0x1a) = uVar8;
    *(undefined2 *)(piStack_f4 + 7) = uVar9;
  }
  uStack_a6 = *(undefined2 *)((int)piStack_f4 + 0x16);
  uStack_a4 = *(undefined2 *)((int)piStack_f4 + 0x1a);
  uStack_a2 = (undefined2)piStack_f4[7];
  (**(code **)(_r_ip_funcs_p + 0x450))(auStack_98,auStack_b0,*(code **)(_r_ip_funcs_p + 0x450));
  pvVar17 = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))(0x7422,*(code **)(_r_plf_funcs_p + 0xbc));
  memcpy(pvVar17,auStack_98,0x16);
  if ((*(byte *)(param_1 + 9) & 4) != 0) {
    pvVar17 = (void *)(**(code **)(_r_modules_funcs_p + 0x120))
                                (0x54,0,*(code **)(_r_modules_funcs_p + 0x120));
    piStack_f4[1] = (int)pvVar17;
    if (pvVar17 == (void *)0x0) {
      (**(code **)(_r_plf_funcs_p + 8))("lld_init.c",0x6c8,*(code **)(_r_plf_funcs_p + 8));
    }
    else {
      memset(pvVar17,0,0x54);
      *(code **)((int)pvVar17 + 0x20) = r_lld_init_evt_canceled_cbk1;
      *(undefined4 *)((int)pvVar17 + 0x18) = 0x10000;
      uVar2 = DAT_00013012;
      *(undefined4 *)((int)pvVar17 + 0x1c) = 0;
      *(undefined1 *)((int)pvVar17 + 0x16) = uVar2;
      uVar30 = param_1[iVar31 * 6 + 0xd];
      uVar16 = (uint)uVar30 * 0x4e2;
      if (_sch_slice_params < uVar16) {
        uVar16 = (uint)_sch_slice_params;
      }
      *(uint *)((int)pvVar17 + 0x10) = uVar16;
      *(ushort *)((int)pvVar17 + 0x14) = DAT_00013013 & 0xf | 0x6000;
      uVar8 = param_1[iVar31 * 6 + 0xc];
      *(ushort *)((int)pvVar17 + 0x2e) = uVar30;
      *(uint *)((int)pvVar17 + 0x24) = (uint)uVar30;
      *(undefined2 *)((int)pvVar17 + 0x2c) = uVar8;
      *(undefined1 *)((int)pvVar17 + 0x51) = 1;
      *(undefined2 *)((int)pvVar17 + 0x30) = 3;
      *(undefined1 *)((int)pvVar17 + 0x3e) = 1;
      *(undefined2 *)((int)pvVar17 + 0x3c) = 0x7f;
      *(undefined1 *)((int)pvVar17 + 0x52) = 10;
      *(undefined2 *)(piStack_f4 + 8) = param_1[iVar31 * 6 + 0xe];
      *(undefined2 *)((int)piStack_f4 + 0x22) = param_1[iVar31 * 6 + 0xf];
      uVar8 = param_1[iVar31 * 6 + 0x10];
      uVar9 = param_1[iVar31 * 6 + 0x11];
      *(char *)(piStack_f4 + 10) = (char)iVar31;
      *(undefined2 *)(piStack_f4 + 9) = uVar8;
      *(undefined2 *)((int)piStack_f4 + 0x26) = uVar9;
      *(byte *)((int)piStack_f4 + 0x2b) = *(byte *)((int)piStack_f4 + 0x2b) | 2;
    }
  }
  uStack_a6 = (undefined2)piStack_f4[8];
  uStack_a4 = (undefined2)piStack_f4[9];
  uStack_a2 = *(undefined2 *)((int)piStack_f4 + 0x26);
  (**(code **)(_r_ip_funcs_p + 0x450))(auStack_98,auStack_b0,*(code **)(_r_ip_funcs_p + 0x450));
  pvVar17 = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))(0x7444,*(code **)(_r_plf_funcs_p + 0xbc));
  memcpy(pvVar17,auStack_98,0x16);
  *(undefined1 *)((int)piStack_f4 + 0x2a) = *(undefined1 *)((int)param_1 + 0x11);
  if (((*(byte *)(param_1 + 10) & 2) == 0) && (*(char *)(param_1 + 0x1e) == '\0')) {
_L26:
    uStack_f0 = 0;
  }
  else {
    if (*(char *)(param_1 + 0xb) == '\0') {
      uVar16 = (**(code **)(_r_ip_funcs_p + 0x260))
                         (param_1 + 3,*(undefined1 *)((int)param_1 + 0x15),
                          *(code **)(_r_ip_funcs_p + 0x260));
      if (uVar16 < 10) {
        uStack_f8 = uVar16 * 0x34 + 0xc60 & 0xffff;
        uStack_f0 = 1;
        goto _L25;
      }
      goto _L26;
    }
    uStack_f0 = 1;
  }
  uStack_f8 = 0;
_L25:
  uVar16 = (uint)bVar1 * 9 & 0xff;
  bVar1 = *(byte *)(param_1 + 10);
  *(bool *)((int)piStack_f4 + 0x4a) = uStack_f8 != 0;
  piVar24 = piStack_f4 + 2;
  sVar22 = (short)uVar16 * 0xe + 0x1400;
  piVar23 = piStack_f4;
  do {
    bStack_b2 = 0;
    bStack_b1 = 0;
    iVar31 = *piVar23;
    if (iVar31 != 0) {
      bVar14 = *(byte *)(iVar31 + 0x52);
      uVar29 = (uint)bVar14;
      iVar27 = uVar29 * 0x5a;
      uVar30 = (*(char *)((int)param_1 + 0x11) != '\0') + 0xe;
      (**(code **)(_r_ip_funcs_p + 0x490))(uVar29,uVar30,*(code **)(_r_ip_funcs_p + 0x490));
      iVar18 = piStack_f4[3];
      iVar33 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar32 = _r_plf_funcs_p;
      *(short *)(iVar33 + iVar27 + 0x22) = (short)iVar18;
      uVar8 = *(undefined2 *)((int)piStack_f4 + 0x16);
      iVar18 = (**(code **)(iVar32 + 0xbc))(0x400,*(code **)(iVar32 + 0xbc));
      iVar32 = _r_plf_funcs_p;
      *(undefined2 *)(iVar18 + iVar27 + 0x38) = uVar8;
      iVar18 = piStack_f4[8];
      iVar33 = (**(code **)(iVar32 + 0xbc))(0x400,*(code **)(iVar32 + 0xbc));
      iVar32 = _r_plf_funcs_p;
      *(short *)(iVar33 + iVar27 + 0x3c) = (short)iVar18;
      iVar18 = (**(code **)(iVar32 + 0xbc))(0x400,*(code **)(iVar32 + 0xbc));
      *(short *)(iVar18 + iVar27 + 0x1c) = sVar22;
      iVar18 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(short *)(iVar18 + iVar27 + 0x34) = sVar22;
      (**(code **)(_r_modules_funcs_p + 0x1e0))
                (uVar30,uVar29,&bStack_b2,&bStack_b1,*(code **)(_r_modules_funcs_p + 0x1e0));
      uVar21 = (uint)bStack_b1;
      uVar13 = _g_bt_plf_log_level >> 2;
      uVar34 = _g_bt_plf_log_level & 1;
      uVar35 = (uint)bStack_b2;
      uVar12 = _g_bt_plf_log_level & 2;
      if ((uVar35 << 8 & 0xfffffeff) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_init.c",0x41,*(code **)(_r_plf_funcs_p + 8));
      }
      if ((uVar21 << 7 & 0xffffff7f) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_init.c",0x42,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar18 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      pcVar25 = *(code **)(_r_plf_funcs_p + 0xbc);
      *(ushort *)(iVar18 + iVar27) =
           (ushort)(uVar35 << 8) | (ushort)(uVar21 << 7) | (ushort)(uVar34 << 10) |
           (ushort)(uVar12 << 8) | (ushort)((uVar13 & 1) << 5) | uVar30;
      iVar18 = (*pcVar25)(0x400,pcVar25);
      *(undefined2 *)(iVar18 + iVar27 + 0xc) = 0xbed6;
      iVar18 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar18 + iVar27 + 0xe) = 0x8e89;
      iVar18 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar18 + iVar27 + 0x10) = 0x5555;
      iVar18 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar18 + iVar27 + 0x12) = 0x55;
      iVar18 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar18 + iVar27 + 0x46) = 0;
      bVar4 = *(byte *)(param_1 + 0xb);
      bVar5 = *(byte *)(param_1 + 0x1e);
      bVar6 = *(byte *)((int)piStack_f4 + 0x4a);
      iVar18 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      cVar3 = *(char *)((int)piStack_f4 + 0x4a);
      *(ushort *)(iVar18 + iVar27 + 0x14) =
           (ushort)(((bVar1 & 2) << 0x11) >> 0x10) | (ushort)bVar4 << 8 | (ushort)bVar5 << 6 |
           (ushort)bVar6 << 1 | uStack_f0;
      if (cVar3 != '\0') {
        iVar18 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
        *(short *)(iVar18 + iVar27 + 0x2c) = (short)uStack_f8;
      }
      if ((*(char *)(param_1 + 0xb) == '\0') && (*(char *)((int)piStack_f4 + 0x4a) == '\0')) {
        puVar26 = (undefined1 *)((int)param_1 + 7);
        iVar18 = 0;
        do {
          uVar2 = *puVar26;
          uVar7 = puVar26[-1];
          iVar32 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
          *(ushort *)(iVar32 + iVar27 + 0x2c + iVar18) = CONCAT11(uVar2,uVar7);
          iVar18 = iVar18 + 2;
          puVar26 = puVar26 + 2;
        } while (iVar18 != 6);
        bVar4 = *(byte *)((int)param_1 + 0x15);
        iVar18 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
        *(ushort *)(iVar18 + iVar27 + 0x32) = bVar4 & 1;
      }
      iVar18 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar18 + iVar27 + 0x16) = 0x8027;
      iVar32 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar18 = _r_plf_funcs_p;
      *(undefined2 *)(iVar32 + iVar27 + 0x28) = 0;
      iVar18 = (**(code **)(iVar18 + 0xbc))(0x400,*(code **)(iVar18 + 0xbc));
      *(undefined2 *)(iVar18 + iVar27 + 0x2a) = 0;
      bVar4 = *(byte *)(param_1 + 10);
      if ((bVar14 & 0xe0) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_init.c",0xe6,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar18 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar18 + iVar27 + 2) = (ushort)((bVar4 & 1) << 7) | (ushort)bVar14 | 0x800;
      uVar8 = *param_1;
      iVar18 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar18 + iVar27 + 6) = uVar8;
      uVar8 = param_1[1];
      iVar18 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar18 + iVar27 + 8) = uVar8;
      uVar8 = param_1[2];
      iVar18 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar18 + iVar27 + 10) = uVar8;
      bVar14 = *(byte *)(iVar31 + 0x30);
      if (((uint)bVar14 << 2 & 0xfffffff3) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_init.c",399,*(code **)(_r_plf_funcs_p + 8));
      }
      if ((bVar14 & 0xfc) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_init.c",400,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar32 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar18 = _r_plf_funcs_p;
      *(ushort *)(iVar32 + iVar27 + 4) = (ushort)((uint)bVar14 << 2) | (ushort)bVar14 | 0x2000;
      uVar8 = *(undefined2 *)(iVar31 + 0x24);
      iVar18 = (**(code **)(iVar18 + 0xbc))(0x400,*(code **)(iVar18 + 0xbc));
      *(undefined2 *)(iVar18 + iVar27 + 0x20) = uVar8;
      iVar31 = *(int *)(iVar31 + 0x24);
      if (iVar31 << 0x10 < 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_init.c",0x4ab,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar18 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      cVar3 = *(char *)((int)param_1 + 0x11);
      pcVar25 = *(code **)(_r_modules_funcs_p + 0x1a0);
      *(ushort *)(iVar27 + 0x1a + iVar18) = (ushort)iVar31 | 0x8000;
      pbVar20 = (byte *)(*pcVar25)((cVar3 != '\0') + '\t',pcVar25);
      if (pbVar20 != (byte *)0x0) {
        bVar14 = pbVar20[1];
        if (0xb < uVar29) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_init.c",0x299b,*(code **)(_r_plf_funcs_p + 8));
        }
        if (((uint)bVar14 << 8 & 0xf000) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_init.c",0x299d,*(code **)(_r_plf_funcs_p + 8));
        }
        puVar28 = (uint *)((uVar29 + 0x1800c4cb) * 4);
        *puVar28 = *puVar28 & 0xfffff0ff | (uint)bVar14 << 8;
        bVar14 = *pbVar20;
        if (0xb < uVar29) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_init.c",0x294a,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar28 = (uint)bVar14 << 0x1e | *puVar28 & 0xbfffffff;
        bVar14 = pbVar20[3];
        if (0xb < uVar29) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_init.c",0x29bb,*(code **)(_r_plf_funcs_p + 8));
        }
        if ((bVar14 & 0xf0) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_init.c",0x29bd,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar28 = *puVar28 & 0xfffffff0 | (uint)bVar14;
        bVar14 = pbVar20[2];
        if (0xb < uVar29) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_init.c",0x295a,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar28 = (uint)bVar14 << 0x1d | *puVar28 & 0xdfffffff;
        bVar14 = pbVar20[7];
        if (0xb < uVar29) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_init.c",0x298b,*(code **)(_r_plf_funcs_p + 8));
        }
        if (((uint)bVar14 << 0xc & 0xf0000) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_init.c",0x298d,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar28 = *puVar28 & 0xffff0fff | (uint)bVar14 << 0xc;
        bVar14 = pbVar20[8];
        if (0xb < uVar29) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_init.c",0x29ab,*(code **)(_r_plf_funcs_p + 8));
        }
        if (((uint)bVar14 << 4 & 0xffffff0f) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_init.c",0x29ad,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar28 = *puVar28 & 0xffffff0f | (uint)bVar14 << 4;
        bVar14 = pbVar20[9];
        if (0xb < uVar29) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_init.c",0x297b,*(code **)(_r_plf_funcs_p + 8));
        }
        if (((uint)bVar14 << 0x10 & 0xf00000) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_init.c",0x297d,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar28 = *puVar28 & 0xfff0ffff | (uint)bVar14 << 0x10;
        uVar30 = *(ushort *)(pbVar20 + 10);
        if (0xb < uVar29) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_init.c",0x296a,*(code **)(_r_plf_funcs_p + 8));
        }
        if (((uint)uVar30 << 0x14 & 0xe0000000) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_init.c",0x296c,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar28 = *puVar28 & 0xe00fffff | (uint)uVar30 << 0x14;
        bVar14 = pbVar20[6];
        if (0xb < uVar29) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_init.c",0x293a,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar28 = *puVar28 & 0x7fffffff | (uint)bVar14 << 0x1f;
        if (2 < (int)_g_bt_plf_log_level) {
          ets_printf("PTI CNTL CS[%d] REG[%08x] TYPE[INITIATOR] RXEN[%d] RX[%d] IFSEN[%d] IFS[%d] PRTEN[%d] TIME[%d] DIFS[%d] DRX[%d] DTX[%d]\n"
                     ,uVar29,puVar28,pbVar20[2],pbVar20[3],*pbVar20,pbVar20[1],pbVar20[6]);
        }
      }
    }
    piVar23 = piVar23 + 1;
  } while (piVar24 != piVar23);
  iVar31 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  iVar33 = uVar16 * 0xe;
  iVar32 = iVar33 + 2;
  uVar30 = *(ushort *)(iVar31 + iVar32);
  iVar31 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  pcVar25 = *(code **)(_r_plf_funcs_p + 0xbc);
  *(ushort *)(iVar31 + iVar32) = uVar30 & 0xfff0 | 5;
  iVar31 = (*pcVar25)(0x1400,pcVar25);
  *(undefined2 *)(iVar31 + iVar33 + 4) = 0x7400;
  iVar31 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar30 = *(ushort *)(iVar31 + iVar32);
  iVar18 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  iVar31 = _r_plf_funcs_p;
  *(ushort *)(iVar18 + iVar32) = uVar30 & 0xff | 0x2200;
  iVar31 = (**(code **)(iVar31 + 0xbc))(0x1400,*(code **)(iVar31 + 0xbc));
  uVar30 = *(ushort *)(iVar31 + iVar33);
  iVar18 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  iVar31 = _r_plf_funcs_p;
  *(ushort *)(iVar18 + iVar33) = uVar30 & 0x8000;
  bVar1 = *(byte *)((int)param_1 + 0x15);
  iVar31 = (**(code **)(iVar31 + 0xbc))(0x1400,*(code **)(iVar31 + 0xbc));
  pcVar25 = *(code **)(_r_plf_funcs_p + 0xbc);
  *(ushort *)(iVar31 + iVar32) = (ushort)((bVar1 & 1) << 7) | 0x2225;
  iVar31 = (*pcVar25)(0x1400,pcVar25);
  uVar30 = *(ushort *)(iVar31 + iVar33);
  iVar18 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  iVar31 = _r_modules_funcs_p;
  *(ushort *)(iVar18 + iVar33) = uVar30 & 0x7fff;
  iVar31 = (**(code **)(iVar31 + 0x1a0))
                     ((*(char *)((int)param_1 + 0x11) != '\0') + '\t',*(code **)(iVar31 + 0x1a0));
  if (iVar31 != 0) {
    if (2 < (int)_g_bt_plf_log_level) {
      ets_printf("TX PTI [Initiator] [EN%d] [%d] \n",*(undefined1 *)(iVar31 + 4),
                 *(undefined1 *)(iVar31 + 5));
    }
    uVar16 = (uint)*(byte *)(iVar31 + 5) << 8;
    if ((uVar16 & 0xf000) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_init.c",0x33f,*(code **)(_r_plf_funcs_p + 8));
    }
    iVar33 = iVar33 + 10;
    iVar18 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar30 = *(ushort *)(iVar18 + iVar33);
    iVar18 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    pcVar25 = *(code **)(_r_plf_funcs_p + 0xbc);
    *(ushort *)(iVar18 + iVar33) = uVar30 & 0xf0ff | (ushort)uVar16;
    bVar1 = *(byte *)(iVar31 + 4);
    iVar31 = (*pcVar25)(0x1400,pcVar25);
    uVar30 = *(ushort *)(iVar31 + iVar33);
    iVar31 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar31 + iVar33) = uVar30 & 0xefff | (ushort)bVar1 << 0xc;
  }
  piStack_f4[2] = 0;
  uVar19 = 0xc;
  do {
    iVar31 = _r_ip_funcs_p;
    iVar18 = *piStack_f4;
    if (iVar18 != 0) {
      *(uint *)(iVar18 + 4) = uVar15;
      *(uint *)(iVar18 + 0x28) = uVar15;
      iVar31 = (**(code **)(iVar31 + 0x6b0))(iVar18,*(code **)(iVar31 + 0x6b0));
      if (iVar31 == 0) {
        *(undefined1 *)(iVar18 + 0x50) = 0;
        uVar15 = uVar15 + (uint)*(ushort *)(iVar18 + 0x2e) * 2 & 0xfffffff;
        uVar19 = 0;
      }
      else {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_init.c",0x7a5,*(code **)(_r_plf_funcs_p + 8));
        uVar19 = 0;
      }
    }
    piStack_f4 = piStack_f4 + 1;
  } while (piVar24 != piStack_f4);
  return uVar19;
}

