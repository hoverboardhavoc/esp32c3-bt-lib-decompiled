/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_scan.o -> r_lld_scan_process_pkt_rx_aux_chain_ind
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_scan_process_pkt_rx_aux_chain_ind(int param_1,int param_2,char *param_3)

{
  byte bVar1;
  short sVar2;
  ushort uVar3;
  int iVar4;
  short sVar5;
  int iVar6;
  short *psVar7;
  void *__src;
  undefined1 *puVar8;
  undefined1 uVar9;
  uint uVar10;
  undefined4 auStack_24 [2];
  
  iVar4 = *(int *)(_lld_scan_env + param_1 * 4);
  iVar6 = r_emi_get_mem_addr_by_offset(0x1000);
  sVar2 = *(short *)(param_2 * 0x14 + 0x12 + iVar6);
  bVar1 = param_3[5];
  uVar10 = (uint)*(ushort *)(iVar4 + 0x36) + (uint)bVar1;
  iVar6 = uVar10 * 0x10000;
  *(char *)(iVar4 + 0x41) = *(char *)(iVar4 + 0x41) + '\x01';
  *(short *)(iVar4 + 0x36) = (short)((uint)iVar6 >> 0x10);
  if (0x672 < (uVar10 & 0xffff)) {
    *(undefined1 *)(iVar4 + 0x6e) = 2;
    param_3[5] = (bVar1 + 0x72) - (char)((uint)iVar6 >> 0x10);
    goto _L325;
  }
  if (*param_3 == '\0') {
    *(char *)(iVar4 + 0x6e) = (char)(((*(byte *)(iVar4 + 0x6d) >> 3 ^ 1) & 1) << 1);
    goto _L325;
  }
  uVar3 = *(ushort *)(param_3 + 6);
  sVar5 = 0;
  if ((uVar3 & 0x100) != 0) {
    sVar5 = 6;
  }
  if ((uVar3 & 0x200) != 0) {
    sVar5 = sVar5 + 6;
  }
  if ((uVar3 & 0x400) != 0) {
    sVar5 = sVar5 + 1;
  }
  if ((uVar3 >> 0xb & 1) == 0) {
    if ((*(byte *)(iVar4 + 0x6d) & 8) != 0) goto _L299;
  }
  else {
    psVar7 = (short *)r_emi_get_mem_addr_by_offset(sVar2 + sVar5);
    if (*(short *)(iVar4 + 0x34) == *psVar7) {
      sVar5 = sVar5 + 2;
_L299:
      if ((*(ushort *)(param_3 + 6) & 0x1000) == 0) {
        *(undefined1 *)(iVar4 + 0x6e) = 0;
        *(undefined1 *)(iVar4 + 0x3d) = 0;
        goto _L304;
      }
      __src = (void *)r_emi_get_mem_addr_by_offset(sVar2 + sVar5);
      memcpy(auStack_24,__src,3);
      iVar6 = r_emi_get_mem_addr_by_offset(0x1000);
      if ((*(ushort *)(param_2 * 0x14 + 2 + iVar6) >> 9 & 1) == 0) {
        if (*(byte *)(iVar4 + 0x41) < 7) {
          iVar6 = r_lld_calc_aux_rx(iVar4 + 0x48,param_2,auStack_24[0]);
          uVar9 = 1;
          if (iVar6 != 0) goto _L324;
        }
        *(undefined1 *)(iVar4 + 0x6e) = 2;
      }
      else {
        *(undefined4 *)(iVar4 + 0x2c) = auStack_24[0];
        uVar9 = 2;
_L324:
        *(undefined1 *)(iVar4 + 0x3e) = uVar9;
      }
      *(undefined1 *)(iVar4 + 0x3d) = 3;
      sVar5 = sVar5 + 3;
_L304:
      if ((*(ushort *)(param_3 + 6) & 0x2000) != 0) {
        sVar5 = sVar5 + 0x12;
      }
      if ((*(ushort *)(param_3 + 6) & 0x4000) == 0) {
        return;
      }
      puVar8 = (undefined1 *)r_emi_get_mem_addr_by_offset(sVar2 + sVar5);
      *(undefined1 *)(iVar4 + 0x73) = *puVar8;
      return;
    }
  }
  *(undefined1 *)(iVar4 + 0x6e) = 2;
  param_3[5] = '\0';
_L325:
  *(undefined1 *)(iVar4 + 0x3d) = 0;
  return;
}

