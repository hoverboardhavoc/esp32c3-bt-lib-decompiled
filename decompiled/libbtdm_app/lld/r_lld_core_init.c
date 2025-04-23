/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld.o -> r_lld_core_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_core_init(int param_1)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  code *pcVar6;
  uint uVar7;
  int iVar8;
  undefined1 uStack_45;
  uint auStack_44 [4];
  
  if (param_1 != 1) {
    if (param_1 != 2) {
      return;
    }
    iVar2 = 0;
    do {
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc00,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar4 + iVar2) = 0;
      iVar2 = iVar2 + 8;
    } while (iVar2 != 0x60);
    (**(code **)(_r_ip_funcs_p + 0x278))(*(code **)(_r_ip_funcs_p + 0x278));
    _DAT_600310d0 = _DAT_600310d0 & 0xffffefff;
    _DAT_60031050 = 0;
  }
  uStack_45 = 4;
  iVar2 = (*_rwip_param)(0x31,&uStack_45,auStack_44,_rwip_param);
  if (iVar2 == 0) {
    if ((int)auStack_44[0] < 0) {
      (**(code **)(_r_plf_funcs_p + 8))("lld.c",0xa7d,*(code **)(_r_plf_funcs_p + 8));
    }
    if ((auStack_44[0] & 0x800000) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld.c",0xa7f,*(code **)(_r_plf_funcs_p + 8));
    }
    if ((auStack_44[0] & 0x8000) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld.c",0xa81,*(code **)(_r_plf_funcs_p + 8));
    }
    if ((char)auStack_44[0] < '\0') {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld.c",0xa83,*(code **)(_r_plf_funcs_p + 8));
    }
    _DAT_60031050 = auStack_44[0] | 0x80808080;
  }
  _DAT_60031000 = (int)(DAT_0001402e + 1) >> 1 | 0x100200;
  uVar3 = ((uint)_rwip_prog_delay << 0x11) >> 0x10;
  uVar7 = ((uint)_DAT_00014042 << 0x11) >> 0x10;
  if (0x3ff < uVar3) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld.c",0x1902,*(code **)(_r_plf_funcs_p + 8));
  }
  if (0x1ff < uVar7) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld.c",0x1903,*(code **)(_r_plf_funcs_p + 8));
  }
  _DAT_600310e0 = uVar3 << 0x10 | uVar7;
  _DAT_6003100c = 0x40166;
  if (DAT_00014059 != '\0') {
    _DAT_600312d8 = _DAT_600312d8 | 0x8000001e;
    _DAT_6003100c = 0x640166;
  }
  _DAT_60031120 = 0xffff02d9;
  _DAT_60031130 = 0xc0c00;
  _DAT_60031134 = 0xc00;
  _DAT_60031138 = 0xc0c00;
  _DAT_6003113c = 0xc00;
  _DAT_60031170 = 0xa0c60;
  _DAT_60031174 = 0xc60;
  _DAT_60031148 = 0x10;
  iVar2 = 0;
  uVar3 = 0;
  do {
    uVar7 = uVar3 + 1;
    iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
    pcVar6 = *(code **)(_r_ip_funcs_p + 0xe8);
    *(short *)(iVar4 + iVar2) = (short)(uVar7 % 10) * 0x14 + 0x1000;
    iVar4 = (*pcVar6)(pcVar6);
    if ((int)uVar3 < iVar4) {
      iVar4 = (**(code **)(_r_ip_funcs_p + 0xfc))(*(code **)(_r_ip_funcs_p + 0xfc));
      if (iVar4 == 0) {
        (**(code **)(_r_plf_funcs_p + 8))("lld.c",0x108,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar8 = _p_lld_env;
      *(short *)(iVar5 + iVar2 + 0x12) = (short)iVar4;
      *(char *)(iVar8 + 0xd9) = (char)uVar3;
    }
    else {
      iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar4 = _r_plf_funcs_p;
      *(undefined2 *)(iVar8 + iVar2 + 0x12) = 0;
      iVar4 = (**(code **)(iVar4 + 0xbc))(0x1000,*(code **)(iVar4 + 0xbc));
      uVar1 = *(ushort *)(iVar4 + iVar2);
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar4 + iVar2) = uVar1 | 0x8000;
    }
    iVar8 = iVar2 + 2;
    iVar2 = iVar2 + 0x14;
    iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar1 = *(ushort *)(iVar4 + iVar8);
    iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar4 + iVar8) = uVar1 | 0x8000;
    uVar3 = uVar7;
  } while (uVar7 != 10);
  _DAT_600312d4 = _DAT_600312d4 & 0xfffffe00 | (-(uint)(DAT_0001401a == '\0') & 0xfffffffd) + 0x102;
  if (2 < _g_bt_plf_log_level) {
    ets_printf("RX MAX LENGTH %d\n");
  }
  _DAT_60031024 = 0x1000;
  iVar2 = 0;
  do {
    iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar1 = *(ushort *)(iVar4 + 2 + iVar2 * 0x5a);
    iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar4 + 2 + iVar2 * 0x5a) = uVar1 & 0xffe0 | (ushort)iVar2;
    iVar2 = iVar2 + 1;
  } while (iVar2 != 0xc);
  _lld_exp_sync_pos_tab = ((ushort)((uint)_DAT_60031090 >> 8) & 0x7f) + 0x28;
  _DAT_00014026 = ((ushort)((uint)_DAT_60031094 >> 8) & 0x7f) + 0x18;
  uVar1 = (ushort)((uint)_DAT_60031098 >> 8);
  _r_osi_funcs_p = CONCAT22((uVar1 & 0xff) + 0x150,(uVar1 & 0xff) + 0x150);
  uVar3 = (**(code **)(_r_osi_funcs_p + 0x88))(*(code **)(_r_osi_funcs_p + 0x88));
  _DAT_60031178 = uVar3 & 0x3fffff | 0x80000000;
  uVar3 = (**(code **)(_r_osi_funcs_p + 0x88))(*(code **)(_r_osi_funcs_p + 0x88));
  _DAT_6003117c = uVar3 & 0x3fffff | 0x80000000;
  _DAT_60031000 = _DAT_60031000 | 0x100;
  if (_DAT_60031004 != 0x9001b00) {
    (**(code **)(_r_plf_funcs_p + 0xc))
              (_DAT_60031004,"lld.c",0x144,*(code **)(_r_plf_funcs_p + 0xc));
  }
  return;
}

