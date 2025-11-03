/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> lld.o -> r_lld_calc_aux_rx
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_lld_calc_aux_rx(uint *param_1,int param_2,uint param_3)

{
  ushort uVar1;
  undefined2 uVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  
  uVar9 = (param_3 << 0xb) >> 0x13;
  if (uVar9 == 0) {
    uVar6 = 0;
  }
  else {
    uVar7 = param_3 >> 7 & 1;
    uVar8 = param_3 >> 0x15 & 7;
    iVar11 = 300;
    if (uVar7 == 0) {
      iVar11 = 0x1e;
    }
    iVar4 = r_rwip_active_check();
    iVar10 = uVar9 * iVar11;
    uVar9 = 0x14;
    if (iVar4 == 0) {
      uVar9 = (uint)*(ushort *)(_p_lld_env + 0xd4);
    }
    iVar4 = 0x32;
    if ((param_3 >> 6 & 1) == 0) {
      iVar4 = 500;
    }
    iVar5 = r_emi_get_mem_addr_by_offset(0x1000);
    param_2 = param_2 * 0x14;
    uVar1 = *(ushort *)(param_2 + 10 + iVar5);
    if ((uVar1 & 0xf000) != 0) {
      r_assert_err(0,"lld.c",1000);
    }
    iVar5 = r_emi_get_mem_addr_by_offset(0x1000);
    uVar2 = *(undefined2 *)(param_2 + 8 + iVar5);
    iVar5 = r_emi_get_mem_addr_by_offset(0x1000);
    uVar3 = *(ushort *)(param_2 + 0xc + iVar5);
    iVar5 = 0x96;
    if (uVar7 == 0) {
      iVar5 = 0xf;
    }
    iVar4 = (uint)DAT_0001405a + iVar11 + (iVar10 * (uVar9 + iVar4)) / 1000000;
    uVar7 = iVar4 * 2;
    iVar11 = r_emi_get_mem_addr_by_offset(0x1000);
    uVar9 = (iVar5 + iVar10) * 2 + (0x270 - (uVar3 & 0x3ff) & 0xffff) + iVar4 * -2 +
            (uint)*(ushort *)
                   (&lld_exp_sync_pos_tab + (uint)(*(ushort *)(param_2 + 6 + iVar11) >> 0xe) * 2) *
            -2;
    *(undefined *)((int)param_1 + 0xd) = (&lld_aux_phy_to_rate)[uVar8];
    *(byte *)(param_1 + 3) = (byte)param_3 & 0x3f;
    param_1[2] = uVar7;
    uVar6 = 1;
    *param_1 = (int)uVar9 / 0x271 + CONCAT22(uVar1,uVar2) & 0xfffffff;
    param_1[1] = uVar9 % 0x271;
    if (uVar8 == 2) {
      param_1[2] = (uint)DAT_0001405a * 0xe + uVar7;
    }
  }
  return uVar6;
}

