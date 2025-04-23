/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llm_adv.o -> f_hci_le_set_per_adv_data_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 f_hci_le_set_per_adv_data_cmd_handler(byte *param_1,undefined4 param_2)

{
  byte bVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  ushort uVar6;
  undefined2 uVar7;
  int iVar8;
  void *__dest;
  undefined4 uVar9;
  uint uVar10;
  char cVar11;
  int iVar12;
  uint uVar13;
  uint uStack_2c;
  undefined2 uStack_28;
  undefined2 uStack_26;
  undefined2 uStack_24;
  undefined2 uStack_22;
  
  if (*(char *)(_p_llm_env + 0xd7) == '\x01') {
_L718:
    uVar9 = 0xc;
    goto _L716;
  }
  *(undefined1 *)(_p_llm_env + 0xd7) = 2;
  if (0xef < *param_1) goto _L719;
  iVar8 = r_llm_adv_hdl_to_id(0);
  uVar9 = 0x42;
  if (iVar8 == 0xff) goto _L716;
  iVar5 = *(int *)(_p_llm_env + 8);
  uVar13 = (uint)*(byte *)(iVar5 + iVar8 * 0x44 + 0x3d);
  if (uVar13 == 0xff) goto _L718;
  bVar1 = param_1[1];
  if ((3 < bVar1) || (uVar10 = (uint)param_1[2], 0xfc < uVar10)) {
_L719:
    uVar9 = 0x12;
    goto _L716;
  }
  if (bVar1 != 3) {
    if (uVar10 == 0) goto _L719;
    if (*(char *)(uVar13 * 0x44 + iVar5 + 0x40) == '\f') goto _L718;
  }
  iVar3 = uVar13 * 0x44;
  iVar5 = iVar5 + iVar3;
  if ((uint)*(ushort *)(iVar5 + 0x30) < *(ushort *)(iVar5 + 0x2e) + uVar10) {
    if (*(short *)(iVar5 + 0x2c) != 0) {
      r_ble_util_buf_adv_tx_free();
      *(undefined4 *)(*(int *)(_p_llm_env + 8) + iVar3 + 0x2c) = 0;
    }
_L723:
    uVar9 = 7;
  }
  else {
    if ((bVar1 & 0xfd) == 1) {
      if (*(short *)(iVar5 + 0x2c) != 0) {
        r_ble_util_buf_adv_tx_free();
        iVar5 = *(int *)(_p_llm_env + 8) + iVar3;
        *(undefined2 *)(iVar5 + 0x2e) = 0;
      }
      if (param_1[1] == 3) {
        uVar6 = (ushort)param_1[2];
        if (uVar6 != 0) goto _L761;
        uVar7 = 0;
        bVar2 = true;
      }
      else {
        uVar6 = *(ushort *)(iVar5 + 0x30);
_L761:
        uVar7 = r_ble_util_buf_adv_tx_alloc(uVar6);
        bVar2 = false;
      }
      iVar12 = _p_llm_env;
      *(undefined2 *)(iVar5 + 0x2c) = uVar7;
      if ((*(short *)(*(int *)(iVar12 + 8) + iVar3 + 0x2c) == 0) && (!bVar2)) goto _L723;
    }
    bVar1 = param_1[2];
    if (bVar1 != 0) {
      iVar5 = *(int *)(_p_llm_env + 8) + iVar3;
      __dest = (void *)r_emi_get_mem_addr_by_offset
                                 (*(short *)(iVar5 + 0x2c) + *(short *)(iVar5 + 0x2e));
      memcpy(__dest,param_1 + 3,(uint)bVar1);
      iVar5 = *(int *)(_p_llm_env + 8) + iVar3;
      *(ushort *)(iVar5 + 0x2e) = *(short *)(iVar5 + 0x2e) + (ushort)param_1[2];
    }
    if ((byte)(param_1[1] - 2) < 2) {
      iVar5 = *(int *)(_p_llm_env + 8) + iVar3;
      if (*(char *)(iVar5 + 0x40) == '\f') {
        r_lld_per_adv_data_update_hack
                  (uVar13,*(undefined1 *)(iVar5 + 0x2e),*(undefined2 *)(iVar5 + 0x2c));
      }
      else if (*(short *)(iVar5 + 0x28) != 0) {
        r_ble_util_buf_adv_tx_free();
      }
      iVar12 = *(int *)(_p_llm_env + 8);
      piVar4 = (int *)(iVar3 + iVar12);
      iVar5 = piVar4[0xb];
      piVar4[0xb] = 0;
      piVar4[10] = iVar5;
      if ((_bt_rf_coex_hooks_p != 0) && (*(int *)(_bt_rf_coex_hooks_p + 4) != 0)) {
        iVar8 = *(int *)(iVar12 + iVar8 * 0x44);
        uStack_2c = (uint)*(ushort *)(*piVar4 + 4);
        uStack_26 = 0;
        uStack_24 = 0;
        uStack_22 = 0;
        uStack_28 = *(undefined2 *)((int)piVar4 + 0x2e);
        if ((*(byte *)(iVar8 + 0x17) < 3) || (iVar5 = lld_phy_coded_500k_get(), iVar5 == 0)) {
          cVar11 = *(char *)(iVar8 + 0x17) + -1;
        }
        else {
          cVar11 = *(char *)(iVar8 + 0x17);
        }
        uStack_26 = CONCAT11(uStack_26._1_1_,cVar11);
        (**(code **)(_bt_rf_coex_hooks_p + 4))
                  (uVar13,4,&uStack_2c,*(code **)(_bt_rf_coex_hooks_p + 4));
      }
    }
    uVar9 = 0;
  }
_L716:
  r_llm_cmd_cmp_send(param_2,uVar9);
  return 0;
}

