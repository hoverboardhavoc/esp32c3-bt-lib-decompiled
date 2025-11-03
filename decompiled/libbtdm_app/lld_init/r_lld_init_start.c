/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
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
  char cVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  undefined2 uVar8;
  undefined2 uVar9;
  undefined2 uVar10;
  undefined2 uVar11;
  uint uVar12;
  byte bVar13;
  uint uVar14;
  int iVar15;
  void *pvVar16;
  int iVar17;
  byte *pbVar18;
  uint uVar19;
  short sVar20;
  uint uVar21;
  int *piVar22;
  undefined4 uVar23;
  uint uVar24;
  int *piVar25;
  code *pcVar26;
  uint uVar27;
  undefined1 *puVar28;
  uint uVar29;
  int iVar30;
  uint *puVar31;
  uint uVar32;
  ushort uVar33;
  int iVar34;
  uint uStack_fc;
  int *piStack_f8;
  ushort uStack_f4;
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
  uStack_fc = (**(code **)(_r_ip_funcs_p + 0x264))(*(code **)(_r_ip_funcs_p + 0x264));
  uVar14 = (**(code **)(_r_osi_funcs_p + 0x88))(*(code **)(_r_osi_funcs_p + 0x88));
  iVar15 = (**(code **)(_r_ip_funcs_p + 0x838))
                     (1,&uStack_b3,param_1,*(code **)(_r_ip_funcs_p + 0x838));
  if (iVar15 != 0) {
    return uStack_b3;
  }
  if (_lld_init_env != (int *)0x0) goto _L297;
  piStack_f8 = (int *)(**(code **)(_r_modules_funcs_p + 0x120))
                                (0x5c,0,*(code **)(_r_modules_funcs_p + 0x120));
  _lld_init_env = piStack_f8;
  if (piStack_f8 == (int *)0x0) {
    (**(code **)(_r_plf_funcs_p + 8))(0x10000,0x842,*(code **)(_r_plf_funcs_p + 8));
    goto _L297;
  }
  memset(piStack_f8,0,0x5c);
  *(undefined1 *)(piStack_f8 + 0xb) = *(undefined1 *)((int)param_1 + 0x13);
  *(undefined1 *)((int)piStack_f8 + 0x32) = *(undefined1 *)(param_1 + 10);
  *(undefined1 *)((int)piStack_f8 + 0x33) = *(undefined1 *)((int)param_1 + 0x15);
  *(undefined1 *)((int)piStack_f8 + 0x4f) = *(undefined1 *)(param_1 + 0xb);
  memcpy((void *)((int)piStack_f8 + 0x3e),param_1,6);
  memcpy(piStack_f8 + 0x11,param_1 + 3,6);
  memcpy((void *)((int)piStack_f8 + 0x2d),param_1 + 6,5);
  (**(code **)(_r_ip_funcs_p + 0x220))
            (piStack_f8 + 0xd,*(undefined1 *)((int)param_1 + 0x13),*(code **)(_r_ip_funcs_p + 0x220)
            );
  *(short *)(piStack_f8 + 0xe) = (short)uVar14;
  *(char *)((int)piStack_f8 + 0x3a) = (char)((uVar14 & 0xffffff) >> 0x10);
  iVar15 = _p_lld_env;
  *(undefined1 *)((int)piStack_f8 + 0x3b) = 2;
  bVar13 = (char)((uVar14 & 0xffffff) % 0xc) + 5;
  *(byte *)(piStack_f8 + 0xf) = bVar13;
  cVar2 = *(char *)(iVar15 + 0xd6);
  *(char *)((int)piStack_f8 + 0x3d) = cVar2;
  memcpy(auStack_b0,piStack_f8 + 0xd,4);
  memcpy(auStack_ac,piStack_f8 + 0xe,3);
  uStack_a9 = 2;
  uStack_a8 = 0;
  memcpy(auStack_a0,param_1 + 6,5);
  uVar8 = param_1[0xe];
  uVar9 = param_1[0xf];
  uVar10 = param_1[0x10];
  uVar11 = param_1[0x11];
  bStack_9b = bVar13 | cVar2 << 5;
  piVar22 = piStack_f8 + 3;
  do {
    *(undefined2 *)piVar22 = uVar8;
    *(undefined2 *)((int)piVar22 + 2) = uVar9;
    *(undefined2 *)(piVar22 + 1) = uVar10;
    *(undefined2 *)((int)piVar22 + 6) = uVar11;
    *(undefined1 *)(piVar22 + 2) = 0;
    piVar22 = (int *)((int)piVar22 + 10);
  } while ((int *)((int)piStack_f8 + 0x2a) != piVar22);
  uVar14 = *(byte *)(param_1 + 9) & 1;
  if ((*(byte *)(param_1 + 9) & 1) != 0) {
    pvVar16 = (void *)(**(code **)(_r_modules_funcs_p + 0x120))
                                (0x54,0,*(code **)(_r_modules_funcs_p + 0x120));
    *piStack_f8 = (int)pvVar16;
    if (pvVar16 == (void *)0x0) {
      uVar14 = 0;
      (**(code **)(_r_plf_funcs_p + 8))(0x10000,0x6fa,*(code **)(_r_plf_funcs_p + 8));
    }
    else {
      memset(pvVar16,0,0x54);
      uVar23 = *(undefined4 *)(_r_ip_funcs_p + 0x45c);
      *(undefined4 *)((int)pvVar16 + 0x20) = *(undefined4 *)(_r_ip_funcs_p + 0x458);
      *(undefined4 *)((int)pvVar16 + 0x18) = uVar23;
      *(undefined1 *)((int)pvVar16 + 0x16) = DAT_00013022;
      uVar33 = param_1[0xd];
      uVar24 = (uint)uVar33 * 0x4e2;
      if (_sch_slice_params < uVar24) {
        uVar24 = (uint)_sch_slice_params;
      }
      *(uint *)((int)pvVar16 + 0x10) = uVar24;
      *(ushort *)((int)pvVar16 + 0x14) = DAT_00013023 & 0xf | 0x6000;
      uVar8 = param_1[0xc];
      *(ushort *)((int)pvVar16 + 0x2e) = uVar33;
      *(uint *)((int)pvVar16 + 0x24) = (uint)uVar33;
      *(undefined2 *)((int)pvVar16 + 0x2c) = uVar8;
      *(undefined1 *)((int)pvVar16 + 0x3c) = 0x7f;
      *(undefined1 *)((int)pvVar16 + 0x3e) = 1;
      *(undefined1 *)((int)pvVar16 + 0x52) = *(undefined1 *)((int)param_1 + 0x13);
      *(undefined2 *)(piStack_f8 + 3) = param_1[0xe];
      *(undefined2 *)((int)piStack_f8 + 0xe) = param_1[0xf];
      *(undefined2 *)(piStack_f8 + 4) = param_1[0x10];
      uVar8 = param_1[0x11];
      *(undefined1 *)(piStack_f8 + 5) = 0;
      *(undefined2 *)((int)piStack_f8 + 0x12) = uVar8;
      *(byte *)((int)piStack_f8 + 0x2b) = *(byte *)((int)piStack_f8 + 0x2b) | 1;
    }
  }
  uStack_a6 = (undefined2)piStack_f8[3];
  uStack_a4 = (undefined2)piStack_f8[4];
  uStack_a2 = *(undefined2 *)((int)piStack_f8 + 0x12);
  (**(code **)(_r_ip_funcs_p + 0x450))(auStack_98,auStack_b0,*(code **)(_r_ip_funcs_p + 0x450));
  pvVar16 = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))(0x7400,*(code **)(_r_plf_funcs_p + 0xbc));
  memcpy(pvVar16,auStack_98,0x16);
  if ((*(byte *)(param_1 + 9) & 2) != 0) {
    *(undefined2 *)((int)piStack_f8 + 0x16) = param_1[uVar14 * 6 + 0xe];
    *(undefined2 *)(piStack_f8 + 6) = param_1[uVar14 * 6 + 0xf];
    uVar8 = param_1[uVar14 * 6 + 0x10];
    uVar9 = param_1[uVar14 * 6 + 0x11];
    *(char *)((int)piStack_f8 + 0x1e) = (char)uVar14;
    uVar14 = uVar14 + 1;
    *(undefined2 *)((int)piStack_f8 + 0x1a) = uVar8;
    *(undefined2 *)(piStack_f8 + 7) = uVar9;
  }
  uStack_a6 = *(undefined2 *)((int)piStack_f8 + 0x16);
  uStack_a4 = *(undefined2 *)((int)piStack_f8 + 0x1a);
  uStack_a2 = (undefined2)piStack_f8[7];
  (**(code **)(_r_ip_funcs_p + 0x450))(auStack_98,auStack_b0,*(code **)(_r_ip_funcs_p + 0x450));
  pvVar16 = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))(0x7422,*(code **)(_r_plf_funcs_p + 0xbc));
  memcpy(pvVar16,auStack_98,0x16);
  if ((*(byte *)(param_1 + 9) & 4) != 0) {
    pvVar16 = (void *)(**(code **)(_r_modules_funcs_p + 0x120))
                                (0x54,0,*(code **)(_r_modules_funcs_p + 0x120));
    piStack_f8[1] = (int)pvVar16;
    if (pvVar16 == (void *)0x0) {
      (**(code **)(_r_plf_funcs_p + 8))(0x10000,0x75b,*(code **)(_r_plf_funcs_p + 8));
    }
    else {
      memset(pvVar16,0,0x54);
      uVar23 = *(undefined4 *)(_r_ip_funcs_p + 0x45c);
      *(undefined4 *)((int)pvVar16 + 0x20) = *(undefined4 *)(_r_ip_funcs_p + 0x458);
      *(undefined4 *)((int)pvVar16 + 0x18) = uVar23;
      *(undefined1 *)((int)pvVar16 + 0x16) = DAT_00013022;
      uVar33 = param_1[uVar14 * 6 + 0xd];
      uVar24 = (uint)uVar33 * 0x4e2;
      if (_sch_slice_params < uVar24) {
        uVar24 = (uint)_sch_slice_params;
      }
      *(uint *)((int)pvVar16 + 0x10) = uVar24;
      *(ushort *)((int)pvVar16 + 0x14) = DAT_00013023 & 0xf | 0x6000;
      uVar8 = param_1[uVar14 * 6 + 0xc];
      *(ushort *)((int)pvVar16 + 0x2e) = uVar33;
      *(uint *)((int)pvVar16 + 0x24) = (uint)uVar33;
      *(undefined2 *)((int)pvVar16 + 0x2c) = uVar8;
      *(undefined1 *)((int)pvVar16 + 0x30) = 3;
      *(undefined1 *)((int)pvVar16 + 0x51) = 1;
      *(undefined1 *)((int)pvVar16 + 0x3e) = 1;
      *(undefined1 *)((int)pvVar16 + 0x3c) = 0x7f;
      *(undefined1 *)((int)pvVar16 + 0x52) = 10;
      *(undefined2 *)(piStack_f8 + 8) = param_1[uVar14 * 6 + 0xe];
      *(undefined2 *)((int)piStack_f8 + 0x22) = param_1[uVar14 * 6 + 0xf];
      uVar8 = param_1[uVar14 * 6 + 0x10];
      uVar9 = param_1[uVar14 * 6 + 0x11];
      *(char *)(piStack_f8 + 10) = (char)uVar14;
      *(undefined2 *)(piStack_f8 + 9) = uVar8;
      *(undefined2 *)((int)piStack_f8 + 0x26) = uVar9;
      *(byte *)((int)piStack_f8 + 0x2b) = *(byte *)((int)piStack_f8 + 0x2b) | 2;
    }
  }
  uStack_a6 = (undefined2)piStack_f8[8];
  uStack_a4 = (undefined2)piStack_f8[9];
  uStack_a2 = *(undefined2 *)((int)piStack_f8 + 0x26);
  (**(code **)(_r_ip_funcs_p + 0x450))(auStack_98,auStack_b0,*(code **)(_r_ip_funcs_p + 0x450));
  pvVar16 = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))(0x7444,*(code **)(_r_plf_funcs_p + 0xbc));
  memcpy(pvVar16,auStack_98,0x16);
  *(undefined1 *)((int)piStack_f8 + 0x2a) = *(undefined1 *)((int)param_1 + 0x11);
  if (((*(byte *)(param_1 + 10) & 2) == 0) && (*(char *)(param_1 + 0x1e) == '\0')) {
_L309:
    uStack_f4 = 0;
_L412:
    uVar14 = 0;
  }
  else {
    if (*(char *)(param_1 + 0xb) != '\0') {
      uStack_f4 = 1;
      goto _L412;
    }
    uVar14 = (**(code **)(_r_ip_funcs_p + 0x260))
                       (param_1 + 3,*(undefined1 *)((int)param_1 + 0x15),
                        *(code **)(_r_ip_funcs_p + 0x260));
    if (9 < uVar14) goto _L309;
    uVar14 = uVar14 * 0x34 + 0xc60 & 0xffff;
    uStack_f4 = 1;
  }
  bVar13 = *(byte *)(param_1 + 10);
  uVar24 = (uint)bVar1 * 9 & 0xff;
  *(bool *)((int)piStack_f8 + 0x4a) = uVar14 != 0;
  sVar20 = (short)uVar24 * 0xe + 0x1400;
  piVar25 = piStack_f8 + 2;
  piVar22 = piStack_f8;
  do {
    bStack_b2 = 0;
    bStack_b1 = 0;
    iVar15 = *piVar22;
    if (iVar15 != 0) {
      bVar1 = *(byte *)(iVar15 + 0x52);
      uVar32 = (uint)bVar1;
      uVar33 = *(byte *)((int)param_1 + 0x11) + 0xe & 0xff;
      iVar34 = uVar32 * 0x5a;
      (**(code **)(_r_ip_funcs_p + 0x490))(uVar32,uVar33,*(code **)(_r_ip_funcs_p + 0x490));
      iVar17 = piStack_f8[3];
      iVar30 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(short *)(iVar34 + 0x22 + iVar30) = (short)iVar17;
      uVar8 = *(undefined2 *)((int)piStack_f8 + 0x16);
      iVar17 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar34 + 0x38 + iVar17) = uVar8;
      iVar17 = piStack_f8[8];
      iVar30 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(short *)(iVar34 + 0x3c + iVar30) = (short)iVar17;
      iVar17 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(short *)(iVar34 + 0x1c + iVar17) = sVar20;
      iVar17 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(short *)(iVar34 + 0x34 + iVar17) = sVar20;
      (**(code **)(_r_modules_funcs_p + 0x1e0))
                (uVar33,uVar32,&bStack_b2,&bStack_b1,*(code **)(_r_modules_funcs_p + 0x1e0));
      uVar21 = (uint)bStack_b1;
      uVar12 = _g_bt_plf_log_level >> 2;
      uVar19 = _g_bt_plf_log_level & 1;
      uVar29 = _g_bt_plf_log_level & 2;
      uVar27 = (uint)bStack_b2;
      if ((uVar27 << 8 & 0xfffffeff) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x41,*(code **)(_r_plf_funcs_p + 8));
      }
      if ((uVar21 << 7 & 0xffffff7f) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x42,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar17 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      pcVar26 = *(code **)(_r_plf_funcs_p + 0xbc);
      *(ushort *)(iVar17 + iVar34) =
           (ushort)(uVar27 << 8) | (ushort)(uVar21 << 7) | (ushort)(uVar19 << 10) |
           (ushort)(uVar29 << 8) | (ushort)((uVar12 & 1) << 5) | uVar33;
      iVar17 = (*pcVar26)(0x400,pcVar26);
      *(undefined2 *)(iVar34 + 0xc + iVar17) = 0xbed6;
      iVar17 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar34 + 0xe + iVar17) = 0x8e89;
      iVar17 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar34 + 0x10 + iVar17) = 0x5555;
      iVar17 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar34 + 0x12 + iVar17) = 0x55;
      iVar17 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar34 + 0x46 + iVar17) = 0;
      bVar3 = *(byte *)(param_1 + 0xb);
      bVar4 = *(byte *)(param_1 + 0x1e);
      bVar5 = *(byte *)((int)piStack_f8 + 0x4a);
      iVar17 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar34 + 0x14 + iVar17) =
           (ushort)((bVar13 & 2) << 1) | (ushort)bVar3 << 8 | (ushort)bVar4 << 6 |
           (ushort)bVar5 << 1 | uStack_f4;
      if (*(char *)((int)piStack_f8 + 0x4a) != '\0') {
        iVar17 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
        *(short *)(iVar34 + 0x2c + iVar17) = (short)uVar14;
      }
      if ((*(char *)(param_1 + 0xb) == '\0') && (*(char *)((int)piStack_f8 + 0x4a) == '\0')) {
        puVar28 = (undefined1 *)((int)param_1 + 7);
        iVar17 = 0;
        do {
          uVar6 = *puVar28;
          uVar7 = puVar28[-1];
          iVar30 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
          *(ushort *)(iVar30 + iVar34 + 0x2c + iVar17) = CONCAT11(uVar6,uVar7);
          iVar17 = iVar17 + 2;
          puVar28 = puVar28 + 2;
        } while (iVar17 != 6);
        bVar3 = *(byte *)((int)param_1 + 0x15);
        iVar17 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
        *(ushort *)(iVar34 + 0x32 + iVar17) = bVar3 & 1;
      }
      iVar17 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar34 + 0x16 + iVar17) = 0x8027;
      iVar17 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar34 + 0x28 + iVar17) = 0;
      iVar17 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar34 + 0x2a + iVar17) = 0;
      bVar3 = *(byte *)(param_1 + 10);
      if ((bVar1 & 0xe0) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0xe6,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar17 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar34 + 2 + iVar17) = (ushort)((bVar3 & 1) << 7) | (ushort)bVar1 | 0x800;
      uVar8 = *param_1;
      iVar17 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar34 + 6 + iVar17) = uVar8;
      uVar8 = param_1[1];
      iVar17 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar34 + 8 + iVar17) = uVar8;
      uVar8 = param_1[2];
      iVar17 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar34 + 10 + iVar17) = uVar8;
      bVar1 = *(byte *)(iVar15 + 0x30);
      if (((uint)bVar1 << 2 & 0xfffffff3) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,399,*(code **)(_r_plf_funcs_p + 8));
      }
      if ((bVar1 & 0xfc) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,400,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar17 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar34 + 4 + iVar17) = (ushort)((uint)bVar1 << 2) | (ushort)bVar1 | 0x2000;
      uVar8 = *(undefined2 *)(iVar15 + 0x24);
      iVar17 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar34 + 0x20 + iVar17) = uVar8;
      uVar29 = *(uint *)(iVar15 + 0x24);
      if ((uVar29 >> 0xf & 1) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x4ab,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar15 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      bVar1 = *(byte *)((int)param_1 + 0x11);
      pcVar26 = *(code **)(_r_modules_funcs_p + 0x1a0);
      *(ushort *)(iVar34 + 0x1a + iVar15) = (ushort)uVar29 | 0x8000;
      pbVar18 = (byte *)(*pcVar26)(bVar1 + 9,pcVar26);
      if (pbVar18 != (byte *)0x0) {
        bVar1 = pbVar18[1];
        if (0xb < uVar32) {
          (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x299b,*(code **)(_r_plf_funcs_p + 8));
        }
        if (((uint)bVar1 << 8 & 0xf000) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x299d,*(code **)(_r_plf_funcs_p + 8));
        }
        puVar31 = (uint *)((uVar32 + 0x1800c4cb) * 4);
        *puVar31 = *puVar31 & 0xfffff0ff | (uint)bVar1 << 8;
        bVar1 = *pbVar18;
        if (0xb < uVar32) {
          (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x294a,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar31 = (uint)bVar1 << 0x1e | *puVar31 & 0xbfffffff;
        bVar1 = pbVar18[3];
        if (0xb < uVar32) {
          (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x29bb,*(code **)(_r_plf_funcs_p + 8));
        }
        if ((bVar1 & 0xf0) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x29bd,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar31 = *puVar31 & 0xfffffff0 | (uint)bVar1;
        bVar1 = pbVar18[2];
        if (0xb < uVar32) {
          (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x295a,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar31 = (uint)bVar1 << 0x1d | *puVar31 & 0xdfffffff;
        bVar1 = pbVar18[7];
        if (0xb < uVar32) {
          (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x298b,*(code **)(_r_plf_funcs_p + 8));
        }
        if (((uint)bVar1 << 0xc & 0xf0000) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x298d,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar31 = *puVar31 & 0xffff0fff | (uint)bVar1 << 0xc;
        bVar1 = pbVar18[8];
        if (0xb < uVar32) {
          (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x29ab,*(code **)(_r_plf_funcs_p + 8));
        }
        if (((uint)bVar1 << 4 & 0xffffff0f) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x29ad,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar31 = *puVar31 & 0xffffff0f | (uint)bVar1 << 4;
        bVar1 = pbVar18[9];
        if (0xb < uVar32) {
          (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x297b,*(code **)(_r_plf_funcs_p + 8));
        }
        if (((uint)bVar1 << 0x10 & 0xf00000) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x297d,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar31 = *puVar31 & 0xfff0ffff | (uint)bVar1 << 0x10;
        uVar33 = *(ushort *)(pbVar18 + 10);
        if (0xb < uVar32) {
          (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x296a,*(code **)(_r_plf_funcs_p + 8));
        }
        if (((uint)uVar33 << 0x14 & 0xe0000000) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x296c,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar31 = *puVar31 & 0xe00fffff | (uint)uVar33 << 0x14;
        bVar1 = pbVar18[6];
        if (0xb < uVar32) {
          (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x293a,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar31 = *puVar31 & 0x7fffffff | (uint)bVar1 << 0x1f;
        if (2 < (int)_g_bt_plf_log_level) {
          ets_printf("PTI CNTL CS[%d] REG[%08x] TYPE[INITIATOR] RXEN[%d] RX[%d] IFSEN[%d] IFS[%d] PRTEN[%d] TIME[%d] DIFS[%d] DRX[%d] DTX[%d]\n"
                     ,uVar32,puVar31,pbVar18[2],pbVar18[3],*pbVar18,pbVar18[1],pbVar18[6]);
        }
      }
    }
    piVar22 = piVar22 + 1;
  } while (piVar25 != piVar22);
  iVar15 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  iVar30 = uVar24 * 0xe;
  iVar34 = iVar30 + 2;
  uVar33 = *(ushort *)(iVar15 + iVar34);
  iVar15 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  pcVar26 = *(code **)(_r_plf_funcs_p + 0xbc);
  *(ushort *)(iVar15 + iVar34) = uVar33 & 0xfff0 | 5;
  iVar15 = (*pcVar26)(0x1400,pcVar26);
  *(undefined2 *)(iVar30 + 4 + iVar15) = 0x7400;
  iVar15 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar33 = *(ushort *)(iVar15 + iVar34);
  iVar17 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  iVar15 = _r_plf_funcs_p;
  *(ushort *)(iVar17 + iVar34) = uVar33 & 0xff | 0x2200;
  iVar15 = (**(code **)(iVar15 + 0xbc))(0x1400,*(code **)(iVar15 + 0xbc));
  uVar33 = *(ushort *)(iVar15 + iVar30);
  iVar17 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  iVar15 = _r_plf_funcs_p;
  *(ushort *)(iVar17 + iVar30) = uVar33 & 0x8000;
  bVar1 = *(byte *)((int)param_1 + 0x15);
  iVar15 = (**(code **)(iVar15 + 0xbc))(0x1400,*(code **)(iVar15 + 0xbc));
  pcVar26 = *(code **)(_r_plf_funcs_p + 0xbc);
  *(ushort *)(iVar34 + iVar15) = (ushort)((bVar1 & 1) << 7) | 0x2225;
  iVar15 = (*pcVar26)(0x1400,pcVar26);
  uVar33 = *(ushort *)(iVar15 + iVar30);
  iVar17 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  iVar15 = _r_modules_funcs_p;
  *(ushort *)(iVar17 + iVar30) = (ushort)(((uint)uVar33 << 0x11) >> 0x11);
  iVar15 = (**(code **)(iVar15 + 0x1a0))
                     (*(byte *)((int)param_1 + 0x11) + 9,*(code **)(iVar15 + 0x1a0));
  if (iVar15 != 0) {
    if (2 < (int)_g_bt_plf_log_level) {
      ets_printf("TX PTI [Initiator] [EN%d] [%d] \n",*(undefined1 *)(iVar15 + 4),
                 *(undefined1 *)(iVar15 + 5));
    }
    uVar14 = (uint)*(byte *)(iVar15 + 5) << 8;
    if ((uVar14 & 0xf000) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x33f,*(code **)(_r_plf_funcs_p + 8));
    }
    iVar30 = iVar30 + 10;
    iVar17 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar33 = *(ushort *)(iVar17 + iVar30);
    iVar17 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    pcVar26 = *(code **)(_r_plf_funcs_p + 0xbc);
    *(ushort *)(iVar17 + iVar30) = uVar33 & 0xf0ff | (ushort)uVar14;
    bVar1 = *(byte *)(iVar15 + 4);
    iVar15 = (*pcVar26)(0x1400,pcVar26);
    uVar33 = *(ushort *)(iVar15 + iVar30);
    iVar15 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar30 + iVar15) = uVar33 & 0xefff | (ushort)bVar1 << 0xc;
  }
  piStack_f8[2] = 0;
  do {
    iVar15 = *piStack_f8;
    if (iVar15 != 0) {
      pcVar26 = *(code **)(_r_ip_funcs_p + 0x6b0);
      *(uint *)(iVar15 + 4) = uStack_fc;
      *(uint *)(iVar15 + 0x28) = uStack_fc;
      iVar17 = (*pcVar26)(iVar15,pcVar26);
      if (iVar17 == 0) {
        *(undefined1 *)(iVar15 + 0x50) = 0;
        uStack_fc = (uint)*(ushort *)(iVar15 + 0x2e) * 2 + uStack_fc & 0xfffffff;
      }
      else {
        (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x838,*(code **)(_r_plf_funcs_p + 8));
      }
      uStack_b3 = 0;
    }
    piStack_f8 = piStack_f8 + 1;
  } while (piStack_f8 != piVar25);
_L297:
  (**(code **)(_r_ip_funcs_p + 0x838))(0,&uStack_b3,param_1,*(code **)(_r_ip_funcs_p + 0x838));
  return uStack_b3;
}

