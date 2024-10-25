/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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
  int iVar7;
  char *pcVar8;
  void *__dest;
  uint uVar9;
  code *pcVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  ushort *in_stack_00000000;
  undefined2 uStack_4c;
  undefined1 auStack_4a [5];
  undefined1 uStack_45;
  undefined1 uStack_44;
  
  iVar13 = *(int *)(&lld_per_adv_env + param_1 * 4);
  iVar11 = param_2 * 0xe;
  iVar16 = (uint)*(byte *)(iVar13 + 0x52) * 9;
  iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar3 = *(ushort *)(iVar6 + iVar11);
  iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(ushort *)(iVar6 + iVar11) = uVar3 & 0x8000;
  if (param_5 == 0) {
    iVar12 = 0;
    iVar6 = 0;
    if (param_2 != iVar16) goto _L110;
    iVar6 = 1;
  }
  else {
    iVar12 = 2;
    iVar6 = 2;
    if (param_2 != iVar16) goto _L110;
    iVar6 = 2;
  }
  iVar6 = iVar6 + 9;
_L110:
  if ((uint)*in_stack_00000000 + iVar6 < 0xff) {
    iVar15 = 0;
    sVar5 = 0;
  }
  else {
    if ((iVar12 == 0) && (iVar12 = 1, iVar6 == 0)) {
      iVar6 = 1;
    }
    iVar12 = iVar12 + 3;
    iVar6 = iVar6 + 3;
    iVar15 = 1;
    sVar5 = 3;
  }
  if (param_5 != 0) {
    cVar1 = *(char *)(iVar13 + 0x56);
    iVar7 = (**(code **)(_r_ip_funcs_p + 0x4f8))(*(code **)(_r_ip_funcs_p + 0x4f8));
    pcVar8 = (char *)(**(code **)(_r_plf_funcs_p + 0xbc))
                               (*param_6 + sVar5,*(code **)(_r_plf_funcs_p + 0xbc));
    sVar5 = sVar5 + 1;
    *pcVar8 = cVar1 + (char)(iVar7 / 10);
  }
  if (param_2 == iVar16) {
    *(char *)(iVar13 + 0x59) = (char)sVar5;
    iVar7 = _r_plf_funcs_p;
    uStack_4c = 0x2808;
    memcpy(auStack_4a,(void *)(iVar13 + 0x2f),5);
    uStack_45 = (undefined1)*(undefined2 *)(iVar13 + 0x3a);
    uStack_44 = (undefined1)((ushort)*(undefined2 *)(iVar13 + 0x3a) >> 8);
    __dest = (void *)(**(code **)(iVar7 + 0xbc))(*param_6 + sVar5,*(code **)(iVar7 + 0xbc));
    sVar5 = sVar5 + 9;
    memcpy(__dest,&uStack_4c,9);
  }
  uVar14 = 0;
  uVar9 = (uint)*in_stack_00000000;
  if (uVar9 != 0) {
    uVar14 = -iVar6 - 2U & 0xff;
    if (uVar9 < uVar14) {
      uVar14 = uVar9 & 0xff;
    }
    *in_stack_00000000 = *in_stack_00000000 - (short)uVar14;
  }
  if ((param_4 << 6 & 0xffffff3fU) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_per_adv.c",500,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(ushort *)(iVar7 + iVar11 + 6) =
       (ushort)(param_5 << 0xe) | (ushort)(param_4 << 6) | (ushort)iVar12 | (ushort)(iVar15 << 0xc);
  iVar6 = (**(code **)(_r_modules_funcs_p + 4))
                    (iVar6 + 1 + uVar14 & 0xff,*(undefined1 *)(iVar13 + 0x55),
                     *(code **)(_r_modules_funcs_p + 4));
  iVar7 = 0;
  if (iVar15 != 0) {
    iVar7 = (iVar6 + 300U) / 0x1e + 1;
    iVar6 = iVar7 * 0x1e;
    *(short *)(iVar13 + 0x4a) = (short)iVar7;
  }
  bVar2 = *(byte *)(iVar13 + 0x57);
  uVar3 = *(ushort *)(_p_lld_env + 0xd4);
  if ((bVar2 & 0xc0) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_per_adv.c",0x2b0,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar15 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(ushort *)(iVar15 + iVar11 + 8) =
       (ushort)(uVar3 < 0x33) << 6 | (ushort)bVar2 | (ushort)(iVar7 << 8);
  uVar3 = *(ushort *)(iVar13 + 0x4a) >> 8;
  uVar9 = (uint)*(byte *)(iVar13 + 0x55) << 5;
  if ((uVar9 & 0xffffff1f) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_per_adv.c",0x31c,*(code **)(_r_plf_funcs_p + 8));
  }
  if ((uVar3 & 0xffe0) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_per_adv.c",0x31d,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar7 = iVar11 + 10;
  iVar15 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(ushort *)(iVar15 + iVar7) = (ushort)uVar9 | uVar3;
  sVar4 = *param_6;
  iVar15 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(short *)(iVar15 + iVar11 + 0xc) = sVar4;
  *param_6 = sVar5 + *param_6;
  if ((param_3 & 0xfffffff0) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_per_adv.c",0x126,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar15 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(ushort *)(iVar15 + iVar11 + 2) =
       (ushort)((iVar12 + 1 + uVar14 & 0xff) << 8) | (ushort)param_3 | 0x20;
  sVar5 = *param_7;
  iVar15 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(short *)(iVar15 + iVar11 + 4) = sVar5;
  *param_7 = *param_7 + (short)uVar14;
  iVar15 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar3 = *(ushort *)(iVar15 + iVar11);
  iVar15 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(ushort *)(iVar15 + iVar11) = uVar3 & 0x7fff;
  if (param_2 == iVar16) {
    *(char *)(iVar13 + 0x5a) = (char)iVar12;
    *(char *)(iVar13 + 0x5b) = (char)uVar14;
  }
  iVar11 = (**(code **)(_r_modules_funcs_p + 0x1a0))(4,*(code **)(_r_modules_funcs_p + 0x1a0));
  if (iVar11 != 0) {
    if (2 < _g_bt_plf_log_level) {
      ets_printf("TX PTI [PER ADV DATA] [EN%d] [%d] \n",*(undefined1 *)(iVar11 + 4),
                 *(undefined1 *)(iVar11 + 5));
    }
    uVar9 = (uint)*(byte *)(iVar11 + 5) << 8;
    if ((uVar9 & 0xf000) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_per_adv.c",0x33f,*(code **)(_r_plf_funcs_p + 8));
    }
    iVar13 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar3 = *(ushort *)(iVar13 + iVar7);
    iVar13 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    pcVar10 = *(code **)(_r_plf_funcs_p + 0xbc);
    *(ushort *)(iVar13 + iVar7) = uVar3 & 0xf0ff | (ushort)uVar9;
    bVar2 = *(byte *)(iVar11 + 4);
    iVar11 = (*pcVar10)(0x1400,pcVar10);
    uVar3 = *(ushort *)(iVar11 + iVar7);
    iVar11 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar11 + iVar7) = uVar3 & 0xefff | (ushort)bVar2 << 0xc;
  }
  return iVar6;
}

