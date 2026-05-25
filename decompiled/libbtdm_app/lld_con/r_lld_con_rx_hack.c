/*
 * Last changed at upstream commit 0a08c4b32f3666003080b662a1a61794da24ff0f
 * https://github.com/espressif/esp32c3-bt-lib/commit/0a08c4b32f3666003080b662a1a61794da24ff0f
 * Upstream date: 2026-05-25 14:11:16 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(51d9dfde)
 * Source: libbtdm_app -> lld_con.o -> r_lld_con_rx_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_con_rx_hack(int param_1)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  ushort *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int extraout_a1;
  int iVar9;
  ushort uVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  
  iVar6 = (**(code **)(_r_modules_funcs_p + 0x2c4))(*(code **)(_r_modules_funcs_p + 0x2c4));
  iVar11 = param_1 * 4;
  iVar15 = *(int *)(&lld_con_env + iVar11);
  *(ushort *)(iVar15 + 0x84) = *(ushort *)(iVar15 + 0x84) & 0xfffb;
  puVar5 = (ushort *)(lld_con_fake_rx + iVar11);
  do {
    iVar7 = (**(code **)(_r_ip_funcs_p + 0x2a4))(param_1,*(code **)(_r_ip_funcs_p + 0x2a4));
    if (iVar7 == 0) {
      return;
    }
    bVar1 = *(byte *)(_p_lld_env + 0xd8);
    iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
    iVar13 = (uint)bVar1 * 0x14;
    uVar10 = *(ushort *)(iVar13 + 2 + iVar8);
    iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar2 = *(ushort *)(iVar13 + 4 + iVar8);
    iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar4 = *(ushort *)(iVar13 + 6 + iVar8) >> 0xe;
    if ((uVar4 - 2 & 0xff) < 2) {
      if ((uVar10 & 0x2f) == 0 && uVar2 >> 8 == 0) {
        iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
        uVar3 = *(ushort *)(iVar13 + 10 + iVar8);
        if ((uVar3 & 0xf000) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",1000,*(code **)(_r_plf_funcs_p + 8));
        }
        iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
        iVar14 = CONCAT22(uVar3,*(undefined2 *)(iVar13 + 8 + iVar8));
        iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
        uVar12 = iVar6 - iVar14 & 0xfffffff;
        if (uVar12 < 0x8000001) {
          iVar14 = uVar12 * 0x271;
        }
        else {
          iVar14 = (iVar14 - iVar6 & 0xfffffffU) * -0x271;
        }
        if (uVar4 == 2) {
          iVar9 = 0x2ff;
        }
        else {
          iVar9 = 0xfb;
        }
        if (((int)((extraout_a1 - (0x270 - (*(ushort *)(iVar13 + 0xc + iVar8) & 0x3ff))) + iVar14 +
                  (uint)_DAT_0001604a * 2) <= iVar9) ||
           ((((lld_con_fake_rx[iVar11 + 2] & 0x2e) == 0 && (((*puVar5 ^ uVar2) & 0xff) == 0)) &&
            (*puVar5 >> 8 != 0)))) {
          *(ushort *)(iVar15 + 0x84) = *(ushort *)(iVar15 + 0x84) | 0x8000;
          lld_con_fake_rx[iVar11 + 2] = (char)uVar10;
          *puVar5 = uVar2;
        }
      }
      if (-1 < (short)*(ushort *)(iVar15 + 0x84)) {
        *(ushort *)(iVar15 + 0x84) = *(ushort *)(iVar15 + 0x84) & 0xf7ff;
      }
      if ((uVar10 & 1) != 0) goto _L400;
      if (-1 < *(short *)(iVar15 + 0x84)) {
        lld_con_fake_rx[iVar11 + 2] = (char)uVar10;
        *puVar5 = uVar2;
      }
_L399:
      (**(code **)(_r_ip_funcs_p + 0x39c))(param_1,iVar15,*(code **)(_r_ip_funcs_p + 0x39c));
      if ((uVar10 & 8) != 0) goto _L400;
      *(undefined4 *)(iVar15 + 0x58) = *(undefined4 *)(iVar15 + 0x50);
      iVar8 = _r_plf_funcs_p;
      if ((uVar10 & 0x66) == 0) {
        if ((uVar10 & 0x10) == 0) {
          *(ushort *)(iVar15 + 0x84) = *(ushort *)(iVar15 + 0x84) | 0x4000;
          iVar8 = (**(code **)(iVar8 + 0xbc))(0x400,*(code **)(iVar8 + 0xbc));
          uVar10 = uVar2 >> 8;
          *(undefined2 *)(iVar15 + 0x98) = *(undefined2 *)(iVar8 + param_1 * 0x5a + 0x50);
          if ((uVar10 != 0) && ((uVar2 & 3) != 0)) {
            if ((4 < uVar10) && ((*(ushort *)(iVar15 + 0x84) & 0x20) != 0)) {
              uVar10 = uVar10 - 4;
            }
            iVar8 = (**(code **)(_r_ip_funcs_p + 0x394))
                              (param_1,iVar15,uVar10,*(code **)(_r_ip_funcs_p + 0x394));
            if (iVar8 == 0) {
              iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc))
              ;
              *(undefined2 *)(iVar13 + 0x12 + iVar8) = 0;
            }
          }
        }
        else {
          *(ushort *)(iVar15 + 0x84) = *(ushort *)(iVar15 + 0x84) | 0x80;
          *(undefined1 *)(iVar15 + 0x8f) = 2;
        }
      }
    }
    else {
      if ((uVar10 & 1) == 0) goto _L399;
_L400:
      iVar7 = 0;
    }
    (**(code **)(_r_ip_funcs_p + 0x390))(iVar15,iVar7,*(code **)(_r_ip_funcs_p + 0x390));
    (**(code **)(_r_ip_funcs_p + 0x2a8))(*(code **)(_r_ip_funcs_p + 0x2a8));
  } while( true );
}

