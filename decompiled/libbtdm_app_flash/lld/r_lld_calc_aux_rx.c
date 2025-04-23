/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  uint uVar9;
  uint uVar10;
  
  uVar4 = (param_3 << 0xb) >> 0x13;
  if (uVar4 == 0) {
    uVar8 = 0;
  }
  else {
    uVar10 = param_3 >> 7 & 1;
    iVar5 = uVar4 * ((uVar10 - 1 & 0xfffffef2) + 300);
    uVar9 = param_3 >> 0x15 & 7;
    iVar6 = r_rwip_active_check();
    uVar4 = 0x14;
    if (iVar6 == 0) {
      uVar4 = (uint)*(ushort *)(_p_lld_env + 0xd4);
    }
    iVar6 = r_emi_get_mem_addr_by_offset(0x1000);
    param_2 = param_2 * 0x14;
    uVar1 = *(ushort *)(param_2 + 10 + iVar6);
    if (0xfff < uVar1) {
      r_assert_err(0,"lld.c",1000);
    }
    iVar6 = r_emi_get_mem_addr_by_offset(0x1000);
    uVar2 = *(undefined2 *)(param_2 + 8 + iVar6);
    iVar6 = r_emi_get_mem_addr_by_offset(0x1000);
    uVar3 = *(ushort *)(param_2 + 0xc + iVar6);
    iVar6 = DAT_00014062 + 0x1e;
    if (uVar10 != 0) {
      iVar6 = DAT_00014062 + 300;
    }
    iVar6 = (iVar5 * (uVar4 + ((param_3 >> 6 & 1) - 1 & 0x1c2) + 0x32)) / 1000000 + iVar6;
    uVar4 = iVar6 * 2;
    iVar7 = r_emi_get_mem_addr_by_offset(0x1000);
    uVar10 = ((uVar10 - 1 & 0xffffff79) + 0x96 + iVar5) * 2 + (0x270 - (uVar3 & 0x3ff) & 0xffff) +
             iVar6 * -2 +
             (uint)*(ushort *)
                    (&lld_exp_sync_pos_tab + (uint)(*(ushort *)(param_2 + 6 + iVar7) >> 0xe) * 2) *
             -2;
    *(undefined *)((int)param_1 + 0xd) = (&lld_aux_phy_to_rate)[uVar9];
    *(byte *)(param_1 + 3) = (byte)param_3 & 0x3f;
    param_1[2] = uVar4;
    *param_1 = (int)uVar10 / 0x271 + CONCAT22(uVar1,uVar2) & 0xfffffff;
    param_1[1] = uVar10 % 0x271;
    if (uVar9 == 2) {
      param_1[2] = (uint)DAT_00014062 * 0xe + uVar4;
    }
    uVar8 = 1;
  }
  return uVar8;
}

