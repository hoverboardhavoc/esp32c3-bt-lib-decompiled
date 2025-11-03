/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> lld_scan.o -> r_lld_scan_process_pkt_rx_ext_adv
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_scan_process_pkt_rx_ext_adv(int param_1,uint param_2,int param_3,char *param_4)

{
  bool bVar1;
  short sVar2;
  undefined2 uVar3;
  byte *pbVar4;
  void *pvVar5;
  undefined2 *puVar6;
  undefined1 *puVar7;
  short *psVar8;
  byte *pbVar9;
  int iVar10;
  undefined1 uVar11;
  byte bVar12;
  char cVar13;
  ushort uVar14;
  short sVar15;
  uint uVar16;
  uint uVar17;
  int iVar18;
  int iVar19;
  short sVar20;
  int iVar21;
  ushort uVar22;
  uint unaff_s7;
  undefined4 auStack_44 [4];
  undefined4 in_stack_ffffffcc;
  
  if (param_2 < 7) {
    return;
  }
  iVar19 = *(int *)(_lld_scan_env + param_1 * 4);
  iVar21 = param_3 * 0x14 + 0x10;
  iVar10 = r_emi_get_mem_addr_by_offset(0x1000);
  iVar18 = param_3 * 0x14 + 4;
  uVar22 = *(ushort *)(iVar10 + iVar21) & 0x3f;
  *param_4 = (char)uVar22;
  iVar10 = r_emi_get_mem_addr_by_offset(0x1000);
  if (*(ushort *)(iVar10 + iVar18) >> 8 <= uVar22) {
    r_assert_err(0,"lld_scan.c",0x857);
  }
  cVar13 = *param_4;
  if (cVar13 != '\0') {
    cVar13 = cVar13 + -1;
  }
  param_4[4] = cVar13;
  iVar10 = r_emi_get_mem_addr_by_offset(0x1000);
  cVar13 = *param_4;
  param_4[5] = ((char)((ushort)*(undefined2 *)(iVar10 + iVar18) >> 8) - cVar13) + -1;
  *(undefined1 *)(iVar19 + 0x3e) = 0;
  if (cVar13 != '\0') {
    iVar10 = r_emi_get_mem_addr_by_offset(0x1000);
    *(undefined2 *)(param_4 + 6) = *(undefined2 *)(iVar10 + iVar21);
  }
  bVar12 = *(byte *)(iVar19 + 0x3d);
  if (bVar12 != 2) {
    if (2 < bVar12) {
      if (bVar12 != 3) {
        r_assert_err(0,"lld_scan.c",0x87e);
        return;
      }
      iVar10 = *(int *)(_lld_scan_env + param_1 * 4);
      iVar18 = r_emi_get_mem_addr_by_offset(0x1000,param_2);
      sVar2 = *(short *)(param_3 * 0x14 + 0x12 + iVar18);
      bVar12 = param_4[5];
      uVar16 = (uint)*(ushort *)(iVar10 + 0x36) + (uint)bVar12;
      iVar18 = uVar16 * 0x10000;
      *(char *)(iVar10 + 0x41) = *(char *)(iVar10 + 0x41) + '\x01';
      *(short *)(iVar10 + 0x36) = (short)((uint)iVar18 >> 0x10);
      if (0x672 < (uVar16 & 0xffff)) {
        *(undefined1 *)(iVar10 + 0x6e) = 2;
        param_4[5] = (bVar12 + 0x72) - (char)((uint)iVar18 >> 0x10);
        goto _L325;
      }
      if (*param_4 == '\0') {
        *(char *)(iVar10 + 0x6e) = (char)(((*(byte *)(iVar10 + 0x6d) >> 3 ^ 1) & 1) << 1);
        goto _L325;
      }
      uVar22 = *(ushort *)(param_4 + 6);
      sVar15 = 0;
      if ((uVar22 & 0x100) != 0) {
        sVar15 = 6;
      }
      if ((uVar22 & 0x200) != 0) {
        sVar15 = sVar15 + 6;
      }
      if ((uVar22 & 0x400) != 0) {
        sVar15 = sVar15 + 1;
      }
      if ((uVar22 >> 0xb & 1) == 0) {
        if ((*(byte *)(iVar10 + 0x6d) & 8) != 0) goto _L299;
      }
      else {
        psVar8 = (short *)r_emi_get_mem_addr_by_offset(sVar2 + sVar15);
        if (*(short *)(iVar10 + 0x34) == *psVar8) {
          sVar15 = sVar15 + 2;
_L299:
          if ((*(ushort *)(param_4 + 6) & 0x1000) == 0) {
            *(undefined1 *)(iVar10 + 0x6e) = 0;
            *(undefined1 *)(iVar10 + 0x3d) = 0;
            goto _L304;
          }
          pvVar5 = (void *)r_emi_get_mem_addr_by_offset(sVar2 + sVar15);
          memcpy(&stack0xffffffdc,pvVar5,3);
          iVar18 = r_emi_get_mem_addr_by_offset(0x1000);
          if ((*(ushort *)(param_3 * 0x14 + 2 + iVar18) >> 9 & 1) == 0) {
            if (*(byte *)(iVar10 + 0x41) < 7) {
              iVar18 = r_lld_calc_aux_rx(iVar10 + 0x48,param_3,unaff_s7);
              uVar11 = 1;
              if (iVar18 != 0) goto _L324;
            }
            *(undefined1 *)(iVar10 + 0x6e) = 2;
          }
          else {
            *(uint *)(iVar10 + 0x2c) = unaff_s7;
            uVar11 = 2;
_L324:
            *(undefined1 *)(iVar10 + 0x3e) = uVar11;
          }
          *(undefined1 *)(iVar10 + 0x3d) = 3;
          sVar15 = sVar15 + 3;
_L304:
          if ((*(ushort *)(param_4 + 6) & 0x2000) != 0) {
            sVar15 = sVar15 + 0x12;
          }
          if ((*(ushort *)(param_4 + 6) & 0x4000) == 0) {
            return;
          }
          puVar7 = (undefined1 *)r_emi_get_mem_addr_by_offset(sVar2 + sVar15);
          *(undefined1 *)(iVar10 + 0x73) = *puVar7;
          return;
        }
      }
      *(undefined1 *)(iVar10 + 0x6e) = 2;
      param_4[5] = '\0';
_L325:
      *(undefined1 *)(iVar10 + 0x3d) = 0;
      return;
    }
    if (bVar12 != 0) {
      iVar19 = param_3 * 0x14;
      iVar10 = *(int *)(_lld_scan_env + param_1 * 4);
      iVar18 = r_emi_get_mem_addr_by_offset(0x1000,param_2);
      sVar2 = *(short *)(iVar19 + 0x12 + iVar18);
      *(ushort *)(iVar10 + 0x36) = (ushort)(byte)param_4[5];
      iVar18 = r_emi_get_mem_addr_by_offset(0x1000);
      *(byte *)(iVar10 + 0x72) = (byte)((ushort)*(undefined2 *)(iVar18 + iVar19 + 6) >> 0xe);
      pbVar9 = _lld_scan_sync_env;
      if (*param_4 == '\0') {
        *(undefined1 *)(iVar10 + 0x6e) = 0xff;
        *(undefined1 *)(iVar10 + 0x3d) = 0;
        return;
      }
      if ((*(ushort *)(param_4 + 6) & 0x100) == 0) {
        sVar20 = 0;
        sVar15 = 0;
        if ((((*(byte *)(_lld_scan_env + 0x15) & 0xfd) == 1) &&
            (sVar15 = sVar20, *(char *)(iVar10 + 0x6f) == -1)) && ((_DAT_60031000 >> 10 & 1) != 0))
        {
          *(undefined1 *)(iVar10 + 0x6e) = 0xff;
        }
      }
      else {
        if ((param_4[1] == '\0') && (*(char *)(iVar10 + 0x6f) != -1)) {
          *(ushort *)(param_4 + 6) = *(ushort *)(param_4 + 6) & 0xfeff;
        }
        else {
          iVar18 = r_emi_get_mem_addr_by_offset(0x1000);
          bVar12 = (byte)(*(ushort *)(iVar19 + 4 + iVar18) >> 6) & 1;
          param_4[8] = bVar12;
          *(byte *)(iVar10 + 0x6f) = bVar12;
          pvVar5 = (void *)r_emi_get_mem_addr_by_offset((ushort)(byte)param_4[3] + sVar2);
          memcpy((void *)(iVar10 + 0x5c),pvVar5,6);
          if (((*(char *)(_lld_scan_env + 0x15) == '\x01') ||
              ((*(char *)(_lld_scan_env + 0x15) == '\x03' &&
               ((*(ushort *)(param_4 + 6) & 0x200) == 0)))) &&
             (iVar18 = r_emi_get_mem_addr_by_offset(0x1000),
             (*(ushort *)(iVar19 + 2 + iVar18) >> 0xb & 1) == 0)) {
            *(undefined1 *)(iVar10 + 0x6e) = 0xff;
          }
        }
        sVar15 = 6;
      }
      if ((*(ushort *)(param_4 + 6) & 0x200) != 0) {
        if (*(byte *)(iVar10 + 0x6d) == 4) {
          *(ushort *)(param_4 + 6) = *(ushort *)(param_4 + 6) & 0xfdff;
        }
        else {
          *(byte *)(iVar10 + 0x6d) = *(byte *)(iVar10 + 0x6d) | 4;
          iVar18 = r_emi_get_mem_addr_by_offset(0x1000);
          *(byte *)(iVar10 + 0x70) = (byte)(*(ushort *)(iVar19 + 4 + iVar18) >> 7) & 1;
          param_4[2] = (char)sVar15;
        }
        sVar15 = sVar15 + 6;
      }
      if ((*(ushort *)(param_4 + 6) & 0x400) != 0) {
        sVar15 = sVar15 + 1;
      }
      if ((*(ushort *)(param_4 + 6) >> 0xb & 1) == 0) {
        *(undefined1 *)(iVar10 + 0x6e) = 0xff;
        return;
      }
      psVar8 = (short *)r_emi_get_mem_addr_by_offset(sVar2 + sVar15);
      bVar1 = *(short *)(iVar10 + 0x34) != *psVar8;
      if (bVar1) {
        *(undefined1 *)(iVar10 + 0x6e) = 0xff;
      }
      sVar20 = sVar15 + 2;
      if (*(char *)(iVar10 + 0x6e) == -1) {
        if ((*(ushort *)(param_4 + 6) & 0x1000) == 0) goto _L477;
      }
      else {
        if ((*(ushort *)(param_4 + 6) & 0x1000) == 0) {
          if (((*(byte *)(iVar10 + 0x6d) & 2) == 0) || (*(char *)(iVar10 + 0x39) != '\x01')) {
            *(undefined1 *)(iVar10 + 0x6e) = 0;
            *(undefined1 *)(iVar10 + 0x3d) = 0;
          }
          else {
            *(undefined1 *)(iVar10 + 0x6e) = 0;
            *(undefined1 *)(iVar10 + 0x3d) = 2;
          }
          goto _L477;
        }
        pvVar5 = (void *)r_emi_get_mem_addr_by_offset(sVar2 + sVar20);
        memcpy(auStack_44,pvVar5,3);
        iVar18 = r_emi_get_mem_addr_by_offset(0x1000);
        if ((*(ushort *)(iVar19 + 2 + iVar18) >> 9 & 1) == 0) {
          iVar18 = r_lld_calc_aux_rx(iVar10 + 0x48,param_3);
          uVar11 = 1;
          if (iVar18 != 0) goto _L526;
          *(undefined1 *)(iVar10 + 0x6e) = 2;
        }
        else {
          *(undefined4 *)(iVar10 + 0x2c) = auStack_44[0];
          uVar11 = 2;
_L526:
          *(undefined1 *)(iVar10 + 0x3e) = uVar11;
        }
        *(undefined1 *)(iVar10 + 0x3d) = 3;
      }
      sVar20 = sVar15 + 5;
_L477:
      if ((*(ushort *)(param_4 + 6) & 0x2000) != 0) {
        uVar22 = *(ushort *)(iVar10 + 0x68);
        if ((bVar1 || pbVar9 == (byte *)0x0) ||
           (iVar18 = r_lld_scan_sync_accept
                               (param_1,param_3,*(undefined1 *)(iVar10 + 0x6f),
                                *(undefined4 *)(iVar10 + 0x5c),*(undefined4 *)(iVar10 + 0x60),
                                uVar22 >> 0xc), iVar18 == 0)) {
          puVar6 = (undefined2 *)r_emi_get_mem_addr_by_offset(sVar20 + sVar2 + 2);
          *(undefined2 *)(iVar10 + 0x76) = *puVar6;
        }
        else {
          pbVar9 = (byte *)r_ke_msg_alloc(0x203,0,0xff,0x30);
          iVar18 = r_lld_scan_sync_info_unpack(pbVar9 + 2,sVar20 + sVar2);
          if (iVar18 == 0) {
            if (*(short *)(pbVar9 + 2) == 0) {
              *(undefined2 *)(iVar10 + 0x76) = *(undefined2 *)(pbVar9 + 6);
            }
            r_ke_msg_free(pbVar9 + -0xc);
            r_ble_log_internal_x0(0x80a100be);
          }
          else {
            *pbVar9 = *_lld_scan_sync_env;
            iVar18 = r_emi_get_mem_addr_by_offset(0x1000);
            pbVar9[0x1e] = (byte)((ushort)*(undefined2 *)(iVar18 + iVar19 + 6) >> 0xe);
            iVar18 = r_emi_get_mem_addr_by_offset(0x1000);
            uVar14 = *(ushort *)(iVar19 + 10 + iVar18);
            if ((uVar14 & 0xf000) != 0) {
              r_assert_err(0,"lld_scan.c",1000);
            }
            iVar18 = r_emi_get_mem_addr_by_offset(0x1000);
            *(uint *)(pbVar9 + 0x18) = CONCAT22(uVar14,*(undefined2 *)(iVar19 + 8 + iVar18));
            iVar18 = r_emi_get_mem_addr_by_offset(0x1000);
            uVar16 = ((uint)*(ushort *)(&lld_exp_sync_pos_tab + (uint)pbVar9[0x1e] * 2) * -2 + 0x270
                     ) - (*(ushort *)(iVar19 + 0xc + iVar18) & 0x3ff);
            uVar17 = (int)(uVar16 * 0x10000) >> 0x10;
            if ((((byte)r_bt_rf_coex_st_param_get & 2) != 0) && ((pbVar9[0x1e] - 2 & 0xff) < 2)) {
              uVar17 = (int)(((uVar16 & 0xffff) + (uint)_DAT_000150ce * -2) * 0x10000) >> 0x10;
            }
            if (0x751 < (uVar17 + 0x4e1 & 0xffff)) {
              r_assert_err(0,"lld_scan.c",0x700);
            }
            for (; (int)uVar17 < 0; uVar17 = (int)(((uVar17 & 0xffff) + 0x271) * 0x10000) >> 0x10) {
              *(uint *)(pbVar9 + 0x18) = *(int *)(pbVar9 + 0x18) - 1U & 0xfffffff;
            }
            *(short *)(pbVar9 + 0x1c) = (short)uVar17;
            iVar18 = r_emi_get_mem_addr_by_offset(0x1000);
            pbVar4 = _lld_scan_sync_env;
            uVar3 = *(undefined2 *)(iVar19 + 0xe + iVar18);
            pbVar9[0x1f] = (byte)(uVar22 >> 0xc);
            *(undefined2 *)(pbVar9 + 0x20) = uVar3;
            pbVar9[0x22] = pbVar4[3];
            memcpy(pbVar9 + 0x23,pbVar4 + 4,6);
            r_ke_msg_send(pbVar9);
            r_ke_free(_lld_scan_sync_env);
            _lld_scan_sync_env = (byte *)0x0;
            r_ble_log_internal_x2
                      (0x40a100bd,*(undefined4 *)(pbVar9 + 0x18),
                       (uint)*(ushort *)(pbVar9 + 0x1c) |
                       (uint)*pbVar9 << 0x10 | (uint)pbVar9[0x1f] << 0x18);
          }
        }
        sVar20 = sVar20 + 0x12;
      }
      if ((*(ushort *)(param_4 + 6) & 0x4000) != 0) {
        puVar7 = (undefined1 *)r_emi_get_mem_addr_by_offset(sVar2 + sVar20);
        *(undefined1 *)(iVar10 + 0x73) = *puVar7;
      }
      return;
    }
    iVar10 = *(int *)(_lld_scan_env + param_1 * 4);
    if (*(char *)(iVar10 + 0x3d) != '\0') {
      return;
    }
    iVar19 = param_3 * 0x14;
    iVar18 = r_emi_get_mem_addr_by_offset(0x1000,param_2);
    sVar2 = *(short *)(iVar19 + 0x12 + iVar18);
    memset((void *)(iVar10 + 0x58),0,0x2c);
    *(undefined2 *)(iVar10 + 0x36) = 0;
    *(undefined1 *)(iVar10 + 0x41) = 0;
    r_lld_ext_scan_dynamic_pti_process_eco(iVar10,0);
    *(undefined1 *)(iVar10 + 0x6e) = 1;
    *(undefined1 *)(iVar10 + 0x71) = *(undefined1 *)(iVar10 + 0x3b);
    iVar18 = r_emi_get_mem_addr_by_offset(0x1000);
    uVar22 = *(ushort *)(iVar19 + 0x10 + iVar18) >> 6;
    uVar14 = uVar22 & 3;
    param_4[1] = (char)uVar14;
    if (uVar14 == 1) {
      bVar12 = *(byte *)(iVar10 + 0x6d) | 1;
_L252:
      *(byte *)(iVar10 + 0x6d) = bVar12;
    }
    else if (uVar14 == 2) {
      bVar12 = *(byte *)(iVar10 + 0x6d) | 2;
      goto _L252;
    }
    *(undefined1 *)(iVar10 + 0x6a) = 0;
    if (*param_4 == '\0') {
      *(undefined1 *)(iVar10 + 0x6e) = 0;
    }
    else {
      uVar14 = *(ushort *)(param_4 + 6);
      sVar15 = 0;
      if ((uVar14 & 0x100) != 0) {
        if (((uVar22 & 3) == 0) && ((*(char *)(iVar10 + 0x3b) == '\0' || ((uVar14 & 0x1000) == 0))))
        {
          iVar18 = r_emi_get_mem_addr_by_offset(0x1000);
          param_4[8] = (byte)(*(ushort *)(iVar19 + 4 + iVar18) >> 6) & 1;
          pvVar5 = (void *)r_emi_get_mem_addr_by_offset((ushort)(byte)param_4[3] + sVar2);
          memcpy((void *)(iVar10 + 0x5c),pvVar5,6);
        }
        else {
          *(ushort *)(param_4 + 6) = uVar14 & 0xfeff;
        }
        sVar15 = 6;
      }
      uVar22 = *(ushort *)(param_4 + 6);
      if ((uVar22 & 0x200) != 0) {
        if ((param_4[1] == '\0') && ((*(char *)(iVar10 + 0x3b) == '\0' || ((uVar22 & 0x1000) == 0)))
           ) {
          *(byte *)(iVar10 + 0x6d) = *(byte *)(iVar10 + 0x6d) | 4;
          iVar18 = r_emi_get_mem_addr_by_offset(0x1000);
          *(byte *)(iVar10 + 0x70) = (byte)(*(ushort *)(iVar19 + 4 + iVar18) >> 7) & 1;
          param_4[2] = (char)sVar15;
        }
        else {
          *(ushort *)(param_4 + 6) = uVar22 & 0xfdff;
        }
        sVar15 = sVar15 + 6;
      }
      if ((*(ushort *)(param_4 + 6) & 0x400) != 0) {
        sVar15 = sVar15 + 1;
      }
      if ((*(ushort *)(param_4 + 6) >> 0xb & 1) != 0) {
        puVar6 = (undefined2 *)r_emi_get_mem_addr_by_offset(sVar2 + sVar15);
        uVar3 = *puVar6;
        sVar15 = sVar15 + 2;
        *(undefined2 *)(iVar10 + 0x34) = uVar3;
        *(undefined2 *)(iVar10 + 0x68) = uVar3;
        *(undefined1 *)(iVar10 + 0x6a) = 1;
      }
      if ((*(ushort *)(param_4 + 6) & 0x1000) == 0) {
        *(char *)(iVar10 + 0x6e) = -(*(char *)(iVar10 + 0x6f) == -1);
        *(undefined1 *)(iVar10 + 0x72) = 4;
      }
      else {
        pvVar5 = (void *)r_emi_get_mem_addr_by_offset(sVar2 + sVar15);
        memcpy(&stack0xffffffdc,pvVar5,3);
        iVar18 = r_emi_get_mem_addr_by_offset(0x1000);
        if ((*(ushort *)(iVar19 + 2 + iVar18) >> 9 & 1) == 0) {
          if (2 < (unaff_s7 >> 0x15 & 7)) {
_L220:
            *(undefined1 *)(iVar10 + 0x6e) = 0xff;
            return;
          }
          iVar18 = r_lld_calc_aux_rx(iVar10 + 0x48,param_3);
          uVar11 = 1;
          if (iVar18 == 0) goto _L220;
        }
        else {
          *(uint *)(iVar10 + 0x2c) = unaff_s7;
          uVar11 = 2;
        }
        *(undefined1 *)(iVar10 + 0x3e) = uVar11;
        *(undefined1 *)(iVar10 + 0x3d) = 1;
        sVar15 = sVar15 + 3;
      }
      uVar22 = *(ushort *)(param_4 + 6);
      if ((uVar22 & 0x2000) != 0) {
        sVar15 = sVar15 + 0x12;
      }
      if ((uVar22 & 0x4000) == 0) {
        uVar11 = 0x7f;
      }
      else {
        if ((*(char *)(iVar10 + 0x3b) != '\0') && ((param_4[1] != '\0' || ((uVar22 & 0x1000) != 0)))
           ) goto _L226;
        puVar7 = (undefined1 *)r_emi_get_mem_addr_by_offset(sVar2 + sVar15);
        uVar11 = *puVar7;
      }
      *(undefined1 *)(iVar10 + 0x73) = uVar11;
    }
_L226:
    *(char *)(iVar10 + 0x6f) = param_4[8];
    param_4[5] = '\0';
    return;
  }
  iVar19 = param_3 * 0x14;
  iVar10 = *(int *)(_lld_scan_env + param_1 * 4);
  iVar18 = r_emi_get_mem_addr_by_offset(0x1000,param_2);
  sVar2 = *(short *)(iVar19 + 0x12 + iVar18);
  bVar12 = param_4[5];
  *(undefined1 *)(iVar10 + 0x6e) = 1;
  *(ushort *)(iVar10 + 0x36) = (ushort)bVar12;
  *(byte *)(iVar10 + 0x6d) = *(byte *)(iVar10 + 0x6d) | 8;
  if (*param_4 == '\0') {
    *(undefined1 *)(iVar10 + 0x6e) = 0;
    *(undefined1 *)(iVar10 + 0x3d) = 0;
    return;
  }
  sVar15 = 0;
  if ((*(ushort *)(param_4 + 6) & 0x100) != 0) {
    iVar18 = r_emi_get_mem_addr_by_offset(0x1000);
    bVar12 = (byte)(*(ushort *)(iVar19 + 4 + iVar18) >> 6) & 1;
    param_4[8] = bVar12;
    *(byte *)(iVar10 + 0x6f) = bVar12;
    if (((*(char *)(_lld_scan_env + 0x15) == '\x01') ||
        ((*(char *)(_lld_scan_env + 0x15) == '\x03' && ((*(ushort *)(param_4 + 6) & 0x200) == 0))))
       && (iVar18 = r_emi_get_mem_addr_by_offset(0x1000),
          (*(ushort *)(iVar19 + 2 + iVar18) >> 0xb & 1) == 0)) {
      *(undefined1 *)(iVar10 + 0x6e) = 0xff;
      return;
    }
    sVar15 = 6;
  }
  uVar22 = *(ushort *)(param_4 + 6);
  if ((uVar22 & 0x200) != 0) {
    sVar15 = sVar15 + 6;
  }
  if ((uVar22 & 0x400) != 0) {
    sVar15 = sVar15 + 1;
  }
  if ((uVar22 >> 0xb & 1) != 0) {
    sVar15 = sVar15 + 2;
  }
  if ((uVar22 & 0x1000) == 0) {
    *(undefined1 *)(iVar10 + 0x6e) = 0;
    *(undefined1 *)(iVar10 + 0x3d) = 0;
    goto _L269;
  }
  pvVar5 = (void *)r_emi_get_mem_addr_by_offset(sVar2 + sVar15);
  memcpy(&stack0xffffffcc,pvVar5,3);
  iVar18 = r_emi_get_mem_addr_by_offset(0x1000);
  if ((*(ushort *)(iVar19 + 2 + iVar18) >> 9 & 1) == 0) {
    iVar18 = r_lld_calc_aux_rx(iVar10 + 0x48,param_3);
    uVar11 = 1;
    if (iVar18 != 0) goto _L289;
    *(undefined1 *)(iVar10 + 0x6e) = 2;
  }
  else {
    *(undefined4 *)(iVar10 + 0x2c) = in_stack_ffffffcc;
    uVar11 = 2;
_L289:
    *(undefined1 *)(iVar10 + 0x3e) = uVar11;
  }
  *(undefined1 *)(iVar10 + 0x3d) = 3;
  sVar15 = sVar15 + 3;
_L269:
  if ((*(ushort *)(param_4 + 6) & 0x2000) != 0) {
    sVar15 = sVar15 + 0x12;
  }
  if ((*(ushort *)(param_4 + 6) & 0x4000) != 0) {
    puVar7 = (undefined1 *)r_emi_get_mem_addr_by_offset(sVar2 + sVar15);
    *(undefined1 *)(iVar10 + 0x73) = *puVar7;
  }
  return;
}

