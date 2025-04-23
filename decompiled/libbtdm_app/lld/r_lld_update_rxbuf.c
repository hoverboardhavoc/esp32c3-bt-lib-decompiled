/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld.o -> r_lld_update_rxbuf
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_lld_update_rxbuf(uint param_1,uint param_2)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  
  if (((int)param_1 < 0x111) && (param_2 - 1 < 9)) {
    (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
    uVar8 = _DAT_60031024 & 0x7fff;
    iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar3 = (uVar8 - 0x1000) / 0x14 & 0xff;
    uVar1 = *(ushort *)(uVar3 * 0x14 + iVar5);
    uVar7 = (*(byte *)(_p_lld_env + 0xd9) + 1) % 10;
    iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
    iVar5 = uVar7 * 0x14;
    if (-1 < *(short *)(iVar6 + iVar5)) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld.c",0x6f6,*(code **)(_r_plf_funcs_p + 8));
    }
    (**(code **)(_r_ip_funcs_p + 0x10c))(param_2 & 0xff,*(code **)(_r_ip_funcs_p + 0x10c));
    (**(code **)(_r_ip_funcs_p + 0x110))(param_1 & 0xffff,*(code **)(_r_ip_funcs_p + 0x110));
    *(undefined1 *)(_p_lld_env + 0x101) = 1;
    _DAT_600312d0 = uVar7 * 0x14 + 0x1000 | _DAT_600312d0 & 0xffff8000 | 0x8000;
    (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
    if (2 < _g_bt_plf_log_level) {
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar2 = *(ushort *)(iVar6 + iVar5);
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
      ets_printf("RXBUF Update RXDESC: Current %04x[%d], RD %d; Jump %04x[%d], RD %d, NextPTR %04x\n"
                 ,uVar8,uVar3,uVar1 >> 0xf,iVar5 + 0x1000,uVar7,uVar2 >> 0xf,
                 *(ushort *)(iVar6 + iVar5) & 0x7fff);
    }
    uVar4 = 1;
  }
  else {
    if (0 < _g_bt_plf_log_level) {
      ets_printf("RXBUF Update failed, SZ %d, NB %d!\n",param_1,param_2);
    }
    uVar4 = 0;
  }
  return uVar4;
}

