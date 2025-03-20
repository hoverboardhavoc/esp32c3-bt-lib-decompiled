/*
 * Last changed at upstream commit daab5dbba958a13041bd496e4a6ed506c9284a06
 * https://github.com/espressif/esp32c3-bt-lib/commit/daab5dbba958a13041bd496e4a6ed506c9284a06
 * Upstream date: 2025-03-20 20:43:40 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(86a4da5c)
 * Source: libbtdm_app_flash -> lld_scan.o -> r_lld_scan_process_pkt_rx_ext_adv
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_scan_process_pkt_rx_ext_adv(int param_1,uint param_2,int param_3,byte *param_4)

{
  bool bVar1;
  char cVar2;
  short sVar3;
  undefined2 uVar4;
  undefined1 *puVar5;
  int iVar6;
  undefined2 *puVar7;
  short *psVar8;
  void *pvVar9;
  undefined1 *puVar10;
  int iVar11;
  undefined1 uVar12;
  byte bVar13;
  ushort uVar14;
  uint uVar15;
  short sVar16;
  short sVar17;
  int iVar18;
  int iVar19;
  ushort uVar20;
  uint unaff_s7;
  uint uVar21;
  undefined4 auStack_44 [4];
  
  if (param_2 < 7) {
    return;
  }
  iVar19 = *(int *)(_lld_scan_env + param_1 * 4);
  iVar18 = param_3 * 0x14 + 0x10;
  iVar11 = r_emi_get_mem_addr_by_offset(0x1000);
  iVar6 = param_3 * 0x14 + 4;
  uVar20 = *(ushort *)(iVar11 + iVar18) & 0x3f;
  *param_4 = (byte)uVar20;
  iVar11 = r_emi_get_mem_addr_by_offset(0x1000);
  if (*(ushort *)(iVar11 + iVar6) >> 8 <= uVar20) {
    r_assert_err(0,"lld_scan.c",0x816);
  }
  bVar13 = *param_4;
  if (bVar13 != 0) {
    bVar13 = bVar13 - 1;
  }
  param_4[4] = bVar13;
  iVar11 = r_emi_get_mem_addr_by_offset(0x1000);
  bVar13 = *param_4;
  param_4[5] = (char)((ushort)*(undefined2 *)(iVar11 + iVar6) >> 8) + ~bVar13;
  *(undefined1 *)(iVar19 + 0x3e) = 0;
  if (bVar13 != 0) {
    iVar6 = r_emi_get_mem_addr_by_offset(0x1000);
    *(undefined2 *)(param_4 + 6) = *(undefined2 *)(iVar6 + iVar18);
  }
  cVar2 = *(char *)(iVar19 + 0x3d);
  if (cVar2 != '\x01') {
    if (cVar2 != '\0') {
      if (cVar2 != '\x02') {
        if (cVar2 != '\x03') {
          r_assert_err(0,"lld_scan.c",0x83d);
          return;
        }
        iVar6 = *(int *)(_lld_scan_env + param_1 * 4);
        iVar11 = r_emi_get_mem_addr_by_offset(0x1000,param_2);
        bVar13 = param_4[5];
        sVar3 = *(short *)(iVar11 + param_3 * 0x14 + 0x12);
        uVar15 = (uint)*(ushort *)(iVar6 + 0x36) + (uint)bVar13;
        iVar11 = uVar15 * 0x10000;
        *(char *)(iVar6 + 0x41) = *(char *)(iVar6 + 0x41) + '\x01';
        *(short *)(iVar6 + 0x36) = (short)((uint)iVar11 >> 0x10);
        if (0x672 < (uVar15 & 0xffff)) {
          *(undefined1 *)(iVar6 + 0x6e) = 2;
          param_4[5] = (bVar13 + 0x72) - (char)((uint)iVar11 >> 0x10);
          goto _L329;
        }
        if (*param_4 == 0) {
          uVar12 = 0;
          if ((*(byte *)(iVar6 + 0x6d) & 8) == 0) {
            uVar12 = 2;
          }
          *(undefined1 *)(iVar6 + 0x6e) = uVar12;
          goto _L329;
        }
        uVar20 = *(ushort *)(param_4 + 6);
        sVar16 = 0;
        if ((uVar20 & 0x100) != 0) {
          sVar16 = 6;
        }
        if ((uVar20 & 0x200) != 0) {
          sVar16 = sVar16 + 6;
        }
        if ((uVar20 & 0x400) != 0) {
          sVar16 = sVar16 + 1;
        }
        if ((int)((uint)uVar20 << 0x14) < 0) {
          psVar8 = (short *)r_emi_get_mem_addr_by_offset(sVar3 + sVar16);
          if (*(short *)(iVar6 + 0x34) == *psVar8) {
            sVar16 = sVar16 + 2;
_L302:
            if (-1 < (int)((uint)*(ushort *)(param_4 + 6) << 0x13)) {
              *(undefined1 *)(iVar6 + 0x6e) = 0;
              *(undefined1 *)(iVar6 + 0x3d) = 0;
              goto _L307;
            }
            pvVar9 = (void *)r_emi_get_mem_addr_by_offset(sVar3 + sVar16);
            memcpy(&stack0xffffffdc,pvVar9,3);
            iVar11 = r_emi_get_mem_addr_by_offset(0x1000);
            if ((*(ushort *)(param_3 * 0x14 + 2 + iVar11) >> 9 & 1) == 0) {
              if (*(byte *)(iVar6 + 0x41) < 7) {
                iVar11 = r_lld_calc_aux_rx(iVar6 + 0x48,param_3,unaff_s7);
                uVar12 = 1;
                if (iVar11 != 0) goto _L328;
              }
              *(undefined1 *)(iVar6 + 0x6e) = 2;
            }
            else {
              *(uint *)(iVar6 + 0x2c) = unaff_s7;
              uVar12 = 2;
_L328:
              *(undefined1 *)(iVar6 + 0x3e) = uVar12;
            }
            *(undefined1 *)(iVar6 + 0x3d) = 3;
            sVar16 = sVar16 + 3;
_L307:
            if ((int)((uint)*(ushort *)(param_4 + 6) << 0x12) < 0) {
              sVar16 = sVar16 + 0x12;
            }
            if (-1 < (int)((uint)*(ushort *)(param_4 + 6) << 0x11)) {
              return;
            }
            puVar10 = (undefined1 *)r_emi_get_mem_addr_by_offset(sVar3 + sVar16);
            *(undefined1 *)(iVar6 + 0x73) = *puVar10;
            return;
          }
        }
        else if ((*(byte *)(iVar6 + 0x6d) & 8) != 0) goto _L302;
        *(undefined1 *)(iVar6 + 0x6e) = 2;
        param_4[5] = 0;
_L329:
        *(undefined1 *)(iVar6 + 0x3d) = 0;
        return;
      }
      iVar18 = param_3 * 0x14;
      iVar6 = *(int *)(_lld_scan_env + param_1 * 4);
      iVar11 = r_emi_get_mem_addr_by_offset(0x1000,param_2);
      sVar3 = *(short *)(iVar11 + iVar18 + 0x12);
      *(ushort *)(iVar6 + 0x36) = (ushort)param_4[5];
      *(undefined1 *)(iVar6 + 0x6e) = 1;
      *(byte *)(iVar6 + 0x6d) = *(byte *)(iVar6 + 0x6d) | 8;
      if (*param_4 == 0) {
        *(undefined1 *)(iVar6 + 0x6e) = 0;
        *(undefined1 *)(iVar6 + 0x3d) = 0;
        return;
      }
      sVar16 = 0;
      if ((*(ushort *)(param_4 + 6) & 0x100) != 0) {
        iVar11 = r_emi_get_mem_addr_by_offset(0x1000);
        bVar13 = (byte)(*(ushort *)(iVar11 + iVar18 + 4) >> 6) & 1;
        param_4[8] = bVar13;
        *(byte *)(iVar6 + 0x6f) = bVar13;
        if (((*(char *)(_lld_scan_env + 0x15) == '\x01') ||
            ((*(char *)(_lld_scan_env + 0x15) == '\x03' && ((*(ushort *)(param_4 + 6) & 0x200) == 0)
             ))) && (iVar11 = r_emi_get_mem_addr_by_offset(0x1000),
                    -1 < (int)((uint)*(ushort *)(iVar11 + iVar18 + 2) << 0x14))) {
          *(undefined1 *)(iVar6 + 0x6e) = 0xff;
          return;
        }
        sVar16 = 6;
      }
      uVar20 = *(ushort *)(param_4 + 6);
      if ((uVar20 & 0x200) != 0) {
        sVar16 = sVar16 + 6;
      }
      if ((uVar20 & 0x400) != 0) {
        sVar16 = sVar16 + 1;
      }
      if ((int)((uint)uVar20 << 0x14) < 0) {
        sVar16 = sVar16 + 2;
      }
      if (-1 < (int)((uint)uVar20 << 0x13)) {
        *(undefined1 *)(iVar6 + 0x6e) = 0;
        *(undefined1 *)(iVar6 + 0x3d) = 0;
        goto _L272;
      }
      pvVar9 = (void *)r_emi_get_mem_addr_by_offset(sVar3 + sVar16);
      memcpy(&stack0xffffffdc,pvVar9,3);
      iVar11 = r_emi_get_mem_addr_by_offset(0x1000);
      if ((*(ushort *)(iVar18 + 2 + iVar11) >> 9 & 1) == 0) {
        iVar11 = r_lld_calc_aux_rx(iVar6 + 0x48,param_3);
        uVar12 = 1;
        if (iVar11 != 0) goto _L292;
        *(undefined1 *)(iVar6 + 0x6e) = 2;
      }
      else {
        *(uint *)(iVar6 + 0x2c) = unaff_s7;
        uVar12 = 2;
_L292:
        *(undefined1 *)(iVar6 + 0x3e) = uVar12;
      }
      *(undefined1 *)(iVar6 + 0x3d) = 3;
      sVar16 = sVar16 + 3;
_L272:
      if ((int)((uint)*(ushort *)(param_4 + 6) << 0x12) < 0) {
        sVar16 = sVar16 + 0x12;
      }
      if ((int)((uint)*(ushort *)(param_4 + 6) << 0x11) < 0) {
        puVar10 = (undefined1 *)r_emi_get_mem_addr_by_offset(sVar3 + sVar16);
        *(undefined1 *)(iVar6 + 0x73) = *puVar10;
      }
      return;
    }
    iVar6 = *(int *)(_lld_scan_env + param_1 * 4);
    if (*(char *)(iVar6 + 0x3d) != '\0') {
      return;
    }
    iVar18 = param_3 * 0x14;
    iVar11 = r_emi_get_mem_addr_by_offset(0x1000,param_2);
    sVar3 = *(short *)(iVar11 + iVar18 + 0x12);
    memset((void *)(iVar6 + 0x58),0,0x2c);
    *(undefined2 *)(iVar6 + 0x36) = 0;
    *(undefined1 *)(iVar6 + 0x41) = 0;
    r_lld_ext_scan_dynamic_pti_process_eco(iVar6,0);
    *(undefined1 *)(iVar6 + 0x6e) = 1;
    *(undefined1 *)(iVar6 + 0x71) = *(undefined1 *)(iVar6 + 0x3b);
    iVar11 = r_emi_get_mem_addr_by_offset(0x1000);
    uVar20 = *(ushort *)(iVar11 + iVar18 + 0x10) >> 6;
    uVar14 = uVar20 & 3;
    param_4[1] = (byte)uVar14;
    if (uVar14 == 1) {
      bVar13 = *(byte *)(iVar6 + 0x6d) | 1;
_L254:
      *(byte *)(iVar6 + 0x6d) = bVar13;
    }
    else if (uVar14 == 2) {
      bVar13 = *(byte *)(iVar6 + 0x6d) | 2;
      goto _L254;
    }
    *(undefined1 *)(iVar6 + 0x6a) = 0;
    if (*param_4 == 0) {
      *(undefined1 *)(iVar6 + 0x6e) = 0;
    }
    else {
      uVar14 = *(ushort *)(param_4 + 6);
      sVar16 = 0;
      if ((uVar14 & 0x100) != 0) {
        if (((uVar20 & 3) == 0) &&
           ((*(char *)(iVar6 + 0x3b) == '\0' || (-1 < (int)((uint)uVar14 << 0x13))))) {
          iVar11 = r_emi_get_mem_addr_by_offset(0x1000);
          param_4[8] = (byte)(*(ushort *)(iVar11 + iVar18 + 4) >> 6) & 1;
          pvVar9 = (void *)r_emi_get_mem_addr_by_offset((ushort)param_4[3] + sVar3);
          memcpy((void *)(iVar6 + 0x5c),pvVar9,6);
        }
        else {
          *(ushort *)(param_4 + 6) = uVar14 & 0xfeff;
        }
        sVar16 = 6;
      }
      uVar20 = *(ushort *)(param_4 + 6);
      if ((uVar20 & 0x200) != 0) {
        if ((param_4[1] == 0) &&
           ((*(char *)(iVar6 + 0x3b) == '\0' || (-1 < (int)((uint)uVar20 << 0x13))))) {
          *(byte *)(iVar6 + 0x6d) = *(byte *)(iVar6 + 0x6d) | 4;
          iVar11 = r_emi_get_mem_addr_by_offset(0x1000);
          *(byte *)(iVar6 + 0x70) = (byte)(*(ushort *)(iVar11 + iVar18 + 4) >> 7) & 1;
          param_4[2] = (byte)sVar16;
        }
        else {
          *(ushort *)(param_4 + 6) = uVar20 & 0xfdff;
        }
        sVar16 = sVar16 + 6;
      }
      if ((*(ushort *)(param_4 + 6) & 0x400) != 0) {
        sVar16 = sVar16 + 1;
      }
      if ((int)((uint)*(ushort *)(param_4 + 6) << 0x14) < 0) {
        puVar7 = (undefined2 *)r_emi_get_mem_addr_by_offset(sVar3 + sVar16);
        uVar4 = *puVar7;
        sVar16 = sVar16 + 2;
        *(undefined2 *)(iVar6 + 0x34) = uVar4;
        *(undefined2 *)(iVar6 + 0x68) = uVar4;
        *(undefined1 *)(iVar6 + 0x6a) = 1;
      }
      if ((int)((uint)*(ushort *)(param_4 + 6) << 0x13) < 0) {
        pvVar9 = (void *)r_emi_get_mem_addr_by_offset(sVar3 + sVar16);
        memcpy(&stack0xffffffdc,pvVar9,3);
        iVar11 = r_emi_get_mem_addr_by_offset(0x1000);
        if ((*(ushort *)(iVar18 + 2 + iVar11) >> 9 & 1) == 0) {
          if (2 < (unaff_s7 >> 0x15 & 7)) {
_L220:
            *(undefined1 *)(iVar6 + 0x6e) = 0xff;
            return;
          }
          iVar11 = r_lld_calc_aux_rx(iVar6 + 0x48,param_3);
          uVar12 = 1;
          if (iVar11 == 0) goto _L220;
        }
        else {
          *(uint *)(iVar6 + 0x2c) = unaff_s7;
          uVar12 = 2;
        }
        *(undefined1 *)(iVar6 + 0x3e) = uVar12;
        *(undefined1 *)(iVar6 + 0x3d) = 1;
        sVar16 = sVar16 + 3;
      }
      else {
        *(char *)(iVar6 + 0x6e) = -(*(char *)(iVar6 + 0x6f) == -1);
        *(undefined1 *)(iVar6 + 0x72) = 4;
      }
      uVar15 = (uint)*(ushort *)(param_4 + 6);
      if ((int)(uVar15 << 0x12) < 0) {
        sVar16 = sVar16 + 0x12;
      }
      if ((int)(uVar15 << 0x11) < 0) {
        if ((*(char *)(iVar6 + 0x3b) != '\0') && ((param_4[1] != 0 || ((int)(uVar15 << 0x13) < 0))))
        goto _L226;
        puVar10 = (undefined1 *)r_emi_get_mem_addr_by_offset(sVar3 + sVar16);
        uVar12 = *puVar10;
      }
      else {
        uVar12 = 0x7f;
      }
      *(undefined1 *)(iVar6 + 0x73) = uVar12;
    }
_L226:
    *(byte *)(iVar6 + 0x6f) = param_4[8];
    param_4[5] = 0;
    return;
  }
  iVar18 = param_3 * 0x14;
  iVar6 = *(int *)(_lld_scan_env + param_1 * 4);
  iVar11 = r_emi_get_mem_addr_by_offset(0x1000,param_2);
  sVar3 = *(short *)(iVar11 + iVar18 + 0x12);
  *(ushort *)(iVar6 + 0x36) = (ushort)param_4[5];
  iVar11 = r_emi_get_mem_addr_by_offset(0x1000);
  *(byte *)(iVar6 + 0x72) = (byte)((ushort)*(undefined2 *)(iVar11 + iVar18 + 6) >> 0xe);
  puVar10 = _lld_scan_sync_env;
  if (*param_4 == 0) {
    *(undefined1 *)(iVar6 + 0x6e) = 0xff;
    *(undefined1 *)(iVar6 + 0x3d) = 0;
    return;
  }
  if ((*(ushort *)(param_4 + 6) & 0x100) == 0) {
    sVar17 = 0;
    sVar16 = 0;
    if ((((*(byte *)(_lld_scan_env + 0x15) & 0xfd) == 1) &&
        (sVar16 = sVar17, *(char *)(iVar6 + 0x6f) == -1)) && ((_DAT_60031000 >> 10 & 1) != 0)) {
      *(undefined1 *)(iVar6 + 0x6e) = 0xff;
    }
  }
  else {
    if ((param_4[1] == 0) && (*(char *)(iVar6 + 0x6f) != -1)) {
      *(ushort *)(param_4 + 6) = *(ushort *)(param_4 + 6) & 0xfeff;
    }
    else {
      iVar11 = r_emi_get_mem_addr_by_offset(0x1000);
      bVar13 = (byte)(*(ushort *)(iVar11 + iVar18 + 4) >> 6) & 1;
      param_4[8] = bVar13;
      *(byte *)(iVar6 + 0x6f) = bVar13;
      pvVar9 = (void *)r_emi_get_mem_addr_by_offset((ushort)param_4[3] + sVar3);
      memcpy((void *)(iVar6 + 0x5c),pvVar9,6);
      if (((*(char *)(_lld_scan_env + 0x15) == '\x01') ||
          ((*(char *)(_lld_scan_env + 0x15) == '\x03' && ((*(ushort *)(param_4 + 6) & 0x200) == 0)))
          ) && (iVar11 = r_emi_get_mem_addr_by_offset(0x1000),
               -1 < (int)((uint)*(ushort *)(iVar11 + iVar18 + 2) << 0x14))) {
        *(undefined1 *)(iVar6 + 0x6e) = 0xff;
      }
    }
    sVar16 = 6;
  }
  if ((*(ushort *)(param_4 + 6) & 0x200) != 0) {
    if (*(byte *)(iVar6 + 0x6d) == 4) {
      *(ushort *)(param_4 + 6) = *(ushort *)(param_4 + 6) & 0xfdff;
    }
    else {
      *(byte *)(iVar6 + 0x6d) = *(byte *)(iVar6 + 0x6d) | 4;
      iVar11 = r_emi_get_mem_addr_by_offset(0x1000);
      *(byte *)(iVar6 + 0x70) = (byte)(*(ushort *)(iVar11 + iVar18 + 4) >> 7) & 1;
      param_4[2] = (byte)sVar16;
    }
    sVar16 = sVar16 + 6;
  }
  if ((*(ushort *)(param_4 + 6) & 0x400) != 0) {
    sVar16 = sVar16 + 1;
  }
  if (-1 < (int)((uint)*(ushort *)(param_4 + 6) << 0x14)) {
    *(undefined1 *)(iVar6 + 0x6e) = 0xff;
    return;
  }
  psVar8 = (short *)r_emi_get_mem_addr_by_offset(sVar3 + sVar16);
  bVar1 = *(short *)(iVar6 + 0x34) != *psVar8;
  if (bVar1) {
    *(undefined1 *)(iVar6 + 0x6e) = 0xff;
  }
  sVar17 = sVar16 + 2;
  if (*(char *)(iVar6 + 0x6e) == -1) {
    if ((*(ushort *)(param_4 + 6) & 0x1000) != 0) goto _L534;
  }
  else {
    if ((*(ushort *)(param_4 + 6) & 0x1000) == 0) {
      if (((*(byte *)(iVar6 + 0x6d) & 2) == 0) || (*(char *)(iVar6 + 0x39) != '\x01')) {
        *(undefined1 *)(iVar6 + 0x6e) = 0;
        *(undefined1 *)(iVar6 + 0x3d) = 0;
      }
      else {
        *(undefined1 *)(iVar6 + 0x6e) = 0;
        *(undefined1 *)(iVar6 + 0x3d) = 2;
      }
      goto _L484;
    }
    pvVar9 = (void *)r_emi_get_mem_addr_by_offset(sVar3 + sVar17);
    memcpy(auStack_44,pvVar9,3);
    iVar11 = r_emi_get_mem_addr_by_offset(0x1000);
    if ((*(ushort *)(iVar11 + iVar18 + 2) >> 9 & 1) == 0) {
      iVar11 = r_lld_calc_aux_rx(iVar6 + 0x48,param_3);
      uVar12 = 1;
      if (iVar11 != 0) goto _L533;
      *(undefined1 *)(iVar6 + 0x6e) = 2;
    }
    else {
      *(undefined4 *)(iVar6 + 0x2c) = auStack_44[0];
      uVar12 = 2;
_L533:
      *(undefined1 *)(iVar6 + 0x3e) = uVar12;
    }
    *(undefined1 *)(iVar6 + 0x3d) = 3;
_L534:
    sVar17 = sVar16 + 5;
  }
_L484:
  if (-1 < (int)((uint)*(ushort *)(param_4 + 6) << 0x12)) goto _L486;
  if (bVar1 || puVar10 == (undefined1 *)0x0) {
_L487:
    puVar7 = (undefined2 *)r_emi_get_mem_addr_by_offset(sVar3 + 2 + sVar17);
    *(undefined2 *)(iVar6 + 0x76) = *puVar7;
  }
  else {
    uVar20 = *(ushort *)(iVar6 + 0x68);
    iVar11 = r_lld_scan_sync_accept
                       (param_1,param_3,*(undefined1 *)(iVar6 + 0x6f),*(undefined4 *)(iVar6 + 0x5c),
                        *(undefined4 *)(iVar6 + 0x60),uVar20 >> 0xc);
    if (iVar11 == 0) goto _L487;
    puVar10 = (undefined1 *)r_ke_msg_alloc(0x203,0,0xff,0x30);
    iVar11 = r_lld_scan_sync_info_unpack(puVar10 + 2,sVar3 + sVar17);
    if (iVar11 == 0) {
      if (*(short *)(puVar10 + 2) == 0) {
        *(undefined2 *)(iVar6 + 0x76) = *(undefined2 *)(puVar10 + 6);
      }
      r_ke_msg_free(puVar10 + -0xc);
    }
    else {
      *puVar10 = *_lld_scan_sync_env;
      iVar11 = r_emi_get_mem_addr_by_offset(0x1000);
      puVar10[0x1e] = (byte)((ushort)*(undefined2 *)(iVar11 + iVar18 + 6) >> 0xe);
      iVar11 = r_emi_get_mem_addr_by_offset(0x1000);
      uVar14 = *(ushort *)(iVar11 + iVar18 + 10);
      if ((uVar14 & 0xf000) != 0) {
        r_assert_err(0,"lld_scan.c",1000);
      }
      iVar11 = r_emi_get_mem_addr_by_offset(0x1000);
      *(uint *)(puVar10 + 0x18) = CONCAT22(uVar14,*(undefined2 *)(iVar11 + iVar18 + 8));
      iVar11 = r_emi_get_mem_addr_by_offset(0x1000);
      uVar15 = ((uint)*(ushort *)(&lld_exp_sync_pos_tab + (uint)(byte)puVar10[0x1e] * 2) * -2 +
               0x270) - (*(ushort *)(iVar11 + iVar18 + 0xc) & 0x3ff);
      uVar21 = (uint)(short)uVar15;
      if (((g_bt_plf_log_level & 2) != 0) && (((byte)puVar10[0x1e] - 2 & 0xff) < 2)) {
        uVar21 = (int)(((uVar15 & 0xffff) + (uint)_DAT_000150c6 * -2) * 0x10000) >> 0x10;
      }
      if (0x751 < (uVar21 + 0x4e1 & 0xffff)) {
        r_assert_err(0,"lld_scan.c",0x6c2);
      }
      for (; (int)uVar21 < 0; uVar21 = (int)(((uVar21 & 0xffff) + 0x271) * 0x10000) >> 0x10) {
        *(uint *)(puVar10 + 0x18) = *(int *)(puVar10 + 0x18) - 1U & 0xfffffff;
      }
      *(short *)(puVar10 + 0x1c) = (short)uVar21;
      iVar11 = r_emi_get_mem_addr_by_offset(0x1000);
      puVar5 = _lld_scan_sync_env;
      uVar4 = *(undefined2 *)(iVar18 + 0xe + iVar11);
      puVar10[0x1f] = (byte)(uVar20 >> 0xc);
      *(undefined2 *)(puVar10 + 0x20) = uVar4;
      puVar10[0x22] = puVar5[3];
      memcpy(puVar10 + 0x23,puVar5 + 4,6);
      r_ke_msg_send(puVar10);
      r_ke_free(_lld_scan_sync_env);
      _lld_scan_sync_env = (undefined1 *)0x0;
    }
  }
  sVar17 = sVar17 + 0x12;
_L486:
  if ((int)((uint)*(ushort *)(param_4 + 6) << 0x11) < 0) {
    puVar10 = (undefined1 *)r_emi_get_mem_addr_by_offset(sVar3 + sVar17);
    *(undefined1 *)(iVar6 + 0x73) = *puVar10;
  }
  return;
}

