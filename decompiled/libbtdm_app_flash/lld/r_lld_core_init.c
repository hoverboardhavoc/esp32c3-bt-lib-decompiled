/*
 * Last changed at upstream commit 72599d583c232ea78d6461b5b502426c6e5a1ec9
 * https://github.com/espressif/esp32c3-bt-lib/commit/72599d583c232ea78d6461b5b502426c6e5a1ec9
 * Upstream date: 2025-05-19 16:27:45 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(6cfabcd8)
 * Source: libbtdm_app_flash -> lld.o -> r_lld_core_init
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
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  undefined1 uStack_45;
  undefined4 uStack_44;
  
  if (param_1 != 1) {
    if (param_1 != 2) {
      return;
    }
    iVar3 = 0;
    do {
      iVar5 = r_emi_get_mem_addr_by_offset(0xc00);
      *(undefined2 *)(iVar5 + iVar3) = 0;
      iVar3 = iVar3 + 8;
    } while (iVar3 != 0x60);
    r_lld_res_list_clear_hack();
    _DAT_600310d0 = _DAT_600310d0 & 0xffffefff;
    _DAT_60031050 = 0;
  }
  uStack_45 = 4;
  iVar3 = (*_rwip_param)(0x31,&uStack_45,&uStack_44,_rwip_param);
  if (iVar3 == 0) {
    if ((int)uStack_44 < 0) {
      r_assert_err("lld.c",0xa7d);
    }
    if (uStack_44._2_1_ < '\0') {
      r_assert_err(0,"lld.c",0xa7f);
    }
    if (uStack_44._1_1_ < '\0') {
      r_assert_err(0,"lld.c",0xa81);
    }
    if ((uStack_44 & 0x80) != 0) {
      r_assert_err(0,"lld.c",0xa83);
    }
    _DAT_60031050 = uStack_44 | 0x80808080;
  }
  uVar4 = (uint)_r_ble_util_buf_rx_alloc_in_isr;
  _DAT_60031000 = (int)(DAT_00014062 + 1) >> 1 | 0x100200;
  uVar7 = ((uint)_DAT_00014076 << 0x11) >> 0x10;
  if ((uVar4 << 0x11 & 0xfc000000) != 0) {
    r_assert_err(0,"lld.c",0x1902);
  }
  if ((uVar7 & 0xfffffe00) != 0) {
    r_assert_err(0,"lld.c",0x1903);
  }
  _DAT_600310e0 = uVar4 << 0x11 | uVar7;
  if (DAT_0001408d == '\0') {
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
  iVar3 = 0;
  uVar4 = 0;
  do {
    uVar7 = uVar4 + 1;
    iVar5 = r_emi_get_mem_addr_by_offset(0x1000);
    *(short *)(iVar5 + iVar3) = (short)(((uVar7 % 10) * 0x14 + 0x1000) * 0x10000 >> 0x10);
    iVar5 = r_ble_util_buf_get_rx_buf_nb();
    if ((int)uVar4 < iVar5) {
      iVar5 = r_ble_util_buf_rx_alloc();
      if (iVar5 == 0) {
        r_assert_err("lld.c",0x108);
      }
      iVar6 = r_emi_get_mem_addr_by_offset(0x1000);
      iVar2 = _p_lld_env;
      *(short *)(iVar6 + iVar3 + 0x12) = (short)iVar5;
      *(char *)(iVar2 + 0xd9) = (char)uVar4;
    }
    else {
      iVar5 = r_emi_get_mem_addr_by_offset(0x1000);
      *(undefined2 *)(iVar5 + iVar3 + 0x12) = 0;
      iVar5 = r_emi_get_mem_addr_by_offset(0x1000);
      uVar1 = *(ushort *)(iVar5 + iVar3);
      iVar5 = r_emi_get_mem_addr_by_offset(0x1000);
      *(ushort *)(iVar5 + iVar3) = uVar1 & 0x7fff | 0x8000;
    }
    iVar5 = r_emi_get_mem_addr_by_offset(0x1000);
    uVar1 = *(ushort *)(iVar5 + iVar3 + 2);
    iVar5 = r_emi_get_mem_addr_by_offset(0x1000);
    *(ushort *)(iVar3 + 2 + iVar5) = uVar1 & 0x7fff | 0x8000;
    iVar3 = iVar3 + 0x14;
    uVar4 = uVar7;
  } while (uVar7 != 10);
  iVar3 = 3;
  if (DAT_0001404e == '\0') {
    iVar3 = 0;
  }
  _DAT_600312d4 = _DAT_600312d4 & 0xfffffe00 | iVar3 + 0xffU;
  if (2 < _g_bt_plf_log_level) {
    ets_printf("RX MAX LENGTH %d\n");
  }
  _DAT_60031024 = 0x1000;
  iVar3 = 0;
  do {
    iVar5 = r_emi_get_mem_addr_by_offset(0x400);
    uVar1 = *(ushort *)(iVar5 + 2 + iVar3 * 0x5a);
    iVar5 = r_emi_get_mem_addr_by_offset(0x400);
    *(ushort *)(iVar5 + 2 + iVar3 * 0x5a) = uVar1 & 0xffe0 | (ushort)iVar3;
    iVar3 = iVar3 + 1;
  } while (iVar3 != 0xc);
  _lld_exp_sync_pos_tab = ((ushort)((uint)_DAT_60031090 >> 8) & 0x7f) + 0x28;
  _DAT_00014062 = ((ushort)((uint)_DAT_60031094 >> 8) & 0x7f) + 0x18;
  uVar1 = (ushort)((uint)_DAT_60031098 >> 8);
  _r_osi_funcs_p = CONCAT22((uVar1 & 0xff) + 0x150,(uVar1 & 0xff) + 0x150);
  uVar4 = (**(code **)(_r_osi_funcs_p + 0x88))(*(code **)(_r_osi_funcs_p + 0x88));
  _DAT_60031178 = uVar4 & 0x3fffff | 0x80000000;
  uVar4 = (**(code **)(_r_osi_funcs_p + 0x88))(*(code **)(_r_osi_funcs_p + 0x88));
  _DAT_6003117c = uVar4 & 0x3fffff | 0x80000000;
  _DAT_60031000 = _DAT_60031000 | 0x100;
  if (_DAT_60031004 != 0x9001b00) {
    r_assert_param(_DAT_60031004,"lld.c",0x144);
  }
  return;
}

