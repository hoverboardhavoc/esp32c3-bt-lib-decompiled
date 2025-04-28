/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_init.o -> r_lld_init_process_pkt_rx_adv_ind_or_direct_ind
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_init_process_pkt_rx_adv_ind_or_direct_ind(int param_1,undefined4 param_2)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  undefined2 uVar5;
  ushort uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  void *__src;
  int iVar11;
  int iVar12;
  uint uVar13;
  
  iVar7 = _lld_init_env;
  bVar1 = *(byte *)(_p_lld_env + 0xd8);
  iVar12 = *(int *)(param_1 * 4 + _lld_init_env);
  iVar9 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  iVar8 = (uint)bVar1 * 0x14;
  iVar11 = iVar8 + 4;
  if ((*(ushort *)(iVar9 + iVar11) & 0xe) != 0) {
                    /* WARNING: Could not recover jumptable at 0x000107aa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x28d,*(code **)(_r_plf_funcs_p + 8));
    return;
  }
  iVar9 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar2 = *(ushort *)(iVar9 + iVar11);
  iVar9 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar3 = *(ushort *)(iVar8 + 6 + iVar9);
  uVar13 = (uint)(uVar3 >> 0xe);
  iVar9 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar4 = *(ushort *)(iVar8 + 10 + iVar9);
  if ((uVar4 & 0xf000) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,1000,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar9 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar5 = *(undefined2 *)(iVar8 + 8 + iVar9);
  bVar1 = *(byte *)(_p_lld_env + 0xd8);
  iVar9 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar6 = *(ushort *)((uint)bVar1 * 0x14 + 0xc + iVar9);
  iVar9 = (**(code **)(_r_modules_funcs_p + 4))
                    (uVar2 >> 8,uVar13,*(code **)(_r_modules_funcs_p + 4));
  uVar2 = *(ushort *)(&lld_exp_sync_pos_tab + uVar13 * 2);
  iVar10 = (**(code **)(_r_modules_funcs_p + 4))(0x22,uVar13,*(code **)(_r_modules_funcs_p + 4));
  *(uint *)(iVar7 + 0x54) =
       (((iVar10 + (iVar9 - (uint)uVar2) + 0x96) * 2 - (uVar6 & 0x3ff)) + 0x4e0) / 0x271 +
       CONCAT22(uVar4,uVar5) & 0xfffffff;
  iVar9 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  *(undefined2 *)(iVar7 + 0x4c) = *(undefined2 *)(iVar8 + 0xe + iVar9);
  iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar2 = *(ushort *)(iVar8 + iVar11);
  *(byte *)(iVar7 + 0x4e) = (byte)(uVar3 >> 0xe);
  *(byte *)(iVar7 + 0x58) = (byte)(uVar2 >> 5) & 1;
  __src = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))(param_2,*(code **)(_r_plf_funcs_p + 0xbc));
  memcpy((void *)(iVar12 + 0x32),__src,6);
  iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar2 = *(ushort *)(iVar8 + iVar11);
  *(undefined1 *)(iVar7 + 0x59) = 0;
  *(byte *)(iVar7 + 0x33) = (byte)(uVar2 >> 6) & 1;
  *(undefined1 *)(iVar7 + 0x50) = 1;
  return;
}

