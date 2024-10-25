/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llm_scan.o -> f_lld_per_adv_rep_ind_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 f_lld_per_adv_rep_ind_handler(byte *param_1)

{
  undefined1 uVar1;
  short sVar2;
  ushort uVar3;
  ushort uVar4;
  bool bVar5;
  undefined2 *puVar6;
  undefined1 *puVar7;
  ushort *puVar8;
  byte bVar9;
  byte *pbVar10;
  int *piVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  int *__src;
  int iVar15;
  uint uVar16;
  ushort uVar17;
  uint uVar18;
  uint uVar19;
  undefined1 auStack_48 [20];
  
  uVar16 = (uint)*param_1;
  iVar14 = uVar16 * 0x44;
  piVar11 = (int *)(*(int *)(_p_llm_env + 8) + iVar14);
  uVar17 = (ushort)*param_1;
  if ((char)piVar11[0x10] == '\x0e') {
    uVar1 = *(undefined1 *)((int)piVar11 + 0x41);
    __src = piVar11 + 1;
    r_ke_msg_free(*piVar11 + -0xc);
    *(undefined4 *)(*(int *)(_p_llm_env + 8) + iVar14) = 0;
    r_lld_scan_create_sync_cancel(uVar16);
    iVar12 = *(int *)(_p_llm_env + 8) + iVar14;
    *(undefined1 *)(iVar12 + 0x40) = 0xf;
    *(undefined2 *)(iVar12 + 0x2a) = 0xff;
    if ((_bt_rf_coex_hooks_p != (undefined4 *)0x0) && ((code *)*_bt_rf_coex_hooks_p != (code *)0x0))
    {
      (*(code *)*_bt_rf_coex_hooks_p)(uVar16,5,1);
      (*(code *)*_bt_rf_coex_hooks_p)(uVar16,6,0,(code *)*_bt_rf_coex_hooks_p);
    }
    uVar3 = *(ushort *)(param_1 + 4);
    uVar4 = *(ushort *)(param_1 + 6);
    uVar18 = (uint)uVar3 * 2;
    iVar12 = *(int *)(_p_llm_env + 8) + iVar14;
    *(uint *)(iVar12 + 0x14) = (uint)uVar4;
    *(uint *)(iVar12 + 0x10) = uVar18;
    *(undefined4 *)(iVar12 + 0x18) = 2;
    *(undefined4 *)(iVar12 + 0x1c) = 2;
    *(ushort *)(iVar12 + 0x20) = uVar17;
    *(undefined4 *)(iVar12 + 0x24) = 0;
    *(undefined1 *)(iVar12 + 0x22) = 0;
    if (uVar3 == 0) {
      r_assert_err(0,"llm_scan.c",0x94);
    }
    *(int *)(iVar12 + 0x18) = *(int *)(iVar12 + 0x18) + 3;
    *(int *)(iVar12 + 0x1c) = *(int *)(iVar12 + 0x1c) + 3;
    *(uint *)(iVar12 + 0x14) = ((uVar4 - 1) + uVar18) % uVar18;
    r_sch_plan_set(iVar12 + 0xc);
    uVar18 = r_llm_dev_list_search(__src,uVar1);
    if ((uVar18 < 0xc) && ((*(byte *)(uVar18 * 10 + _p_llm_env + 0x2d) & 4) != 0)) {
      r_lld_per_adv_list_rem(__src,uVar1,1 << (param_1[2] & 0x1f) & 0xffff);
    }
    puVar6 = (undefined2 *)r_ke_msg_alloc(0x1104,0,0x3e,0x12);
    *puVar6 = 0xe;
    puVar6[1] = uVar17;
    bVar9 = param_1[2];
    *(undefined1 *)((int)puVar6 + 5) = uVar1;
    *(byte *)(puVar6 + 2) = bVar9;
    memcpy(puVar6 + 3,__src,6);
    *(undefined *)(puVar6 + 6) = (&co_rate_to_phy)[param_1[1]];
    puVar6[7] = *(undefined2 *)(param_1 + 4);
    *(byte *)(puVar6 + 8) = param_1[10];
    r_hci_send_2_host(puVar6);
  }
  if (*(char *)(*(int *)(_p_llm_env + 8) + iVar14 + 0x40) == '\x0f') {
    uVar18 = (uint)param_1[0xe];
    uVar19 = (uint)param_1[0x18];
    do {
      uVar13 = uVar18;
      if (0xf7 < uVar18) {
        uVar13 = 0xf7;
      }
      puVar7 = (undefined1 *)r_ke_msg_alloc(0x1104,0,0x3e,0x100);
      *puVar7 = 0xf;
      *(ushort *)(puVar7 + 2) = uVar17;
      puVar7[4] = param_1[0xb];
      bVar9 = param_1[0xc];
      sVar2 = *(short *)(_p_llm_env + 200);
      puVar7[6] = 0xff;
      puVar7[5] = (char)((int)sVar2 / 10) + bVar9;
      bVar9 = 1;
      if (uVar18 < 0xf8) {
        bVar9 = param_1[0xd];
      }
      puVar7[7] = bVar9;
      puVar7[8] = (char)uVar13;
      memcpy(puVar7 + 9,(void *)(*(int *)(param_1 + 0x14) + uVar19),uVar13);
      uVar18 = uVar18 - uVar13 & 0xff;
      r_hci_send_2_host(puVar7);
      uVar19 = uVar19 + uVar13 & 0xff;
    } while (uVar18 != 0);
    iVar12 = *(int *)(_p_llm_env + 8) + iVar14;
    uVar18 = *(uint *)(iVar12 + 0x10);
    iVar15 = *(int *)(iVar12 + 0x14);
    if (uVar18 == 0) {
      r_assert_err(0,"llm_scan.c",0x94);
    }
    if (((uint)*(ushort *)(param_1 + 6) < *(uint *)(iVar12 + 0x10)) &&
       ((uint)*(ushort *)(param_1 + 6) != (iVar15 + 1U) % uVar18)) {
      r_sch_plan_rem(iVar12 + 0xc);
      uVar3 = *(ushort *)(param_1 + 6);
      uVar18 = *(uint *)(iVar12 + 0x10);
      if (uVar18 == 0) {
        r_assert_err(0,"llm_scan.c",0x94);
      }
      *(uint *)(iVar12 + 0x14) = ((uVar3 - 1) + uVar18) % uVar18;
      r_sch_plan_set(iVar12 + 0xc);
    }
    if (param_1[0x19] != 0) {
      bVar5 = false;
      for (uVar18 = 0; uVar18 < param_1[0x19]; uVar18 = uVar18 + uVar19 + 1 & 0xff) {
        iVar12 = *(int *)(param_1 + 0x14);
        pbVar10 = (byte *)((uint)param_1[0x1a] + iVar12 + uVar18);
        uVar19 = (uint)*pbVar10;
        bVar9 = pbVar10[1];
        if ((bVar5) || (bVar9 != 0x28)) {
          iVar12 = *(int *)(_p_llm_env + 8) + iVar14;
          if ((*(short *)(iVar12 + 0x2a) != 0xff) &&
             ((*(byte *)(iVar12 + 0x29) == bVar9 && ((int)uVar19 < (int)(param_1[0x19] - uVar18)))))
          {
            puVar8 = (ushort *)r_ke_msg_alloc(1,0,uVar19 + 7);
            *(byte *)((int)puVar8 + 3) = bVar9;
            *(undefined1 *)(puVar8 + 1) = 0;
            uVar3 = *(ushort *)(param_1 + 8);
            *(char *)(puVar8 + 3) = (char)(uVar19 - 1);
            *puVar8 = uVar17;
            puVar8[2] = uVar3;
            memcpy((void *)((int)puVar8 + 7),
                   (void *)(*(int *)(param_1 + 0x14) + 2 + (uint)param_1[0x1a] + uVar18),uVar19 - 1)
            ;
            r_ke_msg_send(puVar8);
          }
        }
        else {
          uVar13 = param_1[0x1a] + uVar18 & 0xff;
          memcpy(auStack_48,(void *)((uVar13 + 2 & 0xff) + iVar12),5);
          r_lld_sync_ch_map_update(uVar16,auStack_48,*(undefined2 *)((uVar13 + 7 & 0xff) + iVar12));
          bVar5 = true;
        }
      }
    }
  }
  if ((param_1[0xe] != 0) || (param_1[0x19] != 0)) {
    r_ble_util_buf_rx_free(*(undefined2 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x14));
  }
  return 0;
}

