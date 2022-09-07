/*
 * Last changed at upstream commit 2a91d90e33b3b1104daf1bff898fe5bc3f814811
 * https://github.com/espressif/esp32c3-bt-lib/commit/2a91d90e33b3b1104daf1bff898fe5bc3f814811
 * Upstream date: 2022-09-07 12:18:28 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(2ee0168e)
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
  char cVar5;
  int *piVar6;
  int iVar7;
  short sVar8;
  int iVar9;
  int *piVar10;
  uint uVar11;
  int iVar12;
  byte bVar13;
  int *piVar14;
  byte bVar15;
  int iVar16;
  ushort uVar17;
  int iVar18;
  int local_60;
  
  iVar9 = param_1 * 4;
  iVar16 = *(int *)(&lld_con_env + iVar9);
  local_60 = *(int *)(iVar16 + 0x24);
  piVar14 = *(int **)(iVar16 + 0x30);
  piVar6 = (int *)0x0;
  if ((((*(ushort *)(iVar16 + 0x84) & 0x10) != 0) && (piVar6 = piVar14, piVar14 != (int *)0x0)) &&
     (piVar6 = (int *)0x1, *(short *)(iVar16 + 0x82) == 0)) {
    piVar6 = (int *)(uint)(*piVar14 != 0);
  }
  bVar13 = *(byte *)(iVar16 + 0x92);
  do {
    iVar7 = local_60;
    if (1 < bVar13) {
      return;
    }
    if (local_60 == 0) {
      if (piVar6 == (int *)0x0) {
        return;
      }
_L79:
      if ((*(short *)(iVar16 + 0x82) == 0) && (piVar6 = (int *)*piVar14, piVar6 != (int *)0x0)) {
        uVar3 = *(ushort *)((int)piVar6 + 6);
        *(int **)(iVar16 + 0x30) = piVar6;
        *(ushort *)(iVar16 + 0x82) = uVar3 & 0x3ff;
        piVar14 = piVar6;
      }
      uVar3 = *(ushort *)((int)piVar14 + 6);
      uVar4 = *(ushort *)(iVar16 + 0x82);
      sVar8 = ((short)piVar14[1] - uVar4) + (uVar3 & 0x3ff);
      uVar17 = 2;
      if (((int)(uint)uVar3 >> 0xc & 3U) == 1) {
        uVar17 = 1;
      }
      uVar11 = (uint)*(byte *)(iVar16 + 0x8c);
      if ((uint)uVar4 < (uint)*(byte *)(iVar16 + 0x8c)) {
        uVar11 = (uint)uVar4;
      }
      *(ushort *)((int)piVar14 + 6) = uVar3 & 0xcfff | 0x1000;
      *(ushort *)(iVar16 + 0x82) = uVar4 - (short)uVar11;
    }
    else {
      if (((param_2 == 2) && (piVar6 != (int *)0x0)) && ((bVar13 != 1 && (DAT_00011046 != '\0'))))
      goto _L79;
      uVar17 = 3;
      local_60 = 0;
      uVar11 = (uint)*(byte *)(iVar7 + 6);
      sVar8 = *(short *)(iVar7 + 4);
      *(undefined4 *)(iVar16 + 0x24) = 0;
    }
    cVar1 = *(char *)(iVar16 + 0x91);
    cVar5 = *(char *)(iVar16 + 0x8e) * '\t';
    uVar3 = *(ushort *)(iVar16 + 0x84);
    bVar15 = cVar5 + cVar1;
    piVar6 = (int *)0x0;
    if ((((uVar3 & 0x10) != 0) && (piVar6 = piVar14, piVar14 != (int *)0x0)) &&
       (piVar6 = (int *)0x1, *(short *)(iVar16 + 0x82) == 0)) {
      piVar6 = (int *)(uint)(*piVar14 != 0);
    }
    if ((uVar3 & 0x40) != 0) {
      uVar11 = uVar11 + 4 & 0xffff;
    }
    if ((int)((uint)uVar3 << 0x12) < 0) {
      piVar10 = (int *)0x0;
    }
    else {
      piVar10 = piVar6;
      if (piVar6 == (int *)0x0) {
        piVar10 = (int *)(uVar3 & 1);
      }
    }
    iVar12 = (uint)bVar15 * 0xe;
    iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar7 + iVar12 + 2) =
         (ushort)((uVar11 & 0xff) << 8) | uVar17 | (ushort)((int)piVar10 << 4);
    iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(short *)(iVar7 + iVar12 + 4) = sVar8;
    if (-1 < (int)((uint)*(ushort *)(iVar16 + 0x84) << 0x12)) {
      iVar18 = (uint)(byte)(cVar5 + (cVar1 + 1U & 1)) * 0xe;
      iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      if (-1 < *(short *)(iVar7 + iVar18)) {
        iVar18 = iVar18 + 2;
        iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
        uVar3 = *(ushort *)(iVar7 + iVar18);
        iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
        *(ushort *)(iVar18 + iVar7) = uVar3 & 0xffef | 0x10;
      }
    }
    iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar3 = *(ushort *)(iVar7 + iVar12);
    iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar7 + iVar12) = uVar3 & 0x7fff;
    if ((param_2 == 2) && (uVar17 == 3)) {
      bVar2 = *(byte *)(iVar16 + 0x90);
      lld_con_term_info[iVar9] = 1;
      lld_con_term_info[iVar9 + 1] = bVar15;
      if ((uint)bVar15 == (uint)bVar2 + param_1 * 9) {
        lld_con_term_info[iVar9 + 2] = 1;
      }
    }
    bVar13 = bVar13 + 1;
    *(byte *)(iVar16 + 0x91) = *(char *)(iVar16 + 0x91) + 1U & 1;
    (**(code **)(_r_ip_funcs_p + 0x78c))(iVar16,*(code **)(_r_ip_funcs_p + 0x78c));
    *(char *)(iVar16 + 0x92) = *(char *)(iVar16 + 0x92) + '\x01';
  } while( true );
}

