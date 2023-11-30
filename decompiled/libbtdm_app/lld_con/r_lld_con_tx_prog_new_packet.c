/*
 * Last changed at upstream commit a075a8fde411bdd92973051edf2cd234601b259c
 * https://github.com/espressif/esp32c3-bt-lib/commit/a075a8fde411bdd92973051edf2cd234601b259c
 * Upstream date: 2023-11-30 21:15:40 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(70ab55f)
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
  uint uVar14;
  byte bVar15;
  int iVar16;
  byte bVar17;
  uint uVar18;
  int iVar19;
  ushort uVar20;
  int iVar21;
  int *piStack_64;
  
  iVar21 = *(int *)(&lld_con_env + param_1 * 4);
  iVar19 = *(int *)(iVar21 + 0x24);
  piVar4 = *(int **)(iVar21 + 0x30);
  piStack_64 = (int *)0x0;
  if ((((*(ushort *)(iVar21 + 0x84) & 0x10) != 0) && (piStack_64 = piVar4, piVar4 != (int *)0x0)) &&
     (piStack_64 = (int *)0x1, *(short *)(iVar21 + 0x82) == 0)) {
    piStack_64 = (int *)(uint)(*piVar4 != 0);
  }
  bVar15 = *(byte *)(iVar21 + 0x92);
  do {
    if (1 < bVar15) {
      return;
    }
    if (iVar19 == 0) {
      if (piStack_64 == (int *)0x0) {
        return;
      }
_L141:
      if ((*(short *)(iVar21 + 0x82) == 0) && (piVar10 = (int *)*piVar4, piVar10 != (int *)0x0)) {
        uVar2 = *(ushort *)((int)piVar10 + 6);
        *(int **)(iVar21 + 0x30) = piVar10;
        *(ushort *)(iVar21 + 0x82) = uVar2 & 0x3ff;
        piVar4 = piVar10;
      }
      uVar2 = *(ushort *)((int)piVar4 + 6);
      uVar3 = *(ushort *)(iVar21 + 0x82);
      uVar18 = (uint)uVar3;
      uVar14 = (*(ushort *)(piVar4 + 1) - uVar18) + (uVar2 & 0x3ff) & 0xffff;
      uVar20 = 2;
      if (((int)(uint)uVar2 >> 0xc & 3U) == 1) {
        uVar20 = 1;
      }
      uVar12 = (uint)*(byte *)(iVar21 + 0x8c);
      if (uVar18 < *(byte *)(iVar21 + 0x8c)) {
        uVar12 = uVar18;
      }
      *(ushort *)((int)piVar4 + 6) = uVar2 & 0xcfff | 0x1000;
      *(ushort *)(iVar21 + 0x82) = uVar3 - (short)uVar12;
    }
    else {
      if (((param_2 == 2) && (piStack_64 != (int *)0x0)) &&
         ((bVar15 != 1 && (DAT_0001204e != '\0')))) goto _L141;
      uVar12 = (uint)*(byte *)(iVar19 + 6);
      uVar14 = (uint)*(ushort *)(iVar19 + 4);
      uVar20 = 3;
      *(undefined4 *)(iVar21 + 0x24) = 0;
      iVar19 = 0;
    }
    cVar9 = *(char *)(iVar21 + 0x8e) * '\t';
    uVar2 = *(ushort *)(iVar21 + 0x84);
    cVar1 = *(char *)(iVar21 + 0x91);
    bVar17 = cVar9 + cVar1;
    piStack_64 = (int *)0x0;
    if ((((uVar2 & 0x10) != 0) && (piStack_64 = piVar4, piVar4 != (int *)0x0)) &&
       (piStack_64 = (int *)0x1, *(short *)(iVar21 + 0x82) == 0)) {
      piStack_64 = (int *)(uint)(*piVar4 != 0);
    }
    if ((uVar2 & 0x40) != 0) {
      uVar12 = uVar12 + 4 & 0xffff;
    }
    if ((int)((uint)uVar2 << 0x12) < 0) {
      piVar10 = (int *)0x0;
    }
    else {
      piVar10 = piStack_64;
      if (piStack_64 == (int *)0x0) {
        piVar10 = (int *)(uVar2 & 1);
      }
    }
    iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    iVar16 = (uint)bVar17 * 0xe;
    *(ushort *)(iVar5 + iVar16 + 2) =
         (ushort)((uVar12 & 0xff) << 8) | uVar20 | (ushort)((int)piVar10 << 4);
    iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(short *)(iVar5 + iVar16 + 4) = (short)uVar14;
    if (-1 < (int)((uint)*(ushort *)(iVar21 + 0x84) << 0x12)) {
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar13 = (uint)(byte)((cVar1 + 1U & 1) + cVar9) * 0xe;
      if (-1 < *(short *)(iVar5 + iVar13)) {
        iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
        iVar13 = iVar13 + 2;
        uVar2 = *(ushort *)(iVar5 + iVar13);
        iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
        *(ushort *)(iVar5 + iVar13) = uVar2 & 0xffef | 0x10;
      }
    }
    if (uVar20 == 3) {
      iVar5 = (**(code **)(_r_ip_funcs_p + 0x91c))(*(code **)(_r_ip_funcs_p + 0x91c));
      if (param_2 == 2) {
        puVar6 = (undefined1 *)(iVar5 + param_1 * 4);
        *puVar6 = 1;
        puVar6[1] = bVar17;
        if ((uint)bVar17 == (uint)*(byte *)(iVar21 + 0x90) + param_1 * 9) {
          puVar6[2] = 1;
        }
      }
      else if (param_2 == 1) {
        iVar5 = iVar5 + param_1 * 2;
        pcVar11 = *(code **)(_r_plf_funcs_p + 0xbc);
        *(byte *)(iVar5 + 0x3c) = bVar17;
        uVar18 = uVar14 + 6 & 0xffff;
        *(undefined1 *)(iVar5 + 0x3d) = 2;
        puVar7 = (ushort *)(*pcVar11)(uVar18,pcVar11);
        uVar3 = *puVar7;
        uVar2 = *(ushort *)(iVar21 + 0x44);
        if (((uint)uVar2 == (uint)uVar3) &&
           (pcVar8 = (char *)(**(code **)(_r_plf_funcs_p + 0xbc))
                                       (uVar14,*(code **)(_r_plf_funcs_p + 0xbc)), *pcVar8 == '\x01'
           )) {
          uVar14 = (uint)*(ushort *)(iVar21 + 0x7c) + (uint)*(ushort *)(iVar21 + 0x7e) + 9 +
                   (uint)*(ushort *)(iVar21 + 0x72);
          iVar5 = uVar14 * 0x10000;
          uVar14 = uVar14 & 0xffff;
          if (((uVar14 + 1) - (uint)uVar2 & 0xffff) < 0x7fff) {
            puVar6 = (undefined1 *)
                     (**(code **)(_r_plf_funcs_p + 0xbc))(uVar18,*(code **)(_r_plf_funcs_p + 0xbc));
            *puVar6 = (char)((uint)iVar5 >> 0x10);
            puVar6[1] = (char)(uVar14 >> 8);
            *(short *)(iVar21 + 0x44) = (short)((uint)iVar5 >> 0x10);
          }
        }
        else if (0 < _g_bt_plf_log_level) {
          puVar6 = (undefined1 *)
                   (**(code **)(_r_plf_funcs_p + 0xbc))(uVar14,*(code **)(_r_plf_funcs_p + 0xbc));
          ets_printf("instant proc: %u %u %u %u\n",*puVar6,(uint)uVar3,
                     *(undefined1 *)(iVar21 + 0x46),*(undefined2 *)(iVar21 + 0x44));
        }
      }
    }
    bVar15 = bVar15 + 1;
    iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar2 = *(ushort *)(iVar5 + iVar16);
    iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar5 + iVar16) = uVar2 & 0x7fff;
    *(byte *)(iVar21 + 0x91) = *(char *)(iVar21 + 0x91) + 1U & 1;
    (**(code **)(_r_ip_funcs_p + 0x78c))(iVar21,*(code **)(_r_ip_funcs_p + 0x78c));
    *(char *)(iVar21 + 0x92) = *(char *)(iVar21 + 0x92) + '\x01';
  } while( true );
}

