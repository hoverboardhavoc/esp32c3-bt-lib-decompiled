/*
 * Last changed at upstream commit 5c6ab5248a124cffc731a9e4764473fdeef38054
 * https://github.com/espressif/esp32c3-bt-lib/commit/5c6ab5248a124cffc731a9e4764473fdeef38054
 * Upstream date: 2023-03-09 14:58:19 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(85a1090)
 * Source: libbtdm_app -> lld_con.o -> r_lld_con_tx_prog_new_packet
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_con_tx_prog_new_packet(int param_1,int param_2)

{
  char cVar1;
  ushort uVar2;
  ushort uVar3;
  int *piVar4;
  int iVar5;
  undefined1 *puVar6;
  ushort *puVar7;
  char *pcVar8;
  char cVar9;
  int *piVar10;
  code *pcVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  int *piVar15;
  uint uVar16;
  byte bVar17;
  int iVar18;
  byte bVar19;
  uint uVar20;
  int iVar21;
  ushort uVar22;
  
  iVar18 = *(int *)(&lld_con_env + param_1 * 4);
  iVar21 = *(int *)(iVar18 + 0x24);
  piVar4 = *(int **)(iVar18 + 0x30);
  piVar15 = (int *)0x0;
  if ((((*(ushort *)(iVar18 + 0x84) & 0x10) != 0) && (piVar15 = piVar4, piVar4 != (int *)0x0)) &&
     (piVar15 = (int *)0x1, *(short *)(iVar18 + 0x82) == 0)) {
    piVar15 = (int *)(uint)(*piVar4 != 0);
  }
  bVar17 = *(byte *)(iVar18 + 0x92);
  do {
    if (1 < bVar17) {
      return;
    }
    if (iVar21 == 0) {
      if (piVar15 == (int *)0x0) {
        return;
      }
_L140:
      if ((*(short *)(iVar18 + 0x82) == 0) && (piVar15 = (int *)*piVar4, piVar15 != (int *)0x0)) {
        uVar2 = *(ushort *)((int)piVar15 + 6);
        *(int **)(iVar18 + 0x30) = piVar15;
        *(ushort *)(iVar18 + 0x82) = uVar2 & 0x3ff;
        piVar4 = piVar15;
      }
      uVar2 = *(ushort *)((int)piVar4 + 6);
      uVar3 = *(ushort *)(iVar18 + 0x82);
      uVar20 = (uint)uVar3;
      uVar16 = (*(ushort *)(piVar4 + 1) - uVar20) + (uVar2 & 0x3ff) & 0xffff;
      uVar22 = 2;
      if (((int)(uint)uVar2 >> 0xc & 3U) == 1) {
        uVar22 = 1;
      }
      uVar12 = (uint)*(byte *)(iVar18 + 0x8c);
      if (uVar20 < *(byte *)(iVar18 + 0x8c)) {
        uVar12 = uVar20;
      }
      *(ushort *)((int)piVar4 + 6) = uVar2 & 0xcfff | 0x1000;
      *(ushort *)(iVar18 + 0x82) = uVar3 - (short)uVar12;
    }
    else {
      if (((param_2 == 2) && (piVar15 != (int *)0x0)) && ((bVar17 != 1 && (DAT_0001104e != '\0'))))
      goto _L140;
      uVar12 = (uint)*(byte *)(iVar21 + 6);
      uVar16 = (uint)*(ushort *)(iVar21 + 4);
      uVar22 = 3;
      *(undefined4 *)(iVar18 + 0x24) = 0;
      iVar21 = 0;
    }
    cVar9 = *(char *)(iVar18 + 0x8e) * '\t';
    uVar2 = *(ushort *)(iVar18 + 0x84);
    cVar1 = *(char *)(iVar18 + 0x91);
    bVar19 = cVar9 + cVar1;
    piVar15 = (int *)0x0;
    if ((((uVar2 & 0x10) != 0) && (piVar15 = piVar4, piVar4 != (int *)0x0)) &&
       (piVar15 = (int *)0x1, *(short *)(iVar18 + 0x82) == 0)) {
      piVar15 = (int *)(uint)(*piVar4 != 0);
    }
    if ((uVar2 & 0x40) != 0) {
      uVar12 = uVar12 + 4 & 0xffff;
    }
    if ((int)((uint)uVar2 << 0x12) < 0) {
      piVar10 = (int *)0x0;
    }
    else {
      piVar10 = piVar15;
      if (piVar15 == (int *)0x0) {
        piVar10 = (int *)(uVar2 & 1);
      }
    }
    iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    iVar13 = (uint)bVar19 * 0xe;
    *(ushort *)(iVar5 + iVar13 + 2) =
         (ushort)((uVar12 & 0xff) << 8) | uVar22 | (ushort)((int)piVar10 << 4);
    iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(short *)(iVar5 + iVar13 + 4) = (short)uVar16;
    if (-1 < (int)((uint)*(ushort *)(iVar18 + 0x84) << 0x12)) {
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar14 = (uint)(byte)((cVar1 + 1U & 1) + cVar9) * 0xe;
      if (-1 < *(short *)(iVar5 + iVar14)) {
        iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
        iVar14 = iVar14 + 2;
        uVar2 = *(ushort *)(iVar5 + iVar14);
        iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
        *(ushort *)(iVar5 + iVar14) = uVar2 & 0xffef | 0x10;
      }
    }
    if (uVar22 == 3) {
      iVar5 = (**(code **)(_r_ip_funcs_p + 0x91c))(*(code **)(_r_ip_funcs_p + 0x91c));
      if (param_2 == 2) {
        puVar6 = (undefined1 *)(iVar5 + param_1 * 4);
        *puVar6 = 1;
        puVar6[1] = bVar19;
        if ((uint)bVar19 == (uint)*(byte *)(iVar18 + 0x90) + param_1 * 9) {
          puVar6[2] = 1;
        }
      }
      else if (param_2 == 1) {
        iVar5 = iVar5 + param_1 * 2;
        pcVar11 = *(code **)(_r_plf_funcs_p + 0xbc);
        *(byte *)(iVar5 + 0x3c) = bVar19;
        uVar20 = uVar16 + 6 & 0xffff;
        *(undefined1 *)(iVar5 + 0x3d) = 2;
        puVar7 = (ushort *)(*pcVar11)(uVar20,pcVar11);
        uVar2 = *(ushort *)(iVar18 + 0x44);
        if (((uint)uVar2 == (uint)*puVar7) &&
           (pcVar8 = (char *)(**(code **)(_r_plf_funcs_p + 0xbc))
                                       (uVar16,*(code **)(_r_plf_funcs_p + 0xbc)), *pcVar8 == '\x01'
           )) {
          uVar16 = (uint)*(ushort *)(iVar18 + 0x7c) + (uint)*(ushort *)(iVar18 + 0x7e) +
                   (*(ushort *)(iVar18 + 0x72) + 1) * 9;
          iVar5 = uVar16 * 0x10000;
          uVar16 = uVar16 & 0xffff;
          if (((uVar16 + 1) - (uint)uVar2 & 0xffff) < 0x7fff) {
            puVar6 = (undefined1 *)
                     (**(code **)(_r_plf_funcs_p + 0xbc))(uVar20,*(code **)(_r_plf_funcs_p + 0xbc));
            *puVar6 = (char)((uint)iVar5 >> 0x10);
            puVar6[1] = (char)(uVar16 >> 8);
            *(short *)(iVar18 + 0x44) = (short)((uint)iVar5 >> 0x10);
          }
        }
        else {
          (**(code **)(_r_plf_funcs_p + 0xc))
                    (0,0,"lld_con.c",0x4eb,*(code **)(_r_plf_funcs_p + 0xc));
        }
      }
    }
    bVar17 = bVar17 + 1;
    iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar2 = *(ushort *)(iVar5 + iVar13);
    iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar5 + iVar13) = uVar2 & 0x7fff;
    *(byte *)(iVar18 + 0x91) = *(char *)(iVar18 + 0x91) + 1U & 1;
    (**(code **)(_r_ip_funcs_p + 0x78c))(iVar18,*(code **)(_r_ip_funcs_p + 0x78c));
    *(char *)(iVar18 + 0x92) = *(char *)(iVar18 + 0x92) + '\x01';
  } while( true );
}

