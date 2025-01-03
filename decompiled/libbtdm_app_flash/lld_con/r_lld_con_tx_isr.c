/*
 * Last changed at upstream commit ed99228396aaa18935b575d600bc19da38dc4746
 * https://github.com/espressif/esp32c3-bt-lib/commit/ed99228396aaa18935b575d600bc19da38dc4746
 * Upstream date: 2025-01-03 16:50:09 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(fd62b31)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_tx_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_con_tx_isr(int param_1)

{
  char cVar1;
  byte bVar2;
  ushort uVar3;
  ushort uVar4;
  bool bVar5;
  int *piVar6;
  uint uVar7;
  int iVar8;
  ushort *puVar9;
  undefined1 *puVar10;
  byte *pbVar11;
  byte bVar12;
  int *piVar13;
  int iVar14;
  uint uVar15;
  int iVar16;
  int iVar17;
  ushort uVar18;
  int iVar19;
  byte bVar20;
  byte bVar21;
  uint uVar22;
  char cVar23;
  int iVar24;
  int *piStack_5c;
  
  if (*(int *)(&lld_con_env + param_1 * 4) == 0) {
    r_assert_param(0,"lld_con.c",0xc21);
    return;
  }
  r_lld_con_tx_eco();
  iVar17 = *(int *)(&lld_con_env + param_1 * 4);
  if (*(int *)(iVar17 + 0x30) == 0) {
    iVar14 = *(int *)(iVar17 + 0x28);
    *(int *)(iVar17 + 0x30) = iVar14;
    if (iVar14 != 0) {
      *(ushort *)(iVar17 + 0x82) = *(ushort *)(iVar14 + 6) & 0x3ff;
    }
  }
  bVar5 = false;
  if ((((*(ushort *)(iVar17 + 0x84) & 0x10) != 0) && (*(int **)(iVar17 + 0x30) != (int *)0x0)) &&
     (bVar5 = true, *(short *)(iVar17 + 0x82) == 0)) {
    bVar5 = **(int **)(iVar17 + 0x30) != 0;
  }
  iVar14 = *(int *)(iVar17 + 0x24);
  if ((iVar14 == 0) && (!bVar5)) {
    return;
  }
  if (*(char *)(iVar17 + 0x92) == '\x02') {
    bVar12 = *(byte *)(iVar17 + 0x91);
    bVar20 = *(byte *)(iVar17 + 0x8e);
    iVar14 = r_emi_get_mem_addr_by_offset(0x1400);
    iVar17 = ((bVar12 + 1 & 1) + (uint)bVar20 * 9 & 0xff) * 0xe;
    if (-1 < *(short *)(iVar14 + iVar17)) {
      iVar14 = r_emi_get_mem_addr_by_offset(0x1400);
      iVar17 = iVar17 + 2;
      uVar4 = *(ushort *)(iVar14 + iVar17);
      iVar14 = r_emi_get_mem_addr_by_offset(0x1400);
      *(ushort *)(iVar14 + iVar17) = uVar4 & 0xffef | 0x10;
    }
    return;
  }
  bVar12 = 0x23;
  if (iVar14 != 0) {
    pbVar11 = (byte *)r_emi_get_mem_addr_by_offset(*(undefined2 *)(iVar14 + 4));
    bVar12 = *pbVar11;
  }
  iVar17 = *(int *)(&lld_con_env + param_1 * 4);
  iVar14 = *(int *)(iVar17 + 0x24);
  piVar6 = *(int **)(iVar17 + 0x30);
  piStack_5c = (int *)0x0;
  if ((((*(ushort *)(iVar17 + 0x84) & 0x10) != 0) && (piStack_5c = piVar6, piVar6 != (int *)0x0)) &&
     (piStack_5c = (int *)0x1, *(short *)(iVar17 + 0x82) == 0)) {
    piStack_5c = (int *)(uint)(*piVar6 != 0);
  }
  bVar20 = *(byte *)(iVar17 + 0x92);
  iVar19 = (param_1 + 0x18) * 2;
  do {
    if (1 < bVar20) {
      return;
    }
    if (iVar14 == 0) {
      if (piStack_5c == (int *)0x0) {
        return;
      }
_L407:
      if ((*(short *)(iVar17 + 0x82) == 0) && (piVar13 = (int *)*piVar6, piVar13 != (int *)0x0)) {
        uVar4 = *(ushort *)((int)piVar13 + 6);
        *(int **)(iVar17 + 0x30) = piVar13;
        *(ushort *)(iVar17 + 0x82) = uVar4 & 0x3ff;
        piVar6 = piVar13;
      }
      uVar4 = *(ushort *)((int)piVar6 + 6);
      uVar3 = *(ushort *)(iVar17 + 0x82);
      uVar22 = (uint)uVar3;
      uVar7 = (*(ushort *)(piVar6 + 1) - uVar22) + (uVar4 & 0x3ff) & 0xffff;
      uVar18 = 2;
      if (((int)(uint)uVar4 >> 0xc & 3U) == 1) {
        uVar18 = 1;
      }
      uVar15 = (uint)*(byte *)(iVar17 + 0x8c);
      if (uVar22 < *(byte *)(iVar17 + 0x8c)) {
        uVar15 = uVar22;
      }
      *(ushort *)((int)piVar6 + 6) = uVar4 & 0xcfff | 0x1000;
      *(ushort *)(iVar17 + 0x82) = uVar3 - (short)uVar15;
    }
    else {
      if ((((bVar12 == 2) && (piStack_5c != (int *)0x0)) && (bVar20 != 1)) && (DAT_0001508e != '\0')
         ) goto _L407;
      uVar15 = (uint)*(byte *)(iVar14 + 6);
      uVar7 = (uint)*(ushort *)(iVar14 + 4);
      uVar18 = 3;
      *(undefined4 *)(iVar17 + 0x24) = 0;
      iVar14 = 0;
    }
    uVar4 = *(ushort *)(iVar17 + 0x84);
    cVar23 = *(char *)(iVar17 + 0x8e) * '\t';
    cVar1 = *(char *)(iVar17 + 0x91);
    bVar21 = cVar23 + cVar1;
    piStack_5c = (int *)0x0;
    if ((((uVar4 & 0x10) != 0) && (piStack_5c = piVar6, piVar6 != (int *)0x0)) &&
       (piStack_5c = (int *)0x1, *(short *)(iVar17 + 0x82) == 0)) {
      piStack_5c = (int *)(uint)(*piVar6 != 0);
    }
    if ((uVar4 & 0x40) != 0) {
      uVar15 = uVar15 + 4 & 0xffff;
    }
    if ((int)((uint)uVar4 << 0x12) < 0) {
      piVar13 = (int *)0x0;
    }
    else {
      piVar13 = piStack_5c;
      if (piStack_5c == (int *)0x0) {
        piVar13 = (int *)(uVar4 & 1);
      }
    }
    iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
    iVar16 = (uint)bVar21 * 0xe;
    *(ushort *)(iVar8 + iVar16 + 2) =
         (ushort)((uVar15 & 0xff) << 8) | uVar18 | (ushort)((int)piVar13 << 4);
    iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
    *(short *)(iVar8 + iVar16 + 4) = (short)uVar7;
    if (-1 < (int)((uint)*(ushort *)(iVar17 + 0x84) << 0x12)) {
      iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
      iVar24 = (uint)(byte)((cVar1 + 1U & 1) + cVar23) * 0xe;
      if (-1 < *(short *)(iVar8 + iVar24)) {
        iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
        iVar24 = iVar24 + 2;
        uVar4 = *(ushort *)(iVar8 + iVar24);
        iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
        *(ushort *)(iVar8 + iVar24) = uVar4 & 0xffef | 0x10;
      }
    }
    if (uVar18 == 3) {
      if (bVar12 == 2) {
        bVar2 = *(byte *)(iVar17 + 0x90);
        *(undefined1 *)(&lld_con_cntl_pkt_info + param_1) = 1;
        *(byte *)((int)&lld_con_cntl_pkt_info + param_1 * 4 + 1) = bVar21;
        if ((uint)bVar21 == (uint)bVar2 + param_1 * 9) {
          *(undefined1 *)((int)&lld_con_cntl_pkt_info + param_1 * 4 + 2) = 1;
        }
      }
      else if ((bVar12 < 2) || (bVar12 == 0x18)) {
        if (bVar12 == 0) {
          (&DAT_000149bd)[iVar19] = 1;
          iVar8 = 10;
        }
        else if (bVar12 == 1) {
          (&DAT_000149bd)[iVar19] = 2;
          iVar8 = 6;
        }
        else if (bVar12 == 0x18) {
          (&DAT_000149bd)[iVar19] = 3;
          iVar8 = 3;
        }
        else {
          r_assert_param(param_1,bVar12,"lld_con.c",0x4ec);
          iVar8 = 0;
        }
        (&DAT_000149bc)[iVar19] = bVar21;
        uVar22 = uVar7 + iVar8 & 0xffff;
        puVar9 = (ushort *)r_emi_get_mem_addr_by_offset(uVar22);
        uVar3 = *puVar9;
        uVar4 = *(ushort *)(iVar17 + 0x44);
        if (((uint)uVar4 == (uint)uVar3) &&
           (pbVar11 = (byte *)r_emi_get_mem_addr_by_offset(uVar7), *pbVar11 == bVar12)) {
          uVar7 = (uint)*(ushort *)(iVar17 + 0x7c) + (uint)*(ushort *)(iVar17 + 0x7e) + 9 +
                  (uint)*(ushort *)(iVar17 + 0x72);
          iVar8 = uVar7 * 0x10000;
          uVar7 = uVar7 & 0xffff;
          if (((uVar7 + 1) - (uint)uVar4 & 0xffff) < 0x7fff) {
            puVar10 = (undefined1 *)r_emi_get_mem_addr_by_offset(uVar22);
            *puVar10 = (char)((uint)iVar8 >> 0x10);
            puVar10[1] = (char)(uVar7 >> 8);
            *(short *)(iVar17 + 0x44) = (short)((uint)iVar8 >> 0x10);
          }
        }
        else {
          if (0 < _g_bt_plf_log_level) {
            uVar4 = *(ushort *)(iVar17 + 0x7e);
            uVar18 = *(ushort *)(iVar17 + 0x7c);
            puVar10 = (undefined1 *)r_emi_get_mem_addr_by_offset(uVar7);
            ets_printf("llcp prog: %u %u %u %u %u\n",(uint)uVar18 + (uint)uVar4,*puVar10,(uint)uVar3
                       ,*(undefined1 *)(iVar17 + 0x46),*(undefined2 *)(iVar17 + 0x44));
          }
          *(undefined2 *)(&DAT_000149bc + iVar19) = 0;
        }
      }
    }
    iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
    bVar20 = bVar20 + 1;
    uVar4 = *(ushort *)(iVar8 + iVar16);
    iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
    *(ushort *)(iVar8 + iVar16) = uVar4 & 0x7fff;
    *(byte *)(iVar17 + 0x91) = *(char *)(iVar17 + 0x91) + 1U & 1;
    r_lld_con_tx_prog_new_packet_coex(iVar17);
    *(char *)(iVar17 + 0x92) = *(char *)(iVar17 + 0x92) + '\x01';
  } while( true );
}

