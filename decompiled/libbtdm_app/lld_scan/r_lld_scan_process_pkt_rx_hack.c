/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app -> lld_scan.o -> r_lld_scan_process_pkt_rx_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_scan_process_pkt_rx_hack(int param_1)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  ushort uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  code *pcVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined2 uStack_44;
  
  iVar12 = *(int *)(param_1 * 4 + _lld_scan_env);
  bVar1 = *(byte *)(_lld_scan_env + 0xd);
  do {
    uVar6 = (**(code **)(_r_ip_funcs_p + 0x2a4))
                      (*(undefined1 *)(iVar12 + 0x38),*(code **)(_r_ip_funcs_p + 0x2a4));
    if (uVar6 == 0) {
      iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar12 = ((uint)bVar1 * 9 & 0xff) * 0xe;
      if (*(short *)(iVar7 + iVar12) < 0) {
        iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
        uVar3 = *(ushort *)(iVar7 + iVar12);
        iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
        *(ushort *)(iVar12 + iVar7) = (ushort)(((uint)uVar3 << 0x11) >> 0x11);
      }
      return;
    }
    uVar13 = (uint)*(byte *)(_p_lld_env + 0xd8);
    (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
    iVar10 = uVar13 * 0x14;
    iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar3 = *(ushort *)(iVar10 + 2 + iVar7);
    if (*(ushort *)(iVar12 + 0x36) < 0x673) {
      iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar5 = *(ushort *)(iVar7 + iVar10 + 4) & 0xf;
      if (uVar5 < 7) {
        bVar2 = *(byte *)(_lld_scan_env + 0x17);
        uVar11 = uVar6;
        if (bVar2 != 0) {
          (**(code **)(_r_ip_funcs_p + 0x930))(iVar12,*(code **)(_r_ip_funcs_p + 0x930));
          uVar11 = (uint)bVar2;
        }
_L72:
        uVar8 = 0x128U >> uVar5 & 1;
      }
      else {
        iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
        uVar4 = *(ushort *)(iVar10 + 0x10 + iVar7);
        iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
        uVar11 = (uint)((uVar4 & 0x3f) < *(ushort *)(iVar7 + iVar10 + 4) >> 8);
        uVar8 = uVar6;
        if (uVar5 < 9) goto _L72;
      }
      iVar7 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
      if ((*(char *)(iVar7 + 0x18) == '\0') && (6 < uVar5)) {
        uVar8 = uVar6;
      }
      if ((((uVar3 & 0x602d) == 0) && (uVar11 != 0)) && (uVar8 == 0)) {
        uStack_44 = 0xff;
        *(undefined1 *)(iVar12 + 0x43) = 1;
        uStack_4c = 0;
        uStack_48 = 0;
        if ((8 < uVar5) || ((0x128U >> uVar5 & 1) != 0)) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x29c,*(code **)(_r_plf_funcs_p + 8));
        }
        if (uVar5 < 7) {
          pcVar9 = *(code **)(_r_ip_funcs_p + 0x420);
        }
        else {
          pcVar9 = *(code **)(_r_ip_funcs_p + 0x40c);
        }
        (*pcVar9)(param_1,uVar5,uVar13,&uStack_4c,pcVar9);
        (**(code **)(_r_ip_funcs_p + 0x424))
                  (param_1,uVar5,uVar13,&uStack_4c,*(code **)(_r_ip_funcs_p + 0x424));
      }
      else if (((_DAT_60031048 & 8) != 0) &&
              ((**(code **)(_r_ip_funcs_p + 0x428))(param_1,*(code **)(_r_ip_funcs_p + 0x428)),
              *(char *)(_lld_scan_env + 0x17) != '\0')) {
        (**(code **)(_r_ip_funcs_p + 0x930))(iVar12,*(code **)(_r_ip_funcs_p + 0x930));
      }
    }
    (**(code **)(_r_ip_funcs_p + 0x2a8))(*(code **)(_r_ip_funcs_p + 0x2a8));
  } while( true );
}

