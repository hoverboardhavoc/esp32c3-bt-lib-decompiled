/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_per_adv.o -> r_lld_per_adv_ext_pkt_prepare
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int r_lld_per_adv_ext_pkt_prepare
              (int param_1,int param_2,uint param_3,int param_4,int param_5,short *param_6,
              short *param_7)

{
  char cVar1;
  byte bVar2;
  ushort uVar3;
  short sVar4;
  short sVar5;
  int iVar6;
  char *pcVar7;
  void *__dest;
  int iVar8;
  int iVar9;
  uint uVar10;
  code *pcVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  int iVar16;
  ushort *in_stack_00000000;
  int local_60;
  undefined2 uStack_4c;
  undefined1 auStack_4a [5];
  undefined1 uStack_45;
  undefined1 uStack_44;
  
  iVar12 = *(int *)(&lld_per_adv_env + param_1 * 4);
  iVar13 = param_2 * 0xe;
  iVar16 = (uint)*(byte *)(iVar12 + 0x52) * 9;
  iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar3 = *(ushort *)(iVar6 + iVar13);
  iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(ushort *)(iVar6 + iVar13) = uVar3 & 0x8000;
  if (param_5 == 0) {
    iVar14 = 0;
    iVar6 = 0;
    if (param_2 != iVar16) goto _L109;
    iVar6 = 1;
  }
  else {
    iVar14 = 2;
    iVar6 = 2;
    if (param_2 != iVar16) goto _L109;
    iVar6 = 2;
  }
  iVar6 = iVar6 + 9;
_L109:
  if ((uint)*in_stack_00000000 + iVar6 < 0xff) {
    local_60 = 0;
    sVar5 = 0;
  }
  else {
    iVar9 = 2;
    if (iVar14 == 0) {
      if (iVar6 == 0) {
        iVar6 = 1;
      }
      iVar9 = 1;
    }
    iVar6 = iVar6 + 3;
    iVar14 = iVar9 + 3;
    local_60 = 1;
    sVar5 = 3;
  }
  if (param_5 != 0) {
    cVar1 = *(char *)(iVar12 + 0x56);
    iVar9 = (**(code **)(_r_ip_funcs_p + 0x4f8))(*(code **)(_r_ip_funcs_p + 0x4f8));
    pcVar7 = (char *)(**(code **)(_r_plf_funcs_p + 0xbc))
                               (*param_6 + sVar5,*(code **)(_r_plf_funcs_p + 0xbc));
    sVar5 = sVar5 + 1;
    *pcVar7 = cVar1 + (char)(iVar9 / 10);
  }
  if (param_2 == iVar16) {
    *(char *)(iVar12 + 0x59) = (char)sVar5;
    iVar9 = _r_plf_funcs_p;
    uStack_4c = 0x2808;
    memcpy(auStack_4a,(void *)(iVar12 + 0x2f),5);
    uStack_45 = (undefined1)*(undefined2 *)(iVar12 + 0x3a);
    uStack_44 = (undefined1)((ushort)*(undefined2 *)(iVar12 + 0x3a) >> 8);
    __dest = (void *)(**(code **)(iVar9 + 0xbc))(*param_6 + sVar5,*(code **)(iVar9 + 0xbc));
    sVar5 = sVar5 + 9;
    memcpy(__dest,&uStack_4c,9);
  }
  uVar15 = 0;
  uVar10 = (uint)*in_stack_00000000;
  if (uVar10 != 0) {
    uVar15 = -iVar6 - 2U & 0xff;
    if (uVar10 < uVar15) {
      uVar15 = uVar10 & 0xff;
    }
    *in_stack_00000000 = *in_stack_00000000 - (short)uVar15;
  }
  if ((param_4 << 6 & 0xffffff3fU) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,500,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  iVar9 = _r_modules_funcs_p;
  *(ushort *)(iVar13 + 6 + iVar8) =
       (ushort)(param_5 << 0xe) | (ushort)(param_4 << 6) | (ushort)iVar14 |
       (ushort)(local_60 << 0xc);
  iVar6 = (**(code **)(iVar9 + 4))
                    (uVar15 + iVar6 + 1 & 0xff,*(undefined1 *)(iVar12 + 0x55),*(code **)(iVar9 + 4))
  ;
  iVar9 = 0;
  if (local_60 != 0) {
    iVar9 = (iVar6 + 300U) / 0x1e + 1;
    iVar6 = iVar9 * 0x1e;
    *(short *)(iVar12 + 0x4a) = (short)iVar9;
  }
  bVar2 = *(byte *)(iVar12 + 0x57);
  uVar3 = *(ushort *)(_p_lld_env + 0xd4);
  if ((bVar2 & 0xc0) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x2b0,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(ushort *)(iVar13 + 8 + iVar8) =
       (ushort)(uVar3 < 0x33) << 6 | (ushort)bVar2 | (ushort)(iVar9 << 8);
  uVar3 = *(ushort *)(iVar12 + 0x4a) >> 8;
  uVar10 = (uint)*(byte *)(iVar12 + 0x55) << 5;
  if ((uVar10 & 0xffffff1f) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x31c,*(code **)(_r_plf_funcs_p + 8));
  }
  if ((uVar3 & 0xffe0) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x31d,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar8 = iVar13 + 10;
  iVar9 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(ushort *)(iVar9 + iVar8) = uVar3 | (ushort)uVar10;
  sVar4 = *param_6;
  iVar9 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(short *)(iVar13 + 0xc + iVar9) = sVar4;
  *param_6 = *param_6 + sVar5;
  if ((param_3 & 0xfffffff0) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x126,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar9 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(ushort *)(iVar13 + 2 + iVar9) =
       (ushort)((iVar14 + 1 + uVar15 & 0xff) << 8) | (ushort)param_3 | 0x20;
  sVar5 = *param_7;
  iVar9 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(short *)(iVar13 + 4 + iVar9) = sVar5;
  *param_7 = *param_7 + (short)uVar15;
  iVar9 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar3 = *(ushort *)(iVar9 + iVar13);
  iVar9 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(ushort *)(iVar9 + iVar13) = (ushort)(((uint)uVar3 << 0x11) >> 0x11);
  if (param_2 == iVar16) {
    *(char *)(iVar12 + 0x5a) = (char)iVar14;
    *(char *)(iVar12 + 0x5b) = (char)uVar15;
  }
  iVar12 = (**(code **)(_r_modules_funcs_p + 0x1a0))(4,*(code **)(_r_modules_funcs_p + 0x1a0));
  if (iVar12 != 0) {
    if (2 < _g_bt_plf_log_level) {
      ets_printf("TX PTI [PER ADV DATA] [EN%d] [%d] \n",*(undefined1 *)(iVar12 + 4),
                 *(undefined1 *)(iVar12 + 5));
    }
    uVar10 = (uint)*(byte *)(iVar12 + 5) << 8;
    if ((uVar10 & 0xf000) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x33f,*(code **)(_r_plf_funcs_p + 8));
    }
    iVar13 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar3 = *(ushort *)(iVar13 + iVar8);
    iVar13 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    pcVar11 = *(code **)(_r_plf_funcs_p + 0xbc);
    *(ushort *)(iVar13 + iVar8) = uVar3 & 0xf0ff | (ushort)uVar10;
    bVar2 = *(byte *)(iVar12 + 4);
    iVar12 = (*pcVar11)(0x1400,pcVar11);
    uVar3 = *(ushort *)(iVar12 + iVar8);
    iVar12 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar8 + iVar12) = uVar3 & 0xefff | (ushort)bVar2 << 0xc;
  }
  return iVar6;
}

