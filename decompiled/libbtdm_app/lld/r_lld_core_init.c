/*
 * Last changed at upstream commit 0cfac1b21ebc995e8e9aa040ab1ab29deee4f580
 * https://github.com/espressif/esp32c3-bt-lib/commit/0cfac1b21ebc995e8e9aa040ab1ab29deee4f580
 * Upstream date: 2023-08-10 21:56:13 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(59725b5)
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
  int iVar6;
  uint uVar7;
  undefined1 uStack_45;
  undefined4 uStack_44;
  
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
  iVar2 = (*_rwip_param)(0x31,&uStack_45,&uStack_44,_rwip_param);
  if (iVar2 == 0) {
    if ((int)uStack_44 < 0) {
      (**(code **)(_r_plf_funcs_p + 8))("lld.c",0xa7d,*(code **)(_r_plf_funcs_p + 8));
    }
    if (uStack_44._2_1_ < '\0') {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld.c",0xa7f,*(code **)(_r_plf_funcs_p + 8));
    }
    if (uStack_44._1_1_ < '\0') {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld.c",0xa81,*(code **)(_r_plf_funcs_p + 8));
    }
    if ((uStack_44 & 0x80) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld.c",0xa83,*(code **)(_r_plf_funcs_p + 8));
    }
    _DAT_60031050 = uStack_44 | 0x80808080;
  }
  uVar3 = (uint)_r_lld_sw_cca_isr;
  _DAT_60031000 = (int)(DAT_00011026 + 1) >> 1 | 0x100600;
  uVar7 = ((uint)_DAT_0001103a << 0x11) >> 0x10;
  if ((uVar3 << 0x11 & 0xfc000000) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld.c",0x1902,*(code **)(_r_plf_funcs_p + 8));
  }
  if ((uVar7 & 0xfffffe00) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld.c",0x1903,*(code **)(_r_plf_funcs_p + 8));
  }
  _DAT_600310e0 = uVar3 << 0x11 | uVar7;
  if (DAT_00011051 == '\0') {
    _DAT_6003100c = 0x40000;
  }
  else {
    _DAT_600312d8 = _DAT_600312d8 | 0x8000001e;
    _DAT_6003100c = 0x640000;
  }
  _DAT_6003100c = _DAT_6003100c + 0x166;
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
    iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
    iVar4 = _r_ip_funcs_p;
    *(short *)(iVar5 + iVar2) = (short)(uVar7 % 10) * 0x14 + 0x1000;
    iVar4 = (**(code **)(iVar4 + 0xe8))(*(code **)(iVar4 + 0xe8));
    if ((int)uVar3 < iVar4) {
      iVar4 = (**(code **)(_r_ip_funcs_p + 0xfc))(*(code **)(_r_ip_funcs_p + 0xfc));
      if (iVar4 == 0) {
        (**(code **)(_r_plf_funcs_p + 8))("lld.c",0xee,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar5 = _p_lld_env;
      *(short *)(iVar6 + iVar2 + 0x12) = (short)iVar4;
      *(char *)(iVar5 + 0xd9) = (char)uVar7 + -1;
    }
    else {
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar4 = _r_plf_funcs_p;
      *(undefined2 *)(iVar5 + iVar2 + 0x12) = 0;
      iVar4 = (**(code **)(iVar4 + 0xbc))(0x1000,*(code **)(iVar4 + 0xbc));
      uVar1 = *(ushort *)(iVar4 + iVar2);
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar4 + iVar2) = uVar1 & 0x7fff | 0x8000;
    }
    iVar5 = iVar2 + 2;
    iVar2 = iVar2 + 0x14;
    iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar1 = *(ushort *)(iVar4 + iVar5);
    iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar4 + iVar5) = uVar1 & 0x7fff | 0x8000;
    uVar3 = uVar7;
  } while (uVar7 != 10);
  iVar2 = 3;
  if (DAT_00011012 == '\0') {
    iVar2 = 0;
  }
  _DAT_600312d4 = _DAT_600312d4 & 0xfffffe00 | iVar2 + 0xffU;
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
  _DAT_0001101e = ((ushort)((uint)_DAT_60031094 >> 8) & 0x7f) + 0x18;
  uVar1 = (ushort)((uint)_DAT_60031098 >> 8);
  _r_osi_funcs_p = CONCAT22((uVar1 & 0xff) + 0x150,(uVar1 & 0xff) + 0x150);
  uVar3 = (**(code **)(_r_osi_funcs_p + 0x88))(*(code **)(_r_osi_funcs_p + 0x88));
  _DAT_60031178 = uVar3 & 0x3fffff | 0x80000000;
  uVar3 = (**(code **)(_r_osi_funcs_p + 0x88))(*(code **)(_r_osi_funcs_p + 0x88));
  _DAT_6003117c = uVar3 & 0x3fffff | 0x80000000;
  _DAT_60031000 = _DAT_60031000 | 0x100;
  if (_DAT_60031004 != 0x9001b00) {
    (**(code **)(_r_plf_funcs_p + 0xc))
              (_DAT_60031004,"lld.c",0x12a,*(code **)(_r_plf_funcs_p + 0xc));
  }
  return;
}

