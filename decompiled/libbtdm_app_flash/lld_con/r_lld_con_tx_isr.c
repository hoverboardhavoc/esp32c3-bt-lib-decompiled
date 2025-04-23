/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_tx_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_con_tx_isr(uint param_1)

{
  char cVar1;
  byte bVar2;
  ushort uVar3;
  ushort uVar4;
  bool bVar5;
  char cVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  ushort *puVar10;
  undefined1 *puVar11;
  byte *pbVar12;
  uint uVar13;
  uint uVar14;
  int *piVar15;
  int iVar16;
  undefined1 uVar17;
  int iVar18;
  uint uVar19;
  int *piVar20;
  int iVar21;
  uint uVar22;
  byte bVar23;
  uint uVar24;
  byte bVar25;
  int iVar26;
  int iVar27;
  ushort uVar28;
  
  if (*(int *)(&lld_con_env + param_1 * 4) == 0) {
    r_assert_param(0,"lld_con.c",0xc46);
    return;
  }
  r_lld_con_tx_eco();
  iVar21 = *(int *)(&lld_con_env + param_1 * 4);
  piVar15 = *(int **)(iVar21 + 0x30);
  if (piVar15 == (int *)0x0) {
    piVar15 = *(int **)(iVar21 + 0x28);
    *(int **)(iVar21 + 0x30) = piVar15;
    if (piVar15 != (int *)0x0) {
      *(ushort *)(iVar21 + 0x82) = *(ushort *)((int)piVar15 + 6) & 0x3ff;
    }
  }
  bVar5 = false;
  if ((((*(ushort *)(iVar21 + 0x84) & 0x10) != 0) && (piVar15 != (int *)0x0)) &&
     (bVar5 = true, *(short *)(iVar21 + 0x82) == 0)) {
    bVar5 = *piVar15 != 0;
  }
  iVar16 = *(int *)(iVar21 + 0x24);
  if ((iVar16 != 0) || (bVar5)) {
    if (*(char *)(iVar21 + 0x92) != '\x02') {
      uVar13 = 0x23;
      if (iVar16 != 0) {
        pbVar12 = (byte *)r_emi_get_mem_addr_by_offset(*(undefined2 *)(iVar16 + 4));
        uVar13 = (uint)*pbVar12;
      }
      iVar21 = param_1 * 4;
      iVar16 = *(int *)(&lld_con_env + iVar21);
      iVar27 = *(int *)(iVar16 + 0x24);
      piVar15 = *(int **)(iVar16 + 0x30);
      uVar22 = 0;
      if ((((*(ushort *)(iVar16 + 0x84) & 0x10) != 0) && (piVar15 != (int *)0x0)) &&
         (uVar22 = 1, *(short *)(iVar16 + 0x82) == 0)) {
        uVar22 = (uint)(*piVar15 != 0);
      }
      bVar25 = *(byte *)(iVar16 + 0x92);
      iVar18 = (param_1 + 0x18) * 2;
      do {
        if (1 < bVar25) {
          return;
        }
        if (iVar27 == 0) {
          if (uVar22 == 0) {
            return;
          }
_L436:
          uVar22 = (uint)*(ushort *)(iVar16 + 0x82);
          if ((uVar22 == 0) && (piVar20 = (int *)*piVar15, piVar20 != (int *)0x0)) {
            uVar4 = *(ushort *)((int)piVar20 + 6);
            *(int **)(iVar16 + 0x30) = piVar20;
            uVar22 = uVar4 & 0x3ff;
            piVar15 = piVar20;
          }
          uVar4 = *(ushort *)((int)piVar15 + 6);
          uVar7 = (*(ushort *)(piVar15 + 1) - uVar22) + (uVar4 & 0x3ff) & 0xffff;
          uVar28 = ((uVar4 & 0x3000) != 0x1000) + 1;
          uVar19 = (uint)*(byte *)(iVar16 + 0x8c);
          if (uVar22 < *(byte *)(iVar16 + 0x8c)) {
            uVar19 = uVar22;
          }
          *(ushort *)((int)piVar15 + 6) = uVar4 & 0xcfff | 0x1000;
          *(short *)(iVar16 + 0x82) = (short)uVar22 - (short)uVar19;
        }
        else {
          if ((((uVar13 == 2) && (uVar22 != 0)) && (bVar25 != 1)) && (sdk_cfg_priv_opts != '\0'))
          goto _L436;
          uVar19 = (uint)*(byte *)(iVar27 + 6);
          uVar7 = (uint)*(ushort *)(iVar27 + 4);
          uVar28 = 3;
          *(undefined4 *)(iVar16 + 0x24) = 0;
          iVar27 = 0;
        }
        cVar1 = *(char *)(iVar16 + 0x91);
        cVar6 = *(char *)(iVar16 + 0x8e) * '\t';
        uVar4 = *(ushort *)(iVar16 + 0x84);
        uVar22 = 0;
        bVar23 = cVar6 + cVar1;
        uVar24 = (uint)bVar23;
        if ((((uVar4 & 0x10) != 0) && (piVar15 != (int *)0x0)) &&
           (uVar22 = 1, *(short *)(iVar16 + 0x82) == 0)) {
          uVar22 = (uint)(*piVar15 != 0);
        }
        if ((uVar4 & 0x40) != 0) {
          uVar19 = uVar19 + 4 & 0xffff;
        }
        if ((int)((uint)uVar4 << 0x12) < 0) {
          uVar14 = 0;
        }
        else {
          uVar14 = uVar22;
          if (uVar22 == 0) {
            uVar14 = uVar4 & 1;
          }
        }
        iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
        iVar26 = uVar24 * 0xe;
        *(ushort *)(iVar8 + iVar26 + 2) = (ushort)(uVar19 << 8) | uVar28 | (ushort)(uVar14 << 4);
        iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
        *(short *)(iVar26 + 4 + iVar8) = (short)uVar7;
        if (-1 < (int)((uint)*(ushort *)(iVar16 + 0x84) << 0x12)) {
          iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
          iVar8 = (uint)(byte)(cVar6 + (cVar1 + 1U & 1)) * 0xe;
          if (-1 < *(short *)(iVar9 + iVar8)) {
            iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
            iVar8 = iVar8 + 2;
            uVar4 = *(ushort *)(iVar9 + iVar8);
            iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
            *(ushort *)(iVar9 + iVar8) = uVar4 | 0x10;
          }
        }
        if (uVar28 == 3) {
          uVar17 = 2;
          if (uVar13 == 2) {
            bVar2 = *(byte *)(iVar16 + 0x90);
            *(undefined1 *)(&lld_con_cntl_pkt_info + param_1) = 1;
            *(byte *)((int)&lld_con_cntl_pkt_info + iVar21 + 1) = bVar23;
            if (uVar24 == (uint)bVar2 + param_1 * 9) {
              *(undefined1 *)((int)&lld_con_cntl_pkt_info + iVar21 + 2) = 1;
            }
          }
          else {
            if (uVar13 < 3) {
              iVar8 = 6;
              if (uVar13 == 0) {
                uVar17 = 1;
                iVar8 = 10;
              }
            }
            else {
              if (uVar13 != 0x18) goto _L449;
              uVar17 = 3;
              iVar8 = 3;
            }
            uVar19 = iVar8 + uVar7 & 0xffff;
            (&DAT_00015075)[iVar18] = uVar17;
            (&DAT_00015074)[iVar18] = bVar23;
            puVar10 = (ushort *)r_emi_get_mem_addr_by_offset(uVar19);
            uVar28 = *puVar10;
            uVar4 = *(ushort *)(iVar16 + 0x44);
            if (((uint)uVar4 == (uint)uVar28) &&
               (pbVar12 = (byte *)r_emi_get_mem_addr_by_offset(uVar7), *pbVar12 == uVar13)) {
              uVar7 = (uint)*(ushort *)(iVar16 + 0x7c) + (uint)*(ushort *)(iVar16 + 0x7e) + 9 +
                      (uint)*(ushort *)(iVar16 + 0x72);
              iVar8 = uVar7 * 0x10000;
              uVar7 = uVar7 & 0xffff;
              if (((uVar7 + 1) - (uint)uVar4 & 0xffff) < 0x7fff) {
                puVar11 = (undefined1 *)r_emi_get_mem_addr_by_offset(uVar19);
                *puVar11 = (char)((uint)iVar8 >> 0x10);
                puVar11[1] = (char)(uVar7 >> 8);
                *(short *)(iVar16 + 0x44) = (short)((uint)iVar8 >> 0x10);
              }
            }
            else {
              if (0 < _g_bt_plf_log_level) {
                uVar4 = *(ushort *)(iVar16 + 0x7e);
                uVar3 = *(ushort *)(iVar16 + 0x7c);
                puVar11 = (undefined1 *)r_emi_get_mem_addr_by_offset(uVar7);
                ets_printf("llcp prog: %u %u %u %u %u\n",(uint)uVar3 + (uint)uVar4,*puVar11,
                           (uint)uVar28,*(undefined1 *)(iVar16 + 0x46),
                           *(undefined2 *)(iVar16 + 0x44));
              }
              r_lld_con_llcp_ind_info_clear(param_1);
            }
          }
        }
_L449:
        iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
        uVar4 = *(ushort *)(iVar8 + iVar26);
        iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
        *(ushort *)(iVar26 + iVar8) = uVar4 & 0x7fff;
        *(byte *)(iVar16 + 0x91) = *(char *)(iVar16 + 0x91) + 1U & 1;
        r_lld_con_tx_prog_new_packet_coex(iVar16);
        *(char *)(iVar16 + 0x92) = *(char *)(iVar16 + 0x92) + '\x01';
        iVar8 = r_sdk_config_get_opts_ext();
        if (((*(uint *)(iVar8 + 0x28) & 0x20) != 0) &&
           (iVar8 = r_sdk_config_get_opts_ext(), *(byte *)(iVar8 + 0x2c) < 3)) {
          iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
          r_ble_log_internal_x2
                    (0x40e30013,uVar13 << 8 | param_1 | uVar24 << 0x10,
                     *(undefined2 *)(iVar8 + iVar26 + 2));
        }
        bVar25 = bVar25 + 1;
      } while( true );
    }
    bVar25 = *(byte *)(iVar21 + 0x91);
    bVar23 = *(byte *)(iVar21 + 0x8e);
    iVar16 = r_emi_get_mem_addr_by_offset(0x1400);
    iVar21 = ((bVar25 + 1 & 1) + (uint)bVar23 * 9 & 0xff) * 0xe;
    if (-1 < *(short *)(iVar16 + iVar21)) {
      iVar16 = r_emi_get_mem_addr_by_offset(0x1400);
      iVar21 = iVar21 + 2;
      uVar4 = *(ushort *)(iVar16 + iVar21);
      iVar16 = r_emi_get_mem_addr_by_offset(0x1400);
      *(ushort *)(iVar16 + iVar21) = uVar4 | 0x10;
    }
  }
  return;
}

