/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_tx_prog_new_packet
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_con_tx_prog_new_packet(uint param_1,uint param_2)

{
  char cVar1;
  byte bVar2;
  ushort uVar3;
  ushort uVar4;
  char cVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  ushort *puVar9;
  byte *pbVar10;
  undefined1 *puVar11;
  uint uVar12;
  int iVar13;
  undefined1 uVar14;
  int iVar15;
  uint uVar16;
  int *piVar17;
  int *piVar18;
  uint uVar19;
  byte bVar20;
  uint uVar21;
  int iVar22;
  byte bVar23;
  int iVar24;
  int iVar25;
  ushort uVar26;
  
  iVar13 = param_1 * 4;
  iVar22 = *(int *)(&lld_con_env + iVar13);
  iVar25 = *(int *)(iVar22 + 0x24);
  piVar18 = *(int **)(iVar22 + 0x30);
  uVar19 = 0;
  if ((((*(ushort *)(iVar22 + 0x84) & 0x10) != 0) && (piVar18 != (int *)0x0)) &&
     (uVar19 = 1, *(short *)(iVar22 + 0x82) == 0)) {
    uVar19 = (uint)(*piVar18 != 0);
  }
  bVar23 = *(byte *)(iVar22 + 0x92);
  iVar15 = (param_1 + 0x18) * 2;
  do {
    if (1 < bVar23) {
      return;
    }
    if (iVar25 == 0) {
      if (uVar19 == 0) {
        return;
      }
_L436:
      uVar19 = (uint)*(ushort *)(iVar22 + 0x82);
      if ((uVar19 == 0) && (piVar17 = (int *)*piVar18, piVar17 != (int *)0x0)) {
        uVar3 = *(ushort *)((int)piVar17 + 6);
        *(int **)(iVar22 + 0x30) = piVar17;
        uVar19 = uVar3 & 0x3ff;
        piVar18 = piVar17;
      }
      uVar3 = *(ushort *)((int)piVar18 + 6);
      uVar6 = (*(ushort *)(piVar18 + 1) - uVar19) + (uVar3 & 0x3ff) & 0xffff;
      uVar26 = ((uVar3 & 0x3000) != 0x1000) + 1;
      uVar16 = (uint)*(byte *)(iVar22 + 0x8c);
      if (uVar19 < *(byte *)(iVar22 + 0x8c)) {
        uVar16 = uVar19;
      }
      *(ushort *)((int)piVar18 + 6) = uVar3 & 0xcfff | 0x1000;
      *(short *)(iVar22 + 0x82) = (short)uVar19 - (short)uVar16;
    }
    else {
      if (((param_2 == 2) && (uVar19 != 0)) && ((bVar23 != 1 && (sdk_cfg_priv_opts != '\0'))))
      goto _L436;
      uVar16 = (uint)*(byte *)(iVar25 + 6);
      uVar6 = (uint)*(ushort *)(iVar25 + 4);
      uVar26 = 3;
      *(undefined4 *)(iVar22 + 0x24) = 0;
      iVar25 = 0;
    }
    cVar1 = *(char *)(iVar22 + 0x91);
    cVar5 = *(char *)(iVar22 + 0x8e) * '\t';
    uVar3 = *(ushort *)(iVar22 + 0x84);
    uVar19 = 0;
    bVar20 = cVar5 + cVar1;
    uVar21 = (uint)bVar20;
    if ((((uVar3 & 0x10) != 0) && (piVar18 != (int *)0x0)) &&
       (uVar19 = 1, *(short *)(iVar22 + 0x82) == 0)) {
      uVar19 = (uint)(*piVar18 != 0);
    }
    if ((uVar3 & 0x40) != 0) {
      uVar16 = uVar16 + 4 & 0xffff;
    }
    if ((int)((uint)uVar3 << 0x12) < 0) {
      uVar12 = 0;
    }
    else {
      uVar12 = uVar19;
      if (uVar19 == 0) {
        uVar12 = uVar3 & 1;
      }
    }
    iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
    iVar24 = uVar21 * 0xe;
    *(ushort *)(iVar7 + iVar24 + 2) = (ushort)(uVar16 << 8) | uVar26 | (ushort)(uVar12 << 4);
    iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
    *(short *)(iVar24 + 4 + iVar7) = (short)uVar6;
    if (-1 < (int)((uint)*(ushort *)(iVar22 + 0x84) << 0x12)) {
      iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
      iVar7 = (uint)(byte)(cVar5 + (cVar1 + 1U & 1)) * 0xe;
      if (-1 < *(short *)(iVar8 + iVar7)) {
        iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
        iVar7 = iVar7 + 2;
        uVar3 = *(ushort *)(iVar8 + iVar7);
        iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
        *(ushort *)(iVar8 + iVar7) = uVar3 | 0x10;
      }
    }
    if (uVar26 == 3) {
      uVar14 = 2;
      if (param_2 == 2) {
        bVar2 = *(byte *)(iVar22 + 0x90);
        *(undefined1 *)(&lld_con_cntl_pkt_info + param_1) = 1;
        *(byte *)((int)&lld_con_cntl_pkt_info + iVar13 + 1) = bVar20;
        if (uVar21 == (uint)bVar2 + param_1 * 9) {
          *(undefined1 *)((int)&lld_con_cntl_pkt_info + iVar13 + 2) = 1;
        }
      }
      else {
        if (param_2 < 3) {
          iVar7 = 6;
          if (param_2 == 0) {
            uVar14 = 1;
            iVar7 = 10;
          }
        }
        else {
          if (param_2 != 0x18) goto _L449;
          uVar14 = 3;
          iVar7 = 3;
        }
        uVar16 = iVar7 + uVar6 & 0xffff;
        (&DAT_00015075)[iVar15] = uVar14;
        (&DAT_00015074)[iVar15] = bVar20;
        puVar9 = (ushort *)r_emi_get_mem_addr_by_offset(uVar16);
        uVar26 = *puVar9;
        uVar3 = *(ushort *)(iVar22 + 0x44);
        if (((uint)uVar3 == (uint)uVar26) &&
           (pbVar10 = (byte *)r_emi_get_mem_addr_by_offset(uVar6), *pbVar10 == param_2)) {
          uVar6 = (uint)*(ushort *)(iVar22 + 0x7c) + (uint)*(ushort *)(iVar22 + 0x7e) + 9 +
                  (uint)*(ushort *)(iVar22 + 0x72);
          iVar7 = uVar6 * 0x10000;
          uVar6 = uVar6 & 0xffff;
          if (((uVar6 + 1) - (uint)uVar3 & 0xffff) < 0x7fff) {
            puVar11 = (undefined1 *)r_emi_get_mem_addr_by_offset(uVar16);
            *puVar11 = (char)((uint)iVar7 >> 0x10);
            puVar11[1] = (char)(uVar6 >> 8);
            *(short *)(iVar22 + 0x44) = (short)((uint)iVar7 >> 0x10);
          }
        }
        else {
          if (0 < _g_bt_plf_log_level) {
            uVar3 = *(ushort *)(iVar22 + 0x7e);
            uVar4 = *(ushort *)(iVar22 + 0x7c);
            puVar11 = (undefined1 *)r_emi_get_mem_addr_by_offset(uVar6);
            ets_printf("llcp prog: %u %u %u %u %u\n",(uint)uVar4 + (uint)uVar3,*puVar11,(uint)uVar26
                       ,*(undefined1 *)(iVar22 + 0x46),*(undefined2 *)(iVar22 + 0x44));
          }
          r_lld_con_llcp_ind_info_clear(param_1);
        }
      }
    }
_L449:
    iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
    uVar3 = *(ushort *)(iVar7 + iVar24);
    iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
    *(ushort *)(iVar24 + iVar7) = uVar3 & 0x7fff;
    *(byte *)(iVar22 + 0x91) = *(char *)(iVar22 + 0x91) + 1U & 1;
    r_lld_con_tx_prog_new_packet_coex(iVar22);
    *(char *)(iVar22 + 0x92) = *(char *)(iVar22 + 0x92) + '\x01';
    iVar7 = r_sdk_config_get_opts_ext();
    if (((*(uint *)(iVar7 + 0x28) & 0x20) != 0) &&
       (iVar7 = r_sdk_config_get_opts_ext(), *(byte *)(iVar7 + 0x2c) < 3)) {
      iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
      r_ble_log_internal_x2
                (0x40e30013,param_2 << 8 | param_1 | uVar21 << 0x10,
                 *(undefined2 *)(iVar7 + iVar24 + 2));
    }
    bVar23 = bVar23 + 1;
  } while( true );
}

