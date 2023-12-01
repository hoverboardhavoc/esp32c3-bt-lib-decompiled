/*
 * Last changed at upstream commit f103dfec019fdd5bf9255abcaeaf20c707b26dc6
 * https://github.com/espressif/esp32c3-bt-lib/commit/f103dfec019fdd5bf9255abcaeaf20c707b26dc6
 * Upstream date: 2023-12-01 21:11:21 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(b8f0db9)
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
  int iVar9;
  char cVar10;
  int *piVar11;
  code *pcVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  byte bVar16;
  int iVar17;
  byte bVar18;
  uint uVar19;
  int iVar20;
  ushort uVar21;
  int *piStack_60;
  
  iVar17 = *(int *)(&lld_con_env + param_1 * 4);
  iVar20 = *(int *)(iVar17 + 0x24);
  piVar4 = *(int **)(iVar17 + 0x30);
  piStack_60 = (int *)0x0;
  if ((((*(ushort *)(iVar17 + 0x84) & 0x10) != 0) && (piStack_60 = piVar4, piVar4 != (int *)0x0)) &&
     (piStack_60 = (int *)0x1, *(short *)(iVar17 + 0x82) == 0)) {
    piStack_60 = (int *)(uint)(*piVar4 != 0);
  }
  bVar16 = *(byte *)(iVar17 + 0x92);
  do {
    if (1 < bVar16) {
      return;
    }
    if (iVar20 == 0) {
      if (piStack_60 == (int *)0x0) {
        return;
      }
_L141:
      if ((*(short *)(iVar17 + 0x82) == 0) && (piVar11 = (int *)*piVar4, piVar11 != (int *)0x0)) {
        uVar2 = *(ushort *)((int)piVar11 + 6);
        *(int **)(iVar17 + 0x30) = piVar11;
        *(ushort *)(iVar17 + 0x82) = uVar2 & 0x3ff;
        piVar4 = piVar11;
      }
      uVar2 = *(ushort *)((int)piVar4 + 6);
      uVar3 = *(ushort *)(iVar17 + 0x82);
      uVar19 = (uint)uVar3;
      uVar15 = (*(ushort *)(piVar4 + 1) - uVar19) + (uVar2 & 0x3ff) & 0xffff;
      uVar21 = 2;
      if (((int)(uint)uVar2 >> 0xc & 3U) == 1) {
        uVar21 = 1;
      }
      uVar13 = (uint)*(byte *)(iVar17 + 0x8c);
      if (uVar19 < *(byte *)(iVar17 + 0x8c)) {
        uVar13 = uVar19;
      }
      *(ushort *)((int)piVar4 + 6) = uVar2 & 0xcfff | 0x1000;
      *(ushort *)(iVar17 + 0x82) = uVar3 - (short)uVar13;
    }
    else {
      if (((param_2 == 2) && (piStack_60 != (int *)0x0)) &&
         ((bVar16 != 1 && (DAT_0001204e != '\0')))) goto _L141;
      uVar13 = (uint)*(byte *)(iVar20 + 6);
      uVar15 = (uint)*(ushort *)(iVar20 + 4);
      uVar21 = 3;
      *(undefined4 *)(iVar17 + 0x24) = 0;
      iVar20 = 0;
    }
    cVar10 = *(char *)(iVar17 + 0x8e) * '\t';
    cVar1 = *(char *)(iVar17 + 0x91);
    bVar18 = cVar10 + cVar1;
    uVar2 = *(ushort *)(iVar17 + 0x84);
    piStack_60 = (int *)0x0;
    if ((((uVar2 & 0x10) != 0) && (piStack_60 = piVar4, piVar4 != (int *)0x0)) &&
       (piStack_60 = (int *)0x1, *(short *)(iVar17 + 0x82) == 0)) {
      piStack_60 = (int *)(uint)(*piVar4 != 0);
    }
    if ((uVar2 & 0x40) != 0) {
      uVar13 = uVar13 + 4 & 0xffff;
    }
    if ((int)((uint)uVar2 << 0x12) < 0) {
      piVar11 = (int *)0x0;
    }
    else {
      piVar11 = piStack_60;
      if (piStack_60 == (int *)0x0) {
        piVar11 = (int *)(uVar2 & 1);
      }
    }
    iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    iVar9 = (uint)bVar18 * 0xe;
    *(ushort *)(iVar5 + iVar9 + 2) =
         (ushort)((uVar13 & 0xff) << 8) | uVar21 | (ushort)((int)piVar11 << 4);
    iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(short *)(iVar5 + iVar9 + 4) = (short)uVar15;
    if (-1 < (int)((uint)*(ushort *)(iVar17 + 0x84) << 0x12)) {
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar14 = (uint)(byte)((cVar1 + 1U & 1) + cVar10) * 0xe;
      if (-1 < *(short *)(iVar5 + iVar14)) {
        iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
        iVar14 = iVar14 + 2;
        uVar2 = *(ushort *)(iVar5 + iVar14);
        iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
        *(ushort *)(iVar5 + iVar14) = uVar2 & 0xffef | 0x10;
      }
    }
    if (uVar21 == 3) {
      iVar5 = (**(code **)(_r_ip_funcs_p + 0x91c))(*(code **)(_r_ip_funcs_p + 0x91c));
      if (param_2 == 2) {
        puVar6 = (undefined1 *)(iVar5 + param_1 * 4);
        *puVar6 = 1;
        puVar6[1] = bVar18;
        if ((uint)bVar18 == (uint)*(byte *)(iVar17 + 0x90) + param_1 * 9) {
          puVar6[2] = 1;
        }
      }
      else if (param_2 == 1) {
        iVar5 = iVar5 + param_1 * 2;
        pcVar12 = *(code **)(_r_plf_funcs_p + 0xbc);
        *(byte *)(iVar5 + 0x3c) = bVar18;
        uVar19 = uVar15 + 6 & 0xffff;
        *(undefined1 *)(iVar5 + 0x3d) = 2;
        puVar7 = (ushort *)(*pcVar12)(uVar19,pcVar12);
        uVar3 = *puVar7;
        uVar2 = *(ushort *)(iVar17 + 0x44);
        if (((uint)uVar2 == (uint)uVar3) &&
           (pcVar8 = (char *)(**(code **)(_r_plf_funcs_p + 0xbc))
                                       (uVar15,*(code **)(_r_plf_funcs_p + 0xbc)), *pcVar8 == '\x01'
           )) {
          uVar15 = (uint)*(ushort *)(iVar17 + 0x7c) + (uint)*(ushort *)(iVar17 + 0x7e) + 9 +
                   (uint)*(ushort *)(iVar17 + 0x72);
          iVar5 = uVar15 * 0x10000;
          uVar15 = uVar15 & 0xffff;
          if (((uVar15 + 1) - (uint)uVar2 & 0xffff) < 0x7fff) {
            puVar6 = (undefined1 *)
                     (**(code **)(_r_plf_funcs_p + 0xbc))(uVar19,*(code **)(_r_plf_funcs_p + 0xbc));
            *puVar6 = (char)((uint)iVar5 >> 0x10);
            puVar6[1] = (char)(uVar15 >> 8);
            *(short *)(iVar17 + 0x44) = (short)((uint)iVar5 >> 0x10);
          }
        }
        else {
          if (0 < _g_bt_plf_log_level) {
            uVar2 = *(ushort *)(iVar17 + 0x7e);
            uVar21 = *(ushort *)(iVar17 + 0x7c);
            puVar6 = (undefined1 *)
                     (**(code **)(_r_plf_funcs_p + 0xbc))(uVar15,*(code **)(_r_plf_funcs_p + 0xbc));
            ets_printf("llcp prog: %u %u %u %u %u\n",(uint)uVar21 + (uint)uVar2,*puVar6,(uint)uVar3,
                       *(undefined1 *)(iVar17 + 0x46),*(undefined2 *)(iVar17 + 0x44));
          }
          (**(code **)(_r_ip_funcs_p + 0x7d4))(param_1,*(code **)(_r_ip_funcs_p + 0x7d4));
        }
      }
    }
    bVar16 = bVar16 + 1;
    iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar2 = *(ushort *)(iVar5 + iVar9);
    iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar5 + iVar9) = uVar2 & 0x7fff;
    *(byte *)(iVar17 + 0x91) = *(char *)(iVar17 + 0x91) + 1U & 1;
    (**(code **)(_r_ip_funcs_p + 0x78c))(iVar17,*(code **)(_r_ip_funcs_p + 0x78c));
    *(char *)(iVar17 + 0x92) = *(char *)(iVar17 + 0x92) + '\x01';
  } while( true );
}

