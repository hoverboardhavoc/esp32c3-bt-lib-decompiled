/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  code *pcVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined2 uStack_44;
  
  iVar10 = *(int *)(param_1 * 4 + _lld_scan_env);
  bVar1 = *(byte *)(_lld_scan_env + 0xd);
  do {
    uVar5 = (**(code **)(_r_ip_funcs_p + 0x2a4))
                      (*(undefined1 *)(iVar10 + 0x38),*(code **)(_r_ip_funcs_p + 0x2a4));
    if (uVar5 == 0) {
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400);
      iVar10 = ((uint)bVar1 * 9 & 0xff) * 0xe;
      if (*(short *)(iVar6 + iVar10) < 0) {
        iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
        uVar2 = *(ushort *)(iVar6 + iVar10);
        iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
        *(ushort *)(iVar10 + iVar6) = (ushort)(((uint)uVar2 << 0x11) >> 0x11);
      }
      return;
    }
    uVar11 = (uint)*(byte *)(_p_lld_env + 0xd8);
    (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000);
    iVar6 = uVar11 * 0x14;
    if (*(ushort *)(iVar10 + 0x36) < 0x673) {
      iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar2 = *(ushort *)(iVar6 + 2 + iVar7);
      iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar4 = *(ushort *)(iVar7 + iVar6 + 4) & 0xf;
      if (uVar4 < 7) {
        uVar9 = uVar5;
        if (*(char *)(_lld_scan_env + 0x17) != '\0') {
          (**(code **)(_r_ip_funcs_p + 0x930))(iVar10,*(code **)(_r_ip_funcs_p + 0x930));
        }
_L70:
        uVar5 = 0x128U >> uVar4 & 1;
      }
      else {
        iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
        uVar3 = *(ushort *)(iVar6 + 0x10 + iVar7);
        iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
        uVar9 = (uint)((uVar3 & 0x3f) < *(ushort *)(iVar6 + 4 + iVar7) >> 8);
        if (uVar4 < 9) goto _L70;
      }
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
      if (*(char *)(iVar6 + 0x18) == '\0') {
        uVar5 = (uint)(6 < uVar4) | uVar5 & 0xff;
      }
      if ((((uVar2 & 0x602d) == 0) && (uVar9 != 0)) && (uVar5 == 0)) {
        uStack_44 = 0xff;
        *(undefined1 *)(iVar10 + 0x43) = 1;
        uStack_4c = 0;
        uStack_48 = 0;
        if ((8 < uVar4) || ((0x128U >> uVar4 & 1) != 0)) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x272,*(code **)(_r_plf_funcs_p + 8));
        }
        if (uVar4 < 7) {
          pcVar8 = *(code **)(_r_ip_funcs_p + 0x420);
        }
        else {
          pcVar8 = *(code **)(_r_ip_funcs_p + 0x40c);
        }
        (*pcVar8)(param_1,uVar4,uVar11,&uStack_4c,pcVar8);
        (**(code **)(_r_ip_funcs_p + 0x424))
                  (param_1,uVar4,uVar11,&uStack_4c,*(code **)(_r_ip_funcs_p + 0x424));
      }
      else if (((_DAT_60031048 & 8) != 0) &&
              ((**(code **)(_r_ip_funcs_p + 0x428))(param_1,*(code **)(_r_ip_funcs_p + 0x428)),
              *(char *)(_lld_scan_env + 0x17) != '\0')) {
        (**(code **)(_r_ip_funcs_p + 0x930))(iVar10,*(code **)(_r_ip_funcs_p + 0x930));
      }
    }
    (**(code **)(_r_ip_funcs_p + 0x2a8))(*(code **)(_r_ip_funcs_p + 0x2a8));
  } while( true );
}

