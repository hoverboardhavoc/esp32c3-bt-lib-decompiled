/*
 * Last changed at upstream commit b0ccea3c26a049649d2fdbaca78318af90a6dd5b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b0ccea3c26a049649d2fdbaca78318af90a6dd5b
 * Upstream date: 2025-05-16 11:55:10 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(4713205)
 * Source: libbtdm_app -> lld.o -> lld_update_rxbuf_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 lld_update_rxbuf_handler(void)

{
  ushort uVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  code *pcVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  uVar3 = ((_DAT_600312d0 & 0x7fff) - 0x1000) / 0x14;
  for (uVar8 = uVar3; uVar8 != uVar3 + 10; uVar8 = uVar8 + 1) {
    iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
    iVar7 = ((int)uVar8 % 10) * 0x14;
    sVar2 = *(short *)(iVar7 + 0x12 + iVar4);
    iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
    if ((-1 < *(short *)(iVar4 + iVar7)) && (sVar2 != 0)) {
      (**(code **)(_r_ip_funcs_p + 0x104))(sVar2,0,*(code **)(_r_ip_funcs_p + 0x104));
    }
  }
  while (iVar4 = (**(code **)(_r_ip_funcs_p + 0xfc))(*(code **)(_r_ip_funcs_p + 0xfc)), iVar4 != 0)
  {
    (**(code **)(_r_ip_funcs_p + 0x104))(0,*(code **)(_r_ip_funcs_p + 0x104));
  }
  iVar7 = 3;
  (**(code **)(_r_ip_funcs_p + 0x114))(*(code **)(_r_ip_funcs_p + 0x114));
  iVar4 = (**(code **)(_r_ip_funcs_p + 0xec))(*(code **)(_r_ip_funcs_p + 0xec));
  if (sdk_cfg_priv_opts == '\0') {
    iVar7 = 0;
  }
  uVar8 = iVar7 + iVar4;
  if ((uVar8 & 0xfe00) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld.c",0x286e,*(code **)(_r_plf_funcs_p + 8));
  }
  _DAT_600312d4 = _DAT_600312d4 & 0xfffffe00 | uVar8 & 0xffff;
  uVar9 = uVar3;
  if (2 < _g_bt_plf_log_level) {
    ets_printf("RX MAX LENGTH %d\n",uVar8);
  }
  for (; iVar4 = _p_lld_env, pcVar6 = *(code **)(_r_plf_funcs_p + 0xbc), uVar9 != uVar3 + 10;
      uVar9 = uVar9 + 1) {
    iVar4 = (*pcVar6)(0x1000);
    iVar7 = ((int)uVar9 % 10) * 0x14;
    uVar1 = *(ushort *)(iVar4 + iVar7 + 2);
    iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar4 + iVar7 + 2) = uVar1 & 0x7fff | 0x8000;
    iVar4 = (**(code **)(_r_ip_funcs_p + 0xe8))(*(code **)(_r_ip_funcs_p + 0xe8));
    if ((int)uVar9 < (int)(iVar4 + uVar3)) {
      iVar4 = (**(code **)(_r_ip_funcs_p + 0xfc))(*(code **)(_r_ip_funcs_p + 0xfc));
      if (iVar4 == 0) {
        (**(code **)(_r_plf_funcs_p + 0xc))
                  (uVar9,uVar3,"lld.c",0x754,*(code **)(_r_plf_funcs_p + 0xc));
      }
      else {
        iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
        *(short *)(iVar7 + 0x12 + iVar5) = (short)iVar4;
        if (uVar9 != uVar3) {
          iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
          uVar1 = *(ushort *)(iVar4 + iVar7);
          iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
          *(ushort *)(iVar4 + iVar7) = uVar1 & 0x7fff;
        }
      }
      *(char *)(_p_lld_env + 0xd9) = (char)uVar9;
    }
    else {
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar7 + 0x12 + iVar4) = 0;
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar1 = *(ushort *)(iVar4 + iVar7);
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar7 + iVar4) = uVar1 & 0x7fff | 0x8000;
    }
  }
  *(char *)(_p_lld_env + 0xd8) = (char)uVar3;
  *(undefined1 *)(iVar4 + 0x101) = 0;
  iVar4 = (*pcVar6)(0x1000);
  uVar1 = *(ushort *)(iVar4 + uVar3 * 0x14);
  iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  pcVar6 = *(code **)(_r_osi_funcs_p + 0x18);
  *(ushort *)(uVar3 * 0x14 + iVar4) = (ushort)(((uint)uVar1 << 0x11) >> 0x11);
  (*pcVar6)(pcVar6);
  if (2 < _g_bt_plf_log_level) {
    ets_printf("RXBUF Update OK\n");
  }
  return 0;
}

