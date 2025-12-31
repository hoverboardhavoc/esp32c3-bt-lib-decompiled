/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
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
  undefined2 uVar5;
  char cVar6;
  uint uVar7;
  int iVar8;
  ushort *puVar9;
  byte *pbVar10;
  undefined1 *puVar11;
  int iVar12;
  uint uVar13;
  undefined1 uVar14;
  int iVar15;
  uint uVar16;
  int *piVar17;
  int *piVar18;
  ushort uVar19;
  byte bVar20;
  uint uVar21;
  byte bVar22;
  int iVar23;
  int iVar24;
  int iVar25;
  int local_70;
  uint uStack_6c;
  
  iVar12 = param_1 * 4;
  iVar25 = *(int *)(&lld_con_env + iVar12);
  local_70 = *(int *)(iVar25 + 0x24);
  piVar18 = *(int **)(iVar25 + 0x30);
  uStack_6c = 0;
  if ((((*(ushort *)(iVar25 + 0x84) & 0x10) != 0) && (piVar18 != (int *)0x0)) &&
     (uStack_6c = 1, *(short *)(iVar25 + 0x82) == 0)) {
    uStack_6c = (uint)(*piVar18 != 0);
  }
  bVar22 = *(byte *)(iVar25 + 0x92);
  iVar15 = (param_1 + 0x18) * 2;
  do {
    if (1 < bVar22) {
      return;
    }
    if (local_70 == 0) {
      if (uStack_6c == 0) {
        return;
      }
_L399:
      if ((*(short *)(iVar25 + 0x82) == 0) && (piVar17 = (int *)*piVar18, piVar17 != (int *)0x0)) {
        uVar3 = *(ushort *)((int)piVar17 + 6);
        *(int **)(iVar25 + 0x30) = piVar17;
        *(ushort *)(iVar25 + 0x82) = uVar3 & 0x3ff;
        piVar18 = piVar17;
      }
      uVar3 = *(ushort *)((int)piVar18 + 6);
      uVar4 = *(ushort *)(iVar25 + 0x82);
      uVar21 = (uint)uVar4;
      uVar7 = (*(ushort *)(piVar18 + 1) - uVar21) + (uVar3 & 0x3ff) & 0xffff;
      uVar19 = 2;
      if (((int)(uint)uVar3 >> 0xc & 3U) == 1) {
        uVar19 = 1;
      }
      uVar16 = (uint)*(byte *)(iVar25 + 0x8c);
      if (uVar21 < *(byte *)(iVar25 + 0x8c)) {
        uVar16 = uVar21;
      }
      *(ushort *)((int)piVar18 + 6) = uVar3 & 0xcfff | 0x1000;
      *(ushort *)(iVar25 + 0x82) = uVar4 - (short)uVar16;
    }
    else {
      if (((param_2 == 2) && (uStack_6c != 0)) && ((bVar22 != 1 && (DAT_00016092 != '\0'))))
      goto _L399;
      uVar19 = 3;
      uVar16 = (uint)*(byte *)(local_70 + 6);
      uVar7 = (uint)*(ushort *)(local_70 + 4);
      local_70 = 0;
      *(undefined4 *)(iVar25 + 0x24) = 0;
    }
    cVar1 = *(char *)(iVar25 + 0x91);
    cVar6 = *(char *)(iVar25 + 0x8e) * '\t';
    uVar3 = *(ushort *)(iVar25 + 0x84);
    uStack_6c = 0;
    bVar20 = cVar6 + cVar1;
    uVar21 = (uint)bVar20;
    if ((((uVar3 & 0x10) != 0) && (piVar18 != (int *)0x0)) &&
       (uStack_6c = 1, *(short *)(iVar25 + 0x82) == 0)) {
      uStack_6c = (uint)(*piVar18 != 0);
    }
    if ((uVar3 & 0x40) != 0) {
      uVar16 = uVar16 + 4 & 0xffff;
    }
    if ((uVar3 & 0x2000) == 0) {
      uVar13 = uStack_6c;
      if (uStack_6c == 0) {
        uVar13 = uVar3 & 1;
      }
    }
    else {
      uVar13 = 0;
    }
    iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
    iVar23 = uVar21 * 0xe;
    *(ushort *)(iVar8 + iVar23 + 2) =
         (ushort)((uVar16 & 0xff) << 8) | uVar19 | (ushort)(uVar13 << 4);
    iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
    *(short *)(iVar23 + 4 + iVar8) = (short)uVar7;
    if ((*(ushort *)(iVar25 + 0x84) & 0x2000) == 0) {
      iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
      iVar24 = (uint)(byte)((cVar1 + 1U & 1) + cVar6) * 0xe;
      if (-1 < *(short *)(iVar8 + iVar24)) {
        iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
        iVar24 = iVar24 + 2;
        uVar3 = *(ushort *)(iVar8 + iVar24);
        iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
        *(ushort *)(iVar8 + iVar24) = uVar3 & 0xffef | 0x10;
      }
    }
    if (uVar19 == 3) {
      if (param_2 == 2) {
        bVar2 = *(byte *)(iVar25 + 0x90);
        *(undefined1 *)(&lld_con_cntl_pkt_info + param_1) = 1;
        *(byte *)((int)&lld_con_cntl_pkt_info + iVar12 + 1) = bVar20;
        if (uVar21 == (uint)bVar2 + param_1 * 9) {
          *(undefined1 *)((int)&lld_con_cntl_pkt_info + iVar12 + 2) = 1;
        }
      }
      else {
        if (param_2 < 3) {
          if (param_2 == 0) {
            uVar14 = 1;
            iVar8 = 10;
          }
          else {
            uVar14 = 2;
            iVar8 = 6;
          }
        }
        else {
          if (param_2 != 0x18) goto _L412;
          uVar14 = 3;
          iVar8 = 3;
        }
        uVar16 = uVar7 + iVar8 & 0xffff;
        (&DAT_0001507d)[iVar15] = uVar14;
        (&DAT_0001507c)[iVar15] = bVar20;
        puVar9 = (ushort *)r_emi_get_mem_addr_by_offset(uVar16);
        uVar3 = *puVar9;
        uVar13 = (uint)*(ushort *)(iVar25 + 0x44);
        if ((uVar13 == uVar3) &&
           (pbVar10 = (byte *)r_emi_get_mem_addr_by_offset(uVar7), *pbVar10 == param_2)) {
          uVar7 = (uint)*(ushort *)(iVar25 + 0x7c) + (uint)*(ushort *)(iVar25 + 0x7e) + 9 +
                  (uint)*(ushort *)(iVar25 + 0x72);
          iVar8 = uVar7 * 0x10000;
          uVar7 = uVar7 & 0xffff;
          if (((uVar7 + 1) - uVar13 & 0xffff) < 0x7fff) {
            puVar11 = (undefined1 *)r_emi_get_mem_addr_by_offset(uVar16);
            *puVar11 = (char)((uint)iVar8 >> 0x10);
            puVar11[1] = (char)(uVar7 >> 8);
            *(short *)(iVar25 + 0x44) = (short)((uint)iVar8 >> 0x10);
            r_ble_log_internal_x2(0x40a300dc,uVar7 << 0x10 | uVar13,param_2 << 8 | param_1);
          }
        }
        else {
          if (0 < _g_bt_plf_log_level) {
            uVar4 = *(ushort *)(iVar25 + 0x7e);
            uVar19 = *(ushort *)(iVar25 + 0x7c);
            puVar11 = (undefined1 *)r_emi_get_mem_addr_by_offset(uVar7);
            ets_printf("llcp prog: %u %u %u %u %u\n",(uint)uVar19 + (uint)uVar4,*puVar11,(uint)uVar3
                       ,*(undefined1 *)(iVar25 + 0x46),*(undefined2 *)(iVar25 + 0x44));
          }
          uVar5 = *(undefined2 *)(iVar25 + 0x44);
          bVar20 = *(byte *)(iVar25 + 0x46);
          pbVar10 = (byte *)r_emi_get_mem_addr_by_offset(uVar7);
          r_ble_log_internal_x2
                    (0x80a300dd,CONCAT22(uVar5,uVar3),
                     (uint)*pbVar10 << 0x18 | (uint)bVar20 << 8 | param_2 << 0x10 | param_1);
          r_lld_con_llcp_ind_info_clear(param_1);
        }
      }
    }
_L412:
    iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
    uVar3 = *(ushort *)(iVar8 + iVar23);
    iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
    *(ushort *)(iVar23 + iVar8) = (ushort)(((uint)uVar3 << 0x11) >> 0x11);
    bVar22 = bVar22 + 1;
    *(byte *)(iVar25 + 0x91) = *(char *)(iVar25 + 0x91) + 1U & 1;
    r_lld_con_tx_prog_new_packet_coex(iVar25);
    *(char *)(iVar25 + 0x92) = *(char *)(iVar25 + 0x92) + '\x01';
    iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
    r_ble_log_internal_x2
              (0x40e300de,(uint)*(ushort *)(iVar8 + iVar23 + 2) | param_1 << 0x10 | param_2 << 0x18,
               uVar21);
  } while( true );
}

