/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
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
  ushort uVar2;
  int iVar3;
  int iVar4;
  short *psVar5;
  void *__src;
  int iVar6;
  undefined1 *puVar7;
  undefined1 uVar8;
  uint uVar9;
  uint uVar10;
  undefined4 auStack_24 [2];
  
  iVar3 = *(int *)(_lld_scan_env + param_1 * 4);
  iVar4 = r_emi_get_mem_addr_by_offset(0x1000);
  uVar10 = (uint)*(ushort *)(param_2 * 0x14 + 0x12 + iVar4);
  bVar1 = param_3[5];
  uVar9 = (uint)*(ushort *)(iVar3 + 0x36) + (uint)bVar1;
  iVar4 = uVar9 * 0x10000;
  *(char *)(iVar3 + 0x41) = *(char *)(iVar3 + 0x41) + '\x01';
  *(short *)(iVar3 + 0x36) = (short)((uint)iVar4 >> 0x10);
  if (0x672 < (uVar9 & 0xffff)) {
    *(undefined1 *)(iVar3 + 0x6e) = 2;
    param_3[5] = (bVar1 + 0x72) - (char)((uint)iVar4 >> 0x10);
    goto _L319;
  }
  if (*param_3 == '\0') {
    *(char *)(iVar3 + 0x6e) = (char)((*(byte *)(iVar3 + 0x6d) >> 3 & 1 ^ 1) << 1);
    goto _L319;
  }
  uVar2 = *(ushort *)(param_3 + 6);
  uVar9 = (int)((uint)uVar2 << 0x17) >> 0x1f & 6;
  if ((uVar2 & 0x200) != 0) {
    uVar9 = uVar9 + 6;
  }
  iVar4 = uVar9 + ((uVar2 & 0x400) != 0);
  if ((int)((uint)uVar2 << 0x14) < 0) {
    psVar5 = (short *)r_emi_get_mem_addr_by_offset(uVar10 + iVar4 & 0xffff);
    if (*(short *)(iVar3 + 0x34) == *psVar5) {
      iVar4 = iVar4 + 2;
_L293:
      if (-1 < (int)((uint)*(ushort *)(param_3 + 6) << 0x13)) {
        *(undefined1 *)(iVar3 + 0x6e) = 0;
        *(undefined1 *)(iVar3 + 0x3d) = 0;
        goto _L298;
      }
      __src = (void *)r_emi_get_mem_addr_by_offset(uVar10 + iVar4 & 0xffff);
      memcpy(auStack_24,__src,3);
      iVar6 = r_emi_get_mem_addr_by_offset(0x1000);
      if ((*(ushort *)(param_2 * 0x14 + 2 + iVar6) >> 9 & 1) == 0) {
        if (*(byte *)(iVar3 + 0x41) < 7) {
          iVar6 = r_lld_calc_aux_rx(iVar3 + 0x48,param_2,auStack_24[0]);
          uVar8 = 1;
          if (iVar6 != 0) goto _L318;
        }
        *(undefined1 *)(iVar3 + 0x6e) = 2;
      }
      else {
        *(undefined4 *)(iVar3 + 0x2c) = auStack_24[0];
        uVar8 = 2;
_L318:
        *(undefined1 *)(iVar3 + 0x3e) = uVar8;
      }
      *(undefined1 *)(iVar3 + 0x3d) = 3;
      iVar4 = iVar4 + 3;
_L298:
      if ((int)((uint)*(ushort *)(param_3 + 6) << 0x12) < 0) {
        iVar4 = iVar4 + 0x12;
      }
      if (-1 < (int)((uint)*(ushort *)(param_3 + 6) << 0x11)) {
        return;
      }
      puVar7 = (undefined1 *)r_emi_get_mem_addr_by_offset(uVar10 + iVar4 & 0xffff);
      *(undefined1 *)(iVar3 + 0x73) = *puVar7;
      return;
    }
  }
  else if ((*(byte *)(iVar3 + 0x6d) & 8) != 0) goto _L293;
  *(undefined1 *)(iVar3 + 0x6e) = 2;
  param_3[5] = '\0';
_L319:
  *(undefined1 *)(iVar3 + 0x3d) = 0;
  return;
}

