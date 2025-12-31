/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
 * Source: libbtdm_app_flash -> llm_scan.o -> lld_per_adv_rep_ind_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 lld_per_adv_rep_ind_handler(byte *param_1,undefined4 param_2)

{
  undefined1 uVar1;
  short sVar2;
  ushort uVar3;
  ushort uVar4;
  bool bVar5;
  undefined2 *puVar6;
  undefined1 *puVar7;
  ushort *puVar8;
  int iVar9;
  byte bVar10;
  byte *pbVar11;
  int *piVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  int *__src;
  int iVar16;
  ushort uVar17;
  uint uVar18;
  uint __n;
  uint uVar19;
  undefined1 auStack_48 [20];
  
  iVar9 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar9 + 0x18) == '\0') {
    return 0;
  }
  uVar15 = (uint)*param_1;
  iVar9 = uVar15 * 0x44;
  piVar12 = (int *)(*(int *)(_p_llm_env + 8) + iVar9);
  uVar17 = (ushort)*param_1;
  if ((char)piVar12[0x10] == '\x0e') {
    uVar1 = *(undefined1 *)((int)piVar12 + 0x41);
    __src = piVar12 + 1;
    r_ke_msg_free(*piVar12 + -0xc,param_2);
    *(undefined4 *)(*(int *)(_p_llm_env + 8) + iVar9) = 0;
    r_lld_scan_create_sync_cancel(uVar15);
    iVar13 = *(int *)(_p_llm_env + 8) + iVar9;
    *(undefined1 *)(iVar13 + 0x40) = 0xf;
    *(undefined2 *)(iVar13 + 0x2a) = 0xff;
    r_ble_log_internal_x1(0x404e01f2,uVar15 | 0xf00);
    if ((_bt_rf_coex_hooks_p != (undefined4 *)0x0) && ((code *)*_bt_rf_coex_hooks_p != (code *)0x0))
    {
      (*(code *)*_bt_rf_coex_hooks_p)(uVar15,5,1);
      (*(code *)*_bt_rf_coex_hooks_p)(uVar15,6,0,(code *)*_bt_rf_coex_hooks_p);
    }
    uVar3 = *(ushort *)(param_1 + 4);
    uVar4 = *(ushort *)(param_1 + 6);
    uVar18 = (uint)uVar3 * 2;
    iVar13 = *(int *)(_p_llm_env + 8) + iVar9;
    *(uint *)(iVar13 + 0x14) = (uint)uVar4;
    *(uint *)(iVar13 + 0x10) = uVar18;
    *(undefined4 *)(iVar13 + 0x18) = 2;
    *(undefined4 *)(iVar13 + 0x1c) = 2;
    *(ushort *)(iVar13 + 0x20) = uVar17;
    *(undefined4 *)(iVar13 + 0x24) = 0;
    *(undefined1 *)(iVar13 + 0x22) = 0;
    if (uVar3 == 0) {
      r_assert_err(0,"llm_scan.c",0x94);
    }
    *(int *)(iVar13 + 0x18) = *(int *)(iVar13 + 0x18) + 3;
    *(int *)(iVar13 + 0x1c) = *(int *)(iVar13 + 0x1c) + 3;
    *(uint *)(iVar13 + 0x14) = ((uVar4 - 1) + uVar18) % uVar18;
    r_sch_plan_set_hack(iVar13 + 0xc);
    uVar18 = r_llm_dev_list_search(__src,uVar1);
    if ((uVar18 < 0xc) && ((*(byte *)(uVar18 * 10 + _p_llm_env + 0x2d) & 4) != 0)) {
      r_lld_per_adv_list_rem(__src,uVar1,1 << (param_1[2] & 0x1f) & 0xffff);
    }
    puVar6 = (undefined2 *)r_ke_msg_alloc(0x1104,0,0x3e,0x12);
    *puVar6 = 0xe;
    puVar6[1] = uVar17;
    bVar10 = param_1[2];
    *(undefined1 *)((int)puVar6 + 5) = uVar1;
    *(byte *)(puVar6 + 2) = bVar10;
    memcpy(puVar6 + 3,__src,6);
    *(undefined *)(puVar6 + 6) = (&co_rate_to_phy)[param_1[1]];
    puVar6[7] = *(undefined2 *)(param_1 + 4);
    *(byte *)(puVar6 + 8) = param_1[10];
    r_hci_send_2_host(puVar6);
  }
  if (*(char *)(*(int *)(_p_llm_env + 8) + iVar9 + 0x40) == '\x0f') {
    uVar18 = (uint)param_1[0xe];
    uVar19 = (uint)param_1[0x18];
    do {
      uVar14 = uVar18;
      if (0xf7 < uVar18) {
        uVar14 = 0xfffffff7;
      }
      __n = uVar14 & 0xff;
      puVar7 = (undefined1 *)r_ke_msg_alloc(0x1104,0,0x3e,0x100);
      *puVar7 = 0xf;
      *(ushort *)(puVar7 + 2) = uVar17;
      puVar7[4] = param_1[0xb];
      bVar10 = param_1[0xc];
      sVar2 = *(short *)(_p_llm_env + 200);
      puVar7[6] = 0xff;
      puVar7[5] = (char)((int)sVar2 / 10) + bVar10;
      bVar10 = 1;
      if (uVar18 < 0xf8) {
        bVar10 = param_1[0xd];
      }
      puVar7[7] = bVar10;
      puVar7[8] = (char)uVar14;
      memcpy(puVar7 + 9,(void *)(*(int *)(param_1 + 0x14) + uVar19),__n);
      r_hci_send_2_host(puVar7);
      uVar18 = uVar18 - __n & 0xff;
      uVar19 = uVar19 + __n & 0xff;
    } while (uVar18 != 0);
    iVar13 = *(int *)(_p_llm_env + 8) + iVar9;
    uVar18 = *(uint *)(iVar13 + 0x10);
    iVar16 = *(int *)(iVar13 + 0x14);
    if (uVar18 == 0) {
      r_assert_err(0,"llm_scan.c",0x94);
    }
    if (((uint)*(ushort *)(param_1 + 6) < *(uint *)(iVar13 + 0x10)) &&
       ((uint)*(ushort *)(param_1 + 6) != (iVar16 + 1U) % uVar18)) {
      r_sch_plan_rem(iVar13 + 0xc);
      uVar3 = *(ushort *)(param_1 + 6);
      uVar18 = *(uint *)(iVar13 + 0x10);
      if (uVar18 == 0) {
        r_assert_err(0,"llm_scan.c",0x94);
      }
      *(uint *)(iVar13 + 0x14) = ((uVar3 - 1) + uVar18) % uVar18;
      r_sch_plan_set_hack(iVar13 + 0xc);
    }
    if (param_1[0x19] != 0) {
      bVar5 = false;
      for (uVar18 = 0; uVar18 < param_1[0x19]; uVar18 = uVar19 + 1 + uVar18 & 0xff) {
        iVar13 = *(int *)(param_1 + 0x14);
        pbVar11 = (byte *)((uint)param_1[0x1a] + iVar13 + uVar18);
        uVar19 = (uint)*pbVar11;
        bVar10 = pbVar11[1];
        if ((bVar5) || (bVar10 != 0x28)) {
          iVar13 = *(int *)(_p_llm_env + 8) + iVar9;
          if ((*(short *)(iVar13 + 0x2a) != 0xff) &&
             ((*(byte *)(iVar13 + 0x29) == bVar10 && ((int)uVar19 < (int)(param_1[0x19] - uVar18))))
             ) {
            puVar8 = (ushort *)r_ke_msg_alloc(1,0,uVar19 + 7);
            *(byte *)((int)puVar8 + 3) = bVar10;
            *(undefined1 *)(puVar8 + 1) = 0;
            uVar3 = *(ushort *)(param_1 + 8);
            *(char *)(puVar8 + 3) = (char)(uVar19 - 1);
            *puVar8 = uVar17;
            iVar13 = *(int *)(param_1 + 0x14);
            puVar8[2] = uVar3;
            memcpy((void *)((int)puVar8 + 7),(void *)(iVar13 + 2 + (uint)param_1[0x1a] + uVar18),
                   uVar19 - 1);
            r_ke_msg_send(puVar8);
          }
        }
        else {
          uVar14 = param_1[0x1a] + uVar18 & 0xff;
          memcpy(auStack_48,(void *)((uVar14 + 2 & 0xff) + iVar13),5);
          r_lld_sync_ch_map_update(uVar15,auStack_48,*(undefined2 *)((uVar14 + 7 & 0xff) + iVar13));
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

