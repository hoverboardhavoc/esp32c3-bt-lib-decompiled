/*
 * Last changed at upstream commit e668c2d101ee46ee1950819607694fb852aecae0
 * https://github.com/espressif/esp32c3-bt-lib/commit/e668c2d101ee46ee1950819607694fb852aecae0
 * Upstream date: 2025-03-14 11:07:43 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(6e312587)
 * Source: libbtdm_app -> lld.o -> lld_update_rxbuf_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

undefined4 lld_update_rxbuf_handler(void)

{
  ushort uVar1;
  short sVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  code *pcVar8;
  uint uVar9;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  uVar3 = ((_DAT_600312d0 & 0x7fff) - 0x1000) / 0x14;
  for (uVar4 = uVar3; uVar4 != uVar3 + 10; uVar4 = uVar4 + 1) {
    iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
    iVar5 = ((int)uVar4 % 10) * 0x14;
    sVar2 = *(short *)(iVar6 + iVar5 + 0x12);
    iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
    if ((-1 < *(short *)(iVar6 + iVar5)) && (sVar2 != 0)) {
      (**(code **)(_r_ip_funcs_p + 0x104))(sVar2,0,*(code **)(_r_ip_funcs_p + 0x104));
    }
  }
  while (iVar5 = (**(code **)(_r_ip_funcs_p + 0xfc))(*(code **)(_r_ip_funcs_p + 0xfc)), iVar5 != 0)
  {
    (**(code **)(_r_ip_funcs_p + 0x104))(0,*(code **)(_r_ip_funcs_p + 0x104));
  }
  (**(code **)(_r_ip_funcs_p + 0x114))(*(code **)(_r_ip_funcs_p + 0x114));
  iVar5 = 3;
  iVar6 = (**(code **)(_r_ip_funcs_p + 0xec))(*(code **)(_r_ip_funcs_p + 0xec));
  if (sdk_cfg_priv_opts == '\0') {
    iVar5 = 0;
  }
  uVar4 = iVar5 + iVar6;
  if ((uVar4 & 0xfe00) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld.c",0x286e,*(code **)(_r_plf_funcs_p + 8));
  }
  _DAT_600312d4 = _DAT_600312d4 & 0xfffffe00 | uVar4 & 0xffff;
  uVar9 = uVar3;
  if (2 < _g_bt_plf_log_level) {
    ets_printf("RX MAX LENGTH %d\n",uVar4);
  }
  for (; iVar5 = _p_lld_env, pcVar8 = *(code **)(_r_plf_funcs_p + 0xbc), uVar9 != uVar3 + 10;
      uVar9 = uVar9 + 1) {
    iVar6 = (*pcVar8)(0x1000);
    iVar5 = ((int)uVar9 % 10) * 0x14;
    uVar1 = *(ushort *)(iVar6 + iVar5 + 2);
    iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar6 + iVar5 + 2) = uVar1 & 0x7fff | 0x8000;
    iVar6 = (**(code **)(_r_ip_funcs_p + 0xe8))(*(code **)(_r_ip_funcs_p + 0xe8));
    if ((int)uVar9 < (int)(iVar6 + uVar3)) {
      iVar6 = (**(code **)(_r_ip_funcs_p + 0xfc))(*(code **)(_r_ip_funcs_p + 0xfc));
      if (iVar6 == 0) {
        (**(code **)(_r_plf_funcs_p + 0xc))
                  (uVar9,uVar3,"lld.c",0x74c,*(code **)(_r_plf_funcs_p + 0xc));
      }
      else {
        iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
        *(short *)(iVar7 + iVar5 + 0x12) = (short)iVar6;
        if (uVar9 != uVar3) {
          iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
          uVar1 = *(ushort *)(iVar6 + iVar5);
          iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
          *(ushort *)(iVar6 + iVar5) = uVar1 & 0x7fff;
        }
      }
      *(char *)(_p_lld_env + 0xd9) = (char)uVar9;
    }
    else {
      iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar6 = _r_plf_funcs_p;
      *(undefined2 *)(iVar7 + iVar5 + 0x12) = 0;
      iVar6 = (**(code **)(iVar6 + 0xbc))(0x1000,*(code **)(iVar6 + 0xbc));
      uVar1 = *(ushort *)(iVar6 + iVar5);
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar6 + iVar5) = uVar1 & 0x7fff | 0x8000;
    }
  }
  *(char *)(_p_lld_env + 0xd8) = (char)uVar3;
  *(undefined1 *)(iVar5 + 0x101) = 0;
  iVar5 = (*pcVar8)(0x1000);
  uVar1 = *(ushort *)(iVar5 + uVar3 * 0x14);
  iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  *(ushort *)(uVar3 * 0x14 + iVar5) = uVar1 & 0x7fff;
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  if (2 < _g_bt_plf_log_level) {
    ets_printf("RXBUF Update OK\n");
  }
  return 0;
}

