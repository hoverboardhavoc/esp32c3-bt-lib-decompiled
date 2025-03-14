/*
 * Last changed at upstream commit e668c2d101ee46ee1950819607694fb852aecae0
 * https://github.com/espressif/esp32c3-bt-lib/commit/e668c2d101ee46ee1950819607694fb852aecae0
 * Upstream date: 2025-03-14 11:07:43 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(6e312587)
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
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  ushort uVar11;
  undefined4 uVar12;
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
  
  if (param_1 == 0) {
    r_assert_err("lld_adv.c",0x94b);
  }
  else {
    bVar1 = *(byte *)(param_1 + 0x53);
    uVar10 = (uint)bVar1;
    iVar9 = uVar10 * 0x5a;
    iVar7 = r_emi_get_mem_addr_by_offset(0x400);
    uVar12 = 0;
    uVar11 = *(ushort *)(iVar7 + iVar9) & 0x1f;
    if ((((*(ushort *)(param_1 + 0x40) & 0x13) == 0) && (*(int *)(param_1 + 0x34) != 0)) &&
       (*(char *)(param_1 + 0x60) == '\0')) {
      uVar12 = 1;
      r_lld_adv_sync_info_set(*(undefined1 *)(param_1 + 0x53));
    }
    iVar7 = *(int *)(param_1 + 0x24);
    if (iVar7 != -1) {
      iVar5 = *(int *)(param_1 + 4);
      iVar8 = r_emi_get_mem_addr_by_offset(0x400);
      *(short *)(iVar8 + iVar9 + 0x20) = (short)((uint)((iVar7 - iVar5) * 0x8000) >> 0x10);
    }
    bVar2 = *(byte *)(param_1 + 0x5d);
    bVar3 = *(byte *)(param_1 + 0x46);
    uVar4 = *(ushort *)(_p_lld_env + 0xd4);
    if ((bVar2 & 0xc0) != 0) {
      r_assert_err(0,"lld_adv.c",0x2b0);
    }
    iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
    iVar5 = (uVar10 * 9 & 0xff) * 0xe;
    *(ushort *)(iVar7 + iVar5 + 8) =
         (ushort)(uVar4 < 0x33) << 6 | (ushort)bVar2 | (ushort)bVar3 << 8;
    uVar4 = *(ushort *)(param_1 + 0x46) >> 8;
    uVar6 = (uint)*(byte *)(param_1 + 0x5c) << 5;
    if ((uVar6 & 0xffffff1f) != 0) {
      r_assert_err(0,"lld_adv.c",0x31c);
    }
    if ((uVar4 & 0xffe0) != 0) {
      r_assert_err(0,"lld_adv.c",0x31d);
    }
    iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
    *(ushort *)(iVar5 + 10 + iVar7) = (ushort)uVar6 | uVar4;
    r_lld_adv_set_tx_power(uVar10,uVar11);
    r_lld_adv_dynamic_pti_process(param_1 + -0x34,1,uVar12);
    r_bt_rma_get_ant_by_act(uVar11,uVar10,&bStack_51,&pcStack_50);
    if (((uint)bStack_51 << 7 & 0xffffff7f) != 0) {
      r_assert_err(0,"lld_adv.c",0x82);
    }
    iVar7 = r_emi_get_mem_addr_by_offset(0x400);
    uVar11 = *(ushort *)(iVar7 + iVar9);
    iVar7 = r_emi_get_mem_addr_by_offset(0x400);
    *(ushort *)(iVar7 + iVar9) = uVar11 & 0xff7f | (ushort)((uint)bStack_51 << 7);
    uVar6 = ((uint)pcStack_50 & 0xff) << 6;
    if ((uVar6 & 0xffffffbf) != 0) {
      r_assert_err(0,"lld_adv.c",0x8e);
    }
    iVar7 = r_emi_get_mem_addr_by_offset(0x400);
    uVar11 = *(ushort *)(iVar7 + iVar9);
    iVar7 = r_emi_get_mem_addr_by_offset(0x400);
    *(ushort *)(iVar7 + iVar9) = uVar11 & 0xffbf | (ushort)uVar6;
    pcStack_50 = r_lld_adv_frm_cbk;
    uStack_4c = *(undefined4 *)(param_1 + 4);
    uStack_48 = 0;
    uStack_44 = *(undefined4 *)(param_1 + 0x10);
    uStack_3c = *(undefined1 *)(param_1 + 0x16);
    uStack_3b = 0;
    uStack_36 = 0;
    uStack_39 = 0xf;
    uStack_34 = 0;
    uStack_37 = 0;
    uStack_40 = uVar10;
    uStack_3a = uStack_3c;
    bStack_38 = bVar1;
    r_sch_prog_push(&pcStack_50);
    *(undefined1 *)(param_1 + 0x55) = 1;
  }
  return;
}

