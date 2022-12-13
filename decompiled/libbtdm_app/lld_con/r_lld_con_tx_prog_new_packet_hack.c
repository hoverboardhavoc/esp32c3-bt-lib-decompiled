/*
 * Last changed at upstream commit 84ebcda82aa5886d2a0b939dec1dbc62aa1c11c7
 * https://github.com/espressif/esp32c3-bt-lib/commit/84ebcda82aa5886d2a0b939dec1dbc62aa1c11c7
 * Upstream date: 2022-12-13 21:37:30 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3 (edd93b0)
 * Source: libbtdm_app -> lld_con.o -> r_lld_con_tx_prog_new_packet_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_con_tx_prog_new_packet_hack(int param_1,int param_2)

{
  char cVar1;
  byte bVar2;
  ushort uVar3;
  ushort uVar4;
  int *piVar5;
  int iVar6;
  ushort *puVar7;
  char *pcVar8;
  undefined1 *puVar9;
  code *pcVar10;
  int iVar11;
  int *piVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  byte bVar16;
  int iVar17;
  byte bVar18;
  uint uVar19;
  char cVar20;
  int iVar21;
  int iVar22;
  ushort uVar23;
  int *piStack_58;
  
  iVar11 = param_1 * 4;
  iVar17 = *(int *)(&lld_con_env + iVar11);
  iVar22 = *(int *)(iVar17 + 0x24);
  piVar5 = *(int **)(iVar17 + 0x30);
  piStack_58 = (int *)0x0;
  if ((((*(ushort *)(iVar17 + 0x84) & 0x10) != 0) && (piStack_58 = piVar5, piVar5 != (int *)0x0)) &&
     (piStack_58 = (int *)0x1, *(short *)(iVar17 + 0x82) == 0)) {
    piStack_58 = (int *)(uint)(*piVar5 != 0);
  }
  bVar16 = *(byte *)(iVar17 + 0x92);
  do {
    if (1 < bVar16) {
      return;
    }
    if (iVar22 == 0) {
      if (piStack_58 == (int *)0x0) {
        return;
      }
_L80:
      if ((*(short *)(iVar17 + 0x82) == 0) && (piVar12 = (int *)*piVar5, piVar12 != (int *)0x0)) {
        uVar3 = *(ushort *)((int)piVar12 + 6);
        *(int **)(iVar17 + 0x30) = piVar12;
        *(ushort *)(iVar17 + 0x82) = uVar3 & 0x3ff;
        piVar5 = piVar12;
      }
      uVar3 = *(ushort *)((int)piVar5 + 6);
      uVar4 = *(ushort *)(iVar17 + 0x82);
      uVar19 = (uint)uVar4;
      uVar14 = (*(ushort *)(piVar5 + 1) - uVar19) + (uVar3 & 0x3ff) & 0xffff;
      uVar23 = 2;
      if (((int)(uint)uVar3 >> 0xc & 3U) == 1) {
        uVar23 = 1;
      }
      uVar13 = (uint)*(byte *)(iVar17 + 0x8c);
      if (uVar19 < *(byte *)(iVar17 + 0x8c)) {
        uVar13 = uVar19;
      }
      *(ushort *)((int)piVar5 + 6) = uVar3 & 0xcfff | 0x1000;
      *(ushort *)(iVar17 + 0x82) = uVar4 - (short)uVar13;
    }
    else {
      if (((param_2 == 2) && (piStack_58 != (int *)0x0)) &&
         ((bVar16 != 1 && (DAT_00011046 != '\0')))) goto _L80;
      uVar13 = (uint)*(byte *)(iVar22 + 6);
      uVar14 = (uint)*(ushort *)(iVar22 + 4);
      uVar23 = 3;
      *(undefined4 *)(iVar17 + 0x24) = 0;
      iVar22 = 0;
    }
    uVar3 = *(ushort *)(iVar17 + 0x84);
    cVar20 = *(char *)(iVar17 + 0x8e) * '\t';
    cVar1 = *(char *)(iVar17 + 0x91);
    bVar18 = cVar20 + cVar1;
    piStack_58 = (int *)0x0;
    if ((((uVar3 & 0x10) != 0) && (piStack_58 = piVar5, piVar5 != (int *)0x0)) &&
       (piStack_58 = (int *)0x1, *(short *)(iVar17 + 0x82) == 0)) {
      piStack_58 = (int *)(uint)(*piVar5 != 0);
    }
    if ((uVar3 & 0x40) != 0) {
      uVar13 = uVar13 + 4 & 0xffff;
    }
    if ((int)((uint)uVar3 << 0x12) < 0) {
      piVar12 = (int *)0x0;
    }
    else {
      piVar12 = piStack_58;
      if (piStack_58 == (int *)0x0) {
        piVar12 = (int *)(uVar3 & 1);
      }
    }
    iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    iVar15 = (uint)bVar18 * 0xe;
    *(ushort *)(iVar6 + iVar15 + 2) =
         (ushort)((uVar13 & 0xff) << 8) | uVar23 | (ushort)((int)piVar12 << 4);
    iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(short *)(iVar6 + iVar15 + 4) = (short)uVar14;
    if (-1 < (int)((uint)*(ushort *)(iVar17 + 0x84) << 0x12)) {
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar21 = (uint)(byte)((cVar1 + 1U & 1) + cVar20) * 0xe;
      if (-1 < *(short *)(iVar6 + iVar21)) {
        iVar21 = iVar21 + 2;
        iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
        uVar3 = *(ushort *)(iVar6 + iVar21);
        iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
        *(ushort *)(iVar6 + iVar21) = uVar3 & 0xffef | 0x10;
      }
    }
    iVar6 = _r_plf_funcs_p;
    if (uVar23 == 3) {
      if (param_2 == 2) {
        bVar2 = *(byte *)(iVar17 + 0x90);
        lld_con_term_info[iVar11] = 1;
        lld_con_term_info[iVar11 + 1] = bVar18;
        if ((uint)bVar18 == (uint)bVar2 + param_1 * 9) {
          lld_con_term_info[iVar11 + 2] = 1;
        }
      }
      else if (param_2 == 1) {
        llcp_ind_info[param_1 * 2] = bVar18;
        pcVar10 = *(code **)(iVar6 + 0xbc);
        uVar19 = uVar14 + 6 & 0xffff;
        llcp_ind_info[param_1 * 2 + 1] = 2;
        puVar7 = (ushort *)(*pcVar10)(uVar19,pcVar10);
        uVar3 = *(ushort *)(iVar17 + 0x44);
        if (((uint)uVar3 == (uint)*puVar7) &&
           (pcVar8 = (char *)(**(code **)(_r_plf_funcs_p + 0xbc))
                                       (uVar14,*(code **)(_r_plf_funcs_p + 0xbc)), *pcVar8 == '\x01'
           )) {
          uVar14 = (uint)*(ushort *)(iVar17 + 0x7c) + (uint)*(ushort *)(iVar17 + 0x7e) +
                   (*(ushort *)(iVar17 + 0x72) + 1) * 9;
          iVar6 = uVar14 * 0x10000;
          uVar14 = uVar14 & 0xffff;
          if (((uVar14 + 1) - (uint)uVar3 & 0xffff) < 0x7fff) {
            puVar9 = (undefined1 *)
                     (**(code **)(_r_plf_funcs_p + 0xbc))(uVar19,*(code **)(_r_plf_funcs_p + 0xbc));
            *puVar9 = (char)((uint)iVar6 >> 0x10);
            puVar9[1] = (char)(uVar14 >> 8);
            *(short *)(iVar17 + 0x44) = (short)((uint)iVar6 >> 0x10);
          }
        }
        else {
          (**(code **)(_r_plf_funcs_p + 0xc))
                    (0,0,"lld_con.c",0x4ae,*(code **)(_r_plf_funcs_p + 0xc));
        }
      }
    }
    bVar16 = bVar16 + 1;
    iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar3 = *(ushort *)(iVar6 + iVar15);
    iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar6 + iVar15) = uVar3 & 0x7fff;
    *(byte *)(iVar17 + 0x91) = *(char *)(iVar17 + 0x91) + 1U & 1;
    (**(code **)(_r_ip_funcs_p + 0x78c))(iVar17,*(code **)(_r_ip_funcs_p + 0x78c));
    *(char *)(iVar17 + 0x92) = *(char *)(iVar17 + 0x92) + '\x01';
  } while( true );
}

