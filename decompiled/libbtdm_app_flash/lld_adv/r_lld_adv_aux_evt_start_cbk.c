/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_adv_aux_evt_start_cbk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_adv_aux_evt_start_cbk(int param_1)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  ushort uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  ushort uVar10;
  undefined4 uVar11;
  uint uVar12;
  byte bStack_51;
  code *pcStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  uint uStack_40;
  undefined1 uStack_3c;
  undefined1 uStack_3b;
  undefined1 uStack_3a;
  undefined1 uStack_39;
  byte bStack_38;
  undefined1 uStack_37;
  undefined1 uStack_36;
  undefined1 uStack_34;
  
  if (param_1 != 0) {
    bVar1 = *(byte *)(param_1 + 0x53);
    uVar9 = (uint)bVar1;
    iVar8 = uVar9 * 0x5a;
    iVar5 = r_emi_get_mem_addr_by_offset(0x400);
    uVar11 = 0;
    uVar10 = *(ushort *)(iVar5 + iVar8) & 0x1f;
    if ((((*(ushort *)(param_1 + 0x40) & 0x13) == 0) && (*(int *)(param_1 + 0x34) != 0)) &&
       (*(char *)(param_1 + 0x60) == '\0')) {
      uVar11 = 1;
      r_lld_adv_sync_info_set(*(undefined1 *)(param_1 + 0x53));
    }
    iVar5 = *(int *)(param_1 + 0x24);
    if (iVar5 != -1) {
      iVar7 = *(int *)(param_1 + 4);
      iVar6 = r_emi_get_mem_addr_by_offset(0x400);
      *(short *)(iVar8 + 0x20 + iVar6) = (short)((uint)((iVar5 - iVar7) * 0x8000) >> 0x10);
    }
    bVar2 = *(byte *)(param_1 + 0x5d);
    bVar3 = *(byte *)(param_1 + 0x46);
    uVar4 = *(ushort *)(_p_lld_env + 0xd4);
    if ((bVar2 & 0xc0) != 0) {
      r_assert_err(0,0x10000,0x2b0);
    }
    iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
    iVar6 = (uVar9 * 9 & 0xff) * 0xe;
    *(ushort *)(iVar6 + 8 + iVar5) =
         (ushort)(uVar4 < 0x33) << 6 | (ushort)bVar2 | (ushort)bVar3 << 8;
    uVar12 = (uint)*(byte *)(param_1 + 0x5c) << 5;
    uVar4 = *(ushort *)(param_1 + 0x46) >> 8;
    if ((uVar12 & 0xffffff1f) != 0) {
      r_assert_err(0,0x10000,0x31c);
    }
    if ((uVar4 & 0xffe0) != 0) {
      r_assert_err(0,0x10000,0x31d);
    }
    iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
    *(ushort *)(iVar6 + 10 + iVar5) = uVar4 | (ushort)uVar12;
    r_lld_adv_set_tx_power(uVar9,uVar10);
    r_lld_adv_dynamic_pti_process(param_1 + -0x34,1,uVar11);
    r_bt_rma_get_ant_by_act(uVar10,uVar9,&bStack_51,&pcStack_50);
    if (((uint)bStack_51 << 7 & 0xffffff7f) != 0) {
      r_assert_err(0,0x10000,0x82);
    }
    iVar5 = r_emi_get_mem_addr_by_offset(0x400);
    uVar10 = *(ushort *)(iVar5 + iVar8);
    iVar5 = r_emi_get_mem_addr_by_offset(0x400);
    *(ushort *)(iVar5 + iVar8) = uVar10 & 0xff7f | (ushort)((uint)bStack_51 << 7);
    uVar12 = ((uint)pcStack_50 & 0xff) << 6;
    if ((uVar12 & 0xffffffbf) != 0) {
      r_assert_err(0,0x10000,0x8e);
    }
    iVar5 = r_emi_get_mem_addr_by_offset(0x400);
    uVar10 = *(ushort *)(iVar5 + iVar8);
    iVar5 = r_emi_get_mem_addr_by_offset(0x400);
    *(ushort *)(iVar8 + iVar5) = uVar10 & 0xffbf | (ushort)uVar12;
    pcStack_50 = r_lld_adv_frm_cbk;
    uStack_4c = *(undefined4 *)(param_1 + 4);
    uStack_44 = *(undefined4 *)(param_1 + 0x10);
    uStack_48 = 0;
    uStack_3c = *(undefined1 *)(param_1 + 0x16);
    uStack_3b = 0;
    uStack_36 = 0;
    uStack_39 = 0xf;
    uStack_34 = 0;
    uStack_37 = 0;
    uStack_40 = uVar9;
    uStack_3a = uStack_3c;
    bStack_38 = bVar1;
    r_sch_prog_push(&pcStack_50);
    *(undefined1 *)(param_1 + 0x55) = 1;
    return;
  }
  r_assert_err(0x10000,0x99c);
  return;
}

