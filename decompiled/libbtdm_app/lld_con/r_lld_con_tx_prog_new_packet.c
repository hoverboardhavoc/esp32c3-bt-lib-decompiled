/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
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
  byte bVar5;
  int iVar6;
  ushort *puVar7;
  byte *pbVar8;
  undefined1 *puVar9;
  char cVar10;
  uint uVar11;
  undefined1 uVar12;
  uint uVar13;
  int *piVar14;
  uint uVar15;
  int *piVar16;
  byte bVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  ushort uVar21;
  int iVar22;
  uint uStack_5c;
  
  iVar20 = *(int *)(&lld_con_env + param_1 * 4);
  iVar19 = *(int *)(iVar20 + 0x24);
  piVar16 = *(int **)(iVar20 + 0x30);
  uStack_5c = 0;
  if ((((*(ushort *)(iVar20 + 0x84) & 0x10) != 0) && (piVar16 != (int *)0x0)) &&
     (uStack_5c = 1, *(short *)(iVar20 + 0x82) == 0)) {
    uStack_5c = (uint)(*piVar16 != 0);
  }
  bVar17 = *(byte *)(iVar20 + 0x92);
  do {
    if (1 < bVar17) {
      return;
    }
    if (iVar19 == 0) {
      if (uStack_5c == 0) {
        return;
      }
_L122:
      uVar11 = (uint)*(ushort *)(iVar20 + 0x82);
      if ((uVar11 == 0) && (piVar14 = (int *)*piVar16, piVar14 != (int *)0x0)) {
        uVar2 = *(ushort *)((int)piVar14 + 6);
        *(int **)(iVar20 + 0x30) = piVar14;
        uVar11 = uVar2 & 0x3ff;
        piVar16 = piVar14;
      }
      uVar2 = *(ushort *)((int)piVar16 + 6);
      uVar15 = (*(ushort *)(piVar16 + 1) - uVar11) + (uVar2 & 0x3ff) & 0xffff;
      uVar21 = ((uVar2 & 0x3000) != 0x1000) + 1;
      uVar13 = (uint)*(byte *)(iVar20 + 0x8c);
      if (uVar11 < *(byte *)(iVar20 + 0x8c)) {
        uVar13 = uVar11;
      }
      *(ushort *)((int)piVar16 + 6) = uVar2 & 0xcfff | 0x1000;
      *(short *)(iVar20 + 0x82) = (short)uVar11 - (short)uVar13;
    }
    else {
      if (((param_2 == 2) && (uStack_5c != 0)) && ((bVar17 != 1 && (sdk_cfg_priv_opts != '\0'))))
      goto _L122;
      uVar13 = (uint)*(byte *)(iVar19 + 6);
      uVar15 = (uint)*(ushort *)(iVar19 + 4);
      uVar21 = 3;
      *(undefined4 *)(iVar20 + 0x24) = 0;
      iVar19 = 0;
    }
    cVar1 = *(char *)(iVar20 + 0x91);
    cVar10 = *(char *)(iVar20 + 0x8e) * '\t';
    uVar2 = *(ushort *)(iVar20 + 0x84);
    bVar5 = cVar10 + cVar1;
    uStack_5c = 0;
    if ((((uVar2 & 0x10) != 0) && (piVar16 != (int *)0x0)) &&
       (uStack_5c = 1, *(short *)(iVar20 + 0x82) == 0)) {
      uStack_5c = (uint)(*piVar16 != 0);
    }
    if ((uVar2 & 0x40) != 0) {
      uVar13 = uVar13 + 4 & 0xffff;
    }
    if ((int)((uint)uVar2 << 0x12) < 0) {
      uVar11 = 0;
    }
    else {
      uVar11 = uStack_5c;
      if (uStack_5c == 0) {
        uVar11 = uVar2 & 1;
      }
    }
    iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    iVar18 = (uint)bVar5 * 0xe;
    *(ushort *)(iVar18 + 2 + iVar6) = (ushort)(uVar13 << 8) | uVar21 | (ushort)(uVar11 << 4);
    iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(short *)(iVar18 + 4 + iVar6) = (short)uVar15;
    if (-1 < (int)((uint)*(ushort *)(iVar20 + 0x84) << 0x12)) {
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar22 = (uint)(byte)((cVar1 + 1U & 1) + cVar10) * 0xe;
      if (-1 < *(short *)(iVar6 + iVar22)) {
        iVar22 = iVar22 + 2;
        iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
        uVar2 = *(ushort *)(iVar6 + iVar22);
        iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
        *(ushort *)(iVar6 + iVar22) = uVar2 | 0x10;
      }
    }
    if (uVar21 == 3) {
      iVar6 = (**(code **)(_r_ip_funcs_p + 0x91c))(*(code **)(_r_ip_funcs_p + 0x91c));
      if (param_2 == 2) {
        puVar9 = (undefined1 *)(iVar6 + param_1 * 4);
        *puVar9 = 1;
        puVar9[1] = bVar5;
        if ((uint)bVar5 == (uint)*(byte *)(iVar20 + 0x90) + param_1 * 9) {
          puVar9[2] = 1;
        }
      }
      else {
        if (param_2 < 3) {
          if (param_2 == 0) {
            uVar12 = 1;
            iVar22 = 10;
          }
          else {
            uVar12 = 2;
            iVar22 = 6;
          }
        }
        else {
          if (param_2 != 0x18) goto _L135;
          uVar12 = 3;
          iVar22 = 3;
        }
        iVar6 = iVar6 + param_1 * 2;
        *(undefined1 *)(iVar6 + 0x3d) = uVar12;
        iVar4 = _r_plf_funcs_p;
        *(byte *)(iVar6 + 0x3c) = bVar5;
        uVar11 = iVar22 + uVar15 & 0xffff;
        puVar7 = (ushort *)(**(code **)(iVar4 + 0xbc))(uVar11,*(code **)(iVar4 + 0xbc));
        uVar21 = *puVar7;
        uVar2 = *(ushort *)(iVar20 + 0x44);
        if (((uint)uVar2 == (uint)uVar21) &&
           (pbVar8 = (byte *)(**(code **)(_r_plf_funcs_p + 0xbc))
                                       (uVar15,*(code **)(_r_plf_funcs_p + 0xbc)),
           *pbVar8 == param_2)) {
          uVar13 = (uint)*(ushort *)(iVar20 + 0x7c) + (uint)*(ushort *)(iVar20 + 0x7e) + 9 +
                   (uint)*(ushort *)(iVar20 + 0x72);
          iVar6 = uVar13 * 0x10000;
          uVar13 = uVar13 & 0xffff;
          if (((uVar13 + 1) - (uint)uVar2 & 0xffff) < 0x7fff) {
            puVar9 = (undefined1 *)
                     (**(code **)(_r_plf_funcs_p + 0xbc))(uVar11,*(code **)(_r_plf_funcs_p + 0xbc));
            *puVar9 = (char)((uint)iVar6 >> 0x10);
            puVar9[1] = (char)(uVar13 >> 8);
            *(short *)(iVar20 + 0x44) = (short)((uint)iVar6 >> 0x10);
          }
        }
        else {
          if (0 < _g_bt_plf_log_level) {
            uVar2 = *(ushort *)(iVar20 + 0x7e);
            uVar3 = *(ushort *)(iVar20 + 0x7c);
            puVar9 = (undefined1 *)
                     (**(code **)(_r_plf_funcs_p + 0xbc))(uVar15,*(code **)(_r_plf_funcs_p + 0xbc));
            ets_printf("llcp prog: %u %u %u %u %u\n",(uint)uVar3 + (uint)uVar2,*puVar9,(uint)uVar21,
                       *(undefined1 *)(iVar20 + 0x46),*(undefined2 *)(iVar20 + 0x44));
          }
          (**(code **)(_r_ip_funcs_p + 0x7d4))(param_1,*(code **)(_r_ip_funcs_p + 0x7d4));
        }
      }
    }
_L135:
    bVar17 = bVar17 + 1;
    iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar2 = *(ushort *)(iVar6 + iVar18);
    iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar18 + iVar6) = uVar2 & 0x7fff;
    *(byte *)(iVar20 + 0x91) = *(char *)(iVar20 + 0x91) + 1U & 1;
    (**(code **)(_r_ip_funcs_p + 0x78c))(iVar20,*(code **)(_r_ip_funcs_p + 0x78c));
    *(char *)(iVar20 + 0x92) = *(char *)(iVar20 + 0x92) + '\x01';
  } while( true );
}

