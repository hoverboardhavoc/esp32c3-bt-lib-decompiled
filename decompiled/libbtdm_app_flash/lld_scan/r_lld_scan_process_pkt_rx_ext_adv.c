/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  undefined1 *puVar4;
  void *pvVar5;
  undefined2 *puVar6;
  undefined1 *puVar7;
  short *psVar8;
  int iVar9;
  undefined1 uVar10;
  byte bVar11;
  char cVar12;
  ushort uVar13;
  short sVar14;
  uint uVar15;
  uint uVar16;
  int iVar17;
  int iVar18;
  short sVar19;
  int iVar20;
  ushort uVar21;
  uint unaff_s7;
  undefined4 auStack_44 [4];
  undefined4 in_stack_ffffffcc;
  
  if (param_2 < 7) {
    return;
  }
  iVar18 = *(int *)(_lld_scan_env + param_1 * 4);
  iVar20 = param_3 * 0x14 + 0x10;
  iVar9 = r_emi_get_mem_addr_by_offset(0x1000);
  iVar17 = param_3 * 0x14 + 4;
  uVar21 = *(ushort *)(iVar9 + iVar20) & 0x3f;
  *param_4 = (char)uVar21;
  iVar9 = r_emi_get_mem_addr_by_offset(0x1000);
  if (*(ushort *)(iVar9 + iVar17) >> 8 <= uVar21) {
    r_assert_err(0,"lld_scan.c",0x825);
  }
  cVar12 = *param_4;
  if (cVar12 != '\0') {
    cVar12 = cVar12 + -1;
  }
  param_4[4] = cVar12;
  iVar9 = r_emi_get_mem_addr_by_offset(0x1000);
  cVar12 = *param_4;
  param_4[5] = ((char)((ushort)*(undefined2 *)(iVar9 + iVar17) >> 8) - cVar12) + -1;
  *(undefined1 *)(iVar18 + 0x3e) = 0;
  if (cVar12 != '\0') {
    iVar9 = r_emi_get_mem_addr_by_offset(0x1000);
    *(undefined2 *)(param_4 + 6) = *(undefined2 *)(iVar9 + iVar20);
  }
  bVar11 = *(byte *)(iVar18 + 0x3d);
  if (bVar11 != 2) {
    if (2 < bVar11) {
      if (bVar11 != 3) {
        r_assert_err(0,"lld_scan.c",0x84c);
        return;
      }
      iVar9 = *(int *)(_lld_scan_env + param_1 * 4);
      iVar17 = r_emi_get_mem_addr_by_offset(0x1000,param_2);
      sVar2 = *(short *)(param_3 * 0x14 + 0x12 + iVar17);
      bVar11 = param_4[5];
      uVar15 = (uint)*(ushort *)(iVar9 + 0x36) + (uint)bVar11;
      iVar17 = uVar15 * 0x10000;
      *(char *)(iVar9 + 0x41) = *(char *)(iVar9 + 0x41) + '\x01';
      *(short *)(iVar9 + 0x36) = (short)((uint)iVar17 >> 0x10);
      if (0x672 < (uVar15 & 0xffff)) {
        *(undefined1 *)(iVar9 + 0x6e) = 2;
        param_4[5] = (bVar11 + 0x72) - (char)((uint)iVar17 >> 0x10);
        goto _L325;
      }
      if (*param_4 == '\0') {
        *(char *)(iVar9 + 0x6e) = (char)(((*(byte *)(iVar9 + 0x6d) >> 3 ^ 1) & 1) << 1);
        goto _L325;
      }
      uVar21 = *(ushort *)(param_4 + 6);
      sVar14 = 0;
      if ((uVar21 & 0x100) != 0) {
        sVar14 = 6;
      }
      if ((uVar21 & 0x200) != 0) {
        sVar14 = sVar14 + 6;
      }
      if ((uVar21 & 0x400) != 0) {
        sVar14 = sVar14 + 1;
      }
      if ((uVar21 >> 0xb & 1) == 0) {
        if ((*(byte *)(iVar9 + 0x6d) & 8) != 0) goto _L299;
      }
      else {
        psVar8 = (short *)r_emi_get_mem_addr_by_offset(sVar2 + sVar14);
        if (*(short *)(iVar9 + 0x34) == *psVar8) {
          sVar14 = sVar14 + 2;
_L299:
          if ((*(ushort *)(param_4 + 6) & 0x1000) == 0) {
            *(undefined1 *)(iVar9 + 0x6e) = 0;
            *(undefined1 *)(iVar9 + 0x3d) = 0;
            goto _L304;
          }
          pvVar5 = (void *)r_emi_get_mem_addr_by_offset(sVar2 + sVar14);
          memcpy(&stack0xffffffdc,pvVar5,3);
          iVar17 = r_emi_get_mem_addr_by_offset(0x1000);
          if ((*(ushort *)(param_3 * 0x14 + 2 + iVar17) >> 9 & 1) == 0) {
            if (*(byte *)(iVar9 + 0x41) < 7) {
              iVar17 = r_lld_calc_aux_rx(iVar9 + 0x48,param_3,unaff_s7);
              uVar10 = 1;
              if (iVar17 != 0) goto _L324;
            }
            *(undefined1 *)(iVar9 + 0x6e) = 2;
          }
          else {
            *(uint *)(iVar9 + 0x2c) = unaff_s7;
            uVar10 = 2;
_L324:
            *(undefined1 *)(iVar9 + 0x3e) = uVar10;
          }
          *(undefined1 *)(iVar9 + 0x3d) = 3;
          sVar14 = sVar14 + 3;
_L304:
          if ((*(ushort *)(param_4 + 6) & 0x2000) != 0) {
            sVar14 = sVar14 + 0x12;
          }
          if ((*(ushort *)(param_4 + 6) & 0x4000) == 0) {
            return;
          }
          puVar7 = (undefined1 *)r_emi_get_mem_addr_by_offset(sVar2 + sVar14);
          *(undefined1 *)(iVar9 + 0x73) = *puVar7;
          return;
        }
      }
      *(undefined1 *)(iVar9 + 0x6e) = 2;
      param_4[5] = '\0';
_L325:
      *(undefined1 *)(iVar9 + 0x3d) = 0;
      return;
    }
    if (bVar11 != 0) {
      iVar18 = param_3 * 0x14;
      iVar9 = *(int *)(_lld_scan_env + param_1 * 4);
      iVar17 = r_emi_get_mem_addr_by_offset(0x1000,param_2);
      sVar2 = *(short *)(iVar18 + 0x12 + iVar17);
      *(ushort *)(iVar9 + 0x36) = (ushort)(byte)param_4[5];
      iVar17 = r_emi_get_mem_addr_by_offset(0x1000);
      *(byte *)(iVar9 + 0x72) = (byte)((ushort)*(undefined2 *)(iVar17 + iVar18 + 6) >> 0xe);
      puVar7 = _lld_scan_sync_env;
      if (*param_4 == '\0') {
        *(undefined1 *)(iVar9 + 0x6e) = 0xff;
        *(undefined1 *)(iVar9 + 0x3d) = 0;
        return;
      }
      if ((*(ushort *)(param_4 + 6) & 0x100) == 0) {
        sVar19 = 0;
        sVar14 = 0;
        if ((((*(byte *)(_lld_scan_env + 0x15) & 0xfd) == 1) &&
            (sVar14 = sVar19, *(char *)(iVar9 + 0x6f) == -1)) && ((_DAT_60031000 >> 10 & 1) != 0)) {
          *(undefined1 *)(iVar9 + 0x6e) = 0xff;
        }
      }
      else {
        if ((param_4[1] == '\0') && (*(char *)(iVar9 + 0x6f) != -1)) {
          *(ushort *)(param_4 + 6) = *(ushort *)(param_4 + 6) & 0xfeff;
        }
        else {
          iVar17 = r_emi_get_mem_addr_by_offset(0x1000);
          bVar11 = (byte)(*(ushort *)(iVar18 + 4 + iVar17) >> 6) & 1;
          param_4[8] = bVar11;
          *(byte *)(iVar9 + 0x6f) = bVar11;
          pvVar5 = (void *)r_emi_get_mem_addr_by_offset((ushort)(byte)param_4[3] + sVar2);
          memcpy((void *)(iVar9 + 0x5c),pvVar5,6);
          if (((*(char *)(_lld_scan_env + 0x15) == '\x01') ||
              ((*(char *)(_lld_scan_env + 0x15) == '\x03' &&
               ((*(ushort *)(param_4 + 6) & 0x200) == 0)))) &&
             (iVar17 = r_emi_get_mem_addr_by_offset(0x1000),
             (*(ushort *)(iVar18 + 2 + iVar17) >> 0xb & 1) == 0)) {
            *(undefined1 *)(iVar9 + 0x6e) = 0xff;
          }
        }
        sVar14 = 6;
      }
      if ((*(ushort *)(param_4 + 6) & 0x200) != 0) {
        if (*(byte *)(iVar9 + 0x6d) == 4) {
          *(ushort *)(param_4 + 6) = *(ushort *)(param_4 + 6) & 0xfdff;
        }
        else {
          *(byte *)(iVar9 + 0x6d) = *(byte *)(iVar9 + 0x6d) | 4;
          iVar17 = r_emi_get_mem_addr_by_offset(0x1000);
          *(byte *)(iVar9 + 0x70) = (byte)(*(ushort *)(iVar18 + 4 + iVar17) >> 7) & 1;
          param_4[2] = (char)sVar14;
        }
        sVar14 = sVar14 + 6;
      }
      if ((*(ushort *)(param_4 + 6) & 0x400) != 0) {
        sVar14 = sVar14 + 1;
      }
      if ((*(ushort *)(param_4 + 6) >> 0xb & 1) == 0) {
        *(undefined1 *)(iVar9 + 0x6e) = 0xff;
        return;
      }
      psVar8 = (short *)r_emi_get_mem_addr_by_offset(sVar2 + sVar14);
      bVar1 = *(short *)(iVar9 + 0x34) != *psVar8;
      if (bVar1) {
        *(undefined1 *)(iVar9 + 0x6e) = 0xff;
      }
      sVar19 = sVar14 + 2;
      if (*(char *)(iVar9 + 0x6e) == -1) {
        if ((*(ushort *)(param_4 + 6) & 0x1000) == 0) goto _L482;
      }
      else {
        if ((*(ushort *)(param_4 + 6) & 0x1000) == 0) {
          if (((*(byte *)(iVar9 + 0x6d) & 2) == 0) || (*(char *)(iVar9 + 0x39) != '\x01')) {
            *(undefined1 *)(iVar9 + 0x6e) = 0;
            *(undefined1 *)(iVar9 + 0x3d) = 0;
          }
          else {
            *(undefined1 *)(iVar9 + 0x6e) = 0;
            *(undefined1 *)(iVar9 + 0x3d) = 2;
          }
          goto _L482;
        }
        pvVar5 = (void *)r_emi_get_mem_addr_by_offset(sVar2 + sVar19);
        memcpy(auStack_44,pvVar5,3);
        iVar17 = r_emi_get_mem_addr_by_offset(0x1000);
        if ((*(ushort *)(iVar18 + 2 + iVar17) >> 9 & 1) == 0) {
          iVar17 = r_lld_calc_aux_rx(iVar9 + 0x48,param_3);
          uVar10 = 1;
          if (iVar17 != 0) goto _L531;
          *(undefined1 *)(iVar9 + 0x6e) = 2;
        }
        else {
          *(undefined4 *)(iVar9 + 0x2c) = auStack_44[0];
          uVar10 = 2;
_L531:
          *(undefined1 *)(iVar9 + 0x3e) = uVar10;
        }
        *(undefined1 *)(iVar9 + 0x3d) = 3;
      }
      sVar19 = sVar14 + 5;
_L482:
      if ((*(ushort *)(param_4 + 6) & 0x2000) != 0) {
        uVar21 = *(ushort *)(iVar9 + 0x68);
        if ((bVar1 || puVar7 == (undefined1 *)0x0) ||
           (iVar17 = r_lld_scan_sync_accept
                               (param_1,param_3,*(undefined1 *)(iVar9 + 0x6f),
                                *(undefined4 *)(iVar9 + 0x5c),*(undefined4 *)(iVar9 + 0x60),
                                uVar21 >> 0xc), iVar17 == 0)) {
          puVar6 = (undefined2 *)r_emi_get_mem_addr_by_offset(sVar19 + sVar2 + 2);
          *(undefined2 *)(iVar9 + 0x76) = *puVar6;
        }
        else {
          puVar7 = (undefined1 *)r_ke_msg_alloc(0x203,0,0xff,0x30);
          iVar17 = r_lld_scan_sync_info_unpack(puVar7 + 2,sVar2 + sVar19);
          if (iVar17 == 0) {
            if (*(short *)(puVar7 + 2) == 0) {
              *(undefined2 *)(iVar9 + 0x76) = *(undefined2 *)(puVar7 + 6);
            }
            r_ke_msg_free(puVar7 + -0xc);
          }
          else {
            *puVar7 = *_lld_scan_sync_env;
            iVar17 = r_emi_get_mem_addr_by_offset(0x1000);
            puVar7[0x1e] = (byte)((ushort)*(undefined2 *)(iVar17 + iVar18 + 6) >> 0xe);
            iVar17 = r_emi_get_mem_addr_by_offset(0x1000);
            uVar13 = *(ushort *)(iVar18 + 10 + iVar17);
            if ((uVar13 & 0xf000) != 0) {
              r_assert_err(0,"lld_scan.c",1000);
            }
            iVar17 = r_emi_get_mem_addr_by_offset(0x1000);
            *(uint *)(puVar7 + 0x18) = CONCAT22(uVar13,*(undefined2 *)(iVar18 + 8 + iVar17));
            iVar17 = r_emi_get_mem_addr_by_offset(0x1000);
            uVar15 = ((uint)*(ushort *)(&lld_exp_sync_pos_tab + (uint)(byte)puVar7[0x1e] * 2) * -2 +
                     0x270) - (*(ushort *)(iVar18 + 0xc + iVar17) & 0x3ff);
            uVar16 = (int)(uVar15 * 0x10000) >> 0x10;
            if (((g_bt_plf_log_level & 2) != 0) && (((byte)puVar7[0x1e] - 2 & 0xff) < 2)) {
              uVar16 = (int)(((uVar15 & 0xffff) + (uint)_DAT_000150c6 * -2) * 0x10000) >> 0x10;
            }
            if (0x751 < (uVar16 + 0x4e1 & 0xffff)) {
              r_assert_err(0,"lld_scan.c",0x6d1);
            }
            for (; (int)uVar16 < 0; uVar16 = (int)(((uVar16 & 0xffff) + 0x271) * 0x10000) >> 0x10) {
              *(uint *)(puVar7 + 0x18) = *(int *)(puVar7 + 0x18) - 1U & 0xfffffff;
            }
            *(short *)(puVar7 + 0x1c) = (short)uVar16;
            iVar17 = r_emi_get_mem_addr_by_offset(0x1000);
            puVar4 = _lld_scan_sync_env;
            uVar3 = *(undefined2 *)(iVar18 + 0xe + iVar17);
            puVar7[0x1f] = (byte)(uVar21 >> 0xc);
            *(undefined2 *)(puVar7 + 0x20) = uVar3;
            puVar7[0x22] = puVar4[3];
            memcpy(puVar7 + 0x23,puVar4 + 4,6);
            r_ke_msg_send(puVar7);
            r_ke_free(_lld_scan_sync_env);
            _lld_scan_sync_env = (undefined1 *)0x0;
          }
        }
        sVar19 = sVar19 + 0x12;
      }
      if ((*(ushort *)(param_4 + 6) & 0x4000) != 0) {
        puVar7 = (undefined1 *)r_emi_get_mem_addr_by_offset(sVar2 + sVar19);
        *(undefined1 *)(iVar9 + 0x73) = *puVar7;
      }
      return;
    }
    iVar9 = *(int *)(_lld_scan_env + param_1 * 4);
    if (*(char *)(iVar9 + 0x3d) != '\0') {
      return;
    }
    iVar18 = param_3 * 0x14;
    iVar17 = r_emi_get_mem_addr_by_offset(0x1000,param_2);
    sVar2 = *(short *)(iVar18 + 0x12 + iVar17);
    memset((void *)(iVar9 + 0x58),0,0x2c);
    *(undefined2 *)(iVar9 + 0x36) = 0;
    *(undefined1 *)(iVar9 + 0x41) = 0;
    r_lld_ext_scan_dynamic_pti_process_eco(iVar9,0);
    *(undefined1 *)(iVar9 + 0x6e) = 1;
    *(undefined1 *)(iVar9 + 0x71) = *(undefined1 *)(iVar9 + 0x3b);
    iVar17 = r_emi_get_mem_addr_by_offset(0x1000);
    uVar21 = *(ushort *)(iVar18 + 0x10 + iVar17) >> 6;
    uVar13 = uVar21 & 3;
    param_4[1] = (char)uVar13;
    if (uVar13 == 1) {
      bVar11 = *(byte *)(iVar9 + 0x6d) | 1;
_L252:
      *(byte *)(iVar9 + 0x6d) = bVar11;
    }
    else if (uVar13 == 2) {
      bVar11 = *(byte *)(iVar9 + 0x6d) | 2;
      goto _L252;
    }
    *(undefined1 *)(iVar9 + 0x6a) = 0;
    if (*param_4 == '\0') {
      *(undefined1 *)(iVar9 + 0x6e) = 0;
    }
    else {
      uVar13 = *(ushort *)(param_4 + 6);
      sVar14 = 0;
      if ((uVar13 & 0x100) != 0) {
        if (((uVar21 & 3) == 0) && ((*(char *)(iVar9 + 0x3b) == '\0' || ((uVar13 & 0x1000) == 0))))
        {
          iVar17 = r_emi_get_mem_addr_by_offset(0x1000);
          param_4[8] = (byte)(*(ushort *)(iVar18 + 4 + iVar17) >> 6) & 1;
          pvVar5 = (void *)r_emi_get_mem_addr_by_offset((ushort)(byte)param_4[3] + sVar2);
          memcpy((void *)(iVar9 + 0x5c),pvVar5,6);
        }
        else {
          *(ushort *)(param_4 + 6) = uVar13 & 0xfeff;
        }
        sVar14 = 6;
      }
      uVar21 = *(ushort *)(param_4 + 6);
      if ((uVar21 & 0x200) != 0) {
        if ((param_4[1] == '\0') && ((*(char *)(iVar9 + 0x3b) == '\0' || ((uVar21 & 0x1000) == 0))))
        {
          *(byte *)(iVar9 + 0x6d) = *(byte *)(iVar9 + 0x6d) | 4;
          iVar17 = r_emi_get_mem_addr_by_offset(0x1000);
          *(byte *)(iVar9 + 0x70) = (byte)(*(ushort *)(iVar18 + 4 + iVar17) >> 7) & 1;
          param_4[2] = (char)sVar14;
        }
        else {
          *(ushort *)(param_4 + 6) = uVar21 & 0xfdff;
        }
        sVar14 = sVar14 + 6;
      }
      if ((*(ushort *)(param_4 + 6) & 0x400) != 0) {
        sVar14 = sVar14 + 1;
      }
      if ((*(ushort *)(param_4 + 6) >> 0xb & 1) != 0) {
        puVar6 = (undefined2 *)r_emi_get_mem_addr_by_offset(sVar2 + sVar14);
        uVar3 = *puVar6;
        sVar14 = sVar14 + 2;
        *(undefined2 *)(iVar9 + 0x34) = uVar3;
        *(undefined2 *)(iVar9 + 0x68) = uVar3;
        *(undefined1 *)(iVar9 + 0x6a) = 1;
      }
      if ((*(ushort *)(param_4 + 6) & 0x1000) == 0) {
        *(char *)(iVar9 + 0x6e) = -(*(char *)(iVar9 + 0x6f) == -1);
        *(undefined1 *)(iVar9 + 0x72) = 4;
      }
      else {
        pvVar5 = (void *)r_emi_get_mem_addr_by_offset(sVar2 + sVar14);
        memcpy(&stack0xffffffdc,pvVar5,3);
        iVar17 = r_emi_get_mem_addr_by_offset(0x1000);
        if ((*(ushort *)(iVar18 + 2 + iVar17) >> 9 & 1) == 0) {
          if (2 < (unaff_s7 >> 0x15 & 7)) {
_L220:
            *(undefined1 *)(iVar9 + 0x6e) = 0xff;
            return;
          }
          iVar17 = r_lld_calc_aux_rx(iVar9 + 0x48,param_3);
          uVar10 = 1;
          if (iVar17 == 0) goto _L220;
        }
        else {
          *(uint *)(iVar9 + 0x2c) = unaff_s7;
          uVar10 = 2;
        }
        *(undefined1 *)(iVar9 + 0x3e) = uVar10;
        *(undefined1 *)(iVar9 + 0x3d) = 1;
        sVar14 = sVar14 + 3;
      }
      uVar21 = *(ushort *)(param_4 + 6);
      if ((uVar21 & 0x2000) != 0) {
        sVar14 = sVar14 + 0x12;
      }
      if ((uVar21 & 0x4000) == 0) {
        uVar10 = 0x7f;
      }
      else {
        if ((*(char *)(iVar9 + 0x3b) != '\0') && ((param_4[1] != '\0' || ((uVar21 & 0x1000) != 0))))
        goto _L226;
        puVar7 = (undefined1 *)r_emi_get_mem_addr_by_offset(sVar2 + sVar14);
        uVar10 = *puVar7;
      }
      *(undefined1 *)(iVar9 + 0x73) = uVar10;
    }
_L226:
    *(char *)(iVar9 + 0x6f) = param_4[8];
    param_4[5] = '\0';
    return;
  }
  iVar18 = param_3 * 0x14;
  iVar9 = *(int *)(_lld_scan_env + param_1 * 4);
  iVar17 = r_emi_get_mem_addr_by_offset(0x1000,param_2);
  sVar2 = *(short *)(iVar18 + 0x12 + iVar17);
  bVar11 = param_4[5];
  *(undefined1 *)(iVar9 + 0x6e) = 1;
  *(ushort *)(iVar9 + 0x36) = (ushort)bVar11;
  *(byte *)(iVar9 + 0x6d) = *(byte *)(iVar9 + 0x6d) | 8;
  if (*param_4 == '\0') {
    *(undefined1 *)(iVar9 + 0x6e) = 0;
    *(undefined1 *)(iVar9 + 0x3d) = 0;
    return;
  }
  sVar14 = 0;
  if ((*(ushort *)(param_4 + 6) & 0x100) != 0) {
    iVar17 = r_emi_get_mem_addr_by_offset(0x1000);
    bVar11 = (byte)(*(ushort *)(iVar18 + 4 + iVar17) >> 6) & 1;
    param_4[8] = bVar11;
    *(byte *)(iVar9 + 0x6f) = bVar11;
    if (((*(char *)(_lld_scan_env + 0x15) == '\x01') ||
        ((*(char *)(_lld_scan_env + 0x15) == '\x03' && ((*(ushort *)(param_4 + 6) & 0x200) == 0))))
       && (iVar17 = r_emi_get_mem_addr_by_offset(0x1000),
          (*(ushort *)(iVar18 + 2 + iVar17) >> 0xb & 1) == 0)) {
      *(undefined1 *)(iVar9 + 0x6e) = 0xff;
      return;
    }
    sVar14 = 6;
  }
  uVar21 = *(ushort *)(param_4 + 6);
  if ((uVar21 & 0x200) != 0) {
    sVar14 = sVar14 + 6;
  }
  if ((uVar21 & 0x400) != 0) {
    sVar14 = sVar14 + 1;
  }
  if ((uVar21 >> 0xb & 1) != 0) {
    sVar14 = sVar14 + 2;
  }
  if ((uVar21 & 0x1000) == 0) {
    *(undefined1 *)(iVar9 + 0x6e) = 0;
    *(undefined1 *)(iVar9 + 0x3d) = 0;
    goto _L269;
  }
  pvVar5 = (void *)r_emi_get_mem_addr_by_offset(sVar2 + sVar14);
  memcpy(&stack0xffffffcc,pvVar5,3);
  iVar17 = r_emi_get_mem_addr_by_offset(0x1000);
  if ((*(ushort *)(iVar18 + 2 + iVar17) >> 9 & 1) == 0) {
    iVar17 = r_lld_calc_aux_rx(iVar9 + 0x48,param_3);
    uVar10 = 1;
    if (iVar17 != 0) goto _L289;
    *(undefined1 *)(iVar9 + 0x6e) = 2;
  }
  else {
    *(undefined4 *)(iVar9 + 0x2c) = in_stack_ffffffcc;
    uVar10 = 2;
_L289:
    *(undefined1 *)(iVar9 + 0x3e) = uVar10;
  }
  *(undefined1 *)(iVar9 + 0x3d) = 3;
  sVar14 = sVar14 + 3;
_L269:
  if ((*(ushort *)(param_4 + 6) & 0x2000) != 0) {
    sVar14 = sVar14 + 0x12;
  }
  if ((*(ushort *)(param_4 + 6) & 0x4000) != 0) {
    puVar7 = (undefined1 *)r_emi_get_mem_addr_by_offset(sVar2 + sVar14);
    *(undefined1 *)(iVar9 + 0x73) = *puVar7;
  }
  return;
}

