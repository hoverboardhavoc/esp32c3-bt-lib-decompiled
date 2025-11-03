/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app -> lld_sync.o -> r_lld_sync_process_pkt_rx_aux_sync_ind
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_sync_process_pkt_rx_aux_sync_ind(int param_1,int param_2)

{
  byte bVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  iVar4 = *(int *)(&lld_sync_env + param_1 * 4);
  bVar1 = *(byte *)(_p_lld_env + 0xd8);
  iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  if ((param_2 != 0) && ((*(ushort *)((uint)bVar1 * 0x14 + 2 + iVar5) & 1) == 0)) {
    bVar1 = *(byte *)(_p_lld_env + 0xd8);
    iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar2 = *(ushort *)((uint)bVar1 * 0x14 + 10 + iVar5);
    if ((uVar2 & 0xf000) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,1000,*(code **)(_r_plf_funcs_p + 8));
    }
    bVar1 = *(byte *)(_p_lld_env + 0xd8);
    iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar6 = CONCAT22(uVar2,*(undefined2 *)((uint)bVar1 * 0x14 + 8 + iVar5));
    bVar1 = *(byte *)(_p_lld_env + 0xd8);
    iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar3 = ((uint)*(ushort *)(&lld_exp_sync_pos_tab + (uint)*(byte *)(iVar4 + 0x58) * 2) * -2 +
            0x270) - (*(ushort *)((uint)bVar1 * 0x14 + 0xc + iVar5) & 0x3ff);
    iVar5 = (int)(uVar3 * 0x10000) >> 0x10;
    if (((DAT_00013058 & 4) != 0) && ((*(byte *)(iVar4 + 0x58) - 2 & 0xff) < 2)) {
      iVar5 = (int)(((uVar3 & 0xffff) + (uint)_DAT_0001305a * -2) * 0x10000) >> 0x10;
    }
    uVar3 = uVar6;
    if (0x751 < (iVar5 + 0x4e1U & 0xffff)) {
      (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x1a2,*(code **)(_r_plf_funcs_p + 8));
    }
    for (; iVar5 < 0; iVar5 = (iVar5 + 0x271) * 0x10000 >> 0x10) {
      uVar3 = uVar3 - 1 & 0xfffffff;
    }
    *(uint *)(iVar4 + 0x44) = uVar3;
    *(short *)(iVar4 + 0x48) = (short)iVar5;
    *(uint *)(iVar4 + 0x38) = uVar6;
    *(undefined2 *)(iVar4 + 0x52) = 0;
    *(undefined1 *)(iVar4 + 0x54) = 0;
  }
  return;
}

