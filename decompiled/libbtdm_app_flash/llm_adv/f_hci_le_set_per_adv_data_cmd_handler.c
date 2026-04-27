/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
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
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  uint uVar5;
  ushort uVar6;
  undefined2 uVar7;
  int iVar8;
  void *__dest;
  uint uVar9;
  bool bVar10;
  char cVar11;
  int iVar12;
  int iVar13;
  uint uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  if (*(char *)(_p_llm_env + 0xd7) == '\x01') {
_L833:
    uVar4 = 0xc;
    goto _L788;
  }
  *(undefined1 *)(_p_llm_env + 0xd7) = 2;
  if (0xef < *param_1) goto _L792;
  iVar8 = r_llm_adv_hdl_to_id(0);
  if (iVar8 == 0xff) {
    r_ble_log_internal_x1(0x802e01a2,0xff42);
    uVar4 = 0x42;
    goto _L788;
  }
  iVar12 = *(int *)(_p_llm_env + 8);
  uVar5 = (uint)*(byte *)(iVar12 + iVar8 * 0x44 + 0x3d);
  if (uVar5 == 0xff) {
    r_ble_log_internal_x1(0x802e01a3,iVar8 << 8 | 0xff000c);
    goto _L833;
  }
  bVar1 = param_1[1];
  if (bVar1 < 4) {
    uVar9 = (uint)param_1[2];
    if (uVar9 < 0xfd) {
      if (bVar1 != 3) {
        if (uVar9 == 0) goto _L792;
        if (*(char *)(uVar5 * 0x44 + iVar12 + 0x40) == '\f') goto _L833;
      }
      iVar2 = uVar5 * 0x44;
      iVar12 = iVar12 + iVar2;
      if ((uint)*(ushort *)(iVar12 + 0x30) < *(ushort *)(iVar12 + 0x2e) + uVar9) {
        r_ble_log_internal_x2
                  (0x802e01a4,(uint)CONCAT12(param_1[2],*(ushort *)(iVar12 + 0x2e)),uVar5 << 8 | 7);
        uVar4 = 7;
        if (*(short *)(*(int *)(_p_llm_env + 8) + iVar2 + 0x2c) != 0) {
          r_ble_util_buf_adv_tx_free();
          *(undefined4 *)(*(int *)(_p_llm_env + 8) + iVar2 + 0x2c) = 0;
        }
        goto _L788;
      }
      if ((bVar1 & 0xfd) == 1) {
        if (*(short *)(iVar12 + 0x2c) != 0) {
          r_ble_util_buf_adv_tx_free();
          *(undefined2 *)(*(int *)(_p_llm_env + 8) + iVar2 + 0x2e) = 0;
        }
        iVar12 = *(int *)(_p_llm_env + 8) + iVar2;
        if (param_1[1] == 3) {
          uVar6 = (ushort)param_1[2];
          if (uVar6 != 0) goto _L832;
          uVar7 = 0;
          bVar10 = true;
        }
        else {
          uVar6 = *(ushort *)(iVar12 + 0x30);
_L832:
          uVar7 = r_ble_util_buf_adv_tx_alloc(uVar6);
          bVar10 = false;
        }
        iVar13 = _p_llm_env;
        *(undefined2 *)(iVar12 + 0x2c) = uVar7;
        if ((*(short *)(*(int *)(iVar13 + 8) + iVar2 + 0x2c) == 0) && (!bVar10)) {
          r_ble_log_internal_x1(0x802e01a5,uVar5 << 8 | 7);
          uVar4 = 7;
          goto _L788;
        }
      }
      bVar1 = param_1[2];
      if (bVar1 != 0) {
        iVar12 = *(int *)(_p_llm_env + 8) + iVar2;
        __dest = (void *)r_emi_get_mem_addr_by_offset
                                   (*(short *)(iVar12 + 0x2c) + *(short *)(iVar12 + 0x2e));
        memcpy(__dest,param_1 + 3,(uint)bVar1);
        iVar12 = *(int *)(_p_llm_env + 8) + iVar2;
        *(ushort *)(iVar12 + 0x2e) = *(short *)(iVar12 + 0x2e) + (ushort)param_1[2];
      }
      if ((byte)(param_1[1] - 2) < 2) {
        iVar12 = *(int *)(_p_llm_env + 8) + iVar2;
        if (*(char *)(iVar12 + 0x40) == '\f') {
          r_lld_per_adv_data_update_hack
                    (uVar5,*(undefined1 *)(iVar12 + 0x2e),*(undefined2 *)(iVar12 + 0x2c));
        }
        else if (*(short *)(iVar12 + 0x28) != 0) {
          r_ble_util_buf_adv_tx_free();
        }
        iVar13 = *(int *)(_p_llm_env + 8);
        piVar3 = (int *)(iVar2 + iVar13);
        iVar12 = piVar3[0xb];
        piVar3[0xb] = 0;
        piVar3[10] = iVar12;
        if ((_bt_rf_coex_hooks_p != 0) && (*(int *)(_bt_rf_coex_hooks_p + 4) != 0)) {
          iVar8 = *(int *)(iVar13 + iVar8 * 0x44);
          uStack_2c = (uint)*(ushort *)(*piVar3 + 4);
          uStack_24 = 0;
          uStack_28 = (uint)*(ushort *)((int)piVar3 + 0x2e);
          if ((*(byte *)(iVar8 + 0x17) < 3) || (iVar12 = lld_phy_coded_500k_get(), iVar12 == 0)) {
            cVar11 = *(char *)(iVar8 + 0x17) + -1;
          }
          else {
            cVar11 = *(char *)(iVar8 + 0x17);
          }
          uStack_28._0_3_ = CONCAT12(cVar11,(undefined2)uStack_28);
          (**(code **)(_bt_rf_coex_hooks_p + 4))
                    (uVar5,4,&uStack_2c,*(code **)(_bt_rf_coex_hooks_p + 4));
        }
      }
      uVar4 = 0;
      goto _L788;
    }
  }
_L792:
  uVar4 = 0x12;
_L788:
  r_llm_cmd_cmp_send(param_2,uVar4);
  return 0;
}

