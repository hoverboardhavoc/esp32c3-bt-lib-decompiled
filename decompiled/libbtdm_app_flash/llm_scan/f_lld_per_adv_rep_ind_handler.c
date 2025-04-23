/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llm_scan.o -> f_lld_per_adv_rep_ind_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 f_lld_per_adv_rep_ind_handler(byte *param_1)

{
  byte bVar1;
  undefined1 uVar2;
  ushort uVar3;
  ushort uVar4;
  bool bVar5;
  undefined2 *puVar6;
  undefined1 *puVar7;
  ushort *puVar8;
  byte *pbVar9;
  byte bVar10;
  int *piVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  int *__src;
  uint uVar15;
  int iVar16;
  uint uVar17;
  uint uVar18;
  undefined1 auStack_48 [20];
  
  bVar1 = *param_1;
  uVar14 = (uint)bVar1;
  iVar13 = uVar14 * 0x44;
  piVar11 = (int *)(*(int *)(_p_llm_env + 8) + iVar13);
  if ((char)piVar11[0x10] == '\x0e') {
    uVar2 = *(undefined1 *)((int)piVar11 + 0x41);
    __src = piVar11 + 1;
    r_ke_msg_free(*piVar11 + -0xc);
    *(undefined4 *)(*(int *)(_p_llm_env + 8) + iVar13) = 0;
    r_lld_scan_create_sync_cancel(uVar14);
    iVar12 = *(int *)(_p_llm_env + 8) + iVar13;
    *(undefined1 *)(iVar12 + 0x40) = 0xf;
    *(undefined2 *)(iVar12 + 0x2a) = 0xff;
    if ((_bt_rf_coex_hooks_p != (undefined4 *)0x0) && ((code *)*_bt_rf_coex_hooks_p != (code *)0x0))
    {
      (*(code *)*_bt_rf_coex_hooks_p)(uVar14,5,1);
      (*(code *)*_bt_rf_coex_hooks_p)(uVar14,6,0,(code *)*_bt_rf_coex_hooks_p);
    }
    uVar3 = *(ushort *)(param_1 + 4);
    uVar4 = *(ushort *)(param_1 + 6);
    uVar17 = (uint)uVar3 * 2;
    iVar12 = *(int *)(_p_llm_env + 8) + iVar13;
    *(uint *)(iVar12 + 0x14) = (uint)uVar4;
    *(uint *)(iVar12 + 0x10) = uVar17;
    *(undefined4 *)(iVar12 + 0x18) = 2;
    *(undefined4 *)(iVar12 + 0x1c) = 2;
    *(ushort *)(iVar12 + 0x20) = (ushort)bVar1;
    *(undefined4 *)(iVar12 + 0x24) = 0;
    *(undefined1 *)(iVar12 + 0x22) = 0;
    if (uVar3 == 0) {
      r_assert_err(0,"llm_scan.c",0x94);
    }
    *(int *)(iVar12 + 0x18) = *(int *)(iVar12 + 0x18) + 3;
    *(int *)(iVar12 + 0x1c) = *(int *)(iVar12 + 0x1c) + 3;
    *(uint *)(iVar12 + 0x14) = ((uVar4 - 1) + uVar17) % uVar17;
    r_sch_plan_set(iVar12 + 0xc);
    uVar17 = r_llm_dev_list_search(__src,uVar2);
    if ((uVar17 < 0xc) && ((*(byte *)(uVar17 * 10 + _p_llm_env + 0x2d) & 4) != 0)) {
      r_lld_per_adv_list_rem(__src,uVar2,1 << (param_1[2] & 0x1f) & 0xffff);
    }
    puVar6 = (undefined2 *)r_ke_msg_alloc(0x1104,0,0x3e,0x12);
    *puVar6 = 0xe;
    puVar6[1] = (ushort)bVar1;
    *(byte *)(puVar6 + 2) = param_1[2];
    *(undefined1 *)((int)puVar6 + 5) = uVar2;
    memcpy(puVar6 + 3,__src,6);
    *(undefined *)(puVar6 + 6) = (&co_rate_to_phy)[param_1[1]];
    puVar6[7] = *(undefined2 *)(param_1 + 4);
    *(byte *)(puVar6 + 8) = param_1[10];
    r_hci_send_2_host(puVar6);
  }
  if (*(char *)(*(int *)(_p_llm_env + 8) + iVar13 + 0x40) == '\x0f') {
    uVar17 = (uint)param_1[0xe];
    uVar18 = (uint)param_1[0x18];
    do {
      uVar15 = uVar17;
      if (0xf7 < uVar17) {
        uVar15 = 0xf7;
      }
      puVar7 = (undefined1 *)r_ke_msg_alloc(0x1104,0,0x3e,0x100);
      *puVar7 = 0xf;
      *(ushort *)(puVar7 + 2) = (ushort)bVar1;
      puVar7[4] = param_1[0xb];
      puVar7[5] = (char)((int)*(short *)(_p_llm_env + 200) / 10) + param_1[0xc];
      puVar7[6] = 0xff;
      bVar10 = 1;
      if (uVar17 < 0xf8) {
        bVar10 = param_1[0xd];
      }
      puVar7[7] = bVar10;
      puVar7[8] = (char)uVar15;
      memcpy(puVar7 + 9,(void *)(*(int *)(param_1 + 0x14) + uVar18),uVar15);
      uVar17 = uVar17 - uVar15 & 0xff;
      r_hci_send_2_host(puVar7);
      uVar18 = uVar18 + uVar15 & 0xff;
    } while (uVar17 != 0);
    iVar12 = *(int *)(_p_llm_env + 8) + iVar13;
    uVar17 = *(uint *)(iVar12 + 0x10);
    iVar16 = *(int *)(iVar12 + 0x14);
    if (uVar17 == 0) {
      r_assert_err(0,"llm_scan.c",0x94);
    }
    if (((uint)*(ushort *)(param_1 + 6) < *(uint *)(iVar12 + 0x10)) &&
       ((uint)*(ushort *)(param_1 + 6) != (iVar16 + 1U) % uVar17)) {
      r_sch_plan_rem(iVar12 + 0xc);
      uVar3 = *(ushort *)(param_1 + 6);
      uVar17 = *(uint *)(iVar12 + 0x10);
      if (uVar17 == 0) {
        r_assert_err(0,"llm_scan.c",0x94);
      }
      *(uint *)(iVar12 + 0x14) = ((uVar3 - 1) + uVar17) % uVar17;
      r_sch_plan_set(iVar12 + 0xc);
    }
    if (param_1[0x19] != 0) {
      bVar5 = false;
      for (uVar17 = 0; uVar17 < param_1[0x19]; uVar17 = uVar17 + 1 + uVar18 & 0xff) {
        iVar12 = *(int *)(param_1 + 0x14);
        pbVar9 = (byte *)((uint)param_1[0x1a] + iVar12 + uVar17);
        uVar18 = (uint)*pbVar9;
        bVar10 = pbVar9[1];
        if ((bVar5) || (bVar10 != 0x28)) {
          iVar12 = *(int *)(_p_llm_env + 8) + iVar13;
          if ((*(short *)(iVar12 + 0x2a) != 0xff) &&
             ((*(byte *)(iVar12 + 0x29) == bVar10 && ((int)uVar18 < (int)(param_1[0x19] - uVar17))))
             ) {
            puVar8 = (ushort *)r_ke_msg_alloc(1,0,uVar18 + 7);
            *(byte *)((int)puVar8 + 3) = bVar10;
            *(undefined1 *)(puVar8 + 1) = 0;
            uVar3 = *(ushort *)(param_1 + 8);
            *(char *)(puVar8 + 3) = (char)(uVar18 - 1);
            *puVar8 = (ushort)bVar1;
            iVar12 = *(int *)(param_1 + 0x14);
            puVar8[2] = uVar3;
            memcpy((void *)((int)puVar8 + 7),(void *)(iVar12 + 2 + (uint)param_1[0x1a] + uVar17),
                   uVar18 - 1);
            r_ke_msg_send(puVar8);
          }
        }
        else {
          uVar15 = param_1[0x1a] + uVar17 & 0xff;
          memcpy(auStack_48,(void *)((uVar15 + 2 & 0xff) + iVar12),5);
          r_lld_sync_ch_map_update(uVar14,auStack_48,*(undefined2 *)((uVar15 + 7 & 0xff) + iVar12));
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

