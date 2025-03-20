/*
 * Last changed at upstream commit aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * https://github.com/espressif/esp32c3-bt-lib/commit/aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * Upstream date: 2025-03-20 20:31:24 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(d74042a8)
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
  ushort uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  ushort uVar5;
  short sVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  void *__src;
  int iVar10;
  
  iVar7 = _lld_init_env;
  bVar1 = *(byte *)(_p_lld_env + 0xd8);
  iVar10 = *(int *)(param_1 * 4 + _lld_init_env);
  iVar9 = r_emi_get_mem_addr_by_offset(0x1000);
  iVar8 = (uint)bVar1 * 0x14;
  uVar2 = *(ushort *)(iVar9 + iVar8 + 0x10);
  iVar9 = r_emi_get_mem_addr_by_offset(0x1000);
  if ((*(ushort *)(iVar9 + iVar8 + 4) & 0xf) != 8) {
    r_assert_err(0,"lld_init.c",799);
    return;
  }
  if ((*(short *)(iVar10 + 0x38) == *(short *)(iVar10 + 0x3a)) && ((uVar2 & 0x300) == 0x300)) {
    iVar9 = r_emi_get_mem_addr_by_offset(0x1000);
    if ((int)((uint)*(ushort *)(iVar9 + iVar8 + 2) << 0x13) < 0) {
      iVar9 = r_emi_get_mem_addr_by_offset(0x1000);
      uVar3 = *(undefined2 *)(iVar9 + iVar8 + 6);
      iVar9 = r_emi_get_mem_addr_by_offset(0x1000);
      uVar2 = *(ushort *)(iVar9 + iVar8 + 10);
      if ((uVar2 & 0xf000) != 0) {
        r_assert_err(0,"lld_init.c",1000);
      }
      iVar9 = r_emi_get_mem_addr_by_offset(0x1000);
      uVar4 = *(undefined2 *)(iVar9 + iVar8 + 8);
      bVar1 = *(byte *)(_p_lld_env + 0xd8);
      iVar9 = r_emi_get_mem_addr_by_offset(0x1000);
      uVar5 = *(ushort *)((uint)bVar1 * 0x14 + 0xc + iVar9);
      iVar9 = r_emi_get_mem_addr_by_offset(0x1000);
      *(uint *)(iVar7 + 0x54) =
           (((*(ushort *)(&lld_exp_sync_pos_tab + (uint)(*(ushort *)(iVar9 + iVar8 + 6) >> 0xe) * 2)
             + 0x96) * -2 - (uVar5 & 0x3ff)) + 0x751) / 0x271 + CONCAT22(uVar2,uVar4) + -1 &
           0xfffffff;
      iVar9 = r_emi_get_mem_addr_by_offset(0x1000);
      sVar6 = *(short *)(iVar8 + 0xe + iVar9);
      *(short *)(iVar7 + 0x4c) = sVar6;
      if (sVar6 != 0) {
        __src = (void *)r_emi_get_mem_addr_by_offset(param_2);
        memcpy((void *)(iVar10 + 0x32),__src,6);
      }
      *(undefined1 *)(iVar7 + 0x58) = 1;
      *(byte *)(iVar7 + 0x4e) = (byte)((ushort)uVar3 >> 0xe);
      iVar9 = r_emi_get_mem_addr_by_offset(0x1000);
      uVar2 = *(ushort *)(iVar9 + iVar8 + 4);
      *(undefined1 *)(iVar7 + 0x50) = 1;
      *(undefined1 *)(iVar7 + 0x59) = 1;
      *(byte *)(iVar7 + 0x33) = (byte)(uVar2 >> 6) & 1;
    }
  }
  *(undefined1 *)(iVar10 + 0x3d) = 0;
  return;
}

