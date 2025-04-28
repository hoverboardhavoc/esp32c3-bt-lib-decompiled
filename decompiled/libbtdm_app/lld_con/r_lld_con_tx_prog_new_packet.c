/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  uint uVar5;
  int iVar6;
  ushort *puVar7;
  byte *pbVar8;
  undefined1 *puVar9;
  char cVar10;
  uint uVar11;
  undefined1 uVar12;
  uint uVar13;
  int iVar14;
  int *piVar15;
  int *piVar16;
  ushort uVar17;
  byte bVar18;
  int iVar19;
  int iVar20;
  byte bVar21;
  int iVar22;
  uint uStack_60;
  
  iVar19 = *(int *)(&lld_con_env + param_1 * 4);
  iVar22 = *(int *)(iVar19 + 0x24);
  piVar16 = *(int **)(iVar19 + 0x30);
  uStack_60 = 0;
  if ((((*(ushort *)(iVar19 + 0x84) & 0x10) != 0) && (piVar16 != (int *)0x0)) &&
     (uStack_60 = 1, *(short *)(iVar19 + 0x82) == 0)) {
    uStack_60 = (uint)(*piVar16 != 0);
  }
  bVar18 = *(byte *)(iVar19 + 0x92);
  do {
    if (1 < bVar18) {
      return;
    }
    if (iVar22 == 0) {
      if (uStack_60 == 0) {
        return;
      }
_L123:
      if ((*(short *)(iVar19 + 0x82) == 0) && (piVar15 = (int *)*piVar16, piVar15 != (int *)0x0)) {
        uVar2 = *(ushort *)((int)piVar15 + 6);
        *(int **)(iVar19 + 0x30) = piVar15;
        *(ushort *)(iVar19 + 0x82) = uVar2 & 0x3ff;
        piVar16 = piVar15;
      }
      uVar2 = *(ushort *)((int)piVar16 + 6);
      uVar3 = *(ushort *)(iVar19 + 0x82);
      uVar11 = (uint)uVar3;
      uVar5 = (*(ushort *)(piVar16 + 1) - uVar11) + (uVar2 & 0x3ff) & 0xffff;
      uVar17 = 2;
      if (((int)(uint)uVar2 >> 0xc & 3U) == 1) {
        uVar17 = 1;
      }
      uVar13 = (uint)*(byte *)(iVar19 + 0x8c);
      if (uVar11 < *(byte *)(iVar19 + 0x8c)) {
        uVar13 = uVar11;
      }
      *(ushort *)((int)piVar16 + 6) = uVar2 & 0xcfff | 0x1000;
      *(ushort *)(iVar19 + 0x82) = uVar3 - (short)uVar13;
    }
    else {
      if (((param_2 == 2) && (uStack_60 != 0)) && ((bVar18 != 1 && (DAT_0001604e != '\0'))))
      goto _L123;
      uVar13 = (uint)*(byte *)(iVar22 + 6);
      uVar5 = (uint)*(ushort *)(iVar22 + 4);
      uVar17 = 3;
      *(undefined4 *)(iVar19 + 0x24) = 0;
      iVar22 = 0;
    }
    cVar10 = *(char *)(iVar19 + 0x8e) * '\t';
    uVar2 = *(ushort *)(iVar19 + 0x84);
    cVar1 = *(char *)(iVar19 + 0x91);
    bVar21 = cVar10 + cVar1;
    uStack_60 = 0;
    if ((((uVar2 & 0x10) != 0) && (piVar16 != (int *)0x0)) &&
       (uStack_60 = 1, *(short *)(iVar19 + 0x82) == 0)) {
      uStack_60 = (uint)(*piVar16 != 0);
    }
    if ((uVar2 & 0x40) != 0) {
      uVar13 = uVar13 + 4 & 0xffff;
    }
    if ((uVar2 & 0x2000) == 0) {
      uVar11 = uStack_60;
      if (uStack_60 == 0) {
        uVar11 = uVar2 & 1;
      }
    }
    else {
      uVar11 = 0;
    }
    iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    iVar20 = (uint)bVar21 * 0xe;
    *(ushort *)(iVar20 + 2 + iVar6) =
         (ushort)((uVar13 & 0xff) << 8) | uVar17 | (ushort)(uVar11 << 4);
    iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(short *)(iVar20 + 4 + iVar6) = (short)uVar5;
    if ((*(ushort *)(iVar19 + 0x84) & 0x2000) == 0) {
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
    if (uVar17 == 3) {
      iVar6 = (**(code **)(_r_ip_funcs_p + 0x91c))(*(code **)(_r_ip_funcs_p + 0x91c));
      if (param_2 == 2) {
        puVar9 = (undefined1 *)(iVar6 + param_1 * 4);
        *puVar9 = 1;
        puVar9[1] = bVar21;
        if ((uint)bVar21 == (uint)*(byte *)(iVar19 + 0x90) + param_1 * 9) {
          puVar9[2] = 1;
        }
      }
      else {
        if (param_2 < 3) {
          if (param_2 == 0) {
            uVar12 = 1;
            iVar14 = 10;
          }
          else {
            uVar12 = 2;
            iVar14 = 6;
          }
        }
        else {
          if (param_2 != 0x18) goto _L136;
          uVar12 = 3;
          iVar14 = 3;
        }
        iVar6 = iVar6 + param_1 * 2;
        *(undefined1 *)(iVar6 + 0x3d) = uVar12;
        iVar4 = _r_plf_funcs_p;
        *(byte *)(iVar6 + 0x3c) = bVar21;
        uVar11 = uVar5 + iVar14 & 0xffff;
        puVar7 = (ushort *)(**(code **)(iVar4 + 0xbc))(uVar11,*(code **)(iVar4 + 0xbc));
        uVar3 = *puVar7;
        uVar2 = *(ushort *)(iVar19 + 0x44);
        if (((uint)uVar2 == (uint)uVar3) &&
           (pbVar8 = (byte *)(**(code **)(_r_plf_funcs_p + 0xbc))
                                       (uVar5,*(code **)(_r_plf_funcs_p + 0xbc)), *pbVar8 == param_2
           )) {
          uVar5 = (uint)*(ushort *)(iVar19 + 0x7c) + (uint)*(ushort *)(iVar19 + 0x7e) + 9 +
                  (uint)*(ushort *)(iVar19 + 0x72);
          iVar6 = uVar5 * 0x10000;
          uVar5 = uVar5 & 0xffff;
          if (((uVar5 + 1) - (uint)uVar2 & 0xffff) < 0x7fff) {
            puVar9 = (undefined1 *)
                     (**(code **)(_r_plf_funcs_p + 0xbc))(uVar11,*(code **)(_r_plf_funcs_p + 0xbc));
            *puVar9 = (char)((uint)iVar6 >> 0x10);
            puVar9[1] = (char)(uVar5 >> 8);
            *(short *)(iVar19 + 0x44) = (short)((uint)iVar6 >> 0x10);
          }
        }
        else {
          if (0 < _g_bt_plf_log_level) {
            uVar2 = *(ushort *)(iVar19 + 0x7e);
            uVar17 = *(ushort *)(iVar19 + 0x7c);
            puVar9 = (undefined1 *)
                     (**(code **)(_r_plf_funcs_p + 0xbc))(uVar5,*(code **)(_r_plf_funcs_p + 0xbc));
            ets_printf("llcp prog: %u %u %u %u %u\n",(uint)uVar17 + (uint)uVar2,*puVar9,(uint)uVar3,
                       *(undefined1 *)(iVar19 + 0x46),*(undefined2 *)(iVar19 + 0x44));
          }
          (**(code **)(_r_ip_funcs_p + 0x7d4))(param_1,*(code **)(_r_ip_funcs_p + 0x7d4));
        }
      }
    }
_L136:
    bVar18 = bVar18 + 1;
    iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar2 = *(ushort *)(iVar6 + iVar20);
    iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar20 + iVar6) = (ushort)(((uint)uVar2 << 0x11) >> 0x11);
    *(byte *)(iVar19 + 0x91) = *(char *)(iVar19 + 0x91) + 1U & 1;
    (**(code **)(_r_ip_funcs_p + 0x78c))(iVar19,*(code **)(_r_ip_funcs_p + 0x78c));
    *(char *)(iVar19 + 0x92) = *(char *)(iVar19 + 0x92) + '\x01';
  } while( true );
}

