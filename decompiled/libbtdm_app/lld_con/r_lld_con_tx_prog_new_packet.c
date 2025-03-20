/*
 * Last changed at upstream commit daab5dbba958a13041bd496e4a6ed506c9284a06
 * https://github.com/espressif/esp32c3-bt-lib/commit/daab5dbba958a13041bd496e4a6ed506c9284a06
 * Upstream date: 2025-03-20 20:43:40 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(86a4da5c)
 * Source: libbtdm_app -> lld_con.o -> r_lld_con_tx_prog_new_packet
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_con_tx_prog_new_packet(int param_1,uint param_2)

{
  char cVar1;
  ushort uVar2;
  ushort uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  ushort *puVar7;
  byte *pbVar8;
  undefined1 *puVar9;
  char cVar10;
  int *piVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  byte bVar16;
  int iVar17;
  int iVar18;
  byte bVar19;
  uint uVar20;
  ushort uVar21;
  int iStack_68;
  int *piStack_60;
  
  iVar18 = *(int *)(&lld_con_env + param_1 * 4);
  iStack_68 = *(int *)(iVar18 + 0x24);
  piVar5 = *(int **)(iVar18 + 0x30);
  piStack_60 = (int *)0x0;
  if ((((*(ushort *)(iVar18 + 0x84) & 0x10) != 0) && (piStack_60 = piVar5, piVar5 != (int *)0x0)) &&
     (piStack_60 = (int *)0x1, *(short *)(iVar18 + 0x82) == 0)) {
    piStack_60 = (int *)(uint)(*piVar5 != 0);
  }
  bVar16 = *(byte *)(iVar18 + 0x92);
  iVar17 = (param_1 + 0x18) * 2;
  do {
    if (1 < bVar16) {
      return;
    }
    if (iStack_68 == 0) {
      if (piStack_60 == (int *)0x0) {
        return;
      }
_L126:
      if ((*(short *)(iVar18 + 0x82) == 0) && (piVar11 = (int *)*piVar5, piVar11 != (int *)0x0)) {
        uVar2 = *(ushort *)((int)piVar11 + 6);
        *(int **)(iVar18 + 0x30) = piVar11;
        *(ushort *)(iVar18 + 0x82) = uVar2 & 0x3ff;
        piVar5 = piVar11;
      }
      uVar2 = *(ushort *)((int)piVar5 + 6);
      uVar3 = *(ushort *)(iVar18 + 0x82);
      uVar20 = (uint)uVar3;
      uVar15 = (*(ushort *)(piVar5 + 1) - uVar20) + (uVar2 & 0x3ff) & 0xffff;
      uVar21 = 2;
      if (((int)(uint)uVar2 >> 0xc & 3U) == 1) {
        uVar21 = 1;
      }
      uVar13 = (uint)*(byte *)(iVar18 + 0x8c);
      if (uVar20 < *(byte *)(iVar18 + 0x8c)) {
        uVar13 = uVar20;
      }
      *(ushort *)((int)piVar5 + 6) = uVar2 & 0xcfff | 0x1000;
      *(ushort *)(iVar18 + 0x82) = uVar3 - (short)uVar13;
    }
    else {
      if (((param_2 == 2) && (piStack_60 != (int *)0x0)) &&
         ((bVar16 != 1 && (DAT_0001604e != '\0')))) goto _L126;
      uVar21 = 3;
      uVar13 = (uint)*(byte *)(iStack_68 + 6);
      uVar15 = (uint)*(ushort *)(iStack_68 + 4);
      iStack_68 = 0;
      *(undefined4 *)(iVar18 + 0x24) = 0;
    }
    cVar10 = *(char *)(iVar18 + 0x8e) * '\t';
    uVar2 = *(ushort *)(iVar18 + 0x84);
    cVar1 = *(char *)(iVar18 + 0x91);
    bVar19 = cVar10 + cVar1;
    piStack_60 = (int *)0x0;
    if ((((uVar2 & 0x10) != 0) && (piStack_60 = piVar5, piVar5 != (int *)0x0)) &&
       (piStack_60 = (int *)0x1, *(short *)(iVar18 + 0x82) == 0)) {
      piStack_60 = (int *)(uint)(*piVar5 != 0);
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
    iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    iVar12 = (uint)bVar19 * 0xe;
    *(ushort *)(iVar6 + iVar12 + 2) =
         (ushort)((uVar13 & 0xff) << 8) | uVar21 | (ushort)((int)piVar11 << 4);
    iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(short *)(iVar6 + iVar12 + 4) = (short)uVar15;
    if (-1 < (int)((uint)*(ushort *)(iVar18 + 0x84) << 0x12)) {
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar14 = (uint)(byte)((cVar1 + 1U & 1) + cVar10) * 0xe;
      if (-1 < *(short *)(iVar6 + iVar14)) {
        iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
        iVar14 = iVar14 + 2;
        uVar2 = *(ushort *)(iVar6 + iVar14);
        iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
        *(ushort *)(iVar6 + iVar14) = uVar2 & 0xffef | 0x10;
      }
    }
    if (uVar21 == 3) {
      iVar6 = (**(code **)(_r_ip_funcs_p + 0x91c))(*(code **)(_r_ip_funcs_p + 0x91c));
      if (param_2 == 2) {
        puVar9 = (undefined1 *)(iVar6 + param_1 * 4);
        *puVar9 = 1;
        puVar9[1] = bVar19;
        if ((uint)bVar19 == (uint)*(byte *)(iVar18 + 0x90) + param_1 * 9) {
          puVar9[2] = 1;
        }
      }
      else if ((param_2 < 2) || (param_2 == 0x18)) {
        if (param_2 == 0) {
          *(undefined1 *)(iVar6 + iVar17 + 0xd) = 1;
          iVar14 = 10;
        }
        else if (param_2 == 1) {
          *(undefined1 *)(iVar6 + iVar17 + 0xd) = 2;
          iVar14 = 6;
        }
        else if (param_2 == 0x18) {
          *(undefined1 *)(iVar6 + iVar17 + 0xd) = 3;
          iVar14 = 3;
        }
        else {
          (**(code **)(_r_plf_funcs_p + 0xc))
                    (param_1,param_2,"lld_con.c",0x4f6,*(code **)(_r_plf_funcs_p + 0xc));
          iVar14 = 0;
        }
        iVar4 = _r_plf_funcs_p;
        *(byte *)(iVar6 + iVar17 + 0xc) = bVar19;
        uVar20 = uVar15 + iVar14 & 0xffff;
        puVar7 = (ushort *)(**(code **)(iVar4 + 0xbc))(uVar20,*(code **)(iVar4 + 0xbc));
        uVar3 = *puVar7;
        uVar2 = *(ushort *)(iVar18 + 0x44);
        if (((uint)uVar2 == (uint)uVar3) &&
           (pbVar8 = (byte *)(**(code **)(_r_plf_funcs_p + 0xbc))
                                       (uVar15,*(code **)(_r_plf_funcs_p + 0xbc)),
           *pbVar8 == param_2)) {
          uVar15 = (uint)*(ushort *)(iVar18 + 0x7c) + (uint)*(ushort *)(iVar18 + 0x7e) + 9 +
                   (uint)*(ushort *)(iVar18 + 0x72);
          iVar6 = uVar15 * 0x10000;
          uVar15 = uVar15 & 0xffff;
          if (((uVar15 + 1) - (uint)uVar2 & 0xffff) < 0x7fff) {
            puVar9 = (undefined1 *)
                     (**(code **)(_r_plf_funcs_p + 0xbc))(uVar20,*(code **)(_r_plf_funcs_p + 0xbc));
            *puVar9 = (char)((uint)iVar6 >> 0x10);
            puVar9[1] = (char)(uVar15 >> 8);
            *(short *)(iVar18 + 0x44) = (short)((uint)iVar6 >> 0x10);
          }
        }
        else {
          if (0 < _g_bt_plf_log_level) {
            uVar2 = *(ushort *)(iVar18 + 0x7e);
            uVar21 = *(ushort *)(iVar18 + 0x7c);
            puVar9 = (undefined1 *)
                     (**(code **)(_r_plf_funcs_p + 0xbc))(uVar15,*(code **)(_r_plf_funcs_p + 0xbc));
            ets_printf("llcp prog: %u %u %u %u %u\n",(uint)uVar21 + (uint)uVar2,*puVar9,(uint)uVar3,
                       *(undefined1 *)(iVar18 + 0x46),*(undefined2 *)(iVar18 + 0x44));
          }
          (**(code **)(_r_ip_funcs_p + 0x7d4))(param_1,*(code **)(_r_ip_funcs_p + 0x7d4));
        }
      }
    }
    bVar16 = bVar16 + 1;
    iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar2 = *(ushort *)(iVar6 + iVar12);
    iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar6 + iVar12) = uVar2 & 0x7fff;
    *(byte *)(iVar18 + 0x91) = *(char *)(iVar18 + 0x91) + 1U & 1;
    (**(code **)(_r_ip_funcs_p + 0x78c))(iVar18,*(code **)(_r_ip_funcs_p + 0x78c));
    *(char *)(iVar18 + 0x92) = *(char *)(iVar18 + 0x92) + '\x01';
  } while( true );
}

