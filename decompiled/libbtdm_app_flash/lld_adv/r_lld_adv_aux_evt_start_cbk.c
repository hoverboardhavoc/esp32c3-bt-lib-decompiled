/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  short sVar3;
  ushort uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  ushort uVar10;
  undefined4 uVar11;
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
    sVar3 = *(short *)(param_1 + 0x46);
    uVar4 = *(ushort *)(_p_lld_env + 0xd4);
    if (0x3f < bVar2) {
      r_assert_err(0,0x10000,0x2b0);
    }
    iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
    iVar6 = (uVar9 * 9 & 0xff) * 0xe;
    *(ushort *)(iVar6 + 8 + iVar5) = (ushort)(uVar4 < 0x33) << 6 | (ushort)bVar2 | sVar3 << 8;
    bVar2 = *(byte *)(param_1 + 0x5c);
    uVar4 = *(ushort *)(param_1 + 0x46) >> 8;
    if ((bVar2 & 0xf8) != 0) {
      r_assert_err(0,0x10000,0x31c);
    }
    if (0x1f < uVar4) {
      r_assert_err(0,0x10000,0x31d);
    }
    iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
    *(ushort *)(iVar6 + 10 + iVar5) = uVar4 | (ushort)bVar2 << 5;
    r_lld_adv_set_tx_power(uVar9,uVar10);
    r_lld_adv_dynamic_pti_process(param_1 + -0x34,1,uVar11);
    r_bt_rma_get_ant_by_act(uVar10,uVar9,&bStack_51,&pcStack_50);
    if ((bStack_51 & 0xfe) != 0) {
      r_assert_err(0,0x10000,0x82);
    }
    iVar5 = r_emi_get_mem_addr_by_offset(0x400);
    uVar10 = *(ushort *)(iVar5 + iVar8);
    iVar5 = r_emi_get_mem_addr_by_offset(0x400);
    *(ushort *)(iVar5 + iVar8) = uVar10 & 0xff7f | (ushort)bStack_51 << 7;
    if (((uint)pcStack_50 & 0xfe) != 0) {
      r_assert_err(0,0x10000,0x8e);
    }
    iVar5 = r_emi_get_mem_addr_by_offset(0x400);
    uVar10 = *(ushort *)(iVar5 + iVar8);
    iVar5 = r_emi_get_mem_addr_by_offset(0x400);
    *(ushort *)(iVar8 + iVar5) = uVar10 & 0xffbf | (ushort)(byte)pcStack_50 << 6;
    pcStack_50 = r_lld_adv_frm_cbk;
    uStack_4c = *(undefined4 *)(param_1 + 4);
    uStack_3c = *(undefined1 *)(param_1 + 0x16);
    uStack_44 = *(undefined4 *)(param_1 + 0x10);
    uStack_39 = 0xf;
    uStack_48 = 0;
    uStack_3b = 0;
    uStack_36 = 0;
    uStack_34 = 0;
    uStack_37 = 0;
    uStack_40 = uVar9;
    uStack_3a = uStack_3c;
    bStack_38 = bVar1;
    r_sch_prog_push(&pcStack_50);
    *(undefined1 *)(param_1 + 0x55) = 1;
    return;
  }
  r_assert_err(0x10000,0x95e);
  return;
}

