/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  undefined1 *puVar6;
  int iVar7;
  short sVar8;
  int iVar9;
  void *pvVar10;
  short *psVar11;
  undefined1 *puVar12;
  undefined2 *puVar13;
  uint uVar14;
  byte bVar15;
  undefined1 uVar16;
  uint uVar17;
  int iVar18;
  short sVar19;
  undefined4 auStack_44 [4];
  
  iVar18 = param_2 * 0x14;
  iVar7 = *(int *)(_lld_scan_env + param_1 * 4);
  iVar9 = r_emi_get_mem_addr_by_offset(0x1000);
  sVar2 = *(short *)(iVar18 + 0x12 + iVar9);
  *(ushort *)(iVar7 + 0x36) = (ushort)(byte)param_3[5];
  iVar9 = r_emi_get_mem_addr_by_offset(0x1000);
  *(byte *)(iVar7 + 0x72) = (byte)((ushort)*(undefined2 *)(iVar9 + iVar18 + 6) >> 0xe);
  puVar12 = _lld_scan_sync_env;
  if (*param_3 == '\0') {
    *(undefined1 *)(iVar7 + 0x6e) = 0xff;
    *(undefined1 *)(iVar7 + 0x3d) = 0;
    return;
  }
  if ((*(ushort *)(param_3 + 6) & 0x100) == 0) {
    if ((((*(byte *)(_lld_scan_env + 0x15) & 0xfd) == 1) && (*(char *)(iVar7 + 0x6f) == -1)) &&
       ((_DAT_60031000 >> 10 & 1) != 0)) {
      *(undefined1 *)(iVar7 + 0x6e) = 0xff;
    }
    sVar8 = 0;
  }
  else {
    if ((param_3[1] == '\0') && (*(char *)(iVar7 + 0x6f) != -1)) {
      *(ushort *)(param_3 + 6) = *(ushort *)(param_3 + 6) & 0xfeff;
    }
    else {
      iVar9 = r_emi_get_mem_addr_by_offset(0x1000);
      bVar15 = (byte)(*(ushort *)(iVar18 + 4 + iVar9) >> 6) & 1;
      param_3[8] = bVar15;
      *(byte *)(iVar7 + 0x6f) = bVar15;
      pvVar10 = (void *)r_emi_get_mem_addr_by_offset((ushort)(byte)param_3[3] + sVar2);
      memcpy((void *)(iVar7 + 0x5c),pvVar10,6);
      if (((*(char *)(_lld_scan_env + 0x15) == '\x01') ||
          ((*(char *)(_lld_scan_env + 0x15) == '\x03' && ((*(ushort *)(param_3 + 6) & 0x200) == 0)))
          ) && (iVar9 = r_emi_get_mem_addr_by_offset(0x1000),
               -1 < (int)((uint)*(ushort *)(iVar18 + 2 + iVar9) << 0x14))) {
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
      *(byte *)(iVar7 + 0x70) = (byte)(*(ushort *)(iVar18 + 4 + iVar9) >> 7) & 1;
      param_3[2] = (char)sVar8;
    }
    sVar8 = sVar8 + 6;
  }
  sVar8 = sVar8 + (ushort)((*(ushort *)(param_3 + 6) & 0x400) != 0);
  if (-1 < (int)((uint)*(ushort *)(param_3 + 6) << 0x14)) {
    *(undefined1 *)(iVar7 + 0x6e) = 0xff;
    return;
  }
  psVar11 = (short *)r_emi_get_mem_addr_by_offset(sVar2 + sVar8);
  bVar1 = *(short *)(iVar7 + 0x34) != *psVar11;
  if (bVar1) {
    *(undefined1 *)(iVar7 + 0x6e) = 0xff;
  }
  sVar19 = sVar8 + 2;
  if (*(char *)(iVar7 + 0x6e) == -1) {
    if ((*(ushort *)(param_3 + 6) & 0x1000) != 0) goto _L510;
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
      goto _L464;
    }
    pvVar10 = (void *)r_emi_get_mem_addr_by_offset(sVar2 + sVar19);
    memcpy(auStack_44,pvVar10,3);
    iVar9 = r_emi_get_mem_addr_by_offset(0x1000);
    if ((*(ushort *)(iVar18 + 2 + iVar9) >> 9 & 1) == 0) {
      iVar9 = r_lld_calc_aux_rx(iVar7 + 0x48,param_2);
      uVar16 = 1;
      if (iVar9 != 0) goto _L509;
      *(undefined1 *)(iVar7 + 0x6e) = 2;
    }
    else {
      *(undefined4 *)(iVar7 + 0x2c) = auStack_44[0];
      uVar16 = 2;
_L509:
      *(undefined1 *)(iVar7 + 0x3e) = uVar16;
    }
    *(undefined1 *)(iVar7 + 0x3d) = 3;
_L510:
    sVar19 = sVar8 + 5;
  }
