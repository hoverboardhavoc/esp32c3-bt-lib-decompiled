/*
 * Last changed at upstream commit aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * https://github.com/espressif/esp32c3-bt-lib/commit/aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * Upstream date: 2025-03-20 20:31:24 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(d74042a8)
 * Source: libbtdm_app_flash -> lld_scan.o -> r_lld_scan_process_pkt_rx_ext_adv_ind
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_scan_process_pkt_rx_ext_adv_ind(int param_1,int param_2,char *param_3)

{
  short sVar1;
  ushort uVar2;
  undefined2 uVar3;
  int iVar4;
  int iVar5;
  void *pvVar6;
  undefined2 *puVar7;
  undefined1 *puVar8;
  byte bVar9;
  undefined1 uVar10;
  ushort uVar11;
  uint uVar12;
  short sVar13;
  int iVar14;
  uint auStack_24 [2];
  
  iVar4 = *(int *)(_lld_scan_env + param_1 * 4);
  if (*(char *)(iVar4 + 0x3d) != '\0') {
    return;
  }
  iVar14 = param_2 * 0x14;
  iVar5 = r_emi_get_mem_addr_by_offset(0x1000);
  sVar1 = *(short *)(iVar5 + iVar14 + 0x12);
  memset((void *)(iVar4 + 0x58),0,0x2c);
  *(undefined2 *)(iVar4 + 0x36) = 0;
  *(undefined1 *)(iVar4 + 0x41) = 0;
  r_lld_ext_scan_dynamic_pti_process_eco(iVar4,0);
  *(undefined1 *)(iVar4 + 0x6e) = 1;
  *(undefined1 *)(iVar4 + 0x71) = *(undefined1 *)(iVar4 + 0x3b);
  iVar5 = r_emi_get_mem_addr_by_offset(0x1000);
  uVar2 = *(ushort *)(iVar5 + iVar14 + 0x10) >> 6;
  uVar11 = uVar2 & 3;
  param_3[1] = (char)uVar11;
  if (uVar11 == 1) {
    bVar9 = *(byte *)(iVar4 + 0x6d) | 1;
_L252:
    *(byte *)(iVar4 + 0x6d) = bVar9;
  }
  else if (uVar11 == 2) {
    bVar9 = *(byte *)(iVar4 + 0x6d) | 2;
    goto _L252;
  }
  *(undefined1 *)(iVar4 + 0x6a) = 0;
  if (*param_3 == '\0') {
    *(undefined1 *)(iVar4 + 0x6e) = 0;
  }
  else {
    uVar11 = *(ushort *)(param_3 + 6);
    sVar13 = 0;
    if ((uVar11 & 0x100) != 0) {
      if (((uVar2 & 3) == 0) &&
         ((*(char *)(iVar4 + 0x3b) == '\0' || (-1 < (int)((uint)uVar11 << 0x13))))) {
        iVar5 = r_emi_get_mem_addr_by_offset(0x1000);
        param_3[8] = (byte)(*(ushort *)(iVar5 + iVar14 + 4) >> 6) & 1;
        pvVar6 = (void *)r_emi_get_mem_addr_by_offset((ushort)(byte)param_3[3] + sVar1);
        memcpy((void *)(iVar4 + 0x5c),pvVar6,6);
      }
      else {
        *(ushort *)(param_3 + 6) = uVar11 & 0xfeff;
      }
      sVar13 = 6;
    }
    uVar2 = *(ushort *)(param_3 + 6);
    if ((uVar2 & 0x200) != 0) {
      if ((param_3[1] == '\0') &&
         ((*(char *)(iVar4 + 0x3b) == '\0' || (-1 < (int)((uint)uVar2 << 0x13))))) {
        *(byte *)(iVar4 + 0x6d) = *(byte *)(iVar4 + 0x6d) | 4;
        iVar5 = r_emi_get_mem_addr_by_offset(0x1000);
        *(byte *)(iVar4 + 0x70) = (byte)(*(ushort *)(iVar5 + iVar14 + 4) >> 7) & 1;
        param_3[2] = (char)sVar13;
      }
      else {
        *(ushort *)(param_3 + 6) = uVar2 & 0xfdff;
      }
      sVar13 = sVar13 + 6;
    }
    if ((*(ushort *)(param_3 + 6) & 0x400) != 0) {
      sVar13 = sVar13 + 1;
    }
    if ((int)((uint)*(ushort *)(param_3 + 6) << 0x14) < 0) {
      puVar7 = (undefined2 *)r_emi_get_mem_addr_by_offset(sVar1 + sVar13);
      uVar3 = *puVar7;
      sVar13 = sVar13 + 2;
      *(undefined2 *)(iVar4 + 0x34) = uVar3;
      *(undefined2 *)(iVar4 + 0x68) = uVar3;
      *(undefined1 *)(iVar4 + 0x6a) = 1;
    }
    if ((int)((uint)*(ushort *)(param_3 + 6) << 0x13) < 0) {
      pvVar6 = (void *)r_emi_get_mem_addr_by_offset(sVar1 + sVar13);
      memcpy(auStack_24,pvVar6,3);
      iVar5 = r_emi_get_mem_addr_by_offset(0x1000);
      if ((*(ushort *)(iVar14 + 2 + iVar5) >> 9 & 1) == 0) {
        if (2 < (auStack_24[0] >> 0x15 & 7)) {
_L218:
          *(undefined1 *)(iVar4 + 0x6e) = 0xff;
          return;
        }
        iVar5 = r_lld_calc_aux_rx(iVar4 + 0x48,param_2);
        uVar10 = 1;
        if (iVar5 == 0) goto _L218;
      }
      else {
        *(uint *)(iVar4 + 0x2c) = auStack_24[0];
        uVar10 = 2;
      }
      *(undefined1 *)(iVar4 + 0x3e) = uVar10;
      *(undefined1 *)(iVar4 + 0x3d) = 1;
      sVar13 = sVar13 + 3;
    }
    else {
      *(char *)(iVar4 + 0x6e) = -(*(char *)(iVar4 + 0x6f) == -1);
      *(undefined1 *)(iVar4 + 0x72) = 4;
    }
    uVar12 = (uint)*(ushort *)(param_3 + 6);
    if ((int)(uVar12 << 0x12) < 0) {
      sVar13 = sVar13 + 0x12;
    }
    if ((int)(uVar12 << 0x11) < 0) {
      if ((*(char *)(iVar4 + 0x3b) != '\0') && ((param_3[1] != '\0' || ((int)(uVar12 << 0x13) < 0)))
         ) goto _L224;
      puVar8 = (undefined1 *)r_emi_get_mem_addr_by_offset(sVar1 + sVar13);
      uVar10 = *puVar8;
    }
    else {
      uVar10 = 0x7f;
    }
    *(undefined1 *)(iVar4 + 0x73) = uVar10;
  }
_L224:
  *(char *)(iVar4 + 0x6f) = param_3[8];
  param_3[5] = '\0';
  return;
}

