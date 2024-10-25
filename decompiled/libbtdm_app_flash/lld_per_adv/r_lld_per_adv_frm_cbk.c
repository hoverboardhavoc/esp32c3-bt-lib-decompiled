/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld_per_adv.o -> r_lld_per_adv_frm_cbk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_per_adv_frm_cbk(uint param_1,int param_2)

{
  undefined1 uVar1;
  byte bVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined1 *puVar7;
  uint uVar8;
  char cVar9;
  
  if (param_2 != 1) {
    if (param_2 != 0) {
      if (param_2 == 2) {
        return;
      }
      if (param_2 != 4) {
        r_assert_param(param_2,"lld_per_adv.c",0x486);
        return;
      }
      iVar4 = *(int *)(&lld_per_adv_env + (param_1 & 0xff) * 4);
      if (iVar4 == 0) {
        r_assert_err(0,"lld_per_adv.c",0x465);
        return;
      }
      if (1 < (byte)(*(char *)(iVar4 + 0x53) - 1U)) {
        r_assert_err(0,"lld_per_adv.c",0x449);
      }
      r_sch_arb_remove(iVar4,1);
      if (*(char *)(iVar4 + 0x53) != '\x02') {
        bVar2 = *(byte *)(iVar4 + 0x52);
        *(char *)(iVar4 + 0x16) = *(char *)(iVar4 + 0x16) + rwip_priority;
        goto r_lld_per_adv_sched;
      }
      puVar7 = (undefined1 *)r_ke_msg_alloc(0x208,0,0xff,2);
      uVar1 = *(undefined1 *)(iVar4 + 0x52);
      puVar7[1] = 0;
      *puVar7 = uVar1;
      r_ke_msg_send();
      goto r_lld_per_adv_cleanup;
    }
    param_2 = 0;
  }
  uVar8 = param_1 & 0xff;
  if (periodic_adv_data_need_to_set[uVar8] != '\0') {
    *(undefined4 *)(*(int *)(&lld_per_adv_env + uVar8 * 4) + 0x24) = 0;
    r_lld_per_adv_data_set(0,0,1,1);
    periodic_adv_data_need_to_set[uVar8] = '\0';
  }
  iVar4 = *(int *)(&lld_per_adv_env + uVar8 * 4);
  if (iVar4 == 0) {
    r_assert_err(0,"lld_per_adv.c",0x432);
    return;
  }
  r_sch_arb_remove(iVar4,1);
  if (*(char *)(iVar4 + 0x53) != '\x02') {
    bVar2 = *(byte *)(iVar4 + 0x52);
    if (*(short *)(iVar4 + 0x24) != 0) {
      r_lld_per_adv_data_set(uVar8,*(undefined1 *)(iVar4 + 0x26),1,1);
      *(undefined2 *)(iVar4 + 0x24) = 0;
    }
    iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
    iVar5 = ((uint)bVar2 * 9 & 0xff) * 0xe;
    uVar3 = *(ushort *)(iVar6 + iVar5);
    iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
    *(ushort *)(iVar6 + iVar5) = uVar3 & 0x7fff;
    iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
    if ((int)((uint)*(ushort *)(iVar6 + iVar5 + 6) << 0x13) < 0) {
      bVar2 = *(byte *)(iVar4 + 0x52);
      uVar8 = r_lld_ch_idx_get_hack();
      *(char *)(iVar4 + 0x57) = (char)uVar8;
      if ((uVar8 & 0xffffffc0) != 0) {
        r_assert_err(0,"lld_per_adv.c",0x2ea);
      }
      iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
      uVar3 = *(ushort *)(iVar6 + iVar5 + 8);
      iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
      *(ushort *)(iVar5 + 8 + iVar6) = uVar3 & 0xffc0 | (ushort)uVar8;
      uVar8 = (uint)*(byte *)(iVar4 + 0x57) << 10;
      if ((uVar8 & 0x30000) != 0) {
        r_assert_err(0,"lld_per_adv.c",0x635);
      }
      iVar5 = r_emi_get_mem_addr_by_offset(0x400);
      iVar6 = (uint)bVar2 * 0x5a + 0x26;
      uVar3 = *(ushort *)(iVar5 + iVar6);
      iVar5 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar5 + iVar6) = uVar3 & 0x3ff | (ushort)uVar8;
      uVar8 = 0;
      while( true ) {
        bVar2 = *(byte *)(iVar4 + 0x52);
        uVar8 = uVar8 + 1 & 0xff;
        iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
        iVar5 = ((uint)bVar2 * 9 + uVar8 & 0xff) * 0xe;
        uVar3 = *(ushort *)(iVar6 + iVar5);
        iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
        *(ushort *)(iVar6 + iVar5) = uVar3 & 0x7fff;
        if (uVar8 == *(byte *)(iVar4 + 0x58) - 1) break;
        bVar2 = *(byte *)(iVar4 + 0x57);
        if ((bVar2 & 0xc0) != 0) {
          r_assert_err(0,"lld_per_adv.c",0x2ea);
        }
        iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
        uVar3 = *(ushort *)(iVar6 + iVar5 + 8);
        iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
        *(ushort *)(iVar5 + 8 + iVar6) = uVar3 & 0xffc0 | (ushort)bVar2;
      }
    }
    bVar2 = DAT_0001301b;
    cVar9 = DAT_0001301a;
    if (param_2 != 0) {
      cVar9 = *(char *)(iVar4 + 0x16) + DAT_0001301b;
    }
    *(char *)(iVar4 + 0x16) = cVar9;
    *(ushort *)(iVar4 + 0x14) = bVar2 & 0xf | 0x2000;
    bVar2 = *(byte *)(iVar4 + 0x52);
r_lld_per_adv_sched:
    iVar4 = *(int *)(&lld_per_adv_env + (uint)bVar2 * 4);
    *(uint *)(iVar4 + 4) = *(int *)(iVar4 + 4) + *(int *)(iVar4 + 0x40) & 0xfffffff;
    *(short *)(iVar4 + 0x4c) = *(short *)(iVar4 + 0x4c) + 1;
    iVar5 = r_lld_read_clock();
    while ((iVar5 - *(int *)(iVar4 + 4) & 0xfffffffU) < 0x7ffffff) {
      *(uint *)(iVar4 + 4) = *(int *)(iVar4 + 4) + *(int *)(iVar4 + 0x40) & 0xfffffff;
      *(short *)(iVar4 + 0x4c) = *(short *)(iVar4 + 0x4c) + 1;
    }
    cVar9 = '\x0f';
    do {
      iVar5 = r_sch_arb_insert(iVar4);
      if (iVar5 == 0) {
        *(undefined1 *)(iVar4 + 0x53) = 0;
        return;
      }
      cVar9 = cVar9 + -1;
      *(byte *)(iVar4 + 0x16) = *(char *)(iVar4 + 0x16) + DAT_0001301b;
      *(uint *)(iVar4 + 4) = *(int *)(iVar4 + 4) + *(int *)(iVar4 + 0x40) & 0xfffffff;
      *(short *)(iVar4 + 0x4c) = *(short *)(iVar4 + 0x4c) + 1;
    } while (cVar9 != '\0');
    r_assert_param("lld_per_adv.c",0x13e);
    return;
  }
  puVar7 = (undefined1 *)r_ke_msg_alloc(0x208,0,0xff,2);
  uVar1 = *(undefined1 *)(iVar4 + 0x52);
  puVar7[1] = 0;
  *puVar7 = uVar1;
  r_ke_msg_send();
r_lld_per_adv_cleanup:
  if (*(int *)(&lld_per_adv_env + (param_1 & 0xff) * 4) != 0) {
    r_ke_free();
    *(int *)(&lld_per_adv_env + (param_1 & 0xff) * 4) = 0;
  }
  return;
}