_L464:
  if (-1 < (int)((uint)*(ushort *)(param_3 + 6) << 0x12)) goto _L468;
  if (bVar1 || puVar12 == (undefined1 *)0x0) {
_L469:
    puVar13 = (undefined2 *)r_emi_get_mem_addr_by_offset(sVar19 + sVar2 + 2);
    *(undefined2 *)(iVar7 + 0x76) = *puVar13;
  }
  else {
    uVar3 = *(ushort *)(iVar7 + 0x68);
    iVar9 = r_lld_scan_sync_accept
                      (param_1,param_2,*(undefined1 *)(iVar7 + 0x6f),*(undefined4 *)(iVar7 + 0x5c),
                       *(undefined4 *)(iVar7 + 0x60),uVar3 >> 0xc);
    if (iVar9 == 0) goto _L469;
    puVar12 = (undefined1 *)r_ke_msg_alloc(0x203,0,0xff,0x30);
    iVar9 = r_lld_scan_sync_info_unpack(puVar12 + 2,sVar2 + sVar19);
    if (iVar9 == 0) {
      if (*(short *)(puVar12 + 2) == 0) {
        *(undefined2 *)(iVar7 + 0x76) = *(undefined2 *)(puVar12 + 6);
      }
      r_ke_msg_free(puVar12 + -0xc);
    }
    else {
      *puVar12 = *_lld_scan_sync_env;
      iVar9 = r_emi_get_mem_addr_by_offset(0x1000);
      puVar12[0x1e] = (byte)((ushort)*(undefined2 *)(iVar9 + iVar18 + 6) >> 0xe);
      iVar9 = r_emi_get_mem_addr_by_offset(0x1000);
      uVar4 = *(ushort *)(iVar18 + 10 + iVar9);
      if (0xfff < uVar4) {
        r_assert_err(0,"lld_scan.c",1000);
      }
      iVar9 = r_emi_get_mem_addr_by_offset(0x1000);
      *(uint *)(puVar12 + 0x18) = CONCAT22(uVar4,*(undefined2 *)(iVar18 + 8 + iVar9));
      iVar9 = r_emi_get_mem_addr_by_offset(0x1000);
      uVar17 = ((uint)*(ushort *)(&lld_exp_sync_pos_tab + (uint)(byte)puVar12[0x1e] * 2) * -2 +
               0x270) - (*(ushort *)(iVar18 + 0xc + iVar9) & 0x3ff);
      uVar14 = uVar17 & 0xffff;
      uVar17 = (int)(uVar17 * 0x10000) >> 0x10;
      if (((g_bt_plf_log_level & 2) != 0) && (((byte)puVar12[0x1e] - 2 & 0xff) < 2)) {
        uVar17 = uVar14 + (uint)_DAT_000150c6 * -2;
        uVar14 = uVar17 & 0xffff;
        uVar17 = (int)(uVar17 * 0x10000) >> 0x10;
      }
      if (0x751 < (uVar14 + 0x4e1 & 0xffff)) {
        r_assert_err(0,"lld_scan.c",0x6d1);
      }
      for (; (int)uVar17 < 0; uVar17 = (int)(((uVar17 & 0xffff) + 0x271) * 0x10000) >> 0x10) {
        *(uint *)(puVar12 + 0x18) = *(int *)(puVar12 + 0x18) - 1U & 0xfffffff;
      }
      *(short *)(puVar12 + 0x1c) = (short)uVar17;
      iVar9 = r_emi_get_mem_addr_by_offset(0x1000);
      puVar6 = _lld_scan_sync_env;
      uVar5 = *(undefined2 *)(iVar18 + 0xe + iVar9);
      puVar12[0x1f] = (byte)(uVar3 >> 0xc);
      *(undefined2 *)(puVar12 + 0x20) = uVar5;
      puVar12[0x22] = puVar6[3];
      memcpy(puVar12 + 0x23,puVar6 + 4,6);
      r_ke_msg_send(puVar12);
      r_ke_free(_lld_scan_sync_env);
      _lld_scan_sync_env = (undefined1 *)0x0;
    }
  }
  sVar19 = sVar19 + 0x12;
_L468:
  if ((int)((uint)*(ushort *)(param_3 + 6) << 0x11) < 0) {
    puVar12 = (undefined1 *)r_emi_get_mem_addr_by_offset(sVar2 + sVar19);
    *(undefined1 *)(iVar7 + 0x73) = *puVar12;
  }
  return;
}

