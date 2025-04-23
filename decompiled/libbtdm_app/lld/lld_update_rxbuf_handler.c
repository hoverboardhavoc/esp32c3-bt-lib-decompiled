/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld.o -> lld_update_rxbuf_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 lld_update_rxbuf_handler(void)

{
  short sVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  code *pcVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  uVar3 = ((_DAT_600312d0 & 0x7fff) - 0x1000) / 0x14;
  uVar7 = uVar3;
  do {
    iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
    iVar9 = ((int)uVar7 % 10) * 0x14;
    sVar1 = *(short *)(iVar4 + 0x12 + iVar9);
    iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
    if ((-1 < *(short *)(iVar4 + iVar9)) && (sVar1 != 0)) {
      (**(code **)(_r_ip_funcs_p + 0x104))(sVar1,0,*(code **)(_r_ip_funcs_p + 0x104));
    }
    uVar7 = uVar7 + 1;
  } while (uVar7 != uVar3 + 10);
  while (iVar4 = (**(code **)(_r_ip_funcs_p + 0xfc))(*(code **)(_r_ip_funcs_p + 0xfc)), iVar4 != 0)
  {
    (**(code **)(_r_ip_funcs_p + 0x104))(0,*(code **)(_r_ip_funcs_p + 0x104));
  }
  (**(code **)(_r_ip_funcs_p + 0x114))(*(code **)(_r_ip_funcs_p + 0x114));
  iVar4 = (**(code **)(_r_ip_funcs_p + 0xec))(*(code **)(_r_ip_funcs_p + 0xec));
  uVar7 = (-(uint)(sdk_cfg_priv_opts == '\0') & 0xfffffffd) + 3 + iVar4;
  uVar8 = uVar7 & 0xffff;
  if (0x1ff < uVar8) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld.c",0x286e,*(code **)(_r_plf_funcs_p + 8));
  }
  _DAT_600312d4 = _DAT_600312d4 & 0xfffffe00 | uVar8;
  uVar8 = uVar3;
  if (2 < _g_bt_plf_log_level) {
    ets_printf("RX MAX LENGTH %d\n",uVar7);
  }
  for (; iVar4 = _p_lld_env, pcVar6 = *(code **)(_r_plf_funcs_p + 0xbc), uVar8 != uVar3 + 10;
      uVar8 = uVar8 + 1) {
    iVar4 = (*pcVar6)(0x1000);
    iVar9 = ((int)uVar8 % 10) * 0x14;
    uVar2 = *(ushort *)(iVar4 + iVar9 + 2);
    iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar4 + iVar9 + 2) = uVar2 | 0x8000;
    iVar4 = (**(code **)(_r_ip_funcs_p + 0xe8))(*(code **)(_r_ip_funcs_p + 0xe8));
    if ((int)uVar8 < (int)(iVar4 + uVar3)) {
      iVar4 = (**(code **)(_r_ip_funcs_p + 0xfc))(*(code **)(_r_ip_funcs_p + 0xfc));
      if (iVar4 == 0) {
        (**(code **)(_r_plf_funcs_p + 0xc))
                  (uVar8,uVar3,"lld.c",0x75b,*(code **)(_r_plf_funcs_p + 0xc));
      }
      else {
        iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
        *(short *)(iVar9 + 0x12 + iVar5) = (short)iVar4;
        if (uVar8 != uVar3) {
          iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
          uVar2 = *(ushort *)(iVar4 + iVar9);
          iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
          *(ushort *)(iVar4 + iVar9) = uVar2 & 0x7fff;
        }
      }
      *(char *)(_p_lld_env + 0xd9) = (char)uVar8;
    }
    else {
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar9 + 0x12 + iVar4) = 0;
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar2 = *(ushort *)(iVar4 + iVar9);
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar9 + iVar4) = uVar2 | 0x8000;
    }
  }
  *(char *)(_p_lld_env + 0xd8) = (char)uVar3;
  *(undefined1 *)(iVar4 + 0x101) = 0;
  iVar4 = (*pcVar6)(0x1000);
  uVar2 = *(ushort *)(iVar4 + uVar3 * 0x14);
  iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  pcVar6 = *(code **)(_r_osi_funcs_p + 0x18);
  *(ushort *)(uVar3 * 0x14 + iVar4) = (ushort)(((uint)uVar2 << 0x11) >> 0x11);
  (*pcVar6)(pcVar6);
  if (2 < _g_bt_plf_log_level) {
    ets_printf("RXBUF Update OK\n");
  }
  return 0;
}

