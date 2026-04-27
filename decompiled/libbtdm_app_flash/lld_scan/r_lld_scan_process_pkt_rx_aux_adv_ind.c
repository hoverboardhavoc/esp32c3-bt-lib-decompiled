/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> lld_scan.o -> r_lld_scan_process_pkt_rx_aux_adv_ind
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_scan_process_pkt_rx_aux_adv_ind(int param_1,int param_2,char *param_3)

{
  bool bVar1;
  short sVar2;
  ushort uVar3;
  ushort uVar4;
  undefined2 uVar5;
  byte *pbVar6;
  int iVar7;
  short sVar8;
  int iVar9;
  void *pvVar10;
  short *psVar11;
  byte *pbVar12;
  undefined1 *puVar13;
  undefined2 *puVar14;
  byte bVar15;
  undefined1 uVar16;
  int iVar17;
  uint uVar18;
  uint uVar19;
  short sVar20;
  undefined4 auStack_44 [4];
  
  iVar17 = param_2 * 0x14;
  iVar7 = *(int *)(_lld_scan_env + param_1 * 4);
  iVar9 = r_emi_get_mem_addr_by_offset(0x1000);
  sVar2 = *(short *)(iVar17 + 0x12 + iVar9);
  *(ushort *)(iVar7 + 0x36) = (ushort)(byte)param_3[5];
  iVar9 = r_emi_get_mem_addr_by_offset(0x1000);
  *(byte *)(iVar7 + 0x72) = (byte)((ushort)*(undefined2 *)(iVar9 + iVar17 + 6) >> 0xe);
  pbVar12 = _lld_scan_sync_env;
  if (*param_3 == '\0') {
    *(undefined1 *)(iVar7 + 0x6e) = 0xff;
    *(undefined1 *)(iVar7 + 0x3d) = 0;
    return;
  }
  if ((*(ushort *)(param_3 + 6) & 0x100) == 0) {
    sVar20 = 0;
    sVar8 = 0;
    if ((((*(byte *)(_lld_scan_env + 0x15) & 0xfd) == 1) &&
        (sVar8 = sVar20, *(char *)(iVar7 + 0x6f) == -1)) && ((_DAT_60031000 >> 10 & 1) != 0)) {
      *(undefined1 *)(iVar7 + 0x6e) = 0xff;
    }
  }
  else {
    if ((param_3[1] == '\0') && (*(char *)(iVar7 + 0x6f) != -1)) {
      *(ushort *)(param_3 + 6) = *(ushort *)(param_3 + 6) & 0xfeff;
    }
    else {
      iVar9 = r_emi_get_mem_addr_by_offset(0x1000);
      bVar15 = (byte)(*(ushort *)(iVar17 + 4 + iVar9) >> 6) & 1;
      param_3[8] = bVar15;
      *(byte *)(iVar7 + 0x6f) = bVar15;
      pvVar10 = (void *)r_emi_get_mem_addr_by_offset((ushort)(byte)param_3[3] + sVar2);
      memcpy((void *)(iVar7 + 0x5c),pvVar10,6);
      if (((*(char *)(_lld_scan_env + 0x15) == '\x01') ||
          ((*(char *)(_lld_scan_env + 0x15) == '\x03' && ((*(ushort *)(param_3 + 6) & 0x200) == 0)))
          ) && (iVar9 = r_emi_get_mem_addr_by_offset(0x1000),
               (*(ushort *)(iVar17 + 2 + iVar9) >> 0xb & 1) == 0)) {
        *(undefined1 *)(iVar7 + 0x6e) = 0xff;
      }
    }
    sVar8 = 6;
  }
  if ((*(ushort *)(param_3 + 6) & 0x200) != 0) {
    if (*(byte *)(iVar7 + 0x6d) == 4) {
      *(ushort *)(param_3 + 6) = *(ushort *)(param_3 + 6) & 0xfdff;
    }
    else {
      *(byte *)(iVar7 + 0x6d) = *(byte *)(iVar7 + 0x6d) | 4;
      iVar9 = r_emi_get_mem_addr_by_offset(0x1000);
      *(byte *)(iVar7 + 0x70) = (byte)(*(ushort *)(iVar17 + 4 + iVar9) >> 7) & 1;
      param_3[2] = (char)sVar8;
    }
    sVar8 = sVar8 + 6;
  }
  if ((*(ushort *)(param_3 + 6) & 0x400) != 0) {
    sVar8 = sVar8 + 1;
  }
  if ((*(ushort *)(param_3 + 6) >> 0xb & 1) == 0) {
    *(undefined1 *)(iVar7 + 0x6e) = 0xff;
    return;
  }
  psVar11 = (short *)r_emi_get_mem_addr_by_offset(sVar2 + sVar8);
  bVar1 = *(short *)(iVar7 + 0x34) != *psVar11;
  if (bVar1) {
    *(undefined1 *)(iVar7 + 0x6e) = 0xff;
  }
  sVar20 = sVar8 + 2;
  if (*(char *)(iVar7 + 0x6e) == -1) {
    if ((*(ushort *)(param_3 + 6) & 0x1000) == 0) goto _L476;
  }
  else {
    if ((*(ushort *)(param_3 + 6) & 0x1000) == 0) {
      if (((*(byte *)(iVar7 + 0x6d) & 2) == 0) || (*(char *)(iVar7 + 0x39) != '\x01')) {
        *(undefined1 *)(iVar7 + 0x6e) = 0;
        *(undefined1 *)(iVar7 + 0x3d) = 0;
      }
      else {
        *(undefined1 *)(iVar7 + 0x6e) = 0;
        *(undefined1 *)(iVar7 + 0x3d) = 2;
      }
      goto _L476;
    }
    pvVar10 = (void *)r_emi_get_mem_addr_by_offset(sVar2 + sVar20);
    memcpy(auStack_44,pvVar10,3);
    iVar9 = r_emi_get_mem_addr_by_offset(0x1000);
    if ((*(ushort *)(iVar17 + 2 + iVar9) >> 9 & 1) == 0) {
      iVar9 = r_lld_calc_aux_rx(iVar7 + 0x48,param_2);
      uVar16 = 1;
      if (iVar9 != 0) goto _L525;
      *(undefined1 *)(iVar7 + 0x6e) = 2;
    }
    else {
      *(undefined4 *)(iVar7 + 0x2c) = auStack_44[0];
      uVar16 = 2;
_L525:
      *(undefined1 *)(iVar7 + 0x3e) = uVar16;
    }
    *(undefined1 *)(iVar7 + 0x3d) = 3;
  }
  sVar20 = sVar8 + 5;
_L476:
  if ((*(ushort *)(param_3 + 6) & 0x2000) != 0) {
    uVar3 = *(ushort *)(iVar7 + 0x68);
    if ((bVar1 || pbVar12 == (byte *)0x0) ||
       (iVar9 = r_lld_scan_sync_accept
                          (param_1,param_2,*(undefined1 *)(iVar7 + 0x6f),
                           *(undefined4 *)(iVar7 + 0x5c),*(undefined4 *)(iVar7 + 0x60),uVar3 >> 0xc)
       , iVar9 == 0)) {
      puVar14 = (undefined2 *)r_emi_get_mem_addr_by_offset(sVar20 + sVar2 + 2);
      *(undefined2 *)(iVar7 + 0x76) = *puVar14;
    }
    else {
      pbVar12 = (byte *)r_ke_msg_alloc(0x203,0,0xff,0x30);
      iVar9 = r_lld_scan_sync_info_unpack(pbVar12 + 2,sVar20 + sVar2);
      if (iVar9 == 0) {
        if (*(short *)(pbVar12 + 2) == 0) {
          *(undefined2 *)(iVar7 + 0x76) = *(undefined2 *)(pbVar12 + 6);
        }
        r_ke_msg_free(pbVar12 + -0xc);
        r_ble_log_internal_x0(0x80a10147);
      }
      else {
        *pbVar12 = *_lld_scan_sync_env;
        iVar9 = r_emi_get_mem_addr_by_offset(0x1000);
        pbVar12[0x1e] = (byte)((ushort)*(undefined2 *)(iVar9 + iVar17 + 6) >> 0xe);
        iVar9 = r_emi_get_mem_addr_by_offset(0x1000);
        uVar4 = *(ushort *)(iVar17 + 10 + iVar9);
        if ((uVar4 & 0xf000) != 0) {
          r_assert_err(0,"lld_scan.c",1000);
        }
        iVar9 = r_emi_get_mem_addr_by_offset(0x1000);
        *(uint *)(pbVar12 + 0x18) = CONCAT22(uVar4,*(undefined2 *)(iVar17 + 8 + iVar9));
        iVar9 = r_emi_get_mem_addr_by_offset(0x1000);
        uVar18 = ((uint)*(ushort *)(&lld_exp_sync_pos_tab + (uint)pbVar12[0x1e] * 2) * -2 + 0x270) -
                 (*(ushort *)(iVar17 + 0xc + iVar9) & 0x3ff);
        uVar19 = (int)(uVar18 * 0x10000) >> 0x10;
        if ((((byte)r_bt_rf_coex_st_param_get & 2) != 0) && ((pbVar12[0x1e] - 2 & 0xff) < 2)) {
          uVar19 = (int)(((uVar18 & 0xffff) + (uint)_DAT_000150ce * -2) * 0x10000) >> 0x10;
        }
        if (0x751 < (uVar19 + 0x4e1 & 0xffff)) {
          r_assert_err(0,"lld_scan.c",0x713);
        }
        for (; (int)uVar19 < 0; uVar19 = (int)(((uVar19 & 0xffff) + 0x271) * 0x10000) >> 0x10) {
          *(uint *)(pbVar12 + 0x18) = *(int *)(pbVar12 + 0x18) - 1U & 0xfffffff;
        }
        *(short *)(pbVar12 + 0x1c) = (short)uVar19;
        iVar9 = r_emi_get_mem_addr_by_offset(0x1000);
        pbVar6 = _lld_scan_sync_env;
        uVar5 = *(undefined2 *)(iVar17 + 0xe + iVar9);
        pbVar12[0x1f] = (byte)(uVar3 >> 0xc);
        *(undefined2 *)(pbVar12 + 0x20) = uVar5;
        pbVar12[0x22] = pbVar6[3];
        memcpy(pbVar12 + 0x23,pbVar6 + 4,6);
        r_ke_msg_send(pbVar12);
        r_ke_free(_lld_scan_sync_env);
        _lld_scan_sync_env = (byte *)0x0;
        r_ble_log_internal_x2
                  (0x40a10146,*(undefined4 *)(pbVar12 + 0x18),
                   (uint)*(ushort *)(pbVar12 + 0x1c) |
                   (uint)*pbVar12 << 0x10 | (uint)pbVar12[0x1f] << 0x18);
      }
    }
    sVar20 = sVar20 + 0x12;
  }
  if ((*(ushort *)(param_3 + 6) & 0x4000) != 0) {
    puVar13 = (undefined1 *)r_emi_get_mem_addr_by_offset(sVar2 + sVar20);
    *(undefined1 *)(iVar7 + 0x73) = *puVar13;
  }
  return;
}

