/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
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
  ushort *puVar9;
  undefined1 *puVar10;
  byte *pbVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  undefined1 uVar15;
  int iVar16;
  uint uVar17;
  int *piVar18;
  int iVar19;
  int *piVar20;
  ushort uVar21;
  byte bVar22;
  uint uVar23;
  byte bVar24;
  int iVar25;
  int iVar26;
  int iStack_68;
  uint uStack_64;
  
  if (*(int *)(&lld_con_env + param_1 * 4) == 0) {
    r_assert_param(0,"lld_con.c",0xc46);
    return;
  }
  r_lld_con_tx_eco();
  iVar19 = *(int *)(&lld_con_env + param_1 * 4);
  if (*(int *)(iVar19 + 0x30) == 0) {
    iVar14 = *(int *)(iVar19 + 0x28);
    *(int *)(iVar19 + 0x30) = iVar14;
    if (iVar14 != 0) {
      *(ushort *)(iVar19 + 0x82) = *(ushort *)(iVar14 + 6) & 0x3ff;
    }
  }
  bVar5 = false;
  if ((((*(ushort *)(iVar19 + 0x84) & 0x10) != 0) && (*(int **)(iVar19 + 0x30) != (int *)0x0)) &&
     (bVar5 = true, *(short *)(iVar19 + 0x82) == 0)) {
    bVar5 = **(int **)(iVar19 + 0x30) != 0;
  }
  iVar14 = *(int *)(iVar19 + 0x24);
  if ((iVar14 != 0) || (bVar5)) {
    if (*(char *)(iVar19 + 0x92) != '\x02') {
      uVar12 = 0x23;
      if (iVar14 != 0) {
        pbVar11 = (byte *)r_emi_get_mem_addr_by_offset(*(undefined2 *)(iVar14 + 4));
        uVar12 = (uint)*pbVar11;
      }
      iVar19 = param_1 * 4;
      iVar14 = *(int *)(&lld_con_env + iVar19);
      iStack_68 = *(int *)(iVar14 + 0x24);
      piVar20 = *(int **)(iVar14 + 0x30);
      uStack_64 = 0;
      if ((((*(ushort *)(iVar14 + 0x84) & 0x10) != 0) && (piVar20 != (int *)0x0)) &&
         (uStack_64 = 1, *(short *)(iVar14 + 0x82) == 0)) {
        uStack_64 = (uint)(*piVar20 != 0);
      }
      bVar24 = *(byte *)(iVar14 + 0x92);
      iVar16 = (param_1 + 0x18) * 2;
      do {
        if (1 < bVar24) {
          return;
        }
        if (iStack_68 == 0) {
          if (uStack_64 == 0) {
            return;
          }
_L436:
          if ((*(short *)(iVar14 + 0x82) == 0) && (piVar18 = (int *)*piVar20, piVar18 != (int *)0x0)
             ) {
            uVar4 = *(ushort *)((int)piVar18 + 6);
            *(int **)(iVar14 + 0x30) = piVar18;
            *(ushort *)(iVar14 + 0x82) = uVar4 & 0x3ff;
            piVar20 = piVar18;
          }
          uVar4 = *(ushort *)((int)piVar20 + 6);
          uVar3 = *(ushort *)(iVar14 + 0x82);
          uVar23 = (uint)uVar3;
          uVar7 = (*(ushort *)(piVar20 + 1) - uVar23) + (uVar4 & 0x3ff) & 0xffff;
          uVar21 = 2;
          if (((int)(uint)uVar4 >> 0xc & 3U) == 1) {
            uVar21 = 1;
          }
          uVar17 = (uint)*(byte *)(iVar14 + 0x8c);
          if (uVar23 < *(byte *)(iVar14 + 0x8c)) {
            uVar17 = uVar23;
          }
          *(ushort *)((int)piVar20 + 6) = uVar4 & 0xcfff | 0x1000;
          *(ushort *)(iVar14 + 0x82) = uVar3 - (short)uVar17;
        }
        else {
          if ((((uVar12 == 2) && (uStack_64 != 0)) && (bVar24 != 1)) && (DAT_0001608e != '\0'))
          goto _L436;
          uVar21 = 3;
          uVar17 = (uint)*(byte *)(iStack_68 + 6);
          uVar7 = (uint)*(ushort *)(iStack_68 + 4);
          iStack_68 = 0;
          *(undefined4 *)(iVar14 + 0x24) = 0;
        }
        cVar1 = *(char *)(iVar14 + 0x91);
        cVar6 = *(char *)(iVar14 + 0x8e) * '\t';
        uVar4 = *(ushort *)(iVar14 + 0x84);
        uStack_64 = 0;
        bVar22 = cVar6 + cVar1;
        uVar23 = (uint)bVar22;
        if ((((uVar4 & 0x10) != 0) && (piVar20 != (int *)0x0)) &&
           (uStack_64 = 1, *(short *)(iVar14 + 0x82) == 0)) {
          uStack_64 = (uint)(*piVar20 != 0);
        }
        if ((uVar4 & 0x40) != 0) {
          uVar17 = uVar17 + 4 & 0xffff;
        }
        if ((uVar4 & 0x2000) == 0) {
          uVar13 = uStack_64;
          if (uStack_64 == 0) {
            uVar13 = uVar4 & 1;
          }
        }
        else {
          uVar13 = 0;
        }
        iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
        iVar25 = uVar23 * 0xe;
        *(ushort *)(iVar8 + iVar25 + 2) =
             (ushort)((uVar17 & 0xff) << 8) | uVar21 | (ushort)(uVar13 << 4);
        iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
        *(short *)(iVar25 + 4 + iVar8) = (short)uVar7;
        if ((*(ushort *)(iVar14 + 0x84) & 0x2000) == 0) {
          iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
          iVar26 = (uint)(byte)((cVar1 + 1U & 1) + cVar6) * 0xe;
          if (-1 < *(short *)(iVar8 + iVar26)) {
            iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
            iVar26 = iVar26 + 2;
            uVar4 = *(ushort *)(iVar8 + iVar26);
            iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
            *(ushort *)(iVar8 + iVar26) = uVar4 & 0xffef | 0x10;
          }
        }
        if (uVar21 == 3) {
          if (uVar12 == 2) {
            bVar2 = *(byte *)(iVar14 + 0x90);
            *(undefined1 *)(&lld_con_cntl_pkt_info + param_1) = 1;
            *(byte *)((int)&lld_con_cntl_pkt_info + iVar19 + 1) = bVar22;
            if (uVar23 == (uint)bVar2 + param_1 * 9) {
              *(undefined1 *)((int)&lld_con_cntl_pkt_info + iVar19 + 2) = 1;
            }
          }
          else {
            if (uVar12 < 3) {
              if (uVar12 == 0) {
                uVar15 = 1;
                iVar8 = 10;
              }
              else {
                uVar15 = 2;
                iVar8 = 6;
              }
            }
            else {
              if (uVar12 != 0x18) goto _L449;
              uVar15 = 3;
              iVar8 = 3;
            }
            uVar17 = uVar7 + iVar8 & 0xffff;
            (&DAT_0001503d)[iVar16] = uVar15;
            (&DAT_0001503c)[iVar16] = bVar22;
            puVar9 = (ushort *)r_emi_get_mem_addr_by_offset(uVar17);
            uVar3 = *puVar9;
            uVar4 = *(ushort *)(iVar14 + 0x44);
            if (((uint)uVar4 == (uint)uVar3) &&
               (pbVar11 = (byte *)r_emi_get_mem_addr_by_offset(uVar7), *pbVar11 == uVar12)) {
              uVar7 = (uint)*(ushort *)(iVar14 + 0x7c) + (uint)*(ushort *)(iVar14 + 0x7e) + 9 +
                      (uint)*(ushort *)(iVar14 + 0x72);
              iVar8 = uVar7 * 0x10000;
              uVar7 = uVar7 & 0xffff;
              if (((uVar7 + 1) - (uint)uVar4 & 0xffff) < 0x7fff) {
                puVar10 = (undefined1 *)r_emi_get_mem_addr_by_offset(uVar17);
                *puVar10 = (char)((uint)iVar8 >> 0x10);
                puVar10[1] = (char)(uVar7 >> 8);
                *(short *)(iVar14 + 0x44) = (short)((uint)iVar8 >> 0x10);
              }
            }
            else {
              if (0 < _g_bt_plf_log_level) {
                uVar4 = *(ushort *)(iVar14 + 0x7e);
                uVar21 = *(ushort *)(iVar14 + 0x7c);
                puVar10 = (undefined1 *)r_emi_get_mem_addr_by_offset(uVar7);
                ets_printf("llcp prog: %u %u %u %u %u\n",(uint)uVar21 + (uint)uVar4,*puVar10,
                           (uint)uVar3,*(undefined1 *)(iVar14 + 0x46),*(undefined2 *)(iVar14 + 0x44)
                          );
              }
              r_lld_con_llcp_ind_info_clear(param_1);
            }
          }
        }
_L449:
        iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
        uVar4 = *(ushort *)(iVar8 + iVar25);
        iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
        *(ushort *)(iVar25 + iVar8) = (ushort)(((uint)uVar4 << 0x11) >> 0x11);
        *(byte *)(iVar14 + 0x91) = *(char *)(iVar14 + 0x91) + 1U & 1;
        r_lld_con_tx_prog_new_packet_coex(iVar14);
        *(char *)(iVar14 + 0x92) = *(char *)(iVar14 + 0x92) + '\x01';
        iVar8 = r_sdk_config_get_opts_ext();
        if (((*(uint *)(iVar8 + 0x28) & 0x20) != 0) &&
           (iVar8 = r_sdk_config_get_opts_ext(), *(byte *)(iVar8 + 0x2c) < 3)) {
          iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
          r_ble_log_internal_x2
                    (0x40e30013,uVar23 << 0x10 | uVar12 << 8 | param_1,
                     *(undefined2 *)(iVar8 + iVar25 + 2));
        }
        bVar24 = bVar24 + 1;
      } while( true );
    }
    bVar24 = *(byte *)(iVar19 + 0x91);
    bVar22 = *(byte *)(iVar19 + 0x8e);
    iVar14 = r_emi_get_mem_addr_by_offset(0x1400);
    iVar19 = ((bVar24 + 1 & 1) + (uint)bVar22 * 9 & 0xff) * 0xe;
    if (-1 < *(short *)(iVar14 + iVar19)) {
      iVar14 = r_emi_get_mem_addr_by_offset(0x1400);
      iVar19 = iVar19 + 2;
      uVar4 = *(ushort *)(iVar14 + iVar19);
      iVar14 = r_emi_get_mem_addr_by_offset(0x1400);
      *(ushort *)(iVar19 + iVar14) = uVar4 & 0xffef | 0x10;
    }
  }
  return;
}

