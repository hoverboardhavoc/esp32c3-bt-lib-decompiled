/*
 * Last changed at upstream commit 72599d583c232ea78d6461b5b502426c6e5a1ec9
 * https://github.com/espressif/esp32c3-bt-lib/commit/72599d583c232ea78d6461b5b502426c6e5a1ec9
 * Upstream date: 2025-05-19 16:27:45 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(6cfabcd8)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_tx_prog_new_packet_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_con_tx_prog_new_packet_hack(uint param_1,uint param_2)

{
  char cVar1;
  byte bVar2;
  ushort uVar3;
  ushort uVar4;
  char cVar5;
  uint uVar6;
  int iVar7;
  ushort *puVar8;
  byte *pbVar9;
  undefined1 *puVar10;
  int iVar11;
  uint uVar12;
  undefined1 uVar13;
  int iVar14;
  uint uVar15;
  int *piVar16;
  int *piVar17;
  ushort uVar18;
  byte bVar19;
  uint uVar20;
  byte bVar21;
  int iVar22;
  int iVar23;
  int iVar24;
  int iStack_68;
  uint uStack_64;
  
  iVar11 = param_1 * 4;
  iVar24 = *(int *)(&lld_con_env + iVar11);
  iStack_68 = *(int *)(iVar24 + 0x24);
  piVar17 = *(int **)(iVar24 + 0x30);
  uStack_64 = 0;
  if ((((*(ushort *)(iVar24 + 0x84) & 0x10) != 0) && (piVar17 != (int *)0x0)) &&
     (uStack_64 = 1, *(short *)(iVar24 + 0x82) == 0)) {
    uStack_64 = (uint)(*piVar17 != 0);
  }
  bVar21 = *(byte *)(iVar24 + 0x92);
  iVar14 = (param_1 + 0x18) * 2;
  do {
    if (1 < bVar21) {
      return;
    }
    if (iStack_68 == 0) {
      if (uStack_64 == 0) {
        return;
      }
_L436:
      if ((*(short *)(iVar24 + 0x82) == 0) && (piVar16 = (int *)*piVar17, piVar16 != (int *)0x0)) {
        uVar3 = *(ushort *)((int)piVar16 + 6);
        *(int **)(iVar24 + 0x30) = piVar16;
        *(ushort *)(iVar24 + 0x82) = uVar3 & 0x3ff;
        piVar17 = piVar16;
      }
      uVar3 = *(ushort *)((int)piVar17 + 6);
      uVar4 = *(ushort *)(iVar24 + 0x82);
      uVar20 = (uint)uVar4;
      uVar6 = (*(ushort *)(piVar17 + 1) - uVar20) + (uVar3 & 0x3ff) & 0xffff;
      uVar18 = 2;
      if (((int)(uint)uVar3 >> 0xc & 3U) == 1) {
        uVar18 = 1;
      }
      uVar15 = (uint)*(byte *)(iVar24 + 0x8c);
      if (uVar20 < *(byte *)(iVar24 + 0x8c)) {
        uVar15 = uVar20;
      }
      *(ushort *)((int)piVar17 + 6) = uVar3 & 0xcfff | 0x1000;
      *(ushort *)(iVar24 + 0x82) = uVar4 - (short)uVar15;
    }
    else {
      if (((param_2 == 2) && (uStack_64 != 0)) && ((bVar21 != 1 && (DAT_0001608e != '\0'))))
      goto _L436;
      uVar18 = 3;
      uVar15 = (uint)*(byte *)(iStack_68 + 6);
      uVar6 = (uint)*(ushort *)(iStack_68 + 4);
      iStack_68 = 0;
      *(undefined4 *)(iVar24 + 0x24) = 0;
    }
    cVar1 = *(char *)(iVar24 + 0x91);
    cVar5 = *(char *)(iVar24 + 0x8e) * '\t';
    uVar3 = *(ushort *)(iVar24 + 0x84);
    uStack_64 = 0;
    bVar19 = cVar5 + cVar1;
    uVar20 = (uint)bVar19;
    if ((((uVar3 & 0x10) != 0) && (piVar17 != (int *)0x0)) &&
       (uStack_64 = 1, *(short *)(iVar24 + 0x82) == 0)) {
      uStack_64 = (uint)(*piVar17 != 0);
    }
    if ((uVar3 & 0x40) != 0) {
      uVar15 = uVar15 + 4 & 0xffff;
    }
    if ((uVar3 & 0x2000) == 0) {
      uVar12 = uStack_64;
      if (uStack_64 == 0) {
        uVar12 = uVar3 & 1;
      }
    }
    else {
      uVar12 = 0;
    }
    iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
    iVar22 = uVar20 * 0xe;
    *(ushort *)(iVar7 + iVar22 + 2) =
         (ushort)((uVar15 & 0xff) << 8) | uVar18 | (ushort)(uVar12 << 4);
    iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
    *(short *)(iVar22 + 4 + iVar7) = (short)uVar6;
    if ((*(ushort *)(iVar24 + 0x84) & 0x2000) == 0) {
      iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
      iVar23 = (uint)(byte)((cVar1 + 1U & 1) + cVar5) * 0xe;
      if (-1 < *(short *)(iVar7 + iVar23)) {
        iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
        iVar23 = iVar23 + 2;
        uVar3 = *(ushort *)(iVar7 + iVar23);
        iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
        *(ushort *)(iVar7 + iVar23) = uVar3 & 0xffef | 0x10;
      }
    }
    if (uVar18 == 3) {
      if (param_2 == 2) {
        bVar2 = *(byte *)(iVar24 + 0x90);
        *(undefined1 *)(&lld_con_cntl_pkt_info + param_1) = 1;
        *(byte *)((int)&lld_con_cntl_pkt_info + iVar11 + 1) = bVar19;
        if (uVar20 == (uint)bVar2 + param_1 * 9) {
          *(undefined1 *)((int)&lld_con_cntl_pkt_info + iVar11 + 2) = 1;
        }
      }
      else {
        if (param_2 < 3) {
          if (param_2 == 0) {
            uVar13 = 1;
            iVar7 = 10;
          }
          else {
            uVar13 = 2;
            iVar7 = 6;
          }
        }
        else {
          if (param_2 != 0x18) goto _L449;
          uVar13 = 3;
          iVar7 = 3;
        }
        uVar15 = uVar6 + iVar7 & 0xffff;
        (&DAT_0001503d)[iVar14] = uVar13;
        (&DAT_0001503c)[iVar14] = bVar19;
        puVar8 = (ushort *)r_emi_get_mem_addr_by_offset(uVar15);
        uVar4 = *puVar8;
        uVar3 = *(ushort *)(iVar24 + 0x44);
        if (((uint)uVar3 == (uint)uVar4) &&
           (pbVar9 = (byte *)r_emi_get_mem_addr_by_offset(uVar6), *pbVar9 == param_2)) {
          uVar6 = (uint)*(ushort *)(iVar24 + 0x7c) + (uint)*(ushort *)(iVar24 + 0x7e) + 9 +
                  (uint)*(ushort *)(iVar24 + 0x72);
          iVar7 = uVar6 * 0x10000;
          uVar6 = uVar6 & 0xffff;
          if (((uVar6 + 1) - (uint)uVar3 & 0xffff) < 0x7fff) {
            puVar10 = (undefined1 *)r_emi_get_mem_addr_by_offset(uVar15);
            *puVar10 = (char)((uint)iVar7 >> 0x10);
            puVar10[1] = (char)(uVar6 >> 8);
            *(short *)(iVar24 + 0x44) = (short)((uint)iVar7 >> 0x10);
          }
        }
        else {
          if (0 < _g_bt_plf_log_level) {
            uVar3 = *(ushort *)(iVar24 + 0x7e);
            uVar18 = *(ushort *)(iVar24 + 0x7c);
            puVar10 = (undefined1 *)r_emi_get_mem_addr_by_offset(uVar6);
            ets_printf("llcp prog: %u %u %u %u %u\n",(uint)uVar18 + (uint)uVar3,*puVar10,(uint)uVar4
                       ,*(undefined1 *)(iVar24 + 0x46),*(undefined2 *)(iVar24 + 0x44));
          }
          r_lld_con_llcp_ind_info_clear(param_1);
        }
      }
    }
_L449:
    iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
    uVar3 = *(ushort *)(iVar7 + iVar22);
    iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
    *(ushort *)(iVar22 + iVar7) = (ushort)(((uint)uVar3 << 0x11) >> 0x11);
    *(byte *)(iVar24 + 0x91) = *(char *)(iVar24 + 0x91) + 1U & 1;
    r_lld_con_tx_prog_new_packet_coex(iVar24);
    *(char *)(iVar24 + 0x92) = *(char *)(iVar24 + 0x92) + '\x01';
    iVar7 = r_sdk_config_get_opts_ext();
    if (((*(uint *)(iVar7 + 0x28) & 0x20) != 0) &&
       (iVar7 = r_sdk_config_get_opts_ext(), *(byte *)(iVar7 + 0x2c) < 3)) {
      iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
      r_ble_log_internal_x2
                (0x40e30013,uVar20 << 0x10 | param_2 << 8 | param_1,
                 *(undefined2 *)(iVar7 + iVar22 + 2));
    }
    bVar21 = bVar21 + 1;
  } while( true );
}

