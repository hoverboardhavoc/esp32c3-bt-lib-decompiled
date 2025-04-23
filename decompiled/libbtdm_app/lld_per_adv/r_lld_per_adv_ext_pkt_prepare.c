/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_per_adv.o -> r_lld_per_adv_ext_pkt_prepare
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint r_lld_per_adv_ext_pkt_prepare
               (int param_1,int param_2,uint param_3,uint param_4,uint param_5,short *param_6,
               short *param_7)

{
  char cVar1;
  byte bVar2;
  ushort uVar3;
  short sVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  void *__dest;
  int iVar8;
  code *pcVar9;
  short sVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  ushort uVar15;
  uint uVar16;
  uint uVar17;
  ushort *in_stack_00000000;
  undefined2 uStack_4c;
  undefined1 auStack_4a [5];
  undefined1 uStack_45;
  undefined1 uStack_44;
  
  iVar12 = *(int *)(&lld_per_adv_env + param_1 * 4);
  iVar8 = (uint)*(byte *)(iVar12 + 0x52) * 9;
  iVar11 = param_2 * 0xe;
  uVar14 = (param_5 & 0x7f) << 1;
  iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar3 = *(ushort *)(iVar5 + iVar11);
  iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(ushort *)(iVar5 + iVar11) = uVar3 & 0x8000;
  uVar17 = uVar14;
  if (param_2 == iVar8) {
    uVar17 = param_5 + 10 & 0xff;
  }
  if (*in_stack_00000000 + uVar17 < 0xff) {
    iVar5 = 0;
    sVar10 = 0;
  }
  else {
    iVar5 = 2;
    if (param_5 == 0) {
      if (uVar17 == 0) {
        uVar17 = 1;
      }
      iVar5 = 1;
    }
    uVar14 = iVar5 + 3;
    uVar17 = uVar17 + 3 & 0xff;
    iVar5 = 1;
    sVar10 = 3;
  }
  if (param_5 != 0) {
    cVar1 = *(char *)(iVar12 + 0x56);
    iVar6 = (**(code **)(_r_ip_funcs_p + 0x4f8))(*(code **)(_r_ip_funcs_p + 0x4f8));
    pcVar7 = (char *)(**(code **)(_r_plf_funcs_p + 0xbc))
                               (*param_6 + sVar10,*(code **)(_r_plf_funcs_p + 0xbc));
    sVar10 = sVar10 + 1;
    *pcVar7 = cVar1 + (char)(iVar6 / 10);
  }
  if (param_2 == iVar8) {
    *(char *)(iVar12 + 0x59) = (char)sVar10;
    iVar6 = _r_plf_funcs_p;
    uStack_4c = 0x2808;
    memcpy(auStack_4a,(void *)(iVar12 + 0x2f),5);
    uStack_45 = (undefined1)*(undefined2 *)(iVar12 + 0x3a);
    uStack_44 = (undefined1)((ushort)*(undefined2 *)(iVar12 + 0x3a) >> 8);
    __dest = (void *)(**(code **)(iVar6 + 0xbc))(*param_6 + sVar10,*(code **)(iVar6 + 0xbc));
    sVar10 = sVar10 + 9;
    memcpy(__dest,&uStack_4c,9);
  }
  uVar13 = 0;
  uVar3 = *in_stack_00000000;
  uVar16 = (uint)uVar3;
  uVar15 = uVar3;
  if (uVar16 != 0) {
    uVar13 = -uVar17 - 2 & 0xff;
    if (uVar16 < uVar13) {
      uVar13 = uVar16 & 0xff;
    }
    uVar15 = (ushort)uVar13;
    *in_stack_00000000 = uVar3 - uVar15;
  }
  if ((param_4 & 0xfc) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,500,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(ushort *)(iVar11 + 6 + iVar6) =
       (ushort)(param_5 << 0xe) | (ushort)(param_4 << 6) | (ushort)uVar14 | (ushort)(iVar5 << 0xc);
  uVar17 = (**(code **)(_r_modules_funcs_p + 4))
                     (uVar17 + 1 + uVar13 & 0xff,*(undefined1 *)(iVar12 + 0x55),
                      *(code **)(_r_modules_funcs_p + 4));
  uVar16 = 0;
  if (iVar5 != 0) {
    uVar16 = uVar17 / 0x1e + 0xb;
    uVar17 = uVar16 * 0x1e;
    *(short *)(iVar12 + 0x4a) = (short)uVar16;
  }
  uVar3 = *(ushort *)(_p_lld_env + 0xd4);
  bVar2 = *(byte *)(iVar12 + 0x57);
  if (0x3f < bVar2) {
    (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x2b0,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(ushort *)(iVar11 + 8 + iVar5) =
       (ushort)(uVar3 < 0x33) << 6 | (ushort)bVar2 | (ushort)((uVar16 & 0xff) << 8);
  bVar2 = *(byte *)(iVar12 + 0x55);
  uVar3 = *(ushort *)(iVar12 + 0x4a) >> 8;
  if ((bVar2 & 0xf8) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x31c,*(code **)(_r_plf_funcs_p + 8));
  }
  if (0x1f < uVar3) {
    (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x31d,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar6 = iVar11 + 10;
  iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(ushort *)(iVar5 + iVar6) = (ushort)bVar2 << 5 | uVar3;
  sVar4 = *param_6;
  iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(short *)(iVar11 + 0xc + iVar5) = sVar4;
  *param_6 = sVar10 + *param_6;
  if (0xf < param_3) {
    (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x126,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(ushort *)(iVar11 + 2 + iVar5) =
       (ushort)((uVar14 + 1 + uVar13 & 0xff) << 8) | (ushort)param_3 | 0x20;
  sVar10 = *param_7;
  iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(short *)(iVar11 + 4 + iVar5) = sVar10;
  *param_7 = uVar15 + *param_7;
  iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar3 = *(ushort *)(iVar5 + iVar11);
  iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(ushort *)(iVar11 + iVar5) = (ushort)(((uint)uVar3 << 0x11) >> 0x11);
  if (param_2 == iVar8) {
    *(char *)(iVar12 + 0x5a) = (char)uVar14;
    *(char *)(iVar12 + 0x5b) = (char)uVar13;
  }
  iVar5 = (**(code **)(_r_modules_funcs_p + 0x1a0))(4,*(code **)(_r_modules_funcs_p + 0x1a0));
  if (iVar5 != 0) {
    if (2 < _g_bt_plf_log_level) {
      ets_printf("TX PTI [PER ADV DATA] [EN%d] [%d] \n",*(undefined1 *)(iVar5 + 4),
                 *(undefined1 *)(iVar5 + 5));
    }
    bVar2 = *(byte *)(iVar5 + 5);
    if ((bVar2 & 0xf0) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x33f,*(code **)(_r_plf_funcs_p + 8));
    }
    iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar3 = *(ushort *)(iVar8 + iVar6);
    iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    pcVar9 = *(code **)(_r_plf_funcs_p + 0xbc);
    *(ushort *)(iVar8 + iVar6) = uVar3 & 0xf0ff | (ushort)bVar2 << 8;
    bVar2 = *(byte *)(iVar5 + 4);
    iVar5 = (*pcVar9)(0x1400,pcVar9);
    uVar3 = *(ushort *)(iVar5 + iVar6);
    iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar5 + iVar6) = uVar3 & 0xefff | (ushort)bVar2 << 0xc;
  }
  return uVar17;
}

