/*
 * Last changed at upstream commit aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * https://github.com/espressif/esp32c3-bt-lib/commit/aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * Upstream date: 2025-03-20 20:31:24 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(d74042a8)
 * Source: libbtdm_app -> lld_scan.o -> r_lld_scan_process_pkt_rx
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_scan_process_pkt_rx(int param_1)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  code *pcVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined2 uStack_44;
  
  bVar1 = *(byte *)(_lld_scan_env + 0xd);
  iVar12 = *(int *)(param_1 * 4 + _lld_scan_env);
  do {
    uVar6 = (**(code **)(_r_ip_funcs_p + 0x2a4))
                      (*(undefined1 *)(iVar12 + 0x38),*(code **)(_r_ip_funcs_p + 0x2a4));
    if (uVar6 == 0) {
      iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar12 = ((uint)bVar1 * 9 & 0xff) * 0xe;
      if (*(short *)(iVar7 + iVar12) < 0) {
        iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
        uVar2 = *(ushort *)(iVar7 + iVar12);
        iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
        *(ushort *)(iVar7 + iVar12) = uVar2 & 0x7fff;
      }
      return;
    }
    uVar13 = (uint)*(byte *)(_p_lld_env + 0xd8);
    (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
    iVar7 = uVar13 * 0x14;
    if (*(ushort *)(iVar12 + 0x36) < 0x673) {
      iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar2 = *(ushort *)(iVar8 + iVar7 + 2);
      iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar3 = *(ushort *)(iVar8 + iVar7 + 4);
      uVar5 = uVar3 & 0xf;
      uVar9 = uVar6;
      if (uVar5 < 7) {
        if (*(char *)(_lld_scan_env + 0x17) != '\0') {
          (**(code **)(_r_ip_funcs_p + 0x930))(iVar12,*(code **)(_r_ip_funcs_p + 0x930));
        }
        uVar11 = uVar6;
        if ((uVar5 - 3 & 0xfd) != 0) goto _L65;
      }
      else {
        iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
        uVar4 = *(ushort *)(iVar7 + 0x10 + iVar8);
        iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
        uVar11 = (uint)((uVar4 & 0x3f) < *(ushort *)(iVar8 + iVar7 + 4) >> 8);
        if (uVar5 < 9) {
_L65:
          uVar9 = (uint)(uVar5 == 8);
        }
      }
      iVar7 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
      if ((*(char *)(iVar7 + 0x18) == '\0') && (6 < uVar5)) {
        uVar9 = uVar6;
      }
      if ((((uVar2 & 0x602d) == 0) && (uVar11 != 0)) && (uVar9 == 0)) {
        uStack_44 = 0xff;
        uStack_4c = 0;
        uStack_48 = 0;
        *(undefined1 *)(iVar12 + 0x43) = 1;
        if (((uVar3 & 8) != 0) || ((uVar5 - 3 & 0xfd) == 0)) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x25f,*(code **)(_r_plf_funcs_p + 8));
        }
        if (uVar5 < 7) {
          pcVar10 = *(code **)(_r_ip_funcs_p + 0x420);
        }
        else {
          pcVar10 = *(code **)(_r_ip_funcs_p + 0x40c);
        }
        (*pcVar10)(param_1,uVar5,uVar13,&uStack_4c,pcVar10);
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

