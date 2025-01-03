/*
 * Last changed at upstream commit ed99228396aaa18935b575d600bc19da38dc4746
 * https://github.com/espressif/esp32c3-bt-lib/commit/ed99228396aaa18935b575d600bc19da38dc4746
 * Upstream date: 2025-01-03 16:50:09 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(fd62b31)
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
  uint uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  
  uVar6 = (param_3 << 0xb) >> 0x13;
  if (uVar6 != 0) {
    uVar10 = param_3 >> 7 & 1;
    uVar8 = param_3 >> 0x15 & 7;
    iVar7 = 300;
    if (uVar10 == 0) {
      iVar7 = 0x1e;
    }
    iVar9 = uVar6 * iVar7;
    iVar4 = r_rwip_active_check();
    uVar6 = 0x14;
    if (iVar4 == 0) {
      uVar6 = (uint)*(ushort *)(_p_lld_env + 0xd4);
    }
    iVar4 = 0x32;
    if ((param_3 >> 6 & 1) == 0) {
      iVar4 = 500;
    }
    iVar5 = r_emi_get_mem_addr_by_offset(0x1000);
    param_2 = param_2 * 0x14;
    uVar1 = *(ushort *)(iVar5 + param_2 + 10);
    if ((uVar1 & 0xf000) != 0) {
      r_assert_err(0,"lld.c",1000);
    }
    iVar5 = r_emi_get_mem_addr_by_offset(0x1000);
    uVar2 = *(undefined2 *)(iVar5 + param_2 + 8);
    iVar5 = r_emi_get_mem_addr_by_offset(0x1000);
    uVar3 = *(ushort *)(iVar5 + param_2 + 0xc);
    iVar5 = 0x96;
    if (uVar10 == 0) {
      iVar5 = 0xf;
    }
    iVar4 = iVar7 + (uint)DAT_00014056 + (iVar9 * (uVar6 + iVar4)) / 1000000;
    uVar10 = iVar4 * 2;
    iVar7 = r_emi_get_mem_addr_by_offset(0x1000);
    uVar6 = (0x270 - (uVar3 & 0x3ff) & 0xffff) + iVar4 * -2 + (iVar5 + iVar9) * 2 +
            (uint)*(ushort *)
                   (&lld_exp_sync_pos_tab + (uint)(*(ushort *)(param_2 + 6 + iVar7) >> 0xe) * 2) *
            -2;
    *(undefined *)((int)param_1 + 0xd) = (&lld_aux_phy_to_rate)[uVar8];
    *(byte *)(param_1 + 3) = (byte)param_3 & 0x3f;
    param_1[2] = uVar10;
    *param_1 = CONCAT22(uVar1,uVar2) + (int)uVar6 / 0x271 & 0xfffffff;
    param_1[1] = uVar6 % 0x271;
    if (uVar8 == 2) {
      param_1[2] = uVar10 + (uint)DAT_00014056 * 0xe;
    }
    return 1;
  }
  return 0;
}

