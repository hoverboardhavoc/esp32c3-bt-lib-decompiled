/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
 * Source: libbtdm_app_flash -> lld_init.o -> r_lld_init_process_pkt_rx_aux_connect_rsp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_init_process_pkt_rx_aux_connect_rsp(int param_1,undefined4 param_2)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  undefined2 uVar4;
  short sVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  void *__src;
  int iVar10;
  undefined4 uVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  
  iVar10 = _lld_init_env;
  bVar1 = *(byte *)(_p_lld_env + 0xd8);
  iVar7 = (uint)bVar1 * 0x14;
  iVar14 = *(int *)(param_1 * 4 + _lld_init_env);
  iVar8 = r_emi_get_mem_addr_by_offset(0x1000);
  uVar3 = *(ushort *)(iVar7 + 0x10 + iVar8);
  iVar8 = r_emi_get_mem_addr_by_offset(0x1000);
  if ((*(ushort *)(iVar8 + iVar7 + 4) & 0xf) != 8) {
    r_assert_err(0,0x10000,0x32a);
    return;
  }
  if ((*(short *)(iVar14 + 0x38) == *(short *)(iVar14 + 0x3a)) && ((uVar3 & 0x300) == 0x300)) {
    iVar8 = r_emi_get_mem_addr_by_offset(0x1000);
    if ((*(ushort *)(iVar8 + iVar7 + 2) >> 0xc & 1) != 0) {
      iVar8 = r_emi_get_mem_addr_by_offset(0x1000);
      iVar15 = iVar7 + 6;
      uVar4 = *(undefined2 *)(iVar8 + iVar15);
      iVar8 = r_emi_get_mem_addr_by_offset(0x1000);
      uVar3 = *(ushort *)(iVar7 + 10 + iVar8);
      if ((uVar3 & 0xf000) != 0) {
        r_assert_err(0,0x10000,1000);
      }
      iVar8 = r_emi_get_mem_addr_by_offset(0x1000);
      uVar13 = CONCAT22(uVar3,*(undefined2 *)(iVar7 + 8 + iVar8));
      bVar2 = *(byte *)(_p_lld_env + 0xd8);
      iVar8 = r_emi_get_mem_addr_by_offset(0x1000);
      uVar3 = *(ushort *)((uint)bVar2 * 0x14 + 0xc + iVar8);
      iVar8 = r_emi_get_mem_addr_by_offset(0x1000);
      iVar8 = (*(ushort *)(&lld_exp_sync_pos_tab + (uint)(*(ushort *)(iVar8 + iVar15) >> 0xe) * 2) +
              0x96) * -2 + (0x4e1 - (uVar3 & 0x3ff));
      *(uint *)(iVar10 + 0x54) = (iVar8 + 0x270U) / 0x271 + (uVar13 - 1) & 0xfffffff;
      iVar9 = r_emi_get_mem_addr_by_offset(0x1000);
      sVar5 = *(short *)(iVar7 + 0xe + iVar9);
      *(short *)(iVar10 + 0x4c) = sVar5;
      if (sVar5 != 0) {
        __src = (void *)r_emi_get_mem_addr_by_offset(param_2);
        memcpy((void *)(iVar14 + 0x32),__src,6);
      }
      *(undefined1 *)(iVar10 + 0x58) = 1;
      *(byte *)(iVar10 + 0x4e) = (byte)((ushort)uVar4 >> 0xe);
      iVar9 = r_emi_get_mem_addr_by_offset(0x1000);
      uVar3 = *(ushort *)(iVar9 + iVar7 + 4);
      *(undefined1 *)(iVar10 + 0x50) = 1;
      *(undefined1 *)(iVar10 + 0x59) = 1;
      *(byte *)(iVar10 + 0x33) = (byte)(uVar3 >> 6) & 1;
      iVar10 = r_emi_get_mem_addr_by_offset(0x1000);
      uVar11 = 0x408200fc;
      uVar12 = (uint)*(byte *)(iVar14 + 0x52) << 0x10 | (uint)bVar1 << 0x18 |
               (uint)*(ushort *)(iVar10 + iVar15);
      uVar6 = iVar8 + uVar13 * 0x271;
      uVar13 = ((uint)(uVar6 < uVar13 * 0x271) + (int)((ulonglong)uVar13 * 0x271 >> 0x20)) *
               -0x80000000 | uVar6 >> 1;
      goto _L154;
    }
  }
  iVar10 = r_emi_get_mem_addr_by_offset(0x1000);
  uVar12 = (uint)*(ushort *)(iVar14 + 0x3a) << 0x18 |
           CONCAT22(*(undefined2 *)(iVar14 + 0x38),CONCAT11(bVar1,*(undefined1 *)(iVar14 + 0x52)));
  uVar13 = CONCAT22(*(undefined2 *)(iVar7 + 2 + iVar10),uVar3);
  uVar11 = 0x808200fd;
_L154:
  r_ble_log_internal_x2(uVar11,uVar13,uVar12);
  *(undefined1 *)(iVar14 + 0x3d) = 0;
  return;
}

